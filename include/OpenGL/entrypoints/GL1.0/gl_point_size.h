/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_SIZE_H
#define VKGL_GL_POINT_SIZE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglPointSize(GLfloat size);

    void vkglPointSize_with_validation(OpenGL::Context* in_context_ptr,
                                       const GLfloat&   in_size);
}

#endif /* VKGL_GL_POINT_SIZE_H */