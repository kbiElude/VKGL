/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_PARAMETERIV_H
#define VKGL_GL_POINT_PARAMETERIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglPointParameteriv(GLenum       pname,
                                                 const GLint* params);

#endif /* VKGL_GL_POINT_PARAMETERIV_H */