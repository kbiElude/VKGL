/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POINT_PARAMETERI_H
#define VKGL_GL_POINT_PARAMETERI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglPointParameteri(GLenum pname,
                                           GLint  param);

    void vkglPointParameteri_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_pname,
                                             const GLint&   in_param);
}

#endif /* VKGL_GL_POINT_PARAMETERI_H */