/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/utils_enum.h"

VKGL::BlendEquation VKGL::Utils::get_blend_equation_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BlendEquation result = VKGL::BlendEquation::Unknown;

    switch (in_enum)
    {
        case GL_FUNC_ADD:              result = VKGL::BlendEquation::Function_Add;              break;
        case GL_FUNC_REVERSE_SUBTRACT: result = VKGL::BlendEquation::Function_Reverse_Subtract; break;
        case GL_FUNC_SUBTRACT:         result = VKGL::BlendEquation::Function_Subtract;         break;
        case GL_MAX:                   result = VKGL::BlendEquation::Max;                       break;
        case GL_MIN:                   result = VKGL::BlendEquation::Min;                       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

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

VKGL::BlitFilter VKGL::Utils::get_blit_filter_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BlitFilter result = VKGL::BlitFilter::Unknown;

    switch (in_enum)
    {
        case GL_LINEAR:  result = VKGL::BlitFilter::Linear;  break;
        case GL_NEAREST: result = VKGL::BlitFilter::Nearest; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::BlitMaskBits VKGL::Utils::get_blit_mask_bits_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BlitMaskBits result = 0;

    if (in_enum & GL_COLOR_BUFFER_BIT)
    {
        result |= VKGL::BlitMaskBit::BLIT_MASK_BIT_COLOR_BUFFER;
    }

    if (in_enum & GL_DEPTH_BUFFER_BIT)
    {
        result |= VKGL::BlitMaskBit::BLIT_MASK_BIT_DEPTH_BUFFER;
    }

    if (in_enum & GL_STENCIL_BUFFER_BIT)
    {
        result |= VKGL::BlitMaskBit::BLIT_MASK_BIT_STENCIL_BUFFER;
    }

    return result;
}

VKGL::BufferAccess VKGL::Utils::get_buffer_access_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BufferAccess result = VKGL::BufferAccess::Unknown;

    switch (in_enum)
    {
        case GL_READ_ONLY:  result = VKGL::BufferAccess::Read_Only;  break;
        case GL_READ_WRITE: result = VKGL::BufferAccess::Read_Write; break;
        case GL_WRITE_ONLY: result = VKGL::BufferAccess::Write_Only; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::BufferPointerProperty VKGL::Utils::get_buffer_pointer_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BufferPointerProperty result = VKGL::BufferPointerProperty::Unknown;

    switch (in_enum)
    {
        case GL_BUFFER_MAP_POINTER: result = VKGL::BufferPointerProperty::Buffer_Map_Pointer; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::BufferProperty VKGL::Utils::get_buffer_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BufferProperty result = VKGL::BufferProperty::Unknown;

    switch (in_enum)
    {
        case GL_BUFFER_ACCESS: result = VKGL::BufferProperty::Buffer_Access; break;
        case GL_BUFFER_MAPPED: result = VKGL::BufferProperty::Buffer_Mapped; break;
        case GL_BUFFER_SIZE:   result = VKGL::BufferProperty::Buffer_Size;   break;
        case GL_BUFFER_USAGE:  result = VKGL::BufferProperty::Buffer_Usage;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::BufferTarget VKGL::Utils::get_buffer_target_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BufferTarget result = VKGL::BufferTarget::Unknown;

    switch (in_enum)
    {
        case GL_ARRAY_BUFFER:              result = VKGL::BufferTarget::Array_Buffer;              break;
        case GL_COPY_READ_BUFFER:          result = VKGL::BufferTarget::Copy_Read_Buffer;          break;
        case GL_COPY_WRITE_BUFFER:         result = VKGL::BufferTarget::Copy_Write_Buffer;         break;
        case GL_ELEMENT_ARRAY_BUFFER:      result = VKGL::BufferTarget::Element_Array_Buffer;      break;
        case GL_PIXEL_PACK_BUFFER:         result = VKGL::BufferTarget::Pixel_Pack_Buffer;         break;
        case GL_PIXEL_UNPACK_BUFFER:       result = VKGL::BufferTarget::Pixel_Unpack_Buffer;       break;
        case GL_TEXTURE_BUFFER:            result = VKGL::BufferTarget::Texture_Buffer;            break;
        case GL_TRANSFORM_FEEDBACK_BUFFER: result = VKGL::BufferTarget::Transform_Feedback_Buffer; break;
        case GL_UNIFORM_BUFFER:            result = VKGL::BufferTarget::Uniform_Buffer;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::BufferUsage VKGL::Utils::get_buffer_usage_for_gl_enum(const GLenum& in_enum)
{
    VKGL::BufferUsage result = VKGL::BufferUsage::Unknown;

    switch (in_enum)
    {
        case GL_DYNAMIC_COPY: result = VKGL::BufferUsage::Dynamic_Copy; break;
        case GL_DYNAMIC_DRAW: result = VKGL::BufferUsage::Dynamic_Draw; break;
        case GL_DYNAMIC_READ: result = VKGL::BufferUsage::Dynamic_Read; break;
        case GL_STATIC_COPY:  result = VKGL::BufferUsage::Static_Copy;  break;
        case GL_STATIC_DRAW:  result = VKGL::BufferUsage::Static_Draw;  break;
        case GL_STATIC_READ:  result = VKGL::BufferUsage::Static_Read;  break;
        case GL_STREAM_COPY:  result = VKGL::BufferUsage::Stream_Copy;  break;
        case GL_STREAM_DRAW:  result = VKGL::BufferUsage::Stream_Draw;  break;
        case GL_STREAM_READ:  result = VKGL::BufferUsage::Stream_Read;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ClampReadColorMode VKGL::Utils::get_clamp_read_color_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ClampReadColorMode result = VKGL::ClampReadColorMode::Unknown;

    switch (in_enum)
    {
        case GL_FALSE:      result = VKGL::ClampReadColorMode::False;      break;
        case GL_FIXED_ONLY: result = VKGL::ClampReadColorMode::Fixed_Only; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ClearBuffer VKGL::Utils::get_clear_buffer_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ClearBuffer result = VKGL::ClearBuffer::Unknown;

    switch (in_enum)
    {
        case GL_BACK:           result = VKGL::ClearBuffer::Back;           break;
        case GL_COLOR:          result = VKGL::ClearBuffer::Color;          break;
        case GL_DEPTH:          result = VKGL::ClearBuffer::Depth;          break;
        case GL_DEPTH_STENCIL:  result = VKGL::ClearBuffer::Depth_Stencil;  break;
        case GL_FRONT:          result = VKGL::ClearBuffer::Front;          break;
        case GL_FRONT_AND_BACK: result = VKGL::ClearBuffer::Front_And_Back; break;
        case GL_LEFT:           result = VKGL::ClearBuffer::Left;           break;
        case GL_RIGHT:          result = VKGL::ClearBuffer::Right;          break;
        case GL_STENCIL:        result = VKGL::ClearBuffer::Stencil;        break;

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

VKGL::ConditionalRenderMode VKGL::Utils::get_conditional_render_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ConditionalRenderMode result = VKGL::ConditionalRenderMode::Unknown;

    switch (in_enum)
    {
        case GL_QUERY_BY_REGION_NO_WAIT: result = VKGL::ConditionalRenderMode::Query_By_Region_No_Wait; break;
        case GL_QUERY_BY_REGION_WAIT:    result = VKGL::ConditionalRenderMode::Query_By_Region_Wait;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ContextProperty VKGL::Utils::get_context_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ContextProperty result = VKGL::ContextProperty::Unknown;

    switch (in_enum)
    {
        case GL_ACTIVE_TEXTURE:                           result = VKGL::ContextProperty::Active_Texture;                           break;
        case GL_ALIASED_LINE_WIDTH_RANGE:                 result = VKGL::ContextProperty::Aliased_Line_Width_Range;                 break;
        case GL_ARRAY_BUFFER_BINDING:                     result = VKGL::ContextProperty::Array_Buffer_Binding;                     break;
        case GL_BLEND:                                    result = VKGL::ContextProperty::Blend;                                    break;
        case GL_BLEND_COLOR:                              result = VKGL::ContextProperty::Blend_Color;                              break;
        case GL_BLEND_DST_ALPHA:                          result = VKGL::ContextProperty::Blend_Dst_Alpha;                          break;
        case GL_BLEND_DST_RGB:                            result = VKGL::ContextProperty::Blend_Dst_RGB;                            break;
        case GL_BLEND_EQUATION_ALPHA:                     result = VKGL::ContextProperty::Blend_Equation_Alpha;                     break;
        case GL_BLEND_EQUATION_RGB:                       result = VKGL::ContextProperty::Blend_Equation_RGB;                       break;
        case GL_BLEND_SRC_ALPHA:                          result = VKGL::ContextProperty::Blend_Src_Alpha;                          break;
        case GL_BLEND_SRC_RGB:                            result = VKGL::ContextProperty::Blend_Src_RGB;                            break;
        case GL_COLOR_CLEAR_VALUE:                        result = VKGL::ContextProperty::Color_Clear_Value;                        break;
        case GL_COLOR_LOGIC_OP:                           result = VKGL::ContextProperty::Color_Logic_Op;                           break;
        case GL_COLOR_WRITEMASK:                          result = VKGL::ContextProperty::Color_Writemask;                          break;
        case GL_COMPRESSED_TEXTURE_FORMATS:               result = VKGL::ContextProperty::Compressed_Texture_Formats;               break;
        case GL_CONTEXT_FLAGS:                            result = VKGL::ContextProperty::Context_Flags;                            break;
        case GL_CULL_FACE:                                result = VKGL::ContextProperty::Cull_Face;                                break;
        case GL_CURRENT_PROGRAM:                          result = VKGL::ContextProperty::Current_Program;                          break;
        case GL_DEPTH_CLEAR_VALUE:                        result = VKGL::ContextProperty::Depth_Clear_Value;                        break;
        case GL_DEPTH_FUNC:                               result = VKGL::ContextProperty::Depth_Func;                               break;
        case GL_DEPTH_RANGE:                              result = VKGL::ContextProperty::Depth_Range;                              break;
        case GL_DEPTH_TEST:                               result = VKGL::ContextProperty::Depth_Test;                               break;
        case GL_DEPTH_WRITEMASK:                          result = VKGL::ContextProperty::Depth_Writemask;                          break;
        case GL_DITHER:                                   result = VKGL::ContextProperty::Dither;                                   break;
        case GL_DOUBLEBUFFER:                             result = VKGL::ContextProperty::Doublebuffer;                             break;
        case GL_DRAW_BUFFER:                              result = VKGL::ContextProperty::Draw_Buffer;                              break;
        case GL_DRAW_BUFFER0:                             result = VKGL::ContextProperty::Draw_Buffer0;                             break;
        case GL_DRAW_BUFFER1:                             result = VKGL::ContextProperty::Draw_Buffer1;                             break;
        case GL_DRAW_BUFFER2:                             result = VKGL::ContextProperty::Draw_Buffer2;                             break;
        case GL_DRAW_BUFFER3:                             result = VKGL::ContextProperty::Draw_Buffer3;                             break;
        case GL_DRAW_BUFFER4:                             result = VKGL::ContextProperty::Draw_Buffer4;                             break;
        case GL_DRAW_BUFFER5:                             result = VKGL::ContextProperty::Draw_Buffer5;                             break;
        case GL_DRAW_BUFFER6:                             result = VKGL::ContextProperty::Draw_Buffer6;                             break;
        case GL_DRAW_BUFFER7:                             result = VKGL::ContextProperty::Draw_Buffer7;                             break;
        case GL_DRAW_FRAMEBUFFER_BINDING:                 result = VKGL::ContextProperty::Draw_Framebuffer_Binding;                 break;
        case GL_ELEMENT_ARRAY_BUFFER_BINDING:             result = VKGL::ContextProperty::Element_Array_Buffer_Binding;             break;
        case GL_FRAGMENT_SHADER_DERIVATIVE_HINT:          result = VKGL::ContextProperty::Fragment_Shader_Derivative_Hint;          break;
        case GL_LINE_SMOOTH:                              result = VKGL::ContextProperty::Line_Smooth;                              break;
        case GL_LINE_SMOOTH_HINT:                         result = VKGL::ContextProperty::Line_Smooth_Hint;                         break;
        case GL_LINE_WIDTH:                               result = VKGL::ContextProperty::Line_Width;                               break;
        case GL_LOGIC_OP_MODE:                            result = VKGL::ContextProperty::Logic_Op_Mode;                            break;
        case GL_MAJOR_VERSION:                            result = VKGL::ContextProperty::Major_Version;                            break;
        case GL_MAX_3D_TEXTURE_SIZE:                      result = VKGL::ContextProperty::Max_3D_Texture_Size;                      break;
        case GL_MAX_ARRAY_TEXTURE_LAYERS:                 result = VKGL::ContextProperty::Max_Array_Texture_Layers;                 break;
        case GL_MAX_CLIP_DISTANCES:                       result = VKGL::ContextProperty::Max_Clip_Distances;                       break;
        case GL_MAX_COLOR_TEXTURE_SAMPLES:                result = VKGL::ContextProperty::Max_Color_Texture_Samples;                break;
        case GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS: result = VKGL::ContextProperty::Max_Combined_Fragment_Uniform_Components; break;
        case GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS: result = VKGL::ContextProperty::Max_Combined_Geometry_Uniform_Components; break;
        case GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS:         result = VKGL::ContextProperty::Max_Combined_Texture_Image_Units;         break;
        case GL_MAX_COMBINED_UNIFORM_BLOCKS:              result = VKGL::ContextProperty::Max_Combined_Uniform_Blocks;              break;
        case GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS:   result = VKGL::ContextProperty::Max_Combined_Vertex_Uniform_Components;   break;
        case GL_MAX_CUBE_MAP_TEXTURE_SIZE:                result = VKGL::ContextProperty::Max_Cube_Map_Texture_Size;                break;
        case GL_MAX_DEPTH_TEXTURE_SAMPLES:                result = VKGL::ContextProperty::Max_Depth_Texture_Samples;                break;
        case GL_MAX_DRAW_BUFFERS:                         result = VKGL::ContextProperty::Max_Draw_Buffers;                         break;
        case GL_MAX_DUAL_SOURCE_DRAW_BUFFERS:             result = VKGL::ContextProperty::Max_Dual_Source_Draw_Buffers;             break;
        case GL_MAX_ELEMENTS_INDICES:                     result = VKGL::ContextProperty::Max_Elements_Indices;                     break;
        case GL_MAX_ELEMENTS_VERTICES:                    result = VKGL::ContextProperty::Max_Elements_Vertices;                    break;
        case GL_MAX_FRAGMENT_INPUT_COMPONENTS:            result = VKGL::ContextProperty::Max_Fragment_Input_Components;            break;
        case GL_MAX_FRAGMENT_UNIFORM_BLOCKS:              result = VKGL::ContextProperty::Max_Fragment_Uniform_Blocks;              break;
        case GL_MAX_FRAGMENT_UNIFORM_COMPONENTS:          result = VKGL::ContextProperty::Max_Fragment_Uniform_Components;          break;
        case GL_MAX_GEOMETRY_INPUT_COMPONENTS:            result = VKGL::ContextProperty::Max_Geometry_Input_Components;            break;
        case GL_MAX_GEOMETRY_OUTPUT_COMPONENTS:           result = VKGL::ContextProperty::Max_Geometry_Output_Components;           break;
        case GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS:         result = VKGL::ContextProperty::Max_Geometry_Texture_Image_Units;         break;
        case GL_MAX_GEOMETRY_UNIFORM_BLOCKS:              result = VKGL::ContextProperty::Max_Geometry_Uniform_Blocks;              break;
        case GL_MAX_GEOMETRY_UNIFORM_COMPONENTS:          result = VKGL::ContextProperty::Max_Geometry_Uniform_Components;          break;
        case GL_MAX_INTEGER_SAMPLES:                      result = VKGL::ContextProperty::Max_Integer_Samples;                      break;
        case GL_MAX_PROGRAM_TEXEL_OFFSET:                 result = VKGL::ContextProperty::Max_Program_Texel_Offset;                 break;
        case GL_MAX_RECTANGLE_TEXTURE_SIZE:               result = VKGL::ContextProperty::Max_Rectangle_Texture_Size;               break;
        case GL_MAX_RENDERBUFFER_SIZE:                    result = VKGL::ContextProperty::Max_Renderbuffer_Size;                    break;
        case GL_MAX_SAMPLE_MASK_WORDS:                    result = VKGL::ContextProperty::Max_Sample_Mask_Words;                    break;
        case GL_MAX_SERVER_WAIT_TIMEOUT:                  result = VKGL::ContextProperty::Max_Server_Wait_Timeout;                  break;
        case GL_MAX_TEXTURE_BUFFER_SIZE:                  result = VKGL::ContextProperty::Max_Texture_Buffer_Size;                  break;
        case GL_MAX_TEXTURE_IMAGE_UNITS:                  result = VKGL::ContextProperty::Max_Texture_Image_Units;                  break;
        case GL_MAX_TEXTURE_LOD_BIAS:                     result = VKGL::ContextProperty::Max_Texture_LOD_Bias;                     break;
        case GL_MAX_TEXTURE_SIZE:                         result = VKGL::ContextProperty::Max_Texture_Size;                         break;
        case GL_MAX_UNIFORM_BLOCK_SIZE:                   result = VKGL::ContextProperty::Max_Uniform_Block_Size;                   break;
        case GL_MAX_UNIFORM_BUFFER_BINDINGS:              result = VKGL::ContextProperty::Max_Uniform_Buffer_Bindings;              break;
        case GL_MAX_VARYING_COMPONENTS:                   result = VKGL::ContextProperty::Max_Varying_Components;                   break;
        case GL_MAX_VERTEX_ATTRIBS:                       result = VKGL::ContextProperty::Max_Vertex_Attribs;                       break;
        case GL_MAX_VERTEX_OUTPUT_COMPONENTS:             result = VKGL::ContextProperty::Max_Vertex_Output_Components;             break;
        case GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS:           result = VKGL::ContextProperty::Max_Vertex_Texture_Image_Units;           break;
        case GL_MAX_VERTEX_UNIFORM_BLOCKS:                result = VKGL::ContextProperty::Max_Vertex_Uniform_Blocks;                break;
        case GL_MAX_VERTEX_UNIFORM_COMPONENTS:            result = VKGL::ContextProperty::Max_Vertex_Uniform_Components;            break;
        case GL_MAX_VIEWPORT_DIMS:                        result = VKGL::ContextProperty::Max_Viewport_Dims;                        break;
        case GL_MINOR_VERSION:                            result = VKGL::ContextProperty::Minor_Version;                            break;
        case GL_MIN_PROGRAM_TEXEL_OFFSET:                 result = VKGL::ContextProperty::Min_Program_Texel_Offset;                 break;
        case GL_NUM_COMPRESSED_TEXTURE_FORMATS:           result = VKGL::ContextProperty::Num_Compressed_Texture_Formats;           break;
        case GL_NUM_EXTENSIONS:                           result = VKGL::ContextProperty::Num_Extensions;                           break;
        case GL_PACK_ALIGNMENT:                           result = VKGL::ContextProperty::Pack_Alignment;                           break;
        case GL_PACK_IMAGE_HEIGHT:                        result = VKGL::ContextProperty::Pack_Image_Height;                        break;
        case GL_PACK_LSB_FIRST:                           result = VKGL::ContextProperty::Pack_LSB_First;                           break;
        case GL_PACK_ROW_LENGTH:                          result = VKGL::ContextProperty::Pack_Row_Length;                          break;
        case GL_PACK_SKIP_IMAGES:                         result = VKGL::ContextProperty::Pack_Skip_Images;                         break;
        case GL_PACK_SKIP_PIXELS:                         result = VKGL::ContextProperty::Pack_Skip_Pixels;                         break;
        case GL_PACK_SKIP_ROWS:                           result = VKGL::ContextProperty::Pack_Skip_Rows;                           break;
        case GL_PACK_SWAP_BYTES:                          result = VKGL::ContextProperty::Pack_Swap_Bytes;                          break;
        case GL_PIXEL_PACK_BUFFER_BINDING:                result = VKGL::ContextProperty::Pixel_Pack_Buffer_Binding;                break;
        case GL_PIXEL_UNPACK_BUFFER_BINDING:              result = VKGL::ContextProperty::Pixel_Unpack_Buffer_Binding;              break;
        case GL_POINT_FADE_THRESHOLD_SIZE:                result = VKGL::ContextProperty::Point_Fade_Threshold_Size;                break;
        case GL_POINT_SIZE:                               result = VKGL::ContextProperty::Point_Size;                               break;
        case GL_POINT_SIZE_GRANULARITY:                   result = VKGL::ContextProperty::Point_Size_Granularity;                   break;
        case GL_POINT_SIZE_RANGE:                         result = VKGL::ContextProperty::Point_Size_Range;                         break;
        case GL_POLYGON_OFFSET_FACTOR:                    result = VKGL::ContextProperty::Polygon_Offset_Factor;                    break;
        case GL_POLYGON_OFFSET_FILL:                      result = VKGL::ContextProperty::Polygon_Offset_Fill;                      break;
        case GL_POLYGON_OFFSET_LINE:                      result = VKGL::ContextProperty::Polygon_Offset_Line;                      break;
        case GL_POLYGON_OFFSET_POINT:                     result = VKGL::ContextProperty::Polygon_Offset_Point;                     break;
        case GL_POLYGON_OFFSET_UNITS:                     result = VKGL::ContextProperty::Polygon_Offset_Units;                     break;
        case GL_POLYGON_SMOOTH:                           result = VKGL::ContextProperty::Polygon_Smooth;                           break;
        case GL_POLYGON_SMOOTH_HINT:                      result = VKGL::ContextProperty::Polygon_Smooth_Hint;                      break;
        case GL_PRIMITIVE_RESTART_INDEX:                  result = VKGL::ContextProperty::Primitive_Restart_Index;                  break;
        case GL_PROGRAM_POINT_SIZE:                       result = VKGL::ContextProperty::Program_Point_Size;                       break;
        case GL_PROVOKING_VERTEX:                         result = VKGL::ContextProperty::Provoking_Vertex;                         break;
        case GL_READ_BUFFER:                              result = VKGL::ContextProperty::Read_Buffer;                              break;
        case GL_READ_FRAMEBUFFER_BINDING:                 result = VKGL::ContextProperty::Read_Framebuffer_Binding;                 break;
        case GL_RENDERBUFFER_BINDING:                     result = VKGL::ContextProperty::Renderbuffer_Binding;                     break;
        case GL_SAMPLER_BINDING:                          result = VKGL::ContextProperty::Sampler_Binding;                          break;
        case GL_SAMPLES:                                  result = VKGL::ContextProperty::Samples;                                  break;
        case GL_SAMPLE_BUFFERS:                           result = VKGL::ContextProperty::Sample_Buffers;                           break;
        case GL_SAMPLE_COVERAGE_INVERT:                   result = VKGL::ContextProperty::Sample_Coverage_Invert;                   break;
        case GL_SAMPLE_COVERAGE_VALUE:                    result = VKGL::ContextProperty::Sample_Coverage_Value;                    break;
        case GL_SCISSOR_BOX:                              result = VKGL::ContextProperty::Scissor_Box;                              break;
        case GL_SCISSOR_TEST:                             result = VKGL::ContextProperty::Scissor_Test;                             break;
        case GL_SMOOTH_LINE_WIDTH_GRANULARITY:            result = VKGL::ContextProperty::Smooth_Line_Width_Granularity;            break;
        case GL_SMOOTH_LINE_WIDTH_RANGE:                  result = VKGL::ContextProperty::Smooth_Line_Width_Range;                  break;
        case GL_STENCIL_BACK_FAIL:                        result = VKGL::ContextProperty::Stencil_Back_Fail;                        break;
        case GL_STENCIL_BACK_FUNC:                        result = VKGL::ContextProperty::Stencil_Back_Func;                        break;
        case GL_STENCIL_BACK_PASS_DEPTH_FAIL:             result = VKGL::ContextProperty::Stencil_Back_Pass_Depth_Fail;             break;
        case GL_STENCIL_BACK_PASS_DEPTH_PASS:             result = VKGL::ContextProperty::Stencil_Back_Pass_Depth_Pass;             break;
        case GL_STENCIL_BACK_REF:                         result = VKGL::ContextProperty::Stencil_Back_Ref;                         break;
        case GL_STENCIL_BACK_VALUE_MASK:                  result = VKGL::ContextProperty::Stencil_Back_Value_Mask;                  break;
        case GL_STENCIL_BACK_WRITEMASK:                   result = VKGL::ContextProperty::Stencil_Back_Writemask;                   break;
        case GL_STENCIL_CLEAR_VALUE:                      result = VKGL::ContextProperty::Stencil_Clear_Value;                      break;
        case GL_STENCIL_FAIL:                             result = VKGL::ContextProperty::Stencil_Fail;                             break;
        case GL_STENCIL_FUNC:                             result = VKGL::ContextProperty::Stencil_Func;                             break;
        case GL_STENCIL_PASS_DEPTH_FAIL:                  result = VKGL::ContextProperty::Stencil_Pass_Depth_Fail;                  break;
        case GL_STENCIL_PASS_DEPTH_PASS:                  result = VKGL::ContextProperty::Stencil_Pass_Depth_Pass;                  break;
        case GL_STENCIL_REF:                              result = VKGL::ContextProperty::Stencil_Ref;                              break;
        case GL_STENCIL_TEST:                             result = VKGL::ContextProperty::Stencil_Test;                             break;
        case GL_STENCIL_VALUE_MASK:                       result = VKGL::ContextProperty::Stencil_Value_Mask;                       break;
        case GL_STENCIL_WRITEMASK:                        result = VKGL::ContextProperty::Stencil_Writemask;                        break;
        case GL_STEREO:                                   result = VKGL::ContextProperty::Stereo;                                   break;
        case GL_SUBPIXEL_BITS:                            result = VKGL::ContextProperty::Subpixel_Bits;                            break;
        case GL_TEXTURE_BINDING_1D:                       result = VKGL::ContextProperty::Texture_Binding_1D;                       break;
        case GL_TEXTURE_BINDING_1D_ARRAY:                 result = VKGL::ContextProperty::Texture_Binding_1D_Array;                 break;
        case GL_TEXTURE_BINDING_2D:                       result = VKGL::ContextProperty::Texture_Binding_2D;                       break;
        case GL_TEXTURE_BINDING_2D_ARRAY:                 result = VKGL::ContextProperty::Texture_Binding_2D_Array;                 break;
        case GL_TEXTURE_BINDING_2D_MULTISAMPLE:           result = VKGL::ContextProperty::Texture_Binding_2D_Multisample;           break;
        case GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY:     result = VKGL::ContextProperty::Texture_Binding_2D_Multisample_Array;     break;
        case GL_TEXTURE_BINDING_3D:                       result = VKGL::ContextProperty::Texture_Binding_3D;                       break;
        case GL_TEXTURE_BINDING_BUFFER:                   result = VKGL::ContextProperty::Texture_Binding_Buffer;                   break;
        case GL_TEXTURE_BINDING_CUBE_MAP:                 result = VKGL::ContextProperty::Texture_Binding_Cube_Map;                 break;
        case GL_TEXTURE_BINDING_RECTANGLE:                result = VKGL::ContextProperty::Texture_Binding_Rectangle;                break;
        case GL_TEXTURE_COMPRESSION_HINT:                 result = VKGL::ContextProperty::Texture_Compression_Hint;                 break;
        case GL_TIMESTAMP:                                result = VKGL::ContextProperty::Timestamp;                                break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_BINDING:        result = VKGL::ContextProperty::Transform_Feedback_Buffer_Binding;        break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_SIZE:           result = VKGL::ContextProperty::Transform_Feedback_Buffer_Size;           break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_START:          result = VKGL::ContextProperty::Transform_Feedback_Buffer_Start;          break;
        case GL_UNIFORM_BUFFER_BINDING:                   result = VKGL::ContextProperty::Uniform_Buffer_Binding;                   break;
        case GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT:          result = VKGL::ContextProperty::Uniform_Buffer_Offset_Alignment;          break;
        case GL_UNIFORM_BUFFER_SIZE:                      result = VKGL::ContextProperty::Uniform_Buffer_Size;                      break;
        case GL_UNIFORM_BUFFER_START:                     result = VKGL::ContextProperty::Uniform_Buffer_Start;                     break;
        case GL_UNPACK_ALIGNMENT:                         result = VKGL::ContextProperty::Unpack_Alignment;                         break;
        case GL_UNPACK_IMAGE_HEIGHT:                      result = VKGL::ContextProperty::Unpack_Image_Height;                      break;
        case GL_UNPACK_LSB_FIRST:                         result = VKGL::ContextProperty::Unpack_LSB_First;                         break;
        case GL_UNPACK_ROW_LENGTH:                        result = VKGL::ContextProperty::Unpack_Row_Length;                        break;
        case GL_UNPACK_SKIP_IMAGES:                       result = VKGL::ContextProperty::Unpack_Skip_Images;                       break;
        case GL_UNPACK_SKIP_PIXELS:                       result = VKGL::ContextProperty::Unpack_Skip_Pixels;                       break;
        case GL_UNPACK_SKIP_ROWS:                         result = VKGL::ContextProperty::Unpack_Skip_Rows;                         break;
        case GL_UNPACK_SWAP_BYTES:                        result = VKGL::ContextProperty::Unpack_Swap_Bytes;                        break;
        case GL_VIEWPORT:                                 result = VKGL::ContextProperty::Viewport;                                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::DrawCallIndexType VKGL::Utils::get_draw_call_index_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::DrawCallIndexType result = VKGL::DrawCallIndexType::Unknown;

    switch (in_enum)
    {
        case GL_UNSIGNED_BYTE:  result = VKGL::DrawCallIndexType::Unsigned_Byte;  break;
        case GL_UNSIGNED_SHORT: result = VKGL::DrawCallIndexType::Unsigned_Short; break;
        case GL_UNSIGNED_INT:   result = VKGL::DrawCallIndexType::Unsigned_Int;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::DrawCallMode VKGL::Utils::get_draw_call_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::DrawCallMode result = VKGL::DrawCallMode::Unknown;

    switch (in_enum)
    {
        default:
        {
            case GL_LINES:                    result = VKGL::DrawCallMode::Lines;                    break;
            case GL_LINES_ADJACENCY:          result = VKGL::DrawCallMode::Lines_Adjacency;          break;
            case GL_LINE_LOOP:                result = VKGL::DrawCallMode::Line_Loop;                break;
            case GL_LINE_STRIP:               result = VKGL::DrawCallMode::Line_Strip;               break;
            case GL_LINE_STRIP_ADJACENCY:     result = VKGL::DrawCallMode::Line_Strip_Adjacency;     break;
            case GL_PATCHES:                  result = VKGL::DrawCallMode::Patches;                  break;
            case GL_POINTS:                   result = VKGL::DrawCallMode::Points;                   break;
            case GL_TRIANGLE_FAN:             result = VKGL::DrawCallMode::Triangle_Fan;             break;
            case GL_TRIANGLE_STRIP:           result = VKGL::DrawCallMode::Triangle_Strip;           break;
            case GL_TRIANGLE_STRIP_ADJACENCY: result = VKGL::DrawCallMode::Triangle_Strip_Adjacency; break;
            case GL_TRIANGLES:                result = VKGL::DrawCallMode::Triangles;                break;
            case GL_TRIANGLES_ADJACENCY:      result = VKGL::DrawCallMode::Triangles_Adjacency;      break;

            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ErrorCode VKGL::Utils::get_error_code_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ErrorCode result = VKGL::ErrorCode::Unknown;

    switch (in_enum)
    {
        case GL_INVALID_ENUM:                  result = VKGL::ErrorCode::Invalid_Enum;                  break;
        case GL_INVALID_FRAMEBUFFER_OPERATION: result = VKGL::ErrorCode::Invalid_Framebuffer_Operation; break;
        case GL_INVALID_OPERATION:             result = VKGL::ErrorCode::Invalid_Operation;             break;
        case GL_INVALID_VALUE:                 result = VKGL::ErrorCode::Invalid_Value;                 break;
        case GL_NO_ERROR:                      result = VKGL::ErrorCode::No_Error;                      break;
        case GL_OUT_OF_MEMORY:                 result = VKGL::ErrorCode::Out_Of_Memory;                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FramebufferStatus VKGL::Utils::get_framebuffer_status_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FramebufferStatus result = VKGL::FramebufferStatus::Unknown;

    switch (in_enum)
    {
        case GL_FRAMEBUFFER_COMPLETE:                      result = VKGL::FramebufferStatus::Complete;                      break;
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:         result = VKGL::FramebufferStatus::Incomplete_Attachment;         break;
        case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:        result = VKGL::FramebufferStatus::Incomplete_Draw_Buffer;        break;
        case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:      result = VKGL::FramebufferStatus::Incomplete_Layer_Targets;      break;
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: result = VKGL::FramebufferStatus::Incomplete_Missing_Attachment; break;
        case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:        result = VKGL::FramebufferStatus::Incomplete_Multisample;        break;
        case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:        result = VKGL::FramebufferStatus::Incomplete_Read_Buffer;        break;
        case GL_FRAMEBUFFER_UNDEFINED:                     result = VKGL::FramebufferStatus::Undefined;                     break;
        case GL_FRAMEBUFFER_UNSUPPORTED:                   result = VKGL::FramebufferStatus::Unsupported;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_context_property(const VKGL::ContextProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::ContextProperty::Active_Texture:                           result = GL_ACTIVE_TEXTURE;                           break;
        case VKGL::ContextProperty::Aliased_Line_Width_Range:                 result = GL_ALIASED_LINE_WIDTH_RANGE;                 break;
        case VKGL::ContextProperty::Array_Buffer_Binding:                     result = GL_ARRAY_BUFFER_BINDING;                     break;
        case VKGL::ContextProperty::Blend:                                    result = GL_BLEND;                                    break;
        case VKGL::ContextProperty::Blend_Color:                              result = GL_BLEND_COLOR;                              break;
        case VKGL::ContextProperty::Blend_Dst_Alpha:                          result = GL_BLEND_DST_ALPHA;                          break;
        case VKGL::ContextProperty::Blend_Dst_RGB:                            result = GL_BLEND_DST_RGB;                            break;
        case VKGL::ContextProperty::Blend_Equation_Alpha:                     result = GL_BLEND_EQUATION_ALPHA;                     break;
        case VKGL::ContextProperty::Blend_Equation_RGB:                       result = GL_BLEND_EQUATION_RGB;                       break;
        case VKGL::ContextProperty::Blend_Src_Alpha:                          result = GL_BLEND_SRC_ALPHA;                          break;
        case VKGL::ContextProperty::Blend_Src_RGB:                            result = GL_BLEND_SRC_RGB;                            break;
        case VKGL::ContextProperty::Color_Clear_Value:                        result = GL_COLOR_CLEAR_VALUE;                        break;
        case VKGL::ContextProperty::Color_Logic_Op:                           result = GL_COLOR_LOGIC_OP;                           break;
        case VKGL::ContextProperty::Color_Writemask:                          result = GL_COLOR_WRITEMASK;                          break;
        case VKGL::ContextProperty::Compressed_Texture_Formats:               result = GL_COMPRESSED_TEXTURE_FORMATS;               break;
        case VKGL::ContextProperty::Context_Flags:                            result = GL_CONTEXT_FLAGS;                            break;
        case VKGL::ContextProperty::Cull_Face:                                result = GL_CULL_FACE;                                break;
        case VKGL::ContextProperty::Current_Program:                          result = GL_CURRENT_PROGRAM;                          break;
        case VKGL::ContextProperty::Depth_Clear_Value:                        result = GL_DEPTH_CLEAR_VALUE;                        break;
        case VKGL::ContextProperty::Depth_Func:                               result = GL_DEPTH_FUNC;                               break;
        case VKGL::ContextProperty::Depth_Range:                              result = GL_DEPTH_RANGE;                              break;
        case VKGL::ContextProperty::Depth_Test:                               result = GL_DEPTH_TEST;                               break;
        case VKGL::ContextProperty::Depth_Writemask:                          result = GL_DEPTH_WRITEMASK;                          break;
        case VKGL::ContextProperty::Dither:                                   result = GL_DITHER;                                   break;
        case VKGL::ContextProperty::Doublebuffer:                             result = GL_DOUBLEBUFFER;                             break;
        case VKGL::ContextProperty::Draw_Buffer:                              result = GL_DRAW_BUFFER;                              break;
        case VKGL::ContextProperty::Draw_Buffer0:                             result = GL_DRAW_BUFFER0;                             break;
        case VKGL::ContextProperty::Draw_Buffer1:                             result = GL_DRAW_BUFFER1;                             break;
        case VKGL::ContextProperty::Draw_Buffer2:                             result = GL_DRAW_BUFFER2;                             break;
        case VKGL::ContextProperty::Draw_Buffer3:                             result = GL_DRAW_BUFFER3;                             break;
        case VKGL::ContextProperty::Draw_Buffer4:                             result = GL_DRAW_BUFFER4;                             break;
        case VKGL::ContextProperty::Draw_Buffer5:                             result = GL_DRAW_BUFFER5;                             break;
        case VKGL::ContextProperty::Draw_Buffer6:                             result = GL_DRAW_BUFFER6;                             break;
        case VKGL::ContextProperty::Draw_Buffer7:                             result = GL_DRAW_BUFFER7;                             break;
        case VKGL::ContextProperty::Draw_Framebuffer_Binding:                 result = GL_DRAW_FRAMEBUFFER_BINDING;                 break;
        case VKGL::ContextProperty::Element_Array_Buffer_Binding:             result = GL_ELEMENT_ARRAY_BUFFER_BINDING;             break;
        case VKGL::ContextProperty::Fragment_Shader_Derivative_Hint:          result = GL_FRAGMENT_SHADER_DERIVATIVE_HINT;          break;
        case VKGL::ContextProperty::Line_Smooth:                              result = GL_LINE_SMOOTH;                              break;
        case VKGL::ContextProperty::Line_Smooth_Hint:                         result = GL_LINE_SMOOTH_HINT;                         break;
        case VKGL::ContextProperty::Line_Width:                               result = GL_LINE_WIDTH;                               break;
        case VKGL::ContextProperty::Logic_Op_Mode:                            result = GL_LOGIC_OP_MODE;                            break;
        case VKGL::ContextProperty::Major_Version:                            result = GL_MAJOR_VERSION;                            break;
        case VKGL::ContextProperty::Max_3D_Texture_Size:                      result = GL_MAX_3D_TEXTURE_SIZE;                      break;
        case VKGL::ContextProperty::Max_Array_Texture_Layers:                 result = GL_MAX_ARRAY_TEXTURE_LAYERS;                 break;
        case VKGL::ContextProperty::Max_Clip_Distances:                       result = GL_MAX_CLIP_DISTANCES;                       break;
        case VKGL::ContextProperty::Max_Color_Texture_Samples:                result = GL_MAX_COLOR_TEXTURE_SAMPLES;                break;
        case VKGL::ContextProperty::Max_Combined_Fragment_Uniform_Components: result = GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS; break;
        case VKGL::ContextProperty::Max_Combined_Geometry_Uniform_Components: result = GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS; break;
        case VKGL::ContextProperty::Max_Combined_Texture_Image_Units:         result = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS;         break;
        case VKGL::ContextProperty::Max_Combined_Uniform_Blocks:              result = GL_MAX_COMBINED_UNIFORM_BLOCKS;              break;
        case VKGL::ContextProperty::Max_Combined_Vertex_Uniform_Components:   result = GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS;   break;
        case VKGL::ContextProperty::Max_Cube_Map_Texture_Size:                result = GL_MAX_CUBE_MAP_TEXTURE_SIZE;                break;
        case VKGL::ContextProperty::Max_Depth_Texture_Samples:                result = GL_MAX_DEPTH_TEXTURE_SAMPLES;                break;
        case VKGL::ContextProperty::Max_Draw_Buffers:                         result = GL_MAX_DRAW_BUFFERS;                         break;
        case VKGL::ContextProperty::Max_Dual_Source_Draw_Buffers:             result = GL_MAX_DUAL_SOURCE_DRAW_BUFFERS;             break;
        case VKGL::ContextProperty::Max_Elements_Indices:                     result = GL_MAX_ELEMENTS_INDICES;                     break;
        case VKGL::ContextProperty::Max_Elements_Vertices:                    result = GL_MAX_ELEMENTS_VERTICES;                    break;
        case VKGL::ContextProperty::Max_Fragment_Input_Components:            result = GL_MAX_FRAGMENT_INPUT_COMPONENTS;            break;
        case VKGL::ContextProperty::Max_Fragment_Uniform_Blocks:              result = GL_MAX_FRAGMENT_UNIFORM_BLOCKS;              break;
        case VKGL::ContextProperty::Max_Fragment_Uniform_Components:          result = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS;          break;
        case VKGL::ContextProperty::Max_Geometry_Input_Components:            result = GL_MAX_GEOMETRY_INPUT_COMPONENTS;            break;
        case VKGL::ContextProperty::Max_Geometry_Output_Components:           result = GL_MAX_GEOMETRY_OUTPUT_COMPONENTS;           break;
        case VKGL::ContextProperty::Max_Geometry_Texture_Image_Units:         result = GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS;         break;
        case VKGL::ContextProperty::Max_Geometry_Uniform_Blocks:              result = GL_MAX_GEOMETRY_UNIFORM_BLOCKS;              break;
        case VKGL::ContextProperty::Max_Geometry_Uniform_Components:          result = GL_MAX_GEOMETRY_UNIFORM_COMPONENTS;          break;
        case VKGL::ContextProperty::Max_Integer_Samples:                      result = GL_MAX_INTEGER_SAMPLES;                      break;
        case VKGL::ContextProperty::Max_Program_Texel_Offset:                 result = GL_MAX_PROGRAM_TEXEL_OFFSET;                 break;
        case VKGL::ContextProperty::Max_Rectangle_Texture_Size:               result = GL_MAX_RECTANGLE_TEXTURE_SIZE;               break;
        case VKGL::ContextProperty::Max_Renderbuffer_Size:                    result = GL_MAX_RENDERBUFFER_SIZE;                    break;
        case VKGL::ContextProperty::Max_Sample_Mask_Words:                    result = GL_MAX_SAMPLE_MASK_WORDS;                    break;
        case VKGL::ContextProperty::Max_Server_Wait_Timeout:                  result = GL_MAX_SERVER_WAIT_TIMEOUT;                  break;
        case VKGL::ContextProperty::Max_Texture_Buffer_Size:                  result = GL_MAX_TEXTURE_BUFFER_SIZE;                  break;
        case VKGL::ContextProperty::Max_Texture_Image_Units:                  result = GL_MAX_TEXTURE_IMAGE_UNITS;                  break;
        case VKGL::ContextProperty::Max_Texture_LOD_Bias:                     result = GL_MAX_TEXTURE_LOD_BIAS;                     break;
        case VKGL::ContextProperty::Max_Texture_Size:                         result = GL_MAX_TEXTURE_SIZE;                         break;
        case VKGL::ContextProperty::Max_Uniform_Block_Size:                   result = GL_MAX_UNIFORM_BLOCK_SIZE;                   break;
        case VKGL::ContextProperty::Max_Uniform_Buffer_Bindings:              result = GL_MAX_UNIFORM_BUFFER_BINDINGS;              break;
        case VKGL::ContextProperty::Max_Varying_Components:                   result = GL_MAX_VARYING_COMPONENTS;                   break;
        case VKGL::ContextProperty::Max_Vertex_Attribs:                       result = GL_MAX_VERTEX_ATTRIBS;                       break;
        case VKGL::ContextProperty::Max_Vertex_Output_Components:             result = GL_MAX_VERTEX_OUTPUT_COMPONENTS;             break;
        case VKGL::ContextProperty::Max_Vertex_Texture_Image_Units:           result = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS;           break;
        case VKGL::ContextProperty::Max_Vertex_Uniform_Blocks:                result = GL_MAX_VERTEX_UNIFORM_BLOCKS;                break;
        case VKGL::ContextProperty::Max_Vertex_Uniform_Components:            result = GL_MAX_VERTEX_UNIFORM_COMPONENTS;            break;
        case VKGL::ContextProperty::Max_Viewport_Dims:                        result = GL_MAX_VIEWPORT_DIMS;                        break;
        case VKGL::ContextProperty::Minor_Version:                            result = GL_MINOR_VERSION;                            break;
        case VKGL::ContextProperty::Min_Program_Texel_Offset:                 result = GL_MIN_PROGRAM_TEXEL_OFFSET;                 break;
        case VKGL::ContextProperty::Num_Compressed_Texture_Formats:           result = GL_NUM_COMPRESSED_TEXTURE_FORMATS;           break;
        case VKGL::ContextProperty::Num_Extensions:                           result = GL_NUM_EXTENSIONS;                           break;
        case VKGL::ContextProperty::Pack_Alignment:                           result = GL_PACK_ALIGNMENT;                           break;
        case VKGL::ContextProperty::Pack_Image_Height:                        result = GL_PACK_IMAGE_HEIGHT;                        break;
        case VKGL::ContextProperty::Pack_LSB_First:                           result = GL_PACK_LSB_FIRST;                           break;
        case VKGL::ContextProperty::Pack_Row_Length:                          result = GL_PACK_ROW_LENGTH;                          break;
        case VKGL::ContextProperty::Pack_Skip_Images:                         result = GL_PACK_SKIP_IMAGES;                         break;
        case VKGL::ContextProperty::Pack_Skip_Pixels:                         result = GL_PACK_SKIP_PIXELS;                         break;
        case VKGL::ContextProperty::Pack_Skip_Rows:                           result = GL_PACK_SKIP_ROWS;                           break;
        case VKGL::ContextProperty::Pack_Swap_Bytes:                          result = GL_PACK_SWAP_BYTES;                          break;
        case VKGL::ContextProperty::Pixel_Pack_Buffer_Binding:                result = GL_PIXEL_PACK_BUFFER_BINDING;                break;
        case VKGL::ContextProperty::Pixel_Unpack_Buffer_Binding:              result = GL_PIXEL_UNPACK_BUFFER_BINDING;              break;
        case VKGL::ContextProperty::Point_Fade_Threshold_Size:                result = GL_POINT_FADE_THRESHOLD_SIZE;                break;
        case VKGL::ContextProperty::Point_Size:                               result = GL_POINT_SIZE;                               break;
        case VKGL::ContextProperty::Point_Size_Granularity:                   result = GL_POINT_SIZE_GRANULARITY;                   break;
        case VKGL::ContextProperty::Point_Size_Range:                         result = GL_POINT_SIZE_RANGE;                         break;
        case VKGL::ContextProperty::Polygon_Offset_Factor:                    result = GL_POLYGON_OFFSET_FACTOR;                    break;
        case VKGL::ContextProperty::Polygon_Offset_Fill:                      result = GL_POLYGON_OFFSET_FILL;                      break;
        case VKGL::ContextProperty::Polygon_Offset_Line:                      result = GL_POLYGON_OFFSET_LINE;                      break;
        case VKGL::ContextProperty::Polygon_Offset_Point:                     result = GL_POLYGON_OFFSET_POINT;                     break;
        case VKGL::ContextProperty::Polygon_Offset_Units:                     result = GL_POLYGON_OFFSET_UNITS;                     break;
        case VKGL::ContextProperty::Polygon_Smooth:                           result = GL_POLYGON_SMOOTH;                           break;
        case VKGL::ContextProperty::Polygon_Smooth_Hint:                      result = GL_POLYGON_SMOOTH_HINT;                      break;
        case VKGL::ContextProperty::Primitive_Restart_Index:                  result = GL_PRIMITIVE_RESTART_INDEX;                  break;
        case VKGL::ContextProperty::Program_Point_Size:                       result = GL_PROGRAM_POINT_SIZE;                       break;
        case VKGL::ContextProperty::Provoking_Vertex:                         result = GL_PROVOKING_VERTEX;                         break;
        case VKGL::ContextProperty::Read_Buffer:                              result = GL_READ_BUFFER;                              break;
        case VKGL::ContextProperty::Read_Framebuffer_Binding:                 result = GL_READ_FRAMEBUFFER_BINDING;                 break;
        case VKGL::ContextProperty::Renderbuffer_Binding:                     result = GL_RENDERBUFFER_BINDING;                     break;
        case VKGL::ContextProperty::Sampler_Binding:                          result = GL_SAMPLER_BINDING;                          break;
        case VKGL::ContextProperty::Samples:                                  result = GL_SAMPLES;                                  break;
        case VKGL::ContextProperty::Sample_Buffers:                           result = GL_SAMPLE_BUFFERS;                           break;
        case VKGL::ContextProperty::Sample_Coverage_Invert:                   result = GL_SAMPLE_COVERAGE_INVERT;                   break;
        case VKGL::ContextProperty::Sample_Coverage_Value:                    result = GL_SAMPLE_COVERAGE_VALUE;                    break;
        case VKGL::ContextProperty::Scissor_Box:                              result = GL_SCISSOR_BOX;                              break;
        case VKGL::ContextProperty::Scissor_Test:                             result = GL_SCISSOR_TEST;                             break;
        case VKGL::ContextProperty::Smooth_Line_Width_Granularity:            result = GL_SMOOTH_LINE_WIDTH_GRANULARITY;            break;
        case VKGL::ContextProperty::Smooth_Line_Width_Range:                  result = GL_SMOOTH_LINE_WIDTH_RANGE;                  break;
        case VKGL::ContextProperty::Stencil_Back_Fail:                        result = GL_STENCIL_BACK_FAIL;                        break;
        case VKGL::ContextProperty::Stencil_Back_Func:                        result = GL_STENCIL_BACK_FUNC;                        break;
        case VKGL::ContextProperty::Stencil_Back_Pass_Depth_Fail:             result = GL_STENCIL_BACK_PASS_DEPTH_FAIL;             break;
        case VKGL::ContextProperty::Stencil_Back_Pass_Depth_Pass:             result = GL_STENCIL_BACK_PASS_DEPTH_PASS;             break;
        case VKGL::ContextProperty::Stencil_Back_Ref:                         result = GL_STENCIL_BACK_REF;                         break;
        case VKGL::ContextProperty::Stencil_Back_Value_Mask:                  result = GL_STENCIL_BACK_VALUE_MASK;                  break;
        case VKGL::ContextProperty::Stencil_Back_Writemask:                   result = GL_STENCIL_BACK_WRITEMASK;                   break;
        case VKGL::ContextProperty::Stencil_Clear_Value:                      result = GL_STENCIL_CLEAR_VALUE;                      break;
        case VKGL::ContextProperty::Stencil_Fail:                             result = GL_STENCIL_FAIL;                             break;
        case VKGL::ContextProperty::Stencil_Func:                             result = GL_STENCIL_FUNC;                             break;
        case VKGL::ContextProperty::Stencil_Pass_Depth_Fail:                  result = GL_STENCIL_PASS_DEPTH_FAIL;                  break;
        case VKGL::ContextProperty::Stencil_Pass_Depth_Pass:                  result = GL_STENCIL_PASS_DEPTH_PASS;                  break;
        case VKGL::ContextProperty::Stencil_Ref:                              result = GL_STENCIL_REF;                              break;
        case VKGL::ContextProperty::Stencil_Test:                             result = GL_STENCIL_TEST;                             break;
        case VKGL::ContextProperty::Stencil_Value_Mask:                       result = GL_STENCIL_VALUE_MASK;                       break;
        case VKGL::ContextProperty::Stencil_Writemask:                        result = GL_STENCIL_WRITEMASK;                        break;
        case VKGL::ContextProperty::Stereo:                                   result = GL_STEREO;                                   break;
        case VKGL::ContextProperty::Subpixel_Bits:                            result = GL_SUBPIXEL_BITS;                            break;
        case VKGL::ContextProperty::Texture_Binding_1D:                       result = GL_TEXTURE_BINDING_1D;                       break;
        case VKGL::ContextProperty::Texture_Binding_1D_Array:                 result = GL_TEXTURE_BINDING_1D_ARRAY;                 break;
        case VKGL::ContextProperty::Texture_Binding_2D:                       result = GL_TEXTURE_BINDING_2D;                       break;
        case VKGL::ContextProperty::Texture_Binding_2D_Array:                 result = GL_TEXTURE_BINDING_2D_ARRAY;                 break;
        case VKGL::ContextProperty::Texture_Binding_2D_Multisample:           result = GL_TEXTURE_BINDING_2D_MULTISAMPLE;           break;
        case VKGL::ContextProperty::Texture_Binding_2D_Multisample_Array:     result = GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY;     break;
        case VKGL::ContextProperty::Texture_Binding_3D:                       result = GL_TEXTURE_BINDING_3D;                       break;
        case VKGL::ContextProperty::Texture_Binding_Buffer:                   result = GL_TEXTURE_BINDING_BUFFER;                   break;
        case VKGL::ContextProperty::Texture_Binding_Cube_Map:                 result = GL_TEXTURE_BINDING_CUBE_MAP;                 break;
        case VKGL::ContextProperty::Texture_Binding_Rectangle:                result = GL_TEXTURE_BINDING_RECTANGLE;                break;
        case VKGL::ContextProperty::Texture_Compression_Hint:                 result = GL_TEXTURE_COMPRESSION_HINT;                 break;
        case VKGL::ContextProperty::Timestamp:                                result = GL_TIMESTAMP;                                break;
        case VKGL::ContextProperty::Transform_Feedback_Buffer_Binding:        result = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING;        break;
        case VKGL::ContextProperty::Transform_Feedback_Buffer_Size:           result = GL_TRANSFORM_FEEDBACK_BUFFER_SIZE;           break;
        case VKGL::ContextProperty::Transform_Feedback_Buffer_Start:          result = GL_TRANSFORM_FEEDBACK_BUFFER_START;          break;
        case VKGL::ContextProperty::Uniform_Buffer_Binding:                   result = GL_UNIFORM_BUFFER_BINDING;                   break;
        case VKGL::ContextProperty::Uniform_Buffer_Offset_Alignment:          result = GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT;          break;
        case VKGL::ContextProperty::Uniform_Buffer_Size:                      result = GL_UNIFORM_BUFFER_SIZE;                      break;
        case VKGL::ContextProperty::Uniform_Buffer_Start:                     result = GL_UNIFORM_BUFFER_START;                     break;
        case VKGL::ContextProperty::Unpack_Alignment:                         result = GL_UNPACK_ALIGNMENT;                         break;
        case VKGL::ContextProperty::Unpack_Image_Height:                      result = GL_UNPACK_IMAGE_HEIGHT;                      break;
        case VKGL::ContextProperty::Unpack_LSB_First:                         result = GL_UNPACK_LSB_FIRST;                         break;
        case VKGL::ContextProperty::Unpack_Row_Length:                        result = GL_UNPACK_ROW_LENGTH;                        break;
        case VKGL::ContextProperty::Unpack_Skip_Images:                       result = GL_UNPACK_SKIP_IMAGES;                       break;
        case VKGL::ContextProperty::Unpack_Skip_Pixels:                       result = GL_UNPACK_SKIP_PIXELS;                       break;
        case VKGL::ContextProperty::Unpack_Skip_Rows:                         result = GL_UNPACK_SKIP_ROWS;                         break;
        case VKGL::ContextProperty::Unpack_Swap_Bytes:                        result = GL_UNPACK_SWAP_BYTES;                        break;
        case VKGL::ContextProperty::Viewport:                                 result = GL_VIEWPORT;                                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_error_code(const VKGL::ErrorCode& in_error)
{
    GLenum result = 0;

    switch (in_error)
    {
        case VKGL::ErrorCode::Invalid_Enum:                  result = GL_INVALID_ENUM;                  break;
        case VKGL::ErrorCode::Invalid_Framebuffer_Operation: result = GL_INVALID_FRAMEBUFFER_OPERATION; break;
        case VKGL::ErrorCode::Invalid_Operation:             result = GL_INVALID_OPERATION;             break;
        case VKGL::ErrorCode::Invalid_Value:                 result = GL_INVALID_VALUE;                 break;
        case VKGL::ErrorCode::No_Error:                      result = GL_NO_ERROR;                      break;
        case VKGL::ErrorCode::Out_Of_Memory:                 result = GL_OUT_OF_MEMORY;                 break;

        default:
        {
            vkgl_assert_fail();
        }
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

VKGL::DrawBuffer VKGL::Utils::get_draw_buffer_for_gl_enum(const GLenum& in_enum)
{
    VKGL::DrawBuffer result = VKGL::DrawBuffer::Unknown;

    switch (in_enum)
    {
        case GL_BACK:              result = VKGL::DrawBuffer::Back;              break;
        case GL_BACK_LEFT:         result = VKGL::DrawBuffer::Back_Left;         break;
        case GL_BACK_RIGHT:        result = VKGL::DrawBuffer::Back_Right;        break;
        case GL_COLOR_ATTACHMENT0: result = VKGL::DrawBuffer::Color_Attachment0; break;
        case GL_COLOR_ATTACHMENT1: result = VKGL::DrawBuffer::Color_Attachment1; break;
        case GL_COLOR_ATTACHMENT2: result = VKGL::DrawBuffer::Color_Attachment2; break;
        case GL_COLOR_ATTACHMENT3: result = VKGL::DrawBuffer::Color_Attachment3; break;
        case GL_COLOR_ATTACHMENT4: result = VKGL::DrawBuffer::Color_Attachment4; break;
        case GL_COLOR_ATTACHMENT5: result = VKGL::DrawBuffer::Color_Attachment5; break;
        case GL_COLOR_ATTACHMENT6: result = VKGL::DrawBuffer::Color_Attachment6; break;
        case GL_COLOR_ATTACHMENT7: result = VKGL::DrawBuffer::Color_Attachment7; break;
        case GL_FRONT:             result = VKGL::DrawBuffer::Front;             break;
        case GL_FRONT_AND_BACK:    result = VKGL::DrawBuffer::Front_And_Back;    break;
        case GL_FRONT_LEFT:        result = VKGL::DrawBuffer::Front_Left;        break;
        case GL_FRONT_RIGHT:       result = VKGL::DrawBuffer::Front_Right;       break;
        case GL_LEFT:              result = VKGL::DrawBuffer::Left;              break;
        case GL_RIGHT:             result = VKGL::DrawBuffer::Right;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FramebufferAttachmentComponentType VKGL::Utils::get_framebuffer_attachment_component_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FramebufferAttachmentComponentType result = VKGL::FramebufferAttachmentComponentType::Unknown;

    switch (in_enum)
    {
        case GL_FLOAT:               result = VKGL::FramebufferAttachmentComponentType::Float;               break;
        case GL_INT:                 result = VKGL::FramebufferAttachmentComponentType::Int;                 break;
        case GL_NONE:                result = VKGL::FramebufferAttachmentComponentType::None;                break;
        case GL_SIGNED_NORMALIZED:   result = VKGL::FramebufferAttachmentComponentType::Signed_Normalized;   break;
        case GL_UNSIGNED_INT:        result = VKGL::FramebufferAttachmentComponentType::Unsigned_Int;        break;
        case GL_UNSIGNED_NORMALIZED: result = VKGL::FramebufferAttachmentComponentType::Unsigned_Normalized; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FramebufferAttachmentObjectType VKGL::Utils::get_framebuffer_attachment_object_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FramebufferAttachmentObjectType result = VKGL::FramebufferAttachmentObjectType::Unknown;

    switch (in_enum)
    {
        case GL_FRAMEBUFFER_DEFAULT: result = VKGL::FramebufferAttachmentObjectType::Framebuffer_Default; break;
        case GL_NONE:                result = VKGL::FramebufferAttachmentObjectType::None;                break;
        case GL_RENDERBUFFER:        result = VKGL::FramebufferAttachmentObjectType::Renderbuffer;        break;
        case GL_TEXTURE:             result = VKGL::FramebufferAttachmentObjectType::Texture;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FramebufferAttachmentPoint VKGL::Utils::get_framebuffer_attachment_point_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FramebufferAttachmentPoint result = VKGL::FramebufferAttachmentPoint::Unknown;

    switch (in_enum)
    {
        case GL_COLOR_ATTACHMENT0:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment0;        break;
        case GL_COLOR_ATTACHMENT1:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment1;        break;
        case GL_COLOR_ATTACHMENT2:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment2;        break;
        case GL_COLOR_ATTACHMENT3:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment3;        break;
        case GL_COLOR_ATTACHMENT4:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment4;        break;
        case GL_COLOR_ATTACHMENT5:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment5;        break;
        case GL_COLOR_ATTACHMENT6:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment6;        break;
        case GL_COLOR_ATTACHMENT7:        result = VKGL::FramebufferAttachmentPoint::Color_Attachment7;        break;
        case GL_DEPTH_ATTACHMENT:         result = VKGL::FramebufferAttachmentPoint::Depth_Attachment;         break;
        case GL_DEPTH_STENCIL_ATTACHMENT: result = VKGL::FramebufferAttachmentPoint::Depth_Stencil_Attachment; break;
        case GL_STENCIL_ATTACHMENT:       result = VKGL::FramebufferAttachmentPoint::Stencil_Attachment;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FramebufferAttachmentProperty VKGL::Utils::get_framebuffer_attachment_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FramebufferAttachmentProperty result = VKGL::FramebufferAttachmentProperty::Unknown;

    switch (in_enum)
    {
        case GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE:            result = VKGL::FramebufferAttachmentProperty::Alpha_Size;             break;
        case GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE:             result = VKGL::FramebufferAttachmentProperty::Blue_Size;              break;
        case GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING:        result = VKGL::FramebufferAttachmentProperty::Color_Encoding;         break;
        case GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE:        result = VKGL::FramebufferAttachmentProperty::Component_Type;         break;
        case GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE:            result = VKGL::FramebufferAttachmentProperty::Depth_Size;             break;
        case GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE:            result = VKGL::FramebufferAttachmentProperty::Green_Size;             break;
        case GL_FRAMEBUFFER_ATTACHMENT_LAYERED:               result = VKGL::FramebufferAttachmentProperty::Layered;                break;
        case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME:           result = VKGL::FramebufferAttachmentProperty::Object_Name;            break;
        case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE:           result = VKGL::FramebufferAttachmentProperty::Object_Type;            break;
        case GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE:              result = VKGL::FramebufferAttachmentProperty::Red_Size;               break;
        case GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE:          result = VKGL::FramebufferAttachmentProperty::Stencil_Size;           break;
        case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE: result = VKGL::FramebufferAttachmentProperty::Texture_Cube_Map_Face;  break;
        case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER:         result = VKGL::FramebufferAttachmentProperty::Texture_Layer;          break;
        case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL:         result = VKGL::FramebufferAttachmentProperty::Texture_Level;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::FramebufferTarget VKGL::Utils::get_framebuffer_target_for_gl_enum(const GLenum& in_enum)
{
    VKGL::FramebufferTarget result = VKGL::FramebufferTarget::Unknown;

    switch (in_enum)
    {
        case GL_DRAW_FRAMEBUFFER: result = VKGL::FramebufferTarget::Draw_Framebuffer; break;
        case GL_FRAMEBUFFER:      result = VKGL::FramebufferTarget::Framebuffer;      break;
        case GL_READ_FRAMEBUFFER: result = VKGL::FramebufferTarget::Read_Framebuffer; break;

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

VKGL::GeometryInputType VKGL::Utils::get_geometry_input_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::GeometryInputType result = VKGL::GeometryInputType::Unknown;

    switch (in_enum)
    {
        case GL_LINES:               result = VKGL::GeometryInputType::Lines;               break;
        case GL_LINES_ADJACENCY:     result = VKGL::GeometryInputType::Lines_Adjacency;     break;
        case GL_POINTS:              result = VKGL::GeometryInputType::Points;              break;
        case GL_TRIANGLES:           result = VKGL::GeometryInputType::Triangles;           break;
        case GL_TRIANGLES_ADJACENCY: result = VKGL::GeometryInputType::Triangles_Adjacency; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::GeometryOutputType VKGL::Utils::get_geometry_output_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::GeometryOutputType result = VKGL::GeometryOutputType::Unknown;

    switch (in_enum)
    {
        case GL_LINE_STRIP:     result = VKGL::GeometryOutputType::Line_Strip;     break;
        case GL_POINTS:         result = VKGL::GeometryOutputType::Points;         break;
        case GL_TRIANGLE_STRIP: result = VKGL::GeometryOutputType::Triangle_Strip; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_buffer_pointer_property(const VKGL::BufferPointerProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::BufferPointerProperty::Buffer_Map_Pointer: result = GL_BUFFER_MAP_POINTER; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_buffer_property(const VKGL::BufferProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::BufferProperty::Buffer_Access: result = GL_BUFFER_ACCESS; break;
        case VKGL::BufferProperty::Buffer_Mapped: result = GL_BUFFER_MAPPED; break;
        case VKGL::BufferProperty::Buffer_Size:   result = GL_BUFFER_SIZE;   break;
        case VKGL::BufferProperty::Buffer_Usage:  result = GL_BUFFER_USAGE;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_geometry_input_type(const VKGL::GeometryInputType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::GeometryInputType::Lines:               result = GL_LINES;               break;
        case VKGL::GeometryInputType::Lines_Adjacency:     result = GL_LINES_ADJACENCY;     break;
        case VKGL::GeometryInputType::Points:              result = GL_POINTS;              break;
        case VKGL::GeometryInputType::Triangles:           result = GL_TRIANGLES;           break;
        case VKGL::GeometryInputType::Triangles_Adjacency: result = GL_TRIANGLES_ADJACENCY; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_geometry_output_type(const VKGL::GeometryOutputType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::GeometryOutputType::Line_Strip:     result = GL_LINE_STRIP;     break;
        case VKGL::GeometryOutputType::Points:         result = GL_POINTS;         break;
        case VKGL::GeometryOutputType::Triangle_Strip: result = GL_TRIANGLE_STRIP; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_blend_equation(const VKGL::BlendEquation& in_blend_equation)
{
    GLenum result = 0;

    switch (in_blend_equation)
    {
        case VKGL::BlendEquation::Function_Add:              result = GL_FUNC_ADD;              break;
        case VKGL::BlendEquation::Function_Reverse_Subtract: result = GL_FUNC_REVERSE_SUBTRACT; break;
        case VKGL::BlendEquation::Function_Subtract:         result = GL_FUNC_SUBTRACT;         break;
        case VKGL::BlendEquation::Max:                       result = GL_MAX;                   break;
        case VKGL::BlendEquation::Min:                       result = GL_MIN;                   break;

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

GLenum VKGL::Utils::get_gl_enum_for_blit_filter(const VKGL::BlitFilter& in_filter)
{
    GLenum result = 0;

    switch (in_filter)
    {
        case VKGL::BlitFilter::Linear:  result = GL_LINEAR;  break;
        case VKGL::BlitFilter::Nearest: result = GL_NEAREST; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_blit_mask_bits(const VKGL::BlitMaskBits& in_bits)
{
    GLenum result = 0;

    if (in_bits & VKGL::BlitMaskBit::BLIT_MASK_BIT_COLOR_BUFFER)
    {
        result |= GL_COLOR_BUFFER_BIT;
    }

    if (in_bits & VKGL::BlitMaskBit::BLIT_MASK_BIT_DEPTH_BUFFER)
    {
        result |= GL_DEPTH_BUFFER_BIT;
    }

    if (in_bits & VKGL::BlitMaskBit::BLIT_MASK_BIT_STENCIL_BUFFER)
    {
        result |= GL_STENCIL_BUFFER_BIT;
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_buffer_access(const VKGL::BufferAccess& in_access)
{
    GLenum result = 0;

    switch (in_access)
    {
        case VKGL::BufferAccess::Read_Only:  result = GL_READ_ONLY;  break;
        case VKGL::BufferAccess::Read_Write: result = GL_READ_WRITE; break;
        case VKGL::BufferAccess::Write_Only: result = GL_WRITE_ONLY; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_buffer_target(const VKGL::BufferTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case VKGL::BufferTarget::Array_Buffer:              result = GL_ARRAY_BUFFER;              break;
        case VKGL::BufferTarget::Copy_Read_Buffer:          result = GL_COPY_READ_BUFFER;          break;
        case VKGL::BufferTarget::Copy_Write_Buffer:         result = GL_COPY_WRITE_BUFFER;         break;
        case VKGL::BufferTarget::Element_Array_Buffer:      result = GL_ELEMENT_ARRAY_BUFFER;      break;
        case VKGL::BufferTarget::Pixel_Pack_Buffer:         result = GL_PIXEL_PACK_BUFFER;         break;
        case VKGL::BufferTarget::Pixel_Unpack_Buffer:       result = GL_PIXEL_UNPACK_BUFFER;       break;
        case VKGL::BufferTarget::Texture_Buffer:            result = GL_TEXTURE_BUFFER;            break;
        case VKGL::BufferTarget::Transform_Feedback_Buffer: result = GL_TRANSFORM_FEEDBACK_BUFFER; break;
        case VKGL::BufferTarget::Uniform_Buffer:            result = GL_UNIFORM_BUFFER;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_buffer_usage(const VKGL::BufferUsage& in_usage)
{
    GLenum result = 0;

    switch (in_usage)
    {
        case VKGL::BufferUsage::Dynamic_Copy: result = GL_DYNAMIC_COPY; break;
        case VKGL::BufferUsage::Dynamic_Draw: result = GL_DYNAMIC_DRAW; break;
        case VKGL::BufferUsage::Dynamic_Read: result = GL_DYNAMIC_READ; break;
        case VKGL::BufferUsage::Static_Copy:  result = GL_STATIC_COPY;  break;
        case VKGL::BufferUsage::Static_Draw:  result = GL_STATIC_DRAW;  break;
        case VKGL::BufferUsage::Static_Read:  result = GL_STATIC_READ;  break;
        case VKGL::BufferUsage::Stream_Copy:  result = GL_STREAM_COPY;  break;
        case VKGL::BufferUsage::Stream_Draw:  result = GL_STREAM_DRAW;  break;
        case VKGL::BufferUsage::Stream_Read:  result = GL_STREAM_READ;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_clamp_read_color_mode(const VKGL::ClampReadColorMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case VKGL::ClampReadColorMode::False:      result = GL_FALSE;      break;
        case VKGL::ClampReadColorMode::Fixed_Only: result = GL_FIXED_ONLY; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_clear_buffer(const VKGL::ClearBuffer& in_clear_buffer)
{
    GLenum result = 0;

    switch (in_clear_buffer)
    {
        case VKGL::ClearBuffer::Back:           result = GL_BACK;           break;
        case VKGL::ClearBuffer::Color:          result = GL_COLOR;          break;
        case VKGL::ClearBuffer::Depth:          result = GL_DEPTH;          break;
        case VKGL::ClearBuffer::Depth_Stencil:  result = GL_DEPTH_STENCIL;  break;
        case VKGL::ClearBuffer::Front:          result = GL_FRONT;          break;
        case VKGL::ClearBuffer::Front_And_Back: result = GL_FRONT_AND_BACK; break;
        case VKGL::ClearBuffer::Left:           result = GL_LEFT;           break;
        case VKGL::ClearBuffer::Right:          result = GL_RIGHT;          break;
        case VKGL::ClearBuffer::Stencil:        result = GL_STENCIL;        break;

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

GLenum VKGL::Utils::get_gl_enum_for_conditional_render_mode(const VKGL::ConditionalRenderMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case VKGL::ConditionalRenderMode::Query_By_Region_No_Wait: result = GL_QUERY_BY_REGION_NO_WAIT; break;
        case VKGL::ConditionalRenderMode::Query_By_Region_Wait:    result = GL_QUERY_BY_REGION_WAIT;    break;

        default:
        {
            vkgl_assert_fail();
        }
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

GLenum VKGL::Utils::get_gl_enum_for_draw_buffer(const VKGL::DrawBuffer& in_draw_buffer)
{
    GLenum result = 0;

    switch (in_draw_buffer)
    {
        case VKGL::DrawBuffer::Back:              result = GL_BACK;              break;
        case VKGL::DrawBuffer::Back_Left:         result = GL_BACK_LEFT;         break;
        case VKGL::DrawBuffer::Back_Right:        result = GL_BACK_RIGHT;        break;
        case VKGL::DrawBuffer::Color_Attachment0: result = GL_COLOR_ATTACHMENT0; break;
        case VKGL::DrawBuffer::Color_Attachment1: result = GL_COLOR_ATTACHMENT1; break;
        case VKGL::DrawBuffer::Color_Attachment2: result = GL_COLOR_ATTACHMENT2; break;
        case VKGL::DrawBuffer::Color_Attachment3: result = GL_COLOR_ATTACHMENT3; break;
        case VKGL::DrawBuffer::Color_Attachment4: result = GL_COLOR_ATTACHMENT4; break;
        case VKGL::DrawBuffer::Color_Attachment5: result = GL_COLOR_ATTACHMENT5; break;
        case VKGL::DrawBuffer::Color_Attachment6: result = GL_COLOR_ATTACHMENT6; break;
        case VKGL::DrawBuffer::Color_Attachment7: result = GL_COLOR_ATTACHMENT7; break;
        case VKGL::DrawBuffer::Front:             result = GL_FRONT;             break;
        case VKGL::DrawBuffer::Front_And_Back:    result = GL_FRONT_AND_BACK;    break;
        case VKGL::DrawBuffer::Front_Left:        result = GL_FRONT_LEFT;        break;
        case VKGL::DrawBuffer::Front_Right:       result = GL_FRONT_RIGHT;       break;
        case VKGL::DrawBuffer::Left:              result = GL_LEFT;              break;
        case VKGL::DrawBuffer::Right:             result = GL_RIGHT;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_draw_call_index_type(const VKGL::DrawCallIndexType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::DrawCallIndexType::Unsigned_Byte:  result = GL_UNSIGNED_BYTE;  break;
        case VKGL::DrawCallIndexType::Unsigned_Short: result = GL_UNSIGNED_SHORT; break;
        case VKGL::DrawCallIndexType::Unsigned_Int:   result = GL_UNSIGNED_INT;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_draw_call_mode(const VKGL::DrawCallMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        default:
        {
            case VKGL::DrawCallMode::Lines:                    result = GL_LINES;                    break;
            case VKGL::DrawCallMode::Lines_Adjacency:          result = GL_LINES_ADJACENCY;          break;
            case VKGL::DrawCallMode::Line_Loop:                result = GL_LINE_LOOP;                break;
            case VKGL::DrawCallMode::Line_Strip:               result = GL_LINE_STRIP;               break;
            case VKGL::DrawCallMode::Line_Strip_Adjacency:     result = GL_LINE_STRIP_ADJACENCY;     break;
            case VKGL::DrawCallMode::Patches:                  result = GL_PATCHES;                  break;
            case VKGL::DrawCallMode::Points:                   result = GL_POINTS;                   break;
            case VKGL::DrawCallMode::Triangle_Fan:             result = GL_TRIANGLE_FAN;             break;
            case VKGL::DrawCallMode::Triangle_Strip:           result = GL_TRIANGLE_STRIP;           break;
            case VKGL::DrawCallMode::Triangle_Strip_Adjacency: result = GL_TRIANGLE_STRIP_ADJACENCY; break;
            case VKGL::DrawCallMode::Triangles:                result = GL_TRIANGLES;                break;
            case VKGL::DrawCallMode::Triangles_Adjacency:      result = GL_TRIANGLES_ADJACENCY;      break;

            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_framebuffer_attachment_component_type(const VKGL::FramebufferAttachmentComponentType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::FramebufferAttachmentComponentType::Float:               result = GL_FLOAT;               break;
        case VKGL::FramebufferAttachmentComponentType::Int:                 result = GL_INT;                 break;
        case VKGL::FramebufferAttachmentComponentType::None:                result = GL_NONE;                break;
        case VKGL::FramebufferAttachmentComponentType::Signed_Normalized:   result = GL_SIGNED_NORMALIZED;   break;
        case VKGL::FramebufferAttachmentComponentType::Unsigned_Int:        result = GL_UNSIGNED_INT;        break;
        case VKGL::FramebufferAttachmentComponentType::Unsigned_Normalized: result = GL_UNSIGNED_NORMALIZED; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_framebuffer_attachment_object_type(const VKGL::FramebufferAttachmentObjectType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::FramebufferAttachmentObjectType::Framebuffer_Default: result = GL_FRAMEBUFFER_DEFAULT; break;
        case VKGL::FramebufferAttachmentObjectType::None:                result = GL_NONE;                break;
        case VKGL::FramebufferAttachmentObjectType::Renderbuffer:        result = GL_RENDERBUFFER;        break;
        case VKGL::FramebufferAttachmentObjectType::Texture:             result = GL_TEXTURE;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_framebuffer_attachment_point(const VKGL::FramebufferAttachmentPoint& in_fb_attachment_point)
{
    GLenum result = 0;

    switch (in_fb_attachment_point)
    {
        case VKGL::FramebufferAttachmentPoint::Color_Attachment0:        result = GL_COLOR_ATTACHMENT0;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment1:        result = GL_COLOR_ATTACHMENT1;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment2:        result = GL_COLOR_ATTACHMENT2;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment3:        result = GL_COLOR_ATTACHMENT3;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment4:        result = GL_COLOR_ATTACHMENT4;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment5:        result = GL_COLOR_ATTACHMENT5;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment6:        result = GL_COLOR_ATTACHMENT6;        break;
        case VKGL::FramebufferAttachmentPoint::Color_Attachment7:        result = GL_COLOR_ATTACHMENT7;        break;
        case VKGL::FramebufferAttachmentPoint::Depth_Attachment:         result = GL_DEPTH_ATTACHMENT;         break;
        case VKGL::FramebufferAttachmentPoint::Depth_Stencil_Attachment: result = GL_DEPTH_STENCIL_ATTACHMENT; break;
        case VKGL::FramebufferAttachmentPoint::Stencil_Attachment:       result = GL_STENCIL_ATTACHMENT;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_framebuffer_attachment_property(const VKGL::FramebufferAttachmentProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case VKGL::FramebufferAttachmentProperty::Alpha_Size:             result = GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE;            break;
        case VKGL::FramebufferAttachmentProperty::Blue_Size:              result = GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE;             break;
        case VKGL::FramebufferAttachmentProperty::Color_Encoding:         result = GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING;        break;
        case VKGL::FramebufferAttachmentProperty::Component_Type:         result = GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE;        break;
        case VKGL::FramebufferAttachmentProperty::Depth_Size:             result = GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE;            break;
        case VKGL::FramebufferAttachmentProperty::Green_Size:             result = GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE;            break;
        case VKGL::FramebufferAttachmentProperty::Layered:                result = GL_FRAMEBUFFER_ATTACHMENT_LAYERED;               break;
        case VKGL::FramebufferAttachmentProperty::Object_Name:            result = GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME;           break;
        case VKGL::FramebufferAttachmentProperty::Object_Type:            result = GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE;           break;
        case VKGL::FramebufferAttachmentProperty::Red_Size:               result = GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE;              break;
        case VKGL::FramebufferAttachmentProperty::Stencil_Size:           result = GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE;          break;
        case VKGL::FramebufferAttachmentProperty::Texture_Cube_Map_Face:  result = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE; break;
        case VKGL::FramebufferAttachmentProperty::Texture_Layer:          result = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER;         break;
        case VKGL::FramebufferAttachmentProperty::Texture_Level:          result = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL;         break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_framebuffer_status(const VKGL::FramebufferStatus& in_status)
{
    GLenum result = 0;

    switch (in_status)
    {
        case VKGL::FramebufferStatus::Complete:                      result = GL_FRAMEBUFFER_COMPLETE;                      break;
        case VKGL::FramebufferStatus::Incomplete_Attachment:         result = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT;         break;
        case VKGL::FramebufferStatus::Incomplete_Draw_Buffer:        result = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER;        break;
        case VKGL::FramebufferStatus::Incomplete_Layer_Targets:      result = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS;      break;
        case VKGL::FramebufferStatus::Incomplete_Missing_Attachment: result = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT; break;
        case VKGL::FramebufferStatus::Incomplete_Multisample:        result = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE;        break;
        case VKGL::FramebufferStatus::Incomplete_Read_Buffer:        result = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER;        break;
        case VKGL::FramebufferStatus::Undefined:                     result = GL_FRAMEBUFFER_UNDEFINED;                     break;
        case VKGL::FramebufferStatus::Unsupported:                   result = GL_FRAMEBUFFER_UNSUPPORTED;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_framebuffer_target(const VKGL::FramebufferTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case VKGL::FramebufferTarget::Draw_Framebuffer: result = GL_DRAW_FRAMEBUFFER; break;
        case VKGL::FramebufferTarget::Framebuffer:      result = GL_FRAMEBUFFER;      break;
        case VKGL::FramebufferTarget::Read_Framebuffer: result = GL_READ_FRAMEBUFFER; break;

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

GLenum VKGL::Utils::get_gl_enum_for_hint_target(const VKGL::HintTarget& in_hint_target)
{
    GLenum result = 0;

    switch (in_hint_target)
    {
        case VKGL::HintTarget::Fragment_Shader_Derivative: result = GL_FRAGMENT_SHADER_DERIVATIVE_HINT; break;
        case VKGL::HintTarget::Line_Smooth:                result = GL_LINE_SMOOTH_HINT;               break;
        case VKGL::HintTarget::Polygon_Smooth:             result = GL_POLYGON_SMOOTH_HINT;            break;
        case VKGL::HintTarget::Texture_Compression:        result = GL_TEXTURE_COMPRESSION_HINT;       break;

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

GLenum VKGL::Utils::get_gl_enum_for_mipmap_generation_texture_target(const VKGL::MipmapGenerationTextureTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case VKGL::MipmapGenerationTextureTarget::Texture_1D:       result = GL_TEXTURE_1D;       break;
        case VKGL::MipmapGenerationTextureTarget::Texture_1D_Array: result = GL_TEXTURE_1D_ARRAY; break;
        case VKGL::MipmapGenerationTextureTarget::Texture_2D:       result = GL_TEXTURE_2D;       break;
        case VKGL::MipmapGenerationTextureTarget::Texture_2D_Array: result = GL_TEXTURE_2D_ARRAY; break;
        case VKGL::MipmapGenerationTextureTarget::Texture_3D:       result = GL_TEXTURE_3D;       break;
        case VKGL::MipmapGenerationTextureTarget::Texture_Cube_Map: result = GL_TEXTURE_CUBE_MAP; break;

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

GLenum VKGL::Utils::get_gl_enum_for_pixel_store_property(const VKGL::PixelStoreProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::PixelStoreProperty::Pack_Alignment:      result = GL_PACK_ALIGNMENT;      break;
        case VKGL::PixelStoreProperty::Pack_Image_Height:   result = GL_PACK_IMAGE_HEIGHT;   break;
        case VKGL::PixelStoreProperty::Pack_LSB_First:      result = GL_PACK_LSB_FIRST;      break;
        case VKGL::PixelStoreProperty::Pack_Row_Length:     result = GL_PACK_ROW_LENGTH;     break;
        case VKGL::PixelStoreProperty::Pack_Skip_Images:    result = GL_PACK_SKIP_IMAGES;    break;
        case VKGL::PixelStoreProperty::Pack_Skip_Pixels:    result = GL_PACK_SKIP_PIXELS;    break;
        case VKGL::PixelStoreProperty::Pack_Skip_Rows:      result = GL_PACK_SKIP_ROWS;      break;
        case VKGL::PixelStoreProperty::Pack_Swap_Bytes:     result = GL_PACK_SWAP_BYTES;     break;
        case VKGL::PixelStoreProperty::Unpack_Alignment:    result = GL_UNPACK_ALIGNMENT;    break;
        case VKGL::PixelStoreProperty::Unpack_Image_Height: result = GL_UNPACK_IMAGE_HEIGHT; break;
        case VKGL::PixelStoreProperty::Unpack_LSB_First:    result = GL_UNPACK_LSB_FIRST;    break;
        case VKGL::PixelStoreProperty::Unpack_Row_Length:   result = GL_UNPACK_ROW_LENGTH;   break;
        case VKGL::PixelStoreProperty::Unpack_Skip_Images:  result = GL_UNPACK_SKIP_IMAGES;  break;
        case VKGL::PixelStoreProperty::Unpack_Skip_Pixels:  result = GL_UNPACK_SKIP_PIXELS;  break;
        case VKGL::PixelStoreProperty::Unpack_Skip_Rows:    result = GL_UNPACK_SKIP_ROWS;    break;
        case VKGL::PixelStoreProperty::Unpack_Swap_Bytes:   result = GL_UNPACK_SWAP_BYTES;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_point_sprite_coord_origin(const VKGL::PointSpriteCoordOrigin& in_origin)
{
    GLenum result = 0;

    switch (in_origin)
    {
        case VKGL::PointSpriteCoordOrigin::Lower_Left: result = GL_LOWER_LEFT; break;
        case VKGL::PointSpriteCoordOrigin::Upper_Left: result = GL_UPPER_LEFT; break;

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

GLenum VKGL::Utils::get_gl_enum_for_point_property(const VKGL::PointProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::PointProperty::Fade_Threshold_Size: result = GL_POINT_FADE_THRESHOLD_SIZE; break;
        case VKGL::PointProperty::Sprite_Coord_Origin: result = GL_POINT_SPRITE_COORD_ORIGIN; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_program_property(const VKGL::ProgramProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case VKGL::ProgramProperty::Active_Attributes:                     result = GL_ACTIVE_ATTRIBUTES;                     break;
        case VKGL::ProgramProperty::Active_Attribute_Max_Length:           result = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH;           break;
        case VKGL::ProgramProperty::Active_Uniforms:                       result = GL_ACTIVE_UNIFORMS;                       break;
        case VKGL::ProgramProperty::Active_Uniform_Blocks:                 result = GL_ACTIVE_UNIFORM_BLOCKS;                 break;
        case VKGL::ProgramProperty::Active_Uniform_Block_Max_Name_Length:  result = GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH;  break;
        case VKGL::ProgramProperty::Active_Uniform_Max_Length:             result = GL_ACTIVE_UNIFORM_MAX_LENGTH;             break;
        case VKGL::ProgramProperty::Attached_Shaders:                      result = GL_ATTACHED_SHADERS;                      break;
        case VKGL::ProgramProperty::Delete_Status:                         result = GL_DELETE_STATUS;                         break;
        case VKGL::ProgramProperty::Geometry_Input_Type:                   result = GL_GEOMETRY_INPUT_TYPE;                   break;
        case VKGL::ProgramProperty::Geometry_Output_Type:                  result = GL_GEOMETRY_OUTPUT_TYPE;                  break;
        case VKGL::ProgramProperty::Geometry_Vertices_Out:                 result = GL_GEOMETRY_VERTICES_OUT;                 break;
        case VKGL::ProgramProperty::Info_Log_Length:                       result = GL_INFO_LOG_LENGTH;                       break;
        case VKGL::ProgramProperty::Link_Status:                           result = GL_LINK_STATUS;                           break;
        case VKGL::ProgramProperty::Transform_Feedback_Buffer_Mode:        result = GL_TRANSFORM_FEEDBACK_BUFFER_MODE;        break;
        case VKGL::ProgramProperty::Transform_Feedback_Varyings:           result = GL_TRANSFORM_FEEDBACK_VARYINGS;           break;
        case VKGL::ProgramProperty::Transform_Feedback_Varying_Max_Length: result = GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH; break;
        case VKGL::ProgramProperty::Validate_Status:                       result = GL_VALIDATE_STATUS;                       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_provoking_vertex_convention(const VKGL::ProvokingVertexConvention& in_convention)
{
    GLenum result = 0;

    switch (in_convention)
    {
        case VKGL::ProvokingVertexConvention::First: result = GL_FIRST_VERTEX_CONVENTION; break;
        case VKGL::ProvokingVertexConvention::Last:  result = GL_LAST_VERTEX_CONVENTION;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_query_property(const VKGL::QueryProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::QueryProperty::Query_Result:           result = GL_QUERY_RESULT;           break;
        case VKGL::QueryProperty::Query_Result_Available: result = GL_QUERY_RESULT_AVAILABLE; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_query_target(const VKGL::QueryTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case VKGL::QueryTarget::Primitives_Generated:                  result = GL_PRIMITIVES_GENERATED;                  break;
        case VKGL::QueryTarget::Samples_Passed:                        result = GL_SAMPLES_PASSED;                        break;
        case VKGL::QueryTarget::Transform_Feedback_Primitives_Written: result = GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_query_target_property(const VKGL::QueryTargetProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::QueryTargetProperty::Current_Query:      result = GL_CURRENT_QUERY;      break;
        case VKGL::QueryTargetProperty::Query_Counter_Bits: result = GL_QUERY_COUNTER_BITS; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_read_buffer(const VKGL::ReadBuffer& in_read_buffer)
{
    GLenum result = 0;

    switch (in_read_buffer)
    {
        case VKGL::ReadBuffer::Back:              result = GL_BACK;              break;
        case VKGL::ReadBuffer::Back_Left:         result = GL_BACK_LEFT;         break;
        case VKGL::ReadBuffer::Back_Right:        result = GL_BACK_RIGHT;        break;
        case VKGL::ReadBuffer::Color_Attachment0: result = GL_COLOR_ATTACHMENT0; break;
        case VKGL::ReadBuffer::Color_Attachment1: result = GL_COLOR_ATTACHMENT1; break;
        case VKGL::ReadBuffer::Color_Attachment2: result = GL_COLOR_ATTACHMENT2; break;
        case VKGL::ReadBuffer::Color_Attachment3: result = GL_COLOR_ATTACHMENT3; break;
        case VKGL::ReadBuffer::Color_Attachment4: result = GL_COLOR_ATTACHMENT4; break;
        case VKGL::ReadBuffer::Color_Attachment5: result = GL_COLOR_ATTACHMENT5; break;
        case VKGL::ReadBuffer::Color_Attachment6: result = GL_COLOR_ATTACHMENT6; break;
        case VKGL::ReadBuffer::Color_Attachment7: result = GL_COLOR_ATTACHMENT7; break;
        case VKGL::ReadBuffer::Front:             result = GL_FRONT;             break;
        case VKGL::ReadBuffer::Front_And_Back:    result = GL_FRONT_AND_BACK;    break;
        case VKGL::ReadBuffer::Front_Left:        result = GL_FRONT_LEFT;        break;
        case VKGL::ReadBuffer::Front_Right:       result = GL_FRONT_RIGHT;       break;
        case VKGL::ReadBuffer::Left:              result = GL_LEFT;              break;
        case VKGL::ReadBuffer::Right:             result = GL_RIGHT;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_renderbuffer_property(const VKGL::RenderbufferProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case VKGL::RenderbufferProperty::Alpha_Size:      result = GL_RENDERBUFFER_ALPHA_SIZE;
        case VKGL::RenderbufferProperty::Blue_Size:       result = GL_RENDERBUFFER_BLUE_SIZE;
        case VKGL::RenderbufferProperty::Depth_Size:      result = GL_RENDERBUFFER_DEPTH_SIZE;
        case VKGL::RenderbufferProperty::Green_Size:      result = GL_RENDERBUFFER_GREEN_SIZE;
        case VKGL::RenderbufferProperty::Height:          result = GL_RENDERBUFFER_HEIGHT;
        case VKGL::RenderbufferProperty::Internal_Format: result = GL_RENDERBUFFER_INTERNAL_FORMAT;
        case VKGL::RenderbufferProperty::Red_Size:        result = GL_RENDERBUFFER_RED_SIZE;
        case VKGL::RenderbufferProperty::Samples:         result = GL_RENDERBUFFER_SAMPLES;
        case VKGL::RenderbufferProperty::Stencil_Size:    result = GL_RENDERBUFFER_STENCIL_SIZE;
        case VKGL::RenderbufferProperty::Width:           result = GL_RENDERBUFFER_WIDTH;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_renderbuffer_target(const VKGL::RenderbufferTarget& in_target)
{
    vkgl_assert(in_target == VKGL::RenderbufferTarget::Renderbuffer);

    return GL_RENDERBUFFER;
}

GLenum VKGL::Utils::get_gl_enum_for_shader_property(const VKGL::ShaderProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case VKGL::ShaderProperty::Compile_Status:       result = GL_COMPILE_STATUS;       break;
        case VKGL::ShaderProperty::Delete_Status:        result = GL_DELETE_STATUS;        break;
        case VKGL::ShaderProperty::Info_Log_Length:      result = GL_INFO_LOG_LENGTH;      break;
        case VKGL::ShaderProperty::Shader_Source_Length: result = GL_SHADER_SOURCE_LENGTH; break;
        case VKGL::ShaderProperty::Shader_Type:          result = GL_SHADER_TYPE;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_shader_type(const VKGL::ShaderType& in_shader_type)
{
    GLenum result = 0;

    switch (in_shader_type)
    {
        case VKGL::ShaderType::Fragment: result = GL_FRAGMENT_SHADER; break;
        case VKGL::ShaderType::Geometry: result = GL_GEOMETRY_SHADER; break;
        case VKGL::ShaderType::Vertex:   result = GL_VERTEX_SHADER;   break;

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

GLenum VKGL::Utils::get_gl_enum_for_stencil_state_face(const VKGL::StencilStateFace& in_face)
{
    GLenum result = 0;

    switch (in_face)
    {
        case VKGL::StencilStateFace::Back:           result = GL_BACK;           break;
        case VKGL::StencilStateFace::Front:          result = GL_FRONT;          break;
        case VKGL::StencilStateFace::Front_And_Back: result = GL_FRONT_AND_BACK; break;

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

GLenum VKGL::Utils::get_gl_enum_for_texture_cube_map_face(const VKGL::TextureCubeMapFace& in_face)
{
    GLenum result = 0;

    switch (in_face)
    {
        case VKGL::TextureCubeMapFace::Negative_X: result = GL_TEXTURE_CUBE_MAP_NEGATIVE_X; break;
        case VKGL::TextureCubeMapFace::Negative_Y: result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y; break;
        case VKGL::TextureCubeMapFace::Negative_Z: result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z; break;
        case VKGL::TextureCubeMapFace::None:       result = GL_NONE;                        break;
        case VKGL::TextureCubeMapFace::Positive_X: result = GL_TEXTURE_CUBE_MAP_POSITIVE_X; break;
        case VKGL::TextureCubeMapFace::Positive_Y: result = GL_TEXTURE_CUBE_MAP_POSITIVE_Y; break;
        case VKGL::TextureCubeMapFace::Positive_Z: result = GL_TEXTURE_CUBE_MAP_POSITIVE_Z; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_texture_level_property(const VKGL::TextureLevelProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::TextureLevelProperty::Texture_Alpha_Size:            result = GL_TEXTURE_ALPHA_SIZE;            break;
        case VKGL::TextureLevelProperty::Texture_Blue_Size:             result = GL_TEXTURE_BLUE_SIZE;             break;
        case VKGL::TextureLevelProperty::Texture_Buffer_Offset:         result = GL_TEXTURE_BUFFER_OFFSET;         break;
        case VKGL::TextureLevelProperty::Texture_Compressed:            result = GL_TEXTURE_COMPRESSED;            break;
        case VKGL::TextureLevelProperty::Texture_Compressed_Image_Size: result = GL_TEXTURE_COMPRESSED_IMAGE_SIZE; break;
        case VKGL::TextureLevelProperty::Texture_Depth:                 result = GL_TEXTURE_DEPTH;                 break;
        case VKGL::TextureLevelProperty::Texture_Depth_Size:            result = GL_TEXTURE_DEPTH_SIZE;            break;
        case VKGL::TextureLevelProperty::Texture_Green_Size:            result = GL_TEXTURE_GREEN_SIZE;            break;
        case VKGL::TextureLevelProperty::Texture_Height:                result = GL_TEXTURE_HEIGHT;                break;
        case VKGL::TextureLevelProperty::Texture_Internal_Format:       result = GL_TEXTURE_INTERNAL_FORMAT;       break;
        case VKGL::TextureLevelProperty::Texture_Red_Size:              result = GL_TEXTURE_RED_SIZE;              break;
        case VKGL::TextureLevelProperty::Texture_Width:                 result = GL_TEXTURE_WIDTH;                 break;

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

GLenum VKGL::Utils::get_gl_enum_for_texture_property(const VKGL::TextureProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::TextureProperty::Depth_Stencil_Texture_Mode: result = GL_DEPTH_STENCIL_TEXTURE_MODE; break;
        case VKGL::TextureProperty::Texture_Base_Level:         result = GL_TEXTURE_BASE_LEVEL;         break;
        case VKGL::TextureProperty::Texture_Compare_Func:       result = GL_TEXTURE_COMPARE_FUNC;       break;
        case VKGL::TextureProperty::Texture_Compare_Mode:       result = GL_TEXTURE_COMPARE_MODE;       break;
        case VKGL::TextureProperty::Texture_Lod_Bias:           result = GL_TEXTURE_LOD_BIAS;           break;
        case VKGL::TextureProperty::Texture_Mag_Filter:         result = GL_TEXTURE_MAG_FILTER;         break;
        case VKGL::TextureProperty::Texture_Max_Level:          result = GL_TEXTURE_MAX_LEVEL;          break;
        case VKGL::TextureProperty::Texture_Max_Lod:            result = GL_TEXTURE_MAX_LOD;            break;
        case VKGL::TextureProperty::Texture_Min_Filter:         result = GL_TEXTURE_MIN_FILTER;         break;
        case VKGL::TextureProperty::Texture_Min_Lod:            result = GL_TEXTURE_MIN_LOD;            break;
        case VKGL::TextureProperty::Texture_Swizzle_A:          result = GL_TEXTURE_SWIZZLE_A;          break;
        case VKGL::TextureProperty::Texture_Swizzle_B:          result = GL_TEXTURE_SWIZZLE_B;          break;
        case VKGL::TextureProperty::Texture_Swizzle_G:          result = GL_TEXTURE_SWIZZLE_G;          break;
        case VKGL::TextureProperty::Texture_Swizzle_R:          result = GL_TEXTURE_SWIZZLE_R;          break;
        case VKGL::TextureProperty::Texture_Wrap_R:             result = GL_TEXTURE_WRAP_R;             break;
        case VKGL::TextureProperty::Texture_Wrap_S:             result = GL_TEXTURE_WRAP_S;             break;
        case VKGL::TextureProperty::Texture_Wrap_T:             result = GL_TEXTURE_WRAP_T;             break;

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

GLenum VKGL::Utils::get_gl_enum_for_transform_feedback_buffer_mode(const VKGL::TransformFeedbackBufferMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case VKGL::TransformFeedbackBufferMode::Interleaved_Attribs: result = GL_INTERLEAVED_ATTRIBS; break;
        case VKGL::TransformFeedbackBufferMode::Separate_Attribs:    result = GL_SEPARATE_ATTRIBS;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_transform_feedback_primitive_mode(const VKGL::TransformFeedbackPrimitiveMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case VKGL::TransformFeedbackPrimitiveMode::Lines:     result = GL_LINES;     break;
        case VKGL::TransformFeedbackPrimitiveMode::Points:    result = GL_POINTS;    break;
        case VKGL::TransformFeedbackPrimitiveMode::Triangles: result = GL_TRIANGLES; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_variable_type(const VariableType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::VariableType::Bool:                 result = GL_BOOL;                                      break;
        case VKGL::VariableType::Bvec2:                result = GL_BOOL_VEC2;                                 break;
        case VKGL::VariableType::Bvec3:                result = GL_BOOL_VEC3;                                 break;
        case VKGL::VariableType::Bvec4:                result = GL_BOOL_VEC4;                                 break;
        case VKGL::VariableType::Float:                result = GL_FLOAT;                                     break;
        case VKGL::VariableType::Int:                  result = GL_INT;                                       break;
        case VKGL::VariableType::Isampler1D:           result = GL_INT_SAMPLER_1D;                            break;
        case VKGL::VariableType::Isampler1DArray:      result = GL_INT_SAMPLER_1D_ARRAY;                      break;
        case VKGL::VariableType::Isampler2D:           result = GL_INT_SAMPLER_2D;                            break;
        case VKGL::VariableType::Isampler2DArray:      result = GL_INT_SAMPLER_2D_ARRAY;                      break;
        case VKGL::VariableType::Isampler2DMS:         result = GL_INT_SAMPLER_2D_MULTISAMPLE;                break;
        case VKGL::VariableType::Isampler2DMSArray:    result = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY;          break;
        case VKGL::VariableType::Isampler2DRect:       result = GL_INT_SAMPLER_2D_RECT;                       break;
        case VKGL::VariableType::Isampler3D:           result = GL_INT_SAMPLER_3D;                            break;
        case VKGL::VariableType::IsamplerBuffer:       result = GL_INT_SAMPLER_BUFFER;                        break;
        case VKGL::VariableType::IsamplerCube:         result = GL_INT_SAMPLER_CUBE;                          break;
        case VKGL::VariableType::Ivec2:                result = GL_INT_VEC2;                                  break;
        case VKGL::VariableType::Ivec3:                result = GL_INT_VEC3;                                  break;
        case VKGL::VariableType::Ivec4:                result = GL_INT_VEC4;                                  break;
        case VKGL::VariableType::Mat2:                 result = GL_FLOAT_MAT2;                                break;
        case VKGL::VariableType::Mat3:                 result = GL_FLOAT_MAT3;                                break;
        case VKGL::VariableType::Mat4:                 result = GL_FLOAT_MAT4;                                break;
        case VKGL::VariableType::Mat2x3:               result = GL_FLOAT_MAT2x3;                              break;
        case VKGL::VariableType::Mat2x4:               result = GL_FLOAT_MAT2x4;                              break;
        case VKGL::VariableType::Mat3x2:               result = GL_FLOAT_MAT3x2;                              break;
        case VKGL::VariableType::Mat3x4:               result = GL_FLOAT_MAT3x4;                              break;
        case VKGL::VariableType::Mat4x2:               result = GL_FLOAT_MAT4x2;                              break;
        case VKGL::VariableType::Mat4x3:               result = GL_FLOAT_MAT4x3;                              break;
        case VKGL::VariableType::Sampler1D:            result = GL_SAMPLER_1D;                                break;
        case VKGL::VariableType::Sampler1DArray:       result = GL_SAMPLER_1D_ARRAY;                          break;
        case VKGL::VariableType::Sampler1DArrayShadow: result = GL_SAMPLER_1D_ARRAY_SHADOW;                   break;
        case VKGL::VariableType::Sampler1DShadow:      result = GL_SAMPLER_1D_SHADOW;                         break;
        case VKGL::VariableType::Sampler2D:            result = GL_SAMPLER_2D;                                break;
        case VKGL::VariableType::Sampler2DArray:       result = GL_SAMPLER_2D_ARRAY;                          break;
        case VKGL::VariableType::Sampler2DArrayShadow: result = GL_SAMPLER_2D_ARRAY_SHADOW;                   break;
        case VKGL::VariableType::Sampler2DMS:          result = GL_SAMPLER_2D_MULTISAMPLE;                    break;
        case VKGL::VariableType::Sampler2DMSArray:     result = GL_SAMPLER_2D_MULTISAMPLE_ARRAY;              break;
        case VKGL::VariableType::Sampler2DRect:        result = GL_SAMPLER_2D_RECT;                           break;
        case VKGL::VariableType::Sampler2DRectShadow:  result = GL_SAMPLER_2D_RECT_SHADOW;                    break;
        case VKGL::VariableType::Sampler2DShadow:      result = GL_SAMPLER_2D_SHADOW;                         break;
        case VKGL::VariableType::Sampler3D:            result = GL_SAMPLER_3D;                                break;
        case VKGL::VariableType::SamplerBuffer:        result = GL_SAMPLER_BUFFER;                            break;
        case VKGL::VariableType::SamplerCube:          result = GL_SAMPLER_CUBE;                              break;
        case VKGL::VariableType::SamplerCubeShadow:    result = GL_SAMPLER_CUBE_SHADOW;                       break;
        case VKGL::VariableType::Uint:                 result = GL_UNSIGNED_INT;                              break;
        case VKGL::VariableType::Usampler1D:           result = GL_UNSIGNED_INT_SAMPLER_1D;                   break;
        case VKGL::VariableType::Usampler1DArray:      result = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY;             break;
        case VKGL::VariableType::Usampler2D:           result = GL_UNSIGNED_INT_SAMPLER_2D;                   break;
        case VKGL::VariableType::Usampler2DArray:      result = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY;             break;
        case VKGL::VariableType::Usampler2DMS:         result = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE;       break;
        case VKGL::VariableType::Usampler2DMSArray:    result = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY; break;
        case VKGL::VariableType::Usampler2DRect:       result = GL_UNSIGNED_INT_SAMPLER_2D_RECT;              break;
        case VKGL::VariableType::Usampler3D:           result = GL_UNSIGNED_INT_SAMPLER_3D;                   break;
        case VKGL::VariableType::UsamplerBuffer:       result = GL_UNSIGNED_INT_SAMPLER_BUFFER;               break;
        case VKGL::VariableType::UsamplerCube:         result = GL_UNSIGNED_INT_SAMPLER_CUBE;                 break;
        case VKGL::VariableType::Uvec2:                result = GL_UNSIGNED_INT_VEC2;                         break;
        case VKGL::VariableType::Uvec3:                result = GL_UNSIGNED_INT_VEC3;                         break;
        case VKGL::VariableType::Uvec4:                result = GL_UNSIGNED_INT_VEC4;                         break;
        case VKGL::VariableType::Vec2:                 result = GL_FLOAT_VEC2;                                break;
        case VKGL::VariableType::Vec3:                 result = GL_FLOAT_VEC3;                                break;
        case VKGL::VariableType::Vec4:                 result = GL_FLOAT_VEC4;                                break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_vertex_attribute_pointer_property(const VKGL::VertexAttributePointerProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case VKGL::VertexAttributePointerProperty::Vertex_Attribute_Array_Pointer: result = GL_VERTEX_ATTRIB_ARRAY_POINTER; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_vertex_attribute_array_type(const VKGL::VertexAttributeArrayType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case VKGL::VertexAttributeArrayType::Byte:           result = GL_BYTE;           break;
        case VKGL::VertexAttributeArrayType::Double:         result = GL_DOUBLE;         break;
        case VKGL::VertexAttributeArrayType::Float:          result = GL_FLOAT;          break;
        case VKGL::VertexAttributeArrayType::Int:            result = GL_INT;            break;
        case VKGL::VertexAttributeArrayType::Short:          result = GL_SHORT;          break;
        case VKGL::VertexAttributeArrayType::Unsigned_Byte:  result = GL_UNSIGNED_BYTE;  break;
        case VKGL::VertexAttributeArrayType::Unsigned_Int:   result = GL_UNSIGNED_INT;   break;
        case VKGL::VertexAttributeArrayType::Unsigned_Short: result = GL_UNSIGNED_SHORT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum VKGL::Utils::get_gl_enum_for_vertex_attribute_property(const VKGL::VertexAttributeProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case VKGL::VertexAttributeProperty::Array_Size:               result = GL_VERTEX_ATTRIB_ARRAY_SIZE;           break;
        case VKGL::VertexAttributeProperty::Array_Type:               result = GL_VERTEX_ATTRIB_ARRAY_TYPE;           break;
        case VKGL::VertexAttributeProperty::Buffer_Binding:           result = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING; break;
        case VKGL::VertexAttributeProperty::Current_Vertex_Attribute: result = GL_CURRENT_VERTEX_ATTRIB;              break;
        case VKGL::VertexAttributeProperty::Divisor:                  result = GL_VERTEX_ATTRIB_ARRAY_DIVISOR;        break;
        case VKGL::VertexAttributeProperty::Enabled:                  result = GL_VERTEX_ATTRIB_ARRAY_ENABLED;        break;
        case VKGL::VertexAttributeProperty::Integer:                  result = GL_VERTEX_ATTRIB_ARRAY_INTEGER;        break;
        case VKGL::VertexAttributeProperty::Normalized:               result = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED;     break;
        case VKGL::VertexAttributeProperty::Stride:                   result = GL_VERTEX_ATTRIB_ARRAY_STRIDE;         break;

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

VKGL::HintTarget VKGL::Utils::get_hint_target_for_gl_enum(const GLenum& in_enum)
{
    VKGL::HintTarget result = VKGL::HintTarget::Unknown;

    switch (in_enum)
    {
        case GL_FRAGMENT_SHADER_DERIVATIVE_HINT: result = VKGL::HintTarget::Fragment_Shader_Derivative; break;
        case GL_LINE_SMOOTH_HINT:                result = VKGL::HintTarget::Line_Smooth;                break;
        case GL_POLYGON_SMOOTH_HINT:             result = VKGL::HintTarget::Polygon_Smooth;             break;
        case GL_TEXTURE_COMPRESSION_HINT:        result = VKGL::HintTarget::Texture_Compression;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
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

VKGL::MipmapGenerationTextureTarget VKGL::Utils::get_mipmap_generation_texture_target_for_gl_enum(const GLenum& in_enum)
{
    VKGL::MipmapGenerationTextureTarget result = VKGL::MipmapGenerationTextureTarget::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_1D:       result = VKGL::MipmapGenerationTextureTarget::Texture_1D;       break;
        case GL_TEXTURE_1D_ARRAY: result = VKGL::MipmapGenerationTextureTarget::Texture_1D_Array; break;
        case GL_TEXTURE_2D:       result = VKGL::MipmapGenerationTextureTarget::Texture_2D;       break;
        case GL_TEXTURE_2D_ARRAY: result = VKGL::MipmapGenerationTextureTarget::Texture_2D_Array; break;
        case GL_TEXTURE_3D:       result = VKGL::MipmapGenerationTextureTarget::Texture_3D;       break;
        case GL_TEXTURE_CUBE_MAP: result = VKGL::MipmapGenerationTextureTarget::Texture_Cube_Map; break;

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

VKGL::PixelStoreProperty VKGL::Utils::get_pixel_store_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::PixelStoreProperty result = VKGL::PixelStoreProperty::Unknown;

    switch (in_enum)
    {
        case GL_PACK_ALIGNMENT:      result = VKGL::PixelStoreProperty::Pack_Alignment;      break;
        case GL_PACK_IMAGE_HEIGHT:   result = VKGL::PixelStoreProperty::Pack_Image_Height;   break;
        case GL_PACK_LSB_FIRST:      result = VKGL::PixelStoreProperty::Pack_LSB_First;      break;
        case GL_PACK_ROW_LENGTH:     result = VKGL::PixelStoreProperty::Pack_Row_Length;     break;
        case GL_PACK_SKIP_IMAGES:    result = VKGL::PixelStoreProperty::Pack_Skip_Images;    break;
        case GL_PACK_SKIP_PIXELS:    result = VKGL::PixelStoreProperty::Pack_Skip_Pixels;    break;
        case GL_PACK_SKIP_ROWS:      result = VKGL::PixelStoreProperty::Pack_Skip_Rows;      break;
        case GL_PACK_SWAP_BYTES:     result = VKGL::PixelStoreProperty::Pack_Swap_Bytes;     break;
        case GL_UNPACK_ALIGNMENT:    result = VKGL::PixelStoreProperty::Unpack_Alignment;    break;
        case GL_UNPACK_IMAGE_HEIGHT: result = VKGL::PixelStoreProperty::Unpack_Image_Height; break;
        case GL_UNPACK_LSB_FIRST:    result = VKGL::PixelStoreProperty::Unpack_LSB_First;    break;
        case GL_UNPACK_ROW_LENGTH:   result = VKGL::PixelStoreProperty::Unpack_Row_Length;   break;
        case GL_UNPACK_SKIP_IMAGES:  result = VKGL::PixelStoreProperty::Unpack_Skip_Images;  break;
        case GL_UNPACK_SKIP_PIXELS:  result = VKGL::PixelStoreProperty::Unpack_Skip_Pixels;  break;
        case GL_UNPACK_SKIP_ROWS:    result = VKGL::PixelStoreProperty::Unpack_Skip_Rows;    break;
        case GL_UNPACK_SWAP_BYTES:   result = VKGL::PixelStoreProperty::Unpack_Swap_Bytes;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::PixelStoreProperty VKGL::Utils::get_pixel_store_property_from_context_property(const VKGL::ContextProperty& in_context_property)
{
    VKGL::PixelStoreProperty result = VKGL::PixelStoreProperty::Unknown;

    switch (in_context_property)
    {
        case VKGL::ContextProperty::Pack_Alignment:      result = VKGL::PixelStoreProperty::Pack_Alignment;      break;
        case VKGL::ContextProperty::Pack_Image_Height:   result = VKGL::PixelStoreProperty::Pack_Image_Height;   break;
        case VKGL::ContextProperty::Pack_LSB_First:      result = VKGL::PixelStoreProperty::Pack_LSB_First;      break;
        case VKGL::ContextProperty::Pack_Row_Length:     result = VKGL::PixelStoreProperty::Pack_Row_Length;     break;
        case VKGL::ContextProperty::Pack_Skip_Images:    result = VKGL::PixelStoreProperty::Pack_Skip_Images;    break;
        case VKGL::ContextProperty::Pack_Skip_Pixels:    result = VKGL::PixelStoreProperty::Pack_Skip_Pixels;    break;
        case VKGL::ContextProperty::Pack_Skip_Rows:      result = VKGL::PixelStoreProperty::Pack_Skip_Rows;      break;
        case VKGL::ContextProperty::Pack_Swap_Bytes:     result = VKGL::PixelStoreProperty::Pack_Swap_Bytes;     break;
        case VKGL::ContextProperty::Unpack_Alignment:    result = VKGL::PixelStoreProperty::Unpack_Alignment;    break;
        case VKGL::ContextProperty::Unpack_Image_Height: result = VKGL::PixelStoreProperty::Unpack_Image_Height; break;
        case VKGL::ContextProperty::Unpack_LSB_First:    result = VKGL::PixelStoreProperty::Unpack_LSB_First;    break;
        case VKGL::ContextProperty::Unpack_Row_Length:   result = VKGL::PixelStoreProperty::Unpack_Row_Length;   break;
        case VKGL::ContextProperty::Unpack_Skip_Images:  result = VKGL::PixelStoreProperty::Unpack_Skip_Images;  break;
        case VKGL::ContextProperty::Unpack_Skip_Pixels:  result = VKGL::PixelStoreProperty::Unpack_Skip_Pixels;  break;
        case VKGL::ContextProperty::Unpack_Skip_Rows:    result = VKGL::PixelStoreProperty::Unpack_Skip_Rows;    break;
        case VKGL::ContextProperty::Unpack_Swap_Bytes:   result = VKGL::PixelStoreProperty::Unpack_Swap_Bytes;   break;
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

VKGL::PointProperty VKGL::Utils::get_point_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::PointProperty result = VKGL::PointProperty::Unknown;

    switch (in_enum)
    {
        case GL_POINT_FADE_THRESHOLD_SIZE: result = VKGL::PointProperty::Fade_Threshold_Size; break;
        case GL_POINT_SPRITE_COORD_ORIGIN: result = VKGL::PointProperty::Sprite_Coord_Origin; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::PointSpriteCoordOrigin VKGL::Utils::get_point_sprite_coord_origin_for_gl_enum(const GLenum& in_enum)
{
    VKGL::PointSpriteCoordOrigin result = VKGL::PointSpriteCoordOrigin::Unknown;

    switch (in_enum)
    {
        case GL_LOWER_LEFT: result = VKGL::PointSpriteCoordOrigin::Lower_Left; break;
        case GL_UPPER_LEFT: result = VKGL::PointSpriteCoordOrigin::Upper_Left; break;

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

VKGL::ProgramProperty VKGL::Utils::get_program_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ProgramProperty result = VKGL::ProgramProperty::Unknown;

    switch (in_enum)
    {
        case GL_ACTIVE_ATTRIBUTES:                     result = VKGL::ProgramProperty::Active_Attributes;                     break;
        case GL_ACTIVE_ATTRIBUTE_MAX_LENGTH:           result = VKGL::ProgramProperty::Active_Attribute_Max_Length;           break;
        case GL_ACTIVE_UNIFORMS:                       result = VKGL::ProgramProperty::Active_Uniforms;                       break;
        case GL_ACTIVE_UNIFORM_BLOCKS:                 result = VKGL::ProgramProperty::Active_Uniform_Blocks;                 break;
        case GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH:  result = VKGL::ProgramProperty::Active_Uniform_Block_Max_Name_Length;  break;
        case GL_ACTIVE_UNIFORM_MAX_LENGTH:             result = VKGL::ProgramProperty::Active_Uniform_Max_Length;             break;
        case GL_ATTACHED_SHADERS:                      result = VKGL::ProgramProperty::Attached_Shaders;                      break;
        case GL_DELETE_STATUS:                         result = VKGL::ProgramProperty::Delete_Status;                         break;
        case GL_GEOMETRY_INPUT_TYPE:                   result = VKGL::ProgramProperty::Geometry_Input_Type;                   break;
        case GL_GEOMETRY_OUTPUT_TYPE:                  result = VKGL::ProgramProperty::Geometry_Output_Type;                  break;
        case GL_GEOMETRY_VERTICES_OUT:                 result = VKGL::ProgramProperty::Geometry_Vertices_Out;                 break;
        case GL_INFO_LOG_LENGTH:                       result = VKGL::ProgramProperty::Info_Log_Length;                       break;
        case GL_LINK_STATUS:                           result = VKGL::ProgramProperty::Link_Status;                           break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_MODE:        result = VKGL::ProgramProperty::Transform_Feedback_Buffer_Mode;        break;
        case GL_TRANSFORM_FEEDBACK_VARYINGS:           result = VKGL::ProgramProperty::Transform_Feedback_Varyings;           break;
        case GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH: result = VKGL::ProgramProperty::Transform_Feedback_Varying_Max_Length; break;
        case GL_VALIDATE_STATUS:                       result = VKGL::ProgramProperty::Validate_Status;                       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ProvokingVertexConvention VKGL::Utils::get_provoking_vertex_convention_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ProvokingVertexConvention result = VKGL::ProvokingVertexConvention::Unknown;

    switch (in_enum)
    {
        case GL_FIRST_VERTEX_CONVENTION: result = VKGL::ProvokingVertexConvention::First; break;
        case GL_LAST_VERTEX_CONVENTION:  result = VKGL::ProvokingVertexConvention::Last;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::QueryProperty VKGL::Utils::get_query_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::QueryProperty result = VKGL::QueryProperty::Unknown;

    switch (in_enum)
    {
        case GL_QUERY_RESULT:           result = VKGL::QueryProperty::Query_Result;           break;
        case GL_QUERY_RESULT_AVAILABLE: result = VKGL::QueryProperty::Query_Result_Available; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::QueryTarget VKGL::Utils::get_query_target_for_gl_enum(const GLenum& in_enum)
{
    VKGL::QueryTarget result = VKGL::QueryTarget::Unknown;

    switch (in_enum)
    {
        case GL_PRIMITIVES_GENERATED:                  result = VKGL::QueryTarget::Primitives_Generated;                  break;
        case GL_SAMPLES_PASSED:                        result = VKGL::QueryTarget::Samples_Passed;                        break;
        case GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN: result = VKGL::QueryTarget::Transform_Feedback_Primitives_Written; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::QueryTargetProperty VKGL::Utils::get_query_target_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::QueryTargetProperty result = VKGL::QueryTargetProperty::Unknown;

    switch (in_enum)
    {
        case GL_CURRENT_QUERY:      result = VKGL::QueryTargetProperty::Current_Query;      break;
        case GL_QUERY_COUNTER_BITS: result = VKGL::QueryTargetProperty::Query_Counter_Bits; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ReadBuffer VKGL::Utils::get_read_buffer_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ReadBuffer result = VKGL::ReadBuffer::Unknown;

    switch (in_enum)
    {
        case GL_BACK:              result = VKGL::ReadBuffer::Back;              break;
        case GL_BACK_LEFT:         result = VKGL::ReadBuffer::Back_Left;         break;
        case GL_BACK_RIGHT:        result = VKGL::ReadBuffer::Back_Right;        break;
        case GL_COLOR_ATTACHMENT0: result = VKGL::ReadBuffer::Color_Attachment0; break;
        case GL_COLOR_ATTACHMENT1: result = VKGL::ReadBuffer::Color_Attachment1; break;
        case GL_COLOR_ATTACHMENT2: result = VKGL::ReadBuffer::Color_Attachment2; break;
        case GL_COLOR_ATTACHMENT3: result = VKGL::ReadBuffer::Color_Attachment3; break;
        case GL_COLOR_ATTACHMENT4: result = VKGL::ReadBuffer::Color_Attachment4; break;
        case GL_COLOR_ATTACHMENT5: result = VKGL::ReadBuffer::Color_Attachment5; break;
        case GL_COLOR_ATTACHMENT6: result = VKGL::ReadBuffer::Color_Attachment6; break;
        case GL_COLOR_ATTACHMENT7: result = VKGL::ReadBuffer::Color_Attachment7; break;
        case GL_FRONT:             result = VKGL::ReadBuffer::Front;             break;
        case GL_FRONT_AND_BACK:    result = VKGL::ReadBuffer::Front_And_Back;    break;
        case GL_FRONT_LEFT:        result = VKGL::ReadBuffer::Front_Left;        break;
        case GL_FRONT_RIGHT:       result = VKGL::ReadBuffer::Front_Right;       break;
        case GL_LEFT:              result = VKGL::ReadBuffer::Left;              break;
        case GL_RIGHT:             result = VKGL::ReadBuffer::Right;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::RenderbufferProperty VKGL::Utils::get_renderbuffer_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::RenderbufferProperty result = VKGL::RenderbufferProperty::Unknown;

    switch (in_enum)
    {
        case GL_RENDERBUFFER_ALPHA_SIZE:      result = VKGL::RenderbufferProperty::Alpha_Size;      break;
        case GL_RENDERBUFFER_BLUE_SIZE:       result = VKGL::RenderbufferProperty::Blue_Size;       break;
        case GL_RENDERBUFFER_DEPTH_SIZE:      result = VKGL::RenderbufferProperty::Depth_Size;      break;
        case GL_RENDERBUFFER_GREEN_SIZE:      result = VKGL::RenderbufferProperty::Green_Size;      break;
        case GL_RENDERBUFFER_HEIGHT:          result = VKGL::RenderbufferProperty::Height;          break;
        case GL_RENDERBUFFER_INTERNAL_FORMAT: result = VKGL::RenderbufferProperty::Internal_Format; break;
        case GL_RENDERBUFFER_RED_SIZE:        result = VKGL::RenderbufferProperty::Red_Size;        break;
        case GL_RENDERBUFFER_SAMPLES:         result = VKGL::RenderbufferProperty::Samples;         break;
        case GL_RENDERBUFFER_STENCIL_SIZE:    result = VKGL::RenderbufferProperty::Stencil_Size;    break;
        case GL_RENDERBUFFER_WIDTH:           result = VKGL::RenderbufferProperty::Width;           break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::RenderbufferTarget VKGL::Utils::get_renderbuffer_target_for_gl_enum(const GLenum& in_enum)
{
    vkgl_assert(in_enum == GL_RENDERBUFFER);

    return VKGL::RenderbufferTarget::Renderbuffer;
}

VKGL::ShaderProperty VKGL::Utils::get_shader_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ShaderProperty result = VKGL::ShaderProperty::Unknown;

    switch (in_enum)
    {
        case GL_COMPILE_STATUS:       result = VKGL::ShaderProperty::Compile_Status;       break;
        case GL_DELETE_STATUS:        result = VKGL::ShaderProperty::Delete_Status;        break;
        case GL_INFO_LOG_LENGTH:      result = VKGL::ShaderProperty::Info_Log_Length;      break;
        case GL_SHADER_SOURCE_LENGTH: result = VKGL::ShaderProperty::Shader_Source_Length; break;
        case GL_SHADER_TYPE:          result = VKGL::ShaderProperty::Shader_Type;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::ShaderType VKGL::Utils::get_shader_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::ShaderType result = VKGL::ShaderType::Unknown;

    switch (in_enum)
    {
        case GL_FRAGMENT_SHADER: result = VKGL::ShaderType::Fragment; break;
        case GL_GEOMETRY_SHADER: result = VKGL::ShaderType::Geometry; break;
        case GL_VERTEX_SHADER:   result = VKGL::ShaderType::Vertex;   break;

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

VKGL::StencilStateFace VKGL::Utils::get_stencil_state_face_for_gl_enum(const GLenum& in_enum)
{
    VKGL::StencilStateFace result = VKGL::StencilStateFace::Unknown;

    switch (in_enum)
    {
        case GL_BACK:           result = VKGL::StencilStateFace::Back;           break;
        case GL_FRONT:          result = VKGL::StencilStateFace::Front;          break;
        case GL_FRONT_AND_BACK: result = VKGL::StencilStateFace::Front_And_Back; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureBindingProperty VKGL::Utils::get_texture_binding_property_for_context_property(const VKGL::ContextProperty& in_pname)
{
    VKGL::TextureBindingProperty result = VKGL::TextureBindingProperty::Unknown;

    switch (in_pname)
    {
        case VKGL::ContextProperty::Texture_Binding_1D:                   result = VKGL::TextureBindingProperty::_1D;                   break;
        case VKGL::ContextProperty::Texture_Binding_1D_Array:             result = VKGL::TextureBindingProperty::_1D_Array;             break;
        case VKGL::ContextProperty::Texture_Binding_2D:                   result = VKGL::TextureBindingProperty::_2D;                   break;
        case VKGL::ContextProperty::Texture_Binding_2D_Array:             result = VKGL::TextureBindingProperty::_2D_Array;             break;
        case VKGL::ContextProperty::Texture_Binding_2D_Multisample:       result = VKGL::TextureBindingProperty::_2D_Multisample;       break;
        case VKGL::ContextProperty::Texture_Binding_2D_Multisample_Array: result = VKGL::TextureBindingProperty::_2D_Multisample_Array; break;
        case VKGL::ContextProperty::Texture_Binding_3D:                   result = VKGL::TextureBindingProperty::_3D;                   break;
        case VKGL::ContextProperty::Texture_Binding_Buffer:               result = VKGL::TextureBindingProperty::Buffer;                break;
        case VKGL::ContextProperty::Texture_Binding_Cube_Map:             result = VKGL::TextureBindingProperty::Cube_Map;              break;
        case VKGL::ContextProperty::Texture_Binding_Rectangle:            result = VKGL::TextureBindingProperty::Rectangle;             break;
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

VKGL::TextureCubeMapFace VKGL::Utils::get_texture_cube_map_face_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureCubeMapFace result = VKGL::TextureCubeMapFace::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X: result = VKGL::TextureCubeMapFace::Negative_X; break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y: result = VKGL::TextureCubeMapFace::Negative_Y; break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z: result = VKGL::TextureCubeMapFace::Negative_Z; break;
        case GL_NONE:                        result = VKGL::TextureCubeMapFace::None;       break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X: result = VKGL::TextureCubeMapFace::Positive_X; break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y: result = VKGL::TextureCubeMapFace::Positive_Y; break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z: result = VKGL::TextureCubeMapFace::Positive_Z; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TextureLevelProperty VKGL::Utils::get_texture_level_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureLevelProperty result = VKGL::TextureLevelProperty::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_ALPHA_SIZE:            result = VKGL::TextureLevelProperty::Texture_Alpha_Size;            break;
        case GL_TEXTURE_BLUE_SIZE:             result = VKGL::TextureLevelProperty::Texture_Blue_Size;             break;
        case GL_TEXTURE_BUFFER_OFFSET:         result = VKGL::TextureLevelProperty::Texture_Buffer_Offset;         break;
        case GL_TEXTURE_COMPRESSED:            result = VKGL::TextureLevelProperty::Texture_Compressed;            break;
        case GL_TEXTURE_COMPRESSED_IMAGE_SIZE: result = VKGL::TextureLevelProperty::Texture_Compressed_Image_Size; break;
        case GL_TEXTURE_DEPTH:                 result = VKGL::TextureLevelProperty::Texture_Depth;                 break;
        case GL_TEXTURE_DEPTH_SIZE:            result = VKGL::TextureLevelProperty::Texture_Depth_Size;            break;
        case GL_TEXTURE_GREEN_SIZE:            result = VKGL::TextureLevelProperty::Texture_Green_Size;            break;
        case GL_TEXTURE_HEIGHT:                result = VKGL::TextureLevelProperty::Texture_Height;                break;
        case GL_TEXTURE_INTERNAL_FORMAT:       result = VKGL::TextureLevelProperty::Texture_Internal_Format;       break;
        case GL_TEXTURE_RED_SIZE:              result = VKGL::TextureLevelProperty::Texture_Red_Size;              break;
        case GL_TEXTURE_WIDTH:                 result = VKGL::TextureLevelProperty::Texture_Width;                 break;

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

VKGL::TextureProperty VKGL::Utils::get_texture_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TextureProperty result = VKGL::TextureProperty::Unknown;

    switch (in_enum)
    {
        case GL_DEPTH_STENCIL_TEXTURE_MODE: result = VKGL::TextureProperty::Depth_Stencil_Texture_Mode; break;
        case GL_TEXTURE_BASE_LEVEL:         result = VKGL::TextureProperty::Texture_Base_Level;         break;
        case GL_TEXTURE_COMPARE_FUNC:       result = VKGL::TextureProperty::Texture_Compare_Func;       break;
        case GL_TEXTURE_COMPARE_MODE:       result = VKGL::TextureProperty::Texture_Compare_Mode;       break;
        case GL_TEXTURE_LOD_BIAS:           result = VKGL::TextureProperty::Texture_Lod_Bias;           break;
        case GL_TEXTURE_MAG_FILTER:         result = VKGL::TextureProperty::Texture_Mag_Filter;         break;
        case GL_TEXTURE_MAX_LEVEL:          result = VKGL::TextureProperty::Texture_Max_Level;          break;
        case GL_TEXTURE_MAX_LOD:            result = VKGL::TextureProperty::Texture_Max_Lod;            break;
        case GL_TEXTURE_MIN_FILTER:         result = VKGL::TextureProperty::Texture_Min_Filter;         break;
        case GL_TEXTURE_MIN_LOD:            result = VKGL::TextureProperty::Texture_Min_Lod;            break;
        case GL_TEXTURE_SWIZZLE_A:          result = VKGL::TextureProperty::Texture_Swizzle_A;          break;
        case GL_TEXTURE_SWIZZLE_B:          result = VKGL::TextureProperty::Texture_Swizzle_B;          break;
        case GL_TEXTURE_SWIZZLE_G:          result = VKGL::TextureProperty::Texture_Swizzle_G;          break;
        case GL_TEXTURE_SWIZZLE_R:          result = VKGL::TextureProperty::Texture_Swizzle_R;          break;
        case GL_TEXTURE_WRAP_R:             result = VKGL::TextureProperty::Texture_Wrap_R;             break;
        case GL_TEXTURE_WRAP_S:             result = VKGL::TextureProperty::Texture_Wrap_S;             break;
        case GL_TEXTURE_WRAP_T:             result = VKGL::TextureProperty::Texture_Wrap_T;             break;

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
        case GL_TEXTURE_CUBE_MAP:                   result = VKGL::TextureTarget::Cube_Map;                           break;
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

VKGL::VariableType get_variable_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::VariableType result = VKGL::VariableType::Unknown;

    switch (in_enum)
    {
        case GL_BOOL:                                      result = VKGL::VariableType::Bool;                 break;
        case GL_BOOL_VEC2:                                 result = VKGL::VariableType::Bvec2;                break;
        case GL_BOOL_VEC3:                                 result = VKGL::VariableType::Bvec3;                break;
        case GL_BOOL_VEC4:                                 result = VKGL::VariableType::Bvec4;                break;
        case GL_FLOAT:                                     result = VKGL::VariableType::Float;                break;
        case GL_FLOAT_MAT2:                                result = VKGL::VariableType::Mat2;                 break;
        case GL_FLOAT_MAT3:                                result = VKGL::VariableType::Mat3;                 break;
        case GL_FLOAT_MAT4:                                result = VKGL::VariableType::Mat4;                 break;
        case GL_FLOAT_MAT2x3:                              result = VKGL::VariableType::Mat2x3;               break;
        case GL_FLOAT_MAT2x4:                              result = VKGL::VariableType::Mat2x4;               break;
        case GL_FLOAT_MAT3x2:                              result = VKGL::VariableType::Mat3x2;               break;
        case GL_FLOAT_MAT3x4:                              result = VKGL::VariableType::Mat3x4;               break;
        case GL_FLOAT_MAT4x2:                              result = VKGL::VariableType::Mat4x2;               break;
        case GL_FLOAT_MAT4x3:                              result = VKGL::VariableType::Mat4x3;               break;
        case GL_FLOAT_VEC2:                                result = VKGL::VariableType::Vec2;                 break;
        case GL_FLOAT_VEC3:                                result = VKGL::VariableType::Vec3;                 break;
        case GL_FLOAT_VEC4:                                result = VKGL::VariableType::Vec4;                 break;
        case GL_INT:                                       result = VKGL::VariableType::Int;                  break;
        case GL_INT_SAMPLER_1D:                            result = VKGL::VariableType::Isampler1D;           break;
        case GL_INT_SAMPLER_1D_ARRAY:                      result = VKGL::VariableType::Isampler1DArray;      break;
        case GL_INT_SAMPLER_2D:                            result = VKGL::VariableType::Isampler2D;           break;
        case GL_INT_SAMPLER_2D_ARRAY:                      result = VKGL::VariableType::Isampler2DArray;      break;
        case GL_INT_SAMPLER_2D_MULTISAMPLE:                result = VKGL::VariableType::Isampler2DMS;         break;
        case GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:          result = VKGL::VariableType::Isampler2DMSArray;    break;
        case GL_INT_SAMPLER_2D_RECT:                       result = VKGL::VariableType::Isampler2DRect;       break;
        case GL_INT_SAMPLER_3D:                            result = VKGL::VariableType::Isampler3D;           break;
        case GL_INT_SAMPLER_BUFFER:                        result = VKGL::VariableType::IsamplerBuffer;       break;
        case GL_INT_SAMPLER_CUBE:                          result = VKGL::VariableType::IsamplerCube;         break;
        case GL_INT_VEC2:                                  result = VKGL::VariableType::Ivec2;                break;
        case GL_INT_VEC3:                                  result = VKGL::VariableType::Ivec3;                break;
        case GL_INT_VEC4:                                  result = VKGL::VariableType::Ivec4;                break;
        case GL_SAMPLER_1D:                                result = VKGL::VariableType::Sampler1D;            break;
        case GL_SAMPLER_1D_ARRAY:                          result = VKGL::VariableType::Sampler1DArray;       break;
        case GL_SAMPLER_1D_ARRAY_SHADOW:                   result = VKGL::VariableType::Sampler1DArrayShadow; break;
        case GL_SAMPLER_1D_SHADOW:                         result = VKGL::VariableType::Sampler1DShadow;      break;
        case GL_SAMPLER_2D:                                result = VKGL::VariableType::Sampler2D;            break;
        case GL_SAMPLER_2D_ARRAY:                          result = VKGL::VariableType::Sampler2DArray;       break;
        case GL_SAMPLER_2D_ARRAY_SHADOW:                   result = VKGL::VariableType::Sampler2DArrayShadow; break;
        case GL_SAMPLER_2D_MULTISAMPLE:                    result = VKGL::VariableType::Sampler2DMS;          break;
        case GL_SAMPLER_2D_MULTISAMPLE_ARRAY:              result = VKGL::VariableType::Sampler2DMSArray;     break;
        case GL_SAMPLER_2D_RECT:                           result = VKGL::VariableType::Sampler2DRect;        break;
        case GL_SAMPLER_2D_RECT_SHADOW:                    result = VKGL::VariableType::Sampler2DRectShadow;  break;
        case GL_SAMPLER_2D_SHADOW:                         result = VKGL::VariableType::Sampler2DShadow;      break;
        case GL_SAMPLER_3D:                                result = VKGL::VariableType::Sampler3D;            break;
        case GL_SAMPLER_BUFFER:                            result = VKGL::VariableType::SamplerBuffer;        break;
        case GL_SAMPLER_CUBE:                              result = VKGL::VariableType::SamplerCube;          break;
        case GL_SAMPLER_CUBE_SHADOW:                       result = VKGL::VariableType::SamplerCubeShadow;    break;
        case GL_UNSIGNED_INT:                              result = VKGL::VariableType::Uint;                 break;
        case GL_UNSIGNED_INT_SAMPLER_1D:                   result = VKGL::VariableType::Usampler1D;           break;
        case GL_UNSIGNED_INT_SAMPLER_1D_ARRAY:             result = VKGL::VariableType::Usampler1DArray;      break;
        case GL_UNSIGNED_INT_SAMPLER_2D:                   result = VKGL::VariableType::Usampler2D;           break;
        case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY:             result = VKGL::VariableType::Usampler2DArray;      break;
        case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE:       result = VKGL::VariableType::Usampler2DMS;         break;
        case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY: result = VKGL::VariableType::Usampler2DMSArray;    break;
        case GL_UNSIGNED_INT_SAMPLER_2D_RECT:              result = VKGL::VariableType::Usampler2DRect;       break;
        case GL_UNSIGNED_INT_SAMPLER_3D:                   result = VKGL::VariableType::Usampler3D;           break;
        case GL_UNSIGNED_INT_SAMPLER_BUFFER:               result = VKGL::VariableType::UsamplerBuffer;       break;
        case GL_UNSIGNED_INT_SAMPLER_CUBE:                 result = VKGL::VariableType::UsamplerCube;         break;
        case GL_UNSIGNED_INT_VEC2:                         result = VKGL::VariableType::Uvec2;                break;
        case GL_UNSIGNED_INT_VEC3:                         result = VKGL::VariableType::Uvec3;                break;
        case GL_UNSIGNED_INT_VEC4:                         result = VKGL::VariableType::Uvec4;                break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TransformFeedbackBufferMode VKGL::Utils::get_transform_feedback_buffer_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TransformFeedbackBufferMode result = VKGL::TransformFeedbackBufferMode::Unknown;

    switch (in_enum)
    {
        case GL_INTERLEAVED_ATTRIBS: result = VKGL::TransformFeedbackBufferMode::Interleaved_Attribs; break;
        case GL_SEPARATE_ATTRIBS:    result = VKGL::TransformFeedbackBufferMode::Separate_Attribs;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::TransformFeedbackPrimitiveMode VKGL::Utils::get_transform_feedback_primitive_mode_for_gl_enum(const GLenum& in_enum)
{
    VKGL::TransformFeedbackPrimitiveMode result = VKGL::TransformFeedbackPrimitiveMode::Unknown;

    switch (in_enum)
    {
        case GL_LINES:     result = VKGL::TransformFeedbackPrimitiveMode::Lines;     break;
        case GL_POINTS:    result = VKGL::TransformFeedbackPrimitiveMode::Points;    break;
        case GL_TRIANGLES: result = VKGL::TransformFeedbackPrimitiveMode::Triangles; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::VertexAttributePointerProperty VKGL::Utils::get_vertex_attribute_pointer_property_for_gl_enum(const GLenum& in_enum)
{
    VKGL::VertexAttributePointerProperty result = VKGL::VertexAttributePointerProperty::Unknown;

    switch (in_enum)
    {
        case GL_VERTEX_ATTRIB_ARRAY_POINTER: result = VKGL::VertexAttributePointerProperty::Vertex_Attribute_Array_Pointer; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::VertexAttributeArrayType VKGL::Utils::get_vertex_attribute_array_type_for_gl_enum(const GLenum& in_enum)
{
    VKGL::VertexAttributeArrayType result = VKGL::VertexAttributeArrayType::Unknown;

    switch (in_enum)
    {
        case GL_BYTE:           result = VKGL::VertexAttributeArrayType::Byte;           break;
        case GL_DOUBLE:         result = VKGL::VertexAttributeArrayType::Double;         break;
        case GL_FLOAT:          result = VKGL::VertexAttributeArrayType::Float;          break;
        case GL_INT:            result = VKGL::VertexAttributeArrayType::Int;            break;
        case GL_SHORT:          result = VKGL::VertexAttributeArrayType::Short;          break;
        case GL_UNSIGNED_BYTE:  result = VKGL::VertexAttributeArrayType::Unsigned_Byte;  break;
        case GL_UNSIGNED_INT:   result = VKGL::VertexAttributeArrayType::Unsigned_Int;   break;
        case GL_UNSIGNED_SHORT: result = VKGL::VertexAttributeArrayType::Unsigned_Short; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

VKGL::VertexAttributeProperty VKGL::Utils::get_vertex_attribute_property_for_gl_enum(const GLenum& in_pname)
{
    VKGL::VertexAttributeProperty result = VKGL::VertexAttributeProperty::Unknown;

    switch (in_pname)
    {
        case GL_VERTEX_ATTRIB_ARRAY_SIZE:           result = VKGL::VertexAttributeProperty::Array_Size;               break;
        case GL_VERTEX_ATTRIB_ARRAY_TYPE:           result = VKGL::VertexAttributeProperty::Array_Type;               break;
        case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: result = VKGL::VertexAttributeProperty::Buffer_Binding;           break;
        case GL_CURRENT_VERTEX_ATTRIB:              result = VKGL::VertexAttributeProperty::Current_Vertex_Attribute; break;
        case GL_VERTEX_ATTRIB_ARRAY_DIVISOR:        result = VKGL::VertexAttributeProperty::Divisor;                  break;
        case GL_VERTEX_ATTRIB_ARRAY_ENABLED:        result = VKGL::VertexAttributeProperty::Enabled;                  break;
        case GL_VERTEX_ATTRIB_ARRAY_INTEGER:        result = VKGL::VertexAttributeProperty::Integer;                  break;
        case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED:     result = VKGL::VertexAttributeProperty::Normalized;               break;
        case GL_VERTEX_ATTRIB_ARRAY_STRIDE:         result = VKGL::VertexAttributeProperty::Stride;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

bool VKGL::Utils::is_context_property_gl_limit(const VKGL::ContextProperty& in_pname)
{
    bool result = false;

    switch (in_pname)
    {
        case VKGL::ContextProperty::Aliased_Line_Width_Range:
        case VKGL::ContextProperty::Compressed_Texture_Formats:
        case VKGL::ContextProperty::Major_Version:
        case VKGL::ContextProperty::Max_3D_Texture_Size:
        case VKGL::ContextProperty::Max_Array_Texture_Layers:
        case VKGL::ContextProperty::Max_Clip_Distances:
        case VKGL::ContextProperty::Max_Color_Texture_Samples:
        case VKGL::ContextProperty::Max_Combined_Fragment_Uniform_Components:
        case VKGL::ContextProperty::Max_Combined_Geometry_Uniform_Components:
        case VKGL::ContextProperty::Max_Combined_Texture_Image_Units:
        case VKGL::ContextProperty::Max_Combined_Uniform_Blocks:
        case VKGL::ContextProperty::Max_Combined_Vertex_Uniform_Components:
        case VKGL::ContextProperty::Max_Cube_Map_Texture_Size:
        case VKGL::ContextProperty::Max_Depth_Texture_Samples:
        case VKGL::ContextProperty::Max_Draw_Buffers:
        case VKGL::ContextProperty::Max_Dual_Source_Draw_Buffers:
        case VKGL::ContextProperty::Max_Elements_Indices:
        case VKGL::ContextProperty::Max_Elements_Vertices:
        case VKGL::ContextProperty::Max_Fragment_Input_Components:
        case VKGL::ContextProperty::Max_Fragment_Uniform_Blocks:
        case VKGL::ContextProperty::Max_Fragment_Uniform_Components:
        case VKGL::ContextProperty::Max_Geometry_Input_Components:
        case VKGL::ContextProperty::Max_Geometry_Output_Components:
        case VKGL::ContextProperty::Max_Geometry_Texture_Image_Units:
        case VKGL::ContextProperty::Max_Geometry_Uniform_Blocks:
        case VKGL::ContextProperty::Max_Geometry_Uniform_Components:
        case VKGL::ContextProperty::Max_Integer_Samples:
        case VKGL::ContextProperty::Max_Program_Texel_Offset:
        case VKGL::ContextProperty::Max_Rectangle_Texture_Size:
        case VKGL::ContextProperty::Max_Renderbuffer_Size:
        case VKGL::ContextProperty::Max_Sample_Mask_Words:
        case VKGL::ContextProperty::Max_Server_Wait_Timeout:
        case VKGL::ContextProperty::Max_Texture_Buffer_Size:
        case VKGL::ContextProperty::Max_Texture_Image_Units:
        case VKGL::ContextProperty::Max_Texture_LOD_Bias:
        case VKGL::ContextProperty::Max_Texture_Size:
        case VKGL::ContextProperty::Max_Uniform_Block_Size:
        case VKGL::ContextProperty::Max_Uniform_Buffer_Bindings:
        case VKGL::ContextProperty::Max_Varying_Components:
        case VKGL::ContextProperty::Max_Vertex_Attribs:
        case VKGL::ContextProperty::Max_Vertex_Output_Components:
        case VKGL::ContextProperty::Max_Vertex_Texture_Image_Units:
        case VKGL::ContextProperty::Max_Vertex_Uniform_Blocks:
        case VKGL::ContextProperty::Max_Vertex_Uniform_Components:
        case VKGL::ContextProperty::Max_Viewport_Dims:
        case VKGL::ContextProperty::Minor_Version:
        case VKGL::ContextProperty::Min_Program_Texel_Offset:
        case VKGL::ContextProperty::Num_Compressed_Texture_Formats:
        case VKGL::ContextProperty::Num_Extensions:
        case VKGL::ContextProperty::Point_Fade_Threshold_Size:
        case VKGL::ContextProperty::Point_Size_Granularity:
        case VKGL::ContextProperty::Point_Size_Range:
        case VKGL::ContextProperty::Smooth_Line_Width_Granularity:
        case VKGL::ContextProperty::Smooth_Line_Width_Range:
        case VKGL::ContextProperty::Subpixel_Bits:
        case VKGL::ContextProperty::Uniform_Buffer_Offset_Alignment:
        {
            result = true;
        }

        default:
        {
            result = false;
        }
    }

    return result;
}

bool VKGL::Utils::is_texture_binding_pname(const VKGL::ContextProperty& in_pname)
{
    return (in_pname == VKGL::ContextProperty::Texture_Binding_1D                   ||
            in_pname == VKGL::ContextProperty::Texture_Binding_1D_Array             ||
            in_pname == VKGL::ContextProperty::Texture_Binding_2D                   ||
            in_pname == VKGL::ContextProperty::Texture_Binding_2D_Array             ||
            in_pname == VKGL::ContextProperty::Texture_Binding_2D_Multisample       ||
            in_pname == VKGL::ContextProperty::Texture_Binding_2D_Multisample_Array ||
            in_pname == VKGL::ContextProperty::Texture_Binding_3D                   ||
            in_pname == VKGL::ContextProperty::Texture_Binding_Buffer               ||
            in_pname == VKGL::ContextProperty::Texture_Binding_Cube_Map             ||
            in_pname == VKGL::ContextProperty::Texture_Binding_Rectangle);
}
