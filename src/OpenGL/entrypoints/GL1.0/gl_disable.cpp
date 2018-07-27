#include "OpenGL/entrypoints/GL1.0/gl_disable.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glDisable(GLenum cap)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDisable(dispatch_table_ptr->bound_context_ptr,
                                   cap);
}

void vkglDisable_with_validation(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_cap)
{
    todo;
}