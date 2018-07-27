#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameterfv.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_pname,
                     GLfloat*       out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glGetTexLevelParameterfv(GLenum   target,
                                                     GLint    level,
                                                     GLenum   pname,
                                                     GLfloat* params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexLevelParameterfv(dispatch_table_ptr->bound_context_ptr,
                                                  target,
                                                  level,
                                                  pname,
                                                  params);
}

void vkglGetTexLevelParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLint&   in_level,
                                                const GLenum&  in_pname,
                                                GLfloat*       out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_pname,
                 out_params_ptr) )
    {
        todo;
    }
}
