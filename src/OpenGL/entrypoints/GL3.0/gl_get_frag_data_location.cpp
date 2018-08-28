/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_frag_data_location.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLchar*  in_name_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLint VKGL_APIENTRY OpenGL::vkglGetFragDataLocation(GLuint        program,
                                                    const GLchar* name)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetFragDataLocation(dispatch_table_ptr->bound_context_ptr,
                                                      program,
                                                      name);
}

static GLint vkglGetFragDataLocation_execute(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_program,
                                             const GLchar*  in_name_ptr)
{
    return in_context_ptr->get_frag_data_location(in_program,
                                                  in_name_ptr);
}

GLint OpenGL::vkglGetFragDataLocation_with_validation(VKGL::Context* in_context_ptr,
                                                      const GLuint&  in_program,
                                                      const GLchar*  in_name_ptr)
{
    GLint result = INT32_MAX;

    if (validate(in_context_ptr,
                 in_program,
                 in_name_ptr) )
    {
        result = vkglGetFragDataLocation_execute(in_context_ptr,
                                                 in_program,
                                                 in_name_ptr);
    }

    return result;
}
