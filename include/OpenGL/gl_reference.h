/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_REFERENCE_H
#define VKGL_GL_REFERENCE_H

#include "OpenGL/types.h"
#include "OpenGL/types_interfaces.h"

namespace OpenGL
{
    class GLReference
    {
    public:
        GLReference(const GLuint&                           in_id,
                    OpenGL::IObjectManagerReferenceRelease* in_manager_ptr)
            :m_id         (in_id),
             m_manager_ptr(in_manager_ptr)
        {
            vkgl_assert(m_manager_ptr != nullptr);
        }

        ~GLReference()
        {
            m_manager_ptr->release_reference(this);
        }

        const GLuint& get_id() const
        {
            return m_id;
        }

    private:
        std::unique_ptr<GLReference, std::function<void(GLReference*)> > create(const GLuint&                           in_id,
                                                                                OpenGL::IObjectManagerReferenceRelease* in_manager_ptr)
        {
            std::unique_ptr<GLReference, std::function<void(GLReference*)> > result_ptr;

            result_ptr.reset(
                new OpenGL::GLReference(in_id,
                                        in_manager_ptr)
            );

            vkgl_assert(result_ptr != nullptr);
            return result_ptr;
        }

        GLReference           (const GLReference&);
        GLReference& operator=(const GLReference&);

        /* Private variables */
        const GLuint                                  m_id;
        OpenGL::IObjectManagerReferenceRelease* const m_manager_ptr;
    };

    typedef std::unique_ptr<GLReference, std::function<void(GLReference*)> > GLReferenceUniquePtr;
}

#endif /* VKGL_GL_REFERENCE_H */