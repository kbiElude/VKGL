/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_renderbuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_attachment,
                     const GLenum&  in_renderbuffertarget,
                     const GLuint&  in_renderbuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglFramebufferRenderbuffer(GLenum target,
                                                        GLenum attachment,
                                                        GLenum renderbuffertarget,
                                                        GLuint renderbuffer)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFramebufferRenderbuffer(dispatch_table_ptr->bound_context_ptr,
                                                   target,
                                                   attachment,
                                                   renderbuffertarget,
                                                   renderbuffer);
}

void vkglFramebufferRenderbuffer_execute(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_target,
                                         const GLenum&  in_attachment,
                                         const GLenum&  in_renderbuffertarget,
                                         const GLuint&  in_renderbuffer)
{
    const auto attachment_vkgl         = VKGL::Utils::get_framebuffer_attachment_point_for_gl_enum(in_attachment);
    const auto renderbuffertarget_vkgl = VKGL::Utils::get_renderbuffer_target_for_gl_enum         (in_renderbuffertarget);
    const auto target_vkgl             = VKGL::Utils::get_framebuffer_target_for_gl_enum          (in_target);

    in_context_ptr->framebuffer_renderbuffer(target_vkgl,
                                             attachment_vkgl,
                                             renderbuffertarget_vkgl,
                                             in_renderbuffer);
}

void vkglFramebufferRenderbuffer_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLenum&  in_target,
                                                 const GLenum&  in_attachment,
                                                 const GLenum&  in_renderbuffertarget,
                                                 const GLuint&  in_renderbuffer)
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
