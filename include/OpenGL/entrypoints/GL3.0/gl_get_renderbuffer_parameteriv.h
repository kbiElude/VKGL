/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_RENDERBUFFER_PARAMETERIV_H
#define VKGL_GL_GET_RENDERBUFFER_PARAMETERIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetRenderbufferParameteriv(GLenum target,
                                                      GLenum pname,
                                                      GLint* params);

    void vkglGetRenderbufferParameteriv_with_validation(OpenGL::Context* in_context_ptr,
                                                        const GLenum&    in_target,
                                                        const GLenum&    in_pname,
                                                        GLint*           out_params_ptr);
}

#endif /* VKGL_GL_GET_RENDERBUFFER_PARAMETERIV_H */