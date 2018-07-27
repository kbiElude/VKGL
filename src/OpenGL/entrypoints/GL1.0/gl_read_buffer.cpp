#include "OpenGL/entrypoints/GL1.0/gl_read_buffer.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_src)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glReadBuffer(GLenum src)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLReadBuffer(dispatch_table_ptr->bound_context_ptr,
                                      src);
}

void vkglReadBuffer_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_src)
{
    if (validate(in_context_ptr,
                 in_src) )
    {
        todo;
    }
}