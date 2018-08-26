/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_3F_H
#define VKGL_GL_VERTEX_ATTRIB_3F_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglVertexAttrib3f(GLuint  index,
                                      GLfloat x,
                                      GLfloat y,
                                      GLfloat z);

void vkglVertexAttrib3f_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLfloat& in_x,
                                        const GLfloat& in_y,
                                        const GLfloat& in_z);

#endif /* VKGL_GL_VERTEX_ATTRIB_3F_H */