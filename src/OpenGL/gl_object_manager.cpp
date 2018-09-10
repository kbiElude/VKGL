/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/gl_binding.h"
#include "OpenGL/gl_object_manager.h"

OpenGL::GLObjectManager::GLObjectManager(const bool&      in_expose_default_object,
                                         const IGLLimits* in_limits_ptr)
    :m_expose_default_object(in_expose_default_object),
     m_limits_ptr           (in_limits_ptr),
     m_releasing            (false)
{
    /*  Stub */
}

OpenGL::GLObjectManager::~GLObjectManager()
{
    m_releasing = true;

    if (m_expose_default_object)
    {
        m_default_object_binding_ptr.reset();
    }
    else
    {
        vkgl_assert(m_default_object_binding_ptr == nullptr);
    }
}

OpenGL::GLBindingUniquePtr OpenGL::GLObjectManager::acquire_binding(const GLuint& in_id)
{
    OpenGL::GLBindingUniquePtr result_ptr(nullptr,
                                          std::default_delete<OpenGL::GLBinding>() );

    {
        std::unique_lock<std::mutex> lock(m_lock);

        #if defined(_DEBUG)
        {
            const auto object_status = get_object_status(in_id);

            vkgl_assert(object_status != Status::Deleted_Bindings_Pending &&
                        object_status != Status::Unknown);
        }
        #endif

        result_ptr.reset(
            new GLBinding(in_id,
                          dynamic_cast<IObjectManagerBindingRelease*>(this) )
        );

        if (result_ptr == nullptr)
        {
            vkgl_assert(result_ptr != nullptr);

            goto end;
        }

        add_binding(in_id,
                    result_ptr.get() );
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

            /* Only destroy the object *IF* there are no remaining active bindings. Otherwise, assign
             * a corresponding status to the object and leave it alone.
             */
            if (get_n_bindings(current_id) == 0)
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
                                  Status::Deleted_Bindings_Pending);
            }
        }
    }

    result = true;
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

OpenGL::GLBindingUniquePtr OpenGL::GLObjectManager::get_default_object_binding() const
{
    /* Default object NEVER goes out of scope. Hence, we wrap a raw ptr to the pre-baked binding and make
     * sure the destructor never gets called.
     */
    vkgl_assert(m_expose_default_object);

    return OpenGL::GLBindingUniquePtr(m_default_object_binding_ptr.get(),
                                      [](OpenGL::GLBinding*){ /* Stub */});
}

bool OpenGL::GLObjectManager::init()
{
    bool result = false;

    m_id_manager_ptr.reset(
        new OpenGL::Namespace((m_expose_default_object) ? 1 /* in_start_id */
                                                        : 0 /* in_start_id */)
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

        /* ..and bake a binding to the default object. It's going to live until the manager goes out of scope. */
        m_default_object_binding_ptr = acquire_binding(0 /* in_id */);

        if (m_default_object_binding_ptr == nullptr)
        {
            vkgl_assert(m_default_object_binding_ptr != nullptr);

            result = false;
            goto end;
        }
    }
end:
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

bool OpenGL::GLObjectManager::mark_id_as_bound(const GLuint& in_id)
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

void OpenGL::GLObjectManager::release_binding(const OpenGL::GLBinding* in_binding_ptr)
{
    const auto object_id = in_binding_ptr->get_id();

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

        /* Release the binding .. */
        vkgl_assert(is_id_valid(object_id) );

        delete_binding(object_id,
                       in_binding_ptr);

        /* If the object has been destroyed AND there are no more dangling refernces, destroy
         * the container. Otherwise, retain it.
         */
        if ((status                    == Status::Created_Not_Bound         ||
             status                    == Status::Deleted_Bindings_Pending) &&
            (get_n_bindings(object_id) == 0) )
        {
            delete_object(object_id);
        }
    }
}