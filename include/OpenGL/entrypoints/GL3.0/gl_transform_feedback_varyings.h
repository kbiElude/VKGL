#ifndef VKGL_GL_TRANSFORM_FEEDBACK_VARYINGS_H
#define VKGL_GL_TRANSFORM_FEEDBACK_VARYINGS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTransformFeedbackVaryings(GLuint               program,
                                                        GLsizei              count,
                                                        const GLchar* const* varyings,
                                                        GLenum               bufferMode);

#endif /* VKGL_GL_TRANSFORM_FEEDBACK_VARYINGS_H */