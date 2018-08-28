/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_line_width.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLfloat& in_width)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglLineWidth(GLfloat width)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLLineWidth(dispatch_table_ptr->bound_context_ptr,
                                     width);
}

static void vkglLineWidth_execute(VKGL::Context* in_context_ptr,
                                  const GLfloat& in_width)
{
    in_context_ptr->set_line_width(in_width);
}

void OpenGL::vkglLineWidth_with_validation(VKGL::Context* in_context_ptr,
                                           const GLfloat& in_width)
{
    if (validate(in_context_ptr,
                 in_width) )
    {
        vkglLineWidth_execute(in_context_ptr,
                              in_width);
    }
}