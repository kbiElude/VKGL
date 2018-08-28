/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_IS_ENABLED_H
#define VKGL_GL_IS_ENABLED_H

#include "OpenGL/types.h"

namespace OpenGL
{
    GLboolean VKGL_APIENTRY vkglIsEnabled(GLenum cap);

    GLboolean vkglIsEnabled_with_validation(VKGL::Context* in_context_ptr,
                                            const GLenum&  in_cap);
}

#endif /* VKGL_GL_IS_ENABLED_H */