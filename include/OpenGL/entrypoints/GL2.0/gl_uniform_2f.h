/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_2F_H
#define VKGL_GL_UNIFORM_2F_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglUniform2f(GLint   location,
                                     GLfloat v0,
                                     GLfloat v1);

    void vkglUniform2f_with_validation(OpenGL::Context* in_context_ptr,
                                       const GLint&     in_location,
                                       const GLfloat&   in_v0,
                                       const GLfloat&   in_v1);
}

#endif /* VKGL_GL_UNIFORM_2F_H */