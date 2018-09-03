/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4USV_H
#define VKGL_GL_VERTEX_ATTRIB_4USV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib4usv(GLuint          index,
                                            const GLushort* v);

    void vkglVertexAttrib4usv_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_index,
                                              const GLushort*  in_v_ptr);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_4USV_H */