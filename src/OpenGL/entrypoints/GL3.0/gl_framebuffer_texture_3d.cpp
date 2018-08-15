/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_3d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_attachment,
                     const GLenum&  in_textarget,
                     const GLuint&  in_texture,
                     const GLint&   in_level,
                     const GLint&   in_zoffset)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glFramebufferTexture3D(GLenum target,
                                                   GLenum attachment,
                                                   GLenum textarget,
                                                   GLuint texture,
                                                   GLint  level,
                                                   GLint  zoffset)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFramebufferTexture3D(dispatch_table_ptr->bound_context_ptr,
                                                target,
                                                attachment,
                                                textarget,
                                                texture,
                                                level,
                                                zoffset);
}

void vkglFramebufferTexture3D_execute(VKGL::Context* in_context_ptr,
                                      const GLenum&  in_target,
                                      const GLenum&  in_attachment,
                                      const GLenum&  in_textarget,
                                      const GLuint&  in_texture,
                                      const GLint&   in_level,
                                      const GLint&   in_zoffset)
{
    const auto attachment_vkgl = VKGL::Utils::get_framebuffer_attachment_point_for_gl_enum(in_attachment);
    const auto target_vkgl     = VKGL::Utils::get_framebuffer_target_for_gl_enum          (in_target);
    const auto textarget_vkgl  = VKGL::Utils::get_texture_target_for_gl_enum              (in_textarget);

    in_context_ptr->framebuffer_texture_3D(target_vkgl,
                                           attachment_vkgl,
                                           textarget_vkgl,
                                           in_texture,
                                           in_level,
                                           in_zoffset);
}

void vkglFramebufferTexture3D_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_target,
                                              const GLenum&  in_attachment,
                                              const GLenum&  in_textarget,
                                              const GLuint&  in_texture,
                                              const GLint&   in_level,
                                              const GLint&   in_zoffset)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_attachment,
                 in_textarget,
                 in_texture,
                 in_level,
                 in_zoffset) )
    {
        vkglFramebufferTexture3D_execute(in_context_ptr,
                                         in_target,
                                         in_attachment,
                                         in_textarget,
                                         in_texture,
                                         in_level,
                                         in_zoffset);
    }
}
