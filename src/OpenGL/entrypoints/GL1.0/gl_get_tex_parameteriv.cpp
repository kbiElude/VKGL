#include "OpenGL/entrypoints/GL1.0/gl_get_tex_parameteriv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     GLint*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glGetTexParameteriv(GLenum target,
                                                GLenum pname,
                                                GLint* params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetTexParameteriv(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             pname,
                                             params);
}

void vkglGetTexParameteriv_execute(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_target,
                                   const GLenum&  in_pname,
                                   GLint*         out_params_ptr)
{
    const auto pname_vkgl  = VKGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->get_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          VKGL::GetSetArgumentType::Int,
                                          out_params_ptr);
}

void vkglGetTexParameteriv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_target,
                                           const GLenum&  in_pname,
                                           GLint*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetTexParameteriv_execute(in_context_ptr,
                                      in_target,
                                      in_pname,
                                      out_params_ptr);
    }
}