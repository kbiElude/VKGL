#include "OpenGL/entrypoints/GL1.0/gl_stencil_op.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glStencilOp(GLenum fail,
                                        GLenum zfail,
                                        GLenum zpass)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilOp(dispatch_table_ptr->bound_context_ptr,
                                     fail,
                                     zfail,
                                     zpass);
}

void vkglStencilOp_with_validation(VKGL::Context* in_context_ptr,
                                   GLenum         in_fail,
                                   GLenum         in_zfail,
                                   GLenum         in_zpass)
{
    todo;
}