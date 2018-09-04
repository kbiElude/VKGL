/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_is_query.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_id)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


GLboolean VKGL_APIENTRY OpenGL::vkglIsQuery(GLuint id)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glIsQuery(id=[%u])",
               id);

    return dispatch_table_ptr->pGLIsQuery(dispatch_table_ptr->bound_context_ptr,
                                          id) ? GL_TRUE
                                              : GL_FALSE;
}


static bool vkglIsQuery_execute(OpenGL::Context* in_context_ptr,
                                const GLuint&    in_id)
{
    return in_context_ptr->is_query(in_id);
}

bool OpenGL::vkglIsQuery_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLuint&    in_id)
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
