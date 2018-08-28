/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_PROGRAM_H
#define VKGL_GL_IS_PROGRAM_H

#include "OpenGL/types.h"

namespace OpenGL
{
    GLboolean VKGL_APIENTRY vkglIsProgram(GLuint program);

    bool vkglIsProgram_with_validation(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_program);
}

#endif /* VKGL_GL_IS_PROGRAM_H */