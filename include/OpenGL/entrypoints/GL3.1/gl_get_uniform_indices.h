/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_UNIFORM_INDICES_H
#define VKGL_GL_GET_UNIFORM_INDICES_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetUniformIndices(GLuint               program,
                                             GLsizei              uniformCount,
                                             const GLchar* const* uniformNames,
                                             GLuint*              uniformIndices);

    void vkglGetUniformIndices_with_validation(VKGL::Context*       in_context_ptr,
                                               const GLuint&        in_program,
                                               const GLsizei&       in_uniform_count,
                                               const GLchar* const* in_uniform_names_ptr_ptr,
                                               GLuint*              out_uniform_indices_ptr);
}

#endif /* VKGL_GL_GET_UNIFORM_INDICES_H */