/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_REFERENCE_H
#define VKGL_GL_REFERENCE_H

#include "GL/glcorearb.h"
#include <chrono>
#include <functional>
#include <memory>


namespace OpenGL
{
    /* TODO: This is ugly since in a dire split of events a zero time marker may actually be reported for HP clock.
     *       The TimeMarker type should be extended to provide space for an additional flag telling "just use whatever's the latest"
     */
    typedef std::chrono::high_resolution_clock::time_point TimeMarker;

    extern const OpenGL::TimeMarker LATEST_SNAPSHOT_AVAILABLE;

    template<typename Payload>
    class ReferenceBase
    {
    public:
        /* Public functions */

        typedef std::unique_ptr<ReferenceBase<Payload>, std::function<void(ReferenceBase<Payload>*)> > ReferenceUniquePtr;

        ReferenceBase(const Payload&                                                in_payload,
                      std::function<void(ReferenceBase<Payload>*) >                 in_on_reference_created_func,
                      std::function<void(ReferenceBase<Payload>*) >                 in_on_reference_destroyed_func,
                      std::function<ReferenceUniquePtr(GLuint, OpenGL::TimeMarker)> in_acquire_reference_func)
            :m_acquire_reference_func     (in_acquire_reference_func),
             m_on_reference_created_func  (in_on_reference_created_func),
             m_on_reference_destroyed_func(in_on_reference_destroyed_func),
             m_payload                    (in_payload)
        {
            m_on_reference_created_func(this);
        }

        ~ReferenceBase()
        {
            if (m_on_reference_destroyed_func != nullptr)
            {
                m_on_reference_destroyed_func(this);
            }
        }

        ReferenceUniquePtr clone() const
        {
            /* When cloning, make sure to create a reference that points to exactly the same snapshot
             * of the same object this reference is pointing at!
             */
            return m_acquire_reference_func(m_payload.id,
                                            m_payload.time_marker);
        }

        const Payload& get_payload() const
        {
            return m_payload;
        }

        bool operator==(const ReferenceBase<Payload>& in_ref) const
        {
            return (m_payload == in_ref.m_payload);
        }

        bool operator!=(const ReferenceBase<Payload>& in_ref) const
        {
            return (m_payload != in_ref.m_payload);
        }
    private:

        ReferenceBase<Payload>           (const ReferenceBase<Payload>&);
        ReferenceBase<Payload>& operator=(const ReferenceBase<Payload>&);

        /* Private variables */
        std::function<ReferenceUniquePtr(GLuint, OpenGL::TimeMarker)> m_acquire_reference_func;
        std::function<void(ReferenceBase<Payload>*) >                 m_on_reference_created_func;
        std::function<void(ReferenceBase<Payload>*) >                 m_on_reference_destroyed_func;

        const Payload m_payload;
    };

    typedef struct GLPayload
    {
        GLuint             id;
        OpenGL::TimeMarker time_marker;

        const GLPayload(const GLuint&             in_id,
                        const OpenGL::TimeMarker& in_time_marker)
           :id         (in_id),
            time_marker(in_time_marker)
        {
            /* Stub */
        }

        bool operator==(const GLPayload& in_ref) const
        {
            return (id          == in_ref.id          &&
                    time_marker == in_ref.time_marker);
        }

        bool operator!=(const GLPayload& in_ref) const
        {
            return (id          != in_ref.id          ||
                    time_marker != in_ref.time_marker);
        }
    } GLPayload;

    typedef ReferenceBase<GLPayload> Reference;
}

#endif /* VKGL_GL_REFERENCE_H */