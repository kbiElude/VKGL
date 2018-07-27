#ifndef VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H
#define VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexLevelParameterfv(GLenum   target,
                                                     GLint    level,
                                                     GLenum   pname,
                                                     GLfloat* params);

void vkglGetTexLevelParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLint&   in_level,
                                                const GLenum&  in_pname,
                                                GLfloat*       out_params_ptr);

#endif /* VKGL_GL_GET_TEX_LEVEL_PARAMETERFV_H */