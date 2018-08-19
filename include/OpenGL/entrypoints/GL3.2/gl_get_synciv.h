/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_SYNCIV_H
#define VKGL_GL_GET_SYNCIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetSynciv(GLsync   sync,
                                        GLenum   pname,
                                        GLsizei  bufSize,
                                        GLsizei* length,
                                        GLint*   values);

void vkglGetSynciv_with_validation(VKGL::Context* in_context_ptr,
                                   GLsync         in_sync,
                                   GLenum         in_pname,
                                   GLsizei        in_buf_size,
                                   GLsizei*       inout_length_ptr,
                                   GLint*         out_values_ptr);

#endif /* VKGL_GL_GET_SYNCIV_H */