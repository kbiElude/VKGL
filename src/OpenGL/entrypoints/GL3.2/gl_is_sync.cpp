/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_is_sync.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLsync&    in_sync)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


GLboolean VKGL_APIENTRY OpenGL::vkglIsSync(GLsync sync)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glIsSync(sync=[%p])",
               sync);

    return dispatch_table_ptr->pGLIsSync(dispatch_table_ptr->bound_context_ptr,
                                         sync) ? GL_TRUE : GL_FALSE;
}

static GLboolean vkglIsSync_execute(OpenGL::Context* in_context_ptr,
                                    const GLsync&    in_sync)
{
    return in_context_ptr->is_sync(in_sync) ? GL_TRUE : GL_FALSE;
}

GLboolean OpenGL::vkglIsSync_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLsync&    in_sync)
{
    GLboolean result = GL_FALSE;

    if (validate(in_context_ptr,
                 in_sync) )
    {
        result = vkglIsSync_execute(in_context_ptr,
                                    in_sync);
    }

    return result;
}
