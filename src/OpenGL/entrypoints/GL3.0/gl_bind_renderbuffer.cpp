/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_bind_renderbuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_renderbuffer)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glBindRenderbuffer(GLenum target,
                                               GLuint renderbuffer)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBindRenderbuffer(dispatch_table_ptr->bound_context_ptr,
                                            target,
                                            renderbuffer);
}

void vkglBindRenderbuffer_execute(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_target,
                                  const GLuint&  in_renderbuffer)
{
    const auto target_vkgl = VKGL::Utils::get_renderbuffer_target_for_gl_enum(in_target);

    in_context_ptr->bind_renderbuffer(target_vkgl,
                                      in_renderbuffer);
}

void vkglBindRenderbuffer_with_validation(VKGL::Context* in_context_ptr,
                                          const GLenum&  in_target,
                                          const GLuint&  in_renderbuffer)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_renderbuffer) )
    {
        vkglBindRenderbuffer_execute(in_context_ptr,
                                     in_target,
                                     in_renderbuffer);
    }
}
