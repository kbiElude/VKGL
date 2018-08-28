/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_delete_textures.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     const GLuint*  in_textures)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDeleteTextures(GLsizei       n,
                                              const GLuint* textures)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDeleteTextures(dispatch_table_ptr->bound_context_ptr,
                                          n,
                                          textures);
}

static void vkglDeleteTextures_execute(VKGL::Context* in_context_ptr,
                                       const GLsizei& in_n,
                                       const GLuint*  in_textures)
{
    in_context_ptr->delete_textures(in_n,
                                    in_textures);
}

void OpenGL::vkglDeleteTextures_with_validation(VKGL::Context* in_context_ptr,
                                                const GLsizei& in_n,
                                                const GLuint*  in_textures)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_textures) )
    {
        vkglDeleteTextures_execute(in_context_ptr,
                                   in_n,
                                   in_textures);
    }
}