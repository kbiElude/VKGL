/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_get_query_objectuiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_id,
                     const GLenum&  in_pname,
                     const GLuint*  out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGetQueryObjectuiv(GLuint  id,
                                         GLenum  pname,
                                         GLuint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetQueryObjectuiv(dispatch_table_ptr->bound_context_ptr,
                                             id,
                                             pname,
                                             params);
}

void vkglGetQueryObjectuiv_execute(VKGL::Context* in_context_ptr,
                                   const GLuint&  in_id,
                                   const GLenum&  in_pname,
                                   GLuint*        out_params_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_query_property_for_gl_enum(in_pname);

    in_context_ptr->get_query_property(in_id,
                                       pname_vkgl,
                                       VKGL::GetSetArgumentType::Unsigned_Int,
                                       1,
                                       out_params_ptr);
}

void vkglGetQueryObjectuiv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLuint&  in_id,
                                           const GLenum&  in_pname,
                                           GLuint*        out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_id,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetQueryObjectuiv_execute(in_context_ptr,
                                      in_id,
                                      in_pname,
                                      out_params_ptr);
    }
}

