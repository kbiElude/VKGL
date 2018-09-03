/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_is_vertex_array.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_array)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY OpenGL::vkglIsVertexArray(GLuint array)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsVertexArray(dispatch_table_ptr->bound_context_ptr,
                                                array) == GL_TRUE;
}

static bool vkglIsVertexArray_execute(OpenGL::Context* in_context_ptr,
                                      const GLuint&    in_array)
{
    return in_context_ptr->is_vertex_array(in_array) == GL_TRUE;
}

bool OpenGL::vkglIsVertexArray_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLuint&    in_array)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_array) )
    {
        result = vkglIsVertexArray_execute(in_context_ptr,
                                           in_array);
    }

    return result;
}

