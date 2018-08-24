/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_renderbuffer_storage_multisample.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLsizei& in_samples,
                     const GLenum&  in_internalformat,
                     const GLsizei& in_width,
                     const GLsizei& in_height)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglRenderbufferStorageMultisample(GLenum  target,
                                                               GLsizei samples,
                                                               GLenum  internalformat,
                                                               GLsizei width,
                                                               GLsizei height)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLRenderbufferStorageMultisample(dispatch_table_ptr->bound_context_ptr,
                                                          target,
                                                          samples,
                                                          internalformat,
                                                          width,
                                                          height);
}

void vkglRenderbufferStorageMultisample_execute(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLsizei& in_samples,
                                                const GLenum&  in_internalformat,
                                                const GLsizei& in_width,
                                                const GLsizei& in_height)
{
    const auto internalformat_vkgl = VKGL::Utils::get_internal_format_for_gl_enum    (in_internalformat);
    const auto target_vkgl         = VKGL::Utils::get_renderbuffer_target_for_gl_enum(in_target);

    in_context_ptr->renderbuffer_storage_multisample(target_vkgl,
                                                     in_samples,
                                                     internalformat_vkgl,
                                                     in_width,
                                                     in_height);
}

void vkglRenderbufferStorageMultisample_with_validation(VKGL::Context* in_context_ptr,
                                                        const GLenum&  in_target,
                                                        const GLsizei& in_samples,
                                                        const GLenum&  in_internalformat,
                                                        const GLsizei& in_width,
                                                        const GLsizei& in_height)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_samples,
                 in_internalformat,
                 in_width,
                 in_height) )
    {
        vkglRenderbufferStorageMultisample_execute(in_context_ptr,
                                                   in_target,
                                                   in_samples,
                                                   in_internalformat,
                                                   in_width,
                                                   in_height);
    }
}
