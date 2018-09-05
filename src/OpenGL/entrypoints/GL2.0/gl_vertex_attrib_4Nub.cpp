/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nub.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLubyte&   in_x,
                     const GLubyte&   in_y,
                     const GLubyte&   in_z,
                     const GLubyte&   in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttrib4Nub(GLuint  index,
                                                GLubyte x,
                                                GLubyte y,
                                                GLubyte z,
                                                GLubyte w)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttrib4Nub(index=[%u] x=[%u] y=[%u] z=[%u] w=[%u])",
               index,
               static_cast<uint32_t>(x),
               static_cast<uint32_t>(y),
               static_cast<uint32_t>(z),
               static_cast<uint32_t>(w) );

    dispatch_table_ptr->pGLVertexAttrib4Nub(dispatch_table_ptr->bound_context_ptr,
                                            index,
                                            x,
                                            y,
                                            z,
                                            w);
}

static void vkglVertexAttrib4Nub_execute(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_index,
                                         const GLubyte&   in_x,
                                         const GLubyte&   in_y,
                                         const GLubyte&   in_z,
                                         const GLubyte&   in_w)
{
    const GLubyte data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Unsigned_Byte,
                                         OpenGL::GetSetArgumentType::Float,
                                         4,    /* in_n_components */
                                         true, /* in_normalized   */
                                         data);
}

void OpenGL::vkglVertexAttrib4Nub_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLuint&    in_index,
                                                  const GLubyte&   in_x,
                                                  const GLubyte&   in_y,
                                                  const GLubyte&   in_z,
                                                  const GLubyte&   in_w)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z,
                 in_w) )
    {
        vkglVertexAttrib4Nub_execute(in_context_ptr,
                                     in_index,
                                     in_x,
                                     in_y,
                                     in_z,
                                     in_w);
    }
}
