/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_bind_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_buffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglBindBuffer(GLenum target,
                                           GLuint buffer)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindBuffer(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      buffer);
}

void vkglBindBuffer_execute(VKGL::Context* in_context_ptr,
                            const GLenum&  in_target,
                            const GLuint&  in_buffer)
{
    const auto target_vkgl = VKGL::Utils::get_buffer_target_for_gl_enum(in_target);

    in_context_ptr->bind_buffer(target_vkgl,
                                in_buffer);
}

void vkglBindBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLuint&  in_buffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_buffer) )
    {
        vkglBindBuffer_execute(in_context_ptr,
                               in_target,
                               in_buffer);
    }
}


