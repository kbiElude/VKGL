/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H
#define VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglCompressedTexSubImage1D(GLenum      target,
                                                   GLint       level,
                                                   GLint       xoffset,
                                                   GLsizei     width,
                                                   GLenum      format,
                                                   GLsizei     imageSize,
                                                   const void* data);

    void vkglCompressedTexSubImage1D_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_target,
                                                     const GLint&     in_level,
                                                     const GLint&     in_xoffset,
                                                     const GLsizei&   in_width,
                                                     const GLenum&    in_format,
                                                     const GLsizei&   in_image_size,
                                                     const void*      in_data);
}

#endif /* VKGL_GL_COMPRESSED_TEX_SUB_IMAGE_1D_H */