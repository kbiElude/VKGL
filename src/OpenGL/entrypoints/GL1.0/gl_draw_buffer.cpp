/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_draw_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_buf)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglDrawBuffer(GLenum buf)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawBuffer(dispatch_table_ptr->bound_context_ptr,
                                      buf);
}

static void vkglDrawBuffer_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_buf)
{
    const auto buffer_vkgl = OpenGL::Utils::get_draw_buffer_for_gl_enum(in_buf);

    in_context_ptr->set_draw_buffer(buffer_vkgl);
}

void OpenGL::vkglDrawBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_buf)
{
    if (validate(in_context_ptr,
                 in_buf) )
    {
        vkglDrawBuffer_execute(in_context_ptr,
                               in_buf);
    }
}
