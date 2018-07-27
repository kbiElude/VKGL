#ifndef VKGL_GL_LINE_WIDTH_H
#define VKGL_GL_LINE_WIDTH_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glLineWidth(GLfloat width);

void vkglLineWidth_with_validation(VKGL::Context* in_context_ptr,
                                   const GLfloat& in_width);

#endif /* VKGL_GL_LINE_WIDTH_H */