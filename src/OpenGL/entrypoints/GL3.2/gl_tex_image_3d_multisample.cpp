/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_tex_image_3d_multisample.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
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

void VKGL_APIENTRY OpenGL::vkglTexImage3DMultisample(GLenum    target,
                                                     GLsizei   samples,
                                                     GLenum    internalformat,
                                                     GLsizei   width,
                                                     GLsizei   height,
                                                     GLsizei   depth,
                                                     GLboolean fixedsamplelocations)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glTexImage3DMultisample(target=[%s] samples=[%d] internalformat=[%s] width=[%d] height=[%d] depth=[%d] fixedsamplelocations=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               static_cast<int32_t>(samples),
               OpenGL::Utils::get_raw_string_for_gl_enum(internalformat),
               static_cast<int32_t>(width),
               static_cast<int32_t>(height),
               static_cast<int32_t>(depth),
               (fixedsamplelocations == GL_TRUE) ? 1 : 0);

    dispatch_table_ptr->pGLTexImage3DMultisample(dispatch_table_ptr->bound_context_ptr,
                                                 target,
                                                 samples,
                                                 internalformat,
                                                 width,
                                                 height,
                                                 depth,
                                                 fixedsamplelocations);
}

static void vkglTexImage3DMultisample_execute(OpenGL::Context* in_context_ptr,
                                              const GLenum&    in_target,
                                              const GLsizei&   in_samples,
                                              const GLenum&    in_internalformat,
                                              const GLsizei&   in_width,
                                              const GLsizei&   in_height,
                                              const GLsizei&   in_depth,
                                              const GLboolean& in_fixedsamplelocations)
{
    const auto internalformat_vkgl = OpenGL::Utils::get_internal_format_for_gl_enum(in_internalformat);
    const auto target_vkgl         = OpenGL::Utils::get_texture_target_for_gl_enum (in_target);

    in_context_ptr->tex_image_3d_multisample(target_vkgl,
                                             in_samples,
                                             internalformat_vkgl,
                                             in_width,
                                             in_height,
                                             in_depth,
                                             (in_fixedsamplelocations == GL_TRUE) );
}

void OpenGL::vkglTexImage3DMultisample_with_validation(OpenGL::Context* in_context_ptr,
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

