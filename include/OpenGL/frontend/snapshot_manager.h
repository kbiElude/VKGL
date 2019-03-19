/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_SNAPSHOT_MANAGER_H
#define VKGL_SNAPSHOT_MANAGER_H

#include "OpenGL/types.h"
#include <map>

namespace OpenGL
{
    template<typename ObjectReferenceType>
    class ISnapshotManagerReference
    {
    public:
        virtual ~ISnapshotManagerReference()
        {
            /* Stub */
        }

        virtual void on_reference_created  (const ObjectReferenceType* in_reference_ptr) = 0;
        virtual void on_reference_destroyed(const ObjectReferenceType* in_reference_ptr) = 0;
    };

    template<typename ObjectReferenceType,
             typename ObjectReferenceUniquePtrType,
             typename PayloadType>
    class SnapshotManager : public ISnapshotManagerReference<ObjectReferenceType>
    {
    public:
        /* Public functions */
        SnapshotManager(const GLuint&             in_object_id,
                        IStateSnapshotAccessors*  in_state_snapshot_accesors_ptr,
                        const OpenGL::TimeMarker& in_start_time_marker,
                        std::function<void()>     in_on_all_references_deleted_func)
            :m_last_modified_time            (in_start_time_marker),
             m_object_id                     (in_object_id),
             m_on_all_references_deleted_func(in_on_all_references_deleted_func),
             m_state_snapshot_accesors_ptr   (in_state_snapshot_accesors_ptr)
        {
            StateSnapshotUniquePtr new_snapshot_ptr(new StateSnapshot(),
                                                    std::default_delete<StateSnapshot>() );

            vkgl_assert(new_snapshot_ptr != nullptr);

            /* Create a base snapshot. */
            new_snapshot_ptr->internal_data_proxy_ptr = m_state_snapshot_accesors_ptr->create_internal_data_object();
            vkgl_assert(new_snapshot_ptr->internal_data_proxy_ptr != nullptr);

            new_snapshot_ptr->internal_data_nonproxy_ptr = m_state_snapshot_accesors_ptr->clone_internal_data_object(new_snapshot_ptr->internal_data_proxy_ptr.get(),
                                                                                                                     true /* in_convert_from_proxy_to_nonproxy */);
            vkgl_assert(new_snapshot_ptr->internal_data_nonproxy_ptr != nullptr);

            /* Create a scratch version of the base snapshot. The scratch clone will be used for potential update
             * operations requested by inheriting buffers. Please see get_internal_object_props_ptr() (non-const version)
             * and update_last_modified_time() for more details.
             */
            m_scratch_snapshot_ptr = m_state_snapshot_accesors_ptr->clone_internal_data_object(new_snapshot_ptr->internal_data_proxy_ptr.get(),
                                                                                               false /* in_convert_from_proxy_to_nonproxy */);

            vkgl_assert(m_scratch_snapshot_ptr != nullptr);

            /* Stash the base snapshot. */
            m_snapshots[m_last_modified_time] = std::move(new_snapshot_ptr);
        }

        ObjectReferenceUniquePtrType acquire_reference(const PayloadType& in_payload)
        {
            ObjectReferenceUniquePtrType result_ptr(nullptr,
                                                    std::default_delete<ObjectReferenceType>() );

            auto on_reference_created_func   = std::bind(&OpenGL::SnapshotManager<ObjectReferenceType, ObjectReferenceUniquePtrType, PayloadType>::on_reference_created,
                                                         this,
                                                         std::placeholders::_1);
            auto on_reference_destroyed_func = std::bind(&OpenGL::SnapshotManager<ObjectReferenceType, ObjectReferenceUniquePtrType, PayloadType>::on_reference_destroyed,
                                                         this,
                                                         std::placeholders::_1);
            auto acquire_reference_func      = std::bind(&OpenGL::SnapshotManager<ObjectReferenceType, ObjectReferenceUniquePtrType, PayloadType>::acquire_reference,
                                                         this,
                                                         in_payload);

            result_ptr.reset(
                new ObjectReferenceType(in_payload,
                                        on_reference_created_func,
                                        on_reference_destroyed_func,
                                        acquire_reference_func)
            );

            if (result_ptr == nullptr)
            {
                vkgl_assert(result_ptr != nullptr);

                goto end;
            }

        end:
            return result_ptr;
        }

        const OpenGL::TimeMarker& get_last_modified_time() const
        {
            return m_last_modified_time;
        }

        uint32_t get_n_references(const bool& in_include_tot_snapshot_references) const
        {
            auto     lock   = std::unique_lock<std::mutex>(m_mutex);
            uint32_t result = 0;

            for (const auto& current_snapshot : m_snapshots)
            {
                result += static_cast<uint32_t>(current_snapshot.second->references.size() );
            }

            if (in_include_tot_snapshot_references)
            {
                result += static_cast<uint32_t>(m_tot_snapshot_references.size() );
            }

            return result;
        }

        uint32_t get_n_snapshots () const
        {
            return static_cast<uint32_t>(m_snapshots.size() );
        }

        const void* get_readonly_snapshot(const OpenGL::TimeMarker& in_time_marker,
                                         const bool&                in_proxy_references_permitted) const
        {
            auto        lock              = std::unique_lock<std::mutex>(m_mutex);
            const void* result_ptr        = nullptr;
            const auto  time_marker       = (in_time_marker == OpenGL::LATEST_SNAPSHOT_AVAILABLE) ? m_last_modified_time
                                                                                                  : in_time_marker;
            auto        snapshot_iterator = m_snapshots.find(time_marker);

            vkgl_assert(snapshot_iterator != m_snapshots.end() );
            if (snapshot_iterator != m_snapshots.end() )
            {
                result_ptr = (in_proxy_references_permitted) ? snapshot_iterator->second->internal_data_proxy_ptr.get   ()
                                                             : snapshot_iterator->second->internal_data_nonproxy_ptr.get();
            }

            return result_ptr;
        }

        void* get_rw_tot_snapshot()
        {
            return m_scratch_snapshot_ptr.get();
        }

        void update_last_modified_time()
        {
            auto       lock                   = std::unique_lock<std::mutex>(m_mutex);
            const auto old_last_modified_time = m_last_modified_time;

            /* Update the "last modified time" timestamp */
            m_last_modified_time = std::chrono::high_resolution_clock::now();

            /* SLOW PATH: Insert a new ToT snapshot, set it to the scratch state we passed in the preceding
             *            get_internal_object_props_ptr() call time.
             * FAST PATH: Make the current scratch snapshot the new ToT snapshot. Copy its contents over
             *            to the former ToT snapshot and make it the new scratch snapshot. This saves us at least one mem alloc op.
             *
             * TODO: For immutable objects, we should always use a SUPER-FAST PATH which assumes only one snapshot will ever be needed,
             *       meaning we don't actually need the scratch/ToT distinction.
             *
             * NOTE: Fast path can only be exercised if about-to-become-obsolete ToT snapshot has zero non-ToT references
             *       (meaning there are outstanding backend ops which depend on the snapshot's existence).
             */
            {
                auto old_snapshot_iterator = m_snapshots.find(old_last_modified_time);

                if (old_snapshot_iterator->second->references.size() == 0)
                {
                    /* FAST PATH */
                    {
                        /* Copy scratch state to the snapshot.. */
                        m_state_snapshot_accesors_ptr->copy_internal_data_object(m_scratch_snapshot_ptr.get                                (),
                                                                                 old_snapshot_iterator->second->internal_data_proxy_ptr.get() );

                        old_snapshot_iterator->second->internal_data_nonproxy_ptr = m_state_snapshot_accesors_ptr->clone_internal_data_object(old_snapshot_iterator->second->internal_data_proxy_ptr.get(),
                                                                                                                                              true /* in_convert_from_proxy_to_nonproxy */);

                        /* Move snapshot descriptor under the new timestamp */
                        m_snapshots[m_last_modified_time] = std::move(old_snapshot_iterator->second);
                    }

                    /* Drop the old snapshot map entry */
                    m_snapshots.erase(old_last_modified_time);
                }
                else
                {
                    /* SLOW PATH */
                    std::unique_ptr<StateSnapshot> new_snapshot_ptr;
                    void*                          old_scratch_snapshot_ptr = nullptr;

                    vkgl_assert(m_snapshots.find(m_last_modified_time) == m_snapshots.end() );

                    new_snapshot_ptr.reset(new StateSnapshot() );
                    vkgl_assert(new_snapshot_ptr != nullptr);

                    old_scratch_snapshot_ptr                  = m_scratch_snapshot_ptr.get();
                    new_snapshot_ptr->internal_data_proxy_ptr = std::move(m_scratch_snapshot_ptr);

                    new_snapshot_ptr->internal_data_nonproxy_ptr = m_state_snapshot_accesors_ptr->clone_internal_data_object(new_snapshot_ptr->internal_data_proxy_ptr.get(),
                                                                                                                             true /* in_convert_from_proxy_to_nonproxy */);

                    m_snapshots[m_last_modified_time] = std::move(new_snapshot_ptr);

                    /* Create a new scratch state. */
                    m_scratch_snapshot_ptr = m_state_snapshot_accesors_ptr->clone_internal_data_object(old_scratch_snapshot_ptr,
                                                                                                       false /* in_convert_from_proxy_to_nonproxy */);
                    vkgl_assert(m_scratch_snapshot_ptr != nullptr);

                    /* Check if the previous ToT snapshot is being referenced. If not, it's safe to drop it.
                     * If there's at least 1 reference, the snapshot will be removed at some point in on_reference_destroyed()
                     */
                    if (m_snapshots.at(old_last_modified_time)->references.size() == 0)
                    {
                        m_snapshots.erase(old_last_modified_time);
                    }

                }
            }
        }

    private:
        /* Private type definitions */
        typedef struct
        {
            std::unique_ptr<void, std::function<void(void*)> > internal_data_nonproxy_ptr; /* all object references forbidden to have ALWAYS_LATEST timestamps                */
            std::unique_ptr<void, std::function<void(void*)> > internal_data_proxy_ptr;    /* any object reference embedded within is allowed to have ALWAYS_LATEST timestamp */
            std::vector<const ObjectReferenceType*>            references;
        } StateSnapshot;
        typedef std::unique_ptr<StateSnapshot> StateSnapshotUniquePtr;

        /* ISnapshotManagerReference */

        void on_reference_created(const ObjectReferenceType* in_reference_ptr) final
        {
            auto lock = std::unique_lock<std::mutex>(m_mutex);

            if (in_reference_ptr->get_payload().time_marker != OpenGL::LATEST_SNAPSHOT_AVAILABLE)
            {
                auto snapshot_iterator = m_snapshots.find(in_reference_ptr->get_payload().time_marker);

                vkgl_assert(snapshot_iterator != m_snapshots.end() )
                if (snapshot_iterator != m_snapshots.end() )
                {
                    snapshot_iterator->second->references.push_back(in_reference_ptr);
                }
            }
            else
            {
                m_tot_snapshot_references.push_back(in_reference_ptr);
            }
        }

        void on_reference_destroyed(const ObjectReferenceType* in_reference_ptr) final
        {
            const auto object_time_marker = in_reference_ptr->get_payload().time_marker;

            {
                auto lock = std::unique_lock<std::mutex>(m_mutex);

                /* Release the reference .. */
                {
                    if (in_reference_ptr->get_payload().time_marker != OpenGL::LATEST_SNAPSHOT_AVAILABLE)
                    {
                        auto snapshot_iterator = m_snapshots.find(object_time_marker);

                        vkgl_assert(snapshot_iterator != m_snapshots.end() );
                        if (snapshot_iterator != m_snapshots.end() )
                        {
                            auto reference_iterator = std::find(snapshot_iterator->second->references.begin(),
                                                                snapshot_iterator->second->references.end  (),
                                                                in_reference_ptr);

                            vkgl_assert(reference_iterator != snapshot_iterator->second->references.end() );
                            if (reference_iterator != snapshot_iterator->second->references.end() )
                            {
                                snapshot_iterator->second->references.erase(reference_iterator);

                                if (snapshot_iterator->second->references.size() == 0)
                                {
                                    /* The snapshot is no longer being referenced anywhere. If there are newer snapshots
                                     * available, it's safe to release this object.
                                     */
                                    if (snapshot_iterator->first < m_last_modified_time)
                                    {
                                        m_snapshots.erase(snapshot_iterator);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        auto reference_iterator = std::find(m_tot_snapshot_references.begin(),
                                                            m_tot_snapshot_references.end  (),
                                                            in_reference_ptr);

                        vkgl_assert(reference_iterator != m_tot_snapshot_references.end() );
                        if ((reference_iterator != m_tot_snapshot_references.end() ))
                        {
                            m_tot_snapshot_references.erase(reference_iterator);
                        }
                    }
                }
            }

            if (get_n_references(true /* in_include_tot_snapshot_references */) == 0       &&
                m_on_all_references_deleted_func                                != nullptr)
            {
                m_on_all_references_deleted_func();
            }
        }

        /* Private variables */
        OpenGL::TimeMarker                                   m_last_modified_time;
        mutable std::mutex                                   m_mutex;
        const GLuint                                         m_object_id;
        std::unique_ptr<void, std::function<void(void*)> >   m_scratch_snapshot_ptr;
        std::map<OpenGL::TimeMarker, StateSnapshotUniquePtr> m_snapshots;
        std::vector<const ObjectReferenceType*>              m_tot_snapshot_references;

        std::function<void()>    m_on_all_references_deleted_func;
        IStateSnapshotAccessors* m_state_snapshot_accesors_ptr;
    };
};

#endif /* VKGL_SNAPSHOT_MANAGER_H */