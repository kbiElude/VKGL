#ifndef VKGL_GL_PIXEL_STOREI_H
#define VKGL_GL_PIXEL_STOREI_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glPixelStorei(GLenum pname,
                                          GLint  param);

void vkglPixelStorei_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     const GLint&   in_param);

#endif /* VKGL_GL_PIXEL_STOREI_H */