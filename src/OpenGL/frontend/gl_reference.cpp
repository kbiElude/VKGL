/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/types.h"
#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/gl_reference.h"

const OpenGL::TimeMarker OpenGL::LATEST_SNAPSHOT_AVAILABLE = OpenGL::TimeMarker(std::chrono::nanoseconds(0) );
