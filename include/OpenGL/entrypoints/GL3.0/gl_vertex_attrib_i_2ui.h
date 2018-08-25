/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_2UI_H
#define VKGL_GL_VERTEX_ATTRIB_I_2UI_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglVertexAttribI2ui(GLuint index,
                                        GLuint x,
                                        GLuint y);

void vkglVertexAttribI2ui_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_index,
                                          const GLuint&  in_x,
                                          const GLuint&  in_y);

#endif /* VKGL_GL_VERTEX_ATTRIB_I_2UI_H */