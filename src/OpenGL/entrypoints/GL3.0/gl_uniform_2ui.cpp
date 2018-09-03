/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_uniform_2ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLuint&    in_v0,
                     const GLuint&    in_v1)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform2ui(GLint  location,
                                          GLuint v0,
                                          GLuint v1)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform2ui(dispatch_table_ptr->bound_context_ptr,
                                      location,
                                      v0,
                                      v1);
}

static void vkglUniform2ui_execute(OpenGL::Context* in_context_ptr,
                                   const GLint&     in_location,
                                   const GLuint&    in_v0,
                                   const GLuint&    in_v1)
{
    const GLuint data[] =
    {
        in_v0,
        in_v1
    };

    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Unsigned_Int,
                                2,
                                data);
}

void OpenGL::vkglUniform2ui_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLint&     in_location,
                                            const GLuint&    in_v0,
                                            const GLuint&    in_v1)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1) )
    {
        vkglUniform2ui_execute(in_context_ptr,
                               in_location,
                               in_v0,
                               in_v1);
    }
}
