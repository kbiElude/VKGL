#ifndef VKGL_GL_BLEND_FUNC_SEPARATE_H
#define VKGL_GL_BLEND_FUNC_SEPARATE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glBlendFuncSeparate(GLenum sfactorRGB,
                                                GLenum dfactorRGB,
                                                GLenum sfactorAlpha,
                                                GLenum dfactorAlpha);

#endif /* VKGL_GL_BLEND_FUNC_SEPARATE_H */