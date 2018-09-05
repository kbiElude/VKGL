/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_integerv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_pname,
                     GLint*           out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglGetIntegerv(GLenum pname,
                                           GLint* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetIntegerv(pname=[%s] data=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               data);

    dispatch_table_ptr->pGLGetIntegerv(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       data);
}

static void vkglGetIntegerv_execute(OpenGL::Context* in_context_ptr,
                                    const GLenum&    in_pname,
                                    GLint*           out_data_ptr)
{
    const auto pname_vkgl = OpenGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_parameter(pname_vkgl,
                                  OpenGL::GetSetArgumentType::Int,
                                  out_data_ptr);
}

void OpenGL::vkglGetIntegerv_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_pname,
                                             GLint*           out_data_ptr)
{
    if (validate(in_context_ptr,
                 in_pname,
                 out_data_ptr) )
    {
        vkglGetIntegerv_execute(in_context_ptr,
                                in_pname,
                                out_data_ptr);
    }
}