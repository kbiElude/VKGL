/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_PIXEL_STOREI_H
#define VKGL_GL_PIXEL_STOREI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglPixelStorei(GLenum pname,
                                       GLint  param);

    void vkglPixelStorei_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_pname,
                                         const GLint&     in_param);
}

#endif /* VKGL_GL_PIXEL_STOREI_H */