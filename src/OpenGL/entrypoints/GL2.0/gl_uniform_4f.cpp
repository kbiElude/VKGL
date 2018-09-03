/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLfloat&   in_v0,
                     const GLfloat&   in_v1,
                     const GLfloat&   in_v2,
                     const GLfloat&   in_v3)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform4f(GLint   location,
                                         GLfloat v0,
                                         GLfloat v1,
                                         GLfloat v2,
                                         GLfloat v3)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform4f(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0,
                                     v1,
                                     v2,
                                     v3);
}

static void vkglUniform4f_execute(OpenGL::Context* in_context_ptr,
                                  const GLint&     in_location,
                                  const GLfloat&   in_v0,
                                  const GLfloat&   in_v1,
                                  const GLfloat&   in_v2,
                                  const GLfloat&   in_v3)
{
    const GLfloat data[] =
    {
        in_v0,
        in_v1,
        in_v2,
        in_v3
    };

    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Float,
                                4,
                                data);
}

void OpenGL::vkglUniform4f_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLint&     in_location,
                                           const GLfloat&   in_v0,
                                           const GLfloat&   in_v1,
                                           const GLfloat&   in_v2,
                                           const GLfloat&   in_v3)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1,
                 in_v2,
                 in_v3) )
    {
        vkglUniform4f_execute(in_context_ptr,
                              in_location,
                              in_v0,
                              in_v1,
                              in_v2,
                              in_v3);
    }
}
