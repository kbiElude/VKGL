/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_3S_H
#define VKGL_GL_VERTEX_ATTRIB_3S_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib3s(GLuint  index,
                                          GLshort x,
                                          GLshort y,
                                          GLshort z);

    void vkglVertexAttrib3s_with_validation(VKGL::Context* in_context_ptr,
                                            const GLuint&  in_index,
                                            const GLshort& in_x,
                                            const GLshort& in_y,
                                            const GLshort& in_z);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_3S_H */