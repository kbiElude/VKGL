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
    /* TODO: This is ugly since in a dire split of events a zero time marker may actually be reported for HP clock.
     *       The TimeMarker type should be extended to provide space for an additional flag telling "just use whatever's the latest"
     */
    extern const OpenGL::TimeMarker LATEST_SNAPSHOT_AVAILABLE;

    class GLReference
    {
    public:
        /* Public functions */
        /* NOTE: References created using this constructor can be passed to backend. */
        GLReference(const GLuint&                    in_id,
                    const OpenGL::TimeMarker&        in_time_marker,
                    OpenGL::IObjectManagerReference* in_manager_ptr)
            :m_id         (in_id),
             m_manager_ptr(in_manager_ptr),
             m_time_marker(in_time_marker)
        {
            vkgl_assert(m_manager_ptr != nullptr);

            m_manager_ptr->on_reference_created(this);
        }

        ~GLReference();

        GLReferenceUniquePtr clone() const;

        const GLuint& get_id() const
        {
            return m_id;
        }

        const OpenGL::TimeMarker& get_time_marker() const
        {
            return m_time_marker;
        }

        bool operator==(const GLReference& in_ref) const
        {
            return (m_id          == in_ref.m_id          &&
                    m_time_marker == in_ref.m_time_marker);
        }

        bool operator!=(const GLReference& in_ref) const
        {
            return (m_id          != in_ref.m_id          ||
                    m_time_marker != in_ref.m_time_marker);
        }
    private:
#if 0
        std::unique_ptr<GLReference, std::function<void(GLReference*)> > create(const GLuint&             in_id,
                                                                                const OpenGL::TimeMarker& in_time_marker,
                                                                                OpenGL::IGLObjectManager* in_manager_ptr)
        {
            std::unique_ptr<GLReference, std::function<void(GLReference*)> > result_ptr;

            result_ptr.reset(
                new OpenGL::GLReference(in_id,
                                        in_time_marker,
                                        in_manager_ptr)
            );

            vkgl_assert(result_ptr != nullptr);
            return result_ptr;
        }
#endif

        GLReference           (const GLReference&);
        GLReference& operator=(const GLReference&);

        /* Private variables */
        const GLuint                           m_id;
        OpenGL::IObjectManagerReference* const m_manager_ptr;
        OpenGL::TimeMarker                     m_time_marker;
    };
}

#endif /* VKGL_GL_REFERENCE_H */