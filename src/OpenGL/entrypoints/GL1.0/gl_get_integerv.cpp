#include "OpenGL/entrypoints/GL1.0/gl_get_integerv.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glGetIntegerv(GLenum pname,
                                          GLint* data)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetIntegerv(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       data);
}

void vkglGetIntegerv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLint*         out_data_ptr)
{
    todo;
}