#include "OpenGL/entrypoints/GL1.0/gl_blend_func.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_sfactor,
                     const GLenum&  in_dfactor)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}

VKGL_API void VKGL_APIENTRY glBlendFunc(GLenum sfactor,
                                        GLenum dfactor)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBlendFunc(dispatch_table_ptr->bound_context_ptr,
                                     sfactor,
                                     dfactor);
}

void vkglBlendFunc_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_sfactor,
                                   const GLenum&  in_dfactor)
{
    todo;
}