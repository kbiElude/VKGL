/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_is_texture.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_texture)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY vkglIsTexture(GLuint texture)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsTexture(dispatch_table_ptr->bound_context_ptr,
                                            texture);
}

GLboolean vkglIsTexture_execute(VKGL::Context* in_context_ptr,
                                const GLuint&  in_texture)
{
    return (in_context_ptr->is_texture(in_texture) ) ? GL_TRUE : GL_FALSE;
}

GLboolean vkglIsTexture_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_texture)
{
    if (validate(in_context_ptr,
                 in_texture) )
    {
        return vkglIsTexture_execute(in_context_ptr,
                                     in_texture);
    }
}