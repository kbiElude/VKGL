/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_1F_H
#define VKGL_GL_UNIFORM_1F_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglUniform1f(GLint   location,
                                     GLfloat v0);

    void vkglUniform1f_with_validation(VKGL::Context* in_context_ptr,
                                       const GLint&   in_location,
                                       const GLfloat& in_v0);
}

#endif /* VKGL_GL_UNIFORM_1F_H */