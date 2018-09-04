/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_pixel_storei.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_pname,
                     const GLint&     in_param)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglPixelStorei(GLenum pname,
                                           GLint  param)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glPixelStorei(pname=[%s] param=[%d])",
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               param);

    dispatch_table_ptr->pGLPixelStorei(dispatch_table_ptr->bound_context_ptr,
                                       pname,
                                       param);
}

static void vkglPixelStorei_execute(OpenGL::Context* in_context_ptr,
                                    const GLenum&    in_pname,
                                    const GLint&     in_param)
{
    const auto pname_vkgl = OpenGL::Utils::get_pixel_store_property_for_gl_enum(in_pname);

    in_context_ptr->set_pixel_store_property(pname_vkgl,
                                             OpenGL::GetSetArgumentType::Int,
                                            &in_param);
}

void OpenGL::vkglPixelStorei_with_validation(OpenGL::Context* in_context_ptr,
                                             const GLenum&    in_pname,
                                             const GLint&     in_param)
{
    if (validate(in_context_ptr,
                 in_pname,
                 in_param) )
    {
        vkglPixelStorei_execute(in_context_ptr,
                                in_pname,
                                in_param);
    }
}