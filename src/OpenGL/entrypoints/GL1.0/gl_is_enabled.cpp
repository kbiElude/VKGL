/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_is_enabled.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_cap)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API GLboolean VKGL_APIENTRY vkglIsEnabled(GLenum cap)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsEnabled(dispatch_table_ptr->bound_context_ptr,
                                            cap);
}

GLboolean vkglIsEnabled_execute(VKGL::Context* in_context_ptr,
                                const GLenum&  in_cap)
{
    const auto cap_vkgl = VKGL::Utils::get_nonindexed_capability_for_gl_enum(in_cap);

    return (in_context_ptr->is_enabled(cap_vkgl) ) ? GL_TRUE
                                                   : GL_FALSE;
}

GLboolean vkglIsEnabled_with_validation(VKGL::Context* in_context_ptr,
                                        const GLenum&  in_cap)
{
    GLboolean result = GL_FALSE;

    if (validate(in_context_ptr,
                 in_cap) )
    {
        result = vkglIsEnabled_execute(in_context_ptr,
                                       in_cap);
    }

    return result;
}