/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_point_size.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLfloat&   in_size)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglPointSize(GLfloat size)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointSize(dispatch_table_ptr->bound_context_ptr,
                                     size);
}

static void vkglPointSize_execute(OpenGL::Context* in_context_ptr,
                                  const GLfloat&   in_size)
{
    in_context_ptr->set_point_size(in_size);
}

void OpenGL::vkglPointSize_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLfloat&   in_size)
{
    if (validate(in_context_ptr,
                 in_size) )
    {
        vkglPointSize_execute(in_context_ptr,
                              in_size);
    }
}