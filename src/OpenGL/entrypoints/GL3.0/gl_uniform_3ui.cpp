/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_uniform_3ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLuint&    in_v0,
                     const GLuint&    in_v1,
                     const GLuint&    in_v2)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform3ui(GLint  location,
                                          GLuint v0,
                                          GLuint v1,
                                          GLuint v2)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glUniform3ui(location=[%d] v0=[%u] v1=[%u] v2=[%u])",
               location,
               v0,
               v1,
               v2);

    dispatch_table_ptr->pGLUniform3ui(dispatch_table_ptr->bound_context_ptr,
                                      location,
                                      v0,
                                      v1,
                                      v2);
}

static void vkglUniform3ui_execute(OpenGL::Context* in_context_ptr,
                                   const GLint&     in_location,
                                   const GLuint&    in_v0,
                                   const GLuint&    in_v1,
                                   const GLuint&    in_v2)
{
    const GLuint data[] =
    {
        in_v0,
        in_v1,
        in_v2
    };

    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Unsigned_Int,
                                3,
                                data);
}

void OpenGL::vkglUniform3ui_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLint&     in_location,
                                            const GLuint&    in_v0,
                                            const GLuint&    in_v1,
                                            const GLuint&    in_v2)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1,
                 in_v2) )
    {
        vkglUniform3ui_execute(in_context_ptr,
                               in_location,
                               in_v0,
                               in_v1,
                               in_v2);
    }
}
