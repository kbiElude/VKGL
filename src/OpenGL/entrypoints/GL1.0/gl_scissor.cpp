#include "OpenGL/entrypoints/GL1.0/gl_scissor.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glScissor(GLint   x,
                                      GLint   y,
                                      GLsizei width,
                                      GLsizei height)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLScissor(dispatch_table_ptr->bound_context_ptr,
                                   x,
                                   y,
                                   width,
                                   height);
}

void vkglScissor_with_validation(VKGL::Context* in_context_ptr,
                                 const GLint&   x,
                                 const GLint&   in_y,
                                 const GLsizei& in_width,
                                 const GLsizei& in_height)
{
    todo;
}