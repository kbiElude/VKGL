/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterfv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLenum&    in_pname,
                     const GLfloat*   in_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglTexParameterfv(GLenum         target,
                                              GLenum         pname,
                                              const GLfloat* params)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glTexParameterfv(target=[%s] pname=[%s] params=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               params);

    dispatch_table_ptr->pGLTexParameterfv(dispatch_table_ptr->bound_context_ptr,
                                          target,
                                          pname,
                                          params);
}

static void vkglTexParameterfv_execute(OpenGL::Context* in_context_ptr,
                                       const GLenum&    in_target,
                                       const GLenum&    in_pname,
                                       const GLfloat*   in_params_ptr)
{
    const auto pname_vkgl  = OpenGL::Utils::get_texture_property_for_gl_enum(in_pname);
    const auto target_vkgl = OpenGL::Utils::get_texture_target_for_gl_enum  (in_target);

    in_context_ptr->set_texture_parameter(target_vkgl,
                                          pname_vkgl,
                                          OpenGL::GetSetArgumentType::Float,
                                          in_params_ptr);
}

void OpenGL::vkglTexParameterfv_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLenum&    in_target,
                                                const GLenum&    in_pname,
                                                const GLfloat*   in_params_ptr)
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