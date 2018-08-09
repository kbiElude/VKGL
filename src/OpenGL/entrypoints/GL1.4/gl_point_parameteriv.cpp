/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_point_parameteriv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     const GLint*   in_params)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glPointParameteriv(GLenum       pname,
                                               const GLint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointParameteriv(dispatch_table_ptr->bound_context_ptr,
                                            pname,
                                            params);
}

void vkglPointParameteriv_execute(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_pname,
                                  const GLint*   in_params)
{
    const auto pname_vkgl = VKGL::Utils::get_point_property_for_gl_enum(in_pname);

    in_context_ptr->set_point_property(pname_vkgl,
                                       VKGL::GetSetArgumentType::Int,
                                       in_params);
}

void vkglPointParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLenum&  in_pname,
                                          const GLint*   in_params)
{
    if (validate(in_context_ptr,
                 in_pname,
                 in_params) )
    {
        vkglPointParameteriv_execute(in_context_ptr,
                                     in_pname,
                                     in_params);
    }
}

