/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_4fv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
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

void VKGL_APIENTRY OpenGL::vkglUniformMatrix4fv(GLint          location,
                                                GLsizei        count,
                                                GLboolean      transpose,
                                                const GLfloat* value)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glUniformMatrix4fv(location=[%d] count=[%d] transpose=[%d] value=[%p])",
               location,
               static_cast<int32_t>(count),
               (transpose == GL_TRUE) ? 1 : 0,
               value);

    dispatch_table_ptr->pGLUniformMatrix4fv(dispatch_table_ptr->bound_context_ptr,
                                            location,
                                            count,
                                            transpose,
                                            value);
}

static void vkglUniformMatrix4fv_execute(OpenGL::Context* in_context_ptr,
                                         const GLint&     in_location,
                                         const GLsizei&   in_count,
                                         const GLboolean& in_transpose,
                                         const GLfloat*   in_value_ptr)
{
    in_context_ptr->set_matrix_uniform(in_location,
                                       4, /* in_n_columns */
                                       4, /* in_n_rows    */
                                       in_count,
                                       (in_transpose == GL_TRUE),
                                       in_value_ptr);
}

void OpenGL::vkglUniformMatrix4fv_with_validation(OpenGL::Context* in_context_ptr,
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
        vkglUniformMatrix4fv_execute(in_context_ptr,
                                     in_location,
                                     in_count,
                                     in_transpose,
                                     in_value_ptr);
    }
}
