/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_viewport.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_x,
                     const GLint&   in_y,
                     const GLsizei& in_width,
                     const GLsizei& in_height)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY vkglViewport(GLint   x,
                                         GLint   y,
                                         GLsizei width,
                                         GLsizei height)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLViewport(dispatch_table_ptr->bound_context_ptr,
                                    x,
                                    y,
                                    width,
                                    height);
}

void vkglViewport_execute(VKGL::Context* in_context_ptr,
                          const GLint&   in_x,
                          const GLint&   in_y,
                          const GLsizei& in_width,
                          const GLsizei& in_height)
{
    in_context_ptr->set_viewport(in_x,
                                 in_y,
                                 in_width,
                                 in_height);
}

void vkglViewport_with_validation(VKGL::Context* in_context_ptr,
                                  const GLint&   in_x,
                                  const GLint&   in_y,
                                  const GLsizei& in_width,
                                  const GLsizei& in_height)
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