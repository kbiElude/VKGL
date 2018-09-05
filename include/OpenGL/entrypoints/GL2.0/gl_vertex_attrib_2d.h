/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_2D_H
#define VKGL_GL_VERTEX_ATTRIB_2D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib2d(GLuint   index,
                                          GLdouble x,
                                          GLdouble y);

    void vkglVertexAttrib2d_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_index,
                                            const GLdouble&  in_x,
                                            const GLdouble&  in_y);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_2D_H */