/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_1D_H
#define VKGL_GL_VERTEX_ATTRIB_1D_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib1d(GLuint   index,
                                          GLdouble x);

    void vkglVertexAttrib1d_with_validation(VKGL::Context*  in_context_ptr,
                                            const GLuint&   in_index,
                                            const GLdouble& in_x);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_1D_H */