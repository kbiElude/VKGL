/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_floatv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     GLfloat*       out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglGetFloatv(GLenum   pname,
                                 GLfloat* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetFloatv(dispatch_table_ptr->bound_context_ptr,
                                     pname,
                                     data);
}

void vkglGetFloatv_execute(VKGL::Context* in_context_ptr,
                           const GLenum&  in_pname,
                           GLfloat*       out_data_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_parameter(pname_vkgl,
                                  VKGL::GetSetArgumentType::Float,
                                  out_data_ptr);
}

void vkglGetFloatv_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_pname,
                                   GLfloat*       out_data_ptr)
{
    if (validate(in_context_ptr,
                 in_pname,
                 out_data_ptr) )
    {
        vkglGetFloatv_execute(in_context_ptr,
                              in_pname,
                              out_data_ptr);
    }
}