/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.3/gl_active_texture.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(const VKGL::Context* in_context_ptr,
                     const GLenum&        in_texture)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglActiveTexture(GLenum texture)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLActiveTexture(dispatch_table_ptr->bound_context_ptr,
                                         texture);
}

void vkglActiveTexture_execute(VKGL::Context* in_context_ptr,
                               const GLenum&  in_texture)
{
    const auto n_texture_unit = in_texture - GL_TEXTURE0;

    in_context_ptr->set_active_texture(n_texture_unit);
}

void vkglActiveTexture_with_validation(VKGL::Context* in_context_ptr,
                                       const GLenum&  in_texture)
{
    if (validate(in_context_ptr,
                 in_texture) )
    {
        vkglActiveTexture_execute(in_context_ptr,
                                  in_texture);
    }
}

