/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BLIT_FRAMEBUFFER_H
#define VKGL_GL_BLIT_FRAMEBUFFER_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBlitFramebuffer(GLint      srcX0,
                                              GLint      srcY0,
                                              GLint      srcX1,
                                              GLint      srcY1,
                                              GLint      dstX0,
                                              GLint      dstY0,
                                              GLint      dstX1,
                                              GLint      dstY1,
                                              GLbitfield mask,
                                              GLenum     filter);

void vkglBlitFramebuffer_with_validation(VKGL::Context*    in_context_ptr,
                                         const GLint&      in_src_x0,
                                         const GLint&      in_src_y0,
                                         const GLint&      in_src_x1,
                                         const GLint&      in_src_y1,
                                         const GLint&      in_dst_x0,
                                         const GLint&      in_dst_y0,
                                         const GLint&      in_dst_x1,
                                         const GLint&      in_dst_y1,
                                         const GLbitfield& in_mask,
                                         const GLenum&     in_filter);

#endif /* VKGL_GL_BLIT_FRAMEBUFFER_H */