/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_provoking_vertex.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglProvokingVertex(GLenum mode)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLProvokingVertex(dispatch_table_ptr->bound_context_ptr,
                                           mode);
}

static void vkglProvokingVertex_execute(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_mode)
{
    const auto mode_vkgl = VKGL::Utils::get_provoking_vertex_convention_for_gl_enum(in_mode);

    in_context_ptr->set_provoking_vertex(mode_vkgl);
}

void OpenGL::vkglProvokingVertex_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_mode) )
    {
        vkglProvokingVertex_execute(in_context_ptr,
                                    in_mode);
    }
}