/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterfv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_pname,
                     const GLfloat*   in_params)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglPointParameterfv(GLenum         pname,
                                                const GLfloat* params)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointParameterfv(dispatch_table_ptr->bound_context_ptr,
                                            pname,
                                            params);
}

static void vkglPointParameterfv_execute(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_pname,
                                         const GLfloat*   in_params)
{
    const auto pname_vkgl = OpenGL::Utils::get_point_property_for_gl_enum(in_pname);

    in_context_ptr->set_point_property(pname_vkgl,
                                       OpenGL::GetSetArgumentType::Float,
                                       in_params);
}

void OpenGL::vkglPointParameterfv_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLenum&    in_pname,
                                                  const GLfloat*   in_params)
{
    if (validate(in_context_ptr,
                 in_pname,
                 in_params) )
    {
        vkglPointParameterfv_execute(in_context_ptr,
                                     in_pname,
                                     in_params);
    }
}

