/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_get_integer64v.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_pname,
                     GLint64*         out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetInteger64v(GLenum   pname,
                                             GLint64* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetInteger64v(dispatch_table_ptr->bound_context_ptr,
                                         pname,
                                         data);
}

static void vkglGetInteger64v_execute(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_pname,
                                      GLint64*         out_data_ptr)
{
    const auto pname_vkgl = OpenGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_parameter(pname_vkgl,
                                  OpenGL::GetSetArgumentType::Int64,
                                  out_data_ptr);
}

void OpenGL::vkglGetInteger64v_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_pname,
                                               GLint64*         out_data_ptr)
{
    if (validate(in_context_ptr,
                 in_pname,
                 out_data_ptr) )
    {
        vkglGetInteger64v_execute(in_context_ptr,
                                  in_pname,
                                  out_data_ptr);
    }
}
