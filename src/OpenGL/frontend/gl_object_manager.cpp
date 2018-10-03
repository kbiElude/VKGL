/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/snapshot_manager.h"

OpenGL::GLObjectManager::GLObjectManager(const GLuint& in_first_valid_nondefault_id,
                                         const bool&   in_expose_default_object)
    :m_expose_default_object    (in_expose_default_object),
     m_first_valid_nondefault_id(in_first_valid_nondefault_id),
     m_releasing                (false)
{
    /*  Stub */
}

OpenGL::GLObjectManager::~GLObjectManager()
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

OpenGL::ReferenceUniquePtr OpenGL::GLObjectManager::acquire_always_latest_snapshot_reference(const GLuint& in_id)
{
    OpenGL::ReferenceUniquePtr result_ptr;

    result_ptr = acquire_reference(in_id,
                                   OpenGL::LATEST_SNAPSHOT_AVAILABLE);

    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

OpenGL::ReferenceUniquePtr OpenGL::GLObjectManager::acquire_current_latest_snapshot_reference(const GLuint& in_id)
{
    /* NOTE: Must only be called from rendering context's thread */
    OpenGL::ReferenceUniquePtr result_ptr;

    result_ptr = acquire_reference(in_id,
                                   get_general_object_props_ptr(in_id)->snapshot_manager_ptr->get_last_modified_time() );

    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

OpenGL::ReferenceUniquePtr OpenGL::GLObjectManager::acquire_reference(const GLuint&              in_id,
                                                                      const OpenGL::TimeMarker&  in_time_marker)
{
    OpenGL::ReferenceUniquePtr result_ptr(nullptr,
                                          std::default_delete<OpenGL::Reference>() );

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

bool OpenGL::GLObjectManager::delete_ids(const uint32_t& in_n_ids,
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

bool OpenGL::GLObjectManager::delete_object(const GLuint& in_id)
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

bool OpenGL::GLObjectManager::generate_ids(const uint32_t& in_n_ids,
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

OpenGL::ReferenceUniquePtr OpenGL::GLObjectManager::get_default_object_reference() const
{
    /* Default object NEVER goes out of scope. Hence, we wrap a raw ptr to the pre-baked reference and make
     * sure the destructor never gets called.
     */
    vkgl_assert(m_expose_default_object);

    return OpenGL::ReferenceUniquePtr(m_default_object_reference_ptr.get(),
                                      [](OpenGL::Reference*){ /* Stub */});
}

const OpenGL::GLObjectManager::GeneralObjectProps* OpenGL::GLObjectManager::get_general_object_props_ptr(const GLuint& in_id) const
{
    OpenGL::GLObjectManager::GeneralObjectProps* result_ptr     = nullptr;
    const auto                                   object_iterator = m_object_ptrs.find(in_id);

    vkgl_assert(object_iterator != m_object_ptrs.end() );
    if (object_iterator != m_object_ptrs.end() )
    {
        result_ptr = object_iterator->second.get();
    }

    return result_ptr;
}

OpenGL::GLObjectManager::GeneralObjectProps* OpenGL::GLObjectManager::get_general_object_props_ptr(const GLuint& in_id)
{
    OpenGL::GLObjectManager::GeneralObjectProps* result_ptr     = nullptr;
    const auto                                   object_iterator = m_object_ptrs.find(in_id);

    vkgl_assert(object_iterator != m_object_ptrs.end() );
    if (object_iterator != m_object_ptrs.end() )
    {
        result_ptr = object_iterator->second.get();
    }

    return result_ptr;
}

const void* OpenGL::GLObjectManager::get_internal_object_props_ptr(const GLuint&             in_id,
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

void* OpenGL::GLObjectManager::get_internal_object_props_ptr(const GLuint&             in_id,
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

OpenGL::TimeMarker OpenGL::GLObjectManager::get_object_creation_time(const GLuint& in_id) const
{
    const auto         props_ptr = get_general_object_props_ptr(in_id);
    OpenGL::TimeMarker result;

    if (props_ptr != nullptr)
    {
        result = props_ptr->creation_time;
    }

    return result;
}

OpenGL::GLObjectManager::Status OpenGL::GLObjectManager::get_object_status(const GLuint& in_id) const
{
    const auto                      object_ptr = get_general_object_props_ptr(in_id);
    OpenGL::GLObjectManager::Status result     = OpenGL::GLObjectManager::Status::Unknown;

    if (object_ptr != nullptr)
    {
        result = object_ptr->status;
    }

    return result;
}

bool OpenGL::GLObjectManager::init()
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

bool OpenGL::GLObjectManager::insert_object(const GLuint& in_id)
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
                                   std::bind(&OpenGL::GLObjectManager::on_all_snapshot_references_deleted,
                                             this,
                                             in_id))
        );

        vkgl_assert(new_object_ptr != nullptr);

        m_object_ptrs[in_id] = std::move(new_object_ptr);
        result               = true;
    }

    return result;
}

bool OpenGL::GLObjectManager::is_alive_id(const GLuint& in_id) const
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

bool OpenGL::GLObjectManager::is_id_valid(const GLuint& in_id) const
{
    const auto object_iterator = m_object_ptrs.find(in_id);

    return (object_iterator != m_object_ptrs.end() );
}

bool OpenGL::GLObjectManager::is_object_deleted(const GLuint& in_id) const
{
    return get_object_status(in_id) == Status::Deleted_References_Pending;
}

bool OpenGL::GLObjectManager::mark_id_as_alive(const GLuint& in_id)
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

void OpenGL::GLObjectManager::on_all_snapshot_references_deleted(GLuint in_id)
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

bool OpenGL::GLObjectManager::set_object_status(const GLuint& in_id,
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

bool OpenGL::GLObjectManager::update_last_modified_time(const GLuint& in_id)
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