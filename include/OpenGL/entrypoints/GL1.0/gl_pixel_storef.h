#ifndef VKGL_GL_PIXEL_STOREF_H
#define VKGL_GL_PIXEL_STOREF_H

#include "OpenGL/types.h"

GLAPI void APIENTRY glPixelStoref(GLenum  pname,
                                  GLfloat param);

void vkglPixelStoref_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     const GLfloat& in_param);

#endif /* VKGL_GL_PIXEL_STOREF_H */