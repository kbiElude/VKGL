/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_STRINGI_H
#define VKGL_GL_GET_STRINGI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    const GLubyte *APIENTRY vkglGetStringi(GLenum name,
                                           GLuint index);

    const GLubyte* vkglGetStringi_with_validation(VKGL::Context* in_context_ptr,
                                                  const GLenum&  in_name,
                                                  const GLuint&  in_index);
}

#endif /* VKGL_GL_GET_STRINGI_H */