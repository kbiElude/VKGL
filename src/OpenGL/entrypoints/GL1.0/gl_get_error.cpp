#include "OpenGL/entrypoints/GL1.0/gl_get_error.h"
#include "OpenGL/globals.h"

VKGL_API GLenum VKGL_APIENTRY glGetError(void)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetError(dispatch_table_ptr->bound_context_ptr);
}

GLenum vkglGetError_with_validation(VKGL::Context* in_context_ptr)
{
    todo;
}