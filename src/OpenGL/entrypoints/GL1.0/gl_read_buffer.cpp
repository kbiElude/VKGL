/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_read_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_src)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglReadBuffer(GLenum src)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glReadBuffer(src=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(src) );

    dispatch_table_ptr->pGLReadBuffer(dispatch_table_ptr->bound_context_ptr,
                                      src);
}

static void vkglReadBuffer_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_src)
{
    const auto src_vkgl = OpenGL::Utils::get_read_buffer_for_gl_enum(in_src);

    in_context_ptr->set_read_buffer(src_vkgl);
}

void OpenGL::vkglReadBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_src)
{
    if (validate(in_context_ptr,
                 in_src) )
    {
        vkglReadBuffer_execute(in_context_ptr,
                               in_src);
    }
}