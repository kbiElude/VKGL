/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_UTILS_H
#define VKGL_VK_UTILS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    namespace VKUtils
    {
        Anvil::BufferUsageFlags   get_buffer_usage_flags_for_gl_buffer  (const uint32_t&             in_n_buffer_targets,
                                                                         const OpenGL::BufferTarget* in_buffer_targets_ptr);
        Anvil::MemoryFeatureFlags get_memory_feature_flags_for_gl_buffer(const OpenGL::BufferUsage&  in_buffer_usage);
    }
}

#endif /* VKGL_VK_UTILS_H */