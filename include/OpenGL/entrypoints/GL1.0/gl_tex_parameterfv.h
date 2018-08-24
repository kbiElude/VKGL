/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERFV_H
#define VKGL_GL_TEX_PARAMETERFV_H

#include "OpenGL/types.h"

 void VKGL_APIENTRY vkglTexParameterfv(GLenum         target,
                                       GLenum         pname,
                                       const GLfloat* params);
        #endif /* VKGL_GL_TEX_PARAMETERFV_H */