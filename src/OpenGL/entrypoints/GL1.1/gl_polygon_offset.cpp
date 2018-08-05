/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_polygon_offset.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLfloat& in_factor,
                     const GLfloat& in_units)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glPolygonOffset(GLfloat factor,
                                            GLfloat units)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPolygonOffset(dispatch_table_ptr->bound_context_ptr,
                                         factor,
                                         units);
}

void vkglPolygonOffset_execute(VKGL::Context* in_context_ptr,
                               const GLfloat& in_factor,
                               const GLfloat& in_units)
{
    in_context_ptr->set_polygon_offset(in_factor,
                                      in_units);
}

void vkglPolygonOffset_with_validation(VKGL::Context* in_context_ptr,
                                       const GLfloat& in_factor,
                                       const GLfloat& in_units)
{
    vkglPolygonOffset_execute(in_context_ptr,
                              in_factor,
                              in_units);
}