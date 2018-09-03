/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_ENABLE_VERTEX_ATTRIB_ARRAY_H
#define VKGL_GL_ENABLE_VERTEX_ATTRIB_ARRAY_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglEnableVertexAttribArray(GLuint index);

    void vkglEnableVertexAttribArray_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLuint&    in_index);
}

#endif /* VKGL_GL_ENABLE_VERTEX_ATTRIB_ARRAY_H */