/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_END_QUERY_H
#define VKGL_GL_END_QUERY_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglEndQuery(GLenum target);

    void vkglEndQuery_with_validation(VKGL::Context* in_context_ptr,
                                      const GLenum&  in_target);
}

#endif /* VKGL_GL_END_QUERY_H */