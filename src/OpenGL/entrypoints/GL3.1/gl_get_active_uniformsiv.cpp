/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniformsiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLsizei& in_uniform_count,
                     const GLuint*  in_uniform_indices_ptr,
                     const GLenum&  in_pname,
                     GLint*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglGetActiveUniformsiv(GLuint        program,
                                           GLsizei       uniformCount,
                                           const GLuint* uniformIndices,
                                           GLenum        pname,
                                           GLint*        params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetActiveUniformsiv(dispatch_table_ptr->bound_context_ptr,
                                               program,
                                               uniformCount,
                                               uniformIndices,
                                               pname,
                                               params);
}

void vkglGetActiveUniformsiv_execute(VKGL::Context* in_context_ptr,
                                     const GLuint&  in_program,
                                     const GLsizei& in_uniform_count,
                                     const GLuint*  in_uniform_indices_ptr,
                                     const GLenum&  in_pname,
                                     GLint*         out_params_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_uniform_property_for_gl_enum(in_pname);

    in_context_ptr->get_active_uniforms(in_program,
                                        in_uniform_count,
                                        in_uniform_indices_ptr,
                                        pname_vkgl,
                                        out_params_ptr);
}

void vkglGetActiveUniformsiv_with_validation(VKGL::Context* in_context_ptr,
                                             const GLuint&  in_program,
                                             const GLsizei& in_uniform_count,
                                             const GLuint*  in_uniform_indices_ptr,
                                             const GLenum&  in_pname,
                                             GLint*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_count,
                 in_uniform_indices_ptr,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetActiveUniformsiv_execute(in_context_ptr,
                                        in_program,
                                        in_uniform_count,
                                        in_uniform_indices_ptr,
                                        in_pname,
                                        out_params_ptr);
    }
}
