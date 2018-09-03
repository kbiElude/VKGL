/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_parameterfv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_pname,
                     GLfloat*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglGetTexParameterfv(GLenum   target,
                                                 GLenum   pname,
                                                 GLfloat* params)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexParameterfv(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             pname,
                                             params);
}

static void vkglGetTexParameterfv_execute(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_target,
                                          const GLenum&    in_pname,
                                          GLfloat*         out_params_ptr)
{
    const auto pname_vkgl  = OpenGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->get_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          OpenGL::GetSetArgumentType::Float,
                                          out_params_ptr);
}

void OpenGL::vkglGetTexParameterfv_with_validation(OpenGL::Context* in_context_ptr,
                                                   const GLenum&    in_target,
                                                   const GLenum&    in_pname,
                                                   GLfloat*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetTexParameterfv_execute(in_context_ptr,
                                      in_target,
                                      in_pname,
                                      out_params_ptr);
    }
}
