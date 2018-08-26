/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteriv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     const GLint*   in_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglTexParameteriv(GLenum       target,
                                      GLenum       pname,
                                      const GLint* params)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexParameteriv(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          pname,
                                          params);
}

void vkglTexParameteriv_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_target,
                                const GLenum&  in_pname,
                                const GLint*   in_params_ptr)
{
    const auto pname_vkgl  = VKGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->set_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          VKGL::GetSetArgumentType::Int,
                                          in_params_ptr);
}

void vkglTexParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLenum&  in_pname,
                                        const GLint*   in_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 in_params_ptr) )
    {
        vkglTexParameteriv_execute(in_context_ptr,
                                   in_target,
                                   in_pname,
                                   in_params_ptr);
    }
}