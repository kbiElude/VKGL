/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_3D_H
#define VKGL_GL_VERTEX_ATTRIB_3D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib3d(GLuint   index,
                                          GLdouble x,
                                          GLdouble y,
                                          GLdouble z);

    void vkglVertexAttrib3d_with_validation(VKGL::Context*  in_context_ptr,
                                            const GLuint&   in_index,
                                            const GLdouble& in_x,
                                            const GLdouble& in_y,
                                            const GLdouble& in_z);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_3D_H */