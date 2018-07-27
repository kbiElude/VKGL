#include "OpenGL/entrypoints/GL1.0/gl_viewport.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLsizei& in_width,
                     const GLsizei& in_height)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glViewport(GLint   x,
                                       GLint   y,
                                       GLsizei width,
                                       GLsizei height)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLViewport(dispatch_table_ptr->bound_context_ptr,
                                    x,
                                    y,
                                    width,
                                    height);
}

void vkglViewport_with_validation(VKGL::Context* in_context_ptr,
                                  const GLint&   in_x,
                                  const GLint&   in_y,
                                  const GLsizei& in_width,
                                  const GLsizei& in_height)
{
    todo;
}