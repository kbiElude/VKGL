/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_get_booleani_v.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_target,
                     const GLuint&    in_index,
                     GLboolean*       out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetBooleani_v(GLenum     target,
                                             GLuint     index,
                                             GLboolean* data)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetBooleani_v(target=[%s] index=[%u] data=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(target),
               index,
               data);

    dispatch_table_ptr->pGLGetBooleani_v(dispatch_table_ptr->bound_context_ptr,
                                         target,
                                         index,
                                         data);
}

static void vkglGetBooleani_v_execute(OpenGL::Context* in_context_ptr,
                                      const GLenum&    in_target,
                                      const GLuint&    in_index,
                                      GLboolean*       out_data_ptr)
{
    const OpenGL::ContextProperty target_vkgl = OpenGL::Utils::get_context_property_for_gl_enum(in_target);

    in_context_ptr->get_parameter_indexed(target_vkgl,
                                          OpenGL::GetSetArgumentType::Boolean,
                                          out_data_ptr);
}

void OpenGL::vkglGetBooleani_v_with_validation(OpenGL::Context* in_context_ptr,
                                               const GLenum&    in_target,
                                               const GLuint&    in_index,
                                               GLboolean*       out_data_ptr)
{
    if (validate(in_context_ptr,
                 in_target,
                 in_index,
                 out_data_ptr) )
    {
        vkglGetBooleani_v_execute(in_context_ptr,
                                  in_target,
                                  in_index,
                                  out_data_ptr);
    }
}
