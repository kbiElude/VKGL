/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_cull_face.h"
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


void VKGL_APIENTRY vkglCullFace(GLenum mode)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCullFace(dispatch_table_ptr->bound_context_ptr,
                                    mode);
}

void vkglCullFace_execute(VKGL::Context* in_context_ptr,
                          const GLenum&  in_mode)
{
    const auto mode_vkgl = VKGL::Utils::get_cull_mode_for_gl_enum(in_mode);

    in_context_ptr->set_cull_mode(mode_vkgl);
}

void vkglCullFace_with_validation(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_mode) )
    {
        vkglCullFace_execute(in_context_ptr,
                             in_mode);
    }
}