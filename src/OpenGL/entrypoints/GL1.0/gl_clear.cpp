/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_clear.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLbitfield& in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglClear(GLbitfield mask)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLClear(dispatch_table_ptr->bound_context_ptr,
                                 mask);
}

void vkglClear_execute(VKGL::Context*    in_context_ptr,
                       const GLbitfield& in_mask)
{
    const auto clear_buffer_bits = VKGL::Utils::get_clear_buffer_bits_for_gl_enum(in_mask);

    in_context_ptr->clear(clear_buffer_bits);
}

void vkglClear_with_validation(VKGL::Context*    in_context_ptr,
                               const GLbitfield& in_mask)
{
    if (validate(in_context_ptr,
                 in_mask) )
    {
        vkglClear_execute(in_context_ptr,
                          in_mask);
    }
}