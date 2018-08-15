/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_begin_conditional_render.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_id,
                     const GLenum&  in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glBeginConditionalRender(GLuint id,
                                                     GLenum mode)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBeginConditionalRender(dispatch_table_ptr->bound_context_ptr,
                                                  id,
                                                  mode);
}

void vkglBeginConditionalRender_execute(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_id,
                                        const GLenum&  in_mode)
{
    const auto mode_vkgl = VKGL::Utils::get_conditional_render_mode_for_gl_enum(in_mode);

    in_context_ptr->begin_conditional_render(in_id,
                                             mode_vkgl);
}

void vkglBeginConditionalRender_with_validation(VKGL::Context* in_context_ptr,
                                                const GLuint&  in_id,
                                                const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_id,
                 in_mode) )
    {
        vkglBeginConditionalRender_execute(in_context_ptr,
                                           in_id,
                                           in_mode);
    }
}


