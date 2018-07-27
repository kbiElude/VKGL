#include "OpenGL/entrypoints/GL1.0/gl_stencil_func.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glStencilFunc(GLenum func,
                                          GLint  ref,
                                          GLuint mask)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilFunc(dispatch_table_ptr->bound_context_ptr,
                                       func,
                                       ref,
                                       mask);
}

void vkglStencilFunc_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_func,
                                     const GLint&   in_ref,
                                     const GLuint&  in_mask)
{
    todo;
}