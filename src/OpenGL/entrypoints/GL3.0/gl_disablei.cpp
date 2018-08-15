/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_disablei.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_index)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glDisablei(GLenum target,
                                       GLuint index)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDisablei(dispatch_table_ptr->bound_context_ptr,
                                    target,
                                    index);
}

void vkglDisablei_execute(VKGL::Context* in_context_ptr,
                          const GLenum&  in_target,
                          const GLuint&  in_index)
{
    vkgl_assert(in_target == GL_BLEND);

    in_context_ptr->disablei(VKGL::Capability::Blend,
                             in_index);
}

void vkglDisablei_with_validation(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_target,
                                  const GLuint&  in_index)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_index) )
    {
        vkglDisablei_execute(in_context_ptr,
                             in_target,
                             in_index);
    }
}
