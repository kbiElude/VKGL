/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_3D_H
#define VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_3D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glCompressedTexSubImage3D(GLenum      target,
                                                      GLint       level,
                                                      GLint       xoffset,
                                                      GLint       yoffset,
                                                      GLint       zoffset,
                                                      GLsizei     width,
                                                      GLsizei     height,
                                                      GLsizei     depth,
                                                      GLenum      format,
                                                      GLsizei     imageSize,
                                                      const void* data);

void vkglCompressedTexSubImage3D_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLenum&  in_target,
                                                 const GLint&   in_level,
                                                 const GLint&   in_xoffset,
                                                 const GLint&   in_yoffset,
                                                 const GLint&   in_zoffset,
                                                 const GLsizei& in_width,
                                                 const GLsizei& in_height,
                                                 const GLsizei& in_depth,
                                                 const GLenum&  in_format,
                                                 const GLsizei& in_image_size,
                                                 const void*    in_data);

#endif /* VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_3D_H */