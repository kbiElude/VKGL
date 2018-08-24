/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attrib_pointerv.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLenum&  in_pname,
                     void**         out_pointer_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY vkglGetVertexAttribPointerv(GLuint index,
                                                        GLenum pname,
                                                        void** pointer)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLGetVertexAttribPointer(dispatch_table_ptr->bound_context_ptr,
                                                  index,
                                                  pname,
                                                  pointer);
}

void vkglGetVertexAttribPointerv_execute(VKGL::Context* in_context_ptr,
                                         const GLuint&  in_index,
                                         const GLenum&  in_pname,
                                         void**         out_pointer_ptr)
{
    const auto pname_vkgl = VKGL::Utils::get_vertex_attribute_pointer_property_for_gl_enum(in_pname);

    in_context_ptr->get_vertex_attrib_pointer_property(in_index,
                                                       pname_vkgl,
                                                       out_pointer_ptr);
}

void vkglGetVertexAttribPointerv_with_validation(VKGL::Context* in_context_ptr,
                                                 const GLuint&  in_index,
                                                 const GLenum&  in_pname,
                                                 void**         out_pointer_ptr)
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
