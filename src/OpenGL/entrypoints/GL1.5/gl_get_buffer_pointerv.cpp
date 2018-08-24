/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_pointerv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLenum&  in_pname,
                     void**         out_params_ptr_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglGetBufferPointerv(GLenum target,
                                                  GLenum pname,
                                                  void** params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetBufferPointerv(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             pname,
                                             params);
}

void vkglGetBufferPointerv_execute(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_target,
                                   const GLenum&  in_pname,
                                   void**         out_params_ptr_ptr)
{
    const auto pname_vkgl  = VKGL::Utils::get_buffer_pointer_property_for_gl_enum(in_pname);
    const auto target_vkgl = VKGL::Utils::get_buffer_target_for_gl_enum          (in_target);

    in_context_ptr->get_buffer_pointerv(target_vkgl,
                                        pname_vkgl,
                                        out_params_ptr_ptr);
}

void vkglGetBufferPointerv_with_validation(VKGL::Context* in_context_ptr,
                                           const GLenum&  in_target,
                                           const GLenum&  in_pname,
                                           void**         out_params_ptr_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_pname,
                 out_params_ptr_ptr) )
    {
        vkglGetBufferPointerv_execute(in_context_ptr,
                                      in_target,
                                      in_pname,
                                      out_params_ptr_ptr);
    }
}
