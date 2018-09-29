/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/gl_reference.h"

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

OpenGL::GLReferenceUniquePtr OpenGL::GLObjectManager::acquire_always_latest_snapshot_reference(const GLuint& in_id)
{
    OpenGL::GLReferenceUniquePtr result_ptr;

    result_ptr = acquire_reference(in_id,
                                   OpenGL::LATEST_SNAPSHOT_AVAILABLE);

    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

OpenGL::GLReferenceUniquePtr OpenGL::GLObjectManager::acquire_current_latest_snapshot_reference(const GLuint& in_id)
{
    /* NOTE: Must only be called from rendering context's thread */
    OpenGL::GLReferenceUniquePtr result_ptr;

    result_ptr = acquire_reference(in_id,
                                   get_general_object_props_ptr(in_id)->last_modified_time);

    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

OpenGL::GLReferenceUniquePtr OpenGL::GLObjectManager::acquire_reference(const GLuint&              in_id,
                                                                        const OpenGL::TimeMarker&  in_time_marker)
{
    OpenGL::GLReferenceUniquePtr result_ptr(nullptr,
                                            std::default_delete<OpenGL::GLReference>() );

    {
        std::unique_lock<std::mutex> lock(m_lock);

        #if defined(_DEBUG)
        {
            const auto object_status = get_object_status(in_id);

            vkgl_assert(object_status != Status::Deleted_References_Pending &&
                        object_status != Status::Unknown);
        }
        #endif

        result_ptr.reset(
            new GLReference(in_id,
                            in_time_marker,
                            dynamic_cast<IObjectManagerReference*>(this) )
        );

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
        auto lock = std::unique_lock<std::mutex>(m_lock);

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
            if (get_n_references(current_id) == 0)
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
        vkgl_assert((object_iterator->second->snapshots.size() == 0)                                                                               ||
                    (object_iterator->second->snapshots.size() == 1 && object_iterator->second->snapshots.begin()->second->references.size() == 0) );

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

OpenGL::GLReferenceUniquePtr OpenGL::GLObjectManager::get_default_object_reference() const
{
    /* Default object NEVER goes out of scope. Hence, we wrap a raw ptr to the pre-baked reference and make
     * sure the destructor never gets called.
     */
    vkgl_assert(m_expose_default_object);

    return OpenGL::GLReferenceUniquePtr(m_default_object_reference_ptr.get(),
                                        [](OpenGL::GLReference*){ /* Stub */});
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
        const OpenGL::TimeMarker time_marker       = (in_opt_time_marker_ptr == nullptr)                                                                 ? props_ptr->last_modified_time
                                                   : (in_opt_time_marker_ptr != nullptr && *in_opt_time_marker_ptr == OpenGL::LATEST_SNAPSHOT_AVAILABLE) ? props_ptr->last_modified_time
                                                   : *in_opt_time_marker_ptr;
        auto                     snapshot_iterator = props_ptr->snapshots.find(time_marker);

        vkgl_assert(snapshot_iterator != props_ptr->snapshots.end() );
        if (snapshot_iterator != props_ptr->snapshots.end() )
        {
            result_ptr = snapshot_iterator->second->internal_data_ptr.get();
        }
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
        const OpenGL::TimeMarker time_marker       = (in_opt_time_marker_ptr == nullptr)                                                                 ? props_ptr->last_modified_time
                                                   : (in_opt_time_marker_ptr != nullptr && *in_opt_time_marker_ptr == OpenGL::LATEST_SNAPSHOT_AVAILABLE) ? props_ptr->last_modified_time
                                                   : *in_opt_time_marker_ptr;
        auto                     snapshot_iterator = props_ptr->snapshots.find(time_marker);

        /* NOTE: This function must ONLY be called for potential update purposes. State updates can only be performed
         *       against ToT state snapshots.
         *
         *       This is because this function always returns a scratch version of the ToT snapshot. At update_last_modified_time()
         *       call time, this scratch version will be cached in the snapshot map as the new ToT version of the represented state.
         *       (there are special case(s) where this process is performed slightly different; see the func in question for more details)
         *
         *       If update_last_modified_time() is NOT called after this call, it is assumed inheriting manager class has NOT modified the opaque state
         *       in any way.
         *
         *       If you hit this assertion check, you're using the incorrect version of the function. Make sure to use the const one.
         */
        vkgl_assert(time_marker == props_ptr->last_modified_time);

        result_ptr = props_ptr->scratch_snapshot_ptr.get();
    }

    return result_ptr;
}

uint32_t OpenGL::GLObjectManager::get_n_references(const GLuint& in_id) const
{
    auto     object_ptr = get_general_object_props_ptr(in_id);
    uint32_t result     = 0;

    if (object_ptr != nullptr)
    {
        for (const auto& current_snapshot : object_ptr->snapshots)
        {
            result += static_cast<uint32_t>(current_snapshot.second->references.size() );
        }

        result += static_cast<uint32_t>(object_ptr->tot_snapshot_references.size() );
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

    vkgl_assert(object_iterator == m_object_ptrs.end() );
    if (object_iterator == m_object_ptrs.end() )
    {
        std::unique_ptr<GeneralObjectProps> new_object_ptr;

        new_object_ptr.reset(new GeneralObjectProps(in_id) );
        vkgl_assert(new_object_ptr != nullptr);

        {
            GeneralObjectStateSnapshotUniquePtr new_snapshot_ptr(new GeneralObjectStateSnapshot(),
                                                                 std::default_delete<GeneralObjectStateSnapshot>() );

            vkgl_assert(new_snapshot_ptr != nullptr);

            /* Create a base snapshot. */
            new_snapshot_ptr->internal_data_ptr = create_internal_data_object();
            vkgl_assert(new_snapshot_ptr->internal_data_ptr != nullptr);

            /* Create a scratch version of the base snapshot. The scratch clone will be used for potential update
             * operations requested by inheriting buffers. Please see get_internal_object_props_ptr() (non-const version)
             * and update_last_modified_time() for more details.
             */
            new_object_ptr->scratch_snapshot_ptr = clone_internal_data_object(new_snapshot_ptr->internal_data_ptr.get() );
            vkgl_assert(new_object_ptr->scratch_snapshot_ptr != nullptr);

            /* Stash the base snapshot. */
            new_object_ptr->snapshots[new_object_ptr->last_modified_time] = std::move(new_snapshot_ptr);
        }

        m_object_ptrs[in_id] = std::move(new_object_ptr);
        result               = true;
    }

    return result;
}

bool OpenGL::GLObjectManager::is_alive_id(const GLuint& in_id) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock    (m_lock);
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

bool OpenGL::GLObjectManager::mark_id_as_alive(const GLuint& in_id)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock(m_lock);
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

void OpenGL::GLObjectManager::on_reference_created(const OpenGL::GLReference* in_reference_ptr)
{
    /* Note: m_lock is locked at this point. */
    auto props_ptr = get_general_object_props_ptr(in_reference_ptr->get_id() );
    bool result    = false;

    vkgl_assert(props_ptr != nullptr);
    if (props_ptr != nullptr)
    {
        if (in_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE)
        {
            auto snapshot_iterator = props_ptr->snapshots.find(in_reference_ptr->get_time_marker() );

            vkgl_assert(snapshot_iterator != props_ptr->snapshots.end() )
            if (snapshot_iterator != props_ptr->snapshots.end() )
            {
                snapshot_iterator->second->references.push_back(in_reference_ptr);
            }

            result = true;
        }
        else
        {
            props_ptr->tot_snapshot_references.push_back(in_reference_ptr);

            result = true;
        }
    }

    vkgl_assert(result);
}

void OpenGL::GLObjectManager::on_reference_destroyed(const OpenGL::GLReference* in_reference_ptr)
{
    const auto object_id          = in_reference_ptr->get_id         ();
    const auto object_time_marker = in_reference_ptr->get_time_marker();

    if (m_releasing)
    {
        /* Do NOT proceed. The manager is being released and the deriving class' functions
         * we would need to call are pure virtual at this point.
         *
         * Since all objects are wrapped into unique ptrs, they will ultimately dealloc themselves
         * automagically anyway.
         */
        return;
    }

    {
        auto       lock   = std::unique_lock<std::mutex>(m_lock);
        const auto status = get_object_status           (object_id);

        /* Release the reference .. */
        {
            auto object_ptr = get_general_object_props_ptr(object_id);

            vkgl_assert(object_ptr != nullptr);
            if (object_ptr != nullptr)
            {
                if (in_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE)
                {
                    auto snapshot_iterator = object_ptr->snapshots.find(object_time_marker);

                    vkgl_assert(snapshot_iterator != object_ptr->snapshots.end() );
                    if (snapshot_iterator != object_ptr->snapshots.end() )
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
                                if (snapshot_iterator->first < object_ptr->last_modified_time)
                                {
                                    object_ptr->snapshots.erase(snapshot_iterator);
                                }
                            }
                        }
                    }
                }
                else
                {
                    auto reference_iterator = std::find(object_ptr->tot_snapshot_references.begin(),
                                                        object_ptr->tot_snapshot_references.end  (),
                                                        in_reference_ptr);

                    vkgl_assert(reference_iterator != object_ptr->tot_snapshot_references.end() );
                    if ((reference_iterator != object_ptr->tot_snapshot_references.end() ))
                    {
                        object_ptr->tot_snapshot_references.erase(reference_iterator);
                    }
                }
            }
        }

        /* If the object has been destroyed AND there are no more dangling refernces, destroy
         * the container. Otherwise, retain it.
         */
        if ((status                      == Status::Deleted_References_Pending) &&
            (get_n_references(object_id) == 0) )
        {
            delete_object(object_id);
        }
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

void OpenGL::GLObjectManager::update_last_modified_time(const GLuint& in_id)
{
    auto object_ptr = get_general_object_props_ptr(in_id);

    vkgl_assert(object_ptr != nullptr);
    if (object_ptr != nullptr)
    {
        const auto old_last_modified_time   = object_ptr->last_modified_time;
        void*      old_scratch_snapshot_ptr = nullptr;

        /* Update the "last modified time" timestamp */
        object_ptr->last_modified_time = std::chrono::high_resolution_clock::now();

        /* Insert a new ToT snapshot, set it to the scratch state we passed in the preceding
         * get_internal_object_props_ptr() call time.
         */
        {
            std::unique_ptr<GeneralObjectStateSnapshot> new_snapshot_ptr;

            vkgl_assert(object_ptr->snapshots.find(object_ptr->last_modified_time) == object_ptr->snapshots.end() );

            new_snapshot_ptr.reset(new GeneralObjectStateSnapshot() );
            vkgl_assert(new_snapshot_ptr != nullptr);

            old_scratch_snapshot_ptr            = object_ptr->scratch_snapshot_ptr.get();
            new_snapshot_ptr->internal_data_ptr = std::move(object_ptr->scratch_snapshot_ptr);

            object_ptr->snapshots[object_ptr->last_modified_time] = std::move(new_snapshot_ptr);
        }

        /* Create a new scratch state. */
        object_ptr->scratch_snapshot_ptr = clone_internal_data_object(old_scratch_snapshot_ptr);
        vkgl_assert(object_ptr->scratch_snapshot_ptr != nullptr);

        /* Check if the previous ToT snapshot is being referenced. If not, it's safe to drop it.
         * If there's at least 1 reference, the snapshot will be removed at some point in on_reference_destroyed()
         */
        if (object_ptr->snapshots.at(old_last_modified_time)->references.size() == 0)
        {
            object_ptr->snapshots.erase(old_last_modified_time);
        }
    }
}