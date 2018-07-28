#ifndef VKGL_TYPES_ENUMS_H
#define VKGL_TYPES_ENUMS_H

namespace VKGL
{
    enum class BlendFunction
    {
        Constant_Alpha,
        Constant_Color,
        Dst_Alpha,
        Dst_Color,
        One,
        One_Minus_Constant_Alpha,
        One_Minus_Constant_Color,
        One_Minus_Dst_Alpha,
        One_Minus_Dst_Color,
        One_Minus_Src_Alpha,
        One_Minus_Src_Color,
        Src_Alpha,
        Src_Alpha_Saturate,
        Src_Color,
        Zero,

        Unknown
    };

    enum class Capability
    {
        Blend,
        Clip_Distance, /* indexed */
        Color_Logic_Op,
        Cull_Face,
        Depth_Clamp,
        Depth_Test,
        Dither,
        Framebuffer_SRGB,
        Line_Smooth,
        Multisample,
        Polygon_Offset_Fill,
        Polygon_Offset_Line,
        Polygon_Offset_Point,
        Polygon_Smooth,
        Primitive_Restart,
        Program_Point_Size,
        Sample_Alpha_To_Coverage,
        Sample_Alpha_To_One,
        Sample_Coverage,
        Scissor_Test,
        Stencil_Test,
        Texture_Cube_Map_Seamless,

        Unknown
    };

    enum ClearBufferBit
    {
        CLEAR_BUFFER_BIT_COLOR   = 1 << 0,
        CLEAR_BUFFER_BIT_DEPTH   = 1 << 1,
        CLEAR_BUFFER_BIT_STENCIL = 1 << 2
    };

    enum class CullMode
    {
        Back,
        Front,
        Front_Back,

        Unknown
    };

    enum class DepthFunction
    {
        Always,
        Equal,
        GEqual,
        Greater,
        LEqual,
        Less,
        Never,
        NotEqual,

        Unknown
    };

    enum class DepthStencilTextureMode
    {
        Depth_Component,
        Stencil_Component,

        Unknown
    };

    enum class FrontFaceOrientation
    {
        Clockwise,
        Counter_Clockwise,

        Unknown
    };

    enum class HintMode
    {
        Dont_Care,
        Nicest,
        Fastest,

        Unknown
    };

    enum class InternalFormat
    {
        /* Base internal formats */
        Depth_Component,
        Depth_Stencil,
        Red,
        RG,
        RGB,
        RGBA,

        /* Sized internal formats */
        R11F_G11F_B10F,
        R16,
        R16_SNorm,
        R16F,
        R16I,
        R16UI,
        R3_G3_B2,
        R32F,
        R32I,
        R32UI,
        R8,
        R8_SNorm,
        R8I,
        R8UI,
        RG16,
        RG16_SNorm,
        RG16F,
        RG16I,
        RG16UI,
        RG32F,
        RG32I,
        RG32UI,
        RG8,
        RG8_SNorm,
        RG8I,
        RG8UI,
        RGB10,
        RGB10_A2,
        RGB10_A2UI,
        RGB12,
        RGB16_SNorm,
        RGB16F,
        RGB16I,
        RGB16UI,
        RGB32F,
        RGB32I,
        RGB32UI,
        RGB4,
        RGB5,
        RGB5_A1,
        RGB8,
        RGB8_SNorm,
        RGB8I,
        RGB8UI,
        RGB9_E5,
        RGBA12,
        RGBA16,
        RGBA16F,
        RGBA16I,
        RGBA16UI,
        RGBA2,
        RGBA32F,
        RGBA32I,
        RGBA32UI,
        RGBA4,
        RGBA8,
        RGBA8_SNorm,
        RGBA8I,
        RGBA8UI,
        SRGB8,
        SRGB8_Alpha8,

        /* Compressed internal formats */
        Compressed_Red,
        Compressed_Red_RGTC1,
        Compressed_RG,
        Compressed_RG_RGTC2,
        Compressed_RGB,
        Compressed_RGB_BPTC_Signed_Float,
        Compressed_RGB_BPTC_Unsigned_Float,
        Compressed_RGBA,
        Compressed_RGBA_BPTC_UNorm,
        Compressed_Signed_Red_RGTC1,
        Compressed_Signed_RG_RGTC2,
        Compressed_SRGB,
        Compressed_SRGB_Alpha,
        Compressed_SRGB_Alpha_BPTC_UNorm,

        Unknown
    };

    enum class LogicOpMode
    {
        And,
        And_Invert,
        And_Reverse,
        Clear,
        Copy,
        Copy_Inverted,
        Equiv,
        Invert,
        Nand,
        Noop,
        Nor,
        Or,
        Or_Inverted,
        Or_Reverse,
        Set,
        Xor,

        Unknown
    };

    enum class PixelFormat
    {
        Blue,
        Blue_Integer,
        BGR,
        BGR_Integer,
        BGRA,
        BGRA_Integer,
        Depth_Component,
        Depth_Stencil,
        Green,
        Green_Integer,
        Red,
        Red_Integer,
        RG,
        RG_Integer,
        RGB,
        RGB_Integer,
        RGBA,
        RGBA_Integer,
        Stencil_Index,

        Unknown
    };

    enum class PixelType
    {
        Byte,
        Float,
        Float_32_Unsigned_Int_24_8_Rev,
        Half_Float,
        Int,
        Short,
        Unsigned_Byte,
        Unsigned_Byte_2_3_3_Rev,
        Unsigned_Byte_3_3_2,
        Unsigned_Int,
        Unsigned_Int_10_10_10_2,
        Unsigned_Int_10F_11F_11F_Rev,
        Unsigned_Int_2_10_10_10_Rev,
        Unsigned_Int_24_8,
        Unsigned_Int_5_9_9_9_Rev,
        Unsigned_Int_8_8_8_8,
        Unsigned_Int_8_8_8_8_Rev,
        Unsigned_Short,
        Unsigned_Short_1_5_5_5_Rev,
        Unsigned_Short_4_4_4_4,
        Unsigned_Short_4_4_4_4_Rev,
        Unsigned_Short_5_5_5_1,
        Unsigned_Short_5_6_5,
        Unsigned_Short_5_6_5_Rev,

        Unknown
    };

    enum class PolygonMode
    {
        Fill,
        Line,
        Point,

        Unknown
    };

    enum class StencilFunction
    {
        Always,
        Equal,
        GEqual,
        Greater,
        LEqual,
        Less,
        Never,
        NotEqual,

        Unknown
    };

    enum class StencilOperation
    {
        Decr,
        Decr_Wrap,
        Incr,
        Incr_Wrap,
        Invert,
        Keep,
        Replace,
        Zero,

        Unknown
    };

    enum class TextureCompareFunction
    {
        Always,
        Equal,
        GEqual,
        Greater,
        LEqual,
        Less,
        Never,
        NotEqual,

        Unknown
    };

    enum class TextureCompareMode
    {
        Compare_Ref_to_Texture,
        None,

        Unknown
    };

    enum class TextureMagFilter
    {
        Linear,
        Nearest,
    };

    enum class TextureMinFilter
    {
        Linear,
        Linear_Mipmap_Linear,
        Linear_Mipmap_Nearest,
        Nearest,
        Nearest_Mipmap_Linear,
        Nearest_Mipmap_Nearest,
    };

    enum class TextureSwizzle
    {
        Alpha,
        Blue,
        Green,
        One,
        Red,
        Zero,
    };

    enum class TextureTarget
    {
        _1D,
        _1D_Array,
        _2D,
        _2D_Array,
        _2D_Multisample,
        _2D_Multisample_Array,
        _3D,
        Cube_Map_Negative_X,
        Cube_Map_Negative_Y,
        Cube_Map_Negative_Z,
        Cube_Map_Positive_X,
        Cube_Map_Positive_Y,
        Cube_Map_Positive_Z,
        Proxy_Texture_1D,
        Proxy_Texture_1D_Array,
        Proxy_Texture_2D,
        Proxy_Texture_2D_Array,
        Proxy_Texture_2D_Multisample,
        Proxy_Texture_2D_Multisample_Array,
        Proxy_Texture_3D,
        Proxy_Texture_Cube_Map,
        Proxy_Texture_Rectangle,
        Rectangle,
        Texture_Buffer,

        Unknown
    };

    enum class TextureWrapMode
    {
        Clamp_To_Border,
        Clamp_To_Edge,
        Mirror_Clamp_to_Edge,
        Mirrored_Repeat,
        Repeat,

        Unknown
    };
};

#endif /* VKGL_TYPES_ENUMS_H */