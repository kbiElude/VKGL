#include "OpenGL/entrypoints/GL1.0/gl_get_doublev.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glGetDoublev(GLenum    pname,
                                         GLdouble* data)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetDoublev(dispatch_table_ptr->bound_context_ptr,
                                      pname,
                                      data);
}

void vkglGetDoublev_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_pname,
                                    GLdouble*      out_data_ptr)
{
    todo;
}