/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_bind_frag_data_location.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_color,
                     const GLchar*  in_name)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glBindFragDataLocation(GLuint        program,
                                                   GLuint        color,
                                                   const GLchar* name)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindFragDataLocation(dispatch_table_ptr->bound_context_ptr,
                                                program,
                                                color,
                                                name);
}

void vkglBindFragDataLocation_execute(VKGL::Context* in_context_ptr,
                                      const GLuint&  in_program,
                                      const GLuint&  in_color,
                                      const GLchar*  in_name)
{
    in_context_ptr->bind_frag_data_location(in_program,
                                            in_color,
                                            in_name);
}

void vkglBindFragDataLocation_with_validation(VKGL::Context* in_context_ptr,
                                              const GLuint&  in_program,
                                              const GLuint&  in_color,
                                              const GLchar*  in_name)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_color,
                 in_name) )
    {
        vkglBindFragDataLocation_execute(in_context_ptr,
                                         in_program,
                                         in_color,
                                         in_name);
    }
}
