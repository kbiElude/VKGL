/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_PIXEL_STOREF_H
#define VKGL_GL_PIXEL_STOREF_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void APIENTRY vkglPixelStoref(GLenum  pname,
                                  GLfloat param);

    void vkglPixelStoref_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_pname,
                                         const GLfloat& in_param);
}

#endif /* VKGL_GL_PIXEL_STOREF_H */