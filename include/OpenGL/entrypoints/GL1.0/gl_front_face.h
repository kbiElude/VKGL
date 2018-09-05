/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRONT_FACE_H
#define VKGL_GL_FRONT_FACE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglFrontFace(GLenum mode);

    void vkglFrontFace_with_validation(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_mode);
}

#endif /* VKGL_GL_FRONT_FACE_H */