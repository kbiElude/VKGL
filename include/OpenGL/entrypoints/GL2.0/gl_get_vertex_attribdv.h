/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_VERTEX_ATTRIBDV_H
#define VKGL_GL_GET_VERTEX_ATTRIBDV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetVertexAttribdv(GLuint    index,
                                             GLenum    pname,
                                             GLdouble* params);

    void vkglGetVertexAttribdv_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLuint&    in_index,
                                               const GLenum&    in_pname,
                                               GLdouble*        out_params_ptr);
}

#endif /* VKGL_GL_GET_VERTEX_ATTRIBDV_H */