/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4ubv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLubyte* in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttribI4ubv(GLuint         index,
                                                const GLubyte* v)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribI4ubv(dispatch_table_ptr->bound_context_ptr,
                                             index,
                                             v);
}

void vkglVertexAttribI4ubv_execute(VKGL::Context* in_context_ptr,
                                   const GLuint&  in_index,
                                   const GLubyte* in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Unsigned_Byte,
                                         VKGL::GetSetArgumentType::Unsigned_Int,
                                         4,
                                         false, /* in_normalized */
                                         in_v_ptr);
}

void vkglVertexAttribI4ubv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_index,
                                           const GLubyte* in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttribI4ubv_execute(in_context_ptr,
                                      in_index,
                                      in_v_ptr);
    }
}
