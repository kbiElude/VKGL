/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_stringi.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_name,
                     const GLuint&  in_index)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

const GLubyte *APIENTRY OpenGL::vkglGetStringi(GLenum name,
                                               GLuint index)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetStringi(dispatch_table_ptr->bound_context_ptr,
                                             name,
                                             index);
}

static const GLubyte* vkglGetStringi_execute(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_name,
                                             const GLuint&  in_index)
{
    const auto     name_vkgl  = VKGL::Utils::get_context_property_for_gl_enum(in_name);
    const GLubyte* result_ptr = nullptr;

    in_context_ptr->get_parameter_indexed(name_vkgl,
                                          VKGL::GetSetArgumentType::String,
                                          in_index,
                                         &result_ptr);

    return result_ptr;
}

const GLubyte* OpenGL::vkglGetStringi_with_validation(VKGL::Context* in_context_ptr,
                                                      const GLenum&  in_name,
                                                      const GLuint&  in_index)
{
    const GLubyte* result_ptr = nullptr;

    if (validate(in_context_ptr,
                 in_name,
                 in_index) )
    {
        result_ptr = vkglGetStringi_execute(in_context_ptr,
                                            in_name,
                                            in_index);
    }

    return result_ptr;
}