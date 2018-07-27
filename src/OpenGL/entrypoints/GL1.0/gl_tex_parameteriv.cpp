#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteriv.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     const GLint*   in_params_ptr)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glTexParameteriv(GLenum       target,
                                             GLenum       pname,
                                             const GLint* params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexParameteriv(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          pname,
                                          params);
}

void vkglTexParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLenum&  in_pname,
                                        const GLint*   in_params_ptr)
{
    todo;
}