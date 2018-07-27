#include "OpenGL/entrypoints/GL1.0/gl_get_floatv.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glGetFloatv(GLenum   pname,
                                        GLfloat* data)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetFloatv(dispatch_table_ptr->bound_context_ptr,
                                     pname,
                                     data);
}

void vkglGetFloatv_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_pname,
                                   GLfloat*       out_data_ptr)
{
    todo;
}