#include "OpenGL/entrypoints/GL1.0/gl_draw_buffer.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glDrawBuffer(GLenum buf)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawBuffer(dispatch_table_ptr->bound_context_ptr,
                                      buf);
}

void vkglDrawBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum*  in_buf)
{
    todo;
}
