/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_transform_feedback_varyings.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context*    in_context_ptr,
                    const GLuint&        in_program,
                    const GLsizei&       in_count,
                    const GLchar* const* in_varyings_ptr_ptr,
                    const GLenum&        in_buffer_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglTransformFeedbackVaryings(GLuint               program,
                                                         GLsizei              count,
                                                         const GLchar* const* varyings,
                                                         GLenum               bufferMode)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glTransformFeedbackVaryings(program=[%u] count=[%d] varyings=[%p] bufferMode=[%s])",
               program,
               static_cast<int32_t>(count),
               varyings,
               OpenGL::Utils::get_raw_string_for_gl_enum(bufferMode) );

    dispatch_table_ptr->pGLTransformFeedbackVaryings(dispatch_table_ptr->bound_context_ptr,
                                                     program,
                                                     count,
                                                     varyings,
                                                     bufferMode);
}

static void vkglTransformFeedbackVaryings_execute(OpenGL::Context*     in_context_ptr,
                                                  const GLuint&        in_program,
                                                  const GLsizei&       in_count,
                                                  const GLchar* const* in_varyings_ptr_ptr,
                                                  const GLenum&        in_buffer_mode)
{
    const auto buffer_mode_vkgl = OpenGL::Utils::get_transform_feedback_buffer_mode_for_gl_enum(in_buffer_mode);

    in_context_ptr->set_transform_feedback_varyings(in_program,
                                                    in_count,
                                                    in_varyings_ptr_ptr,
                                                    buffer_mode_vkgl);
}

void OpenGL::vkglTransformFeedbackVaryings_with_validation(OpenGL::Context*     in_context_ptr,
                                                           const GLuint&        in_program,
                                                           const GLsizei&       in_count,
                                                           const GLchar* const* in_varyings_ptr_ptr,
                                                           const GLenum&        in_buffer_mode)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_count,
                 in_varyings_ptr_ptr,
                 in_buffer_mode) )
    {
        vkglTransformFeedbackVaryings_execute(in_context_ptr,
                                              in_program,
                                              in_count,
                                              in_varyings_ptr_ptr,
                                              in_buffer_mode);
    }
}
