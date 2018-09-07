/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_3UI_H
#define VKGL_GL_VERTEX_ATTRIB_I_3UI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttribI3ui(GLuint index,
                                            GLuint x,
                                            GLuint y,
                                            GLuint z);

    void vkglVertexAttribI3ui_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_index,
                                              const GLuint&    in_x,
                                              const GLuint&    in_y,
                                              const GLuint&    in_z);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_I_3UI_H */