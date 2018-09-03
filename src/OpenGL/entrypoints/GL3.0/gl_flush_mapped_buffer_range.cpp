/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_flush_mapped_buffer_range.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context*  in_context_ptr,
                     const GLenum&     in_target,
                     const GLintptr&   in_offset,
                     const GLsizeiptr& in_length)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglFlushMappedBufferRange(GLenum     target,
                                                      GLintptr   offset,
                                                      GLsizeiptr length)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFlushMappedBufferRange(dispatch_table_ptr->bound_context_ptr,
                                                  target,
                                                  offset,
                                                  length);
}

static void vkglFlushMappedBufferRange_execute(OpenGL::Context*  in_context_ptr,
                                               const GLenum&     in_target,
                                               const GLintptr&   in_offset,
                                               const GLsizeiptr& in_length)
{
    const auto target_vkgl = OpenGL::Utils::get_buffer_target_for_gl_enum(in_target);

    in_context_ptr->flush_mapped_buffer_range(target_vkgl,
                                              in_offset,
                                              in_length);
}

void OpenGL::vkglFlushMappedBufferRange_with_validation(OpenGL::Context*  in_context_ptr,
                                                        const GLenum&     in_target,
                                                        const GLintptr&   in_offset,
                                                        const GLsizeiptr& in_length)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_offset,
                 in_length) )
    {
        vkglFlushMappedBufferRange_execute(in_context_ptr,
                                           in_target,
                                           in_offset,
                                           in_length);
    }
}
