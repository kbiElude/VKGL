/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DISABLEI_H
#define VKGL_GL_DISABLEI_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glDisablei(GLenum target,
                                       GLuint index);

void vkglDisablei_with_validation(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_target,
                                  const GLuint&  in_index);

#endif /* VKGL_GL_DISABLEI_H */