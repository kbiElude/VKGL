/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_map_buffer_range.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context*  in_context_ptr,
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

    VKGL_TRACE("glMapBufferRange(target=[%s] offset=[%d] length=[%d] access=[%s])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               static_cast<int32_t>(offset),
               static_cast<int32_t>(length),
               OpenGL::Utils::get_raw_string_for_gl_bitfield(OpenGL::BitfieldType::Buffer_Access_Mask, access) );

    return dispatch_table_ptr->pGLMapBufferRange(dispatch_table_ptr->bound_context_ptr,
                                                 target,
                                                 offset,
                                                 length,
                                                 access);
}

static void* vkglMapBufferRange_execute(OpenGL::Context*  in_context_ptr,
                                        const GLenum&     in_target,
                                        const GLintptr&   in_offset,
                                        const GLsizeiptr& in_length,
                                        const GLbitfield& in_access)
{
    const auto access_vkgl = OpenGL::Utils::get_buffer_access_for_gl_enum(in_access);
    const auto target_vkgl = OpenGL::Utils::get_buffer_target_for_gl_enum(in_target);

    return in_context_ptr->map_buffer_range(target_vkgl,
                                            in_offset,
                                            in_length,
                                            access_vkgl);
}

void* OpenGL::vkglMapBufferRange_with_validation(OpenGL::Context*  in_context_ptr,
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
