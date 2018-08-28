/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_1FV_H
#define VKGL_GL_VERTEX_ATTRIB_1FV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib1fv(GLuint         index,
                                           const GLfloat* v);

    void vkglVertexAttrib1fv_with_validation(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_index,
                                             const GLfloat* in_v_ptr);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_1FV_H */