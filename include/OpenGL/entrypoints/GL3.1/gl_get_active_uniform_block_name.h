/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H
#define VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglGetActiveUniformBlockName(GLuint   program,
                                                     GLuint   uniformBlockIndex,
                                                     GLsizei  bufSize,
                                                     GLsizei* length,
                                                     GLchar*  uniformBlockName);

    void vkglGetActiveUniformBlockName_with_validation(OpenGL::Context* in_context_ptr,
                                                       const GLuint&    in_program,
                                                       const GLuint&    in_uniform_block_index,
                                                       const GLsizei&   in_buf_size_ptr,
                                                       GLsizei*         inout_length_ptr,
                                                       GLchar*          out_uniform_block_name_ptr);
}

#endif /* VKGL_GL_GET_ACTIVE_UNIFORM_BLOCK_NAME_H */