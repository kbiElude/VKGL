/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_enablei.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLuint&    in_index)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglEnablei(GLenum target,
                                       GLuint index)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLEnablei(dispatch_table_ptr->bound_context_ptr,
                                   target,
                                   index);
}

static void vkglEnablei_execute(OpenGL::Context* in_context_ptr,
                                const GLenum&    in_target,
                                const GLuint&    in_index)
{
    vkgl_assert(in_target == GL_BLEND);

    in_context_ptr->enablei(OpenGL::Capability::Blend,
                            in_index);
}

void OpenGL::vkglEnablei_with_validation(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_target,
                                         const GLuint&    in_index)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_index) )
    {
        vkglEnablei_execute(in_context_ptr,
                            in_target,
                            in_index);
    }
}
