#ifndef VKGL_GL_GET_INTEGERV_H
#define VKGL_GL_GET_INTEGERV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetIntegerv(GLenum pname,
                                          GLint* data);

void vkglGetIntegerv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLint*         out_data_ptr);

#endif /* VKGL_GL_GET_INTEGERV_H */