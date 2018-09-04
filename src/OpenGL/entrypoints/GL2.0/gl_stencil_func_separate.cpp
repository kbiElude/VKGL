/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_stencil_func_separate.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_face,
                     const GLenum&    in_func,
                     const GLint&     in_ref,
                     const GLuint&    in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglStencilFuncSeparate(GLenum face,
                                                   GLenum func,
                                                   GLint  ref,
                                                   GLuint mask)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glStencilFuncSeparate(face=[%s] func=[%s] ref=[%d] mask=[%u])",
               OpenGL::Utils::get_raw_string_for_gl_enum(face),
               OpenGL::Utils::get_raw_string_for_gl_enum(func),
               ref,
               mask);

    dispatch_table_ptr->pGLStencilFuncSeparate(dispatch_table_ptr->bound_context_ptr,
                                               face,
                                               func,
                                               ref,
                                               mask);
}

static void vkglStencilFuncSeparate_execute(OpenGL::Context* in_context_ptr,
                                            const GLenum&    in_face,
                                            const GLenum&    in_func,
                                            const GLint&     in_ref,
                                            const GLuint&    in_mask)
{
    const auto face_vkgl = OpenGL::Utils::get_stencil_state_face_for_gl_enum(in_face);
    const auto func_vkgl = OpenGL::Utils::get_stencil_function_for_gl_enum  (in_func);

    in_context_ptr->set_stencil_function_separate(face_vkgl,
                                                  func_vkgl,
                                                  in_ref,
                                                  in_mask);
}

void OpenGL::vkglStencilFuncSeparate_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLenum&    in_face,
                                                     const GLenum&    in_func,
                                                     const GLint&     in_ref,
                                                     const GLuint&    in_mask)
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
