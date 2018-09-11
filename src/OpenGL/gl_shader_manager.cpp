/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/gl_reference.h"
#include "OpenGL/gl_shader_manager.h"


OpenGL::GLShaderManager::GLShaderManager()
    :GLObjectManager(1,     /* in_first_valid_nondefault_id */
                     false) /* in_expose_default_object     */
{
    /*  Stub */
}

OpenGL::GLShaderManager::~GLShaderManager()
{
    /* Stub - everything is handled by the base class. */
}

bool OpenGL::GLShaderManager::add_reference(const GLuint&      in_id,
                                            const GLReference* in_reference_ptr)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        shader_ptr->references.push_back(in_reference_ptr);

        result = true;
    }

    return result;
}

OpenGL::GLShaderManagerUniquePtr OpenGL::GLShaderManager::create()
{
    OpenGL::GLShaderManagerUniquePtr result_ptr;

    result_ptr.reset(new GLShaderManager() );

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

bool OpenGL::GLShaderManager::delete_reference(const GLuint&      in_id,
                                               const GLReference* in_reference_ptr)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        auto reference_iterator = std::find(shader_ptr->references.begin(),
                                            shader_ptr->references.end  (),
                                            in_reference_ptr);

        vkgl_assert(reference_iterator != shader_ptr->references.end() );
        if (reference_iterator != shader_ptr->references.end() )
        {
            shader_ptr->references.erase(reference_iterator);

            result = true;
        }
    }

    return result;
}

bool OpenGL::GLShaderManager::delete_object(const GLuint& in_id)
{
    bool       result          = false;
    const auto shader_iterator = m_shader_ptrs.find(in_id);

    vkgl_assert(shader_iterator != m_shader_ptrs.end() );
    if (shader_iterator != m_shader_ptrs.end() )
    {
        vkgl_assert(shader_iterator->second->references.size() == 0);

        m_shader_ptrs.erase(shader_iterator);

        result = true;
    }

    return result;
}

uint32_t OpenGL::GLShaderManager::get_n_references(const GLuint& in_id) const
{
    uint32_t result     = 0;
    auto     shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        result = static_cast<uint32_t>(shader_ptr->references.size() );
    }

    return result;
}

OpenGL::GLObjectManager::Status OpenGL::GLShaderManager::get_object_status(const GLuint& in_id) const
{
    OpenGL::GLObjectManager::Status result     = OpenGL::GLObjectManager::Status::Unknown;
    const auto                      shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        result = shader_ptr->status;
    }

    return result;
}

bool OpenGL::GLShaderManager::get_shader_glsl(const GLuint&  in_id,
                                              const char**   out_result_ptr_ptr) const
{
    static const char* null_string = "";
    bool               result      = false;
    const auto         shader_ptr  = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        *out_result_ptr_ptr = (shader_ptr->glsl.length() > 0) ? &shader_ptr->glsl.at(0)
                                                              : null_string;

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::get_shader_infolog(const GLuint& in_id,
                                                 const char**  out_result_ptr_ptr) const
{
    static const char* null_string = "";
    bool               result      = false;
    const auto         shader_ptr  = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        *out_result_ptr_ptr = (shader_ptr->infolog.length() > 0) ? &shader_ptr->infolog.at(0)
                                                                 : null_string;

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::get_shader_property(const GLuint&                     in_shader,
                                                  const OpenGL::ShaderProperty&     in_pname,
                                                  const OpenGL::GetSetArgumentType& in_params_type,
                                                  const uint32_t&                   in_n_params_components,
                                                  GLint*                            out_params_ptr) const
{
    bool                       result                = false;
    const auto                 shader_ptr            = get_shader_ptr(in_shader);
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
        case OpenGL::ShaderProperty::Compile_Status:       src_data_type = OpenGL::GetSetArgumentType::Boolean;        src_data.boolean      = shader_ptr->successful_last_compile;                        break;
        case OpenGL::ShaderProperty::Delete_Status:        src_data_type = OpenGL::GetSetArgumentType::Boolean;        src_data.boolean      = (shader_ptr->status != Status::Deleted_References_Pending); break;
        case OpenGL::ShaderProperty::Info_Log_Length:      src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int;   src_data.unsigned_int = static_cast<uint32_t>(shader_ptr->infolog.length() + 1);    break;
        case OpenGL::ShaderProperty::Shader_Source_Length: src_data_type = OpenGL::GetSetArgumentType::Unsigned_Int;   src_data.unsigned_int = static_cast<uint32_t>(shader_ptr->glsl.length   () + 1);    break;
        case OpenGL::ShaderProperty::Shader_Type:          src_data_type = OpenGL::GetSetArgumentType::ShaderTypeVKGL; src_data.shader_type  = shader_ptr->type;                                           break;

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

const OpenGL::GLShaderManager::Shader* OpenGL::GLShaderManager::get_shader_ptr(const GLuint& in_id) const
{
    OpenGL::GLShaderManager::Shader* result_ptr      = nullptr;
    const auto                       shader_iterator = m_shader_ptrs.find(in_id);

    vkgl_assert(shader_iterator != m_shader_ptrs.end() );
    if (shader_iterator != m_shader_ptrs.end() )
    {
        result_ptr = shader_iterator->second.get();
    }

    return result_ptr;
}

OpenGL::GLShaderManager::Shader* OpenGL::GLShaderManager::get_shader_ptr(const GLuint& in_id)
{
    OpenGL::GLShaderManager::Shader* result_ptr      = nullptr;
    const auto                       shader_iterator = m_shader_ptrs.find(in_id);

    vkgl_assert(shader_iterator != m_shader_ptrs.end() );
    if (shader_iterator != m_shader_ptrs.end() )
    {
        result_ptr = shader_iterator->second.get();
    }

    return result_ptr;
}

bool OpenGL::GLShaderManager::insert_object(const GLuint& in_id)
{
    bool       result          = false;
    const auto shader_iterator = m_shader_ptrs.find(in_id);

    vkgl_assert(shader_iterator == m_shader_ptrs.end() );
    if (shader_iterator == m_shader_ptrs.end() )
    {
        m_shader_ptrs[in_id].reset(
            new Shader(in_id)
        );

        vkgl_assert(m_shader_ptrs.at(in_id) != nullptr);

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::is_id_valid(const GLuint& in_id) const
{
    const auto shader_iterator = m_shader_ptrs.find(in_id);

    return (shader_iterator != m_shader_ptrs.end() );
}

bool OpenGL::GLShaderManager::set_object_status(const GLuint& in_id,
                                                const Status& in_new_status)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        shader_ptr->status = in_new_status;

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::set_shader_glsl(const GLuint&      in_id,
                                              const std::string& in_glsl)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        shader_ptr->glsl = in_glsl;

        result = true;
    }

    return result;
}

bool OpenGL::GLShaderManager::set_shader_type(const GLuint&             in_id,
                                              const OpenGL::ShaderType& in_type)
{
    bool result     = false;
    auto shader_ptr = get_shader_ptr(in_id);

    if (shader_ptr != nullptr)
    {
        vkgl_assert(shader_ptr->type == OpenGL::ShaderType::Unknown);

        shader_ptr->type = in_type;
        result           = true;
    }

    return result;
}