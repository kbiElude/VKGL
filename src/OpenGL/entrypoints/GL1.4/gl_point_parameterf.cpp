/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterf.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     const GLfloat& in_param)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glPointParameterf(GLenum  pname,
                                              GLfloat param)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointParameterf(dispatch_table_ptr->bound_context_ptr,
                                           pname,
                                           param);
}

void vkglPointParameterf_execute(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_pname,
                                 const GLfloat& in_param)
{
    const auto pname_vkgl = VKGL::Utils::get_point_property_for_gl_enum(in_pname);

    in_context_ptr->set_point_property(pname_vkgl,
                                       VKGL::GetSetArgumentType::Float,
                                      &in_param);
}

void vkglPointParameterf_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_pname,
                                         const GLfloat& in_param)
{
    if (validate(in_context_ptr,
                 in_pname,
                 in_param) )
    {
        vkglPointParameterf_execute(in_context_ptr,
                                    in_pname,
                                    in_param);
    }
}

