/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_get_buffer_parameteri64v.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     GLint64*       out_params_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY vkglGetBufferParameteri64v(GLenum   target,
                                                       GLenum   pname,
                                                       GLint64* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetBufferParameteri64v(dispatch_table_ptr->bound_context_ptr,
                                                  target,
                                                  pname,
                                                  params);
}

void vkglGetBufferParameteri64v_execute(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_target,
                                        const GLenum&  in_pname,
                                        GLint64*       out_params_ptr)
{
    const auto pname_vkgl  = VKGL::Utils::get_buffer_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_buffer_target_for_gl_enum  (in_target);

    in_context_ptr->get_buffer_property(target_vkgl,
                                        pname_vkgl,
                                        VKGL::GetSetArgumentType::Int64,
                                        1,
                                        out_params_ptr);
}

void vkglGetBufferParameteri64v_with_validation(VKGL::Context* in_context_ptr,
                                                const GLenum&  in_target,
                                                const GLenum&  in_pname,
                                                GLint64*       out_params_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 out_params_ptr) )
    {
        vkglGetBufferParameteri64v_execute(in_context_ptr,
                                           in_target,
                                           in_pname,
                                           out_params_ptr);
    }
}
