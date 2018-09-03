/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_renderbuffer_parameteriv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_pname,
                     GLint*           out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetRenderbufferParameteriv(GLenum target,
                                                          GLenum pname,
                                                          GLint* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetRenderbufferParameteriv(dispatch_table_ptr->bound_context_ptr,
                                                      target,
                                                      pname,
                                                      params);
}

static void vkglGetRenderbufferParameteriv_execute(OpenGL::Context* in_context_ptr,
                                                   const GLenum&    in_target,
                                                   const GLenum&    in_pname,
                                                   GLint*           out_params_ptr)
{
    const auto pname_vkgl  = OpenGL::Utils::get_renderbuffer_property_for_gl_enum(in_pname);
    const auto target_vkgl = OpenGL::Utils::get_renderbuffer_target_for_gl_enum  (in_target);

    in_context_ptr->get_renderbuffer_property(target_vkgl,
                                              pname_vkgl,
                                              OpenGL::GetSetArgumentType::Int,
                                              out_params_ptr);
}

void OpenGL::vkglGetRenderbufferParameteriv_with_validation(OpenGL::Context* in_context_ptr,
                                                            const GLenum&    in_target,
                                                            const GLenum&    in_pname,
                                                            GLint*           out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetRenderbufferParameteriv_execute(in_context_ptr,
                                               in_target,
                                               in_pname,
                                               out_params_ptr);
    }
}
