/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3s.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLshort&   in_x,
                     const GLshort&   in_y,
                     const GLshort&   in_z)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib3s(GLuint  index,
                                              GLshort x,
                                              GLshort y,
                                              GLshort z)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttrib3s(index=[%u] x=[%d] y=[%d] z=[%d])",
               index,
               static_cast<int32_t>(x),
               static_cast<int32_t>(y),
               static_cast<int32_t>(z) );

    dispatch_table_ptr->pGLVertexAttrib3s(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z);
}

static void vkglVertexAttrib3s_execute(OpenGL::Context* in_context_ptr,
                                       const GLuint&    in_index,
                                       const GLshort&   in_x,
                                       const GLshort&   in_y,
                                       const GLshort&   in_z)
{
    const GLshort data[] =
    {
        in_x,
        in_y,
        in_z
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Short,
                                         OpenGL::GetSetArgumentType::Float,
                                         3,     /* in_n_components */
                                         false, /* in_normalized   */
                                         data);
}

void OpenGL::vkglVertexAttrib3s_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_index,
                                                const GLshort&   in_x,
                                                const GLshort&   in_y,
                                                const GLshort&   in_z)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z) )
    {
        vkglVertexAttrib3s_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y,
                                   in_z);
    }
}
