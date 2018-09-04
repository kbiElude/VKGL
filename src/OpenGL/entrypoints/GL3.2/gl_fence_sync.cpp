/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_fence_sync.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context*  in_context_ptr,
                     const GLenum&     in_condition,
                     const GLbitfield& in_flags)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLsync VKGL_APIENTRY OpenGL::vkglFenceSync(GLenum     condition,
                                           GLbitfield flags)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glFenceSync(condition=[%s] flags=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(condition),
               OpenGL::Utils::get_raw_string_for_gl_bitfield(OpenGL::BitfieldType::Sync_Condition_Mask, flags) );

    return dispatch_table_ptr->pGLFenceSync(dispatch_table_ptr->bound_context_ptr,
                                            condition,
                                            flags);
}

static GLsync vkglFenceSync_execute(OpenGL::Context*  in_context_ptr,
                                    const GLenum&     in_condition,
                                    const GLbitfield& in_flags)
{
    const auto condition_vkgl = OpenGL::Utils::get_sync_condition_for_gl_enum(in_condition);

    vkgl_assert(in_flags == 0);

    return in_context_ptr->fence_sync(condition_vkgl);
}

GLsync OpenGL::vkglFenceSync_with_validation(OpenGL::Context*  in_context_ptr,
                                             const GLenum&     in_condition,
                                             const GLbitfield& in_flags)
{
    GLsync result = nullptr;

    if (validate(in_context_ptr,
                 in_condition,
                 in_flags) )
    {
        result = vkglFenceSync_execute(in_context_ptr,
                                       in_condition,
                                       in_flags);
    }

    return result;
}
