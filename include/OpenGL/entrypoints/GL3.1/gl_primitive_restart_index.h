/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_PRIMITIVE_RESTART_INDEX_H
#define VKGL_GL_PRIMITIVE_RESTART_INDEX_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglPrimitiveRestartIndex(GLuint index);

void vkglPrimitiveRestartIndex_with_validation(VKGL::Context* in_context_ptr,
                                               const GLuint&  in_index);

#endif /* VKGL_GL_PRIMITIVE_RESTART_INDEX_H */