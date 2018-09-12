/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/types.h"
#include "OpenGL/gl_object_manager.h"
#include "OpenGL/gl_reference.h"

OpenGL::GLReference::~GLReference()
{
    dynamic_cast<IObjectManagerReferenceRelease*>(m_manager_ptr)->release_reference(this);
}

OpenGL::GLReferenceUniquePtr OpenGL::GLReference::clone() const
{
    return m_manager_ptr->acquire_reference(m_id);
}