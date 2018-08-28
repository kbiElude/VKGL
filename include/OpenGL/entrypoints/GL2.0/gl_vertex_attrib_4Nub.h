/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4NUB_H
#define VKGL_GL_VERTEX_ATTRIB_4NUB_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglVertexAttrib4Nub(GLuint  index,
                                            GLubyte x,
                                            GLubyte y,
                                            GLubyte z,
                                            GLubyte w);

    void vkglVertexAttrib4Nub_with_validation(VKGL::Context* in_context_ptr,
                                              const GLuint&  in_index,
                                              const GLubyte& in_x,
                                              const GLubyte& in_y,
                                              const GLubyte& in_z,
                                              const GLubyte& in_w);
}

#endif /* VKGL_GL_VERTEX_ATTRIB_4NUB_H */