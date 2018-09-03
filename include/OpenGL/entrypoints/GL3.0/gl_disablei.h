/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DISABLEI_H
#define VKGL_GL_DISABLEI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDisablei(GLenum target,
                                    GLuint index);

    void vkglDisablei_with_validation(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_target,
                                      const GLuint&    in_index);
}

#endif /* VKGL_GL_DISABLEI_H */