/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_wait_sync.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context*  in_context_ptr,
                     const GLsync&     in_sync,
                     const GLbitfield& in_flags,
                     const GLuint64&   in_timeout)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglWaitSync(GLsync     sync,
                                        GLbitfield flags,
                                        GLuint64   timeout)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLWaitSync(dispatch_table_ptr->bound_context_ptr,
                                    sync,
                                    flags,
                                    timeout);
}

static void vkglWaitSync_execute(OpenGL::Context*  in_context_ptr,
                                 const GLsync&     in_sync,
                                 const GLbitfield& in_flags,
                                 const GLuint64&   in_timeout)
{
    vkgl_assert(in_flags == 0);

    in_context_ptr->wait_sync(in_sync,
                              in_timeout);
}

void OpenGL::vkglWaitSync_with_validation(OpenGL::Context*  in_context_ptr,
                                          const GLsync&     in_sync,
                                          const GLbitfield& in_flags,
                                          const GLuint64&   in_timeout)
{
    if (validate(in_context_ptr,
                 in_sync,
                 in_flags,
                 in_timeout) )
    {
        vkglWaitSync_execute(in_context_ptr,
                             in_sync,
                             in_flags,
                             in_timeout);
    }
}
