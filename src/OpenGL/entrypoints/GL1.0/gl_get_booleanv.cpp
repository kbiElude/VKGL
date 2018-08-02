#include "OpenGL/entrypoints/GL1.0/gl_get_booleanv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     GLboolean*     out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glGetBooleanv(GLenum     pname,
                                          GLboolean* data)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetBooleanv(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       data);
}

void vkglGetBooleanv_execute(VKGL::Context* in_context_ptr,
                             const GLenum&  in_pname,
                             GLboolean*     out_data_ptr)
{
    const VKGL::ContextProperty pname_vkgl = VKGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_parameter(pname_vkgl,
                                  VKGL::GetSetArgumentType::Boolean,
                                  out_data_ptr);
}

void vkglGetBooleanv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     GLboolean*     out_data_ptr)
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