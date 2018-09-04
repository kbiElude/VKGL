/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_begin_conditional_render.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_id,
                     const GLenum&    in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBeginConditionalRender(GLuint id,
                                                      GLenum mode)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glBeginConditionalRender(id=[%d] mode=[%s])",
               id,
               OpenGL::Utils::get_raw_string_for_gl_enum(mode) );

    dispatch_table_ptr->pGLBeginConditionalRender(dispatch_table_ptr->bound_context_ptr,
                                                  id,
                                                  mode);
}

static void vkglBeginConditionalRender_execute(OpenGL::Context* in_context_ptr,
                                               const GLuint&    in_id,
                                               const GLenum&    in_mode)
{
    const auto mode_vkgl = OpenGL::Utils::get_conditional_render_mode_for_gl_enum(in_mode);

    in_context_ptr->begin_conditional_render(in_id,
                                             mode_vkgl);
}

void OpenGL::vkglBeginConditionalRender_with_validation(OpenGL::Context* in_context_ptr,
                                                        const GLuint&    in_id,
                                                        const GLenum&    in_mode)
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


