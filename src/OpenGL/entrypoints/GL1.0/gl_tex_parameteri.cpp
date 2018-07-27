#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteri.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glTexParameteri(GLenum target,
                                            GLenum pname,
                                            GLint  param)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexParameteri(dispatch_table_ptr->bound_context_ptr,
                                         target,
                                         pname,
                                         param);
}

void vkglTexParameteri_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  target,
                                       const GLenum&  pname,
                                       const GLint&   in_param)
{
    todo;
}