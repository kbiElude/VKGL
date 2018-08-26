/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_2x4_fv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*   in_context_ptr,
                     const GLint&     in_location,
                     const GLsizei&   in_count,
                     const GLboolean& in_transpose,
                     const GLfloat*   in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglUniformMatrix2x4fv(GLint          location,
                                          GLsizei        count,
                                          GLboolean      transpose,
                                          const GLfloat* value)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniformMatrix2x4fv(dispatch_table_ptr->bound_context_ptr,
                                              location,
                                              count,
                                              transpose,
                                              value);
}

void vkglUniformMatrix2x4fv_execute(VKGL::Context*   in_context_ptr,
                                    const GLint&     in_location,
                                    const GLsizei&   in_count,
                                    const GLboolean& in_transpose,
                                    const GLfloat*   in_value_ptr)
{
    in_context_ptr->set_uniform_matrix_arrayed(in_location,
                                               VKGL::GetSetArgumentType::Float,
                                               2,
                                               4,
                                               in_count,
                                               (in_transpose == GL_TRUE),
                                               in_value_ptr);
}

void vkglUniformMatrix2x4fv_with_validation(VKGL::Context*   in_context_ptr,
                                            const GLint&     in_location,
                                            const GLsizei&   in_count,
                                            const GLboolean& in_transpose,
                                            const GLfloat*   in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_count,
                 in_transpose,
                 in_value_ptr) )
    {
        vkglUniformMatrix2x4fv_execute(in_context_ptr,
                                       in_location,
                                       in_count,
                                       in_transpose,
                                       in_value_ptr);
    }
}

