/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_end_query.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglEndQuery(GLenum target)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEndQuery(dispatch_table_ptr->bound_context_ptr,
                                    target);
}

static void vkglEndQuery_execute(OpenGL::Context* in_context_ptr,
                                 const GLenum&    in_target)
{
    const auto target_vkgl = OpenGL::Utils::get_query_target_for_gl_enum(in_target);

    in_context_ptr->end_query(target_vkgl);
}

void OpenGL::vkglEndQuery_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_target)
{
    if (validate(in_context_ptr,
                 in_target) )
    {
        vkglEndQuery_execute(in_context_ptr,
                             in_target);
    }
}
