/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_I_4I_H
#define VKGL_GL_VERTEX_ATTRIB_I_4I_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttribI4i(GLuint index,
                                           GLint  x,
                                           GLint  y,
                                           GLint  z,
                                           GLint  w);

    void vkglVertexAttribI4i_with_validation(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_index,
                                             const GLint&   in_x,
                                             const GLint&   in_y,
                                             const GLint&   in_z,
                                             const GLint&   in_w);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_I_4I_H */