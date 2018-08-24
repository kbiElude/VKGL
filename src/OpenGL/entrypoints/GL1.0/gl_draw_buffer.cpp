/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_draw_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_buf)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY vkglDrawBuffer(GLenum buf)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawBuffer(dispatch_table_ptr->bound_context_ptr,
                                      buf);
}

void vkglDrawBuffer_execute(VKGL::Context* in_context_ptr,
                            const GLenum&  in_buf)
{
    const auto buffer_vkgl = VKGL::Utils::get_draw_buffer_for_gl_enum(in_buf);

    in_context_ptr->set_draw_buffer(buffer_vkgl);
}

void vkglDrawBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_buf)
{
    if (validate(in_context_ptr,
                 in_buf) )
    {
        vkglDrawBuffer_execute(in_context_ptr,
                               in_buf);
    }
}
