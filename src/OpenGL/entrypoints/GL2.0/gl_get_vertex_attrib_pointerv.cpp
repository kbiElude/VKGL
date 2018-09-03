/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attrib_pointerv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLenum&    in_pname,
                     void**           out_pointer_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglGetVertexAttribPointerv(GLuint index,
                                                       GLenum pname,
                                                       void** pointer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetVertexAttribPointer(dispatch_table_ptr->bound_context_ptr,
                                                  index,
                                                  pname,
                                                  pointer);
}

static void vkglGetVertexAttribPointerv_execute(OpenGL::Context* in_context_ptr,
                                                const GLuint&    in_index,
                                                const GLenum&    in_pname,
                                                void**           out_pointer_ptr)
{
    const auto pname_vkgl = OpenGL::Utils::get_vertex_attribute_pointer_property_for_gl_enum(in_pname);

    in_context_ptr->get_vertex_attrib_pointer_property(in_index,
                                                       pname_vkgl,
                                                       out_pointer_ptr);
}

void OpenGL::vkglGetVertexAttribPointerv_with_validation(OpenGL::Context* in_context_ptr,
                                                         const GLuint&    in_index,
                                                         const GLenum&    in_pname,
                                                         void**           out_pointer_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_pname,
                 out_pointer_ptr) )
    {
        vkglGetVertexAttribPointerv_execute(in_context_ptr,
                                            in_index,
                                            in_pname,
                                            out_pointer_ptr);
    }
}
