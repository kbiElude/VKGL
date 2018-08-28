/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_2UIV_H
#define VKGL_GL_VERTEX_ATTRIB_I_2UIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttribI2uiv(GLuint        index,
                                             const GLuint* v);

    void vkglVertexAttribI2uiv_with_validation(VKGL::Context* in_context_ptr,
                                               const GLuint&  in_index,
                                               const GLuint*  in_v_ptr);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_I_2UIV_H */