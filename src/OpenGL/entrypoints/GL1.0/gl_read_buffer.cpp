/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_read_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_src)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glReadBuffer(GLenum src)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLReadBuffer(dispatch_table_ptr->bound_context_ptr,
                                      src);
}

void vkglReadBuffer_execute(VKGL::Context* in_context_ptr,
                            const GLenum&  in_src)
{
    const auto src_vkgl = VKGL::Utils::get_read_buffer_for_gl_enum(in_src);

    in_context_ptr->set_read_buffer(src_vkgl);
}

void vkglReadBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_src)
{
    if (validate(in_context_ptr,
                 in_src) )
    {
        vkglReadBuffer_execute(in_context_ptr,
                               in_src);
    }
}