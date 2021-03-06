/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORMUIV_H
#define VKGL_GL_GET_UNIFORMUIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetUniformuiv(GLuint  program,
                                         GLint   location,
                                         GLuint* params);

    void vkglGetUniformuiv_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLuint&    in_program,
                                           const GLint&     in_location,
                                           GLuint*          out_params_ptr);
}

#endif /* VKGL_GL_GET_UNIFORMUIV_H */