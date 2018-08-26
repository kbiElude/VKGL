/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_programiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLenum&  in_pname,
                     GLint*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGetProgramiv(GLuint program,
                                    GLenum pname,
                                    GLint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetProgramiv(dispatch_table_ptr->bound_context_ptr,
                                        program,
                                        pname,
                                        params);
}

void vkglGetProgramiv_execute(VKGL::Context* in_context_ptr,
                              const GLuint&  in_program,
                              const GLenum&  in_pname,
                              GLint*         out_params_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_program_property_for_gl_enum(in_pname);

    in_context_ptr->get_program_property(in_program,
                                         pname_vkgl,
                                         VKGL::GetSetArgumentType::Int,
                                         1,
                                         out_params_ptr);
}

void vkglGetProgramiv_with_validation(VKGL::Context* in_context_ptr,
                                      const GLuint&  in_program,
                                      const GLenum&  in_pname,
                                      GLint*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetProgramiv_execute(in_context_ptr,
                                 in_program,
                                 in_pname,
                                 out_params_ptr);
    }
}
