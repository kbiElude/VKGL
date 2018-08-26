/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_RENDERBUFFER_H
#define VKGL_GL_IS_RENDERBUFFER_H

#include "OpenGL/types.h"

GLboolean VKGL_APIENTRY vkglIsRenderbuffer(GLuint renderbuffer);

bool vkglIsRenderbuffer_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_renderbuffer);

#endif /* VKGL_GL_IS_RENDERBUFFER_H */