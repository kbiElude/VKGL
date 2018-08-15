/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_ENUMS_H
#define VKGL_TYPES_ENUMS_H

namespace VKGL
{
    enum class BlendEquation
    {
        Function_Add,
        Function_Reverse_Subtract,
        Function_Subtract,
        Max,
        Min,

        Unknown
    };

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

    enum class BlitFilter
    {
        Linear,
        Nearest,

        Unknown
    };

    enum BlitMaskBit
    {
        BLIT_MASK_BIT_COLOR_BUFFER   = 1 << 0,
        BLIT_MASK_BIT_DEPTH_BUFFER   = 1 << 1,
        BLIT_MASK_BIT_STENCIL_BUFFER = 1 << 2
    };

    enum class BufferAccess
    {
        Read_Only,
        Read_Write,
        Write_Only,

        Unknown
    };

    enum class BufferPointerProperty
    {
        Buffer_Map_Pointer,

        Unknown
    };

    enum class BufferProperty
    {
        Buffer_Access,
        Buffer_Mapped,
        Buffer_Size,
        Buffer_Usage,

        Unknown
    };

    enum class BufferTarget
    {
        Array_Buffer,
        Copy_Read_Buffer,
        Copy_Write_Buffer,
        Element_Array_Buffer,
        Pixel_Pack_Buffer,
        Pixel_Unpack_Buffer,
        Texture_Buffer,
        Transform_Feedback_Buffer,
        Uniform_Buffer,

        Unknown
    };

    enum class BufferUsage
    {
        Dynamic_Copy,
        Dynamic_Draw,
        Dynamic_Read,
        Static_Copy,
        Static_Draw,
        Static_Read,
        Stream_Copy,
        Stream_Draw,
        Stream_Read,

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

    enum class ClampReadColorMode
    {
        False,
        Fixed_Only,

        Unknown
    };

    enum class ClearBuffer
    {
        Back,
        Color,
        Depth,
        Depth_Stencil,
        Front,
        Front_And_Back,
        Left,
        Right,
        Stencil,

        Unknown
    };

    enum ClearBufferBit
    {
        CLEAR_BUFFER_BIT_COLOR   = 1 << 0,
        CLEAR_BUFFER_BIT_DEPTH   = 1 << 1,
        CLEAR_BUFFER_BIT_STENCIL = 1 << 2
    };

    enum class ContextProperty
    {
        Active_Texture,
        Aliased_Line_Width_Range,
        Array_Buffer_Binding,
        Blend,
        Blend_Color,
        Blend_Dst_Alpha,
        Blend_Dst_RGB,
        Blend_Equation_Alpha,
        Blend_Equation_RGB,
        Blend_Src_Alpha,
        Blend_Src_RGB,
        Color_Clear_Value,
        Color_Logic_Op,
        Color_Writemask,
        Compressed_Texture_Formats,
        Context_Flags,
        Cull_Face,
        Current_Program,
        Depth_Clear_Value,
        Depth_Func,
        Depth_Range,
        Depth_Test,
        Depth_Writemask,
        Dither,
        Doublebuffer,
        Draw_Buffer,
        Draw_Buffer0,
        Draw_Buffer1,
        Draw_Buffer2,
        Draw_Buffer3,
        Draw_Buffer4,
        Draw_Buffer5,
        Draw_Buffer6,
        Draw_Buffer7,
        Draw_Framebuffer_Binding,
        Element_Array_Buffer_Binding,
        Fragment_Shader_Derivative_Hint,
        Line_Smooth,
        Line_Smooth_Hint,
        Line_Width,
        Logic_Op_Mode,
        Major_Version,
        Max_3D_Texture_Size,
        Max_Array_Texture_Layers,
        Max_Clip_Distances,
        Max_Color_Texture_Samples,
        Max_Combined_Fragment_Uniform_Components,
        Max_Combined_Geometry_Uniform_Components,
        Max_Combined_Texture_Image_Units,
        Max_Combined_Uniform_Blocks,
        Max_Combined_Vertex_Uniform_Components,
        Max_Cube_Map_Texture_Size,
        Max_Depth_Texture_Samples,
        Max_Draw_Buffers,
        Max_Dual_Source_Draw_Buffers,
        Max_Elements_Indices,
        Max_Elements_Vertices,
        Max_Fragment_Input_Components,
        Max_Fragment_Uniform_Blocks,
        Max_Fragment_Uniform_Components,
        Max_Geometry_Input_Components,
        Max_Geometry_Output_Components,
        Max_Geometry_Texture_Image_Units,
        Max_Geometry_Uniform_Blocks,
        Max_Geometry_Uniform_Components,
        Max_Integer_Samples,
        Max_Program_Texel_Offset,
        Max_Rectangle_Texture_Size,
        Max_Renderbuffer_Size,
        Max_Sample_Mask_Words,
        Max_Server_Wait_Timeout,
        Max_Texture_Buffer_Size,
        Max_Texture_Image_Units,
        Max_Texture_LOD_Bias,
        Max_Texture_Size,
        Max_Uniform_Block_Size,
        Max_Uniform_Buffer_Bindings,
        Max_Varying_Components,
        Max_Varying_Floats = Max_Varying_Components,
        Max_Vertex_Attribs,
        Max_Vertex_Output_Components,
        Max_Vertex_Texture_Image_Units,
        Max_Vertex_Uniform_Blocks,
        Max_Vertex_Uniform_Components,
        Max_Viewport_Dims,
        Minor_Version,
        Min_Program_Texel_Offset,
        Num_Compressed_Texture_Formats,
        Num_Extensions,
        Pack_Alignment,
        Pack_Image_Height,
        Pack_LSB_First,
        Pack_Row_Length,
        Pack_Skip_Images,
        Pack_Skip_Pixels,
        Pack_Skip_Rows,
        Pack_Swap_Bytes,
        Pixel_Pack_Buffer_Binding,
        Pixel_Unpack_Buffer_Binding,
        Point_Fade_Threshold_Size,
        Point_Size,
        Point_Size_Granularity,
        Point_Size_Range,
        Polygon_Offset_Factor,
        Polygon_Offset_Fill,
        Polygon_Offset_Line,
        Polygon_Offset_Point,
        Polygon_Offset_Units,
        Polygon_Smooth,
        Polygon_Smooth_Hint,
        Primitive_Restart_Index,
        Program_Point_Size,
        Provoking_Vertex,
        Read_Buffer,
        Read_Framebuffer_Binding,
        Renderbuffer_Binding,
        Sampler_Binding,
        Samples,
        Sample_Buffers,
        Sample_Coverage_Invert,
        Sample_Coverage_Value,
        Scissor_Box,
        Scissor_Test,
        Smooth_Line_Width_Granularity,
        Smooth_Line_Width_Range,
        Stencil_Back_Fail,
        Stencil_Back_Func,
        Stencil_Back_Pass_Depth_Fail,
        Stencil_Back_Pass_Depth_Pass,
        Stencil_Back_Ref,
        Stencil_Back_Value_Mask,
        Stencil_Back_Writemask,
        Stencil_Clear_Value,
        Stencil_Fail,
        Stencil_Func,
        Stencil_Pass_Depth_Fail,
        Stencil_Pass_Depth_Pass,
        Stencil_Ref,
        Stencil_Test,
        Stencil_Value_Mask,
        Stencil_Writemask,
        Stereo,
        Subpixel_Bits,
        Texture_Binding_1D,
        Texture_Binding_1D_Array,
        Texture_Binding_2D,
        Texture_Binding_2D_Array,
        Texture_Binding_2D_Multisample,
        Texture_Binding_2D_Multisample_Array,
        Texture_Binding_3D,
        Texture_Binding_Buffer,
        Texture_Binding_Cube_Map,
        Texture_Binding_Rectangle,
        Texture_Compression_Hint,
        Timestamp,
        Transform_Feedback_Buffer_Binding,
        Transform_Feedback_Buffer_Size,
        Transform_Feedback_Buffer_Start,
        Uniform_Buffer_Binding,
        Uniform_Buffer_Offset_Alignment,
        Uniform_Buffer_Size,
        Uniform_Buffer_Start,
        Unpack_Alignment,
        Unpack_Image_Height,
        Unpack_LSB_First,
        Unpack_Row_Length,
        Unpack_Skip_Images,
        Unpack_Skip_Pixels,
        Unpack_Skip_Rows,
        Unpack_Swap_Bytes,
        Viewport,

        Unknown
    };

    enum class ConditionalRenderMode
    {
        Query_By_Region_No_Wait,
        Query_By_Region_Wait,

        Unknown,
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
        Stencil_Index,

        Unknown
    };

    enum class DrawBuffer
    {
        None,
        Back,
        Back_Left,
        Back_Right,
        Front,
        Front_And_Back,
        Front_Left,
        Front_Right,
        Left,
        Right,

        Color_Attachment0,
        Color_Attachment1,
        Color_Attachment2,
        Color_Attachment3,
        Color_Attachment4,
        Color_Attachment5,
        Color_Attachment6,
        Color_Attachment7,

        Unknown
    };

    enum class DrawCallMode
    {
        Lines,
        Lines_Adjacency,
        Line_Loop,
        Line_Strip,
        Line_Strip_Adjacency,
        Patches,
        Points,
        Triangle_Fan,
        Triangle_Strip,
        Triangle_Strip_Adjacency,
        Triangles,
        Triangles_Adjacency,

        Unknown
    };

    enum class DrawCallIndexType
    {
        Unsigned_Byte,
        Unsigned_Short,
        Unsigned_Int,

        Unknown
    };

    enum class ErrorCode
    {
        Invalid_Enum,
        Invalid_Framebuffer_Operation,
        Invalid_Operation,
        Invalid_Value,
        No_Error,
        Out_Of_Memory,

        Unknown
    };

    enum class FramebufferAttachmentComponentType
    {
        Float,
        Int,
        None,
        Signed_Normalized,
        Unsigned_Int,
        Unsigned_Normalized,

        Unknown
    };

    enum class FramebufferAttachmentObjectType
    {
        Framebuffer_Default,
        None,
        Renderbuffer,
        Texture,

        Unknown
    };

    enum class FramebufferAttachmentPoint
    {
        Color_Attachment0,
        Color_Attachment1,
        Color_Attachment2,
        Color_Attachment3,
        Color_Attachment4,
        Color_Attachment5,
        Color_Attachment6,
        Color_Attachment7,
        Depth_Attachment,
        Depth_Stencil_Attachment,
        Stencil_Attachment,

        Unknown,
    };

    enum class FramebufferStatus
    {
        Complete,
        Incomplete_Attachment,
        Incomplete_Draw_Buffer,
        Incomplete_Layer_Targets,
        Incomplete_Missing_Attachment,
        Incomplete_Multisample,
        Incomplete_Read_Buffer,
        Undefined,
        Unsupported,

        Unknown,
    };

    enum class FramebufferTarget
    {
        Draw_Framebuffer,
        Framebuffer,
        Read_Framebuffer,

        Unknown,
    };

    enum class FrontFaceOrientation
    {
        Clockwise,
        Counter_Clockwise,

        Unknown
    };

    enum class GeometryInputType
    {
        Lines,
        Lines_Adjacency,
        Points,
        Triangles,
        Triangles_Adjacency,

        Unknown
    };

    enum class GeometryOutputType
    {
        Line_Strip,
        Points,
        Triangle_Strip,

        Unknown
    };

    enum class GetSetArgumentType
    {
        BlendEquationVKGL,
        BlendFunctionVKGL,
        Boolean,
        BooleanFromInt32_Bit0,
        Byte,
        CullFaceVKGL,
        DepthFunctionVKGL,
        Double,
        Float,
        HintModeVKGL,
        Int,
        LogicOpModeVKGL,
        PointSpriteCoordOriginVKGL,
        ProvokingVertexConventionVKGL,
        Short,
        StencilFunctionVKGL,
        StencilOperationVKGL,
        String,
        Unsigned_Byte,
        Unsigned_Int,
        Unsigned_Short,

        Unknown,
    };

    enum class HintMode
    {
        Dont_Care,
        Nicest,
        Fastest,

        Unknown
    };

    enum class HintTarget
    {
        Fragment_Shader_Derivative,
        Line_Smooth,
        Polygon_Smooth,
        Texture_Compression,

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
        And_Inverted,
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

    enum class PixelStoreProperty
    {
        Pack_Alignment,
        Pack_Image_Height,
        Pack_LSB_First,
        Pack_Row_Length,
        Pack_Skip_Images,
        Pack_Skip_Pixels,
        Pack_Skip_Rows,
        Pack_Swap_Bytes,

        Unpack_Alignment,
        Unpack_Image_Height,
        Unpack_LSB_First,
        Unpack_Row_Length,
        Unpack_Skip_Images,
        Unpack_Skip_Pixels,
        Unpack_Skip_Rows,
        Unpack_Swap_Bytes,

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

    enum class PointProperty
    {
        Fade_Threshold_Size,
        Sprite_Coord_Origin,

        Unknown
    };

    enum class PointSpriteCoordOrigin
    {
        Lower_Left,
        Upper_Left,

        Unknown
    };

    enum class PolygonMode
    {
        Fill,
        Line,
        Point,

        Unknown
    };

    enum class ProgramProperty
    {
        Active_Attribute_Max_Length,
        Active_Attributes,
        Active_Uniform_Block_Max_Name_Length,
        Active_Uniform_Blocks,
        Active_Uniform_Max_Length,
        Active_Uniforms,
        Attached_Shaders,
        Delete_Status,
        Geometry_Input_Type,
        Geometry_Output_Type,
        Geometry_Vertices_Out,
        Info_Log_Length,
        Link_Status,
        Transform_Feedback_Buffer_Mode,
        Transform_Feedback_Varying_Max_Length,
        Transform_Feedback_Varyings,
        Validate_Status,

        Unknown
    };

    enum class QueryProperty
    {
        Query_Result,
        Query_Result_Available,

        Unknown
    };

    enum class QueryTarget
    {
        Primitives_Generated,
        Samples_Passed,
        Transform_Feedback_Primitives_Written,

        Unknown
    };

    enum class QueryTargetProperty
    {
        Current_Query,
        Query_Counter_Bits,

        Unknown
    };

    enum class ReadBuffer
    {
        None,
        Back,
        Back_Left,
        Back_Right,
        Front,
        Front_And_Back,
        Front_Left,
        Front_Right,
        Left,
        Right,

        Color_Attachment0,
        Color_Attachment1,
        Color_Attachment2,
        Color_Attachment3,
        Color_Attachment4,
        Color_Attachment5,
        Color_Attachment6,
        Color_Attachment7,

        Unknown
    };

    enum class RenderbufferTarget
    {
        Renderbuffer,

        Unknown,
    };

    enum class ShaderType
    {
        Fragment,
        Geometry,
        Vertex,

        Unknown
    };

    enum class ProvokingVertexConvention
    {
        First,
        Last,

        Unknown
    };

    enum class ShaderProperty
    {
        Compile_Status,
        Delete_Status,
        Info_Log_Length,
        Shader_Source_Length,
        Shader_Type,

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

    enum class StencilStateFace
    {
        Back,
        Front,
        Front_And_Back,

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

    enum class TextureBindingProperty
    {
        _1D,
        _1D_Array,
        _2D,
        _2D_Array,
        _2D_Multisample,
        _2D_Multisample_Array,
        _3D,
        Buffer,
        Cube_Map,
        Rectangle,

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

    enum class TextureCubeMapFace
    {
        Negative_X,
        Negative_Y,
        Negative_Z,
        None,
        Positive_X,
        Positive_Y,
        Positive_Z,

        Unknown
    };

    enum class TextureLevelProperty
    {
        Texture_Alpha_Size,
        Texture_Blue_Size,
        Texture_Buffer_Offset,
        Texture_Compressed,
        Texture_Compressed_Image_Size,
        Texture_Depth,
        Texture_Depth_Size,
        Texture_Green_Size,
        Texture_Height,
        Texture_Internal_Format,
        Texture_Red_Size,
        Texture_Width,

        Unknown
    };

    enum class TextureMagFilter
    {
        Linear,
        Nearest,

        Unknown
    };

    enum class TextureMinFilter
    {
        Linear,
        Linear_Mipmap_Linear,
        Linear_Mipmap_Nearest,
        Nearest,
        Nearest_Mipmap_Linear,
        Nearest_Mipmap_Nearest,

        Unknown
    };

    enum class TextureProperty
    {
        Depth_Stencil_Texture_Mode,
        Texture_Base_Level,
        Texture_Compare_Func,
        Texture_Compare_Mode,
        Texture_Lod_Bias,
        Texture_Mag_Filter,
        Texture_Max_Level,
        Texture_Max_Lod,
        Texture_Min_Filter,
        Texture_Min_Lod,
        Texture_Swizzle_A,
        Texture_Swizzle_B,
        Texture_Swizzle_G,
        Texture_Swizzle_R,
        Texture_Wrap_R,
        Texture_Wrap_S,
        Texture_Wrap_T,

        Unknown
    };

    enum class TextureSwizzle
    {
        Alpha,
        Blue,
        Green,
        One,
        Red,
        Zero,

        Unknown
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
        Cube_Map,
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

    enum class TransformFeedbackBufferMode
    {
        Interleaved_Attribs,
        Separate_Attribs,

        Unknown
    };

    enum class TransformFeedbackPrimitiveMode
    {
        Lines,
        Points,
        Triangles,

        Unknown,
    };

    enum class VariableType
    {
        Bool,
        Bvec2,
        Bvec3,
        Bvec4,
        Float,
        Int,
        Isampler1D,
        Isampler1DArray,
        Isampler2D,
        Isampler2DArray,
        Isampler2DMS,
        Isampler2DMSArray,
        Isampler2DRect,
        Isampler3D,
        IsamplerBuffer,
        IsamplerCube,
        Ivec2,
        Ivec3,
        Ivec4,
        Mat2,
        Mat3,
        Mat4,
        Mat2x3,
        Mat2x4,
        Mat3x2,
        Mat3x4,
        Mat4x2,
        Mat4x3,
        Sampler1D,
        Sampler1DArray,
        Sampler1DArrayShadow,
        Sampler1DShadow,
        Sampler2D,
        Sampler2DArray,
        Sampler2DArrayShadow,
        Sampler2DMS,
        Sampler2DMSArray,
        Sampler2DRect,
        Sampler2DRectShadow,
        Sampler2DShadow,
        Sampler3D,
        SamplerBuffer,
        SamplerCube,
        SamplerCubeShadow,
        Uint,
        Usampler1D,
        Usampler1DArray,
        Usampler2D,
        Usampler2DArray,
        Usampler2DMS,
        Usampler2DMSArray,
        Usampler2DRect,
        Usampler3D,
        UsamplerBuffer,
        UsamplerCube,
        Uvec2,
        Uvec3,
        Uvec4,
        Vec2,
        Vec3,
        Vec4,

        Unknown
    };

    enum class VertexAttributeArrayType
    {
        Byte,
        Double,
        Float,
        Int,
        Short,
        Unsigned_Byte,
        Unsigned_Int,
        Unsigned_Short,

        Unknown
    };

    enum class VertexAttributePointerProperty
    {
        Vertex_Attribute_Array_Pointer,

        Unknown
    };

    enum class VertexAttributeProperty
    {
        Array_Size,
        Array_Type,
        Buffer_Binding,
        Current_Vertex_Attribute,
        Divisor,
        Enabled,
        Integer,
        Stride,
        Normalized,

        Unknown
    };
};

#endif /* VKGL_TYPES_ENUMS_H */