#include "OpenGL/entrypoints/GL1.0/gl_depth_func.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glDepthFunc(GLenum func)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDepthFunc(dispatch_table_ptr->bound_context_ptr,
                                     func);
}

void vkglDepthFunc_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_func)
{
    todo;
}