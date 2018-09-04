/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_attached_shaders.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_program,
                     const GLsizei&   in_max_count,
                     GLsizei*         out_count_ptr,
                     GLuint*          out_shaders_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetAttachedShaders(GLuint   program,
                                                  GLsizei  maxCount,
                                                  GLsizei* count,
                                                  GLuint*  shaders)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetAttachedShaders(program=[%u] maxCount=[%d] count=[%p] shaders=[%p])",
               program,
               static_cast<int32_t>(maxCount),
               count,
               shaders);

    dispatch_table_ptr->pGLGetAttachedShaders(dispatch_table_ptr->bound_context_ptr,
                                              program,
                                              maxCount,
                                              count,
                                              shaders);
}

static void vkglGetAttachedShaders_execute(OpenGL::Context* in_context_ptr,
                                           const GLuint&    in_program,
                                           const GLsizei&   in_max_count,
                                           GLsizei*         out_count_ptr,
                                           GLuint*          out_shaders_ptr)
{
    in_context_ptr->get_attached_shaders(in_program,
                                         in_max_count,
                                         out_count_ptr,
                                         out_shaders_ptr);
}

void OpenGL::vkglGetAttachedShaders_with_validation(OpenGL::Context* in_context_ptr,
                                                    const GLuint&    in_program,
                                                    const GLsizei&   in_max_count,
                                                    GLsizei*         out_count_ptr,
                                                    GLuint*          out_shaders_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_max_count,
                 out_count_ptr,
                 out_shaders_ptr) )
    {
        vkglGetAttachedShaders_execute(in_context_ptr,
                                       in_program,
                                       in_max_count,
                                       out_count_ptr,
                                       out_shaders_ptr);
    }
}