/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POLYGON_MODE_H
#define VKGL_GL_POLYGON_MODE_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglPolygonMode(GLenum face,
                                       GLenum mode);

    void vkglPolygonMode_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_face,
                                         const GLenum&    in_mode);
}

#endif /* VKGL_GL_POLYGON_MODE_H */