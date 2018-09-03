/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_uniformiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program,
                     const GLint&     in_location,
                     GLint*           out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetUniformiv(GLuint program,
                                            GLint  location,
                                            GLint* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetUniformiv(dispatch_table_ptr->bound_context_ptr,
                                        program,
                                        location,
                                        params);
}

static void vkglGetUniformiv_execute(OpenGL::Context* in_context_ptr,
                                     const GLuint&    in_program,
                                     const GLint&     in_location,
                                     GLint*           out_params_ptr)
{
    in_context_ptr->get_uniform_value(in_program,
                                      in_location,
                                      OpenGL::GetSetArgumentType::Int,
                                      out_params_ptr);
}

void OpenGL::vkglGetUniformiv_with_validation(OpenGL::Context* in_context_ptr,
                                              const GLuint&    in_program,
                                              const GLint&     in_location,
                                              GLint*           out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_location,
                 out_params_ptr) )
    {
        vkglGetUniformiv_execute(in_context_ptr,
                                 in_program,
                                 in_location,
                                 out_params_ptr);
    }
}
