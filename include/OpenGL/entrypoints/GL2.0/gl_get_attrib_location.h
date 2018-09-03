/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ATTRIB_LOCATION_H
#define VKGL_GL_GET_ATTRIB_LOCATION_H

#include "OpenGL/types.h"

namespace OpenGL
{
    GLint VKGL_APIENTRY vkglGetAttribLocation(GLuint        program,
                                              const GLchar* name);

    GLint vkglGetAttribLocation_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_program,
                                                const GLchar*    in_name);
}

#endif /* VKGL_GL_GET_ATTRIB_LOCATION_H */