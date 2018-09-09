/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VAO_BINDING_H
#define VKGL_GL_VAO_BINDING_H

#include "OpenGL/types.h"
#include "OpenGL/gl_vao_manager.h"

namespace OpenGL
{
    class GLVAOBinding
    {
    public:
        ~GLVAOBinding();

        const GLuint& get_id() const
        {
            return m_id;
        }

    private:
        GLVAOBinding(const GLuint&                 in_id,
                     OpenGL::IGLVAOManagerRelease* in_vao_manager_ptr);

        GLVAOBindingUniquePtr create(const GLuint&                 in_id,
                                     OpenGL::IGLVAOManagerRelease* in_vao_manager_ptr);

        GLVAOBinding           (const GLVAOBinding&);
        GLVAOBinding& operator=(const GLVAOBinding&);

        /* Private variables */
        const GLuint                        m_id;
        OpenGL::IGLVAOManagerRelease* const m_vao_manager_ptr;

        friend class GLVAOManager;
    };
}
#endif /* VKGL_GL_VAO_MANAGER_H */