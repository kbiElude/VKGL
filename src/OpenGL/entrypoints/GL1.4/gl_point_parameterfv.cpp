/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterfv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     const GLfloat* in_params)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglPointParameterfv(GLenum         pname,
                                                 const GLfloat* params)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPointParameterfv(dispatch_table_ptr->bound_context_ptr,
                                            pname,
                                            params);
}

void vkglPointParameterfv_execute(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_pname,
                                  const GLfloat* in_params)
{
    const auto pname_vkgl = VKGL::Utils::get_point_property_for_gl_enum(in_pname);

    in_context_ptr->set_point_property(pname_vkgl,
                                       VKGL::GetSetArgumentType::Float,
                                       in_params);
}

void vkglPointParameterfv_with_validation(VKGL::Context* in_context_ptr,
                                          const GLenum&  in_pname,
                                          const GLfloat* in_params)
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

