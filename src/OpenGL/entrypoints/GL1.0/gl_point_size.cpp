/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_point_size.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLfloat& in_size)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY vkglPointSize(GLfloat size)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointSize(dispatch_table_ptr->bound_context_ptr,
                                     size);
}

void vkglPointSize_execute(VKGL::Context* in_context_ptr,
                           const GLfloat& in_size)
{
    in_context_ptr->set_point_size(in_size);
}

void vkglPointSize_with_validation(VKGL::Context* in_context_ptr,
                                   const GLfloat& in_size)
{
    if (validate(in_context_ptr,
                 in_size) )
    {
        vkglPointSize_execute(in_context_ptr,
                              in_size);
    }
}