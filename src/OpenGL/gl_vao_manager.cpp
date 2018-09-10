/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/gl_binding.h"
#include "OpenGL/gl_vao_manager.h"

OpenGL::GLVAOManager::GLVAOManager(const IGLLimits* in_limits_ptr)
    :m_limits_ptr(in_limits_ptr),
     m_releasing (false)
{
    /*  Stub */
}

OpenGL::GLVAOManager::~GLVAOManager()
{
    static const GLuint zero_vao_id = 0;

    m_releasing = true;

    m_zero_vao_binding_ptr.reset();

    delete_ids(1, /* in_n_ids */
              &zero_vao_id);
}

OpenGL::GLBindingUniquePtr OpenGL::GLVAOManager::acquire_vao(const GLuint& in_vao_id)
{
    OpenGL::GLBindingUniquePtr result_ptr(nullptr,
                                          std::default_delete<OpenGL::GLBinding>() );

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        vkgl_assert(vao_iterator->second->status == Status::Alive               ||
                    vao_iterator->second->status == Status::Created_Not_Bound);

        result_ptr.reset(
            new GLBinding(in_vao_id,
                          dynamic_cast<IGLManagerBindingRelease*>(this) )
        );

        if (result_ptr == nullptr)
        {
            vkgl_assert(result_ptr != nullptr);

            goto end;
        }

        vao_iterator->second->bindings.push_back(result_ptr.get() );
    }
end:
    return result_ptr;
}

OpenGL::GLVAOManagerUniquePtr OpenGL::GLVAOManager::create(const IGLLimits* in_limits_ptr)
{
    OpenGL::GLVAOManagerUniquePtr result_ptr;

    result_ptr.reset(new GLVAOManager(in_limits_ptr) );

    if (result_ptr == nullptr)
    {
        vkgl_assert(result_ptr != nullptr);

        goto end;
    }

    if (!result_ptr->init() )
    {
        vkgl_assert_fail();

        result_ptr.reset();
    }

end:
    return result_ptr;
}

bool OpenGL::GLVAOManager::delete_ids(const uint32_t& in_n_ids,
                                      const GLuint*   in_ids_ptr)
{
    bool result = false;

    m_id_manager_ptr->release(in_n_ids,
                              in_ids_ptr);

    {
        auto vao_lock = std::unique_lock<std::mutex>(m_vao_ptrs_lock);

        for (uint32_t n_id = 0;
                      n_id < in_n_ids;
                    ++n_id)
        {
            const auto& current_id   = in_ids_ptr[n_id];
            auto        vao_iterator = m_vao_ptrs.find(current_id);

            if (current_id  == 0      &&
                m_releasing == false)
            {
                continue;
            }

            if (vao_iterator == m_vao_ptrs.end() )
            {
                continue;
            }

            /* Only destroy the VAO *IF* there are no remaining active bindings. Otherwise, assign
             * a corresponding status to the VAO and leave the object alone.
             */
            if (vao_iterator->second->bindings.size() == 0)
            {
                m_vao_ptrs.erase(vao_iterator);
            }
            else
            {
                vkgl_assert(vao_iterator->second->status == Status::Alive              ||
                            vao_iterator->second->status == Status::Created_Not_Bound)

                vao_iterator->second->status = Status::Deleted_Bindings_Pending;
            }
        }
    }

    result = true;
    return result;
}

bool OpenGL::GLVAOManager::generate_ids(const uint32_t& in_n_ids,
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

        if (!insert_new_vao(current_id) )
        {
            vkgl_assert_fail();

            goto end;
        }
    }

    result = true;
end:
    return result;
}

OpenGL::GLBindingUniquePtr OpenGL::GLVAOManager::get_default_vao_binding() const
{
    /* Default VAO NEVER goes out of scope. Hence, we wrap a raw ptr to the pre-baked binding and make
     * sure the destructor never gets called.
     */
    return OpenGL::GLBindingUniquePtr(m_zero_vao_binding_ptr.get(),
                                      [](OpenGL::GLBinding*){ /* Stub */});
}

bool OpenGL::GLVAOManager::get_element_array_buffer_binding(const uint32_t& in_vao_id,
                                                            GLuint*         out_result_ptr) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        vkgl_assert(vao_iterator->second->status == Status::Alive);

        *out_result_ptr = vao_iterator->second->vao_ptr->element_array_buffer_binding;
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::get_vaa_property(const GLuint&                         in_vao_id,
                                            const uint32_t&                       in_n_vao_vaa,
                                            const OpenGL::VertexAttributeProperty in_pname,
                                            const OpenGL::GetSetArgumentType&     in_dst_type,
                                            void*                                 out_result_ptr) const
{
    bool                       result        = false;
    const void*                src_data_ptr  = nullptr;
    OpenGL::GetSetArgumentType src_data_type = OpenGL::GetSetArgumentType::Unknown;

    {
        std::unique_lock<std::mutex>             lock        (m_vao_ptrs_lock);
        const OpenGL::VertexAttributeArrayState* vaa_ptr     (nullptr);
        auto                                     vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        vkgl_assert(vao_iterator->second->status                                  == Status::Alive);
        vkgl_assert(vao_iterator->second->vao_ptr->vertex_attribute_arrays.size() >  in_n_vao_vaa);

        vaa_ptr = &vao_iterator->second->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa);

        switch (in_pname)
        {
            case OpenGL::VertexAttributeProperty::Array_Size:               src_data_ptr = &vaa_ptr->size;           src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int64;           break;
            case OpenGL::VertexAttributeProperty::Array_Type:               src_data_ptr = &vaa_ptr->type;           src_data_type = OpenGL::GetSetArgumentType::VertexAttributeArrayType; break;
            case OpenGL::VertexAttributeProperty::Buffer_Binding:           src_data_ptr = &vaa_ptr->buffer_binding; src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int;             break;
            case OpenGL::VertexAttributeProperty::Enabled:                  src_data_ptr = &vaa_ptr->enabled;        src_data_type = OpenGL::GetSetArgumentType::Boolean;                  break;
            case OpenGL::VertexAttributeProperty::Integer:                  src_data_ptr = &vaa_ptr->integer;        src_data_type = OpenGL::GetSetArgumentType::Boolean;                  break;
            case OpenGL::VertexAttributeProperty::Normalized:               src_data_ptr = &vaa_ptr->normalized;     src_data_type = OpenGL::GetSetArgumentType::Boolean;                  break;
            case OpenGL::VertexAttributeProperty::Pointer:                  src_data_ptr = &vaa_ptr->pointer;        src_data_type = OpenGL::GetSetArgumentType::Pointer;                  break;
            case OpenGL::VertexAttributeProperty::Stride:                   src_data_ptr = &vaa_ptr->stride;         src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int64;           break;

            case OpenGL::VertexAttributeProperty::Current_Vertex_Attribute:
            {
                /* Generic VAA attribute array data is NOT maintained by VAO manager. This case should never be called */
                vkgl_assert_fail();

                goto end;
            }

            default:
            {
                vkgl_assert_fail();

                goto end;
            }
        }

        OpenGL::Converters::convert(src_data_type,
                                    src_data_ptr,
                                    1, /* in_n_vals */
                                    in_dst_type,
                                    out_result_ptr);
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::get_vaa_state_copy(const GLuint&              in_vao_id,
                                              const uint32_t&            in_n_vao_vaa,
                                              VertexAttributeArrayState* out_result_ptr) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        vkgl_assert(vao_iterator->second->status                                  == Status::Alive);
        vkgl_assert(vao_iterator->second->vao_ptr->vertex_attribute_arrays.size() >  in_n_vao_vaa);

        *out_result_ptr = vao_iterator->second->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa);
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::init()
{
    bool result = false;

    m_id_manager_ptr.reset(
        new OpenGL::Namespace(1 /* in_start_id */)
    );

    if (m_id_manager_ptr == nullptr)
    {
        vkgl_assert(m_id_manager_ptr != nullptr);

        goto end;
    }

    /* Instantiate the default VAO. .*/
    result = insert_new_vao(0 /* in_id */);
    vkgl_assert(result);

    /* ..and bake a binding to the default VAO. It's going to live until the manager goes out of scope. */
    m_zero_vao_binding_ptr = acquire_vao(0 /* in_vao_id */);

    if (m_zero_vao_binding_ptr == nullptr)
    {
        vkgl_assert(m_zero_vao_binding_ptr != nullptr);

        result = false;
        goto end;
    }

end:
    return result;
}

bool OpenGL::GLVAOManager::insert_new_vao(const GLuint& in_id)
{
    const auto           n_max_vertex_attribs = m_limits_ptr->get_max_vertex_attribs();
    std::unique_ptr<VAO> new_vao_ptr;
    bool                 result               = false;

    new_vao_ptr.reset( new VAO() );

    if (new_vao_ptr == nullptr)
    {
        vkgl_assert(new_vao_ptr != nullptr);

        goto end;
    }

    new_vao_ptr->vao_ptr.reset(
        new OpenGL::VertexArrayObjectState(n_max_vertex_attribs)
    );

    if (new_vao_ptr->vao_ptr == nullptr)
    {
        vkgl_assert(new_vao_ptr->vao_ptr != nullptr);

        goto end;
    }

    new_vao_ptr->id     = in_id;
    new_vao_ptr->status = Status::Created_Not_Bound;

    {
        std::unique_lock<std::mutex> lock(m_vao_ptrs_lock);

        vkgl_assert(m_vao_ptrs.find(in_id) == m_vao_ptrs.end() );

        m_vao_ptrs[in_id] = std::move(new_vao_ptr);
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::is_alive_id(const GLuint& in_id) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            goto end;
        }

        result = (vao_iterator->second->status == Status::Alive);
    }
end:
    return result;
}

bool OpenGL::GLVAOManager::mark_id_as_bound(const GLuint& in_vao_id)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        if (vao_iterator->second->status == Status::Created_Not_Bound)
        {
            vao_iterator->second->status = Status::Alive;
        }
        else
        {
            vkgl_assert(vao_iterator->second->status == Status::Alive);
        }
    }

    result = true;
end:
    return result;
}

void OpenGL::GLVAOManager::release_binding(const OpenGL::GLBinding* in_vao_binding_ptr)
{
    const auto binding_vao_id = in_vao_binding_ptr->get_id();

    {
        auto vao_lock     = std::unique_lock<std::mutex>(m_vao_ptrs_lock);
        auto vao_iterator = m_vao_ptrs.find(binding_vao_id);

        /* Release the binding .. */
        vkgl_assert(vao_iterator != m_vao_ptrs.end() );

        auto binding_iterator = std::find(vao_iterator->second->bindings.begin(),
                                          vao_iterator->second->bindings.end(),
                                          in_vao_binding_ptr);

        vkgl_assert(binding_iterator != vao_iterator->second->bindings.end() );

        vao_iterator->second->bindings.erase(binding_iterator);

        /* If the VAO has been destroyed AND there are no more dangling refernces, destroy
         * the container. Otherwise, retain it.
         */
        if ((vao_iterator->second->status          == Status::Created_Not_Bound         ||
             vao_iterator->second->status          == Status::Deleted_Bindings_Pending) &&
            (vao_iterator->second->bindings.size() == 0) )
        {
            m_vao_ptrs.erase(vao_iterator);
        }
    }
}

bool OpenGL::GLVAOManager::set_element_array_buffer_binding(const GLuint& in_vao_id,
                                                            const GLuint& in_new_buffer_binding)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        vkgl_assert(vao_iterator->second->status == Status::Alive);

        vao_iterator->second->vao_ptr->element_array_buffer_binding = in_new_buffer_binding;
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::set_vaa_state(const GLuint&                    in_vao_id,
                                         const uint32_t&                  in_n_vao_vaa,
                                         const VertexAttributeArrayState& in_state)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_vao_ptrs_lock);
        auto                         vao_iterator(m_vao_ptrs.find(in_vao_id) );

        if (vao_iterator == m_vao_ptrs.end() )
        {
            vkgl_assert(vao_iterator != m_vao_ptrs.end() );

            goto end;
        }

        vkgl_assert(vao_iterator->second->status                                  == Status::Alive);
        vkgl_assert(vao_iterator->second->vao_ptr->vertex_attribute_arrays.size() >  in_n_vao_vaa);

        vao_iterator->second->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa) = in_state;
    }

    result = true;
end:
    return result;
}
