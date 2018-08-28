/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_delete_queries.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     const GLuint*  in_ids)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteQueries(GLsizei       n,
                                             const GLuint* ids)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDeleteQueries(dispatch_table_ptr->bound_context_ptr,
                                         n,
                                         ids);
}

static void vkglDeleteQueries_execute(VKGL::Context* in_context_ptr,
                                      const GLsizei& in_n,
                                      const GLuint*  in_ids)
{
    in_context_ptr->delete_queries(in_n,
                                   in_ids);
}

void OpenGL::vkglDeleteQueries_with_validation(VKGL::Context* in_context_ptr,
                                               const GLsizei& in_n,
                                               const GLuint*  in_ids)
{
    if (validate(in_context_ptr,
                  in_n,
                  in_ids) )
    {
        vkglDeleteQueries_execute(in_context_ptr,
                                  in_n,
                                  in_ids);
    }
}