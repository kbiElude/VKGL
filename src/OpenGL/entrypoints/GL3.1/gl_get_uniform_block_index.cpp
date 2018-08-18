/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_block_index.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     GLuint         in_program,
                     const GLchar*  in_uniform_block_name)
{
    bool result = false;

    // ...

    result = true;
    return result;
}

VKGL_API GLuint VKGL_APIENTRY glGetUniformBlockIndex(GLuint        program,
                                                     const GLchar* uniformBlockName)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetUniformBlockIndex(dispatch_table_ptr->bound_context_ptr,
                                                       program,
                                                       uniformBlockName);
}

GLuint vkglGetUniformBlockIndex_execute(VKGL::Context* in_context_ptr,
                                        GLuint         in_program,
                                        const GLchar*  in_uniform_block_name)
{
    return in_context_ptr->get_uniform_block_index(in_program,
                                                   in_uniform_block_name);
}

GLuint vkglGetUniformBlockIndex_with_validation(VKGL::Context* in_context_ptr,
                                                GLuint         in_program,
                                                const GLchar*  in_uniform_block_name)
{
    GLuint result = UINT32_MAX;

    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_block_name) )
    {
        result = vkglGetUniformBlockIndex_execute(in_context_ptr,
                                                  in_program,
                                                  in_uniform_block_name);
    }

    return result;
}
