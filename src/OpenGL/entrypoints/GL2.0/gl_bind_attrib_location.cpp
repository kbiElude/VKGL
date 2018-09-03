/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_bind_attrib_location.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program,
                     const GLuint&    in_index,
                     const GLchar*    in_name)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBindAttribLocation(GLuint        program,
                                                  GLuint        index,
                                                  const GLchar* name)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindAttribLocation(dispatch_table_ptr->bound_context_ptr,
                                              program,
                                              index,
                                              name);
}

static void vkglBindAttribLocation_execute(OpenGL::Context* in_context_ptr,
                                           const GLuint&    in_program,
                                           const GLuint&    in_index,
                                           const GLchar*    in_name)
{
    in_context_ptr->bind_attrib_location(in_program,
                                         in_index,
                                         in_name);
}

void OpenGL::vkglBindAttribLocation_with_validation(OpenGL::Context* in_context_ptr,
                                                    const GLuint&    in_program,
                                                    const GLuint&    in_index,
                                                    const GLchar*    in_name)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_index,
                 in_name) )
    {
        vkglBindAttribLocation_execute(in_context_ptr,
                                       in_program,
                                       in_index,
                                       in_name);
    }
}
