/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_is_query.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_id)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


GLboolean VKGL_APIENTRY vkglIsQuery(GLuint id)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsQuery(dispatch_table_ptr->bound_context_ptr,
                                          id) ? GL_TRUE
                                              : GL_FALSE;
}


bool vkglIsQuery_execute(VKGL::Context* in_context_ptr,
                         const GLuint&  in_id)
{
    return in_context_ptr->is_query(in_id);
}

bool vkglIsQuery_with_validation(VKGL::Context* in_context_ptr,
                                 const GLuint&  in_id)
{
    bool result = false;

    if (validate(in_context_ptr,
                 in_id) )
    {
        result = vkglIsQuery_execute(in_context_ptr,
                                     in_id);
    }

    return result;
}
