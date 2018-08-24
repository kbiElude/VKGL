/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_block_name.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_uniform_block_index,
                     const GLsizei& in_buf_size_ptr,
                     GLsizei*       inout_length_ptr,
                     GLchar*        out_uniform_block_name_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglGetActiveUniformBlockName(GLuint   program,
                                                          GLuint   uniformBlockIndex,
                                                          GLsizei  bufSize,
                                                          GLsizei* length,
                                                          GLchar*  uniformBlockName)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetActiveUniformBlockName(dispatch_table_ptr->bound_context_ptr,
                                                     program,
                                                     uniformBlockIndex,
                                                     bufSize,
                                                     length,
                                                     uniformBlockName);
}

void vkglGetActiveUniformBlockName_execute(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_program,
                                           const GLuint&  in_uniform_block_index,
                                           const GLsizei& in_buf_size_ptr,
                                           GLsizei*       inout_length_ptr,
                                           GLchar*        out_uniform_block_name_ptr)
{
    in_context_ptr->get_active_uniform_block_name(in_program,
                                                  in_uniform_block_index,
                                                  in_buf_size_ptr,
                                                  inout_length_ptr,
                                                  out_uniform_block_name_ptr);
}

void vkglGetActiveUniformBlockName_with_validation(VKGL::Context* in_context_ptr,
                                                   const GLuint&  in_program,
                                                   const GLuint&  in_uniform_block_index,
                                                   const GLsizei& in_buf_size_ptr,
                                                   GLsizei*       inout_length_ptr,
                                                   GLchar*        out_uniform_block_name_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_block_index,
                 in_buf_size_ptr,
                 inout_length_ptr,
                 out_uniform_block_name_ptr) )
    {
        vkglGetActiveUniformBlockName_execute(in_context_ptr,
                                              in_program,
                                              in_uniform_block_index,
                                              in_buf_size_ptr,
                                              inout_length_ptr,
                                              out_uniform_block_name_ptr);
    }
}
