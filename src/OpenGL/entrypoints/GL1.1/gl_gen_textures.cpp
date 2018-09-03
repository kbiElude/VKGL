/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_gen_textures.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLsizei&   in_n,
                     GLuint*          in_textures)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGenTextures(GLsizei n,
                                           GLuint* textures)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGenTextures(dispatch_table_ptr->bound_context_ptr,
                                       n,
                                       textures);
}

static void vkglGenTextures_execute(OpenGL::Context* in_context_ptr,
                                    const GLsizei&   in_n,
                                    GLuint*          in_textures)
{
    in_context_ptr->gen_textures(in_n,
                                 in_textures);
}

void OpenGL::vkglGenTextures_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLsizei&   in_n,
                                             GLuint*          in_textures)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_textures) )
    {
        vkglGenTextures_execute(in_context_ptr,
                                in_n,
                                in_textures);
    }
}