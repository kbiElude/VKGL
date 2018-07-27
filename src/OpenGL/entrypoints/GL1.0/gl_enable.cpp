#include "OpenGL/entrypoints/GL1.0/gl_enable.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_cap)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glEnable(GLenum cap)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEnable(dispatch_table_ptr->bound_context_ptr,
                                  cap);
}

void vkglEnable_with_validation(VKGL::Context* in_context_ptr,
                                const GLenum&  in_cap)
{
    if (validate(in_context_ptr,
                 in_cap) )
    {
        todo;
    }
}