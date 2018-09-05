/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_renderbuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_attachment,
                     const GLenum&    in_renderbuffertarget,
                     const GLuint&    in_renderbuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglFramebufferRenderbuffer(GLenum target,
                                                       GLenum attachment,
                                                       GLenum renderbuffertarget,
                                                       GLuint renderbuffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glFramebufferRenderbuffer(target=[%s] attachment=[%s] renderbuffertarget=[%s] renderbuffer=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(attachment),
               OpenGL::Utils::get_raw_string_for_gl_enum(renderbuffertarget),
               renderbuffer);

    dispatch_table_ptr->pGLFramebufferRenderbuffer(dispatch_table_ptr->bound_context_ptr,
                                                   target,
                                                   attachment,
                                                   renderbuffertarget,
                                                   renderbuffer);
}

static void vkglFramebufferRenderbuffer_execute(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLenum&    in_attachment,
                                                const GLenum&    in_renderbuffertarget,
                                                const GLuint&    in_renderbuffer)
{
    const auto attachment_vkgl         = OpenGL::Utils::get_framebuffer_attachment_point_for_gl_enum(in_attachment);
    const auto renderbuffertarget_vkgl = OpenGL::Utils::get_renderbuffer_target_for_gl_enum         (in_renderbuffertarget);
    const auto target_vkgl             = OpenGL::Utils::get_framebuffer_target_for_gl_enum          (in_target);

    in_context_ptr->framebuffer_renderbuffer(target_vkgl,
                                             attachment_vkgl,
                                             renderbuffertarget_vkgl,
                                             in_renderbuffer);
}

void OpenGL::vkglFramebufferRenderbuffer_with_validation(OpenGL::Context* in_context_ptr,
                                                         const GLenum&    in_target,
                                                         const GLenum&    in_attachment,
                                                         const GLenum&    in_renderbuffertarget,
                                                         const GLuint&    in_renderbuffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_attachment,
                 in_renderbuffertarget,
                 in_renderbuffer) )
    {
        vkglFramebufferRenderbuffer_execute(in_context_ptr,
                                            in_target,
                                            in_attachment,
                                            in_renderbuffertarget,
                                            in_renderbuffer);
    }
}
