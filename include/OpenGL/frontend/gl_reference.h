/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_REFERENCE_H
#define VKGL_GL_REFERENCE_H

#include "GL/glcorearb.h"
#include "OpenGL/reference.h"

namespace OpenGL
{
    /* TODO: This is ugly since in a dire split of events a zero time marker may actually be reported for HP clock.
     *       The TimeMarker type should be extended to provide space for an additional flag telling "just use whatever's the latest"
     */
    typedef std::chrono::high_resolution_clock::time_point TimeMarker;

    extern const OpenGL::TimeMarker LATEST_SNAPSHOT_AVAILABLE;

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