/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2s.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLshort& in_x,
                     const GLshort& in_y)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib2s(GLuint  index,
                                              GLshort x,
                                              GLshort y)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib2s(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y);
}

static void vkglVertexAttrib2s_execute(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_index,
                                       const GLshort& in_x,
                                       const GLshort& in_y)
{
    const GLshort data[] =
    {
        in_x,
        in_y
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Short,
                                         VKGL::GetSetArgumentType::Float,
                                         2,
                                         false, /* in_normalized */
                                         data);
}

void OpenGL::vkglVertexAttrib2s_with_validation(VKGL::Context* in_context_ptr,
                                                const GLuint&  in_index,
                                                const GLshort& in_x,
                                                const GLshort& in_y)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y) )
    {
        vkglVertexAttrib2s_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y);
    }
}
