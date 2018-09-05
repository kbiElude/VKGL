/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BIND_ATTRIB_LOCATION_H
#define VKGL_GL_BIND_ATTRIB_LOCATION_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglBindAttribLocation(GLuint        program,
                                              GLuint        index,
                                              const GLchar* name);

    void vkglBindAttribLocation_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_program,
                                                const GLuint&    in_index,
                                                const GLchar*    in_name);
}

#endif /* VKGL_GL_BIND_ATTRIB_LOCATION_H */