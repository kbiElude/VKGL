/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_vertex_attrib_i_iv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLenum&    in_pname,
                     GLint*           out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetVertexAttribIiv(GLuint index,
                                                  GLenum pname,
                                                  GLint* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetVertexAttribIiv(index=[%u] pname=[%s] params=[%p])",
               index,
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               params);

    dispatch_table_ptr->pGLGetVertexAttribIiv(dispatch_table_ptr->bound_context_ptr,
                                              index,
                                              pname,
                                              params);
}

static void vkglGetVertexAttribIiv_execute(OpenGL::Context* in_context_ptr,
                                           const GLuint&    in_index,
                                           const GLenum&    in_pname,
                                           GLint*           out_params_ptr)
{
    const auto pname_vkgl = OpenGL::Utils::get_vertex_attribute_property_for_gl_enum(in_pname);

    in_context_ptr->get_vertex_attribute_property(in_index,
                                                  pname_vkgl,
                                                  OpenGL::GetSetArgumentType::Int,
                                                  OpenGL::GetSetArgumentType::Int,
                                                  out_params_ptr);
}

void OpenGL::vkglGetVertexAttribIiv_with_validation(OpenGL::Context* in_context_ptr,
                                                    const GLuint&    in_index,
                                                    const GLenum&    in_pname,
                                                    GLint*           out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetVertexAttribIiv_execute(in_context_ptr,
                                       in_index,
                                       in_pname,
                                       out_params_ptr);
    }
}
