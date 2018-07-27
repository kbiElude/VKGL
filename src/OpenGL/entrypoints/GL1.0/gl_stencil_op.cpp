#include "OpenGL/entrypoints/GL1.0/gl_stencil_op.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_fail,
                     const GLenum&  in_zfail,
                     const GLenum&  in_zpass)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glStencilOp(GLenum fail,
                                        GLenum zfail,
                                        GLenum zpass)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilOp(dispatch_table_ptr->bound_context_ptr,
                                     fail,
                                     zfail,
                                     zpass);
}

void vkglStencilOp_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_fail,
                                   const GLenum&  in_zfail,
                                   const GLenum&  in_zpass)
{
    if (validate(in_context_ptr,
                 in_fail,
                 in_zfail,
                 in_zpass) )
    {
        todo;
    }
}