/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BEGIN_QUERY_H
#define VKGL_GL_BEGIN_QUERY_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBeginQuery(GLenum target,
                                  GLuint id);

void vkglBeginQuery_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLuint&  in_id);

#endif /* VKGL_GL_BEGIN_QUERY_H */