/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_clear_color.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLfloat&   in_red,
                     const GLfloat&   in_green,
                     const GLfloat&   in_blue,
                     const GLfloat&   in_alpha)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglClearColor(GLfloat red,
                                          GLfloat green,
                                          GLfloat blue,
                                          GLfloat alpha)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glClearColor(red=[%.4f] green=[%.4f] blue=[%.4f] alpha=[%.4f])",
               red,
               green,
               blue,
               alpha);

    dispatch_table_ptr->pGLClearColor(dispatch_table_ptr->bound_context_ptr,
                                      red,
                                      green,
                                      blue,
                                      alpha);
}

static void vkglClearColor_execute(OpenGL::Context* in_context_ptr,
                                   const GLfloat&   in_red,
                                   const GLfloat&   in_green,
                                   const GLfloat&   in_blue,
                                   const GLfloat&   in_alpha)
{
    in_context_ptr->set_clear_color_value(in_red,
                                          in_green,
                                          in_blue,
                                          in_alpha);
}

void OpenGL::vkglClearColor_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLfloat&   in_red,
                                            const GLfloat&   in_green,
                                            const GLfloat&   in_blue,
                                            const GLfloat&   in_alpha)
{
    if (validate(in_context_ptr,
                 in_red,
                 in_green,
                 in_blue,
                 in_alpha) )
    {
        vkglClearColor_execute(in_context_ptr,
                               in_red,
                               in_green,
                               in_blue,
                               in_alpha);
    }
}