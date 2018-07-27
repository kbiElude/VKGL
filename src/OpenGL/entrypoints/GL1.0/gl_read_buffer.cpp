#include "OpenGL/entrypoints/GL1.0/gl_read_buffer.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glReadBuffer(GLenum src)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLReadBuffer(dispatch_table_ptr->bound_context_ptr,
                                      src);
}

void vkglReadBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_src)
{
    todo;
}