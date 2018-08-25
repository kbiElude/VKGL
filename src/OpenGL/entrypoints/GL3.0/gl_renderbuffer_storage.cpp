/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_renderbuffer_storage.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_internalformat,
                     const GLsizei& in_width,
                     const GLsizei& in_height)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglRenderbufferStorage(GLenum  target,
                                           GLenum  internalformat,
                                           GLsizei width,
                                           GLsizei height)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLRenderbufferStorage(dispatch_table_ptr->bound_context_ptr,
                                               target,
                                               internalformat,
                                               width,
                                               height);
}

void vkglRenderbufferStorage_execute(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_target,
                                     const GLenum&  in_internalformat,
                                     const GLsizei& in_width,
                                     const GLsizei& in_height)
{
    const auto internalformat_vkgl = VKGL::Utils::get_internal_format_for_gl_enum    (in_internalformat);
    const auto target_vkgl         = VKGL::Utils::get_renderbuffer_target_for_gl_enum(in_target);

    in_context_ptr->renderbuffer_storage(target_vkgl,
                                         internalformat_vkgl,
                                         in_width,
                                         in_height);
}

void vkglRenderbufferStorage_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_target,
                                             const GLenum&  in_internalformat,
                                             const GLsizei& in_width,
                                             const GLsizei& in_height)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_internalformat,
                 in_width,
                 in_height) )
    {
        vkglRenderbufferStorage_execute(in_context_ptr,
                                        in_target,
                                        in_internalformat,
                                        in_width,
                                        in_height);
    }
}
