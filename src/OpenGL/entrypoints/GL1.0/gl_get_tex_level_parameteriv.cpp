#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameteriv.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_pname,
                     GLint*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glGetTexLevelParameteriv(GLenum target,
                                                     GLint  level,
                                                     GLenum pname,
                                                     GLint* params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexLevelParameteriv(dispatch_table_ptr->bound_context_ptr,
                                                  target,
                                                  level,
                                                  pname,
                                                  params);
}

void vkglGetTexLevelParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLint&   in_level,
                                                const GLenum&  in_pname,
                                                GLint*         out_params_ptr)
{
    todo;
}