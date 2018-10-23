/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/frontend/gl_formats.h"

typedef struct InternalFormatData
{
    OpenGL::FormatDataType data_type;
    uint32_t               n_components;

    /* For base and compressed internal formats, "1" indicates the component is used.
     * For sized internal formats, non-zero value indicates the component is used and describes the component size in bits.
     */
    uint32_t component_size_r;
    uint32_t component_size_g;
    uint32_t component_size_b;
    uint32_t component_size_a;
    uint32_t component_size_depth;
    uint32_t component_size_stencil;
    uint32_t component_size_shared;

    bool     is_base_internal_format;
    bool     is_compressed_internal_format;
    bool     is_sized_internal_format;

    InternalFormatData()
    {
        memset(this,
               0,
               sizeof(*this) );
    }

    InternalFormatData(const OpenGL::FormatDataType& in_data_type,
                       const uint32_t&               in_n_components,
                       const uint32_t&               in_component_size_r,
                       const uint32_t&               in_component_size_g,
                       const uint32_t&               in_component_size_b,
                       const uint32_t&               in_component_size_a,
                       const uint32_t&               in_component_size_depth,
                       const uint32_t&               in_component_size_stencil,
                       const uint32_t&               in_component_size_shared,
                       const bool&                   in_is_base_internal_format,
                       const bool&                   in_is_compressed_internal_format,
                       const bool&                   in_is_sized_internal_format)
        :data_type                    (in_data_type),
         n_components                 (in_n_components),
         component_size_r             (in_component_size_r),
         component_size_g             (in_component_size_g),
         component_size_b             (in_component_size_b),
         component_size_a             (in_component_size_a),
         component_size_depth         (in_component_size_depth),
         component_size_stencil       (in_component_size_stencil),
         component_size_shared        (in_component_size_shared),
         is_base_internal_format      (in_is_base_internal_format),
         is_compressed_internal_format(in_is_compressed_internal_format),
         is_sized_internal_format     (in_is_sized_internal_format)
    {
        /* Stub */
    }
} InternalFormatData;

OpenGL::PixelFormat;
static const std::unordered_map<OpenGL::InternalFormat, InternalFormatData> g_gl_internalformat_data =
{
    /* Base internal formats */
    /* Format                              |                     data_type                      | n_components | r size | g size | b size | a size | d size | s size | shared size | is base? | is compressed? | is sized? */
    {OpenGL::InternalFormat::Depth_Component, InternalFormatData(OpenGL::FormatDataType::Unknown, 1,             0,       0,       0,       0,       1,       0,       0,            true,      false,           false)},
    {OpenGL::InternalFormat::Depth_Stencil,   InternalFormatData(OpenGL::FormatDataType::Unknown, 2,             0,       0,       0,       0,       1,       1,       0,            true,      false,           false)},
    {OpenGL::InternalFormat::Red,             InternalFormatData(OpenGL::FormatDataType::Unknown, 1,             1,       0,       0,       0,       0,       0,       0,            true,      false,           false)},
    {OpenGL::InternalFormat::RG,              InternalFormatData(OpenGL::FormatDataType::Unknown, 2,             1,       1,       0,       0,       0,       0,       0,            true,      false,           false)},
    {OpenGL::InternalFormat::RGB,             InternalFormatData(OpenGL::FormatDataType::Unknown, 3,             1,       1,       1,       0,       0,       0,       0,            true,      false,           false)},
    {OpenGL::InternalFormat::RGBA,            InternalFormatData(OpenGL::FormatDataType::Unknown, 4,             1,       1,       1,       1,       0,       0,       0,            true,      false,           false)},

    /* Sized internal formats */
    /* Format                              |                    data_type                       | n_components | r size | g size | b size | a size | d size | s size | shared size | is base? | is compressed? | is sized? */
    {OpenGL::InternalFormat::R11F_G11F_B10F, InternalFormatData(OpenGL::FormatDataType::SFloat, 3,               11,      11,      10,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R16,            InternalFormatData(OpenGL::FormatDataType::UNorm,  1,               16,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R16_SNorm,      InternalFormatData(OpenGL::FormatDataType::SNorm,  1,               16,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R16F,           InternalFormatData(OpenGL::FormatDataType::SFloat, 1,               16,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R16I,           InternalFormatData(OpenGL::FormatDataType::SInt,   1,               16,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R16UI,          InternalFormatData(OpenGL::FormatDataType::UInt,   1,               16,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R3_G3_B2,       InternalFormatData(OpenGL::FormatDataType::UNorm,  3,               3,       3,       2,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R32F,           InternalFormatData(OpenGL::FormatDataType::SFloat, 1,               32,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R32I,           InternalFormatData(OpenGL::FormatDataType::SInt,   1,               32,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R32UI,          InternalFormatData(OpenGL::FormatDataType::UInt,   1,               32,      0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R8,             InternalFormatData(OpenGL::FormatDataType::UNorm,  1,               8,       0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R8_SNorm,       InternalFormatData(OpenGL::FormatDataType::SNorm,  1,               8,       0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R8I,            InternalFormatData(OpenGL::FormatDataType::SInt,   1,               8,       0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::R8UI,           InternalFormatData(OpenGL::FormatDataType::UInt,   1,               8,       0,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG16,           InternalFormatData(OpenGL::FormatDataType::UNorm,  2,               16,      16,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG16_SNorm,     InternalFormatData(OpenGL::FormatDataType::SNorm,  2,               16,      16,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG16F,          InternalFormatData(OpenGL::FormatDataType::SFloat, 2,               16,      16,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG16I,          InternalFormatData(OpenGL::FormatDataType::SInt,   2,               16,      16,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG16UI,         InternalFormatData(OpenGL::FormatDataType::UInt,   2,               16,      16,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG32F,          InternalFormatData(OpenGL::FormatDataType::SFloat, 2,               32,      32,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG32I,          InternalFormatData(OpenGL::FormatDataType::SInt,   2,               32,      32,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG32UI,         InternalFormatData(OpenGL::FormatDataType::UInt,   2,               32,      32,      0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG8,            InternalFormatData(OpenGL::FormatDataType::UNorm,  2,               8,       8,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG8_SNorm,      InternalFormatData(OpenGL::FormatDataType::SNorm,  2,               8,       8,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG8I,           InternalFormatData(OpenGL::FormatDataType::SInt,   2,               8,       8,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RG8UI,          InternalFormatData(OpenGL::FormatDataType::UInt,   2,               8,       8,       0,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB10,          InternalFormatData(OpenGL::FormatDataType::UNorm,  3,               10,      10,      10,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB10_A2,       InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               10,      10,      10,      2,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB10_A2UI,     InternalFormatData(OpenGL::FormatDataType::UInt,   4,               10,      10,      10,      2,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB12,          InternalFormatData(OpenGL::FormatDataType::UNorm,  3,               12,      12,      12,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB16_SNorm,    InternalFormatData(OpenGL::FormatDataType::SNorm,  3,               16,      16,      16,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB16F,         InternalFormatData(OpenGL::FormatDataType::SFloat, 3,               16,      16,      16,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB16I,         InternalFormatData(OpenGL::FormatDataType::SInt,   3,               16,      16,      16,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB16UI,        InternalFormatData(OpenGL::FormatDataType::UInt,   3,               16,      16,      16,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB32F,         InternalFormatData(OpenGL::FormatDataType::SFloat, 3,               32,      32,      32,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB32I,         InternalFormatData(OpenGL::FormatDataType::SInt,   3,               32,      32,      32,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB32UI,        InternalFormatData(OpenGL::FormatDataType::UInt,   3,               32,      32,      32,      0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB4,           InternalFormatData(OpenGL::FormatDataType::UNorm,  3,               4,       4,       4,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB5,           InternalFormatData(OpenGL::FormatDataType::UNorm,  3,               5,       5,       5,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB5_A1,        InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               5,       5,       5,       1,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB8,           InternalFormatData(OpenGL::FormatDataType::UNorm,  3,               8,       8,       8,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB8_SNorm,     InternalFormatData(OpenGL::FormatDataType::SNorm,  3,               8,       8,       8,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB8I,          InternalFormatData(OpenGL::FormatDataType::SInt,   3,               8,       8,       8,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB8UI,         InternalFormatData(OpenGL::FormatDataType::UInt,   3,               8,       8,       8,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGB9_E5,        InternalFormatData(OpenGL::FormatDataType::SFloat, 4,               9,       9,       9,       0,       0,       0,       5,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA12,         InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               12,      12,      12,      12,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA16,         InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               16,      16,      16,      16,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA16F,        InternalFormatData(OpenGL::FormatDataType::SFloat, 4,               16,      16,      16,      16,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA16I,        InternalFormatData(OpenGL::FormatDataType::SInt,   4,               16,      16,      16,      16,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA16UI,       InternalFormatData(OpenGL::FormatDataType::UInt,   4,               16,      16,      16,      16,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA2,          InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               2,       2,       2,       2,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA32F,        InternalFormatData(OpenGL::FormatDataType::SFloat, 4,               32,      32,      32,      32,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA32I,        InternalFormatData(OpenGL::FormatDataType::SInt,   4,               32,      32,      32,      32,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA32UI,       InternalFormatData(OpenGL::FormatDataType::UInt,   4,               32,      32,      32,      32,      0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA4,          InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               4,       4,       4,       4,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA8,          InternalFormatData(OpenGL::FormatDataType::UNorm,  4,               8,       8,       8,       8,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA8_SNorm,    InternalFormatData(OpenGL::FormatDataType::SNorm,  4,               8,       8,       8,       8,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA8I,         InternalFormatData(OpenGL::FormatDataType::SInt,   4,               8,       8,       8,       8,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::RGBA8UI,        InternalFormatData(OpenGL::FormatDataType::UInt,   4,               8,       8,       8,       8,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::SRGB8,          InternalFormatData(OpenGL::FormatDataType::SRGB,   3,               8,       8,       8,       0,       0,       0,       0,            false,     false,           true)},
    {OpenGL::InternalFormat::SRGB8_Alpha8,   InternalFormatData(OpenGL::FormatDataType::SRGB,   4,               8,       8,       8,       8,       0,       0,       0,            false,     false,           true)},

    /* Format                                       |                    data_type                           | n_components | r size | g size | b size | a size | d size | s size | shared size | is base? | is compressed? | is sized? */
    {OpenGL::InternalFormat::Depth_Component16,       InternalFormatData(OpenGL::FormatDataType::UNorm,        1,             0,       0,       0,       0,       16,      0,        0,           false,     false,           true) },
    {OpenGL::InternalFormat::Depth_Component24,       InternalFormatData(OpenGL::FormatDataType::UNorm,        1,             0,       0,       0,       0,       24,      0,        0,           false,     false,           true) },
    {OpenGL::InternalFormat::Depth_Component32,       InternalFormatData(OpenGL::FormatDataType::UNorm,        1,             0,       0,       0,       0,       32,      0,        0,           false,     false,           true) },
    {OpenGL::InternalFormat::Depth_Component32_Float, InternalFormatData(OpenGL::FormatDataType::UFloat,       1,             0,       0,       0,       0,       32,      0,        0,           false,     false,           true) },
    {OpenGL::InternalFormat::Depth24_Stencil8,        InternalFormatData(OpenGL::FormatDataType::UNorm_UInt,   2,             0,       0,       0,       0,       24,      8,        0,           false,     false,           true) },
    {OpenGL::InternalFormat::Depth32_Float_Stencil8,  InternalFormatData(OpenGL::FormatDataType::UFloat_UInt,  2,             0,       0,       0,       0,       32,      8,        0,           false,     false,           true) },

    /* Compressed internal formats */
    /* Format                              |                                        data_type                      | n_components | r size | g size | b size | a size | d size | s size | shared size | is base? | is compressed? | is sized? */
    {OpenGL::InternalFormat::Compressed_Red,                     InternalFormatData(OpenGL::FormatDataType::UNorm,   1,             1,       0,       0,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_Red_RGTC1,               InternalFormatData(OpenGL::FormatDataType::UNorm,   1,             1,       0,       0,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RG,                      InternalFormatData(OpenGL::FormatDataType::UNorm,   2,             1,       1,       0,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RG_RGTC2,                InternalFormatData(OpenGL::FormatDataType::UNorm,   2,             1,       1,       0,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RGB,                     InternalFormatData(OpenGL::FormatDataType::UNorm,   3,             1,       1,       1,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RGB_BPTC_Signed_Float,   InternalFormatData(OpenGL::FormatDataType::SFloat,  3,             1,       1,       1,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RGB_BPTC_Unsigned_Float, InternalFormatData(OpenGL::FormatDataType::UFloat,  3,             1,       1,       1,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RGBA,                    InternalFormatData(OpenGL::FormatDataType::UNorm,   4,             1,       1,       1,       1,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_RGBA_BPTC_UNorm,         InternalFormatData(OpenGL::FormatDataType::UNorm,   4,             1,       1,       1,       1,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_Signed_Red_RGTC1,        InternalFormatData(OpenGL::FormatDataType::SNorm,   1,             1,       0,       0,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_Signed_RG_RGTC2,         InternalFormatData(OpenGL::FormatDataType::SNorm,   2,             1,       1,       0,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_SRGB,                    InternalFormatData(OpenGL::FormatDataType::SRGB,    3,             1,       1,       1,       0,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_SRGB_Alpha,              InternalFormatData(OpenGL::FormatDataType::SRGB,    4,             1,       1,       1,       1,       0,       0,       0,            false,     true,            false)},
    {OpenGL::InternalFormat::Compressed_SRGB_Alpha_BPTC_UNorm,   InternalFormatData(OpenGL::FormatDataType::SRGB,    4,             1,       1,       1,       1,       0,       0,       0,            false,     true,            false)},

};

static const std::vector<OpenGL::InternalFormat> g_color_sized_internalformats =
{
    OpenGL::InternalFormat::R11F_G11F_B10F,
    OpenGL::InternalFormat::R16,
    OpenGL::InternalFormat::R16_SNorm,
    OpenGL::InternalFormat::R16F,
    OpenGL::InternalFormat::R16I,
    OpenGL::InternalFormat::R16UI,
    OpenGL::InternalFormat::R3_G3_B2,
    OpenGL::InternalFormat::R32F,
    OpenGL::InternalFormat::R32I,
    OpenGL::InternalFormat::R32UI,
    OpenGL::InternalFormat::R8,
    OpenGL::InternalFormat::R8_SNorm,
    OpenGL::InternalFormat::R8I,
    OpenGL::InternalFormat::R8UI,
    OpenGL::InternalFormat::RG16,
    OpenGL::InternalFormat::RG16_SNorm,
    OpenGL::InternalFormat::RG16F,
    OpenGL::InternalFormat::RG16I,
    OpenGL::InternalFormat::RG16UI,
    OpenGL::InternalFormat::RG32F,
    OpenGL::InternalFormat::RG32I,
    OpenGL::InternalFormat::RG32UI,
    OpenGL::InternalFormat::RG8,
    OpenGL::InternalFormat::RG8_SNorm,
    OpenGL::InternalFormat::RG8I,
    OpenGL::InternalFormat::RG8UI,
    OpenGL::InternalFormat::RGB10,
    OpenGL::InternalFormat::RGB10_A2,
    OpenGL::InternalFormat::RGB10_A2UI,
    OpenGL::InternalFormat::RGB12,
    OpenGL::InternalFormat::RGB16_SNorm,
    OpenGL::InternalFormat::RGB16F,
    OpenGL::InternalFormat::RGB16I,
    OpenGL::InternalFormat::RGB16UI,
    OpenGL::InternalFormat::RGB32F,
    OpenGL::InternalFormat::RGB32I,
    OpenGL::InternalFormat::RGB32UI,
    OpenGL::InternalFormat::RGB4,
    OpenGL::InternalFormat::RGB5,
    OpenGL::InternalFormat::RGB5_A1,
    OpenGL::InternalFormat::RGB8,
    OpenGL::InternalFormat::RGB8_SNorm,
    OpenGL::InternalFormat::RGB8I,
    OpenGL::InternalFormat::RGB8UI,
    OpenGL::InternalFormat::RGB9_E5,
    OpenGL::InternalFormat::RGBA12,
    OpenGL::InternalFormat::RGBA16,
    OpenGL::InternalFormat::RGBA16F,
    OpenGL::InternalFormat::RGBA16I,
    OpenGL::InternalFormat::RGBA16UI,
    OpenGL::InternalFormat::RGBA2,
    OpenGL::InternalFormat::RGBA32F,
    OpenGL::InternalFormat::RGBA32I,
    OpenGL::InternalFormat::RGBA32UI,
    OpenGL::InternalFormat::RGBA4,
    OpenGL::InternalFormat::RGBA8,
    OpenGL::InternalFormat::RGBA8_SNorm,
    OpenGL::InternalFormat::RGBA8I,
    OpenGL::InternalFormat::RGBA8UI,
    OpenGL::InternalFormat::SRGB8,
    OpenGL::InternalFormat::SRGB8_Alpha8,
};

static const std::vector<OpenGL::InternalFormat> g_ds_sized_internalformats =
{
    OpenGL::InternalFormat::Depth_Component16,
    OpenGL::InternalFormat::Depth_Component24,
    OpenGL::InternalFormat::Depth_Component32,
    OpenGL::InternalFormat::Depth_Component32_Float,
    OpenGL::InternalFormat::Depth24_Stencil8,
    OpenGL::InternalFormat::Depth32_Float_Stencil8,
};

OpenGL::InternalFormat OpenGL::GLFormats::get_best_fit_ds_internal_format(const uint32_t& in_depth_bits,
                                                                          const uint32_t& in_stencil_bits)
{
    OpenGL::InternalFormat result                = OpenGL::InternalFormat::Unknown;
    uint32_t               result_n_depth_bits   = 0;
    uint32_t               result_n_stencil_bits = 0;

    vkgl_assert(in_depth_bits   != 0 ||
                in_stencil_bits != 0);

    for (const auto& current_internalformat : g_ds_sized_internalformats)
    {
        const auto& internalformat_data_iterator = g_gl_internalformat_data.find(current_internalformat);
        vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );

        const auto& internalformat_data          = internalformat_data_iterator->second;

        if ((in_depth_bits   == 0 && internalformat_data.component_size_depth   != 0) ||
            (in_stencil_bits == 0 && internalformat_data.component_size_stencil != 0) )
        {
            continue;
        }

        if ((in_depth_bits   != 0 && internalformat_data.component_size_depth   == 0) ||
            (in_stencil_bits != 0 && internalformat_data.component_size_stencil == 0) )
        {
            continue;
        }

        if (result == OpenGL::InternalFormat::Unknown)
        {
            result                = current_internalformat;
            result_n_depth_bits   = internalformat_data.component_size_depth;
            result_n_stencil_bits = internalformat_data.component_size_stencil;
        }
        else
        {
            const auto current_depth_diff   = abs(static_cast<int32_t>(internalformat_data.component_size_depth)   - static_cast<int32_t>(in_depth_bits) );
            const auto current_stencil_diff = abs(static_cast<int32_t>(internalformat_data.component_size_stencil) - static_cast<int32_t>(in_stencil_bits) );
            const auto result_depth_diff    = abs(static_cast<int32_t>(result_n_depth_bits)                        - static_cast<int32_t>(in_depth_bits) );
            const auto result_stencil_diff  = abs(static_cast<int32_t>(result_n_stencil_bits)                      - static_cast<int32_t>(in_stencil_bits) );

            if (current_depth_diff + current_stencil_diff < result_depth_diff + result_stencil_diff)
            {
                result                = current_internalformat;
                result_n_depth_bits   = internalformat_data.component_size_depth;
                result_n_stencil_bits = internalformat_data.component_size_stencil;
            }
        }
    }

    vkgl_assert(result != OpenGL::InternalFormat::Unknown);
    return result;
}

OpenGL::FormatDataType OpenGL::GLFormats::get_format_data_type_for_non_base_internal_format(const OpenGL::InternalFormat& in_format)
{
    const auto             internalformat_data_iterator = g_gl_internalformat_data.find(in_format);
    OpenGL::FormatDataType result                       = OpenGL::FormatDataType::Unknown;

    vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );
    if (internalformat_data_iterator != g_gl_internalformat_data.end() )
    {
        result = internalformat_data_iterator->second.data_type;
    }

    return result;
}

uint32_t OpenGL::GLFormats::get_n_components_for_sized_internal_format(const OpenGL::InternalFormat& in_format)
{
    const auto internalformat_data_iterator = g_gl_internalformat_data.find(in_format);
    uint32_t   result                       = 0;

    vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );
    if (internalformat_data_iterator != g_gl_internalformat_data.end() )
    {
        result = internalformat_data_iterator->second.n_components;
    }

    return result;
}

bool OpenGL::GLFormats::get_per_component_bit_size_for_sized_internal_format(const OpenGL::InternalFormat& in_format,
                                                                             uint32_t*                     out_rgba_bit_size_ptr,
                                                                             uint32_t*                     out_ds_size_ptr,
                                                                             uint32_t*                     out_shared_size_ptr)
{
    const auto internalformat_data_iterator = g_gl_internalformat_data.find(in_format);
    bool       result                       = false;

    vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );
    if (internalformat_data_iterator != g_gl_internalformat_data.end() )
    {
        out_rgba_bit_size_ptr[0] = internalformat_data_iterator->second.component_size_r;
        out_rgba_bit_size_ptr[1] = internalformat_data_iterator->second.component_size_g;
        out_rgba_bit_size_ptr[2] = internalformat_data_iterator->second.component_size_b;
        out_rgba_bit_size_ptr[3] = internalformat_data_iterator->second.component_size_a;
        out_ds_size_ptr      [0] = internalformat_data_iterator->second.component_size_depth;
        out_ds_size_ptr      [1] = internalformat_data_iterator->second.component_size_stencil;
        *out_shared_size_ptr     = internalformat_data_iterator->second.component_size_shared;

        result = true;
    }

    return result;

}

bool OpenGL::GLFormats::is_base_internal_format(const OpenGL::InternalFormat& in_format)
{
    const auto internalformat_data_iterator = g_gl_internalformat_data.find(in_format);
    bool       result                       = false;

    vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );
    if (internalformat_data_iterator != g_gl_internalformat_data.end() )
    {
        result = internalformat_data_iterator->second.is_base_internal_format;
    }

    return result;
}

bool OpenGL::GLFormats::is_compressed_internal_format(const OpenGL::InternalFormat& in_format)
{
    const auto internalformat_data_iterator = g_gl_internalformat_data.find(in_format);
    bool       result                       = false;

    vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );
    if (internalformat_data_iterator != g_gl_internalformat_data.end() )
    {
        result = internalformat_data_iterator->second.is_compressed_internal_format;
    }

    return result;
}

bool OpenGL::GLFormats::is_sized_internal_format(const OpenGL::InternalFormat& in_format)
{
    const auto internalformat_data_iterator = g_gl_internalformat_data.find(in_format);
    bool       result                       = false;

    vkgl_assert(internalformat_data_iterator != g_gl_internalformat_data.end() );
    if (internalformat_data_iterator != g_gl_internalformat_data.end() )
    {
        result = internalformat_data_iterator->second.is_sized_internal_format;
    }

    return result;
}
