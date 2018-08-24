/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_active_uniform.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_index,
                     const GLsizei& in_buf_size,
                     GLsizei*       out_length_ptr,
                     GLint*         out_size_ptr,
                     GLenum*        out_type_ptr,
                     GLchar*        out_name_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglGetActiveUniform(GLuint   program,
                                                 GLuint   index,
                                                 GLsizei  bufSize,
                                                 GLsizei* length,
                                                 GLint*   size,
                                                 GLenum*  type,
                                                 GLchar*  name)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetActiveUniform(dispatch_table_ptr->bound_context_ptr,
                                            program,
                                            index,
                                            bufSize,
                                            length,
                                            size,
                                            type,
                                            name);
}

void vkglGetActiveUniform_execute(VKGL::Context* in_context_ptr,
                                  const GLuint&  in_program,
                                  const GLuint&  in_index,
                                  const GLsizei& in_buf_size,
                                  GLsizei*       out_length_ptr,
                                  GLint*         out_size_ptr,
                                  GLenum*        out_type_ptr,
                                  GLchar*        out_name_ptr)
{
    auto type_vkgl = VKGL::VariableType::Unknown;

    in_context_ptr->get_active_uniform(in_program,
                                       in_index,
                                       in_buf_size,
                                       out_length_ptr,
                                       out_size_ptr,
                                      &type_vkgl,
                                       out_name_ptr)

    *out_type_ptr = VKGL::Utils::get_gl_enum_for_variable_type(type_vkgl);
}

void vkglGetActiveUniform_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_program,
                                          const GLuint&  in_index,
                                          const GLsizei& in_buf_size,
                                          GLsizei*       out_length_ptr,
                                          GLint*         out_size_ptr,
                                          GLenum*        out_type_ptr,
                                          GLchar*        out_name_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_index,
                 in_buf_size,
                 out_length_ptr,
                 out_size_ptr,
                 out_type_ptr,
                 out_name_ptr) )
    {
        vkglGetActiveUniform_execute(in_context_ptr,
                                     in_program,
                                     in_index,
                                     in_buf_size,
                                     out_length_ptr,
                                     out_size_ptr,
                                     out_type_ptr,
                                     out_name_ptr);
    }
}