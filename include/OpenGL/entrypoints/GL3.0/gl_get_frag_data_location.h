/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_FRAG_DATA_LOCATION_H
#define VKGL_GL_GET_FRAG_DATA_LOCATION_H

#include "OpenGL/types.h"

namespace OpenGL
{
    GLint VKGL_APIENTRY vkglGetFragDataLocation(GLuint        program,
                                                const GLchar* name);

    GLint vkglGetFragDataLocation_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLuint&    in_program,
                                                  const GLchar*    in_name_ptr);
}

#endif /* VKGL_GL_GET_FRAG_DATA_LOCATION_H */