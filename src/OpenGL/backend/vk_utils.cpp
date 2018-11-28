/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/backend/vk_utils.h"

Anvil::CompareOp OpenGL::VKUtils::get_anvil_compare_op_for_depth_function(const OpenGL::DepthFunction& in_depth_func)
{
    Anvil::CompareOp result = Anvil::CompareOp::UNKNOWN;

    switch (in_depth_func)
    {
        case OpenGL::DepthFunction::Always:   result = Anvil::CompareOp::ALWAYS;           break;
        case OpenGL::DepthFunction::Equal:    result = Anvil::CompareOp::EQUAL;            break;
        case OpenGL::DepthFunction::GEqual:   result = Anvil::CompareOp::GREATER_OR_EQUAL; break;
        case OpenGL::DepthFunction::Greater:  result = Anvil::CompareOp::GREATER;          break;
        case OpenGL::DepthFunction::LEqual:   result = Anvil::CompareOp::LESS_OR_EQUAL;    break;
        case OpenGL::DepthFunction::Less:     result = Anvil::CompareOp::LESS;             break;
        case OpenGL::DepthFunction::Never:    result = Anvil::CompareOp::NEVER;            break;
        case OpenGL::DepthFunction::NotEqual: result = Anvil::CompareOp::NOT_EQUAL;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::CompareOp OpenGL::VKUtils::get_anvil_compare_op_for_stencil_function(const OpenGL::StencilFunction& in_stencil_func)
{
    Anvil::CompareOp result = Anvil::CompareOp::UNKNOWN;

    switch (in_stencil_func)
    {
        case OpenGL::StencilFunction::Always:   result = Anvil::CompareOp::ALWAYS;           break;
        case OpenGL::StencilFunction::Equal:    result = Anvil::CompareOp::EQUAL;            break;
        case OpenGL::StencilFunction::GEqual:   result = Anvil::CompareOp::GREATER_OR_EQUAL; break;
        case OpenGL::StencilFunction::Greater:  result = Anvil::CompareOp::GREATER;          break;
        case OpenGL::StencilFunction::LEqual:   result = Anvil::CompareOp::LESS_OR_EQUAL;    break;
        case OpenGL::StencilFunction::Less:     result = Anvil::CompareOp::LESS;             break;
        case OpenGL::StencilFunction::Never:    result = Anvil::CompareOp::NEVER;            break;
        case OpenGL::StencilFunction::NotEqual: result = Anvil::CompareOp::NOT_EQUAL;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::CullModeFlags OpenGL::VKUtils::get_anvil_cull_mode_flags_for_cull_face_mode(const OpenGL::CullMode& in_cull_face_mode)
{
    Anvil::CullModeFlags result = Anvil::CullModeFlagBits::NONE;

    switch (in_cull_face_mode)
    {
        case OpenGL::CullMode::Back:       result = Anvil::CullModeFlagBits::BACK_BIT;       break;
        case OpenGL::CullMode::Front:      result = Anvil::CullModeFlagBits::FRONT_AND_BACK; break;
        case OpenGL::CullMode::Front_Back: result = Anvil::CullModeFlagBits::FRONT_BIT;      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::FrontFace OpenGL::VKUtils::get_anvil_front_face_for_front_face_orientation(const OpenGL::FrontFaceOrientation& in_front_face_orientation)
{
    Anvil::FrontFace result = Anvil::FrontFace::UNKNOWN;

    switch (in_front_face_orientation)
    {
        case OpenGL::FrontFaceOrientation::Clockwise:         result = Anvil::FrontFace::CLOCKWISE;         break;
        case OpenGL::FrontFaceOrientation::Counter_Clockwise: result = Anvil::FrontFace::COUNTER_CLOCKWISE; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::LogicOp OpenGL::VKUtils::get_anvil_logic_op_for_logic_op_mode(const OpenGL::LogicOpMode& in_logic_op_mode)
{
    Anvil::LogicOp result = Anvil::LogicOp::UNKNOWN;

    switch (in_logic_op_mode)
    {
        case OpenGL::LogicOpMode::And:           result = Anvil::LogicOp::AND;           break;
        case OpenGL::LogicOpMode::And_Inverted:  result = Anvil::LogicOp::AND_INVERTED;  break;
        case OpenGL::LogicOpMode::And_Reverse:   result = Anvil::LogicOp::AND_REVERSE;   break;
        case OpenGL::LogicOpMode::Clear:         result = Anvil::LogicOp::CLEAR;         break;
        case OpenGL::LogicOpMode::Copy:          result = Anvil::LogicOp::COPY;          break;
        case OpenGL::LogicOpMode::Copy_Inverted: result = Anvil::LogicOp::COPY_INVERTED; break;
        case OpenGL::LogicOpMode::Equiv:         result = Anvil::LogicOp::EQUIVALENT;    break;
        case OpenGL::LogicOpMode::Invert:        result = Anvil::LogicOp::INVERT;        break;
        case OpenGL::LogicOpMode::Nand:          result = Anvil::LogicOp::NAND;          break;
        case OpenGL::LogicOpMode::Noop:          result = Anvil::LogicOp::NO_OP;         break;
        case OpenGL::LogicOpMode::Nor:           result = Anvil::LogicOp::NOR;           break;
        case OpenGL::LogicOpMode::Or:            result = Anvil::LogicOp::OR;            break;
        case OpenGL::LogicOpMode::Or_Inverted:   result = Anvil::LogicOp::OR_INVERTED;   break;
        case OpenGL::LogicOpMode::Or_Reverse:    result = Anvil::LogicOp::OR_REVERSE;    break;
        case OpenGL::LogicOpMode::Set:           result = Anvil::LogicOp::SET;           break;
        case OpenGL::LogicOpMode::Xor:           result = Anvil::LogicOp::XOR;           break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::PolygonMode OpenGL::VKUtils::get_anvil_polygon_mode_for_polygon_mode(const OpenGL::PolygonMode& in_polygon_mode)
{
    Anvil::PolygonMode result = Anvil::PolygonMode::UNKNOWN;

    switch (in_polygon_mode)
    {
        case OpenGL::PolygonMode::Fill:  result = Anvil::PolygonMode::FILL;  break;
        case OpenGL::PolygonMode::Line:  result = Anvil::PolygonMode::LINE;  break;
        case OpenGL::PolygonMode::Point: result = Anvil::PolygonMode::POINT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::PrimitiveTopology OpenGL::VKUtils::get_anvil_primitive_topology_for_draw_call_mode(const OpenGL::DrawCallMode& in_draw_call_mode)
{
    Anvil::PrimitiveTopology result = Anvil::PrimitiveTopology::UNKNOWN;

    switch (in_draw_call_mode)
    {
        case OpenGL::DrawCallMode::Lines:                    result = Anvil::PrimitiveTopology::LINE_LIST;                     break;
        case OpenGL::DrawCallMode::Lines_Adjacency:          result = Anvil::PrimitiveTopology::LINE_LIST_WITH_ADJACENCY;      break;
        case OpenGL::DrawCallMode::Line_Strip:               result = Anvil::PrimitiveTopology::LINE_STRIP;                    break;
        case OpenGL::DrawCallMode::Line_Strip_Adjacency:     result = Anvil::PrimitiveTopology::LINE_STRIP_WITH_ADJACENCY;     break;
        case OpenGL::DrawCallMode::Patches:                  result = Anvil::PrimitiveTopology::PATCH_LIST;                    break;
        case OpenGL::DrawCallMode::Points:                   result = Anvil::PrimitiveTopology::POINT_LIST;                    break;
        case OpenGL::DrawCallMode::Triangle_Fan:             result = Anvil::PrimitiveTopology::TRIANGLE_FAN;                  break;
        case OpenGL::DrawCallMode::Triangle_Strip:           result = Anvil::PrimitiveTopology::TRIANGLE_STRIP;                break;
        case OpenGL::DrawCallMode::Triangle_Strip_Adjacency: result = Anvil::PrimitiveTopology::TRIANGLE_STRIP_WITH_ADJACENCY; break;
        case OpenGL::DrawCallMode::Triangles:                result = Anvil::PrimitiveTopology::TRIANGLE_LIST;                 break;
        case OpenGL::DrawCallMode::Triangles_Adjacency:      result = Anvil::PrimitiveTopology::TRIANGLE_LIST_WITH_ADJACENCY;  break;

        case OpenGL::DrawCallMode::Line_Loop:
        {
            /* Not available in Vulkan. This will require some coding muscles to get to work. Deferring. */
            vkgl_not_implemented();

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::StencilOp OpenGL::VKUtils::get_anvil_stencil_op_for_stencil_operation(const OpenGL::StencilOperation& in_stencil_op)
{
    Anvil::StencilOp result = Anvil::StencilOp::UNKNOWN;

    switch (in_stencil_op)
    {
        case OpenGL::StencilOperation::Decr:      result = Anvil::StencilOp::DECREMENT_AND_CLAMP; break;
        case OpenGL::StencilOperation::Decr_Wrap: result = Anvil::StencilOp::DECREMENT_AND_WRAP;  break;
        case OpenGL::StencilOperation::Incr:      result = Anvil::StencilOp::INCREMENT_AND_CLAMP; break;
        case OpenGL::StencilOperation::Incr_Wrap: result = Anvil::StencilOp::INCREMENT_AND_WRAP;  break;
        case OpenGL::StencilOperation::Invert:    result = Anvil::StencilOp::INVERT;              break;
        case OpenGL::StencilOperation::Keep:      result = Anvil::StencilOp::KEEP;                break;
        case OpenGL::StencilOperation::Replace:   result = Anvil::StencilOp::REPLACE;             break;
        case OpenGL::StencilOperation::Zero:      result = Anvil::StencilOp::ZERO;                break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::BufferUsageFlags OpenGL::VKUtils::get_buffer_usage_flags_for_gl_buffer(const uint32_t&             in_n_buffer_targets,
                                                                              const OpenGL::BufferTarget* in_buffer_targets_ptr)
{
    Anvil::BufferUsageFlags result = Anvil::BufferUsageFlagBits::NONE;

    vkgl_assert(in_buffer_targets_ptr != nullptr);

    for (uint32_t n_buffer_target = 0;
                  n_buffer_target < in_n_buffer_targets;
                ++n_buffer_target)
    {
        const auto& current_target = in_buffer_targets_ptr[n_buffer_target];

        switch (current_target)
        {
            case OpenGL::BufferTarget::Array_Buffer:         result |= Anvil::BufferUsageFlagBits::VERTEX_BUFFER_BIT;        break;
            case OpenGL::BufferTarget::Copy_Read_Buffer:     result |= Anvil::BufferUsageFlagBits::TRANSFER_SRC_BIT;         break;
            case OpenGL::BufferTarget::Copy_Write_Buffer:    result |= Anvil::BufferUsageFlagBits::TRANSFER_DST_BIT;         break;
            case OpenGL::BufferTarget::Element_Array_Buffer: result |= Anvil::BufferUsageFlagBits::INDEX_BUFFER_BIT;         break;
            case OpenGL::BufferTarget::Pixel_Pack_Buffer:    result |= Anvil::BufferUsageFlagBits::TRANSFER_DST_BIT;         break;
            case OpenGL::BufferTarget::Pixel_Unpack_Buffer:  result |= Anvil::BufferUsageFlagBits::TRANSFER_SRC_BIT;         break;
            case OpenGL::BufferTarget::Texture_Buffer:       result |= Anvil::BufferUsageFlagBits::UNIFORM_TEXEL_BUFFER_BIT; break;
            case OpenGL::BufferTarget::Uniform_Buffer:       result |= Anvil::BufferUsageFlagBits::UNIFORM_BUFFER_BIT;       break;

            case OpenGL::BufferTarget::Transform_Feedback_Buffer:
            {
                vkgl_not_implemented();

                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }

    return result;
}

Anvil::MemoryFeatureFlags OpenGL::VKUtils::get_memory_feature_flags_for_gl_buffer(const OpenGL::BufferUsage& in_buffer_usage)
{
    const bool is_dynamic = (in_buffer_usage == OpenGL::BufferUsage::Dynamic_Copy ||
                             in_buffer_usage == OpenGL::BufferUsage::Dynamic_Draw ||
                             in_buffer_usage == OpenGL::BufferUsage::Dynamic_Read);
    const bool is_static  = (in_buffer_usage == OpenGL::BufferUsage::Static_Copy  ||
                             in_buffer_usage == OpenGL::BufferUsage::Static_Draw  ||
                             in_buffer_usage == OpenGL::BufferUsage::Static_Read);
    const bool is_stream  = (in_buffer_usage == OpenGL::BufferUsage::Stream_Copy  ||
                             in_buffer_usage == OpenGL::BufferUsage::Stream_Draw  ||
                             in_buffer_usage == OpenGL::BufferUsage::Stream_Read);

    const bool is_copy = (in_buffer_usage == OpenGL::BufferUsage::Dynamic_Copy ||
                          in_buffer_usage == OpenGL::BufferUsage::Static_Copy  ||
                          in_buffer_usage == OpenGL::BufferUsage::Stream_Copy);
    const bool is_draw = (in_buffer_usage == OpenGL::BufferUsage::Dynamic_Draw ||
                          in_buffer_usage == OpenGL::BufferUsage::Static_Draw  ||
                          in_buffer_usage == OpenGL::BufferUsage::Stream_Draw);
    const bool is_read = (in_buffer_usage == OpenGL::BufferUsage::Dynamic_Read ||
                          in_buffer_usage == OpenGL::BufferUsage::Static_Read  ||
                          in_buffer_usage == OpenGL::BufferUsage::Stream_Read);

    Anvil::MemoryFeatureFlags result = Anvil::MemoryFeatureFlagBits::NONE;


    if (is_static)
    {
        /* Data is specified once by the app .. */
        if (is_draw)
        {
            /* ..and used many times for draw + image transfer ops */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT;
        }
        else
        if (is_read)
        {
            /* ..data is generated on-device, contents will be polled many times by the app  */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT | Anvil::MemoryFeatureFlagBits::MAPPABLE_BIT;
        }
        else
        if (is_copy)
        {
            /* ..data is generated on-device, and used for copy + image transfer ops for many times */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT;
        }
        else
        {
            vkgl_assert_fail();
        }
    }
    else
    if (is_stream)
    {
        /* Data is specified once by the app */
        if (is_draw)
        {
            /* ..and used for a few times for draw + image transfer ops */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT;
        }
        else
        if (is_read)
        {
            /* ..data is generated on-device, contents will be polled for a number of times by the app  */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT | Anvil::MemoryFeatureFlagBits::MAPPABLE_BIT;
        }
        else
        if (is_copy)
        {
            /* ..data is generated on-device, and used for a number of times for copy + image transfer ops */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT;
        }
        else
        {
            vkgl_assert_fail();
        }
    }
    else
    if (is_dynamic)
    {
        /* Data is specified many times */
        if (is_draw)
        {
            /* ..and used many times for draw + image transfer ops */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT | Anvil::MemoryFeatureFlagBits::MAPPABLE_BIT;
        }
        else
        if (is_read)
        {
            /* ..data is generated on-device, contents will be polled many times by the app  */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT | Anvil::MemoryFeatureFlagBits::MAPPABLE_BIT;
        }
        else
        if (is_copy)
        {
            /* ..data is generated on-device, and used many times for copy + image transfer ops */
            result = Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT | Anvil::MemoryFeatureFlagBits::MAPPABLE_BIT;
        }
        else
        {
            vkgl_assert_fail();
        }
    }
    else
    {
        vkgl_assert_fail();
    }

    return result;
}
