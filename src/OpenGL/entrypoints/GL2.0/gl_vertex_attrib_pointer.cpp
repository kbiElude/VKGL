/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_pointer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLuint&    in_index,
                     const GLint&     in_size,
                     const GLenum&    in_type,
                     const GLboolean& in_normalized,
                     const GLsizei&   in_stride,
                     const void*      in_pointer_ptr)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglVertexAttribPointer(GLuint      index,
                                                   GLint       size,
                                                   GLenum      type,
                                                   GLboolean   normalized,
                                                   GLsizei     stride,
                                                   const void* pointer)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glVertexAttribPointer(index=[%u] size=[%d] type=[%s] normalized=[%d] stride=[%d] pointer=[%p])",
               index,
               size,
               OpenGL::Utils::get_raw_string_for_gl_enum(type),
               (normalized == GL_TRUE) ? 1 : 0,
               static_cast<int32_t>(stride),
               pointer);

    dispatch_table_ptr->pGLVertexAttribPointer(dispatch_table_ptr->bound_context_ptr,
                                               index,
                                               size,
                                               type,
                                               normalized,
                                               stride,
                                               pointer);
}

static void vkglVertexAttribPointer_execute(OpenGL::Context* in_context_ptr,
                                            const GLuint&    in_index,
                                            const GLint&     in_size,
                                            const GLenum&    in_type,
                                            const GLboolean& in_normalized,
                                            const GLsizei&   in_stride,
                                            const void*      in_pointer_ptr)
{
    const auto type_vkgl = OpenGL::Utils::get_vertex_attribute_array_type_for_gl_enum(in_type);

    in_context_ptr->set_vertex_attrib_pointer(in_index,
                                              in_size,
                                              type_vkgl,
                                              OpenGL::GetSetArgumentType::Float,
                                              in_normalized == GL_TRUE,
                                              in_stride,
                                              in_pointer_ptr);
}

void OpenGL::vkglVertexAttribPointer_with_validation(OpenGL::Context* in_context_ptr,
                                                     const GLuint&    in_index,
                                                     const GLint&     in_size,
                                                     const GLenum&    in_type,
                                                     const GLboolean& in_normalized,
                                                     const GLsizei&   in_stride,
                                                     const void*      in_pointer_ptr)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_size,
                 in_type,
                 in_normalized,
                 in_stride,
                 in_pointer_ptr) )
    {
        vkglVertexAttribPointer_execute(in_context_ptr,
                                        in_index,
                                        in_size,
                                        in_type,
                                        in_normalized,
                                        in_stride,
                                        in_pointer_ptr);
    }
}
