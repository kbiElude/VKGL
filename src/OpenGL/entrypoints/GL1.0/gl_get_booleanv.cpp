#include "OpenGL/entrypoints/GL1.0/gl_get_booleanv.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glGetBooleanv(GLenum     pname,
                                          GLboolean* data)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetBooleanv(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       data);
}

void vkglGetBooleanv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLboolean*     out_data_ptr)
{
    todo;
}