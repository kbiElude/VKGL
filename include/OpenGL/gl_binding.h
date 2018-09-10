/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BINDING_H
#define VKGL_GL_BINDING_H

#include "OpenGL/types.h"
#include "OpenGL/types_interfaces.h"

namespace OpenGL
{
    class GLBinding
    {
    public:
        GLBinding(const GLuint&                         in_id,
                  OpenGL::IObjectManagerBindingRelease* in_manager_ptr)
            :m_id         (in_id),
             m_manager_ptr(in_manager_ptr)
        {
            vkgl_assert(m_manager_ptr != nullptr);
        }

        ~GLBinding()
        {
            m_manager_ptr->release_binding(this);
        }

        const GLuint& get_id() const
        {
            return m_id;
        }

    private:
        std::unique_ptr<GLBinding, std::function<void(GLBinding*)> > create(const GLuint&                         in_id,
                                                                            OpenGL::IObjectManagerBindingRelease* in_manager_ptr)
        {
            std::unique_ptr<GLBinding, std::function<void(GLBinding*)> > result_ptr;

            result_ptr.reset(
                new OpenGL::GLBinding(in_id,
                                      in_manager_ptr)
            );

            vkgl_assert(result_ptr != nullptr);
            return result_ptr;
        }

        GLBinding           (const GLBinding&);
        GLBinding& operator=(const GLBinding&);

        /* Private variables */
        const GLuint                                m_id;
        OpenGL::IObjectManagerBindingRelease* const m_manager_ptr;
    };

    typedef std::unique_ptr<GLBinding, std::function<void(GLBinding*)> > GLBindingUniquePtr;
}

#endif /* VKGL_GL_BINDING_H */