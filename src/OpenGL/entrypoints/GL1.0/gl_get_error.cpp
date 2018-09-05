/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_error.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

GLenum VKGL_APIENTRY OpenGL::vkglGetError(void)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetError()");

    return dispatch_table_ptr->pGLGetError(dispatch_table_ptr->bound_context_ptr);
}

GLenum OpenGL::vkglGetError_with_validation(OpenGL::Context* in_context_ptr)
{
    const auto error_vkgl = in_context_ptr->get_error();

    return OpenGL::Utils::get_gl_enum_for_error_code(error_vkgl);
}