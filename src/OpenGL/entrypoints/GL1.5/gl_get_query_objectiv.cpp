/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_get_query_objectiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_id,
                     const GLenum&  in_pname,
                     const GLint*   out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGetQueryObjectiv(GLuint id,
                                        GLenum pname,
                                        GLint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetQueryObjectiv(dispatch_table_ptr->bound_context_ptr,
                                            id,
                                            pname,
                                            params);
}

void vkglGetQueryObjectiv_execute(VKGL::Context* in_context_ptr,
                                  const GLuint&  in_id,
                                  const GLenum&  in_pname,
                                  GLint*         out_params_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_query_property_for_gl_enum(in_pname);

    in_context_ptr->get_query_property(in_id,
                                       pname_vkgl,
                                       VKGL::GetSetArgumentType::Int,
                                       1,
                                       out_params_ptr);
}

void vkglGetQueryObjectiv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLuint&  in_id,
                                          const GLenum&  in_pname,
                                          GLint*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_id,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetQueryObjectiv_execute(in_context_ptr,
                                     in_id,
                                     in_pname,
                                     out_params_ptr);
    }
}

