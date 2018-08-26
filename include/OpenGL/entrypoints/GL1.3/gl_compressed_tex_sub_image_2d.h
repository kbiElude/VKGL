/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_2D_H
#define VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_2D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCompressedTexSubImage2D(GLenum      target,
                                               GLint       level,
                                               GLint       xoffset,
                                               GLint       yoffset,
                                               GLsizei     width,
                                               GLsizei     height,
                                               GLenum      format,
                                               GLsizei     imageSize,
                                               const void* data);

void vkglCompressedTexSubImage2D_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLenum&  in_target,
                                                 const GLint&   in_level,
                                                 const GLint&   in_xoffset,
                                                 const GLint&   in_yoffset,
                                                 const GLsizei& in_width,
                                                 const GLsizei& in_height,
                                                 const GLenum&  in_format,
                                                 const GLsizei& in_image_size,
                                                 const void*    in_data);

#endif /* VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_2D_H */