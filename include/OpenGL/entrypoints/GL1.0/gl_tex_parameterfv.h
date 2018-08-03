/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERFV_H
#define VKGL_GL_TEX_PARAMETERFV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameterfv(GLenum         target,
                                             GLenum         pname,
                                             const GLfloat* params);

void vkglTexParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  target,
                                        const GLenum&  in_pname,
                                        const GLfloat* in_params_ptr);

#endif /* VKGL_GL_TEX_PARAMETERFV_H */