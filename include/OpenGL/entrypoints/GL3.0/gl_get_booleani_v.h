/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_BOOLEANI_V_H
#define VKGL_GL_GET_BOOLEANI_V_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetBooleani_v(GLenum     target,
                                         GLuint     index,
                                         GLboolean* data);

    void vkglGetBooleani_v_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_target,
                                           const GLuint&    in_index,
                                           GLboolean*       out_data_ptr);
}

#endif /* VKGL_GL_GET_BOOLEANI_V_H */