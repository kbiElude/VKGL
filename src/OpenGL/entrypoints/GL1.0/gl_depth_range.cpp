/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_depth_range.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*  in_context_ptr,
                     const GLdouble& in_n,
                     const GLdouble& in_f)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglDepthRange(GLdouble n,
                                          GLdouble f)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDepthRange(dispatch_table_ptr->bound_context_ptr,
                                      n,
                                      f);
}

static void vkglDepthRange_execute(VKGL::Context*  in_context_ptr,
                                   const GLdouble& in_n,
                                   const GLdouble& in_f)
{
    in_context_ptr->set_depth_range(in_n,
                                    in_f);
}

void OpenGL::vkglDepthRange_with_validation(VKGL::Context*  in_context_ptr,
                                            const GLdouble& in_n,
                                            const GLdouble& in_f)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_f) )
    {
        vkglDepthRange_execute(in_context_ptr,
                               in_n,
                               in_f);
    }
}