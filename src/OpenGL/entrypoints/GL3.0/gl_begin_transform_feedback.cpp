/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_begin_transform_feedback.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_primitive_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBeginTransformFeedback(GLenum primitiveMode)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBeginTransformFeedback(primitiveMode=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(primitiveMode) );

    dispatch_table_ptr->pGLBeginTransformFeedback(dispatch_table_ptr->bound_context_ptr,
                                                  primitiveMode);
}

static void vkglBeginTransformFeedback_execute(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_primitive_mode)
{
    const auto primitive_mode_vkgl = OpenGL::Utils::get_transform_feedback_primitive_mode_for_gl_enum(in_primitive_mode);

    in_context_ptr->begin_transform_feedback(primitive_mode_vkgl);
}

void OpenGL::vkglBeginTransformFeedback_with_validation(OpenGL::Context* in_context_ptr,
                                                        const GLenum&    in_primitive_mode)
{
    if (validate(in_context_ptr,
                 in_primitive_mode) )
    {
        vkglBeginTransformFeedback_execute(in_context_ptr,
                                           in_primitive_mode);
    }
}
