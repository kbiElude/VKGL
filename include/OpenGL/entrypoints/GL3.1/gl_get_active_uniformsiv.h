/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORMSIV_H
#define VKGL_GL_GET_ACTIVE_UNIFORMSIV_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetActiveUniformsiv(GLuint        program,
                                               GLsizei       uniformCount,
                                               const GLuint* uniformIndices,
                                               GLenum        pname,
                                               GLint*        params);

    void vkglGetActiveUniformsiv_with_validation(OpenGL::Context* in_context_ptr,
                                                 const GLuint&    in_program,
                                                 const GLsizei&   in_uniform_count,
                                                 const GLuint*    in_uniform_indices_ptr,
                                                 const GLenum&    in_pname,
                                                 GLint*           out_params_ptr);
}

#endif /* VKGL_GL_GET_ACTIVE_UNIFORMSIV_H */