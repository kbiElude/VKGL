/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_transform_feedback_varying.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     GLuint           in_program,
                     GLuint           in_index,
                     GLsizei          in_buf_size,
                     GLsizei*         out_length_ptr,
                     GLsizei*         out_size_ptr,
                     GLenum*          out_type_ptr,
                     GLchar*          out_name_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetTransformFeedbackVarying(GLuint   program,
                                                           GLuint   index,
                                                           GLsizei  bufSize,
                                                           GLsizei* length,
                                                           GLsizei* size,
                                                           GLenum*  type,
                                                           GLchar*  name)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTransformFeedbackVarying(dispatch_table_ptr->bound_context_ptr,
                                                       program,
                                                       index,
                                                       bufSize,
                                                       length,
                                                       size,
                                                       type,
                                                       name);
}

void vkglGetTransformFeedbackVarying_execute(OpenGL::Context* in_context_ptr,
                                             GLuint           in_program,
                                             GLuint           in_index,
                                             GLsizei          in_buf_size,
                                             GLsizei*         out_length_ptr,
                                             GLsizei*         out_size_ptr,
                                             GLenum*          out_type_ptr,
                                             GLchar*          out_name_ptr)
{
    OpenGL::VariableType type_vkgl = OpenGL::VariableType::Unknown;

    in_context_ptr->get_transform_feedback_varying(in_program,
                                                   in_index,
                                                   in_buf_size,
                                                   out_length_ptr,
                                                   out_size_ptr,
                                                  &type_vkgl,
                                                   out_name_ptr);

    *out_type_ptr = OpenGL::Utils::get_gl_enum_for_variable_type(type_vkgl);
}

void OpenGL::vkglGetTransformFeedbackVarying_with_validation(OpenGL::Context* in_context_ptr,
                                                             GLuint           in_program,
                                                             GLuint           in_index,
                                                             GLsizei          in_buf_size,
                                                             GLsizei*         out_length_ptr,
                                                             GLsizei*         out_size_ptr,
                                                             GLenum*          out_type_ptr,
                                                             GLchar*          out_name_ptr)
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
        vkglGetTransformFeedbackVarying_execute(in_context_ptr,
                                                in_program,
                                                in_index,
                                                in_buf_size,
                                                out_length_ptr,
                                                out_size_ptr,
                                                out_type_ptr,
                                                out_name_ptr);
    }
}
