/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/types.h"
#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/gl_reference.h"

const OpenGL::TimeMarker OpenGL::LATEST_SNAPSHOT_AVAILABLE = OpenGL::TimeMarker(std::chrono::nanoseconds(0) );


OpenGL::GLReference::~GLReference()
{
    if (m_on_reference_destroyed_func != nullptr)
    {
        m_on_reference_destroyed_func(this);
    }
}

OpenGL::GLReferenceUniquePtr OpenGL::GLReference::clone() const
{
    /* When cloning, make sure to create a reference that points to exactly the same snapshot
     * of the same object this reference is pointing at!
     */
    return m_acquire_reference_func(m_id,
                                    m_time_marker);
}