/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_PARAMETERF_H
#define VKGL_GL_POINT_PARAMETERF_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglPointParameterf(GLenum  pname,
                                           GLfloat param);

    void vkglPointParameterf_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_pname,
                                             const GLfloat&   in_param);
}

#endif /* VKGL_GL_POINT_PARAMETERF_H */