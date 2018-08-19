/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_UNIFORM_4UI_H
#define VKGL_GL_UNIFORM_4UI_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glUniform4ui(GLint  location,
                                         GLuint v0,
                                         GLuint v1,
                                         GLuint v2,
                                         GLuint v3);

void vkglUniform4ui_with_validation(VKGL::Context* in_context_ptr,
                                    const GLint&   in_location,
                                    const GLuint&  in_v0,
                                    const GLuint&  in_v1,
                                    const GLuint&  in_v2,
                                    const GLuint&  in_v3);

#endif /* VKGL_GL_UNIFORM_4UI_H */