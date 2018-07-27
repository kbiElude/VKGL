#ifndef VKGL_GL_IS_ENABLED_H
#define VKGL_GL_IS_ENABLED_H

#include "OpenGL/types.h"

VKGL_API GLboolean VKGL_APIENTRY glIsEnabled(GLenum cap);

GLboolean vkglIsEnabled_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_cap);

#endif /* VKGL_GL_IS_ENABLED_H */