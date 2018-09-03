/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_SHADERIV_H
#define VKGL_GL_GET_SHADERIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetShaderiv(GLuint shader,
                                       GLenum pname,
                                       GLint* params);

    void vkglGetShaderiv_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_shader,
                                         const GLenum&    in_pname,
                                         GLint*           out_params_ptr);
}

#endif /* VKGL_GL_GET_SHADERIV_H */