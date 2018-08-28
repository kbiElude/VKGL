/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ATTACHED_SHADERS_H
#define VKGL_GL_GET_ATTACHED_SHADERS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetAttachedShaders(GLuint   program,
                                              GLsizei  maxCount,
                                              GLsizei* count,
                                              GLuint*  shaders);

    void vkglGetAttachedShaders_with_validation(VKGL::Context* in_context_ptr,
                                                const GLuint&  in_program,
                                                const GLsizei& in_max_count,
                                                GLsizei*       out_count_ptr,
                                                GLuint*        out_shaders_ptr);
}

#endif /* VKGL_GL_GET_ATTACHED_SHADERS_H */