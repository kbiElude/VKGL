/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_read_pixels.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLsizei& in_width,
                     const GLsizei& in_height,
                     const GLenum&  in_format,
                     const GLenum&  in_type,
                     void*          out_pixels_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglReadPixels(GLint   x,
                                  GLint   y,
                                  GLsizei width,
                                  GLsizei height,
                                  GLenum  format,
                                  GLenum  type,
                                  void*   pixels)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLReadPixels(dispatch_table_ptr->bound_context_ptr,
                                      x,
                                      y,
                                      width,
                                      height,
                                      format,
                                      type,
                                      pixels);
}

void vkglReadPixels_execute(VKGL::Context* in_context_ptr,
                            const GLint&   in_x,
                            const GLint&   in_y,
                            const GLsizei& in_width,
                            const GLsizei& in_height,
                            const GLenum&  in_format,
                            const GLenum&  in_type,
                            void*          out_pixels_ptr)
{
    const auto format_vkgl = VKGL::Utils::get_pixel_format_for_gl_enum(in_format);
    const auto type_vkgl   = VKGL::Utils::get_pixel_type_for_gl_enum  (in_type);

    in_context_ptr->read_pixels(in_x,
                                in_y,
                                in_width,
                                in_height,
                                format_vkgl,
                                type_vkgl,
                                out_pixels_ptr);
}

void vkglReadPixels_with_validation(VKGL::Context* in_context_ptr,
                                    const GLint&   in_x,
                                    const GLint&   in_y,
                                    const GLsizei& in_width,
                                    const GLsizei& in_height,
                                    const GLenum&  in_format,
                                    const GLenum&  in_type,
                                    void*          out_pixels_ptr)
{
    if (validate(in_context_ptr,
                 in_x,
                 in_y,
                 in_width,
                 in_height,
                 in_format,
                 in_type,
                 out_pixels_ptr) )
    {
        vkglReadPixels_execute(in_context_ptr,
                               in_x,
                               in_y,
                               in_width,
                               in_height,
                               in_format,
                               in_type,
                               out_pixels_ptr);
    }
}