/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribdv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLenum&    in_pname,
                     GLdouble*        out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetVertexAttribdv(GLuint    index,
                                                 GLenum    pname,
                                                 GLdouble* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetVertexAttribdv(dispatch_table_ptr->bound_context_ptr,
                                             index,
                                             pname,
                                             params);
}

static void vkglGetVertexAttribdv_execute(OpenGL::Context* in_context_ptr,
                                          const GLuint&    in_index,
                                          const GLenum&    in_pname,
                                          GLdouble*        out_params_ptr)
{
    const auto pname_vkgl = OpenGL::Utils::get_vertex_attribute_property_for_gl_enum(in_pname);

    in_context_ptr->get_vertex_attribute_property(in_index,
                                                  pname_vkgl,
                                                  OpenGL::GetSetArgumentType::Float,
                                                  OpenGL::GetSetArgumentType::Double,
                                                  out_params_ptr);
}

void OpenGL::vkglGetVertexAttribdv_with_validation(OpenGL::Context* in_context_ptr,
                                                   const GLuint&    in_index,
                                                   const GLenum&    in_pname,
                                                   GLdouble*        out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetVertexAttribdv_execute(in_context_ptr,
                                      in_index,
                                      in_pname,
                                      out_params_ptr);
    }
}
