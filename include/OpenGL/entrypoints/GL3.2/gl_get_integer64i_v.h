/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_INTEGER64I_V_H
#define VKGL_GL_GET_INTEGER64I_V_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetInteger64i_v(GLenum   target,
                                           GLuint   index,
                                           GLint64* data);

    void vkglGetInteger64i_v_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_target,
                                             const GLuint&  in_index,
                                             GLint64*       out_data_ptr);
}

#endif /* VKGL_GL_GET_INTEGER64I_V_H */