#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterf.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     const GLfloat& in_param)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glTexParameterf(GLenum  target,
                                            GLenum  pname,
                                            GLfloat param)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexParameterf(dispatch_table_ptr->bound_context_ptr,
                                         target,
                                         pname,
                                         param);
}

void vkglTexParameterf_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_target,
                                       const GLenum&  in_pname,
                                       const GLfloat& in_param)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 in_param) )
    {
        todo;
    }
}