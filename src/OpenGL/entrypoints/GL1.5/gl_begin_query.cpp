/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_begin_query.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLuint&    in_id)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBeginQuery(GLenum target,
                                          GLuint id)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBeginQuery(target=[%s] id=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               id);

    dispatch_table_ptr->pGLBeginQuery(dispatch_table_ptr->bound_context_ptr,
                                      target,
                                      id);
}

static void vkglBeginQuery_execute(OpenGL::Context* in_context_ptr,
                                   const GLenum&    in_target,
                                   const GLuint&    in_id)
{
    const auto target_vkgl = OpenGL::Utils::get_query_target_for_gl_enum(in_target);

    in_context_ptr->begin_query(target_vkgl,
                                in_id);
}

void OpenGL::vkglBeginQuery_with_validation(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_target,
                                            const GLuint&    in_id)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_id) )
    {
        vkglBeginQuery_execute(in_context_ptr,
                               in_target,
                               in_id);
    }
}
