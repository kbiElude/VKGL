#include "OpenGL/entrypoints/GL1.0/gl_tex_image_2d.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLint&   in_internalformat,
                     const GLsizei& in_width,
                     const GLsizei& in_height,
                     const GLint&   in_border,
                     const GLenum&  in_format,
                     const GLenum&  in_type,
                     const void*    in_pixels_ptr)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glTexImage2D(GLenum      target,
                                         GLint       level,
                                         GLint       internalformat,
                                         GLsizei     width,
                                         GLsizei     height,
                                         GLint       border,
                                         GLenum      format,
                                         GLenum      type,
                                         const void* pixels)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexImage2D(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      level,
                                      internalformat,
                                      width,
                                      height,
                                      border,
                                      format,
                                      type,
                                      pixels);
}

void vkglTexImage2D_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLint&   in_level,
                                    const GLint&   in_internalformat,
                                    const GLsizei& in_width,
                                    const GLsizei& in_height,
                                    const GLint&   in_border,
                                    const GLenum&  in_format,
                                    const GLenum&  in_type,
                                    const void*    in_pixels_ptr)
{
    todo;
}