/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_blend_color.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLfloat& in_red,
                     const GLfloat& in_green,
                     const GLfloat& in_blue,
                     const GLfloat& in_alpha)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glBlendColor(GLfloat red,
                                         GLfloat green,
                                         GLfloat blue,
                                         GLfloat alpha)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBlendColor(dispatch_table_ptr->bound_context_ptr,
                                      red,
                                      green,
                                      blue,
                                      alpha);
}

void vkglBlendColor_execute(VKGL::Context* in_context_ptr,
                            const GLfloat& in_red,
                            const GLfloat& in_green,
                            const GLfloat& in_blue,
                            const GLfloat& in_alpha)
{
    in_context_ptr->set_blend_color(in_red,
                                    in_green,
                                    in_blue,
                                    in_alpha);
}

void vkglBlendColor_with_validation(VKGL::Context* in_context_ptr,
                                    const GLfloat& in_red,
                                    const GLfloat& in_green,
                                    const GLfloat& in_blue,
                                    const GLfloat& in_alpha)
{
    if (validate(in_context_ptr,
                 in_red,
                 in_green,
                 in_blue,
                 in_alpha) )
    {
        vkglBlendColor_execute(in_context_ptr,
                               in_red,
                               in_green,
                               in_blue,
                               in_alpha);
    }
}
