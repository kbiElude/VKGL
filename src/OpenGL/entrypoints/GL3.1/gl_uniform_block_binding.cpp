/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_uniform_block_binding.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program,
                     const GLuint&    in_uniform_block_index,
                     const GLuint&    in_uniform_block_binding)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniformBlockBinding(GLuint program,
                                                   GLuint uniformBlockIndex,
                                                   GLuint uniformBlockBinding)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniformBlockBinding(dispatch_table_ptr->bound_context_ptr,
                                               program,
                                               uniformBlockIndex,
                                               uniformBlockBinding);
}

static void vkglUniformBlockBinding_execute(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_program,
                                            const GLuint&    in_uniform_block_index,
                                            const GLuint&    in_uniform_block_binding)
{
    in_context_ptr->uniform_block_binding(in_program,
                                          in_uniform_block_index,
                                          in_uniform_block_binding);
}

void OpenGL::vkglUniformBlockBinding_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLuint&    in_program,
                                                     const GLuint&    in_uniform_block_index,
                                                     const GLuint&    in_uniform_block_binding)
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