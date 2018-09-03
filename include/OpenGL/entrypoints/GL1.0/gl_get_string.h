/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_STRING_H
#define VKGL_GL_GET_STRING_H

#include "OpenGL/types.h"

namespace OpenGL
{
    const GLubyte *APIENTRY vkglGetString(GLenum name);

    const GLubyte* vkglGetString_with_validation(OpenGL::Context* in_context_ptr,
                                                 const GLenum&    in_name);
}

#endif /* VKGL_GL_GET_STRING_H */