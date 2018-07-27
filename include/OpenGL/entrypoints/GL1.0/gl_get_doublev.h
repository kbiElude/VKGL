#ifndef VKGL_GL_GET_DOUBLEV_H
#define VKGL_GL_GET_DOUBLEV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetDoublev(GLenum    pname,
                                         GLdouble* data);

void vkglGetDoublev_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_pname,
                                    GLdouble*      out_data_ptr);

#endif /* VKGL_GL_GET_DOUBLEV_H */