/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_pointer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*   in_context_ptr,
                     const GLuint&    in_index,
                     const GLint&     in_size,
                     const GLenum&    in_type,
                     const GLsizei&   in_stride,
                     const void*      in_pointer_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglVertexAttribIPointer(GLuint      index,
                                                    GLint       size,
                                                    GLenum      type,
                                                    GLsizei     stride,
                                                    const void* pointer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttribIPointer(dispatch_table_ptr->bound_context_ptr,
                                                index,
                                                size,
                                                type,
                                                stride,
                                                pointer);
}

static void vkglVertexAttribIPointer_execute(VKGL::Context*   in_context_ptr,
                                             const GLuint&    in_index,
                                             const GLint&     in_size,
                                             const GLenum&    in_type,
                                             const GLsizei&   in_stride,
                                             const void*      in_pointer_ptr)
{
    const auto type_vkgl = VKGL::Utils::get_variable_type_for_gl_enum(in_type);

    in_context_ptr->set_vertex_attrib_pointer(in_index,
                                              in_size,
                                              type_vkgl,
                                              VKGL::GetSetArgumentType::Int,
                                              false, /* in_normalized */
                                              in_stride,
                                              in_pointer_ptr);
}

void OpenGL::vkglVertexAttribIPointer_with_validation(VKGL::Context*   in_context_ptr,
                                                      const GLuint&    in_index,
                                                      const GLint&     in_size,
                                                      const GLenum&    in_type,
                                                      const GLsizei&   in_stride,
                                                      const void*      in_pointer_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_size,
                 in_type,
                 in_stride,
                 in_pointer_ptr) )
    {
        vkglVertexAttribIPointer_execute(in_context_ptr,
                                        in_index,
                                        in_size,
                                        in_type,
                                        in_stride,
                                        in_pointer_ptr);
    }
}
