/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_get_synciv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     GLsync           in_sync,
                     GLenum           in_pname,
                     GLsizei          in_buf_size,
                     GLsizei*         inout_length_ptr,
                     GLint*           out_values_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetSynciv(GLsync   sync,
                                         GLenum   pname,
                                         GLsizei  bufSize,
                                         GLsizei* length,
                                         GLint*   values)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetSynciv(dispatch_table_ptr->bound_context_ptr,
                                     sync,
                                     pname,
                                     bufSize,
                                     length,
                                     values);
}

static void vkglGetSynciv_execute(OpenGL::Context* in_context_ptr,
                                  GLsync           in_sync,
                                  GLenum           in_pname,
                                  GLsizei          in_buf_size,
                                  GLsizei*         inout_length_ptr,
                                  GLint*           out_values_ptr)
{
    const auto pname_vkgl = OpenGL::Utils::get_sync_property_for_gl_enum(in_pname);

    in_context_ptr->get_synciv(in_sync,
                               in_pname,
                               in_buf_size,
                               inout_length_ptr,
                               out_values_ptr);
}

void OpenGL::vkglGetSynciv_with_validation(OpenGL::Context* in_context_ptr,
                                           GLsync           in_sync,
                                           GLenum           in_pname,
                                           GLsizei          in_buf_size,
                                           GLsizei*         inout_length_ptr,
                                           GLint*           out_values_ptr)
{
    if (validate(in_context_ptr,
                 in_sync,
                 in_pname,
                 in_buf_size,
                 inout_length_ptr,
                 out_values_ptr) )
    {
        vkglGetSynciv_execute(in_context_ptr,
                              in_sync,
                              in_pname,
                              in_buf_size,
                              inout_length_ptr,
                              out_values_ptr);
    }
}
