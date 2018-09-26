/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_REFERENCE_H
#define VKGL_GL_REFERENCE_H

#include "Common/macros.h"
#include "OpenGL/types.h"
#include "OpenGL/types_interfaces.h"

namespace OpenGL
{
    class GLReference
    {
    public:
        GLReference(const GLuint&             in_id,
                    OpenGL::IGLObjectManager* in_manager_ptr)
            :m_id         (in_id),
             m_manager_ptr(in_manager_ptr)
        {
            vkgl_assert(m_manager_ptr != nullptr);
        }

        ~GLReference();

        GLReferenceUniquePtr clone() const;

        const GLuint& get_id() const
        {
            return m_id;
        }

        bool operator==(const GLReference& in_ref) const
        {
            return (m_id == in_ref.m_id);
        }

        bool operator!=(const GLReference& in_ref) const
        {
            return (m_id != in_ref.m_id);
        }
    private:
        std::unique_ptr<GLReference, std::function<void(GLReference*)> > create(const GLuint&             in_id,
                                                                                OpenGL::IGLObjectManager* in_manager_ptr)
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
        const GLuint                    m_id;
        OpenGL::IGLObjectManager* const m_manager_ptr;
    };
}

#endif /* VKGL_GL_REFERENCE_H */