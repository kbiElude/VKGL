/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_uniform_4ui.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLint&   in_location,
                     const GLuint&  in_v0,
                     const GLuint&  in_v1,
                     const GLuint&  in_v2,
                     const GLuint&  in_v3)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglUniform4ui(GLint  location,
                                  GLuint v0,
                                  GLuint v1,
                                  GLuint v2,
                                  GLuint v3)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLUniform4ui(dispatch_table_ptr->bound_context_ptr,
                                      location,
                                      v0,
                                      v1,
                                      v2,
                                      v3);
}

void vkglUniform4ui_execute(VKGL::Context* in_context_ptr,
                            const GLint&   in_location,
                            const GLuint&  in_v0,
                            const GLuint&  in_v1,
                            const GLuint&  in_v2,
                            const GLuint&  in_v3)
{
    const GLuint data[] =
    {
        in_v0,
        in_v1,
        in_v2,
        in_v3
    };

    in_context_ptr->set_uniform(in_location,
                                VKGL::GetSetArgumentType::Unsigned_Int,
                                4,
                                data);
}

void vkglUniform4ui_with_validation(VKGL::Context* in_context_ptr,
                                    const GLint&   in_location,
                                    const GLuint&  in_v0,
                                    const GLuint&  in_v1,
                                    const GLuint&  in_v2,
                                    const GLuint&  in_v3)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_v0,
                 in_v1,
                 in_v2,
                 in_v3) )
    {
        vkglUniform4ui_execute(in_context_ptr,
                               in_location,
                               in_v0,
                               in_v1,
                               in_v2,
                               in_v3);
    }
}
