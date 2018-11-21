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

        Anvil::CompareOp     get_anvil_compare_op_for_depth_function        (const OpenGL::DepthFunction&        in_depth_func);
        Anvil::CompareOp     get_anvil_compare_op_for_stencil_function      (const OpenGL::StencilFunction&      in_stencil_func);
        Anvil::CullModeFlags get_anvil_cull_mode_flags_for_cull_face_mode   (const OpenGL::CullMode&             in_cull_face_mode);
        Anvil::FrontFace     get_anvil_front_face_for_front_face_orientation(const OpenGL::FrontFaceOrientation& in_front_face_orientation);
        Anvil::LogicOp       get_anvil_logic_op_for_logic_op_mode           (const OpenGL::LogicOpMode&          in_logic_op_mode);
        Anvil::PolygonMode   get_anvil_polygon_mode_for_polygon_mode        (const OpenGL::PolygonMode&          in_polygon_mode);
        Anvil::StencilOp     get_anvil_stencil_op_for_stencil_operation     (const OpenGL::StencilOperation&     in_stencil_op);
    }
}

#endif /* VKGL_VK_UTILS_H */