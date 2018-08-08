/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H
#define VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCompressedTexImage1D(GLenum      target,
                                                   GLint       level,
                                                   GLenum      internalformat,
                                                   GLsizei     width,
                                                   GLint       border,
                                                   GLsizei     imageSize,
                                                   const void* data);

void vkglCompressedTexImage1D_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_target,
                                              const GLint&   in_level,
                                              const GLenum&  in_internalformat,
                                              const GLsizei& in_width,
                                              const GLint&   in_border,
                                              const GLsizei& in_image_size,
                                              const void*    in_data);

#endif /* VKGL_GL_COMPRESSED_TEX_IMAGE_1D_H */