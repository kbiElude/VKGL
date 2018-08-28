/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H
#define VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetFramebufferAttachmentParameteriv(GLenum target,
                                                               GLenum attachment,
                                                               GLenum pname,
                                                               GLint* params);

    void vkglGetFramebufferAttachmentParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                                                 const GLenum&  in_target,
                                                                 const GLenum&  in_attachment,
                                                                 const GLenum&  in_pname,
                                                                 GLint*         out_params_ptr);
}

#endif /* VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H */