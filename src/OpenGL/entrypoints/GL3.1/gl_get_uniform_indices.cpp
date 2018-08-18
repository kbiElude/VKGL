/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_indices.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*       in_context_ptr,
                     const GLuint&        in_program,
                     const GLsizei&       in_uniform_count,
                     const GLchar* const* in_uniform_names_ptr_ptr,
                     GLuint*              out_uniform_indices_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glGetUniformIndices(GLuint               program,
                                                GLsizei              uniformCount,
                                                const GLchar* const* uniformNames,
                                                GLuint*              uniformIndices)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetUniformIndices(dispatch_table_ptr->bound_context_ptr,
                                             program,
                                             uniformCount,
                                             uniformNames,
                                             uniformIndices);
}

void vkglGetUniformIndices_execute(VKGL::Context*       in_context_ptr,
                                   const GLuint&        in_program,
                                   const GLsizei&       in_uniform_count,
                                   const GLchar* const* in_uniform_names_ptr_ptr,
                                   GLuint*              out_uniform_indices_ptr)
{
    in_context_ptr->get_uniform_indices(in_program,
                                        in_uniform_count,
                                        in_uniform_names_ptr_ptr,
                                        out_uniform_indices_ptr);
}

void vkglGetUniformIndices_with_validation(VKGL::Context*       in_context_ptr,
                                           const GLuint&        in_program,
                                           const GLsizei&       in_uniform_count,
                                           const GLchar* const* in_uniform_names_ptr_ptr,
                                           GLuint*              out_uniform_indices_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_count,
                 in_uniform_names_ptr_ptr,
                 out_uniform_indices_ptr) )
    {
        vkglGetUniformIndices_execute(in_context_ptr,
                                      in_program,
                                      in_uniform_count,
                                      in_uniform_names_ptr_ptr,
                                      out_uniform_indices_ptr);
    }
}
