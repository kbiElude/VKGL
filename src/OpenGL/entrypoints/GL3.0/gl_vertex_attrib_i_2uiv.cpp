/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2uiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLuint*    in_v_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribI2uiv(GLuint        index,
                                                 const GLuint* v)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glVertexAttribI2uiv(index=[%u] v=[%p])",
               index,
               v);

    dispatch_table_ptr->pGLVertexAttribI2uiv(dispatch_table_ptr->bound_context_ptr,
                                             index,
                                             v);
}

static void vkglVertexAttribI2uiv_execute(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_index,
                                          const GLuint*    in_v_ptr)
{
    in_context_ptr->set_vertex_attribute(in_index,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         OpenGL::GetSetArgumentType::Unsigned_Int,
                                         2,     /* in_n_components */
                                         false, /* in_normalized   */
                                         in_v_ptr);
}

void OpenGL::vkglVertexAttribI2uiv_with_validation(OpenGL::Context* in_context_ptr,
                                                   const GLuint&    in_index,
                                                   const GLuint*    in_v_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_v_ptr) )
    {
        vkglVertexAttribI2uiv_execute(in_context_ptr,
                                      in_index,
                                      in_v_ptr);
    }
}
