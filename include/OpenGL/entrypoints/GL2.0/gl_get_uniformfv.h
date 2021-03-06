/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORMFV_H
#define VKGL_GL_GET_UNIFORMFV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetUniformfv(GLuint   program,
                                        GLint    location,
                                        GLfloat* params);

    void vkglGetUniformfv_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_program,
                                          const GLint&     in_location,
                                          GLfloat*         out_params_ptr);
}

#endif /* VKGL_GL_GET_UNIFORMFV_H */