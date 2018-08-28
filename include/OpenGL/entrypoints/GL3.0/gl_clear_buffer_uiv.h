/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CLEAR_BUFFER_UIV_H
#define VKGL_GL_CLEAR_BUFFER_UIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglClearBufferuiv(GLenum        buffer,
                                          GLint         drawbuffer,
                                          const GLuint* value);

    void vkglClearBufferuiv_with_validation(VKGL::Context* in_context_ptr,
                                            const GLenum&  in_buffer,
                                            const GLint&   in_drawbuffer,
                                            const GLuint*  in_value_ptr);
}

#endif /* VKGL_GL_CLEAR_BUFFER_UIV_H */