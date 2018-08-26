/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_IMAGE_2D_H
#define VKGL_GL_COMPRESSED_TEX_IMAGE_2D_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCompressedTexImage2D(GLenum      target,
                                            GLint       level,
                                            GLenum      internalformat,
                                            GLsizei     width,
                                            GLsizei     height,
                                            GLint       border,
                                            GLsizei     imageSize,
                                            const void* data);

void vkglCompressedTexImage2D_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_target,
                                              const GLint&   in_level,
                                              const GLenum&  in_internalformat,
                                              const GLsizei& in_width,
                                              const GLsizei& in_height,
                                              const GLint&   in_border,
                                              const GLsizei& in_image_size,
                                              const void*    in_data);

#endif /* VKGL_GL_COMPRESSED_TEX_IMAGE_2D_H */