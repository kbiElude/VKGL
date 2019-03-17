/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/gl_vao_manager.h"

OpenGL::GLVAOManager::VAO::VAO(const VAO&                    in_vao,
                               const bool&                   in_convert_from_proxy_to_nonproxy,
                               const IContextObjectManagers* in_frontend_object_managers_ptr)
{
    vao_ptr.reset(
        new OpenGL::VertexArrayObjectState(*in_vao.vao_ptr)
    );
    vkgl_assert(vao_ptr != nullptr);

    if (in_convert_from_proxy_to_nonproxy)
    {
        auto frontend_buffer_manager_ptr = in_frontend_object_managers_ptr->get_buffer_manager_ptr();

        /* TODO: Element array buffer binding proxy->nonproxy conversion */

        for (auto& current_vaa : vao_ptr->vertex_attribute_arrays)
        {
            if (current_vaa.buffer_binding_ptr != nullptr)
            {
                current_vaa.buffer_binding_ptr = frontend_buffer_manager_ptr->acquire_current_latest_snapshot_reference(current_vaa.buffer_binding_ptr->get_payload().id);
            }
        }
    }
}

OpenGL::GLVAOManager::VAO::VAO(const OpenGL::IGLLimits* in_limits_ptr)
{
    vkgl_assert(in_limits_ptr != nullptr);

    vao_ptr.reset(
        new OpenGL::VertexArrayObjectState(in_limits_ptr->get_max_vertex_attribs())
    );

    vkgl_assert(vao_ptr != nullptr);
}

OpenGL::GLVAOManager::VAO& OpenGL::GLVAOManager::VAO::operator=(const OpenGL::GLVAOManager::VAO& in_vao)
{
    vkgl_assert(vao_ptr != nullptr);

    *vao_ptr = *in_vao.vao_ptr;

    return *this;
}

OpenGL::GLVAOManager::GLVAOManager(const IGLLimits*              in_limits_ptr,
                                   const IContextObjectManagers* in_frontend_object_managers_ptr)
    :GLObjectManager               (1,   /* in_first_valid_nondefault_id */
                                    true /* in_expose_default_object     */),
     m_frontend_object_managers_ptr(in_frontend_object_managers_ptr),
     m_limits_ptr                  (in_limits_ptr)
{
    /*  Stub */
}

OpenGL::GLVAOManager::~GLVAOManager()
{
    /* Stub - everything is handled by the base class. */
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLVAOManager::clone_internal_data_object(const void* in_ptr,
                                                                                                    const bool& in_convert_from_proxy_to_nonproxy)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<VAO*>(in_ptr); });

    result_ptr.reset(
        new VAO(*reinterpret_cast<const VAO*>(in_ptr),
                in_convert_from_proxy_to_nonproxy,
                m_frontend_object_managers_ptr)
    );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

void OpenGL::GLVAOManager::copy_internal_data_object(const void* in_src_ptr,
                                                     void*       in_dst_ptr)
{
    *reinterpret_cast<VAO*>(in_dst_ptr) = *reinterpret_cast<const VAO*>(in_src_ptr);
}

OpenGL::GLVAOManagerUniquePtr OpenGL::GLVAOManager::create(const IGLLimits*              in_limits_ptr,
                                                           const IContextObjectManagers* in_frontend_object_managers_ptr)
{
    OpenGL::GLVAOManagerUniquePtr result_ptr;

    result_ptr.reset(new GLVAOManager(in_limits_ptr,
                                      in_frontend_object_managers_ptr) );

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

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLVAOManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<VAO*>(in_ptr); });

    result_ptr.reset(
        new VAO(m_limits_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

bool OpenGL::GLVAOManager::get_element_array_buffer_binding(const uint32_t&           in_vao_id,
                                                            const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                                            GLuint*                   out_result_ptr) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock         (m_mutex);
        auto                         vao_props_ptr(get_vao_ptr(in_vao_id,
                                                               in_opt_time_marker_ptr) );

        if (vao_props_ptr == nullptr)
        {
            vkgl_assert(vao_props_ptr != nullptr);

            goto end;
        }

        vkgl_assert(get_general_object_props_ptr(in_vao_id)->status == Status::Alive);

        *out_result_ptr = vao_props_ptr->vao_ptr->element_array_buffer_binding;
    }

    result = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::get_vaa_property(const GLuint&                         in_vao_id,
                                            const OpenGL::TimeMarker*             in_opt_time_marker_ptr,
                                            const uint32_t&                       in_n_vao_vaa,
                                            const OpenGL::VertexAttributeProperty in_pname,
                                            const OpenGL::GetSetArgumentType&     in_dst_type,
                                            void*                                 out_result_ptr) const
{
    bool                       result        = false;
    const void*                src_data_ptr  = nullptr;
    OpenGL::GetSetArgumentType src_data_type = OpenGL::GetSetArgumentType::Unknown;

    {
        std::unique_lock<std::mutex>             lock         (m_mutex);
        const OpenGL::VertexAttributeArrayState* vaa_ptr      (nullptr);
        auto                                     vao_props_ptr(get_vao_ptr(in_vao_id,
                                                                           in_opt_time_marker_ptr) );

        if (vao_props_ptr == nullptr)
        {
            vkgl_assert(vao_props_ptr != nullptr);

            goto end;
        }

        vkgl_assert(get_general_object_props_ptr(in_vao_id)->status        == Status::Alive);
        vkgl_assert(vao_props_ptr->vao_ptr->vertex_attribute_arrays.size() >  in_n_vao_vaa);

        vaa_ptr = &vao_props_ptr->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa);

        switch (in_pname)
        {
            case OpenGL::VertexAttributeProperty::Array_Size: src_data_ptr = &vaa_ptr->size;       src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int64;           break;
            case OpenGL::VertexAttributeProperty::Array_Type: src_data_ptr = &vaa_ptr->type;       src_data_type = OpenGL::GetSetArgumentType::VertexAttributeArrayType; break;
            case OpenGL::VertexAttributeProperty::Enabled:    src_data_ptr = &vaa_ptr->enabled;    src_data_type = OpenGL::GetSetArgumentType::Boolean;                  break;
            case OpenGL::VertexAttributeProperty::Integer:    src_data_ptr = &vaa_ptr->integer;    src_data_type = OpenGL::GetSetArgumentType::Boolean;                  break;
            case OpenGL::VertexAttributeProperty::Normalized: src_data_ptr = &vaa_ptr->normalized; src_data_type = OpenGL::GetSetArgumentType::Boolean;                  break;
            case OpenGL::VertexAttributeProperty::Pointer:    src_data_ptr = &vaa_ptr->pointer;    src_data_type = OpenGL::GetSetArgumentType::Pointer;                  break;
            case OpenGL::VertexAttributeProperty::Stride:     src_data_ptr = &vaa_ptr->stride;     src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int64;           break;

            case OpenGL::VertexAttributeProperty::Buffer_Binding:
            {
                src_data_ptr  = &vaa_ptr->buffer_binding_ptr->get_payload().id;
                src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int;

                break;
            }

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
                                              const OpenGL::TimeMarker*  in_opt_time_marker_ptr,
                                              const uint32_t&            in_n_vao_vaa,
                                              VertexAttributeArrayState* out_result_ptr) const
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock         (m_mutex);
        auto                         vao_props_ptr(get_vao_ptr(in_vao_id,
                                                               in_opt_time_marker_ptr) );

        if (vao_props_ptr == nullptr)
        {
            vkgl_assert(vao_props_ptr != nullptr);

            goto end;
        }

        vkgl_assert(get_general_object_props_ptr(in_vao_id)->status        == Status::Alive);
        vkgl_assert(vao_props_ptr->vao_ptr->vertex_attribute_arrays.size() >  in_n_vao_vaa);

        *out_result_ptr = vao_props_ptr->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa);
    }

    result = true;
end:
    return result;
}

const OpenGL::GLVAOManager::VAO* OpenGL::GLVAOManager::get_vao_ptr(const GLuint&             in_id,
                                                                   const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    return reinterpret_cast<const OpenGL::GLVAOManager::VAO*>(get_internal_object_props_ptr(in_id,
                                                                                            in_opt_time_marker_ptr) );
}

OpenGL::GLVAOManager::VAO* OpenGL::GLVAOManager::get_vao_ptr(const GLuint&             in_id,
                                                             const OpenGL::TimeMarker* in_opt_time_marker_ptr)
{
    return reinterpret_cast<OpenGL::GLVAOManager::VAO*>(get_internal_object_props_ptr(in_id,
                                                                                      in_opt_time_marker_ptr) );
}

bool OpenGL::GLVAOManager::get_vao_state_ptr(const GLuint&                          in_vao_id,
                                             const OpenGL::TimeMarker*              in_opt_time_marker_ptr,
                                             const OpenGL::VertexArrayObjectState** out_vao_state_ptr_ptr) const
{
    std::unique_lock<std::mutex> lock         (m_mutex);
    bool                         result       (false);
    auto                         vao_props_ptr(get_vao_ptr(in_vao_id,
                                                           in_opt_time_marker_ptr) );

    if (vao_props_ptr == nullptr)
    {
        vkgl_assert(vao_props_ptr != nullptr);

        goto end;
    }

    *out_vao_state_ptr_ptr = vao_props_ptr->vao_ptr.get();
    result                 = true;
end:
    return result;
}

bool OpenGL::GLVAOManager::set_element_array_buffer_binding(const GLuint& in_vao_id,
                                                            const GLuint& in_new_buffer_binding)
{
    bool result = false;

    {
        std::unique_lock<std::mutex> lock         (m_mutex);
        auto                         vao_props_ptr(get_vao_ptr(in_vao_id,
                                                               nullptr /* in_opt_time_marker_ptr */) );

        if (vao_props_ptr == nullptr)
        {
            vkgl_assert(vao_props_ptr != nullptr);

            goto end;
        }

        vkgl_assert(reinterpret_cast<const GLVAOManager*>(this)->get_general_object_props_ptr(in_vao_id)->status == Status::Alive);

        if (vao_props_ptr->vao_ptr->element_array_buffer_binding != in_new_buffer_binding)
        {
            vao_props_ptr->vao_ptr->element_array_buffer_binding = in_new_buffer_binding;

            update_last_modified_time(in_vao_id);
        }
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
        std::unique_lock<std::mutex> lock         (m_mutex);
        auto                         vao_props_ptr(get_vao_ptr(in_vao_id,
                                                               nullptr /* in_opt_time_marker_ptr */) );

        if (vao_props_ptr == nullptr)
        {
            vkgl_assert(vao_props_ptr != nullptr);

            goto end;
        }

        vkgl_assert(reinterpret_cast<const GLVAOManager*>(this)->get_general_object_props_ptr(in_vao_id)->status == Status::Alive);
        vkgl_assert(vao_props_ptr->vao_ptr->vertex_attribute_arrays.size()                                       >  in_n_vao_vaa);

        if (!(vao_props_ptr->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa) == in_state))
        {
            vao_props_ptr->vao_ptr->vertex_attribute_arrays.at(in_n_vao_vaa) = in_state;

            update_last_modified_time(in_vao_id);
        }
    }

    result = true;
end:
    return result;
}
