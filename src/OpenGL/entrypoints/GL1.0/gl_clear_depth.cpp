#include "OpenGL/entrypoints/GL1.0/gl_clear_depth.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glClearDepth(GLdouble depth)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClearDepth(dispatch_table_ptr->bound_context_ptr,
                                      depth);
}

void vkglClearDepth_with_validation(VKGL::Context*  in_context_ptr,
                                    const GLdouble& in_depth)
{
    todo;
}