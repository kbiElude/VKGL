/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORMIV_H
#define VKGL_GL_GET_UNIFORMIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetUniformiv(GLuint program,
                                           GLint  location,
                                           GLint* params);

void vkglGetUniformiv_with_validation(VKGL::Context* in_context_ptr,
                                      const GLuint&  in_program,
                                      const GLint&   in_location,
                                      GLint*         out_params_ptr);

#endif /* VKGL_GL_GET_UNIFORMIV_H */