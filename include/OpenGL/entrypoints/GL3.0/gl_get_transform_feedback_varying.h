#ifndef VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H
#define VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTransformFeedbackVarying(GLuint   program,
                                                          GLuint   index,
                                                          GLsizei  bufSize,
                                                          GLsizei* length,
                                                          GLsizei* size,
                                                          GLenum*  type,
                                                          GLchar*  name);

#endif /* VKGL_GL_GET_TRANSFORM_FEEDBACK_VARYING_H */