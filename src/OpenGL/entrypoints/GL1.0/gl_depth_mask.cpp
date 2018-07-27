#include "OpenGL/entrypoints/GL1.0/gl_depth_mask.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glDepthMask(GLboolean flag)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDepthMask(dispatch_table_ptr->bound_context_ptr,
                                     flag);
}

void vkglDepthMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_flag)
{
    todo;
}
