/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_viewport.h"
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


void VKGL_APIENTRY OpenGL::vkglViewport(GLint   x,
                                        GLint   y,
                                        GLsizei width,
                                        GLsizei height)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLViewport(dispatch_table_ptr->bound_context_ptr,
                                    x,
                                    y,
                                    width,
                                    height);
}

static void vkglViewport_execute(OpenGL::Context* in_context_ptr,
                                 const GLint&     in_x,
                                 const GLint&     in_y,
                                 const GLsizei&   in_width,
                                 const GLsizei&   in_height)
{
    in_context_ptr->set_viewport(in_x,
                                 in_y,
                                 in_width,
                                 in_height);
}

void OpenGL::vkglViewport_with_validation(OpenGL::Context* in_context_ptr,
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
        vkglViewport_execute(in_context_ptr,
                             in_x,
                             in_y,
                             in_width,
                             in_height);
    }

}