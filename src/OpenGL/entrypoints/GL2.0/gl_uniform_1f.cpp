/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLfloat&   in_v0)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform1f(GLint   location,
                                         GLfloat v0)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform1f(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0);
}

static void vkglUniform1f_execute(OpenGL::Context* in_context_ptr,
                                  const GLint&     in_location,
                                  const GLfloat&   in_v0)
{
    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Float,
                                1,
                               &in_v0);
}

void OpenGL::vkglUniform1f_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLint&     in_location,
                                           const GLfloat&   in_v0)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0) )
    {
        vkglUniform1f_execute(in_context_ptr,
                              in_location,
                              in_v0);
    }
}
