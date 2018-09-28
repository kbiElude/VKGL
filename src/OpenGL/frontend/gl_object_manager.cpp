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

OpenGL::GLReferenceUniquePtr OpenGL::GLObjectManager::acquire_reference(const GLuint& in_id)
{
    /* For acquisition requests coming from non-reference objects, which this entrypoint handles,
     * make sure frontend *always* uses the latest version of the object's state available.
     * When frontend decides to pass a call over to backend, it will create a new reference and
     * replace the snapshot version setting with the version of the snapshot available at the time of the call.
     *
     * Note that older snapshots may still be in use by backend. This is fine.
     *
     * Note that GLReference constructor calls GLObjectManager::on_reference_created() to bump up the latest
     * snapshot's ref counter, which is how we guarantee the snapshot does not go out of scope until
     * all backend users are done using it.
     *
     * Note: this entrypoint will never be called outside of application's rendering context thread.
     */
    OpenGL::GLReferenceUniquePtr result_ptr;

    result_ptr = acquire_reference(in_id,
                                   OpenGL::LATEST_SNAPSHOT_AVAILABLE);

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
        vkgl_assert(object_iterator->second->references.size() == 0);

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

const void* OpenGL::GLObjectManager::get_internal_object_props_ptr(const GLuint& in_id) const
{
    const auto  props_ptr  = get_general_object_props_ptr(in_id);
    const void* result_ptr = nullptr;

    if (props_ptr != nullptr)
    {
        result_ptr = props_ptr->internal_data_ptr.get();
    }

    return result_ptr;
}

void* OpenGL::GLObjectManager::get_internal_object_props_ptr(const GLuint& in_id)
{
    const auto props_ptr  = get_general_object_props_ptr(in_id);
    void*      result_ptr = nullptr;

    if (props_ptr != nullptr)
    {
        result_ptr = props_ptr->internal_data_ptr.get();
    }

    return result_ptr;
}

uint32_t OpenGL::GLObjectManager::get_n_references(const GLuint& in_id) const
{
    auto     object_ptr = get_general_object_props_ptr(in_id);
    uint32_t result     = 0;

    if (object_ptr != nullptr)
    {
        result = static_cast<uint32_t>(object_ptr->references.size() );
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
        m_default_object_reference_ptr = acquire_reference(0 /* in_id */);

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
        m_object_ptrs[in_id].reset(
            new GeneralObjectProps(in_id)
        );

        vkgl_assert(m_object_ptrs.at(in_id) != nullptr);

        m_object_ptrs[in_id]->internal_data_ptr = create_internal_data_object(in_id);
        result                                  = true;
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

    bool result    = false;
    auto props_ptr = get_general_object_props_ptr(in_reference_ptr->get_id() );

    if (props_ptr != nullptr)
    {
        props_ptr->references.push_back(in_reference_ptr);

        result = true;
    }

    vkgl_assert(result);
}

void OpenGL::GLObjectManager::on_reference_destroyed(const OpenGL::GLReference* in_reference_ptr)
{
    const auto object_id = in_reference_ptr->get_id();

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
                auto reference_iterator = std::find(object_ptr->references.begin(),
                                                    object_ptr->references.end  (),
                                                    in_reference_ptr);

                vkgl_assert(reference_iterator != object_ptr->references.end() );
                if (reference_iterator != object_ptr->references.end() )
                {
                    object_ptr->references.erase(reference_iterator);
                }
            }
        }

        /* If the object has been destroyed AND there are no more dangling refernces, destroy
         * the container. Otherwise, retain it.
         */
        if ((status                      == Status::Created_Not_Bound           ||
             status                      == Status::Deleted_References_Pending) &&
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
        object_ptr->last_modified_time = std::chrono::high_resolution_clock::now();
    }
}