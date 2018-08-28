/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_map_buffer_range.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLenum&     in_target,
                     const GLintptr&   in_offset,
                     const GLsizeiptr& in_length,
                     const GLbitfield& in_access)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void* APIENTRY OpenGL::vkglMapBufferRange(GLenum     target,
                                          GLintptr   offset,
                                          GLsizeiptr length,
                                          GLbitfield access)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLMapBufferRange(dispatch_table_ptr->bound_context_ptr,
                                                 target,
                                                 offset,
                                                 length,
                                                 access);
}

static void* vkglMapBufferRange_execute(VKGL::Context*    in_context_ptr,
                                        const GLenum&     in_target,
                                        const GLintptr&   in_offset,
                                        const GLsizeiptr& in_length,
                                        const GLbitfield& in_access)
{
    const auto access_vkgl = VKGL::Utils::get_buffer_access_for_gl_enum(in_access);
    const auto target_vkgl = VKGL::Utils::get_buffer_target_for_gl_enum(in_target);

    return in_context_ptr->map_buffer_range(target_vkgl,
                                            in_offset,
                                            in_length,
                                            access_vkgl);
}

void* OpenGL::vkglMapBufferRange_with_validation(VKGL::Context*    in_context_ptr,
                                                 const GLenum&     in_target,
                                                 const GLintptr&   in_offset,
                                                 const GLsizeiptr& in_length,
                                                 const GLbitfield& in_access)
{
    void* result = nullptr;

    if (validate(in_context_ptr,
                 in_target,
                 in_offset,
                 in_length,
                 in_access) )
    {
        result = vkglMapBufferRange_execute(in_context_ptr,
                                            in_target,
                                            in_offset,
                                            in_length,
                                            in_access);
    }

    return result;
}
