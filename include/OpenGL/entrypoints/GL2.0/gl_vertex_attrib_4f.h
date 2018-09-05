/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4F_H
#define VKGL_GL_VERTEX_ATTRIB_4F_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib4f(GLuint  index,
                                          GLfloat x,
                                          GLfloat y,
                                          GLfloat z,
                                          GLfloat w);

    void vkglVertexAttrib4f_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_index,
                                            const GLfloat&   in_x,
                                            const GLfloat&   in_y,
                                            const GLfloat&   in_z,
                                            const GLfloat&   in_w);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_4F_H */