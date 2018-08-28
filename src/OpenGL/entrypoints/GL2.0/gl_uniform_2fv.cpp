/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2fv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_location,
                     const GLsizei& in_count,
                     const GLfloat* in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform2fv(GLint          location,
                                          GLsizei        count,
                                          const GLfloat* value)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform2fv(dispatch_table_ptr->bound_context_ptr,
                                      location,
                                      count,
                                      value);
}

static void vkglUniform2fv_execute(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLsizei& in_count,
                                   const GLfloat* in_value_ptr)
{
    in_context_ptr->set_uniform_arrayed(in_location,
                                        VKGL::GetSetArgumentType::Float,
                                        2,
                                        in_count,
                                        in_value_ptr);
}

void OpenGL::vkglUniform2fv_with_validation(VKGL::Context* in_context_ptr,
                                            const GLint&   in_location,
                                            const GLsizei& in_count,
                                            const GLfloat* in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_count,
                 in_value_ptr) )
    {
        vkglUniform2fv_execute(in_context_ptr,
                               in_location,
                               in_count,
                               in_value_ptr);
    }
}
