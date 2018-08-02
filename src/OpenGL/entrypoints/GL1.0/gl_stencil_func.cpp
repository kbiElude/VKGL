#include "OpenGL/entrypoints/GL1.0/gl_stencil_func.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_func,
                     const GLint&   in_ref,
                     const GLuint&  in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glStencilFunc(GLenum func,
                                          GLint  ref,
                                          GLuint mask)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLStencilFunc(dispatch_table_ptr->bound_context_ptr,
                                       func,
                                       ref,
                                       mask);
}

void vkglStencilFunc_execute(VKGL::Context* in_context_ptr,
                             const GLenum&  in_func,
                             const GLint&   in_ref,
                             const GLuint&  in_mask)
{
    const auto func_vkgl = VKGL::Utils::get_stencil_function_for_gl_enum(in_func);

    in_context_ptr->set_stencil_function(func_vkgl,
                                         in_ref,
                                         in_mask);
}

void vkglStencilFunc_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_func,
                                     const GLint&   in_ref,
                                     const GLuint&  in_mask)
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