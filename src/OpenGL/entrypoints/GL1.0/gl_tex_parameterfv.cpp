#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterfv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     const GLfloat* in_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glTexParameterfv(GLenum         target,
                                             GLenum         pname,
                                             const GLfloat* params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLTexParameterfv(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          pname,
                                          params);
}

void vkglTexParameterfv_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_target,
                                const GLenum&  in_pname,
                                const GLfloat* in_params_ptr)
{
    const auto pname_vkgl  = VKGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->set_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          VKGL::GetSetArgumentType::Float,
                                          in_params_ptr);
}

void vkglTexParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLenum&  in_pname,
                                        const GLfloat* in_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 in_params_ptr) )
    {
        vkglTexParameterfv_execute(in_context_ptr,
                                   in_target,
                                   in_pname,
                                   in_params_ptr);
    }
}