/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_2IV_H
#define VKGL_GL_VERTEX_ATTRIB_I_2IV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttribI2iv(GLuint       index,
                                            const GLint* v);

    void vkglVertexAttribI2iv_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_index,
                                              const GLint*     in_v_ptr);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_I_2IV_H */