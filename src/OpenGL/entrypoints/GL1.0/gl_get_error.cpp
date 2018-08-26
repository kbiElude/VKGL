/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_error.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

GLenum VKGL_APIENTRY vkglGetError(void)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetError(dispatch_table_ptr->bound_context_ptr);
}

GLenum vkglGetError_with_validation(VKGL::Context* in_context_ptr)
{
    const auto error_vkgl = in_context_ptr->get_error();

    return VKGL::Utils::get_gl_enum_for_error_code(error_vkgl);
}