/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3f.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLfloat&   in_v0,
                     const GLfloat&   in_v1,
                     const GLfloat&   in_v2)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform3f(GLint   location,
                                         GLfloat v0,
                                         GLfloat v1,
                                         GLfloat v2)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glUniform3f(location=[%d] v0=[%.4f] v1=[%.4f] v2=[%.4f])",
               location,
               v0,
               v1,
               v2);

    dispatch_table_ptr->pGLUniform3f(dispatch_table_ptr->bound_context_ptr,
                                     location,
                                     v0,
                                     v1,
                                     v2);
}

static void vkglUniform3f_execute(OpenGL::Context* in_context_ptr,
                                  const GLint&     in_location,
                                  const GLfloat&   in_v0,
                                  const GLfloat&   in_v1,
                                  const GLfloat&   in_v2)
{
    const GLfloat data[] =
    {
        in_v0,
        in_v1,
        in_v2
    };

    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Float,
                                3, /* in_n_components  */
                                1, /* in_n_array_items */
                                data);
}

void OpenGL::vkglUniform3f_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLint&     in_location,
                                           const GLfloat&   in_v0,
                                           const GLfloat&   in_v1,
                                           const GLfloat&   in_v2)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1,
                 in_v2) )
    {
        vkglUniform3f_execute(in_context_ptr,
                              in_location,
                              in_v0,
                              in_v1,
                              in_v2);
    }
}
