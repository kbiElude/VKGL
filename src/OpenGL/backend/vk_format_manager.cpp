/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/formats.h"
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/physical_device.h"
#include "Common/macros.h"
#include "OpenGL/backend/vk_format_manager.h"
#include "OpenGL/frontend/gl_formats.h"

OpenGL::VKFormatManager::VKFormatManager(Anvil::SGPUDevice* in_device_ptr)
    :m_device_ptr(in_device_ptr)
{
    vkgl_assert(m_device_ptr != nullptr);
}

OpenGL::VKFormatManager::~VKFormatManager()
{
}

OpenGL::VKFormatManagerUniquePtr OpenGL::VKFormatManager::create(Anvil::SGPUDevice* in_device_ptr)
{
    OpenGL::VKFormatManagerUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::VKFormatManager(in_device_ptr) );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

Anvil::FormatType OpenGL::VKFormatManager::get_anvil_format_type_for_gl_format_data_type(const OpenGL::FormatDataType& in_data_type) const
{
    Anvil::FormatType result = Anvil::FormatType::UNKNOWN;

    switch (in_data_type)
    {
        case OpenGL::FormatDataType::SFloat:     result = Anvil::FormatType::SFLOAT;     break;
        case OpenGL::FormatDataType::SInt:       result = Anvil::FormatType::SINT;       break;
        case OpenGL::FormatDataType::SNorm:      result = Anvil::FormatType::SNORM;      break;
        case OpenGL::FormatDataType::SRGB:       result = Anvil::FormatType::SRGB;       break;
        case OpenGL::FormatDataType::UFloat:     result = Anvil::FormatType::UFLOAT;     break;
        case OpenGL::FormatDataType::UInt:       result = Anvil::FormatType::UINT;       break;
        case OpenGL::FormatDataType::UNorm:      result = Anvil::FormatType::UNORM;      break;
        case OpenGL::FormatDataType::UNorm_UInt: result = Anvil::FormatType::UNORM_UINT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

Anvil::Format OpenGL::VKFormatManager::get_best_fit_anvil_format(const OpenGL::InternalFormat&    in_internal_format,
                                                                const Anvil::FormatFeatureFlags& in_format_features)
{
    std::lock_guard<std::mutex> lock                 (m_gl_to_vk_format_map_mutex);
    Anvil::Format               result               (Anvil::Format::UNKNOWN);
    uint32_t                    result_bits_per_texel(0);

    /* Sanity check: this func must not be called for non-sized / compressed internal formats (TODO: is this true for the latter?) */
    vkgl_assert(OpenGL::GLFormats::is_sized_internal_format(in_internal_format) );

    {
        /* Check if the query has not been issued in the past first. */
        auto map_iterator(m_gl_to_vk_format_map.find(GLToVKFormatMapKey(in_internal_format,
                                                                        in_format_features) ));

        if (map_iterator != m_gl_to_vk_format_map.end() )
        {
            result = map_iterator->second;

            goto end;
        }
    }
    {
        /* Need to do the search..
         *
         * 1. Prepare a list of formats which meet component size requirements.
         */
        std::vector<Anvil::Format> candidate_formats;
        uint32_t                   internal_format_size_ds    [2]  = {0, 0};
        uint32_t                   internal_format_size_rgba  [4]  = {0, 0, 0, 0};
        uint32_t                   internal_format_size_shared     = 0;
        const auto                 internal_format_data_type       = OpenGL::GLFormats::get_format_data_type_for_non_base_internal_format(in_internal_format);
        const auto                 internal_format_data_type_anvil = get_anvil_format_type_for_gl_format_data_type                       (internal_format_data_type);

        static const Anvil::Format color_formats[] =
        {
            Anvil::Format::R4G4_UNORM_PACK8,
            Anvil::Format::R4G4B4A4_UNORM_PACK16,
            Anvil::Format::B4G4R4A4_UNORM_PACK16,
            Anvil::Format::R5G6B5_UNORM_PACK16,
            Anvil::Format::B5G6R5_UNORM_PACK16,
            Anvil::Format::R5G5B5A1_UNORM_PACK16,
            Anvil::Format::B5G5R5A1_UNORM_PACK16,
            Anvil::Format::A1R5G5B5_UNORM_PACK16,
            Anvil::Format::R8_UNORM,
            Anvil::Format::R8_SNORM,
            Anvil::Format::R8_USCALED,
            Anvil::Format::R8_SSCALED,
            Anvil::Format::R8_UINT,
            Anvil::Format::R8_SINT,
            Anvil::Format::R8_SRGB,
            Anvil::Format::R8G8_UNORM,
            Anvil::Format::R8G8_SNORM,
            Anvil::Format::R8G8_USCALED,
            Anvil::Format::R8G8_SSCALED,
            Anvil::Format::R8G8_UINT,
            Anvil::Format::R8G8_SINT,
            Anvil::Format::R8G8_SRGB,
            Anvil::Format::R8G8B8_UNORM,
            Anvil::Format::R8G8B8_SNORM,
            Anvil::Format::R8G8B8_USCALED,
            Anvil::Format::R8G8B8_SSCALED,
            Anvil::Format::R8G8B8_UINT,
            Anvil::Format::R8G8B8_SINT,
            Anvil::Format::R8G8B8_SRGB,
            Anvil::Format::B8G8R8_UNORM,
            Anvil::Format::B8G8R8_SNORM,
            Anvil::Format::B8G8R8_USCALED,
            Anvil::Format::B8G8R8_SSCALED,
            Anvil::Format::B8G8R8_UINT,
            Anvil::Format::B8G8R8_SINT,
            Anvil::Format::B8G8R8_SRGB,
            Anvil::Format::R8G8B8A8_UNORM,
            Anvil::Format::R8G8B8A8_SNORM,
            Anvil::Format::R8G8B8A8_USCALED,
            Anvil::Format::R8G8B8A8_SSCALED,
            Anvil::Format::R8G8B8A8_UINT,
            Anvil::Format::R8G8B8A8_SINT,
            Anvil::Format::R8G8B8A8_SRGB,
            Anvil::Format::B8G8R8A8_UNORM,
            Anvil::Format::B8G8R8A8_SNORM,
            Anvil::Format::B8G8R8A8_USCALED,
            Anvil::Format::B8G8R8A8_SSCALED,
            Anvil::Format::B8G8R8A8_UINT,
            Anvil::Format::B8G8R8A8_SINT,
            Anvil::Format::B8G8R8A8_SRGB,
            Anvil::Format::A8B8G8R8_UNORM_PACK32,
            Anvil::Format::A8B8G8R8_SNORM_PACK32,
            Anvil::Format::A8B8G8R8_USCALED_PACK32,
            Anvil::Format::A8B8G8R8_SSCALED_PACK32,
            Anvil::Format::A8B8G8R8_UINT_PACK32,
            Anvil::Format::A8B8G8R8_SINT_PACK32,
            Anvil::Format::A8B8G8R8_SRGB_PACK32,
            Anvil::Format::A2R10G10B10_UNORM_PACK32,
            Anvil::Format::A2R10G10B10_SNORM_PACK32,
            Anvil::Format::A2R10G10B10_USCALED_PACK32,
            Anvil::Format::A2R10G10B10_SSCALED_PACK32,
            Anvil::Format::A2R10G10B10_UINT_PACK32,
            Anvil::Format::A2R10G10B10_SINT_PACK32,
            Anvil::Format::A2B10G10R10_UNORM_PACK32,
            Anvil::Format::A2B10G10R10_SNORM_PACK32,
            Anvil::Format::A2B10G10R10_USCALED_PACK32,
            Anvil::Format::A2B10G10R10_SSCALED_PACK32,
            Anvil::Format::A2B10G10R10_UINT_PACK32,
            Anvil::Format::A2B10G10R10_SINT_PACK32,
            Anvil::Format::R16_UNORM,
            Anvil::Format::R16_SNORM,
            Anvil::Format::R16_USCALED,
            Anvil::Format::R16_SSCALED,
            Anvil::Format::R16_UINT,
            Anvil::Format::R16_SINT,
            Anvil::Format::R16_SFLOAT,
            Anvil::Format::R16G16_UNORM,
            Anvil::Format::R16G16_SNORM,
            Anvil::Format::R16G16_USCALED,
            Anvil::Format::R16G16_SSCALED,
            Anvil::Format::R16G16_UINT,
            Anvil::Format::R16G16_SINT,
            Anvil::Format::R16G16_SFLOAT,
            Anvil::Format::R16G16B16_UNORM,
            Anvil::Format::R16G16B16_SNORM,
            Anvil::Format::R16G16B16_USCALED,
            Anvil::Format::R16G16B16_SSCALED,
            Anvil::Format::R16G16B16_UINT,
            Anvil::Format::R16G16B16_SINT,
            Anvil::Format::R16G16B16_SFLOAT,
            Anvil::Format::R16G16B16A16_UNORM,
            Anvil::Format::R16G16B16A16_SNORM,
            Anvil::Format::R16G16B16A16_USCALED,
            Anvil::Format::R16G16B16A16_SSCALED,
            Anvil::Format::R16G16B16A16_UINT,
            Anvil::Format::R16G16B16A16_SINT,
            Anvil::Format::R16G16B16A16_SFLOAT,
            Anvil::Format::R32_UINT,
            Anvil::Format::R32_SINT,
            Anvil::Format::R32_SFLOAT,
            Anvil::Format::R32G32_UINT,
            Anvil::Format::R32G32_SINT,
            Anvil::Format::R32G32_SFLOAT,
            Anvil::Format::R32G32B32_UINT,
            Anvil::Format::R32G32B32_SINT,
            Anvil::Format::R32G32B32_SFLOAT,
            Anvil::Format::R32G32B32A32_UINT,
            Anvil::Format::R32G32B32A32_SINT,
            Anvil::Format::R32G32B32A32_SFLOAT,
            Anvil::Format::R64_UINT,
            Anvil::Format::R64_SINT,
            Anvil::Format::R64_SFLOAT,
            Anvil::Format::R64G64_UINT,
            Anvil::Format::R64G64_SINT,
            Anvil::Format::R64G64_SFLOAT,
            Anvil::Format::R64G64B64_UINT,
            Anvil::Format::R64G64B64_SINT,
            Anvil::Format::R64G64B64_SFLOAT,
            Anvil::Format::R64G64B64A64_UINT,
            Anvil::Format::R64G64B64A64_SINT,
            Anvil::Format::R64G64B64A64_SFLOAT,
            Anvil::Format::B10G11R11_UFLOAT_PACK32,
            Anvil::Format::E5B9G9R9_UFLOAT_PACK32,
        };

        static const Anvil::Format ds_formats[] =
        {
            Anvil::Format::D16_UNORM,
            Anvil::Format::X8_D24_UNORM_PACK32,
            Anvil::Format::D32_SFLOAT,
            Anvil::Format::S8_UINT,
            Anvil::Format::D16_UNORM_S8_UINT,
            Anvil::Format::D24_UNORM_S8_UINT,
            Anvil::Format::D32_SFLOAT_S8_UINT,
        };

        const Anvil::Format* input_formats   = nullptr;
        uint32_t             n_input_formats = 0;

        if (!OpenGL::GLFormats::get_per_component_bit_size_for_sized_internal_format(in_internal_format,
                                                                                     internal_format_size_rgba,
                                                                                     internal_format_size_ds,
                                                                                    &internal_format_size_shared) )
        {
            vkgl_assert_fail();

            goto end;
        }

        if (internal_format_size_ds[0] == 0 &&
            internal_format_size_ds[1] == 0)
        {
            /* Internal format is a color format */
            vkgl_assert(internal_format_size_rgba[0] == 0 &&
                        internal_format_size_rgba[1] == 0 &&
                        internal_format_size_rgba[2] == 0 &&
                        internal_format_size_rgba[3] == 0);

            input_formats   = color_formats;
            n_input_formats = sizeof(color_formats) / sizeof(color_formats[0]);
        }
        else
        {
            /* Internal format is a D/DS/S format */
            vkgl_assert(internal_format_size_ds[0] != 0 ||
                        internal_format_size_ds[1] != 0);

            input_formats   = ds_formats;
            n_input_formats = sizeof(ds_formats) / sizeof(ds_formats[0]);
        }

        for (uint32_t n_input_format = 0;
                      n_input_format < n_input_formats;
                    ++n_input_format)
        {
            const auto current_format              = input_formats[n_input_format];
            const auto current_format_props        = m_device_ptr->get_physical_device_format_properties(current_format);
            uint32_t   current_format_rgba_size[4] = {0, 0, 0, 0};
            const auto current_format_type         = Anvil::Formats::get_format_type(current_format);

            /* Make sure per-component number of bits is sufficient */
            Anvil::Formats::get_format_n_component_bits_nonyuv(current_format,
                                                               current_format_rgba_size + 0,
                                                               current_format_rgba_size + 1,
                                                               current_format_rgba_size + 2,
                                                               current_format_rgba_size + 3);

            if (internal_format_size_rgba[0] > current_format_rgba_size[0] ||
                internal_format_size_rgba[1] > current_format_rgba_size[1] ||
                internal_format_size_rgba[2] > current_format_rgba_size[2] ||
                internal_format_size_rgba[3] > current_format_rgba_size[3])
            {
                continue;
            }

            /* Make sure data types match. */
            if (current_format_type != internal_format_data_type_anvil)
            {
                continue;
            }

            /* That's a good candidate. */
            candidate_formats.push_back(current_format);
        }

        /* 2. Get rid of formats which do not support the requested usage flags */
        for (uint32_t n_candidate_format = 0;
                      n_candidate_format < candidate_formats.size(); )
        {
            const auto current_format       = candidate_formats.at(n_candidate_format);
            const auto current_format_props = m_device_ptr->get_physical_device_format_properties(current_format);

            if ((current_format_props.optimal_tiling_capabilities & in_format_features) != in_format_features)
            {
                /* The device does not provide sufficient caps for current format. Move on */
                candidate_formats.erase(candidate_formats.begin() + n_candidate_format);

                continue;
            }

            ++n_candidate_format;
        }

        /* 3. The format whose total texel size is the smallest wins. */
        if (candidate_formats.size() == 0)
        {
            vkgl_assert(candidate_formats.size() != 0);

            goto end;
        }

        for (const auto& current_candidate_format : candidate_formats)
        {
            uint32_t current_candidate_format_size_per_texel = 0;

            {
                uint32_t current_candidate_format_size[4] = {0, 0, 0, 0};

                Anvil::Formats::get_format_n_component_bits_nonyuv(current_candidate_format,
                                                                   current_candidate_format_size + 0,
                                                                   current_candidate_format_size + 1,
                                                                   current_candidate_format_size + 2,
                                                                   current_candidate_format_size + 3);

                current_candidate_format_size_per_texel = current_candidate_format_size[0] +
                                                          current_candidate_format_size[1] +
                                                          current_candidate_format_size[2] +
                                                          current_candidate_format_size[3];
            }

            if (result == Anvil::Format::UNKNOWN                                ||
                result_bits_per_texel < current_candidate_format_size_per_texel)
            {
                result                = current_candidate_format;
                result_bits_per_texel = current_candidate_format_size_per_texel;
            }
        }
    }

    /* All done */
end:
    vkgl_assert(result != Anvil::Format::UNKNOWN);

    return result;
}