/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_tex_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_internalformat,
                     const GLuint&  in_buffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glTexBuffer(GLenum target,
                                        GLenum internalformat,
                                        GLuint buffer)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexBuffer(dispatch_table_ptr->bound_context_ptr,
                                     target,
                                     internalformat,
                                     buffer);
}

void vkglTexBuffer_execute(VKGL::Context* in_context_ptr,
                           const GLenum&  in_target,
                           const GLenum&  in_internalformat,
                           const GLuint&  in_buffer)
{
    const auto internalformat_vkgl = VKGL::Utils::get_internal_format_for_gl_enum(in_internalformat);

    vkgl_assert(in_target == GL_TEXTURE_BUFFER);

    in_context_ptr->tex_buffer(internalformat_vkgl,
                               in_buffer);
}

void vkglTexBuffer_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_target,
                                   const GLenum&  in_internalformat,
                                   const GLuint&  in_buffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_internalformat,
                 in_buffer) )
    {
        vkglTexBuffer_execute(in_context_ptr,
                              in_target,
                              in_internalformat,
                              in_buffer);
    }
}
