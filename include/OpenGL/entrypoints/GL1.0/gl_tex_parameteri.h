/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERI_H
#define VKGL_GL_TEX_PARAMETERI_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexParameteri(GLenum target,
                                            GLenum pname,
                                            GLint  param);

void vkglTexParameteri_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  target,
                                       const GLenum&  pname,
                                       const GLint&   in_param);

#endif /* VKGL_GL_TEX_PARAMETERI_H */