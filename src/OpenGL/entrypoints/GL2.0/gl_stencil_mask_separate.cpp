/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_stencil_mask_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_face,
                     const GLuint&    in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglStencilMaskSeparate(GLenum face,
                                                   GLuint mask)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilMaskSeparate(dispatch_table_ptr->bound_context_ptr,
                                               face,
                                               mask);
}

static void vkglStencilMaskSeparate_execute(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_face,
                                            const GLuint&    in_mask)
{
    const auto face_vkgl = OpenGL::Utils::get_stencil_state_face_for_gl_enum(in_face);

    in_context_ptr->set_stencil_mask_separate(face_vkgl,
                                              in_mask);
}

void OpenGL::vkglStencilMaskSeparate_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_face,
                                                     const GLuint&    in_mask)
{
    if (validate(in_context_ptr,
                 in_face,
                 in_mask) )
    {
        vkglStencilMaskSeparate_execute(in_context_ptr,
                                        in_face,
                                        in_mask);
    }
}
