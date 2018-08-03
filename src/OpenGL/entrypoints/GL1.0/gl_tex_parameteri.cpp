/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteri.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     const GLint&   in_param)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glTexParameteri(GLenum target,
                                            GLenum pname,
                                            GLint  param)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexParameteri(dispatch_table_ptr->bound_context_ptr,
                                         target,
                                         pname,
                                         param);
}

void vkglTexParameteri_execute(VKGL::Context* in_context_ptr,
                               const GLenum&  in_target,
                               const GLenum&  in_pname,
                               const GLint&   in_param)
{
    const auto pname_vkgl  = VKGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->set_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          VKGL::GetSetArgumentType::Int,
                                         &in_param);
}

void vkglTexParameteri_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_target,
                                       const GLenum&  in_pname,
                                       const GLint&   in_param)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 in_param) )
    {
        vkglTexParameteri_execute(in_context_ptr,
                                  in_target,
                                  in_pname,
                                  in_param);
    }
}