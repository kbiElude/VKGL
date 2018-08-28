/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_client_wait_sync.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLsync&     in_sync,
                     const GLbitfield& in_flags,
                     const GLuint64&   in_timeout)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLenum VKGL_APIENTRY OpenGL::vkglClientWaitSync(GLsync     sync,
                                                GLbitfield flags,
                                                GLuint64   timeout)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClientWaitSync(dispatch_table_ptr->bound_context_ptr,
                                          sync,
                                          flags,
                                          timeout);
}

static GLenum vkglClientWaitSync_execute(VKGL::Context*    in_context_ptr,
                                         const GLsync&     in_sync,
                                         const GLbitfield& in_flags,
                                         const GLuint64&   in_timeout)
{
    const auto flags_vkgl = VKGL::Utils::get_wait_sync_bits_for_gl_enum(in_flags);
    const auto result     = in_context_ptr->client_wait_sync           (in_sync,
                                                                        flags_vkgl,
                                                                        in_timeout);

    return VKGL::Utils::get_gl_enum_for_wait_result(result);
}

GLenum OpenGL::vkglClientWaitSync_with_validation(VKGL::Context*    in_context_ptr,
                                                  const GLsync&     in_sync,
                                                  const GLbitfield& in_flags,
                                                  const GLuint64&   in_timeout)
{
    GLenum result = UINT32_MAX;

    if (validate(in_context_ptr,
                 in_sync,
                 in_flags,
                 in_timeout) )
    {
        vkglClientWaitSync_execute(in_context_ptr,
                                   in_sync,
                                   in_flags,
                                   in_timeout);
    }
}
