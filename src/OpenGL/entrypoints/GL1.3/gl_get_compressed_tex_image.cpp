/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.3/gl_get_compressed_tex_image.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     GLenum         in_target,
                     GLint          in_level,
                     void*          in_img)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGetCompressedTexImage(GLenum target,
                                             GLint  level,
                                             void*  img)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetCompressedTexImage(dispatch_table_ptr->bound_context_ptr,
                                                 target,
                                                 level,
                                                 img);
}

void vkglGetCompressedTexImage_execute(VKGL::Context* in_context_ptr,
                                       GLenum         in_target,
                                       GLint          in_level,
                                       void*          in_img)
{
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum(in_target);

    in_context_ptr->get_compressed_tex_image(target_vkgl,
                                             in_level,
                                             in_img);
}

void vkglGetCompressedTexImage_with_validation(VKGL::Context* in_context_ptr,
                                               GLenum         in_target,
                                               GLint          in_level,
                                               void*          in_img)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_level,
                 in_img) )
    {
        vkglGetCompressedTexImage_execute(in_context_ptr,
                                          in_target,
                                          in_level,
                                          in_img);
    }
}
