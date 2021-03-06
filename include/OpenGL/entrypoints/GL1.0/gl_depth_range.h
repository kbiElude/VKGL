/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_DEPTH_RANGE_H
#define VKGL_GL_DEPTH_RANGE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglDepthRange(GLdouble n,
                                      GLdouble f);

    void vkglDepthRange_with_validation(OpenGL::Context* in_context_ptr,
                                        const GLdouble&  in_n,
                                        const GLdouble&  in_f);
}

#endif /* VKGL_GL_DEPTH_RANGE_H */