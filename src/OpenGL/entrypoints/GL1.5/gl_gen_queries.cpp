/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_gen_queries.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     GLuint*        out_ids_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGenQueries(GLsizei n,
                                  GLuint* ids)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenQueries(dispatch_table_ptr->bound_context_ptr,
                                      n,
                                      ids);
}

void vkglGenQueries_execute(VKGL::Context* in_context_ptr,
                            const GLsizei& in_n,
                            GLuint*        out_ids_ptr)
{
    in_context_ptr->gen_queries(in_n,
                                out_ids_ptr);
}

void vkglGenQueries_with_validation(VKGL::Context* in_context_ptr,
                                    const GLsizei& in_n,
                                    GLuint*        out_ids_ptr)
{
    if (validate(in_context_ptr,
                 in_n,
                 out_ids_ptr) )
    {
        vkglGenQueries_execute(in_context_ptr,
                               in_n,
                               out_ids_ptr);
    }
}
