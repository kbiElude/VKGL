/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_POLYGON_OFFSET_H
#define VKGL_GL_POLYGON_OFFSET_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglPolygonOffset(GLfloat factor,
                                         GLfloat units);

    void vkglPolygonOffset_with_validation(VKGL::Context* in_context_ptr,
                                           const GLfloat& in_factor,
                                           const GLfloat& in_units);
}

#endif /* VKGL_GL_POLYGON_OFFSET_H */