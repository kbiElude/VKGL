#ifndef VKGL_GL_GET_BOOLEANV_H
#define VKGL_GL_GET_BOOLEANV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetBooleanv(GLenum     pname,
                                          GLboolean* data);

void vkglGetBooleanv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLboolean*     out_data_ptr);

#endif /* VKGL_GL_GET_BOOLEANV_H */