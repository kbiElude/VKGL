/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.1/gl_get_pointerv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     void**         in_params)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glGetPointerv(GLenum pname,
                                          void** params)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetPointerv(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       params);
}

void vkglGetPointerv_execute(VKGL::Context* in_context_ptr,
                             const GLenum&  in_pname,
                             void**         in_params)
{
    const auto pname_vkgl = VKGL::Utils::get_context_property_for_gl_enum(in_pname);

    in_context_ptr->get_pointerv(pname_vkgl,
                                 in_params);
}

void vkglGetPointerv_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_pname,
                                     void**         in_params)
{
    if (validate(in_context_ptr,
                 in_pname,
                 in_params) )
    {
        vkglGetPointerv_execute(in_context_ptr,
                                in_pname,
                                in_params);
    }
}
