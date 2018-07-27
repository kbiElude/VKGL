#include "OpenGL/entrypoints/GL1.0/gl_clear_stencil.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glClearStencil(GLint s)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClearStencil(dispatch_table_ptr->bound_context_ptr,
                                        s);
}

void vkglClearStencil_with_validation(VKGL::Context* in_context_ptr,
                                      const GLint&   in_s)
{
    todo;
}