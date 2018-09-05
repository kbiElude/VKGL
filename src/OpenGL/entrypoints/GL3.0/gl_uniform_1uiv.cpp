/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_uniform_1uiv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLint&     in_location,
                     const GLsizei&   in_count,
                     const GLuint*    in_value_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglUniform1uiv(GLint         location,
                                           GLsizei       count,
                                           const GLuint* value)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    /* TODO: Make me more useful */
    VKGL_TRACE("glUniform1uiv(location=[%d] count=[%d] value=[%p])",
               location,
               static_cast<int32_t>(count),
               value);

    dispatch_table_ptr->pGLUniform1uiv(dispatch_table_ptr->bound_context_ptr,
                                       location,
                                       count,
                                       value);
}

static void vkglUniform1uiv_execute(OpenGL::Context* in_context_ptr,
                                    const GLint&     in_location,
                                    const GLsizei&   in_count,
                                    const GLuint*    in_value_ptr)
{
    in_context_ptr->set_uniform(in_location,
                                OpenGL::GetSetArgumentType::Unsigned_Int,
                                1, /* in_n_components */
                                in_count,
                                in_value_ptr);
}

void OpenGL::vkglUniform1uiv_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLint&     in_location,
                                             const GLsizei&   in_count,
                                             const GLuint*    in_value_ptr)
{
    if (validate(in_context_ptr,
                 in_location,
                 in_count,
                 in_value_ptr) )
    {
        vkglUniform1uiv_execute(in_context_ptr,
                                in_location,
                                in_count,
                                in_value_ptr);
    }
}
