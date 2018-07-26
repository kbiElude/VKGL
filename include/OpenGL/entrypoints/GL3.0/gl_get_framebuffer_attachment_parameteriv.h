#ifndef VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H
#define VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetFramebufferAttachmentParameteriv(GLenum target,
                                                                  GLenum attachment,
                                                                  GLenum pname,
                                                                  GLint* params);

#endif /* VKGL_GL_GET_FRAMEBUFFER_ATTACHMENT_PARAMETERIV_H */