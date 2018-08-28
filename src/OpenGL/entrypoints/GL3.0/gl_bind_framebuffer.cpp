/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_bind_framebuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_framebuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBindFramebuffer(GLenum target,
                                               GLuint framebuffer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindFramebuffer(dispatch_table_ptr->bound_context_ptr,
                                           target,
                                           framebuffer);
}

static void vkglBindFramebuffer_execute(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLuint&  in_framebuffer)
{
    const auto target_vkgl = VKGL::Utils::get_framebuffer_target_for_gl_enum(in_target);

    in_context_ptr->bind_framebuffer(target_vkgl,
                                     in_framebuffer);
}

void OpenGL::vkglBindFramebuffer_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLenum&  in_target,
                                                 const GLuint&  in_framebuffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_framebuffer) )
    {
        vkglBindFramebuffer_execute(in_context_ptr,
                                    in_target,
                                    in_framebuffer);
    }
}
