/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/gl_vao_binding.h"

OpenGL::GLVAOBinding::GLVAOBinding(const GLuint&                 in_id,
                                   OpenGL::IGLVAOManagerRelease* in_vao_manager_ptr)
    :m_id             (in_id),
     m_vao_manager_ptr(in_vao_manager_ptr)
{
    vkgl_assert(m_vao_manager_ptr != nullptr);
}

OpenGL::GLVAOBinding::~GLVAOBinding()
{
    m_vao_manager_ptr->release_vao(this);
}

OpenGL::GLVAOBindingUniquePtr OpenGL::GLVAOBinding::create(const GLuint&                 in_id,
                                                           OpenGL::IGLVAOManagerRelease* in_vao_manager_ptr)
{
    OpenGL::GLVAOBindingUniquePtr result_ptr;

    result_ptr.reset(
        new OpenGL::GLVAOBinding(in_id,
                                 in_vao_manager_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}
