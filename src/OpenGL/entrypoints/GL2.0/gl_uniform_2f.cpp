/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_location,
                     const GLfloat& in_v0,
                     const GLfloat& in_v1)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglUniform2f(GLint   location,
                                 GLfloat v0,
                                 GLfloat v1)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform2f(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0,
                                     v1);
}

void vkglUniform2f_execute(VKGL::Context* in_context_ptr,
                           const GLint&   in_location,
                           const GLfloat& in_v0,
                           const GLfloat& in_v1)
{
    const GLfloat data[] =
    {
        in_v0,
        in_v1
    };

    in_context_ptr->set_uniform(in_location,
                                VKGL::GetSetArgumentType::Float,
                                2,
                                data);
}

void vkglUniform2f_with_validation(VKGL::Context* in_context_ptr,
                                   const GLint&   in_location,
                                   const GLfloat& in_v0,
                                   const GLfloat& in_v1)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1) )
    {
        vkglUniform2f_execute(in_context_ptr,
                              in_location,
                              in_v0,
                              in_v1);
    }
}
