/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_uniform_block_binding.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_uniform_block_index,
                     const GLuint&  in_uniform_block_binding)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glUniformBlockBinding(GLuint program,
                                                  GLuint uniformBlockIndex,
                                                  GLuint uniformBlockBinding)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniformBlockBinding(dispatch_table_ptr->bound_context_ptr,
                                               program,
                                               uniformBlockIndex,
                                               uniformBlockBinding);
}

void vkglUniformBlockBinding_execute(VKGL::Context* in_context_ptr,
                                     const GLuint&  in_program,
                                     const GLuint&  in_uniform_block_index,
                                     const GLuint&  in_uniform_block_binding)
{
    in_context_ptr->uniform_block_binding(in_program,
                                          in_uniform_block_index,
                                          in_uniform_block_binding);
}

void vkglUniformBlockBinding_with_validation(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_program,
                                             const GLuint&  in_uniform_block_index,
                                             const GLuint&  in_uniform_block_binding)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_block_index,
                 in_uniform_block_binding) )
    {
        vkglUniformBlockBinding_execute(in_context_ptr,
                                        in_program,
                                        in_uniform_block_index,
                                        in_uniform_block_binding);
    }
}