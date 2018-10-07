/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_REFERENCE_H
#define VKGL_GL_REFERENCE_H

#include "GL/glcorearb.h"
#include "OpenGL/reference.h"
#include <chrono>

namespace OpenGL
{
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

    typedef struct GLContextStatePayload
    {
        OpenGL::TimeMarker time_marker;

        const GLContextStatePayload(const OpenGL::TimeMarker& in_time_marker)
           :time_marker(in_time_marker)
        {
            /* Stub */
        }

        bool operator==(const GLContextStatePayload& in_ref) const
        {
            return (time_marker == in_ref.time_marker);
        }

        bool operator!=(const GLContextStatePayload& in_ref) const
        {
            return (time_marker != in_ref.time_marker);
        }
    } GLContextStatePayload;

    typedef ReferenceBase<GLPayload>             GLBufferReference;
    typedef ReferenceBase<GLContextStatePayload> GLContextStateReference;
    typedef ReferenceBase<GLPayload>             GLFramebufferReference;
    typedef ReferenceBase<GLPayload>             GLProgramReference;
    typedef ReferenceBase<GLPayload>             GLRenderbufferReference;
    typedef ReferenceBase<GLPayload>             GLShaderReference;
    typedef ReferenceBase<GLPayload>             GLTextureReference;
    typedef ReferenceBase<GLPayload>             GLVAOReference;
}

#endif /* VKGL_GL_REFERENCE_H */