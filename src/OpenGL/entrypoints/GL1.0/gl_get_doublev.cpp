/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_doublev.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     GLdouble*      out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void vkglGetDoublev_execute(VKGL::Context* in_context_ptr,
                            const GLenum&  in_pname,
                            GLdouble*      out_data_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_parameter(pname_vkgl,
                                  VKGL::GetSetArgumentType::Double,
                                  out_data_ptr);
}

void vkglGetDoublev_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_pname,
                                    GLdouble*      out_data_ptr)
{
    if (validate(in_context_ptr,
                 in_pname,
                 out_data_ptr) )
    {
        vkglGetDoublev_execute(in_context_ptr,
                               in_pname,
                               out_data_ptr);
    }
}

VKGL_API void VKGL_APIENTRY vkglGetDoublev(GLenum    pname,
                                           GLdouble* data)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetDoublev(dispatch_table_ptr->bound_context_ptr,
                                      pname,
                                      data);
}