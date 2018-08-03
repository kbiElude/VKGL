/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_get_string.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_name)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API const GLubyte *APIENTRY glGetString(GLenum name)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetString(dispatch_table_ptr->bound_context_ptr,
                                            name);
}

const GLubyte* vkglGetString_execute(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_name)
{
    const auto     name_vkgl  = VKGL::Utils::get_context_property_for_gl_enum(in_name);
    const GLubyte* result_ptr = nullptr;

    in_context_ptr->get_parameter(name_vkgl,
                                  VKGL::GetSetArgumentType::String,
                                 &result_ptr);

    return result_ptr;
}

const GLubyte* vkglGetString_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_name)
{
    const GLubyte* result_ptr = nullptr;

    if (validate(in_context_ptr,
                 in_name) )
    {
        result_ptr = vkglGetString_execute(in_context_ptr,
                                           in_name);
    }

    return result_ptr;
}