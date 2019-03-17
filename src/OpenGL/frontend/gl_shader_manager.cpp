/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/gl_shader_manager.h"


OpenGL::GLShaderManager::GLShaderManager(IBackendGLCallbacks* in_backend_ptr)
    :GLObjectManager(1,              /* in_first_valid_nondefault_id */
                     true),          /* in_expose_default_object     */
     m_backend_ptr  (in_backend_ptr)
{
    vkgl_assert(in_backend_ptr != nullptr);
}

OpenGL::GLShaderManager::~GLShaderManager()
{
    /* Stub - everything is handled by the base class. */
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLShaderManager::clone_internal_data_object(const void* in_ptr,
                                                                                                       const bool& in_convert_from_proxy_to_nonproxy)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Shader*>(in_ptr); });

    /* NOTE: Proxy->non-proxy conversion has no meaning for GL shaders, as we only cache shader state properties,
     *       not actual object references */
    ANVIL_REDUNDANT_ARGUMENT_CONST(in_convert_from_proxy_to_nonproxy);

    result_ptr.reset(
        new Shader(*reinterpret_cast<const Shader*>(in_ptr) )
    );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

void OpenGL::GLShaderManager::copy_internal_data_object(const void* in_src_ptr,
                                                         void*       in_dst_ptr)
{
    *reinterpret_cast<Shader*>(in_dst_ptr) = *reinterpret_cast<const Shader*>(in_src_ptr);
}

OpenGL::GLShaderManagerUniquePtr OpenGL::GLShaderManager::create(IBackendGLCallbacks* in_backend_ptr)
{
    OpenGL::GLShaderManagerUniquePtr result_ptr;

    result_ptr.reset(new GLShaderManager(in_backend_ptr) );

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

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLShaderManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Shader*>(in_ptr); });

    result_ptr.reset(
        new Shader()
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

bool OpenGL::GLShaderManager::get_shader_glsl(const GLuint&             in_id,
                                              const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                              const char**              out_result_ptr_ptr) const
{
    static const char* null_string = "";
    bool               result      = false;
    const auto         shader_ptr  = get_shader_ptr(in_id,
                                                    in_opt_time_marker_ptr);

    if (shader_ptr != nullptr)
    {
        *out_result_ptr_ptr = (shader_ptr->glsl.length() > 0) ? &shader_ptr->glsl.at(0)
                                                              : null_string;

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::get_shader_infolog(const GLuint&             in_id,
                                                 const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                                 const char**              out_result_ptr_ptr) const
{
    static const char* null_string = "";
    bool               result      = false;
    const auto         shader_ptr  = get_shader_ptr(in_id,
                                                    in_opt_time_marker_ptr);

    if (shader_ptr != nullptr)
    {
        if (shader_ptr->spirv_blob_id == UINT32_MAX)
        {
            /* glCompileShader() has not been called for this shader object. */
            *out_result_ptr_ptr = null_string;
        }
        else
        {
            m_backend_ptr->get_spirv_manager_ptr()->get_shader_compilation_status(shader_ptr->spirv_blob_id,
                                                                                  nullptr, /* out_status_ptr */
                                                                                  out_result_ptr_ptr);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::get_shader_type(const GLuint&             in_id,
                                              const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                              OpenGL::ShaderType*       out_result_ptr) const
{
    bool       result     = false;
    const auto shader_ptr = get_shader_ptr(in_id,
                                           in_opt_time_marker_ptr);

    if (shader_ptr != nullptr)
    {
        *out_result_ptr = shader_ptr->type;
        result          = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::get_shader_property(const GLuint&                     in_shader,
                                                  const OpenGL::TimeMarker*         in_opt_time_marker_ptr,
                                                  const OpenGL::ShaderProperty&     in_pname,
                                                  const OpenGL::GetSetArgumentType& in_params_type,
                                                  const uint32_t&                   in_n_params_components,
                                                  GLint*                            out_params_ptr) const
{
    bool                       result                = false;
    volatile const auto        shader_ptr            = const_cast<OpenGL::GLShaderManager*>(this)->get_shader_ptr(in_shader,
                                                                                                                  in_opt_time_marker_ptr);
    const void*                src_data_ptr          = nullptr;
    OpenGL::GetSetArgumentType src_data_type         = OpenGL::GetSetArgumentType::Unknown;

    union
    {
        uint32_t   boolean;
        ShaderType shader_type;
        uint32_t   unsigned_int;
    } src_data;

    if (shader_ptr == nullptr)
    {
        vkgl_assert(shader_ptr != nullptr);

        goto end;
    }

    static_assert(GL_TRUE                == true, "");
    vkgl_assert  (in_n_params_components == 1);

    switch (in_pname)
    {
        case OpenGL::ShaderProperty::Compile_Status:
        case OpenGL::ShaderProperty::Info_Log_Length:
        {
            src_data_type = (in_pname == OpenGL::ShaderProperty::Compile_Status) ? OpenGL::GetSetArgumentType::Boolean
                                                                                 : OpenGL::GetSetArgumentType::Unsigned_Int;

            if (shader_ptr->spirv_blob_id == UINT32_MAX)
            {
                /* glCompileShader() has not been invoked for this shader object */
                if (in_pname == OpenGL::ShaderProperty::Compile_Status)
                {
                    src_data.boolean = false;
                }
                else
                {
                    src_data.unsigned_int = 1; /* terminator */
                }
            }
            else
            {
                bool        compilation_status  = false;
                const char* compilation_log_ptr = nullptr;

                m_backend_ptr->get_spirv_manager_ptr()->get_shader_compilation_status(shader_ptr->spirv_blob_id,
                                                                                     &compilation_status,
                                                                                     &compilation_log_ptr);

                if (in_pname == OpenGL::ShaderProperty::Compile_Status)
                {
                    src_data.boolean = compilation_status;
                }
                else
                {
                    src_data.unsigned_int = strlen(compilation_log_ptr) + 1; /* terminator */
                }
            }

            break;
        }

        case OpenGL::ShaderProperty::Shader_Source_Length: src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int;   src_data.unsigned_int = static_cast<uint32_t>(shader_ptr->glsl.length() + 1);  break;
        case OpenGL::ShaderProperty::Shader_Type:          src_data_type = OpenGL::GetSetArgumentType::ShaderTypeVKGL; src_data.shader_type  = shader_ptr->type;                                      break;

        case OpenGL::ShaderProperty::Delete_Status:
        {
            src_data_type    = OpenGL::GetSetArgumentType::Boolean;
            src_data.boolean = (get_general_object_props_ptr(in_shader)->status != Status::Deleted_References_Pending);

            break;
        }

        default:
        {
            vkgl_assert_fail();

            goto end;
        }
    }

    OpenGL::Converters::convert(src_data_type,
                               &src_data,
                                1, /* in_n_vals */
                                in_params_type,
                                out_params_ptr);

    result = true;
end:
    return result;
}

const OpenGL::GLShaderManager::Shader* OpenGL::GLShaderManager::get_shader_ptr(const GLuint&             in_id,
                                                                               const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    return reinterpret_cast<const OpenGL::GLShaderManager::Shader*>(get_internal_object_props_ptr(in_id,
                                                                                                  in_opt_time_marker_ptr) );
}

OpenGL::GLShaderManager::Shader* OpenGL::GLShaderManager::get_shader_ptr(const GLuint&             in_id,
                                                                         const OpenGL::TimeMarker* in_opt_time_marker_ptr)
{
    return reinterpret_cast<OpenGL::GLShaderManager::Shader*>(get_internal_object_props_ptr(in_id,
                                                                                            in_opt_time_marker_ptr) );
}

void OpenGL::GLShaderManager::set_shader_backend_spirv_blob_id(const GLuint&             in_id,
                                                               const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                                               OpenGL::SPIRVBlobID       in_spirv_blob_id)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id,
                                     nullptr /* in_opt_time_marker_ptr */);

    if (shader_ptr != nullptr)
    {
        vkgl_assert(shader_ptr->spirv_blob_id == UINT32_MAX);

        /* NOTE: This aciton is an update of INTERNAL state, hence no update notification propagation */
        shader_ptr->spirv_blob_id = in_spirv_blob_id;
        result                    = true;
    }
}

bool OpenGL::GLShaderManager::set_shader_glsl(const GLuint&      in_id,
                                              const std::string& in_glsl)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id,
                                     nullptr /* in_opt_time_marker_ptr */);

    if (shader_ptr != nullptr)
    {
        if (shader_ptr->glsl != in_glsl)
        {
            shader_ptr->glsl = in_glsl;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::set_shader_type(const GLuint&             in_id,
                                              const OpenGL::ShaderType& in_type)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id,
                                     nullptr /* in_opt_time_marker_ptr */);

    if (shader_ptr != nullptr)
    {
        vkgl_assert(shader_ptr->type == OpenGL::ShaderType::Unknown);

        if (shader_ptr->type != in_type)
        {
            shader_ptr->type = in_type;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}