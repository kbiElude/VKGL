/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_2I_H
#define VKGL_GL_UNIFORM_2I_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglUniform2i(GLint location,
                                     GLint v0,
                                     GLint v1);

    void vkglUniform2i_with_validation(VKGL::Context* in_context_ptr,
                                       const GLint&   in_location,
                                       const GLint&   in_v0,
                                       const GLint&   in_v1);
}

#endif /* VKGL_GL_UNIFORM_2I_H */