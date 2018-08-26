/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_TEX_IMAGE_H
#define VKGL_GL_GET_TEX_IMAGE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGetTexImage(GLenum target,
                                   GLint  level,
                                   GLenum format,
                                   GLenum type,
                                   void*  pixels);

void vkglGetTexImage_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_target,
                                     const GLint&   in_level,
                                     const GLenum&  in_format,
                                     const GLenum&  in_type,
                                     void*          out_pixels_ptr);

#endif /* VKGL_GL_GET_TEX_IMAGE_H */