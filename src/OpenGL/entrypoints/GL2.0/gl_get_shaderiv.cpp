/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)

 */
#include "OpenGL/entrypoints/GL2.0/gl_get_shaderiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_pshader,
                     const GLenum&  in_pname,
                     GLint*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glGetShaderiv(GLuint shader,
                                          GLenum pname,
                                          GLint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetShaderiv(dispatch_table_ptr->bound_context_ptr,
                                       shader,
                                       pname,
                                       params);
}

void vkglGetShaderiv_execute(VKGL::Context* in_context_ptr,
                             const GLuint&  in_shader,
                             const GLenum&  in_pname,
                             GLint*         out_params_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_shader_property_for_gl_enum(in_pname);

    in_context_ptr->get_shader_property(in_shader,
                                        pname_vkgl,
                                        VKGL::GetSetArgumentType::Int,
                                        1,
                                        out_params_ptr);
}

void vkglGetShaderiv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLuint&  in_shader,
                                     const GLenum&  in_pname,
                                     GLint*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_shader,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetShaderiv_execute(in_context_ptr,
                                in_shader,
                                in_pname,
                                out_params_ptr);
    }
}
