/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_ENABLEDI_H
#define VKGL_GL_IS_ENABLEDI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    GLboolean VKGL_APIENTRY vkglIsEnabledi(GLenum target,
                                           GLuint index);

    GLboolean vkglIsEnabledi_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_target,
                                             const GLuint&    in_index);
}

#endif /* VKGL_GL_IS_ENABLEDI_H */