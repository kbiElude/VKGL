/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_FRAG_DATA_LOCATION_H
#define VKGL_GL_BIND_FRAG_DATA_LOCATION_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBindFragDataLocation(GLuint        program,
                                            GLuint        color,
                                            const GLchar* name);

void vkglBindFragDataLocation_with_validation(VKGL::Context* in_context_ptr,
                                              const GLuint&  in_program,
                                              const GLuint&  in_color,
                                              const GLchar*  in_name);

#endif /* VKGL_GL_BIND_FRAG_DATA_LOCATION_H */