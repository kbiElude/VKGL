/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_COPY_TEX_SUB_IMAGE_3D_H
#define VKGL_GL_COPY_TEX_SUB_IMAGE_3D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglCopyTexSubImage3D(GLenum  target,
                                             GLint   level,
                                             GLint   xoffset,
                                             GLint   yoffset,
                                             GLint   zoffset,
                                             GLint   x,
                                             GLint   y,
                                             GLsizei width,
                                             GLsizei height);

    void vkglCopyTexSubImage3D_with_validation(VKGL::Context* in_context_ptr,
                                               const GLenum&  in_target,
                                               const GLint&   in_level,
                                               const GLint&   in_xoffset,
                                               const GLint&   in_yoffset,
                                               const GLint&   in_zoffset,
                                               const GLint&   in_x,
                                               const GLint&   in_y,
                                               const GLsizei& in_width,
                                               const GLsizei& in_height);
}

#endif /* VKGL_GL_COPY_TEX_SUB_IMAGE_3D_H */