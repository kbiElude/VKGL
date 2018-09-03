/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3iv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLsizei&   in_count,
                     const GLint*     in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform3iv(GLint        location,
                                          GLsizei      count,
                                          const GLint* value)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform3iv(dispatch_table_ptr->bound_context_ptr,
                                      location,
                                      count,
                                      value);
}

static void vkglUniform3iv_execute(OpenGL::Context* in_context_ptr,
                                   const GLint&     in_location,
                                   const GLsizei&   in_count,
                                   const GLint*     in_value_ptr)
{
    in_context_ptr->set_uniform_arrayed(in_location,
                                        OpenGL::GetSetArgumentType::Int,
                                        3,
                                        in_count,
                                        in_value_ptr);
}

void OpenGL::vkglUniform3iv_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLint&     in_location,
                                            const GLsizei&   in_count,
                                            const GLint*     in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_count,
                 in_value_ptr) )
    {
        vkglUniform3iv_execute(in_context_ptr,
                               in_location,
                               in_count,
                               in_value_ptr);
    }
}
