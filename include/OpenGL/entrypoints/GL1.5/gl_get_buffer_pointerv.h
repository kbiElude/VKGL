/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BUFFER_POINTERV_H
#define VKGL_GL_GET_BUFFER_POINTERV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetBufferPointerv(GLenum target,
                                             GLenum pname,
                                             void** params);

    void vkglGetBufferPointerv_with_validation(VKGL::Context* in_context_ptr,
                                               const GLenum&  in_target,
                                               const GLenum&  in_pname,
                                               void**         out_params_ptr_ptr);
}

#endif /* VKGL_GL_GET_BUFFER_POINTERV_H */