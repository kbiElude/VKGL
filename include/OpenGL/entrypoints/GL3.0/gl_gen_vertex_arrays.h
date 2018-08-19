/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GEN_VERTEX_ARRAYS_H
#define VKGL_GL_GEN_VERTEX_ARRAYS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGenVertexArrays(GLsizei n,
                                              GLuint* arrays);

void vkglGenVertexArrays_with_validation(VKGL::Context* in_context_ptr,
                                         const GLsizei& in_n,
                                         GLuint*        out_arrays_ptr);

#endif /* VKGL_GL_GEN_VERTEX_ARRAYS_H */