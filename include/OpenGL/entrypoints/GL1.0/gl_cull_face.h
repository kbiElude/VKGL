/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CULL_FACE_H
#define VKGL_GL_CULL_FACE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglCullFace(GLenum mode);

void vkglCullFace_with_validation(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_mode);

#endif /* VKGL_GL_CULL_FACE_H */