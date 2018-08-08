/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_1d.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLint&   in_level,
                     const GLenum&  in_internalformat,
                     const GLsizei& in_width,
                     const GLint&   in_border,
                     const GLsizei& in_image_size,
                     const void*    in_data)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glCompressedTexImage1D(GLenum      target,
                                                   GLint       level,
                                                   GLenum      internalformat,
                                                   GLsizei     width,
                                                   GLint       border,
                                                   GLsizei     imageSize,
                                                   const void* data)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCompressedTexImage1D(dispatch_table_ptr->bound_context_ptr,
                                                target,
                                                level,
                                                internalformat,
                                                width,
                                                border,
                                                imageSize,
                                                data);
}

void vkglCompressedTexImage1D_execute(VKGL::Context* in_context_ptr,
                                      const GLenum&  in_target,
                                      const GLint&   in_level,
                                      const GLenum&  in_internalformat,
                                      const GLsizei& in_width,
                                      const GLint&   in_border,
                                      const GLsizei& in_image_size,
                                      const void*    in_data)
{
    const auto internalformat_vkgl = VKGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = VKGL::Utils::get_texture_target_for_gl_enum( in_target);

    in_context_ptr->compressed_tex_image_1d(in_context_ptr,
                                            target_vkgl,
                                            in_level,
                                            internalformat_vkgl,
                                            in_width,
                                            in_border,
                                            in_image_size,
                                            in_data);
}

void vkglCompressedTexImage1D_with_validation(VKGL::Context* in_context_ptr,
                                              const GLenum&  in_target,
                                              const GLint&   in_level,
                                              const GLenum&  in_internalformat,
                                              const GLsizei& in_width,
                                              const GLint&   in_border,
                                              const GLsizei& in_image_size,
                                              const void*    in_data)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_internalformat,
                 in_width,
                 in_border,
                 in_image_size,
                 in_data))
    {
        vkglCompressedTexImage1D_execute(in_context_ptr,
                                         in_target,
                                         in_level,
                                         in_internalformat,
                                         in_width,
                                         in_border,
                                         in_image_size,
                                         in_data);
    }
}