#include "OpenGL/entrypoints/GL1.0/gl_tex_image_1d.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glTexImage1D(GLenum      target,
                                         GLint       level,
                                         GLint       internalformat,
                                         GLsizei     width,
                                         GLint       border,
                                         GLenum      format,
                                         GLenum      type,
                                         const void* pixels)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexImage1D(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      level,
                                      internalformat,
                                      width,
                                      border,
                                      format,
                                      type,
                                      pixels);
}

void vkglTexImage1D_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLint&   in_level,
                                    const GLint&   in_internalformat,
                                    const GLsizei& in_width,
                                    const GLint&   in_border,
                                    const GLenum&  in_format,
                                    const GLenum&  in_type,
                                    const void*    in_pixels_ptr)
{
    todo;
}
