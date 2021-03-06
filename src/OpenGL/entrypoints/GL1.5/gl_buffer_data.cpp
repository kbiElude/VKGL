/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_buffer_data.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context*  in_context_ptr,
                     const GLenum&     in_target,
                     const GLsizeiptr& in_size,
                     const void*       in_data,
                     const GLenum&     in_usage)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBufferData(GLenum      target,
                                          GLsizeiptr  size,
                                          const void* data,
                                          GLenum      usage)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBufferData(target=[%s] size=[%d] data=[%p] usage=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               static_cast<uint32_t>(size),
               data,
               OpenGL::Utils::get_raw_string_for_gl_enum(usage) );

    dispatch_table_ptr->pGLBufferData(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      size,
                                      data,
                                      usage);
}

static void vkglBufferData_execute(OpenGL::Context*  in_context_ptr,
                                   const GLenum&     in_target,
                                   const GLsizeiptr& in_size,
                                   const void*       in_data,
                                   const GLenum&     in_usage)
{
    const auto target_vkgl = OpenGL::Utils::get_buffer_target_for_gl_enum(in_target);
    const auto usage_vkgl  = OpenGL::Utils::get_buffer_usage_for_gl_enum (in_usage);

    in_context_ptr->buffer_data(target_vkgl,
                                in_size,
                                in_data,
                                usage_vkgl);
}

void OpenGL::vkglBufferData_with_validation(OpenGL::Context*  in_context_ptr,
                                            const GLenum&     in_target,
                                            const GLsizeiptr& in_size,
                                            const void*       in_data,
                                            const GLenum&     in_usage)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_size,
                 in_data,
                 in_usage) )
    {
        vkglBufferData_execute(in_context_ptr,
                               in_target,
                               in_size,
                               in_data,
                               in_usage);
    }
}
