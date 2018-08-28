/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_VERTEX_ATTRIBIV_H
#define VKGL_GL_GET_VERTEX_ATTRIBIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetVertexAttribiv(GLuint index,
                                             GLenum pname,
                                             GLint* params);

    void vkglGetVertexAttribiv_with_validation(VKGL::Context* in_context_ptr,
                                               const GLuint&  in_index,
                                               const GLenum&  in_pname,
                                               GLint*         out_params_ptr);
}

#endif /* VKGL_GL_GET_VERTEX_ATTRIBIV_H */