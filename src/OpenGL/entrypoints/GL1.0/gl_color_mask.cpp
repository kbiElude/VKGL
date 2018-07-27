#include "OpenGL/entrypoints/GL1.0/gl_color_mask.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glColorMask(GLboolean red,
                                        GLboolean green,
                                        GLboolean blue,
                                        GLboolean alpha)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLColorMask(dispatch_table_ptr->bound_context_ptr,
                                     red,
                                     green,
                                     blue,
                                     alpha);
}

void vkglColorMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_red,
                                   const GLboolean& in_green,
                                   const GLboolean& in_blue,
                                   const GLboolean& in_alpha)
{
    todo;
}