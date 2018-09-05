/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_VERTEX_ARRAY_H
#define VKGL_GL_IS_VERTEX_ARRAY_H

#include "OpenGL/types.h"

namespace OpenGL
{
    GLboolean VKGL_APIENTRY vkglIsVertexArray(GLuint array);

    bool vkglIsVertexArray_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLuint&    in_array);
}

#endif /* VKGL_GL_IS_VERTEX_ARRAY_H */