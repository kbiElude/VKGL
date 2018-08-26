/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_location,
                     const GLint&   in_v0)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglUniform1i(GLint location,
                                 GLint v0)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform1i(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0);
}

void vkglUniform1i_execute(VKGL::Context* in_context_ptr,
                           const GLint&   in_location,
                           const GLint&   in_v0)
{
    in_context_ptr->set_uniform(in_location,
                                VKGL::GetSetArgumentType::Int,
                                1,
                               &in_v0);
}

void vkglUniform1i_with_validation(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLint&   in_v0)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0) )
    {
        vkglUniform1i_execute(in_context_ptr,
                              in_location,
                              in_v0);
    }
}
