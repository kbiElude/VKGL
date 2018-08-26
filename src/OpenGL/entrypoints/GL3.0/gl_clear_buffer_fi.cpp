/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fi.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_buffer,
                     const GLint&   in_drawbuffer,
                     const GLfloat& in_depth,
                     const GLint&   in_stencil)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglClearBufferfi(GLenum  buffer,
                                     GLint   drawbuffer,
                                     GLfloat depth,
                                     GLint   stencil)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClearBufferfi(dispatch_table_ptr->bound_context_ptr,
                                         buffer,
                                         drawbuffer,
                                         depth,
                                         stencil);
}

void vkglClearBufferfi_execute(VKGL::Context* in_context_ptr,
                               const GLenum&  in_buffer,
                               const GLint&   in_drawbuffer,
                               const GLfloat& in_depth,
                               const GLint&   in_stencil)
{
    const auto buffer_vkgl = VKGL::Utils::get_clear_buffer_for_gl_enum(in_buffer);

    in_context_ptr->clear_buffer(buffer_vkgl,
                                 in_drawbuffer,
                                 VKGL::GetSetArgumentType::Unknown,
                                 0,
                                 nullptr,
                                 in_depth,
                                 in_stencil);
}

void vkglClearBufferfi_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_buffer,
                                       const GLint&   in_drawbuffer,
                                       const GLfloat& in_depth,
                                       const GLint&   in_stencil)
{
    if (validate(in_context_ptr,
                 in_buffer,
                 in_drawbuffer,
                 in_depth,
                 in_stencil) )
    {
        vkglClearBufferfi_execute(in_context_ptr,
                                  in_buffer,
                                  in_drawbuffer,
                                  in_depth,
                                  in_stencil);
    }
}
