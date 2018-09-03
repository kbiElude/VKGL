/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_booleanv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_pname,
                     GLboolean*       out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglGetBooleanv(GLenum     pname,
                                           GLboolean* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetBooleanv(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       data);
}

static void vkglGetBooleanv_execute(OpenGL::Context* in_context_ptr,
                                    const GLenum&    in_pname,
                                    GLboolean*       out_data_ptr)
{
    const OpenGL::ContextProperty pname_vkgl = OpenGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_parameter(pname_vkgl,
                                  OpenGL::GetSetArgumentType::Boolean,
                                  out_data_ptr);
}

void OpenGL::vkglGetBooleanv_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_pname,
                                             GLboolean*       out_data_ptr)
{
    if (validate(in_context_ptr,
                 in_pname,
                 out_data_ptr) )
    {
        vkglGetBooleanv_execute(in_context_ptr,
                                in_pname,
                                out_data_ptr);
    }
}