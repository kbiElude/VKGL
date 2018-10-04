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

    class Reference
    {
    public:
        /* Public functions */

        Reference(const GLuint&                                                         in_id,
                  const OpenGL::TimeMarker&                                             in_time_marker,
                  std::function<void(Reference*) >                                      in_on_reference_created_func,
                  std::function<void(Reference*) >                                      in_on_reference_destroyed_func,
                  std::function<OpenGL::ReferenceUniquePtr(GLuint, OpenGL::TimeMarker)> in_acquire_reference_func)
            :m_acquire_reference_func     (in_acquire_reference_func),
             m_id                         (in_id),
             m_on_reference_created_func  (in_on_reference_created_func),
             m_on_reference_destroyed_func(in_on_reference_destroyed_func),
             m_time_marker                (in_time_marker)
        {
            m_on_reference_created_func(this);
        }

        ~Reference();

        ReferenceUniquePtr clone() const;

        const GLuint& get_id() const
        {
            return m_id;
        }

        const OpenGL::TimeMarker& get_time_marker() const
        {
            return m_time_marker;
        }

        bool operator==(const Reference& in_ref) const
        {
            return (m_id          == in_ref.m_id          &&
                    m_time_marker == in_ref.m_time_marker);
        }

        bool operator!=(const Reference& in_ref) const
        {
            return (m_id          != in_ref.m_id          ||
                    m_time_marker != in_ref.m_time_marker);
        }
    private:

        Reference           (const Reference&);
        Reference& operator=(const Reference&);

        /* Private variables */
        const GLuint       m_id;
        OpenGL::TimeMarker m_time_marker;

        std::function<OpenGL::ReferenceUniquePtr(GLuint, OpenGL::TimeMarker)> m_acquire_reference_func;
        std::function<void(Reference*) >                                      m_on_reference_created_func;
        std::function<void(Reference*) >                                      m_on_reference_destroyed_func;
    };
}

#endif /* VKGL_GL_REFERENCE_H */