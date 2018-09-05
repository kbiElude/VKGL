/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_indices.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context*     in_context_ptr,
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

void VKGL_APIENTRY OpenGL::vkglGetUniformIndices(GLuint               program,
                                                 GLsizei              uniformCount,
                                                 const GLchar* const* uniformNames,
                                                 GLuint*              uniformIndices)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glGetUniformIndices(program=[%u] uniformCount=[%d] uniformNames=[%p] uniformIndices=[%p])",
               program,
               static_cast<int32_t>(uniformCount),
               uniformNames,
               uniformIndices);

    dispatch_table_ptr->pGLGetUniformIndices(dispatch_table_ptr->bound_context_ptr,
                                             program,
                                             uniformCount,
                                             uniformNames,
                                             uniformIndices);
}

static void vkglGetUniformIndices_execute(OpenGL::Context*     in_context_ptr,
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

void OpenGL::vkglGetUniformIndices_with_validation(OpenGL::Context*     in_context_ptr,
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
