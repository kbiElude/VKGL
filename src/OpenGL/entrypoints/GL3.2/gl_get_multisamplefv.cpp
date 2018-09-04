/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_get_multisamplefv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_pname,
                     const GLuint&    in_index,
                     GLfloat*         out_val_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglGetMultisamplefv(GLenum   pname,
                                                GLuint   index,
                                                GLfloat* val)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glGetMultisamplefv(pname=[%s] index=[%u] val=[%p])",
               OpenGL::Utils::get_raw_string_for_gl_enum(pname),
               index,
               val);

    dispatch_table_ptr->pGLGetMultisamplefv(dispatch_table_ptr->bound_context_ptr,
                                            pname,
                                            index,
                                            val);
}

static void vkglGetMultisamplefv_execute(OpenGL::Context* in_context_ptr,
                                         const GLenum&    in_pname,
                                         const GLuint&    in_index,
                                         GLfloat*         out_val_ptr)
{
    vkgl_assert(in_pname == GL_SAMPLE_POSITION);

    in_context_ptr->get_sample_position(in_index,
                                        out_val_ptr);
}

void OpenGL::vkglGetMultisamplefv_with_validation(OpenGL::Context* in_context_ptr,
                                                  const GLenum&    in_pname,
                                                  const GLuint&    in_index,
                                                  GLfloat*         out_val_ptr)
{
    if (validate(in_context_ptr,
                 in_pname,
                 in_index,
                 out_val_ptr) )
    {
        vkglGetMultisamplefv_execute(in_context_ptr,
                                     in_pname,
                                     in_index,
                                     out_val_ptr);
    }
}
