#include "OpenGL/entrypoints/GL1.0/gl_clear.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLbitfield& in_mask)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}

VKGL_API void VKGL_APIENTRY glClear(GLbitfield mask)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClear(dispatch_table_ptr->bound_context_ptr,
                                 mask);
}

void vkglClear_with_validation(VKGL::Context*    in_context_ptr,
                               const GLbitfield& in_mask)
{
    if (validate(in_context_ptr,
                 in_mask) )
    {
        todo;
    }
}