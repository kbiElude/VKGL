/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_bind_buffer_base.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_index,
                     const GLuint&  in_buffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglBindBufferBase(GLenum target,
                                               GLuint index,
                                               GLuint buffer)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindBufferBase(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          index,
                                          buffer);
}

void vkglBindBufferBase_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_target,
                                const GLuint&  in_index,
                                const GLuint&  in_buffer)
{
    const auto target_vkgl = VKGL::Utils::get_buffer_target_for_gl_enum(in_target);

    in_context_ptr->bind_buffer_base(target_vkgl,
                                     in_index,
                                     in_buffer);
}

void vkglBindBufferBase_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLuint&  in_index,
                                        const GLuint&  in_buffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_index,
                 in_buffer) )
    {
        vkglBindBufferBase_execute(in_context_ptr,
                                   in_target,
                                   in_index,
                                   in_buffer);
    }
}
