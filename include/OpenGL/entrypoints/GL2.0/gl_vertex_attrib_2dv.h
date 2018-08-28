/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_2DV_H
#define VKGL_GL_VERTEX_ATTRIB_2DV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib2dv(GLuint          index,
                                           const GLdouble* v);

    void vkglVertexAttrib2dv_with_validation(VKGL::Context*  in_context_ptr,
                                             const GLuint&   in_index,
                                             const GLdouble* in_v_ptr);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_2DV_H */