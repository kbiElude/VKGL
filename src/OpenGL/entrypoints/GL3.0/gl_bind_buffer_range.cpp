/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_bind_buffer_range.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLenum&     in_target,
                     const GLuint&     in_index,
                     const GLuint&     in_buffer,
                     const GLintptr&   in_offset,
                     const GLsizeiptr& in_size)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglBindBufferRange(GLenum     target,
                                       GLuint     index,
                                       GLuint     buffer,
                                       GLintptr   offset,
                                       GLsizeiptr size)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindBufferRange(dispatch_table_ptr->bound_context_ptr,
                                           target,
                                           index,
                                           buffer,
                                           offset,
                                           size);
}

void vkglBindBufferRange_execute(VKGL::Context*    in_context_ptr,
                                 const GLenum&     in_target,
                                 const GLuint&     in_index,
                                 const GLuint&     in_buffer,
                                 const GLintptr&   in_offset,
                                 const GLsizeiptr& in_size)
{
    const auto target_vkgl = VKGL::Utils::get_buffer_target_for_gl_enum(in_target);

    in_context_ptr->bind_buffer_range(target_vkgl,
                                      in_index,
                                      in_buffer,
                                      in_offset,
                                      in_size);
}

void vkglBindBufferRange_with_validation(VKGL::Context*    in_context_ptr,
                                         const GLenum&     in_target,
                                         const GLuint&     in_index,
                                         const GLuint&     in_buffer,
                                         const GLintptr&   in_offset,
                                         const GLsizeiptr& in_size)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_index,
                 in_buffer,
                 in_offset,
                 in_size) )
    {
        vkglBindBufferRange_execute(in_context_ptr,
                                    in_target,
                                    in_index,
                                    in_buffer,
                                    in_offset,
                                    in_size);
    }
}
