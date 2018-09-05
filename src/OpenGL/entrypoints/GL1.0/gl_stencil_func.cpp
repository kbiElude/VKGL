/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_stencil_func.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_func,
                     const GLint&     in_ref,
                     const GLuint&    in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglStencilFunc(GLenum func,
                                           GLint  ref,
                                           GLuint mask)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glStencilFunc(func=[%s] ref=[%d] mask=[%u])",
               OpenGL::Utils::get_raw_string_for_gl_enum(func),
               ref,
               mask);

    dispatch_table_ptr->pGLStencilFunc(dispatch_table_ptr->bound_context_ptr,
                                       func,
                                       ref,
                                       mask);
}

static void vkglStencilFunc_execute(OpenGL::Context* in_context_ptr,
                                    const GLenum&    in_func,
                                    const GLint&     in_ref,
                                    const GLuint&    in_mask)
{
    const auto func_vkgl = OpenGL::Utils::get_stencil_function_for_gl_enum(in_func);

    in_context_ptr->set_stencil_function(func_vkgl,
                                         in_ref,
                                         in_mask);
}

void OpenGL::vkglStencilFunc_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_func,
                                             const GLint&     in_ref,
                                             const GLuint&    in_mask)
{
    if (validate(in_context_ptr,
                 in_func,
                 in_ref,
                 in_mask) )
    {
        vkglStencilFunc_execute(in_context_ptr,
                                in_func,
                                in_ref,
                                in_mask);
    }
}