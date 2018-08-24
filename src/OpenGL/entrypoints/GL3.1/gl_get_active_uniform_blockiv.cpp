/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_blockiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_program,
                     const GLuint&  in_uniform_block_index,
                     const GLenum&  in_pname,
                     GLint*         out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglGetActiveUniformBlockiv(GLuint program,
                                                        GLuint uniformBlockIndex,
                                                        GLenum pname,
                                                        GLint* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetActiveUniformBlockiv(dispatch_table_ptr->bound_context_ptr,
                                                   program,
                                                   uniformBlockIndex,
                                                   pname,
                                                   params);
}

void vkglGetActiveUniformBlockiv_execute(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_program,
                                         const GLuint&  in_uniform_block_index,
                                         const GLenum&  in_pname,
                                         GLint*         out_params_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_uniform_block_property_for_gl_enum(in_pname);

    in_context_ptr->get_active_uniform_block_property(in_program,
                                                      in_uniform_block_index,
                                                      pname_vkgl,
                                                      VKGL::GetSetArgumentType::Int,
                                                      out_params_ptr);
}

void vkglGetActiveUniformBlockiv_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLuint&  in_program,
                                                 const GLuint&  in_uniform_block_index,
                                                 const GLenum&  in_pname,
                                                 GLint*         out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_program,
                 in_uniform_block_index,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetActiveUniformBlockiv_execute(in_context_ptr,
                                            in_program,
                                            in_uniform_block_index,
                                            in_pname,
                                            out_params_ptr);
    }
}
