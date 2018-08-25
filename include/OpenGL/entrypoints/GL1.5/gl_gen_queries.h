/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GEN_QUERIES_H
#define VKGL_GL_GEN_QUERIES_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglGenQueries(GLsizei n,
                                  GLuint* ids);

void vkglGenQueries_with_validation(VKGL::Context* in_context_ptr,
                                    const GLsizei& in_n,
                                    GLuint*        out_ids_ptr);

#endif /* VKGL_GL_GEN_QUERIES_H */