/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameterfv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_pname,
                     GLfloat*       out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY vkglGetTexLevelParameterfv(GLenum   target,
                                                       GLint    level,
                                                       GLenum   pname,
                                                       GLfloat* params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexLevelParameterfv(dispatch_table_ptr->bound_context_ptr,
                                                  target,
                                                  level,
                                                  pname,
                                                  params);
}

void vkglGetTexLevelParameterfv_execute(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLint&   in_level,
                                        const GLenum&  in_pname,
                                        GLfloat*       out_params_ptr)
{
    const auto pname_vkgl  = VKGL::Utils::get_texture_level_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum        (in_target);

    in_context_ptr->get_texture_level_parameter(target_vkgl,
                                                in_level,
                                                pname_vkgl,
                                                VKGL::GetSetArgumentType::Float,
                                                out_params_ptr);
}

void vkglGetTexLevelParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLint&   in_level,
                                                const GLenum&  in_pname,
                                                GLfloat*       out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetTexLevelParameterfv_execute(in_context_ptr,
                                           in_target,
                                           in_level,
                                           in_pname,
                                           out_params_ptr);
    }
}
