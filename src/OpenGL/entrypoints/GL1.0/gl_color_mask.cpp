/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_color_mask.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*   in_context_ptr,
                     const GLboolean& in_red,
                     const GLboolean& in_green,
                     const GLboolean& in_blue,
                     const GLboolean& in_alpha)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY vkglColorMask(GLboolean red,
                                 GLboolean green,
                                 GLboolean blue,
                                 GLboolean alpha)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLColorMask(dispatch_table_ptr->bound_context_ptr,
                                     red,
                                     green,
                                     blue,
                                     alpha);
}

void vkglColorMask_execute(VKGL::Context*   in_context_ptr,
                           const GLboolean& in_red,
                           const GLboolean& in_green,
                           const GLboolean& in_blue,
                           const GLboolean& in_alpha)
{
    in_context_ptr->set_color_mask( (in_red   == GL_TRUE),
                                    (in_green == GL_TRUE),
                                    (in_blue  == GL_TRUE),
                                    (in_alpha == GL_TRUE) );
}

void vkglColorMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_red,
                                   const GLboolean& in_green,
                                   const GLboolean& in_blue,
                                   const GLboolean& in_alpha)
{
    if (validate(in_context_ptr,
                 in_red,
                 in_green,
                 in_blue,
                 in_alpha) )
    {
        vkglColorMask_execute(in_context_ptr,
                              in_red,
                              in_green,
                              in_blue,
                              in_alpha);
    }
}