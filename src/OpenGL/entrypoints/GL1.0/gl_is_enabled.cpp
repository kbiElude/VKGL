#include "OpenGL/entrypoints/GL1.0/gl_is_enabled.h"
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


VKGL_API GLboolean VKGL_APIENTRY glIsEnabled(GLenum cap)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsEnabled(dispatch_table_ptr->bound_context_ptr,
                                            cap);
}

GLboolean vkglIsEnabled_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_cap)
{
    todo;
}