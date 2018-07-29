#include "OpenGL/utils_enum.h"

VKGL::BlendFunction VKGL::Utils::get_blend_function_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BlendFunction result = VKGL::BlendFunction::Unknown;

    switch (in_enum)
    {
        case GL_CONSTANT_ALPHA:           result = VKGL::BlendFunction::Constant_Alpha;           break;
        case GL_CONSTANT_COLOR:           result = VKGL::BlendFunction::Constant_Color;           break;
        case GL_DST_ALPHA:                result = VKGL::BlendFunction::Dst_Alpha;                break;
        case GL_DST_COLOR:                result = VKGL::BlendFunction::Dst_Color;                break;
        case GL_ONE:                      result = VKGL::BlendFunction::One;                      break;
        case GL_ONE_MINUS_CONSTANT_ALPHA: result = VKGL::BlendFunction::One_Minus_Constant_Alpha; break;
        case GL_ONE_MINUS_CONSTANT_COLOR: result = VKGL::BlendFunction::One_Minus_Constant_Color; break;
        case GL_ONE_MINUS_DST_ALPHA:      result = VKGL::BlendFunction::One_Minus_Dst_Alpha;      break;
        case GL_ONE_MINUS_DST_COLOR:      result = VKGL::BlendFunction::One_Minus_Dst_Color;      break;
        case GL_ONE_MINUS_SRC_ALPHA:      result = VKGL::BlendFunction::One_Minus_Src_Alpha;      break;
        case GL_ONE_MINUS_SRC_COLOR:      result = VKGL::BlendFunction::One_Minus_Src_Color;      break;
        case GL_SRC_ALPHA:                result = VKGL::BlendFunction::Src_Alpha;                break;
        case GL_SRC_ALPHA_SATURATE:       result = VKGL::BlendFunction::Src_Alpha_Saturate;       break;
        case GL_SRC_COLOR:                result = VKGL::BlendFunction::Src_Color;                break;
        case GL_ZERO:                     result = VKGL::BlendFunction::Zero;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ClearBufferBits VKGL::Utils::get_clear_buffer_bits_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ClearBufferBits result = 0;

    if (in_enum & GL_COLOR_BUFFER_BIT)
    {
        result |= VKGL::ClearBufferBit::CLEAR_BUFFER_BIT_COLOR;
    }

    if (in_enum & GL_DEPTH_BUFFER_BIT)
    {
        result |= VKGL::ClearBufferBit::CLEAR_BUFFER_BIT_DEPTH;
    }

    if (in_enum & GL_STENCIL_BUFFER_BIT)
    {
        result |= VKGL::ClearBufferBit::CLEAR_BUFFER_BIT_STENCIL;
    }

    return result;
}

VKGL::CullMode VKGL::Utils::get_cull_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::CullMode result = VKGL::CullMode::Unknown;

    switch (in_enum)
    {
        case GL_BACK:           result = VKGL::CullMode::Back;       break;
        case GL_FRONT:          result = VKGL::CullMode::Front;      break;
        case GL_FRONT_AND_BACK: result = VKGL::CullMode::Front_Back; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::DepthFunction VKGL::Utils::get_depth_function_for_gl_enum(const GLenum& in_enum)
{
    VKGL::DepthFunction result = VKGL::DepthFunction::Unknown;

    switch (in_enum)
    {
        case GL_ALWAYS:   result = VKGL::DepthFunction::Always;   break;
        case GL_EQUAL:    result = VKGL::DepthFunction::Equal;    break;
        case GL_GEQUAL:   result = VKGL::DepthFunction::GEqual;   break;
        case GL_GREATER:  result = VKGL::DepthFunction::Greater;  break;
        case GL_LEQUAL:   result = VKGL::DepthFunction::LEqual;   break;
        case GL_LESS:     result = VKGL::DepthFunction::Less;     break;
        case GL_NEVER:    result = VKGL::DepthFunction::Never;    break;
        case GL_NOTEQUAL: result = VKGL::DepthFunction::NotEqual; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::DepthStencilTextureMode VKGL::Utils::get_depth_stencil_texture_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::DepthStencilTextureMode result = VKGL::DepthStencilTextureMode::Unknown;

    switch (in_enum)
    {
        case GL_DEPTH_COMPONENT: result = VKGL::DepthStencilTextureMode::Depth_Component; break;
        case GL_STENCIL_INDEX:   result = VKGL::DepthStencilTextureMode::Stencil_Index;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FrontFaceOrientation VKGL::Utils::get_front_face_orientation_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FrontFaceOrientation result = VKGL::FrontFaceOrientation::Unknown;

    switch (in_enum)
    {
        case GL_CW:  result = VKGL::FrontFaceOrientation::Clockwise;         break;
        case GL_CCW: result = VKGL::FrontFaceOrientation::Counter_Clockwise; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_blend_function(const VKGL::BlendFunction& in_blend_func)
{
    GLenum result = 0;

    switch (in_blend_func)
    {
        case VKGL::BlendFunction::Constant_Alpha:           result = GL_CONSTANT_ALPHA;           break;
        case VKGL::BlendFunction::Constant_Color:           result = GL_CONSTANT_COLOR;           break;
        case VKGL::BlendFunction::Dst_Alpha:                result = GL_DST_ALPHA;                break;
        case VKGL::BlendFunction::Dst_Color:                result = GL_DST_COLOR;                break;
        case VKGL::BlendFunction::One:                      result = GL_ONE;                      break;
        case VKGL::BlendFunction::One_Minus_Constant_Alpha: result = GL_ONE_MINUS_CONSTANT_ALPHA; break;
        case VKGL::BlendFunction::One_Minus_Constant_Color: result = GL_ONE_MINUS_CONSTANT_COLOR; break;
        case VKGL::BlendFunction::One_Minus_Dst_Alpha:      result = GL_ONE_MINUS_DST_ALPHA;      break;
        case VKGL::BlendFunction::One_Minus_Dst_Color:      result = GL_ONE_MINUS_DST_COLOR;      break;
        case VKGL::BlendFunction::One_Minus_Src_Alpha:      result = GL_ONE_MINUS_SRC_ALPHA;      break;
        case VKGL::BlendFunction::One_Minus_Src_Color:      result = GL_ONE_MINUS_SRC_COLOR;      break;
        case VKGL::BlendFunction::Src_Alpha:                result = GL_SRC_ALPHA;                break;
        case VKGL::BlendFunction::Src_Alpha_Saturate:       result = GL_SRC_ALPHA_SATURATE;       break;
        case VKGL::BlendFunction::Src_Color:                result = GL_SRC_COLOR;                break;
        case VKGL::BlendFunction::Zero:                     result = GL_ZERO;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_clear_buffer_bits(const VKGL::ClearBufferBits& in_buffers)
{
    GLenum result = 0;

    if (in_buffers & VKGL::ClearBufferBit::CLEAR_BUFFER_BIT_COLOR)
    {
        result |= GL_COLOR_BUFFER_BIT;
    }

    if (in_buffers & VKGL::ClearBufferBit::CLEAR_BUFFER_BIT_DEPTH)
    {
        result |= GL_DEPTH_BUFFER_BIT;
    }

    if (in_buffers & VKGL::ClearBufferBit::CLEAR_BUFFER_BIT_STENCIL)
    {
        result |= GL_STENCIL_BUFFER_BIT;
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_cull_mode(const VKGL::CullMode& in_cull_mode)
{
    GLenum result = 0;

    switch (in_cull_mode)
    {
        case VKGL::CullMode::Back:       result = GL_BACK;           break;
        case VKGL::CullMode::Front:      result = GL_FRONT;          break;
        case VKGL::CullMode::Front_Back: result = GL_FRONT_AND_BACK; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_depth_function(const VKGL::DepthFunction& in_depth_function)
{
    GLenum result = 0;

    switch (in_depth_function)
    {
        case VKGL::DepthFunction::Always:   result = GL_ALWAYS;   break;
        case VKGL::DepthFunction::Equal:    result = GL_EQUAL;    break;
        case VKGL::DepthFunction::GEqual:   result = GL_GEQUAL;   break;
        case VKGL::DepthFunction::Greater:  result = GL_GREATER;  break;
        case VKGL::DepthFunction::LEqual:   result = GL_LEQUAL;   break;
        case VKGL::DepthFunction::Less:     result = GL_LESS;     break;
        case VKGL::DepthFunction::Never:    result = GL_NEVER;    break;
        case VKGL::DepthFunction::NotEqual: result = GL_NOTEQUAL; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_depth_stencil_texture_mode(const VKGL::DepthStencilTextureMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case VKGL::DepthStencilTextureMode::Depth_Component: result = GL_DEPTH_COMPONENT; break;
        case VKGL::DepthStencilTextureMode::Stencil_Index:   result = GL_STENCIL_INDEX;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation)
{
    GLenum result = 0;

    switch (in_orientation)
    {
        case VKGL::FrontFaceOrientation::Clockwise:         result = GL_CW;  break;
        case VKGL::FrontFaceOrientation::Counter_Clockwise: result = GL_CCW; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_hint_mode(const VKGL::HintMode& in_hint_mode)
{
    GLenum result = 0;

    switch (in_hint_mode)
    {
        case VKGL::HintMode::Dont_Care: result = GL_DONT_CARE; break;
        case VKGL::HintMode::Fastest:   result = GL_FASTEST;   break;
        case VKGL::HintMode::Nicest:    result = GL_NICEST;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_indexed_capability(const VKGL::Capability& in_capability,
                                                       const uint32_t&         in_index)
{
    GLenum result  = 0;

    switch (in_capability)
    {
        case VKGL::Capability::Clip_Distance:
        {
            vkgl_assert(in_index < 8); /* todo: replace magic numver with context-specific constant? */

            result = GL_CLIP_DISTANCE0 + in_index;
            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_internal_format(const VKGL::InternalFormat& in_internal_format)
{
    GLenum result = 0;

    switch (in_internal_format)
    {
        /* Base internal formats */
        case VKGL::InternalFormat::Depth_Component: result = GL_DEPTH_COMPONENT; break;
        case VKGL::InternalFormat::Depth_Stencil:   result = GL_DEPTH_STENCIL;   break;
        case VKGL::InternalFormat::Red:             result = GL_RED;             break;
        case VKGL::InternalFormat::RG:              result = GL_RG;              break;
        case VKGL::InternalFormat::RGB:             result = GL_RGB;             break;
        case VKGL::InternalFormat::RGBA:            result = GL_RGBA;            break;

        /* Sized internal formats */
        case VKGL::InternalFormat::R11F_G11F_B10F: result = GL_R11F_G11F_B10F; break;
        case VKGL::InternalFormat::R16:            result = GL_R16;            break;
        case VKGL::InternalFormat::R16_SNorm:      result = GL_R16_SNORM;      break;
        case VKGL::InternalFormat::R16F:           result = GL_R16F;           break;
        case VKGL::InternalFormat::R16I:           result = GL_R16I;           break;
        case VKGL::InternalFormat::R16UI:          result = GL_R16UI;          break;
        case VKGL::InternalFormat::R3_G3_B2:       result = GL_R3_G3_B2;       break;
        case VKGL::InternalFormat::R32F:           result = GL_R32F;           break;
        case VKGL::InternalFormat::R32I:           result = GL_R32I;           break;
        case VKGL::InternalFormat::R32UI:          result = GL_R32UI;          break;
        case VKGL::InternalFormat::R8:             result = GL_R8;             break;
        case VKGL::InternalFormat::R8_SNorm:       result = GL_R8_SNORM;       break;
        case VKGL::InternalFormat::R8I:            result = GL_R8I;            break;
        case VKGL::InternalFormat::R8UI:           result = GL_R8UI;           break;
        case VKGL::InternalFormat::RG16:           result = GL_RG16;           break;
        case VKGL::InternalFormat::RG16_SNorm:     result = GL_RG16_SNORM;     break;
        case VKGL::InternalFormat::RG16F:          result = GL_RG16F;          break;
        case VKGL::InternalFormat::RG16I:          result = GL_RG16I;          break;
        case VKGL::InternalFormat::RG16UI:         result = GL_RG16UI;         break;
        case VKGL::InternalFormat::RG32F:          result = GL_RG32F;          break;
        case VKGL::InternalFormat::RG32I:          result = GL_RG32I;          break;
        case VKGL::InternalFormat::RG32UI:         result = GL_RG32UI;         break;
        case VKGL::InternalFormat::RG8:            result = GL_RG8;            break;
        case VKGL::InternalFormat::RG8_SNorm:      result = GL_RG8_SNORM;      break;
        case VKGL::InternalFormat::RG8I:           result = GL_RG8I;           break;
        case VKGL::InternalFormat::RG8UI:          result = GL_RG8UI;          break;
        case VKGL::InternalFormat::RGB10:          result = GL_RGB10;          break;
        case VKGL::InternalFormat::RGB10_A2:       result = GL_RGB10_A2;       break;
        case VKGL::InternalFormat::RGB10_A2UI:     result = GL_RGB10_A2UI;     break;
        case VKGL::InternalFormat::RGB12:          result = GL_RGB12;          break;
        case VKGL::InternalFormat::RGB16_SNorm:    result = GL_RGB16_SNORM;    break;
        case VKGL::InternalFormat::RGB16F:         result = GL_RGB16F;         break;
        case VKGL::InternalFormat::RGB16I:         result = GL_RGB16I;         break;
        case VKGL::InternalFormat::RGB16UI:        result = GL_RGB16UI;        break;
        case VKGL::InternalFormat::RGB32F:         result = GL_RGB32F;         break;
        case VKGL::InternalFormat::RGB32I:         result = GL_RGB32I;         break;
        case VKGL::InternalFormat::RGB32UI:        result = GL_RGB32UI;        break;
        case VKGL::InternalFormat::RGB4:           result = GL_RGB4;           break;
        case VKGL::InternalFormat::RGB5:           result = GL_RGB5;           break;
        case VKGL::InternalFormat::RGB5_A1:        result = GL_RGB5_A1;        break;
        case VKGL::InternalFormat::RGB8:           result = GL_RGB8;           break;
        case VKGL::InternalFormat::RGB8_SNorm:     result = GL_RGB8_SNORM;     break;
        case VKGL::InternalFormat::RGB8I:          result = GL_RGB8I;          break;
        case VKGL::InternalFormat::RGB8UI:         result = GL_RGB8UI;         break;
        case VKGL::InternalFormat::RGB9_E5:        result = GL_RGB9_E5;        break;
        case VKGL::InternalFormat::RGBA12:         result = GL_RGBA12;         break;
        case VKGL::InternalFormat::RGBA16:         result = GL_RGBA16;         break;
        case VKGL::InternalFormat::RGBA16F:        result = GL_RGBA16F;        break;
        case VKGL::InternalFormat::RGBA16I:        result = GL_RGBA16I;        break;
        case VKGL::InternalFormat::RGBA16UI:       result = GL_RGBA16UI;       break;
        case VKGL::InternalFormat::RGBA2:          result = GL_RGBA2;          break;
        case VKGL::InternalFormat::RGBA32F:        result = GL_RGBA32F;        break;
        case VKGL::InternalFormat::RGBA32I:        result = GL_RGBA32I;        break;
        case VKGL::InternalFormat::RGBA32UI:       result = GL_RGBA32UI;       break;
        case VKGL::InternalFormat::RGBA4:          result = GL_RGBA4;          break;
        case VKGL::InternalFormat::RGBA8:          result = GL_RGBA8;          break;
        case VKGL::InternalFormat::RGBA8_SNorm:    result = GL_RGBA8_SNORM;    break;
        case VKGL::InternalFormat::RGBA8I:         result = GL_RGBA8I;         break;
        case VKGL::InternalFormat::RGBA8UI:        result = GL_RGBA8UI;        break;
        case VKGL::InternalFormat::SRGB8:          result = GL_SRGB8;          break;
        case VKGL::InternalFormat::SRGB8_Alpha8:   result = GL_SRGB8_ALPHA8;   break;

        /* Compressed internal formats */
        case VKGL::InternalFormat::Compressed_Red:                     result = GL_COMPRESSED_RED;                     break;
        case VKGL::InternalFormat::Compressed_Red_RGTC1:               result = GL_COMPRESSED_RED_RGTC1;               break;
        case VKGL::InternalFormat::Compressed_RG:                      result = GL_COMPRESSED_RG;                      break;
        case VKGL::InternalFormat::Compressed_RG_RGTC2:                result = GL_COMPRESSED_RG_RGTC2;                break;
        case VKGL::InternalFormat::Compressed_RGB:                     result = GL_COMPRESSED_RGB;                     break;
        case VKGL::InternalFormat::Compressed_RGB_BPTC_Signed_Float:   result = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT;   break;
        case VKGL::InternalFormat::Compressed_RGB_BPTC_Unsigned_Float: result = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT; break;
        case VKGL::InternalFormat::Compressed_RGBA:                    result = GL_COMPRESSED_RGBA;                    break;
        case VKGL::InternalFormat::Compressed_RGBA_BPTC_UNorm:         result = GL_COMPRESSED_RGBA_BPTC_UNORM;         break;
        case VKGL::InternalFormat::Compressed_Signed_Red_RGTC1:        result = GL_COMPRESSED_SIGNED_RED_RGTC1;        break;
        case VKGL::InternalFormat::Compressed_Signed_RG_RGTC2:         result = GL_COMPRESSED_SIGNED_RG_RGTC2;         break;
        case VKGL::InternalFormat::Compressed_SRGB:                    result = GL_COMPRESSED_SRGB;                    break;
        case VKGL::InternalFormat::Compressed_SRGB_Alpha:              result = GL_COMPRESSED_SRGB_ALPHA;              break;
        case VKGL::InternalFormat::Compressed_SRGB_Alpha_BPTC_UNorm:   result = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_logic_op_mode(const VKGL::LogicOpMode& in_logic_op_mode)
{
    GLenum result = 0;

    switch (in_logic_op_mode)
    {
        case VKGL::LogicOpMode::And:           result = GL_AND;           break;
        case VKGL::LogicOpMode::And_Inverted:  result = GL_AND_INVERTED;  break;
        case VKGL::LogicOpMode::And_Reverse:   result = GL_AND_REVERSE;   break;
        case VKGL::LogicOpMode::Clear:         result = GL_CLEAR;         break;
        case VKGL::LogicOpMode::Copy:          result = GL_COPY;          break;
        case VKGL::LogicOpMode::Copy_Inverted: result = GL_COPY_INVERTED; break;
        case VKGL::LogicOpMode::Equiv:         result = GL_EQUIV;         break;
        case VKGL::LogicOpMode::Invert:        result = GL_INVERT;        break;
        case VKGL::LogicOpMode::Nand:          result = GL_NAND;          break;
        case VKGL::LogicOpMode::Noop:          result = GL_NOOP;          break;
        case VKGL::LogicOpMode::Nor:           result = GL_NOR;           break;
        case VKGL::LogicOpMode::Or:            result = GL_OR;            break;
        case VKGL::LogicOpMode::Or_Inverted:   result = GL_OR_INVERTED;   break;
        case VKGL::LogicOpMode::Or_Reverse:    result = GL_OR_REVERSE;    break;
        case VKGL::LogicOpMode::Set:           result = GL_SET;           break;
        case VKGL::LogicOpMode::Xor:           result = GL_XOR;           break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_nonindexed_capability(const VKGL::Capability& in_capability)
{
    GLenum result = 0;

    switch (in_capability)
    {
        case VKGL::Capability::Blend:                     result = GL_BLEND;                     break;
        case VKGL::Capability::Color_Logic_Op:            result = GL_COLOR_LOGIC_OP;            break;
        case VKGL::Capability::Cull_Face:                 result = GL_CULL_FACE;                 break;
        case VKGL::Capability::Depth_Clamp:               result = GL_DEPTH_CLAMP;               break;
        case VKGL::Capability::Depth_Test:                result = GL_DEPTH_TEST;                break;
        case VKGL::Capability::Dither:                    result = GL_DITHER;                    break;
        case VKGL::Capability::Framebuffer_SRGB:          result = GL_FRAMEBUFFER_SRGB;          break;
        case VKGL::Capability::Line_Smooth:               result = GL_LINE_SMOOTH;               break;
        case VKGL::Capability::Multisample:               result = GL_MULTISAMPLE;               break;
        case VKGL::Capability::Polygon_Offset_Fill:       result = GL_POLYGON_OFFSET_FILL;       break;
        case VKGL::Capability::Polygon_Offset_Line:       result = GL_POLYGON_OFFSET_LINE;       break;
        case VKGL::Capability::Polygon_Offset_Point:      result = GL_POLYGON_OFFSET_POINT;      break;
        case VKGL::Capability::Polygon_Smooth:            result = GL_POLYGON_SMOOTH;            break;
        case VKGL::Capability::Primitive_Restart:         result = GL_PRIMITIVE_RESTART;         break;
        case VKGL::Capability::Program_Point_Size:        result = GL_PROGRAM_POINT_SIZE;        break;
        case VKGL::Capability::Sample_Alpha_To_Coverage:  result = GL_SAMPLE_ALPHA_TO_COVERAGE;  break;
        case VKGL::Capability::Sample_Alpha_To_One:       result = GL_SAMPLE_ALPHA_TO_ONE;       break;
        case VKGL::Capability::Sample_Coverage:           result = GL_SAMPLE_COVERAGE;           break;
        case VKGL::Capability::Scissor_Test:              result = GL_SCISSOR_TEST;              break;
        case VKGL::Capability::Stencil_Test:              result = GL_STENCIL_TEST;              break;
        case VKGL::Capability::Texture_Cube_Map_Seamless: result = GL_TEXTURE_CUBE_MAP_SEAMLESS; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_pixel_format(const VKGL::PixelFormat& in_pixel_format)
{
    GLenum result = 0;

    switch (in_pixel_format)
    {
        case VKGL::PixelFormat::Blue:            result = GL_BLUE;            break;
        case VKGL::PixelFormat::Blue_Integer:    result = GL_BLUE_INTEGER;    break;
        case VKGL::PixelFormat::BGR:             result = GL_BGR;             break;
        case VKGL::PixelFormat::BGR_Integer:     result = GL_BGR_INTEGER;     break;
        case VKGL::PixelFormat::BGRA:            result = GL_BGRA;            break;
        case VKGL::PixelFormat::BGRA_Integer:    result = GL_BGRA_INTEGER;    break;
        case VKGL::PixelFormat::Depth_Component: result = GL_DEPTH_COMPONENT; break;
        case VKGL::PixelFormat::Depth_Stencil:   result = GL_DEPTH_STENCIL;   break;
        case VKGL::PixelFormat::Green:           result = GL_GREEN;           break;
        case VKGL::PixelFormat::Green_Integer:   result = GL_GREEN_INTEGER;   break;
        case VKGL::PixelFormat::Red:             result = GL_RED;             break;
        case VKGL::PixelFormat::Red_Integer:     result = GL_RED_INTEGER;     break;
        case VKGL::PixelFormat::RG:              result = GL_RG;              break;
        case VKGL::PixelFormat::RG_Integer:      result = GL_RG_INTEGER;      break;
        case VKGL::PixelFormat::RGB:             result = GL_RGB;             break;
        case VKGL::PixelFormat::RGB_Integer:     result = GL_RGB_INTEGER;     break;
        case VKGL::PixelFormat::RGBA:            result = GL_RGBA;            break;
        case VKGL::PixelFormat::RGBA_Integer:    result = GL_RGBA_INTEGER;    break;
        case VKGL::PixelFormat::Stencil_Index:   result = GL_STENCIL_INDEX;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_polygon_mode(const VKGL::PolygonMode& in_polygon_mode)
{
    GLenum result = 0;

    switch (in_polygon_mode)
    {
        case VKGL::PolygonMode::Fill:  result = GL_FILL;  break;
        case VKGL::PolygonMode::Line:  result = GL_LINE;  break;
        case VKGL::PolygonMode::Point: result = GL_POINT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_pixel_type(const VKGL::PixelType& in_pixel_type)
{
    GLenum result = 0;

    switch (in_pixel_type)
    {
        case VKGL::PixelType::Float:                          result = GL_FLOAT;                          break;
        case VKGL::PixelType::Float_32_Unsigned_Int_24_8_Rev: result = GL_FLOAT_32_UNSIGNED_INT_24_8_REV; break;
        case VKGL::PixelType::Half_Float:                     result = GL_HALF_FLOAT;                     break;
        case VKGL::PixelType::Int:                            result = GL_INT;                            break;
        case VKGL::PixelType::Short:                          result = GL_SHORT;                          break;
        case VKGL::PixelType::Unsigned_Byte:                  result = GL_UNSIGNED_BYTE;                  break;
        case VKGL::PixelType::Unsigned_Byte_2_3_3_Rev:        result = GL_UNSIGNED_BYTE_2_3_3_REV;        break;
        case VKGL::PixelType::Unsigned_Byte_3_3_2:            result = GL_UNSIGNED_BYTE_3_3_2;            break;
        case VKGL::PixelType::Unsigned_Int:                   result = GL_UNSIGNED_INT;                   break;
        case VKGL::PixelType::Unsigned_Int_10_10_10_2:        result = GL_UNSIGNED_INT_10_10_10_2;        break;
        case VKGL::PixelType::Unsigned_Int_10F_11F_11F_Rev:   result = GL_UNSIGNED_INT_10F_11F_11F_REV;   break;
        case VKGL::PixelType::Unsigned_Int_2_10_10_10_Rev:    result = GL_UNSIGNED_INT_2_10_10_10_REV;    break;
        case VKGL::PixelType::Unsigned_Int_24_8:              result = GL_UNSIGNED_INT_24_8;              break;
        case VKGL::PixelType::Unsigned_Int_5_9_9_9_Rev:       result = GL_UNSIGNED_INT_5_9_9_9_REV;       break;
        case VKGL::PixelType::Unsigned_Int_8_8_8_8:           result = GL_UNSIGNED_INT_8_8_8_8;           break;
        case VKGL::PixelType::Unsigned_Int_8_8_8_8_Rev:       result = GL_UNSIGNED_INT_8_8_8_8_REV;       break;
        case VKGL::PixelType::Unsigned_Short:                 result = GL_UNSIGNED_SHORT;                 break;
        case VKGL::PixelType::Unsigned_Short_1_5_5_5_Rev:     result = GL_UNSIGNED_SHORT_1_5_5_5_REV;     break;
        case VKGL::PixelType::Unsigned_Short_4_4_4_4:         result = GL_UNSIGNED_SHORT_4_4_4_4;         break;
        case VKGL::PixelType::Unsigned_Short_4_4_4_4_Rev:     result = GL_UNSIGNED_SHORT_4_4_4_4_REV;     break;
        case VKGL::PixelType::Unsigned_Short_5_5_5_1:         result = GL_UNSIGNED_SHORT_5_5_5_1;         break;
        case VKGL::PixelType::Unsigned_Short_5_6_5:           result = GL_UNSIGNED_SHORT_5_6_5;           break;
        case VKGL::PixelType::Unsigned_Short_5_6_5_Rev:       result = GL_UNSIGNED_SHORT_5_6_5_REV;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_stencil_function(const VKGL::StencilFunction& in_stencil_function)
{
    GLenum result = 0;

    switch (in_stencil_function)
    {
        case VKGL::StencilFunction::Always:   result = GL_ALWAYS;   break;
        case VKGL::StencilFunction::Equal:    result = GL_EQUAL;    break;
        case VKGL::StencilFunction::GEqual:   result = GL_GEQUAL;   break;
        case VKGL::StencilFunction::Greater:  result = GL_GREATER;  break;
        case VKGL::StencilFunction::LEqual:   result = GL_LEQUAL;   break;
        case VKGL::StencilFunction::Less:     result = GL_LESS;     break;
        case VKGL::StencilFunction::Never:    result = GL_NEVER;    break;
        case VKGL::StencilFunction::NotEqual: result = GL_NOTEQUAL; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_stencil_operation(const VKGL::StencilOperation& in_operation)
{
    GLenum result = 0;

    switch (in_operation)
    {
        case VKGL::StencilOperation::Decr:      result = GL_DECR;      break;
        case VKGL::StencilOperation::Decr_Wrap: result = GL_DECR_WRAP; break;
        case VKGL::StencilOperation::Incr:      result = GL_INCR;      break;
        case VKGL::StencilOperation::Incr_Wrap: result = GL_INCR_WRAP; break;
        case VKGL::StencilOperation::Invert:    result = GL_INVERT;    break;
        case VKGL::StencilOperation::Keep:      result = GL_KEEP;      break;
        case VKGL::StencilOperation::Replace:   result = GL_REPLACE;   break;
        case VKGL::StencilOperation::Zero:      result = GL_ZERO;      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_compare_function(const VKGL::TextureCompareFunction& in_compare_function)
{
    GLenum result = 0;

    switch (in_compare_function)
    {
        case VKGL::TextureCompareFunction::Always:   result = GL_ALWAYS;   break;
        case VKGL::TextureCompareFunction::Equal:    result = GL_EQUAL;    break;
        case VKGL::TextureCompareFunction::GEqual:   result = GL_GEQUAL;   break;
        case VKGL::TextureCompareFunction::Greater:  result = GL_GREATER;  break;
        case VKGL::TextureCompareFunction::LEqual:   result = GL_LEQUAL;   break;
        case VKGL::TextureCompareFunction::Less:     result = GL_LESS;     break;
        case VKGL::TextureCompareFunction::Never:    result = GL_NEVER;    break;
        case VKGL::TextureCompareFunction::NotEqual: result = GL_NOTEQUAL; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_compare_mode(const VKGL::TextureCompareMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case VKGL::TextureCompareMode::Compare_Ref_to_Texture: result = GL_COMPARE_REF_TO_TEXTURE; break;
        case VKGL::TextureCompareMode::None:                   result = GL_NONE;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_mag_filter(const VKGL::TextureMagFilter& in_filter)
{
    GLenum result = 0;

    switch (in_filter)
    {
        case VKGL::TextureMagFilter::Linear:  result = GL_LINEAR;  break;
        case VKGL::TextureMagFilter::Nearest: result = GL_NEAREST; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_min_filter(const VKGL::TextureMinFilter& in_filter)
{
    GLenum result = 0;

    switch (in_filter)
    {
        case VKGL::TextureMinFilter::Linear:                 result = GL_LINEAR;                 break;
        case VKGL::TextureMinFilter::Linear_Mipmap_Linear:   result = GL_LINEAR_MIPMAP_LINEAR;   break;
        case VKGL::TextureMinFilter::Linear_Mipmap_Nearest:  result = GL_LINEAR_MIPMAP_NEAREST;  break;
        case VKGL::TextureMinFilter::Nearest:                result = GL_NEAREST;                break;
        case VKGL::TextureMinFilter::Nearest_Mipmap_Linear:  result = GL_NEAREST_MIPMAP_LINEAR;  break;
        case VKGL::TextureMinFilter::Nearest_Mipmap_Nearest: result = GL_NEAREST_MIPMAP_NEAREST; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_swizzle(const VKGL::TextureSwizzle& in_swizzle)
{
    GLenum result = 0;

    switch (in_swizzle)
    {
        case VKGL::TextureSwizzle::Alpha: result = GL_ALPHA; break;
        case VKGL::TextureSwizzle::Blue:  result = GL_BLUE;  break;
        case VKGL::TextureSwizzle::Green: result = GL_GREEN; break;
        case VKGL::TextureSwizzle::One:   result = GL_ONE;   break;
        case VKGL::TextureSwizzle::Red:   result = GL_RED;   break;
        case VKGL::TextureSwizzle::Zero:  result = GL_ZERO;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_target(const VKGL::TextureTarget& in_texture_target)
{
    GLenum result = 0;

    switch (in_texture_target)
    {
        case VKGL::TextureTarget::_1D:                                result = GL_TEXTURE_1D;                         break;
        case VKGL::TextureTarget::_1D_Array:                          result = GL_TEXTURE_1D_ARRAY;                   break;
        case VKGL::TextureTarget::_2D:                                result = GL_TEXTURE_2D;                         break;
        case VKGL::TextureTarget::_2D_Array:                          result = GL_TEXTURE_2D_ARRAY;                   break;
        case VKGL::TextureTarget::_2D_Multisample:                    result = GL_TEXTURE_2D_MULTISAMPLE;             break;
        case VKGL::TextureTarget::_2D_Multisample_Array:              result = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;       break;
        case VKGL::TextureTarget::_3D:                                result = GL_TEXTURE_3D;                         break;
        case VKGL::TextureTarget::Cube_Map_Negative_X:                result = GL_TEXTURE_CUBE_MAP_NEGATIVE_X;        break;
        case VKGL::TextureTarget::Cube_Map_Negative_Y:                result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;        break;
        case VKGL::TextureTarget::Cube_Map_Negative_Z:                result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;        break;
        case VKGL::TextureTarget::Cube_Map_Positive_X:                result = GL_TEXTURE_CUBE_MAP_POSITIVE_X;        break;
        case VKGL::TextureTarget::Cube_Map_Positive_Y:                result = GL_TEXTURE_CUBE_MAP_POSITIVE_Y;        break;
        case VKGL::TextureTarget::Cube_Map_Positive_Z:                result = GL_TEXTURE_CUBE_MAP_POSITIVE_Z;        break;
        case VKGL::TextureTarget::Proxy_Texture_1D:                   result = GL_PROXY_TEXTURE_1D;                   break;
        case VKGL::TextureTarget::Proxy_Texture_1D_Array:             result = GL_PROXY_TEXTURE_1D_ARRAY;             break;
        case VKGL::TextureTarget::Proxy_Texture_2D:                   result = GL_PROXY_TEXTURE_2D;                   break;
        case VKGL::TextureTarget::Proxy_Texture_2D_Array:             result = GL_PROXY_TEXTURE_2D_ARRAY;             break;
        case VKGL::TextureTarget::Proxy_Texture_2D_Multisample:       result = GL_PROXY_TEXTURE_2D_MULTISAMPLE;       break;
        case VKGL::TextureTarget::Proxy_Texture_2D_Multisample_Array: result = GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY; break;
        case VKGL::TextureTarget::Proxy_Texture_3D:                   result = GL_PROXY_TEXTURE_3D;                   break;
        case VKGL::TextureTarget::Proxy_Texture_Cube_Map:             result = GL_PROXY_TEXTURE_CUBE_MAP;             break;
        case VKGL::TextureTarget::Proxy_Texture_Rectangle:            result = GL_PROXY_TEXTURE_RECTANGLE;            break;
        case VKGL::TextureTarget::Rectangle:                          result = GL_TEXTURE_RECTANGLE;                  break;
        case VKGL::TextureTarget::Texture_Buffer:                     result = GL_TEXTURE_BUFFER;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_wrap_mode(const VKGL::TextureWrapMode& in_wrap_mode)
{
    GLenum result = 0;

    switch (in_wrap_mode)
    {
        case VKGL::TextureWrapMode::Clamp_To_Border:      result = GL_CLAMP_TO_BORDER;      break;
        case VKGL::TextureWrapMode::Clamp_To_Edge:        result = GL_CLAMP_TO_EDGE;        break;
        case VKGL::TextureWrapMode::Mirror_Clamp_to_Edge: result = GL_MIRROR_CLAMP_TO_EDGE; break;
        case VKGL::TextureWrapMode::Mirrored_Repeat:      result = GL_MIRRORED_REPEAT;      break;
        case VKGL::TextureWrapMode::Repeat:               result = GL_REPEAT;               break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::HintMode VKGL::Utils::get_hint_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::HintMode result = VKGL::HintMode::Unknown;

    switch (in_enum)
    {
        case GL_DONT_CARE: result = VKGL::HintMode::Dont_Care; break;
        case GL_FASTEST:   result = VKGL::HintMode::Fastest;   break;
        case GL_NICEST:    result = VKGL::HintMode::Nicest;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

void VKGL::Utils::get_indexed_capability_for_gl_enum(const GLenum&    in_enum,
                                                    VKGL::Capability* out_capability_ptr,
                                                    uint32_t*         out_index_ptr)
{
    if (in_enum >= GL_CLIP_DISTANCE0 &&
        in_enum <= GL_CLIP_DISTANCE7)   /* todo: there may be more clip distances supported ! */
    {
        *out_capability_ptr = VKGL::Capability::Clip_Distance;
        *out_index_ptr      = in_enum - GL_CLIP_DISTANCE0;
    }
    else
    {
        vkgl_assert_fail();

        *out_capability_ptr = VKGL::Capability::Unknown;
    }
}

VKGL::InternalFormat VKGL::Utils::get_internal_format_for_gl_enum(const GLenum& in_enum)
{
    VKGL::InternalFormat result = VKGL::InternalFormat::Unknown;

    switch (in_enum)
    {
        /* Base internal formats */
        case GL_DEPTH_COMPONENT: result = VKGL::InternalFormat::Depth_Component; break;
        case GL_DEPTH_STENCIL:   result = VKGL::InternalFormat::Depth_Stencil;   break;
        case GL_RED:             result = VKGL::InternalFormat::Red;             break;
        case GL_RG:              result = VKGL::InternalFormat::RG;              break;
        case GL_RGB:             result = VKGL::InternalFormat::RGB;             break;
        case GL_RGBA:            result = VKGL::InternalFormat::RGBA;            break;

        /* Sized internal formats */
        case GL_R11F_G11F_B10F: result = VKGL::InternalFormat::R11F_G11F_B10F; break;
        case GL_R16:            result = VKGL::InternalFormat::R16;            break;
        case GL_R16_SNORM:      result = VKGL::InternalFormat::R16_SNorm;      break;
        case GL_R16F:           result = VKGL::InternalFormat::R16F;           break;
        case GL_R16I:           result = VKGL::InternalFormat::R16I;           break;
        case GL_R16UI:          result = VKGL::InternalFormat::R16UI;          break;
        case GL_R3_G3_B2:       result = VKGL::InternalFormat::R3_G3_B2;       break;
        case GL_R32F:           result = VKGL::InternalFormat::R32F;           break;
        case GL_R32I:           result = VKGL::InternalFormat::R32I;           break;
        case GL_R32UI:          result = VKGL::InternalFormat::R32UI;          break;
        case GL_R8:             result = VKGL::InternalFormat::R8;             break;
        case GL_R8_SNORM:       result = VKGL::InternalFormat::R8_SNorm;       break;
        case GL_R8I:            result = VKGL::InternalFormat::R8I;            break;
        case GL_R8UI:           result = VKGL::InternalFormat::R8UI;           break;
        case GL_RG16:           result = VKGL::InternalFormat::RG16;           break;
        case GL_RG16_SNORM:     result = VKGL::InternalFormat::RG16_SNorm;     break;
        case GL_RG16F:          result = VKGL::InternalFormat::RG16F;          break;
        case GL_RG16I:          result = VKGL::InternalFormat::RG16I;          break;
        case GL_RG16UI:         result = VKGL::InternalFormat::RG16UI;         break;
        case GL_RG32F:          result = VKGL::InternalFormat::RG32F;          break;
        case GL_RG32I:          result = VKGL::InternalFormat::RG32I;          break;
        case GL_RG32UI:         result = VKGL::InternalFormat::RG32UI;         break;
        case GL_RG8:            result = VKGL::InternalFormat::RG8;            break;
        case GL_RG8_SNORM:      result = VKGL::InternalFormat::RG8_SNorm;      break;
        case GL_RG8I:           result = VKGL::InternalFormat::RG8I;           break;
        case GL_RG8UI:          result = VKGL::InternalFormat::RG8UI;          break;
        case GL_RGB10:          result = VKGL::InternalFormat::RGB10;          break;
        case GL_RGB10_A2:       result = VKGL::InternalFormat::RGB10_A2;       break;
        case GL_RGB10_A2UI:     result = VKGL::InternalFormat::RGB10_A2UI;     break;
        case GL_RGB12:          result = VKGL::InternalFormat::RGB12;          break;
        case GL_RGB16_SNORM:    result = VKGL::InternalFormat::RGB16_SNorm;    break;
        case GL_RGB16F:         result = VKGL::InternalFormat::RGB16F;         break;
        case GL_RGB16I:         result = VKGL::InternalFormat::RGB16I;         break;
        case GL_RGB16UI:        result = VKGL::InternalFormat::RGB16UI;        break;
        case GL_RGB32F:         result = VKGL::InternalFormat::RGB32F;         break;
        case GL_RGB32I:         result = VKGL::InternalFormat::RGB32I;         break;
        case GL_RGB32UI:        result = VKGL::InternalFormat::RGB32UI;        break;
        case GL_RGB4:           result = VKGL::InternalFormat::RGB4;           break;
        case GL_RGB5:           result = VKGL::InternalFormat::RGB5;           break;
        case GL_RGB5_A1:        result = VKGL::InternalFormat::RGB5_A1;        break;
        case GL_RGB8:           result = VKGL::InternalFormat::RGB8;           break;
        case GL_RGB8_SNORM:     result = VKGL::InternalFormat::RGB8_SNorm;     break;
        case GL_RGB8I:          result = VKGL::InternalFormat::RGB8I;          break;
        case GL_RGB8UI:         result = VKGL::InternalFormat::RGB8UI;         break;
        case GL_RGB9_E5:        result = VKGL::InternalFormat::RGB9_E5;        break;
        case GL_RGBA12:         result = VKGL::InternalFormat::RGBA12;         break;
        case GL_RGBA16:         result = VKGL::InternalFormat::RGBA16;         break;
        case GL_RGBA16F:        result = VKGL::InternalFormat::RGBA16F;        break;
        case GL_RGBA16I:        result = VKGL::InternalFormat::RGBA16I;        break;
        case GL_RGBA16UI:       result = VKGL::InternalFormat::RGBA16UI;       break;
        case GL_RGBA2:          result = VKGL::InternalFormat::RGBA2;          break;
        case GL_RGBA32F:        result = VKGL::InternalFormat::RGBA32F;        break;
        case GL_RGBA32I:        result = VKGL::InternalFormat::RGBA32I;        break;
        case GL_RGBA32UI:       result = VKGL::InternalFormat::RGBA32UI;       break;
        case GL_RGBA4:          result = VKGL::InternalFormat::RGBA4;          break;
        case GL_RGBA8:          result = VKGL::InternalFormat::RGBA8;          break;
        case GL_RGBA8_SNORM:    result = VKGL::InternalFormat::RGBA8_SNorm;    break;
        case GL_RGBA8I:         result = VKGL::InternalFormat::RGBA8I;         break;
        case GL_RGBA8UI:        result = VKGL::InternalFormat::RGBA8UI;        break;
        case GL_SRGB8:          result = VKGL::InternalFormat::SRGB8;          break;
        case GL_SRGB8_ALPHA8:   result = VKGL::InternalFormat::SRGB8_Alpha8;   break;

        /* Compressed internal formats */
        case GL_COMPRESSED_RED:                     result = VKGL::InternalFormat::Compressed_Red;                     break;
        case GL_COMPRESSED_RED_RGTC1:               result = VKGL::InternalFormat::Compressed_Red_RGTC1;               break;
        case GL_COMPRESSED_RG:                      result = VKGL::InternalFormat::Compressed_RG;                      break;
        case GL_COMPRESSED_RG_RGTC2:                result = VKGL::InternalFormat::Compressed_RG_RGTC2;                break;
        case GL_COMPRESSED_RGB:                     result = VKGL::InternalFormat::Compressed_RGB;                     break;
        case GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:   result = VKGL::InternalFormat::Compressed_RGB_BPTC_Signed_Float;   break;
        case GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT: result = VKGL::InternalFormat::Compressed_RGB_BPTC_Unsigned_Float; break;
        case GL_COMPRESSED_RGBA:                    result = VKGL::InternalFormat::Compressed_RGBA;                    break;
        case GL_COMPRESSED_RGBA_BPTC_UNORM:         result = VKGL::InternalFormat::Compressed_RGBA_BPTC_UNorm;         break;
        case GL_COMPRESSED_SIGNED_RED_RGTC1:        result = VKGL::InternalFormat::Compressed_Signed_Red_RGTC1;        break;
        case GL_COMPRESSED_SIGNED_RG_RGTC2:         result = VKGL::InternalFormat::Compressed_Signed_RG_RGTC2;         break;
        case GL_COMPRESSED_SRGB:                    result = VKGL::InternalFormat::Compressed_SRGB;                    break;
        case GL_COMPRESSED_SRGB_ALPHA:              result = VKGL::InternalFormat::Compressed_SRGB_Alpha;              break;
        case GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:   result = VKGL::InternalFormat::Compressed_SRGB_Alpha_BPTC_UNorm;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::LogicOpMode VKGL::Utils::get_logic_op_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::LogicOpMode result = VKGL::LogicOpMode::Unknown;

    switch (in_enum)
    {
        case GL_AND:           result = VKGL::LogicOpMode::And;            break;
        case GL_AND_INVERTED:  result = VKGL::LogicOpMode::And_Inverted;   break;
        case GL_AND_REVERSE:   result = VKGL::LogicOpMode::And_Reverse;    break;
        case GL_CLEAR:         result = VKGL::LogicOpMode::Clear;          break;
        case GL_COPY:          result = VKGL::LogicOpMode::Copy;           break;
        case GL_COPY_INVERTED: result = VKGL::LogicOpMode::Copy_Inverted;  break;
        case GL_EQUIV:         result = VKGL::LogicOpMode::Equiv;          break;
        case GL_INVERT:        result = VKGL::LogicOpMode::Invert;         break;
        case GL_NAND:          result = VKGL::LogicOpMode::Nand;           break;
        case GL_NOOP:          result = VKGL::LogicOpMode::Noop;           break;
        case GL_NOR:           result = VKGL::LogicOpMode::Nor;            break;
        case GL_OR:            result = VKGL::LogicOpMode::Or;             break;
        case GL_OR_INVERTED:   result = VKGL::LogicOpMode::Or_Inverted;    break;
        case GL_OR_REVERSE:    result = VKGL::LogicOpMode::Or_Reverse;     break;
        case GL_SET:           result = VKGL::LogicOpMode::Set;            break;
        case GL_XOR:           result = VKGL::LogicOpMode::Xor;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::Capability VKGL::Utils::get_nonindexed_capability_for_gl_enum(const GLenum& in_enum)
{
    VKGL::Capability result = VKGL::Capability::Unknown;

    switch (in_enum)
    {
        case GL_BLEND:                     result = VKGL::Capability::Blend;                     break;
        case GL_COLOR_LOGIC_OP:            result = VKGL::Capability::Color_Logic_Op;            break;
        case GL_CULL_FACE:                 result = VKGL::Capability::Cull_Face;                 break;
        case GL_DEPTH_CLAMP:               result = VKGL::Capability::Depth_Clamp;               break;
        case GL_DEPTH_TEST:                result = VKGL::Capability::Depth_Test;                break;
        case GL_DITHER:                    result = VKGL::Capability::Dither;                    break;
        case GL_FRAMEBUFFER_SRGB:          result = VKGL::Capability::Framebuffer_SRGB;          break;
        case GL_LINE_SMOOTH:               result = VKGL::Capability::Line_Smooth;               break;
        case GL_MULTISAMPLE:               result = VKGL::Capability::Multisample;               break;
        case GL_POLYGON_OFFSET_FILL:       result = VKGL::Capability::Polygon_Offset_Fill;       break;
        case GL_POLYGON_OFFSET_LINE:       result = VKGL::Capability::Polygon_Offset_Line;       break;
        case GL_POLYGON_OFFSET_POINT:      result = VKGL::Capability::Polygon_Offset_Point;      break;
        case GL_POLYGON_SMOOTH:            result = VKGL::Capability::Polygon_Smooth;            break;
        case GL_PRIMITIVE_RESTART:         result = VKGL::Capability::Primitive_Restart;         break;
        case GL_PROGRAM_POINT_SIZE:        result = VKGL::Capability::Program_Point_Size;        break;
        case GL_SAMPLE_ALPHA_TO_COVERAGE:  result = VKGL::Capability::Sample_Alpha_To_Coverage;  break;
        case GL_SAMPLE_ALPHA_TO_ONE:       result = VKGL::Capability::Sample_Alpha_To_One;       break;
        case GL_SAMPLE_COVERAGE:           result = VKGL::Capability::Sample_Coverage;           break;
        case GL_SCISSOR_TEST:              result = VKGL::Capability::Scissor_Test;              break;
        case GL_STENCIL_TEST:              result = VKGL::Capability::Stencil_Test;              break;
        case GL_TEXTURE_CUBE_MAP_SEAMLESS: result = VKGL::Capability::Texture_Cube_Map_Seamless; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::PixelFormat VKGL::Utils::get_pixel_format_for_gl_enum(const GLenum& in_enum)
{
    VKGL::PixelFormat result = VKGL::PixelFormat::Unknown;

    switch (in_enum)
    {
        case GL_BLUE:            result = VKGL::PixelFormat::Blue;            break;
        case GL_BLUE_INTEGER:    result = VKGL::PixelFormat::Blue_Integer;    break;
        case GL_BGR:             result = VKGL::PixelFormat::BGR;             break;
        case GL_BGR_INTEGER:     result = VKGL::PixelFormat::BGR_Integer;     break;
        case GL_BGRA:            result = VKGL::PixelFormat::BGRA;            break;
        case GL_BGRA_INTEGER:    result = VKGL::PixelFormat::BGRA_Integer;    break;
        case GL_DEPTH_COMPONENT: result = VKGL::PixelFormat::Depth_Component; break;
        case GL_DEPTH_STENCIL:   result = VKGL::PixelFormat::Depth_Stencil;   break;
        case GL_GREEN:           result = VKGL::PixelFormat::Green;           break;
        case GL_GREEN_INTEGER:   result = VKGL::PixelFormat::Green_Integer;   break;
        case GL_RED:             result = VKGL::PixelFormat::Red;             break;
        case GL_RED_INTEGER:     result = VKGL::PixelFormat::Red_Integer;     break;
        case GL_RG:              result = VKGL::PixelFormat::RG;              break;
        case GL_RG_INTEGER:      result = VKGL::PixelFormat::RG_Integer;      break;
        case GL_RGB:             result = VKGL::PixelFormat::RGB;             break;
        case GL_RGB_INTEGER:     result = VKGL::PixelFormat::RGB_Integer;     break;
        case GL_RGBA:            result = VKGL::PixelFormat::RGBA;            break;
        case GL_RGBA_INTEGER:    result = VKGL::PixelFormat::RGBA_Integer;    break;
        case GL_STENCIL_INDEX:   result = VKGL::PixelFormat::Stencil_Index;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::PixelType VKGL::Utils::get_pixel_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::PixelType result = VKGL::PixelType::Unknown;

    switch (in_enum)
    {
        case GL_FLOAT:                          result = VKGL::PixelType::Float;                           break;
        case GL_FLOAT_32_UNSIGNED_INT_24_8_REV: result = VKGL::PixelType::Float_32_Unsigned_Int_24_8_Rev;  break;
        case GL_HALF_FLOAT:                     result = VKGL::PixelType::Half_Float;                      break;
        case GL_INT:                            result = VKGL::PixelType::Int;                             break;
        case GL_SHORT:                          result = VKGL::PixelType::Short;                           break;
        case GL_UNSIGNED_BYTE:                  result = VKGL::PixelType::Unsigned_Byte;                   break;
        case GL_UNSIGNED_BYTE_2_3_3_REV:        result = VKGL::PixelType::Unsigned_Byte_2_3_3_Rev;         break;
        case GL_UNSIGNED_BYTE_3_3_2:            result = VKGL::PixelType::Unsigned_Byte_3_3_2;             break;
        case GL_UNSIGNED_INT:                   result = VKGL::PixelType::Unsigned_Int;                    break;
        case GL_UNSIGNED_INT_10_10_10_2:        result = VKGL::PixelType::Unsigned_Int_10_10_10_2;         break;
        case GL_UNSIGNED_INT_10F_11F_11F_REV:   result = VKGL::PixelType::Unsigned_Int_10F_11F_11F_Rev;    break;
        case GL_UNSIGNED_INT_2_10_10_10_REV:    result = VKGL::PixelType::Unsigned_Int_2_10_10_10_Rev;     break;
        case GL_UNSIGNED_INT_24_8:              result = VKGL::PixelType::Unsigned_Int_24_8;               break;
        case GL_UNSIGNED_INT_5_9_9_9_REV:       result = VKGL::PixelType::Unsigned_Int_5_9_9_9_Rev;        break;
        case GL_UNSIGNED_INT_8_8_8_8:           result = VKGL::PixelType::Unsigned_Int_8_8_8_8;            break;
        case GL_UNSIGNED_INT_8_8_8_8_REV:       result = VKGL::PixelType::Unsigned_Int_8_8_8_8_Rev;        break;
        case GL_UNSIGNED_SHORT:                 result = VKGL::PixelType::Unsigned_Short;                  break;
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:     result = VKGL::PixelType::Unsigned_Short_1_5_5_5_Rev;      break;
        case GL_UNSIGNED_SHORT_4_4_4_4:         result = VKGL::PixelType::Unsigned_Short_4_4_4_4;          break;
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:     result = VKGL::PixelType::Unsigned_Short_4_4_4_4_Rev;      break;
        case GL_UNSIGNED_SHORT_5_5_5_1:         result = VKGL::PixelType::Unsigned_Short_5_5_5_1;          break;
        case GL_UNSIGNED_SHORT_5_6_5:           result = VKGL::PixelType::Unsigned_Short_5_6_5;            break;
        case GL_UNSIGNED_SHORT_5_6_5_REV:       result = VKGL::PixelType::Unsigned_Short_5_6_5_Rev;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::PolygonMode VKGL::Utils::get_polygon_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::PolygonMode result = VKGL::PolygonMode::Unknown;

    switch (in_enum)
    {
        case GL_FILL:  result = VKGL::PolygonMode::Fill;  break;
        case GL_LINE:  result = VKGL::PolygonMode::Line;  break;
        case GL_POINT: result = VKGL::PolygonMode::Point; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::StencilFunction VKGL::Utils::get_stencil_function_for_gl_enum(const GLenum& in_enum)
{
    VKGL::StencilFunction result = VKGL::StencilFunction::Unknown;

    switch (in_enum)
    {
        case GL_ALWAYS:   result = VKGL::StencilFunction::Always;   break;
        case GL_EQUAL:    result = VKGL::StencilFunction::Equal;    break;
        case GL_GEQUAL:   result = VKGL::StencilFunction::GEqual;   break;
        case GL_GREATER:  result = VKGL::StencilFunction::Greater;  break;
        case GL_LEQUAL:   result = VKGL::StencilFunction::LEqual;   break;
        case GL_LESS:     result = VKGL::StencilFunction::Less;     break;
        case GL_NEVER:    result = VKGL::StencilFunction::Never;    break;
        case GL_NOTEQUAL: result = VKGL::StencilFunction::NotEqual; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::StencilOperation VKGL::Utils::get_stencil_operation_for_gl_enum(const GLenum& in_enum)
{
    VKGL::StencilOperation result = VKGL::StencilOperation::Unknown;

    switch (in_enum)
    {
        case GL_DECR:      result = VKGL::StencilOperation::Decr;      break;
        case GL_DECR_WRAP: result = VKGL::StencilOperation::Decr_Wrap; break;
        case GL_INCR:      result = VKGL::StencilOperation::Incr;      break;
        case GL_INCR_WRAP: result = VKGL::StencilOperation::Incr_Wrap; break;
        case GL_INVERT:    result = VKGL::StencilOperation::Invert;    break;
        case GL_KEEP:      result = VKGL::StencilOperation::Keep;      break;
        case GL_REPLACE:   result = VKGL::StencilOperation::Replace;   break;
        case GL_ZERO:      result = VKGL::StencilOperation::Zero;      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureCompareFunction VKGL::Utils::get_texture_compare_function_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureCompareFunction result = VKGL::TextureCompareFunction::Unknown;

    switch (in_enum)
    {
        case GL_ALWAYS:   result = VKGL::TextureCompareFunction::Always;   break;
        case GL_EQUAL:    result = VKGL::TextureCompareFunction::Equal;    break;
        case GL_GEQUAL:   result = VKGL::TextureCompareFunction::GEqual;   break;
        case GL_GREATER:  result = VKGL::TextureCompareFunction::Greater;  break;
        case GL_LEQUAL:   result = VKGL::TextureCompareFunction::LEqual;   break;
        case GL_LESS:     result = VKGL::TextureCompareFunction::Less;     break;
        case GL_NEVER:    result = VKGL::TextureCompareFunction::Never;    break;
        case GL_NOTEQUAL: result = VKGL::TextureCompareFunction::NotEqual; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureCompareMode VKGL::Utils::get_texture_compare_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureCompareMode result = VKGL::TextureCompareMode::Unknown;

    switch (in_enum)
    {
        case GL_COMPARE_REF_TO_TEXTURE: result = VKGL::TextureCompareMode::Compare_Ref_to_Texture; break;
        case GL_NONE:                   result = VKGL::TextureCompareMode::None;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureMagFilter VKGL::Utils::get_texture_mag_filter_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureMagFilter result = VKGL::TextureMagFilter::Unknown;

    switch (in_enum)
    {
        case GL_LINEAR:  result = VKGL::TextureMagFilter::Linear;  break;
        case GL_NEAREST: result = VKGL::TextureMagFilter::Nearest; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureMinFilter VKGL::Utils::get_texture_min_filter_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureMinFilter result = VKGL::TextureMinFilter::Unknown;

    switch (in_enum)
    {
        case GL_LINEAR:                 result = VKGL::TextureMinFilter::Linear;                 break;
        case GL_LINEAR_MIPMAP_LINEAR:   result = VKGL::TextureMinFilter::Linear_Mipmap_Linear;   break;
        case GL_LINEAR_MIPMAP_NEAREST:  result = VKGL::TextureMinFilter::Linear_Mipmap_Nearest;  break;
        case GL_NEAREST:                result = VKGL::TextureMinFilter::Nearest;                break;
        case GL_NEAREST_MIPMAP_LINEAR:  result = VKGL::TextureMinFilter::Nearest_Mipmap_Linear;  break;
        case GL_NEAREST_MIPMAP_NEAREST: result = VKGL::TextureMinFilter::Nearest_Mipmap_Nearest; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureSwizzle VKGL::Utils::get_texture_swizzle_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureSwizzle result = VKGL::TextureSwizzle::Unknown;

    switch (in_enum)
    {
        case GL_ALPHA: result = VKGL::TextureSwizzle::Alpha; break;
        case GL_BLUE:  result = VKGL::TextureSwizzle::Blue;  break;
        case GL_GREEN: result = VKGL::TextureSwizzle::Green; break;
        case GL_ONE:   result = VKGL::TextureSwizzle::One;   break;
        case GL_RED:   result = VKGL::TextureSwizzle::Red;   break;
        case GL_ZERO:  result = VKGL::TextureSwizzle::Zero;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureTarget VKGL::Utils::get_texture_target_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureTarget result = VKGL::TextureTarget::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_1D:                         result = VKGL::TextureTarget::_1D;                                break;
        case GL_TEXTURE_1D_ARRAY:                   result = VKGL::TextureTarget::_1D_Array;                          break;
        case GL_TEXTURE_2D:                         result = VKGL::TextureTarget::_2D;                                break;
        case GL_TEXTURE_2D_ARRAY:                   result = VKGL::TextureTarget::_2D_Array;                          break;
        case GL_TEXTURE_2D_MULTISAMPLE:             result = VKGL::TextureTarget::_2D_Multisample;                    break;
        case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:       result = VKGL::TextureTarget::_2D_Multisample_Array;              break;
        case GL_TEXTURE_3D:                         result = VKGL::TextureTarget::_3D;                                break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:        result = VKGL::TextureTarget::Cube_Map_Negative_X;                break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:        result = VKGL::TextureTarget::Cube_Map_Negative_Y;                break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:        result = VKGL::TextureTarget::Cube_Map_Negative_Z;                break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X:        result = VKGL::TextureTarget::Cube_Map_Positive_X;                break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:        result = VKGL::TextureTarget::Cube_Map_Positive_Y;                break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:        result = VKGL::TextureTarget::Cube_Map_Positive_Z;                break;
        case GL_PROXY_TEXTURE_1D:                   result = VKGL::TextureTarget::Proxy_Texture_1D;                   break;
        case GL_PROXY_TEXTURE_1D_ARRAY:             result = VKGL::TextureTarget::Proxy_Texture_1D_Array;             break;
        case GL_PROXY_TEXTURE_2D:                   result = VKGL::TextureTarget::Proxy_Texture_2D;                   break;
        case GL_PROXY_TEXTURE_2D_ARRAY:             result = VKGL::TextureTarget::Proxy_Texture_2D_Array;             break;
        case GL_PROXY_TEXTURE_2D_MULTISAMPLE:       result = VKGL::TextureTarget::Proxy_Texture_2D_Multisample;       break;
        case GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY: result = VKGL::TextureTarget::Proxy_Texture_2D_Multisample_Array; break;
        case GL_PROXY_TEXTURE_3D:                   result = VKGL::TextureTarget::Proxy_Texture_3D;                   break;
        case GL_PROXY_TEXTURE_CUBE_MAP:             result = VKGL::TextureTarget::Proxy_Texture_Cube_Map;             break;
        case GL_PROXY_TEXTURE_RECTANGLE:            result = VKGL::TextureTarget::Proxy_Texture_Rectangle;            break;
        case GL_TEXTURE_RECTANGLE:                  result = VKGL::TextureTarget::Rectangle;                          break;
        case GL_TEXTURE_BUFFER:                     result = VKGL::TextureTarget::Texture_Buffer;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureWrapMode VKGL::Utils::get_texture_wrap_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureWrapMode result = VKGL::TextureWrapMode::Unknown;

    switch (in_enum)
    {
        case GL_CLAMP_TO_BORDER:      result = VKGL::TextureWrapMode::Clamp_To_Border;      break;
        case GL_CLAMP_TO_EDGE:        result = VKGL::TextureWrapMode::Clamp_To_Edge;        break;
        case GL_MIRROR_CLAMP_TO_EDGE: result = VKGL::TextureWrapMode::Mirror_Clamp_to_Edge; break;
        case GL_MIRRORED_REPEAT:      result = VKGL::TextureWrapMode::Mirrored_Repeat;      break;
        case GL_REPEAT:               result = VKGL::TextureWrapMode::Repeat;               break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}
