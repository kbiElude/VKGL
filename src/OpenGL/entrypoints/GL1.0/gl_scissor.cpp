/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_scissor.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_x,
                     const GLint&     in_y,
                     const GLsizei&   in_width,
                     const GLsizei&   in_height)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglScissor(GLint   x,
                                       GLint   y,
                                       GLsizei width,
                                       GLsizei height)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLScissor(dispatch_table_ptr->bound_context_ptr,
                                   x,
                                   y,
                                   width,
                                   height);
}

static void vkglScissor_execute(OpenGL::Context* in_context_ptr,
                                const GLint&     in_x,
                                const GLint&     in_y,
                                const GLsizei&   in_width,
                                const GLsizei&   in_height)
{
    in_context_ptr->set_scissor(in_x,
                                in_y,
                                in_width,
                                in_height);
}

void OpenGL::vkglScissor_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLint&     in_x,
                                         const GLint&     in_y,
                                         const GLsizei&   in_width,
                                         const GLsizei&   in_height)
{
    if (validate(in_context_ptr,
                 in_x,
                 in_y,
                 in_width,
                 in_height) )
    {
        vkglScissor_execute(in_context_ptr,
                            in_x,
                            in_y,
                            in_width,
                            in_height);
    }
}