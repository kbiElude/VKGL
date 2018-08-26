/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_is_enabledi.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_target,
                     const GLuint&  in_index)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

GLboolean VKGL_APIENTRY vkglIsEnabledi(GLenum target,
                                       GLuint index)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLIsEnabledi(dispatch_table_ptr->bound_context_ptr,
                                             target,
                                             index);
}

GLboolean vkglIsEnabledi_execute(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_target,
                                 const GLuint&  in_index)
{
    vkgl_assert(in_target == GL_BLEND);

    return (in_context_ptr->is_enabledi(VKGL::Capability::Blend,
                                        in_index) ) ? GL_TRUE
                                                    : GL_FALSE;
}

GLboolean vkglIsEnabledi_with_validation(VKGL::Context* in_context_ptr,
                                         const GLenum&  in_target,
                                         const GLuint&  in_index)
{
    GLboolean result = GL_FALSE;

    if (validate(in_context_ptr,
                 in_target,
                 in_index) )
    {
        result = vkglIsEnabledi_execute(in_context_ptr,
                                        in_target,
                                        in_index);
    }

    return result;
}
