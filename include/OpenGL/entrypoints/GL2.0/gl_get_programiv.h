/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_PROGRAMIV_H
#define VKGL_GL_GET_PROGRAMIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetProgramiv(GLuint program,
                                        GLenum pname,
                                        GLint* params);

    void vkglGetProgramiv_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_program,
                                          const GLenum&    in_pname,
                                          GLint*           out_params_ptr);
}

#endif /* VKGL_GL_GET_PROGRAMIV_H */