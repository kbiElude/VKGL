/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_unmap_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglUnmapBuffer(GLenum target)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLUnmapBuffer(dispatch_table_ptr->bound_context_ptr,
                                              target) ? GL_TRUE
                                                      : GL_FALSE;
}

static bool vkglUnmapBuffer_execute(OpenGL::Context* in_context_ptr,
                                    const GLenum&    in_target)
{
    const auto target_vkgl = OpenGL::Utils::get_buffer_target_for_gl_enum(in_target);

    return in_context_ptr->unmap_buffer(target_vkgl);
}

bool OpenGL::vkglUnmapBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_target)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_target) )
    {
        result = vkglUnmapBuffer_execute(in_context_ptr,
                                         in_target);
    }

    return result;
}

