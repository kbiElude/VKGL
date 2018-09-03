/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_bind_buffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLuint&    in_buffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBindBuffer(GLenum target,
                                          GLuint buffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindBuffer(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      buffer);
}

static void vkglBindBuffer_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_target,
                                   const GLuint&    in_buffer)
{
    const auto target_vkgl = OpenGL::Utils::get_buffer_target_for_gl_enum(in_target);

    in_context_ptr->bind_buffer(target_vkgl,
                                in_buffer);
}

void OpenGL::vkglBindBuffer_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_target,
                                            const GLuint&    in_buffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_buffer) )
    {
        vkglBindBuffer_execute(in_context_ptr,
                               in_target,
                               in_buffer);
    }
}


