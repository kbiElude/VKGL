/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_polygon_mode.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_face,
                     const GLenum&  in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglPolygonMode(GLenum face,
                                   GLenum mode)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPolygonMode(dispatch_table_ptr->bound_context_ptr,
                                       face,
                                       mode);
}

void vkglPolygonMode_execute(VKGL::Context* in_context_ptr,
                            const GLenum&   in_face,
                            const GLenum&   in_mode)
{
    const auto mode_vkgl = VKGL::Utils::get_polygon_mode_for_gl_enum(in_mode);

    vkgl_assert(in_face == GL_FRONT_AND_BACK);

    in_context_ptr->set_polygon_mode(mode_vkgl);
}

void vkglPolygonMode_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_face,
                                     const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_face,
                 in_mode) )
    {
        vkglPolygonMode_execute(in_context_ptr,
                                in_face,
                                in_mode);
    }
}