/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_uniform_4uiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_location,
                     const GLsizei& in_count,
                     const GLuint*  in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glUniform4uiv(GLint         location,
                                          GLsizei       count,
                                          const GLuint* value)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform4uiv(dispatch_table_ptr->bound_context_ptr,
                                       location,
                                       count,
                                       value);
}

void vkglUniform4uiv_execute(VKGL::Context* in_context_ptr,
                             const GLint&   in_location,
                             const GLsizei& in_count,
                             const GLuint*  in_value_ptr)
{
    in_context_ptr->set_uniform_arrayed(in_location,
                                        VKGL::GetSetArgumentType::Unsigned_Int,
                                        4,
                                        in_count,
                                        in_value_ptr);
}

void vkglUniform4uiv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLint&   in_location,
                                     const GLsizei& in_count,
                                     const GLuint*  in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_count,
                 in_value_ptr) )
    {
        vkglUniform4uiv_execute(in_context_ptr,
                                in_location,
                                in_count,
                                in_value_ptr);
    }
}
