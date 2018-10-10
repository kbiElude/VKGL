/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/backend/vk_utils.h"

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
