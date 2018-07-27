#include "OpenGL/entrypoints/GL1.0/gl_hint.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_mode)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glHint(GLenum target,
                                   GLenum mode)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLHint(dispatch_table_ptr->bound_context_ptr,
                                target,
                                mode);
}

void vkglHint_with_validation(VKGL::Context* in_context_ptr,
                              const GLenum&  in_target,
                              const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_mode) )
    {
        todo;
    }
}