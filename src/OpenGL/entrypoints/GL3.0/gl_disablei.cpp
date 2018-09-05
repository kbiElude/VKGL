/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_disablei.h"
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

void VKGL_APIENTRY OpenGL::vkglDisablei(GLenum target,
                                        GLuint index)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glDisablei(target=[%s] index=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               index);

    dispatch_table_ptr->pGLDisablei(dispatch_table_ptr->bound_context_ptr,
                                    target,
                                    index);
}

static void vkglDisablei_execute(OpenGL::Context* in_context_ptr,
                                 const GLenum&    in_target,
                                 const GLuint&    in_index)
{
    vkgl_assert(in_target == GL_BLEND);

    in_context_ptr->disable_indexed(OpenGL::Capability::Blend,
                                    in_index);
}

void OpenGL::vkglDisablei_with_validation(OpenGL::Context* in_context_ptr,
                                          const GLenum&    in_target,
                                          const GLuint&    in_index)
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
