#include "OpenGL/entrypoints/GL1.0/gl_finish.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glFinish(void)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFinish(dispatch_table_ptr->bound_context_ptr);
}

void vkglFinish_with_validation(VKGL::Context* in_context_ptr)
{
    todo;
}