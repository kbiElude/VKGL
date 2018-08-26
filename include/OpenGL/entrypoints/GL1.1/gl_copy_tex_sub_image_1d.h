/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCopyTexSubImage1D(GLenum  target,
                                         GLint   level,
                                         GLint   xoffset,
                                         GLint   x,
                                         GLint   y,
                                         GLsizei width);

void vkglCopyTexSubImage1D_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_target,
                                           const GLint&   in_level,
                                           const GLint&   in_xoffset,
                                           const GLint&   in_x,
                                           const GLint&   in_y,
                                           const GLsizei& in_width);

#endif /* VKGL_GL_COPY_TEX_SUB_IMAGE_1D_H */