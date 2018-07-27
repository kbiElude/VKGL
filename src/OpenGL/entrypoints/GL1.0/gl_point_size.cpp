#include "OpenGL/entrypoints/GL1.0/gl_point_size.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glPointSize(GLfloat size)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointSize(dispatch_table_ptr->bound_context_ptr,
                                     size);
}

void vkglPointSize_with_validation(VKGL::Context* in_context_ptr,
                                   const GLfloat& in_size)
{
    todo;
}