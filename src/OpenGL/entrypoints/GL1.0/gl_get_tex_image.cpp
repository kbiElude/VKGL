#include "OpenGL/entrypoints/GL1.0/gl_get_tex_image.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_format,
                     const GLenum&  in_type,
                     void*          out_pixels_ptr)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glGetTexImage(GLenum target,
                                          GLint  level,
                                          GLenum format,
                                          GLenum type,
                                          void*  pixels)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexImage(dispatch_table_ptr->bound_context_ptr,
                                       target,
                                       level,
                                       format,
                                       type,
                                       pixels);
}

void vkglGetTexImage_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_target,
                                     const GLint&   in_level,
                                     const GLenum&  in_format,
                                     const GLenum&  in_type,
                                     void*          out_pixels_ptr)
{
    todo;
}