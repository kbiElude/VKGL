/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DRAW_RANGE_ELEMENTS_H
#define VKGL_GL_DRAW_RANGE_ELEMENTS_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglDrawRangeElements(GLenum      mode,
                                         GLuint      start,
                                         GLuint      end,
                                         GLsizei     count,
                                         GLenum      type,
                                         const void* indices);

void vkglDrawRangeElements_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_mode,
                                           const GLuint&  in_start,
                                           const GLuint&  in_end,
                                           const GLsizei& in_count,
                                           const GLenum&  in_type,
                                           const void*    in_indices);

#endif /* VKGL_GL_DRAW_RANGE_ELEMENTS_H */