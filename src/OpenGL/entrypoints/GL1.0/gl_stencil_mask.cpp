#include "OpenGL/entrypoints/GL1.0/gl_stencil_mask.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_mask)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glStencilMask(GLuint mask)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilMask(dispatch_table_ptr->bound_context_ptr,
                                       mask);
}

void vkglStencilMask_with_validation(VKGL::Context* in_context_ptr,
                                     const GLuint&  in_mask)
{
    if (validate(in_context_ptr,
                 in_mask) )
    {
        todo;
    }
}