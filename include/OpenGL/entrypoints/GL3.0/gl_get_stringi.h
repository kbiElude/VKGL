/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_STRINGI_H
#define VKGL_GL_GET_STRINGI_H

#include "OpenGL/types.h"

VKGL_API const GLubyte *APIENTRY glGetStringi(GLenum name,
                                              GLuint index);

#endif /* VKGL_GL_GET_STRINGI_H */