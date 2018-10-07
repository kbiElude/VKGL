/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_OBJECT_MANAGER_H
#define VKGL_GL_OBJECT_MANAGER_H

#include "Common/macros.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/snapshot_manager.h"
#include "OpenGL/namespace.h"
#include <map>


namespace OpenGL
{
    template<typename ObjectReferenceType,
             typename ObjectReferenceUniquePtrType>
    class GLObjectManager : public IGLObjectManager<ObjectReferenceUniquePtrType>,
                            public IStateSnapshotAccessors
    {
    public:
        /* Public functions */

        bool delete_ids(const uint32_t& in_n_ids,
                        const GLuint*   in_ids_ptr)
        {
            bool result = false;

            m_id_manager_ptr->release(in_n_ids,
                                      in_ids_ptr);

            {
                auto lock = std::unique_lock<std::mutex>(m_mutex);

                for (uint32_t n_id = 0;
                              n_id < in_n_ids;
                            ++n_id)
                {
                    const auto& current_id = in_ids_ptr[n_id];

                    if (current_id  == 0      &&
                        m_releasing == false)
                    {
                        continue;
                    }

                    if (!is_id_valid(current_id) )
                    {
                        continue;
                    }

                    /* Only destroy the object *IF* there are no remaining active references. Otherwise, assign
                     * a corresponding status to the object and leave it alone.
                     */
                    if (m_object_ptrs.at(current_id)->snapshot_manager_ptr->get_n_references(true /* include_tot_snapshot_references */) == 0)
                    {
                        delete_object(current_id);
                    }
                    else
                    {
                        #if defined(_DEBUG)
                        {
                            const auto object_status = get_object_status(current_id);

                            vkgl_assert(object_status == Status::Alive              ||
                                        object_status == Status::Created_Not_Bound)
                        }
                        #endif

                        set_object_status(current_id,
                                          Status::Deleted_References_Pending);
                    }
                }
            }

            result = true;
            return result;
        }

        bool generate_ids(const uint32_t& in_n_ids,
                          GLuint*         out_ids_ptr)
        {
            bool result = false;

            m_id_manager_ptr->allocate(in_n_ids,
                                       out_ids_ptr);

            for (uint32_t n_id = 0;
                          n_id < in_n_ids;
                        ++n_id)
            {
                const auto& current_id = out_ids_ptr[n_id];

                if (!insert_object(current_id) )
                {
                    vkgl_assert_fail();

                    goto end;
                }
            }

            result = true;
        end:
            return result;
        }

        bool is_alive_id(const GLuint& in_id) const
        {
            bool result = false;

            {
                std::unique_lock<std::mutex> lock    (m_mutex);
                const bool                   is_valid(is_id_valid(in_id) );

                if (is_valid                                  &&
                    get_object_status(in_id) == Status::Alive)
                {
                    result = true;
                }
            }

            return result;
        }

        bool mark_id_as_alive(const GLuint& in_id)
        {
            bool result = false;

            {
                std::unique_lock<std::mutex> lock(m_mutex);
                const auto                   object_status(get_object_status(in_id) );

                if (object_status == Status::Created_Not_Bound)
                {
                    set_object_status(in_id,
                                      Status::Alive);
                }
                else
                {
                    vkgl_assert(object_status == Status::Alive);
                }
            }

            result = true;
            return result;
        }

        OpenGL::TimeMarker get_object_creation_time(const GLuint& in_id) const
        {
            const auto         props_ptr = get_general_object_props_ptr(in_id);
            OpenGL::TimeMarker result;

            if (props_ptr != nullptr)
            {
                result = props_ptr->creation_time;
            }

            return result;
        }

        ObjectReferenceUniquePtrType acquire_always_latest_snapshot_reference (const GLuint& in_id)
        {
            ObjectReferenceUniquePtrType result_ptr;

            result_ptr = acquire_reference(in_id,
                                           OpenGL::LATEST_SNAPSHOT_AVAILABLE);

            vkgl_assert(result_ptr != nullptr);

            return result_ptr;
        }

        ObjectReferenceUniquePtrType acquire_current_latest_snapshot_reference(const GLuint& in_id)
        {
            /* NOTE: Must only be called from rendering context's thread */
            ObjectReferenceUniquePtrType result_ptr;

            result_ptr = acquire_reference(in_id,
                                           get_general_object_props_ptr(in_id)->snapshot_manager_ptr->get_last_modified_time() );

            vkgl_assert(result_ptr != nullptr);

            return result_ptr;
        }

        virtual ~GLObjectManager()
        {
            m_releasing = true;

            if (m_expose_default_object)
            {
                m_default_object_reference_ptr.reset();
            }
            else
            {
                vkgl_assert(m_default_object_reference_ptr == nullptr);
            }
        }

    protected:
        /* Protected type definitions */

        enum class Status
        {
            Created_Not_Bound,
            Alive,
            Deleted_References_Pending,

            Unknown
        };

        typedef struct GeneralObjectProps
        {
            OpenGL::TimeMarker                                                                           creation_time;
            GLuint                                                                                       id;
            std::unique_ptr<OpenGL::SnapshotManager<ObjectReferenceType, ObjectReferenceUniquePtrType> > snapshot_manager_ptr;
            Status                                                                                       status;

            GeneralObjectProps(IStateSnapshotAccessors* in_state_snapshot_accessors_ptr,
                               const GLuint&            in_id,
                               std::function<void()>    in_on_all_references_deleted_func)
            {
                creation_time = std::chrono::high_resolution_clock::now();
                id            = in_id;
                status        = Status::Created_Not_Bound;

                snapshot_manager_ptr.reset(
                    new SnapshotManager<ObjectReferenceType, ObjectReferenceUniquePtrType>(id,
                                                                                           in_state_snapshot_accessors_ptr,
                                                                                           std::chrono::high_resolution_clock::now(),
                                                                                           in_on_all_references_deleted_func)
                );
            }
        } GeneralObjectProps;

        /* IGLObjectManager interface */
        ObjectReferenceUniquePtrType get_default_object_reference() const final
        {
            /* Default object NEVER goes out of scope. Hence, we wrap a raw ptr to the pre-baked reference and make
             * sure the destructor never gets called.
             */
            vkgl_assert(m_expose_default_object);

            return ObjectReferenceUniquePtrType(m_default_object_reference_ptr.get(),
                                                [](ObjectReferenceType*){ /* Stub */});
        }

        bool is_object_deleted(const GLuint& in_id) const final
        {
            return get_object_status(in_id) == Status::Deleted_References_Pending;
        }

        /* Protected functions */

        GLObjectManager(const GLuint& in_first_valid_nondefault_id,
                        const bool&   in_expose_default_object)
            :m_expose_default_object    (in_expose_default_object),
             m_first_valid_nondefault_id(in_first_valid_nondefault_id),
             m_releasing                (false)
        {
            /*  Stub */
        }

        ObjectReferenceUniquePtrType acquire_reference(const GLuint&             in_id,
                                                       const OpenGL::TimeMarker& in_time_marker)
        {
            ObjectReferenceUniquePtrType result_ptr(nullptr,
                                                    std::default_delete<ObjectReferenceType>() );

            {
                std::unique_lock<std::mutex> lock      (m_mutex);
                auto                         object_ptr(m_object_ptrs.at(in_id).get() );

                vkgl_assert(object_ptr != nullptr);

                #if defined(_DEBUG)
                {
                    const auto& object_status = object_ptr->status;

                    vkgl_assert(object_status != Status::Deleted_References_Pending &&
                                object_status != Status::Unknown);
                }
                #endif

                result_ptr = object_ptr->snapshot_manager_ptr->acquire_reference(in_time_marker);

                if (result_ptr == nullptr)
                {
                    vkgl_assert(result_ptr != nullptr);

                    goto end;
                }
            }

        end:
            return result_ptr;
        }

        const GeneralObjectProps* get_general_object_props_ptr (const GLuint& in_id) const
        {
            GeneralObjectProps* result_ptr     = nullptr;
            const auto          object_iterator = m_object_ptrs.find(in_id);

            vkgl_assert(object_iterator != m_object_ptrs.end() );
            if (object_iterator != m_object_ptrs.end() )
            {
                result_ptr = object_iterator->second.get();
            }

            return result_ptr;
        }

        const void* get_internal_object_props_ptr(const GLuint&             in_id,
                                                  const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
        {
            const auto  props_ptr  = get_general_object_props_ptr(in_id);
            const void* result_ptr = nullptr;

            if (props_ptr != nullptr)
            {
                const OpenGL::TimeMarker time_marker = (in_opt_time_marker_ptr == nullptr)                                                                 ? props_ptr->snapshot_manager_ptr->get_last_modified_time()
                                                     : (in_opt_time_marker_ptr != nullptr && *in_opt_time_marker_ptr == OpenGL::LATEST_SNAPSHOT_AVAILABLE) ? props_ptr->snapshot_manager_ptr->get_last_modified_time()
                                                     : *in_opt_time_marker_ptr;

                result_ptr = props_ptr->snapshot_manager_ptr->get_readonly_snapshot(time_marker);
            }

            return result_ptr;
        }

        void* get_internal_object_props_ptr(const GLuint&             in_id,
                                            const OpenGL::TimeMarker* in_opt_time_marker_ptr)
        {
            const auto props_ptr  = get_general_object_props_ptr(in_id);
            void*      result_ptr = nullptr;

            if (props_ptr != nullptr)
            {
                const OpenGL::TimeMarker time_marker = (in_opt_time_marker_ptr == nullptr)                                                                 ? props_ptr->snapshot_manager_ptr->get_last_modified_time()
                                                     : (in_opt_time_marker_ptr != nullptr && *in_opt_time_marker_ptr == OpenGL::LATEST_SNAPSHOT_AVAILABLE) ? props_ptr->snapshot_manager_ptr->get_last_modified_time()
                                                     : *in_opt_time_marker_ptr;

                /* NOTE: This function must ONLY be called for potential update purposes. State updates can only be performed
                 *       against ToT state snapshots.
                 */
                vkgl_assert(time_marker == props_ptr->snapshot_manager_ptr->get_last_modified_time() );

                result_ptr = props_ptr->snapshot_manager_ptr->get_rw_tot_snapshot();
            }

            return result_ptr;
        }

        bool init()
        {
            bool result = false;

            m_id_manager_ptr.reset(
                new OpenGL::Namespace(m_first_valid_nondefault_id)
            );

            if (m_id_manager_ptr == nullptr)
            {
                vkgl_assert(m_id_manager_ptr != nullptr);

                goto end;
            }

            if (m_expose_default_object)
            {
                /* Instantiate the default object. .*/
                result = insert_object(0 /* in_id */);
                vkgl_assert(result);

                /* ..and bake a reference to the default object. It's going to live until the manager goes out of scope. */
                m_default_object_reference_ptr = acquire_always_latest_snapshot_reference(0 /* in_id */);

                if (m_default_object_reference_ptr == nullptr)
                {
                    vkgl_assert(m_default_object_reference_ptr != nullptr);

                    result = false;
                    goto end;
                }
            }

            result = true;
        end:
            return result;
        }

        bool update_last_modified_time(const GLuint& in_id)
        {
            bool result     = false;
            auto object_ptr = get_general_object_props_ptr(in_id);

            if (object_ptr != nullptr)
            {
                object_ptr->snapshot_manager_ptr->update_last_modified_time();

                result = true;
            }

            return result;
        }

        /* Protected variables */
        OpenGL::NamespaceUniquePtr m_id_manager_ptr;

        ObjectReferenceUniquePtrType m_default_object_reference_ptr;
        const bool                   m_expose_default_object;
        const GLuint                 m_first_valid_nondefault_id;
        mutable std::mutex           m_mutex;
        bool                         m_releasing;

    private:

        /* Private functions */

        bool delete_object(const GLuint& in_id)
        {
            bool       result          = false;
            const auto object_iterator = m_object_ptrs.find(in_id);

            vkgl_assert(object_iterator != m_object_ptrs.end() );
            if (object_iterator != m_object_ptrs.end() )
            {
                const auto n_nontot_references = object_iterator->second->snapshot_manager_ptr->get_n_references(false /* in_include_tot_snapshots_references */);
                const auto n_snapshots         = object_iterator->second->snapshot_manager_ptr->get_n_snapshots ();

                vkgl_assert((n_snapshots == 0)                             ||
                            (n_snapshots == 1 && n_nontot_references == 0) );

                m_object_ptrs.erase(object_iterator);

                result = true;
            }

            return result;
        }

        Status get_object_status(const GLuint& in_id) const
        {
            const auto object_ptr = get_general_object_props_ptr(in_id);
            Status     result     = Status::Unknown;

            if (object_ptr != nullptr)
            {
                result = object_ptr->status;
            }

            return result;
        }

        bool insert_object(const GLuint& in_id)
        {
            bool       result          = false;
            const auto object_iterator = m_object_ptrs.find(in_id);

            /* TODO: This assertion check will trigger when:
             *
             * 1. Frontend creates an object.
             * 2. Frontend schedules ops operating on the object for execution in the backend.
             * 3. Frontend immediately destroys an object.
             *
             * Need to move about-to-be-destroyed object descriptors with pending references to a separate map.
             */
            vkgl_assert(object_iterator == m_object_ptrs.end() );
            if (object_iterator == m_object_ptrs.end() )
            {
                std::unique_ptr<GeneralObjectProps> new_object_ptr;

                new_object_ptr.reset(
                    new GeneralObjectProps(dynamic_cast<IStateSnapshotAccessors*>(this),
                                           in_id,
                                           std::bind(&OpenGL::GLObjectManager<ObjectReferenceType, ObjectReferenceUniquePtrType>::on_all_snapshot_references_deleted,
                                                     this,
                                                     in_id))
                );

                vkgl_assert(new_object_ptr != nullptr);

                m_object_ptrs[in_id] = std::move(new_object_ptr);
                result               = true;
            }

            return result;
        }

        bool is_id_valid(const GLuint& in_id) const
        {
            const auto object_iterator = m_object_ptrs.find(in_id);

            return (object_iterator != m_object_ptrs.end() );
        }

        void on_all_snapshot_references_deleted(GLuint in_id)
        {
            /* If the object has been destroyed AND there are no more dangling refernces, destroy
             * the container. Otherwise, retain it.
             */
            const auto status = get_object_status(in_id);

            if (status == Status::Deleted_References_Pending)
            {
                delete_object(in_id);
            }
        }

        bool set_object_status(const GLuint& in_id,
                               const Status& in_new_status)
        {
            bool result     = false;
            auto object_ptr = get_general_object_props_ptr(in_id);

            if (object_ptr != nullptr)
            {
                object_ptr->status = in_new_status;

                result = true;
            }

            return result;
        }

        GeneralObjectProps* get_general_object_props_ptr(const GLuint& in_id)
        {
            GeneralObjectProps* result_ptr     = nullptr;
            const auto          object_iterator = m_object_ptrs.find(in_id);

            vkgl_assert(object_iterator != m_object_ptrs.end() );
            if (object_iterator != m_object_ptrs.end() )
            {
                result_ptr = object_iterator->second.get();
            }

            return result_ptr;
        }

        /* Private variables */
        std::unordered_map<GLuint, std::unique_ptr<GeneralObjectProps> > m_object_ptrs;

        friend ObjectReferenceType;
    };
}
#endif /* VKGL_GL_OBJECT_MANAGER_H */