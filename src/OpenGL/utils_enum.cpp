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

VKGL::ClearBufferBits get_clear_buffer_bits_for_gl_enum(const GLenum& in_enum)
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

VKGL::CullMode get_cull_mode_for_gl_enum(const GLenum& in_enum)
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

GLenum get_gl_enum_for_clear_buffer_bits(const VKGL::ClearBufferBits& in_buffers)
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

GLenum get_gl_enum_for_cull_mode(const VKGL::CullMode& in_cull_mode)
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