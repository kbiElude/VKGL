/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BLEND_FUNC_SEPARATE_H
#define VKGL_GL_BLEND_FUNC_SEPARATE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglBlendFuncSeparate(GLenum sfactorRGB,
                                         GLenum dfactorRGB,
                                         GLenum sfactorAlpha,
                                         GLenum dfactorAlpha);

void vkglBlendFuncSeparate_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_sfactorRGB,
                                           const GLenum&  in_dfactorRGB,
                                           const GLenum&  in_sfactorAlpha,
                                           const GLenum&  in_dfactorAlpha);

#endif /* VKGL_GL_BLEND_FUNC_SEPARATE_H */