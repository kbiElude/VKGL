/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_bind_texture.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_texture)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBindTexture(GLenum target,
                                           GLuint texture)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindTexture(dispatch_table_ptr->bound_context_ptr,
                                       target,
                                       texture);
}

static void vkglBindTexture_execute(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_target,
                                    const GLuint&  in_texture)
{
    const auto target_vkgl = VKGL::Utils::get_texture_target_for_gl_enum(in_texture);

    in_context_ptr->bind_texture(target_vkgl,
                                 in_texture);
}

void OpenGL::vkglBindTexture_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_target,
                                             const GLuint&  in_texture)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_texture) )
    {
        vkglBindTexture_execute(in_context_ptr,
                                in_target,
                                in_texture);
    }
}