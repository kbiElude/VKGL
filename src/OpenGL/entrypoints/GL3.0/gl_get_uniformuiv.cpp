/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_uniformuiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLint&   in_location,
                     GLuint*        out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglGetUniformuiv(GLuint  program,
                                              GLint   location,
                                              GLuint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetUniformuiv(dispatch_table_ptr->bound_context_ptr,
                                         program,
                                         location,
                                         params);
}

void vkglGetUniformuiv_execute(VKGL::Context* in_context_ptr,
                               const GLuint&  in_program,
                               const GLint&   in_location,
                               GLuint*        out_params_ptr)
{
    in_context_ptr->get_uniform_value(in_program,
                                      in_location,
                                      VKGL::GetSetArgumentType::Unsigned_Int,
                                      out_params_ptr);
}

void vkglGetUniformuiv_with_validation(VKGL::Context* in_context_ptr,
                                       const GLuint&  in_program,
                                       const GLint&   in_location,
                                       GLuint*        out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_location,
                 out_params_ptr) )
    {
        vkglGetUniformuiv_execute(in_context_ptr,
                                  in_program,
                                  in_location,
                                  out_params_ptr);
    }
}
