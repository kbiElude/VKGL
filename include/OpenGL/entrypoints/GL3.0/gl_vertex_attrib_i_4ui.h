/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_4UI_H
#define VKGL_GL_VERTEX_ATTRIB_I_4UI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttribI4ui(GLuint index,
                                            GLuint x,
                                            GLuint y,
                                            GLuint z,
                                            GLuint w);

    void vkglVertexAttribI4ui_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_index,
                                              const GLuint&    in_x,
                                              const GLuint&    in_y,
                                              const GLuint&    in_z,
                                              const GLuint&    in_w);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_I_4UI_H */