/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/gl_binding.h"
#include "OpenGL/gl_vao_manager.h"

OpenGL::GLVAOManager::VAO::VAO(const GLuint&            in_id,
                               const OpenGL::IGLLimits* in_limits_ptr)
{
    vkgl_assert(in_limits_ptr != nullptr);

    id      = in_id;
    status  = Status::Created_Not_Bound;

    vao_ptr.reset(
        new OpenGL::VertexArrayObjectState(in_limits_ptr->get_max_vertex_attribs())
    );
     
    vkgl_assert(vao_ptr != nullptr);
}

OpenGL::GLVAOManager::GLVAOManager(const IGLLimits* in_limits_ptr)
    :GLObjectManager(true, /* in_expose_default_object */
                     in_limits_ptr)
{
    /*  Stub */
}

OpenGL::GLVAOManager::~GLVAOManager()
{
    /* Stub - everything is handled by the base class. */
}

bool OpenGL::GLVAOManager::add_binding(const GLuint&    in_id,
                                       const GLBinding* in_binding_ptr)
{
    bool       result       = false;
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator != m_vao_ptrs.end() );
    if (vao_iterator != m_vao_ptrs.end() )
    {
        vao_iterator->second->bindings.push_back(in_binding_ptr);

        result = true;
    }

    return result;
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

bool OpenGL::GLVAOManager::delete_binding(const GLuint&    in_id,
                                          const GLBinding* in_binding_ptr)
{
    bool       result       = false;
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator != m_vao_ptrs.end() );
    if (vao_iterator != m_vao_ptrs.end() )
    {
        auto binding_iterator = std::find(vao_iterator->second->bindings.begin(),
                                          vao_iterator->second->bindings.end  (),
                                          in_binding_ptr);

        vkgl_assert(binding_iterator != vao_iterator->second->bindings.end() );
        if (binding_iterator != vao_iterator->second->bindings.end() )
        {
            vao_iterator->second->bindings.erase(binding_iterator);

            result = true;
        }
    }

    return result;
}

bool OpenGL::GLVAOManager::delete_object(const GLuint& in_id)
{
    bool       result       = false;
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator != m_vao_ptrs.end() );
    if (vao_iterator != m_vao_ptrs.end() )
    {
        vkgl_assert(vao_iterator->second->bindings.size() == 0);

        m_vao_ptrs.erase(vao_iterator);

        result = true;
    }

    return result;
}

uint32_t OpenGL::GLVAOManager::get_n_bindings(const GLuint& in_id) const
{
    uint32_t   result       = 0;
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator != m_vao_ptrs.end() );
    if (vao_iterator != m_vao_ptrs.end() )
    {
        result = static_cast<uint32_t>(vao_iterator->second->bindings.size() );
    }

    return result;
}

bool OpenGL::GLVAOManager::get_element_array_buffer_binding(const uint32_t& in_vao_id,
                                                            GLuint*         out_result_ptr) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_lock);
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

OpenGL::GLObjectManager::Status OpenGL::GLVAOManager::get_object_status(const GLuint& in_id) const
{
    OpenGL::GLObjectManager::Status result       = OpenGL::GLObjectManager::Status::Unknown;
    const auto                      vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator != m_vao_ptrs.end() );
    if (vao_iterator != m_vao_ptrs.end() )
    {
        result = vao_iterator->second->status;
    }

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
        std::unique_lock<std::mutex>             lock        (m_lock);
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
        std::unique_lock<std::mutex> lock        (m_lock);
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
        std::unique_lock<std::mutex> lock(m_lock);

        vkgl_assert(m_vao_ptrs.find(in_id) == m_vao_ptrs.end() );

        m_vao_ptrs[in_id] = std::move(new_vao_ptr);
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::insert_object(const GLuint& in_id)
{
    bool       result       = false;
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator == m_vao_ptrs.end() );
    if (vao_iterator == m_vao_ptrs.end() )
    {
        m_vao_ptrs[in_id].reset(
            new VAO(in_id,
                    m_limits_ptr)
        );

        vkgl_assert(m_vao_ptrs.at(in_id) != nullptr);

        result = true;
    }

    return result;
}

bool OpenGL::GLVAOManager::is_id_valid(const GLuint& in_id) const
{
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    return (vao_iterator != m_vao_ptrs.end() );
}

bool OpenGL::GLVAOManager::set_element_array_buffer_binding(const GLuint& in_vao_id,
                                                            const GLuint& in_new_buffer_binding)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_lock);
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

bool OpenGL::GLVAOManager::set_object_status(const GLuint& in_id,
                                             const Status& in_new_status)
{
    bool       result       = false;
    const auto vao_iterator = m_vao_ptrs.find(in_id);

    vkgl_assert(vao_iterator != m_vao_ptrs.end() );
    if (vao_iterator != m_vao_ptrs.end() )
    {
        vao_iterator->second->status = in_new_status;

        result = true;
    }

    return result;
}

bool OpenGL::GLVAOManager::set_vaa_state(const GLuint&                    in_vao_id,
                                         const uint32_t&                  in_n_vao_vaa,
                                         const VertexAttributeArrayState& in_state)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock        (m_lock);
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
