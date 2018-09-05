/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4i.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLint&     in_v0,
                     const GLint&     in_v1,
                     const GLint&     in_v2,
                     const GLint&     in_v3)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform4i(GLint location,
                                         GLint v0,
                                         GLint v1,
                                         GLint v2,
                                         GLint v3)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glUniform4i(location=[%d] v0=[%d] v1=[%d] v2=[%d] v3=[%d])",
               location,
               v0,
               v1,
               v2,
               v3);

    dispatch_table_ptr->pGLUniform4i(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0,
                                     v1,
                                     v2,
                                     v3);
}

static void vkglUniform4i_execute(OpenGL::Context* in_context_ptr,
                                  const GLint&     in_location,
                                  const GLint&     in_v0,
                                  const GLint&     in_v1,
                                  const GLint&     in_v2,
                                  const GLint&     in_v3)
{
    const GLint data[] =
    {
        in_v0,
        in_v1,
        in_v2,
        in_v3
    };

    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Int,
                                4,
                                data);
}

void OpenGL::vkglUniform4i_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLint&     in_location,
                                           const GLint&     in_v0,
                                           const GLint&     in_v1,
                                           const GLint&     in_v2,
                                           const GLint&     in_v3)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1,
                 in_v2,
                 in_v3) )
    {
        vkglUniform4i_execute(in_context_ptr,
                              in_location,
                              in_v0,
                              in_v1,
                              in_v2,
                              in_v3);
    }
}
