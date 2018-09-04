/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fi.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_buffer,
                     const GLint&     in_drawbuffer,
                     const GLfloat&   in_depth,
                     const GLint&     in_stencil)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglClearBufferfi(GLenum  buffer,
                                             GLint   drawbuffer,
                                             GLfloat depth,
                                             GLint   stencil)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glClearBufferfi(buffer=[%s] drawbuffer=[%d] depth=[%.4f] stencil=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(buffer),
               drawbuffer,
               depth,
               stencil);

    dispatch_table_ptr->pGLClearBufferfi(dispatch_table_ptr->bound_context_ptr,
                                         buffer,
                                         drawbuffer,
                                         depth,
                                         stencil);
}

static void vkglClearBufferfi_execute(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_buffer,
                                      const GLint&     in_drawbuffer,
                                      const GLfloat&   in_depth,
                                      const GLint&     in_stencil)
{
    const auto buffer_vkgl = OpenGL::Utils::get_clear_buffer_for_gl_enum(in_buffer);

    in_context_ptr->clear_buffer(buffer_vkgl,
                                 in_drawbuffer,
                                 OpenGL::GetSetArgumentType::Unknown,
                                 0,
                                 nullptr,
                                 in_depth,
                                 in_stencil);
}

void OpenGL::vkglClearBufferfi_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_buffer,
                                               const GLint&     in_drawbuffer,
                                               const GLfloat&   in_depth,
                                               const GLint&     in_stencil)
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
