/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4D_H
#define VKGL_GL_VERTEX_ATTRIB_4D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib4d(GLuint   index,
                                          GLdouble x,
                                          GLdouble y,
                                          GLdouble z,
                                          GLdouble w);

    void vkglVertexAttrib4d_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_index,
                                            const GLdouble&  in_x,
                                            const GLdouble&  in_y,
                                            const GLdouble&  in_z,
                                            const GLdouble&  in_w);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_4D_H */