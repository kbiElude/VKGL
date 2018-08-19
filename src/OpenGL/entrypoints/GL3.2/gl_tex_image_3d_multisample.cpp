/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_tex_image_3d_multisample.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*   in_context_ptr,
                     const GLenum&    in_target,
                     const GLsizei&   in_samples,
                     const GLenum&    in_internalformat,
                     const GLsizei&   in_width,
                     const GLsizei&   in_height,
                     const GLsizei&   in_depth,
                     const GLboolean& in_fixedsamplelocations)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glTexImage3DMultisample(GLenum    target,
                                                    GLsizei   samples,
                                                    GLenum    internalformat,
                                                    GLsizei   width,
                                                    GLsizei   height,
                                                    GLsizei   depth,
                                                    GLboolean fixedsamplelocations)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexImage3DMultisample(dispatch_table_ptr->bound_context_ptr,
                                                 target,
                                                 samples,
                                                 internalformat,
                                                 width,
                                                 height,
                                                 depth,
                                                 fixedsamplelocations);
}

void vkglTexImage3DMultisample_execute(VKGL::Context*   in_context_ptr,
                                       const GLenum&    in_target,
                                       const GLsizei&   in_samples,
                                       const GLenum&    in_internalformat,
                                       const GLsizei&   in_width,
                                       const GLsizei&   in_height,
                                       const GLsizei&   in_depth,
                                       const GLboolean& in_fixedsamplelocations)
{
    const auto internalformat_vkgl = VKGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = VKGL::Utils::get_texture_target_for_gl_enum (in_target);

    in_context_ptr->tex_image_3d_multisample(target_vkgl,
                                             in_samples,
                                             internalformat_vkgl,
                                             in_width,
                                             in_height,
                                             in_depth,
                                             (in_fixedsamplelocations == GL_TRUE) );
}

void vkglTexImage3DMultisample_with_validation(VKGL::Context*   in_context_ptr,
                                               const GLenum&    in_target,
                                               const GLsizei&   in_samples,
                                               const GLenum&    in_internalformat,
                                               const GLsizei&   in_width,
                                               const GLsizei&   in_height,
                                               const GLsizei&   in_depth,
                                               const GLboolean& in_fixedsamplelocations)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_samples,
                 in_internalformat,
                 in_width,
                 in_height,
                 in_depth,
                 in_fixedsamplelocations) )
    {
        vkglTexImage3DMultisample_execute(in_context_ptr,
                                          in_target,
                                          in_samples,
                                          in_internalformat,
                                          in_width,
                                          in_height,
                                          in_depth,
                                          in_fixedsamplelocations);
    }
}

