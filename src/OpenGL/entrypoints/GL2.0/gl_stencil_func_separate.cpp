/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_stencil_func_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_face,
                     const GLenum&  in_func,
                     const GLint&   in_ref,
                     const GLuint&  in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglStencilFuncSeparate(GLenum face,
                                           GLenum func,
                                           GLint  ref,
                                           GLuint mask)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilFuncSeparate(dispatch_table_ptr->bound_context_ptr,
                                               face,
                                               func,
                                               ref,
                                               mask);
}

void vkglStencilFuncSeparate_execute(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_face,
                                     const GLenum&  in_func,
                                     const GLint&   in_ref,
                                     const GLuint&  in_mask)
{
    const auto face_vkgl = VKGL::Utils::get_stencil_state_face_for_gl_enum(in_face);
    const auto func_vkgl = VKGL::Utils::get_stencil_function_for_gl_enum  (in_func);

    in_context_ptr->set_stencil_function_separate(face_vkgl,
                                                  func_vkgl,
                                                  in_ref,
                                                  in_mask);
}

void vkglStencilFuncSeparate_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_face,
                                             const GLenum&  in_func,
                                             const GLint&   in_ref,
                                             const GLuint&  in_mask)
{
    if (validate(in_context_ptr,
                 in_face,
                 in_func,
                 in_ref,
                 in_mask) )
    {
        vkglStencilFuncSeparate_execute(in_context_ptr,
                                        in_face,
                                        in_func,
                                        in_ref,
                                        in_mask);
    }
}
