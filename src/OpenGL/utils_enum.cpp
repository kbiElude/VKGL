/* OpenGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/debug.h"
#include "Common/globals.h"
#include "Common/macros.h"
#include "OpenGL/utils_enum.h"

OpenGL::BlendEquation OpenGL::Utils::get_blend_equation_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BlendEquation result = OpenGL::BlendEquation::Unknown;

    switch (in_enum)
    {
        case GL_FUNC_ADD:              result = OpenGL::BlendEquation::Function_Add;              break;
        case GL_FUNC_REVERSE_SUBTRACT: result = OpenGL::BlendEquation::Function_Reverse_Subtract; break;
        case GL_FUNC_SUBTRACT:         result = OpenGL::BlendEquation::Function_Subtract;         break;
        case GL_MAX:                   result = OpenGL::BlendEquation::Max;                       break;
        case GL_MIN:                   result = OpenGL::BlendEquation::Min;                       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BlendFunction OpenGL::Utils::get_blend_function_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BlendFunction result = OpenGL::BlendFunction::Unknown;

    switch (in_enum)
    {
        case GL_CONSTANT_ALPHA:           result = OpenGL::BlendFunction::Constant_Alpha;           break;
        case GL_CONSTANT_COLOR:           result = OpenGL::BlendFunction::Constant_Color;           break;
        case GL_DST_ALPHA:                result = OpenGL::BlendFunction::Dst_Alpha;                break;
        case GL_DST_COLOR:                result = OpenGL::BlendFunction::Dst_Color;                break;
        case GL_ONE:                      result = OpenGL::BlendFunction::One;                      break;
        case GL_ONE_MINUS_CONSTANT_ALPHA: result = OpenGL::BlendFunction::One_Minus_Constant_Alpha; break;
        case GL_ONE_MINUS_CONSTANT_COLOR: result = OpenGL::BlendFunction::One_Minus_Constant_Color; break;
        case GL_ONE_MINUS_DST_ALPHA:      result = OpenGL::BlendFunction::One_Minus_Dst_Alpha;      break;
        case GL_ONE_MINUS_DST_COLOR:      result = OpenGL::BlendFunction::One_Minus_Dst_Color;      break;
        case GL_ONE_MINUS_SRC_ALPHA:      result = OpenGL::BlendFunction::One_Minus_Src_Alpha;      break;
        case GL_ONE_MINUS_SRC_COLOR:      result = OpenGL::BlendFunction::One_Minus_Src_Color;      break;
        case GL_SRC_ALPHA:                result = OpenGL::BlendFunction::Src_Alpha;                break;
        case GL_SRC_ALPHA_SATURATE:       result = OpenGL::BlendFunction::Src_Alpha_Saturate;       break;
        case GL_SRC_COLOR:                result = OpenGL::BlendFunction::Src_Color;                break;
        case GL_ZERO:                     result = OpenGL::BlendFunction::Zero;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BlitFilter OpenGL::Utils::get_blit_filter_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BlitFilter result = OpenGL::BlitFilter::Unknown;

    switch (in_enum)
    {
        case GL_LINEAR:  result = OpenGL::BlitFilter::Linear;  break;
        case GL_NEAREST: result = OpenGL::BlitFilter::Nearest; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BlitMaskBits OpenGL::Utils::get_blit_mask_bits_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BlitMaskBits result = 0;

    if (in_enum & GL_COLOR_BUFFER_BIT)
    {
        result |= OpenGL::BlitMaskBit::BLIT_MASK_BIT_COLOR_BUFFER;
    }

    if (in_enum & GL_DEPTH_BUFFER_BIT)
    {
        result |= OpenGL::BlitMaskBit::BLIT_MASK_BIT_DEPTH_BUFFER;
    }

    if (in_enum & GL_STENCIL_BUFFER_BIT)
    {
        result |= OpenGL::BlitMaskBit::BLIT_MASK_BIT_STENCIL_BUFFER;
    }

    return result;
}

OpenGL::BufferAccess OpenGL::Utils::get_buffer_access_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BufferAccess result = OpenGL::BufferAccess::Unknown;

    switch (in_enum)
    {
        case GL_READ_ONLY:  result = OpenGL::BufferAccess::Read_Only;  break;
        case GL_READ_WRITE: result = OpenGL::BufferAccess::Read_Write; break;
        case GL_WRITE_ONLY: result = OpenGL::BufferAccess::Write_Only; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BufferPointerProperty OpenGL::Utils::get_buffer_pointer_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BufferPointerProperty result = OpenGL::BufferPointerProperty::Unknown;

    switch (in_enum)
    {
        case GL_BUFFER_MAP_POINTER: result = OpenGL::BufferPointerProperty::Buffer_Map_Pointer; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BufferProperty OpenGL::Utils::get_buffer_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BufferProperty result = OpenGL::BufferProperty::Unknown;

    switch (in_enum)
    {
        case GL_BUFFER_ACCESS: result = OpenGL::BufferProperty::Buffer_Access; break;
        case GL_BUFFER_MAPPED: result = OpenGL::BufferProperty::Buffer_Mapped; break;
        case GL_BUFFER_SIZE:   result = OpenGL::BufferProperty::Buffer_Size;   break;
        case GL_BUFFER_USAGE:  result = OpenGL::BufferProperty::Buffer_Usage;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BufferTarget OpenGL::Utils::get_buffer_target_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BufferTarget result = OpenGL::BufferTarget::Unknown;

    switch (in_enum)
    {
        case GL_ARRAY_BUFFER:              result = OpenGL::BufferTarget::Array_Buffer;              break;
        case GL_COPY_READ_BUFFER:          result = OpenGL::BufferTarget::Copy_Read_Buffer;          break;
        case GL_COPY_WRITE_BUFFER:         result = OpenGL::BufferTarget::Copy_Write_Buffer;         break;
        case GL_ELEMENT_ARRAY_BUFFER:      result = OpenGL::BufferTarget::Element_Array_Buffer;      break;
        case GL_PIXEL_PACK_BUFFER:         result = OpenGL::BufferTarget::Pixel_Pack_Buffer;         break;
        case GL_PIXEL_UNPACK_BUFFER:       result = OpenGL::BufferTarget::Pixel_Unpack_Buffer;       break;
        case GL_TEXTURE_BUFFER:            result = OpenGL::BufferTarget::Texture_Buffer;            break;
        case GL_TRANSFORM_FEEDBACK_BUFFER: result = OpenGL::BufferTarget::Transform_Feedback_Buffer; break;
        case GL_UNIFORM_BUFFER:            result = OpenGL::BufferTarget::Uniform_Buffer;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::BufferUsage OpenGL::Utils::get_buffer_usage_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::BufferUsage result = OpenGL::BufferUsage::Unknown;

    switch (in_enum)
    {
        case GL_DYNAMIC_COPY: result = OpenGL::BufferUsage::Dynamic_Copy; break;
        case GL_DYNAMIC_DRAW: result = OpenGL::BufferUsage::Dynamic_Draw; break;
        case GL_DYNAMIC_READ: result = OpenGL::BufferUsage::Dynamic_Read; break;
        case GL_STATIC_COPY:  result = OpenGL::BufferUsage::Static_Copy;  break;
        case GL_STATIC_DRAW:  result = OpenGL::BufferUsage::Static_Draw;  break;
        case GL_STATIC_READ:  result = OpenGL::BufferUsage::Static_Read;  break;
        case GL_STREAM_COPY:  result = OpenGL::BufferUsage::Stream_Copy;  break;
        case GL_STREAM_DRAW:  result = OpenGL::BufferUsage::Stream_Draw;  break;
        case GL_STREAM_READ:  result = OpenGL::BufferUsage::Stream_Read;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ClampReadColorMode OpenGL::Utils::get_clamp_read_color_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ClampReadColorMode result = OpenGL::ClampReadColorMode::Unknown;

    switch (in_enum)
    {
        case GL_FALSE:      result = OpenGL::ClampReadColorMode::False;      break;
        case GL_FIXED_ONLY: result = OpenGL::ClampReadColorMode::Fixed_Only; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ClearBuffer OpenGL::Utils::get_clear_buffer_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ClearBuffer result = OpenGL::ClearBuffer::Unknown;

    switch (in_enum)
    {
        case GL_BACK:           result = OpenGL::ClearBuffer::Back;           break;
        case GL_COLOR:          result = OpenGL::ClearBuffer::Color;          break;
        case GL_DEPTH:          result = OpenGL::ClearBuffer::Depth;          break;
        case GL_DEPTH_STENCIL:  result = OpenGL::ClearBuffer::Depth_Stencil;  break;
        case GL_FRONT:          result = OpenGL::ClearBuffer::Front;          break;
        case GL_FRONT_AND_BACK: result = OpenGL::ClearBuffer::Front_And_Back; break;
        case GL_LEFT:           result = OpenGL::ClearBuffer::Left;           break;
        case GL_RIGHT:          result = OpenGL::ClearBuffer::Right;          break;
        case GL_STENCIL:        result = OpenGL::ClearBuffer::Stencil;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ClearBufferBits OpenGL::Utils::get_clear_buffer_bits_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ClearBufferBits result = 0;

    if (in_enum & GL_COLOR_BUFFER_BIT)
    {
        result |= OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_COLOR;
    }

    if (in_enum & GL_DEPTH_BUFFER_BIT)
    {
        result |= OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_DEPTH;
    }

    if (in_enum & GL_STENCIL_BUFFER_BIT)
    {
        result |= OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_STENCIL;
    }

    return result;
}

OpenGL::ConditionalRenderMode OpenGL::Utils::get_conditional_render_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ConditionalRenderMode result = OpenGL::ConditionalRenderMode::Unknown;

    switch (in_enum)
    {
        case GL_QUERY_BY_REGION_NO_WAIT: result = OpenGL::ConditionalRenderMode::Query_By_Region_No_Wait; break;
        case GL_QUERY_BY_REGION_WAIT:    result = OpenGL::ConditionalRenderMode::Query_By_Region_Wait;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ContextProperty OpenGL::Utils::get_context_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ContextProperty result = OpenGL::ContextProperty::Unknown;

    switch (in_enum)
    {
        case GL_ACTIVE_TEXTURE:                                result = OpenGL::ContextProperty::Active_Texture;                                break;
        case GL_ALIASED_LINE_WIDTH_RANGE:                      result = OpenGL::ContextProperty::Aliased_Line_Width_Range;                      break;
        case GL_ARRAY_BUFFER_BINDING:                          result = OpenGL::ContextProperty::Array_Buffer_Binding;                          break;
        case GL_BLEND:                                         result = OpenGL::ContextProperty::Blend;                                         break;
        case GL_BLEND_COLOR:                                   result = OpenGL::ContextProperty::Blend_Color;                                   break;
        case GL_BLEND_DST_ALPHA:                               result = OpenGL::ContextProperty::Blend_Dst_Alpha;                               break;
        case GL_BLEND_DST_RGB:                                 result = OpenGL::ContextProperty::Blend_Dst_RGB;                                 break;
        case GL_BLEND_EQUATION_ALPHA:                          result = OpenGL::ContextProperty::Blend_Equation_Alpha;                          break;
        case GL_BLEND_EQUATION_RGB:                            result = OpenGL::ContextProperty::Blend_Equation_RGB;                            break;
        case GL_BLEND_SRC_ALPHA:                               result = OpenGL::ContextProperty::Blend_Src_Alpha;                               break;
        case GL_BLEND_SRC_RGB:                                 result = OpenGL::ContextProperty::Blend_Src_RGB;                                 break;
        case GL_COLOR_CLEAR_VALUE:                             result = OpenGL::ContextProperty::Color_Clear_Value;                             break;
        case GL_COLOR_LOGIC_OP:                                result = OpenGL::ContextProperty::Color_Logic_Op;                                break;
        case GL_COLOR_WRITEMASK:                               result = OpenGL::ContextProperty::Color_Writemask;                               break;
        case GL_COMPRESSED_TEXTURE_FORMATS:                    result = OpenGL::ContextProperty::Compressed_Texture_Formats;                    break;
        case GL_CONTEXT_FLAGS:                                 result = OpenGL::ContextProperty::Context_Flags;                                 break;
        case GL_CONTEXT_PROFILE_MASK:                          result = OpenGL::ContextProperty::Context_Profile_Mask;                          break;
        case GL_CULL_FACE:                                     result = OpenGL::ContextProperty::Cull_Face;                                     break;
        case GL_CURRENT_PROGRAM:                               result = OpenGL::ContextProperty::Current_Program;                               break;
        case GL_DEPTH_CLEAR_VALUE:                             result = OpenGL::ContextProperty::Depth_Clear_Value;                             break;
        case GL_DEPTH_FUNC:                                    result = OpenGL::ContextProperty::Depth_Func;                                    break;
        case GL_DEPTH_RANGE:                                   result = OpenGL::ContextProperty::Depth_Range;                                   break;
        case GL_DEPTH_TEST:                                    result = OpenGL::ContextProperty::Depth_Test;                                    break;
        case GL_DEPTH_WRITEMASK:                               result = OpenGL::ContextProperty::Depth_Writemask;                               break;
        case GL_DITHER:                                        result = OpenGL::ContextProperty::Dither;                                        break;
        case GL_DOUBLEBUFFER:                                  result = OpenGL::ContextProperty::Doublebuffer;                                  break;
        case GL_DRAW_BUFFER:                                   result = OpenGL::ContextProperty::Draw_Buffer;                                   break;
        case GL_DRAW_BUFFER0:                                  result = OpenGL::ContextProperty::Draw_Buffer0;                                  break;
        case GL_DRAW_BUFFER1:                                  result = OpenGL::ContextProperty::Draw_Buffer1;                                  break;
        case GL_DRAW_BUFFER2:                                  result = OpenGL::ContextProperty::Draw_Buffer2;                                  break;
        case GL_DRAW_BUFFER3:                                  result = OpenGL::ContextProperty::Draw_Buffer3;                                  break;
        case GL_DRAW_BUFFER4:                                  result = OpenGL::ContextProperty::Draw_Buffer4;                                  break;
        case GL_DRAW_BUFFER5:                                  result = OpenGL::ContextProperty::Draw_Buffer5;                                  break;
        case GL_DRAW_BUFFER6:                                  result = OpenGL::ContextProperty::Draw_Buffer6;                                  break;
        case GL_DRAW_BUFFER7:                                  result = OpenGL::ContextProperty::Draw_Buffer7;                                  break;
        case GL_DRAW_FRAMEBUFFER_BINDING:                      result = OpenGL::ContextProperty::Draw_Framebuffer_Binding;                      break;
        case GL_ELEMENT_ARRAY_BUFFER_BINDING:                  result = OpenGL::ContextProperty::Element_Array_Buffer_Binding;                  break;
        case GL_EXTENSIONS:                                    result = OpenGL::ContextProperty::Extensions;                                    break;
        case GL_FRAGMENT_SHADER_DERIVATIVE_HINT:               result = OpenGL::ContextProperty::Fragment_Shader_Derivative_Hint;               break;
        case GL_LINE_SMOOTH:                                   result = OpenGL::ContextProperty::Line_Smooth;                                   break;
        case GL_LINE_SMOOTH_HINT:                              result = OpenGL::ContextProperty::Line_Smooth_Hint;                              break;
        case GL_LINE_WIDTH:                                    result = OpenGL::ContextProperty::Line_Width;                                    break;
        case GL_LOGIC_OP_MODE:                                 result = OpenGL::ContextProperty::Logic_Op_Mode;                                 break;
        case GL_MAJOR_VERSION:                                 result = OpenGL::ContextProperty::Major_Version;                                 break;
        case GL_MAX_3D_TEXTURE_SIZE:                           result = OpenGL::ContextProperty::Max_3D_Texture_Size;                           break;
        case GL_MAX_ARRAY_TEXTURE_LAYERS:                      result = OpenGL::ContextProperty::Max_Array_Texture_Layers;                      break;
        case GL_MAX_CLIP_DISTANCES:                            result = OpenGL::ContextProperty::Max_Clip_Distances;                            break;
        case GL_MAX_COLOR_ATTACHMENTS:                         result = OpenGL::ContextProperty::Max_Color_Attachments;                         break;
        case GL_MAX_COLOR_TEXTURE_SAMPLES:                     result = OpenGL::ContextProperty::Max_Color_Texture_Samples;                     break;
        case GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS:      result = OpenGL::ContextProperty::Max_Combined_Fragment_Uniform_Components;      break;
        case GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS:      result = OpenGL::ContextProperty::Max_Combined_Geometry_Uniform_Components;      break;
        case GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS:              result = OpenGL::ContextProperty::Max_Combined_Texture_Image_Units;              break;
        case GL_MAX_COMBINED_UNIFORM_BLOCKS:                   result = OpenGL::ContextProperty::Max_Combined_Uniform_Blocks;                   break;
        case GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS:        result = OpenGL::ContextProperty::Max_Combined_Vertex_Uniform_Components;        break;
        case GL_MAX_CUBE_MAP_TEXTURE_SIZE:                     result = OpenGL::ContextProperty::Max_Cube_Map_Texture_Size;                     break;
        case GL_MAX_DEPTH_TEXTURE_SAMPLES:                     result = OpenGL::ContextProperty::Max_Depth_Texture_Samples;                     break;
        case GL_MAX_DRAW_BUFFERS:                              result = OpenGL::ContextProperty::Max_Draw_Buffers;                              break;
        case GL_MAX_DUAL_SOURCE_DRAW_BUFFERS:                  result = OpenGL::ContextProperty::Max_Dual_Source_Draw_Buffers;                  break;
        case GL_MAX_ELEMENTS_INDICES:                          result = OpenGL::ContextProperty::Max_Elements_Indices;                          break;
        case GL_MAX_ELEMENTS_VERTICES:                         result = OpenGL::ContextProperty::Max_Elements_Vertices;                         break;
        case GL_MAX_FRAGMENT_INPUT_COMPONENTS:                 result = OpenGL::ContextProperty::Max_Fragment_Input_Components;                 break;
        case GL_MAX_FRAGMENT_UNIFORM_BLOCKS:                   result = OpenGL::ContextProperty::Max_Fragment_Uniform_Blocks;                   break;
        case GL_MAX_FRAGMENT_UNIFORM_COMPONENTS:               result = OpenGL::ContextProperty::Max_Fragment_Uniform_Components;               break;
        case GL_MAX_GEOMETRY_INPUT_COMPONENTS:                 result = OpenGL::ContextProperty::Max_Geometry_Input_Components;                 break;
        case GL_MAX_GEOMETRY_OUTPUT_COMPONENTS:                result = OpenGL::ContextProperty::Max_Geometry_Output_Components;                break;
        case GL_MAX_GEOMETRY_OUTPUT_VERTICES:                  result = OpenGL::ContextProperty::Max_Geometry_Output_Vertices;                  break;
        case GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS:              result = OpenGL::ContextProperty::Max_Geometry_Texture_Image_Units;              break;
        case GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS:          result = OpenGL::ContextProperty::Max_Geometry_Total_Output_Components;          break;
        case GL_MAX_GEOMETRY_UNIFORM_BLOCKS:                   result = OpenGL::ContextProperty::Max_Geometry_Uniform_Blocks;                   break;
        case GL_MAX_GEOMETRY_UNIFORM_COMPONENTS:               result = OpenGL::ContextProperty::Max_Geometry_Uniform_Components;               break;
        case GL_MAX_INTEGER_SAMPLES:                           result = OpenGL::ContextProperty::Max_Integer_Samples;                           break;
        case GL_MAX_PROGRAM_TEXEL_OFFSET:                      result = OpenGL::ContextProperty::Max_Program_Texel_Offset;                      break;
        case GL_MAX_RECTANGLE_TEXTURE_SIZE:                    result = OpenGL::ContextProperty::Max_Rectangle_Texture_Size;                    break;
        case GL_MAX_RENDERBUFFER_SIZE:                         result = OpenGL::ContextProperty::Max_Renderbuffer_Size;                         break;
        case GL_MAX_SAMPLE_MASK_WORDS:                         result = OpenGL::ContextProperty::Max_Sample_Mask_Words;                         break;
        case GL_MAX_SAMPLES:                                   result = OpenGL::ContextProperty::Max_Samples;                                   break;
        case GL_MAX_SERVER_WAIT_TIMEOUT:                       result = OpenGL::ContextProperty::Max_Server_Wait_Timeout;                       break;
        case GL_MAX_TEXTURE_BUFFER_SIZE:                       result = OpenGL::ContextProperty::Max_Texture_Buffer_Size;                       break;
        case GL_MAX_TEXTURE_IMAGE_UNITS:                       result = OpenGL::ContextProperty::Max_Texture_Image_Units;                       break;
        case GL_MAX_TEXTURE_LOD_BIAS:                          result = OpenGL::ContextProperty::Max_Texture_LOD_Bias;                          break;
        case GL_MAX_TEXTURE_SIZE:                              result = OpenGL::ContextProperty::Max_Texture_Size;                              break;
        case GL_MAX_TRANSFORM_FEEDBACK_BUFFERS:                result = OpenGL::ContextProperty::Max_Transform_Feedback_Buffers;                break;
        case GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS: result = OpenGL::ContextProperty::Max_Transform_Feedback_Interleaved_Components; break;
        case GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS:       result = OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Attribs;       break;
        case GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS:    result = OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Components;    break;
        case GL_MAX_UNIFORM_BLOCK_SIZE:                        result = OpenGL::ContextProperty::Max_Uniform_Block_Size;                        break;
        case GL_MAX_UNIFORM_BUFFER_BINDINGS:                   result = OpenGL::ContextProperty::Max_Uniform_Buffer_Bindings;                   break;
        case GL_MAX_VARYING_COMPONENTS:                        result = OpenGL::ContextProperty::Max_Varying_Components;                        break;
        case GL_MAX_VERTEX_ATTRIBS:                            result = OpenGL::ContextProperty::Max_Vertex_Attribs;                            break;
        case GL_MAX_VERTEX_OUTPUT_COMPONENTS:                  result = OpenGL::ContextProperty::Max_Vertex_Output_Components;                  break;
        case GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS:                result = OpenGL::ContextProperty::Max_Vertex_Texture_Image_Units;                break;
        case GL_MAX_VERTEX_UNIFORM_BLOCKS:                     result = OpenGL::ContextProperty::Max_Vertex_Uniform_Blocks;                     break;
        case GL_MAX_VERTEX_UNIFORM_COMPONENTS:                 result = OpenGL::ContextProperty::Max_Vertex_Uniform_Components;                 break;
        case GL_MAX_VIEWPORT_DIMS:                             result = OpenGL::ContextProperty::Max_Viewport_Dims;                             break;
        case GL_MINOR_VERSION:                                 result = OpenGL::ContextProperty::Minor_Version;                                 break;
        case GL_MIN_PROGRAM_TEXEL_OFFSET:                      result = OpenGL::ContextProperty::Min_Program_Texel_Offset;                      break;
        case GL_NUM_COMPRESSED_TEXTURE_FORMATS:                result = OpenGL::ContextProperty::Num_Compressed_Texture_Formats;                break;
        case GL_NUM_EXTENSIONS:                                result = OpenGL::ContextProperty::Num_Extensions;                                break;
        case GL_PACK_ALIGNMENT:                                result = OpenGL::ContextProperty::Pack_Alignment;                                break;
        case GL_PACK_IMAGE_HEIGHT:                             result = OpenGL::ContextProperty::Pack_Image_Height;                             break;
        case GL_PACK_LSB_FIRST:                                result = OpenGL::ContextProperty::Pack_LSB_First;                                break;
        case GL_PACK_ROW_LENGTH:                               result = OpenGL::ContextProperty::Pack_Row_Length;                               break;
        case GL_PACK_SKIP_IMAGES:                              result = OpenGL::ContextProperty::Pack_Skip_Images;                              break;
        case GL_PACK_SKIP_PIXELS:                              result = OpenGL::ContextProperty::Pack_Skip_Pixels;                              break;
        case GL_PACK_SKIP_ROWS:                                result = OpenGL::ContextProperty::Pack_Skip_Rows;                                break;
        case GL_PACK_SWAP_BYTES:                               result = OpenGL::ContextProperty::Pack_Swap_Bytes;                               break;
        case GL_PIXEL_PACK_BUFFER_BINDING:                     result = OpenGL::ContextProperty::Pixel_Pack_Buffer_Binding;                     break;
        case GL_PIXEL_UNPACK_BUFFER_BINDING:                   result = OpenGL::ContextProperty::Pixel_Unpack_Buffer_Binding;                   break;
        case GL_POINT_FADE_THRESHOLD_SIZE:                     result = OpenGL::ContextProperty::Point_Fade_Threshold_Size;                     break;
        case GL_POINT_SIZE:                                    result = OpenGL::ContextProperty::Point_Size;                                    break;
        case GL_POINT_SIZE_GRANULARITY:                        result = OpenGL::ContextProperty::Point_Size_Granularity;                        break;
        case GL_POINT_SIZE_RANGE:                              result = OpenGL::ContextProperty::Point_Size_Range;                              break;
        case GL_POLYGON_OFFSET_FACTOR:                         result = OpenGL::ContextProperty::Polygon_Offset_Factor;                         break;
        case GL_POLYGON_OFFSET_FILL:                           result = OpenGL::ContextProperty::Polygon_Offset_Fill;                           break;
        case GL_POLYGON_OFFSET_LINE:                           result = OpenGL::ContextProperty::Polygon_Offset_Line;                           break;
        case GL_POLYGON_OFFSET_POINT:                          result = OpenGL::ContextProperty::Polygon_Offset_Point;                          break;
        case GL_POLYGON_OFFSET_UNITS:                          result = OpenGL::ContextProperty::Polygon_Offset_Units;                          break;
        case GL_POLYGON_SMOOTH:                                result = OpenGL::ContextProperty::Polygon_Smooth;                                break;
        case GL_POLYGON_SMOOTH_HINT:                           result = OpenGL::ContextProperty::Polygon_Smooth_Hint;                           break;
        case GL_PRIMITIVE_RESTART_INDEX:                       result = OpenGL::ContextProperty::Primitive_Restart_Index;                       break;
        case GL_PROGRAM_POINT_SIZE:                            result = OpenGL::ContextProperty::Program_Point_Size;                            break;
        case GL_PROVOKING_VERTEX:                              result = OpenGL::ContextProperty::Provoking_Vertex;                              break;
        case GL_QUERY_COUNTER_BITS:                            result = OpenGL::ContextProperty::Query_Counter_Bits;                            break;
        case GL_READ_BUFFER:                                   result = OpenGL::ContextProperty::Read_Buffer;                                   break;
        case GL_READ_FRAMEBUFFER_BINDING:                      result = OpenGL::ContextProperty::Read_Framebuffer_Binding;                      break;
        case GL_RENDERER:                                      result = OpenGL::ContextProperty::Renderer;                                      break;
        case GL_RENDERBUFFER_BINDING:                          result = OpenGL::ContextProperty::Renderbuffer_Binding;                          break;
        case GL_SAMPLER_BINDING:                               result = OpenGL::ContextProperty::Sampler_Binding;                               break;
        case GL_SAMPLES:                                       result = OpenGL::ContextProperty::Samples;                                       break;
        case GL_SAMPLE_BUFFERS:                                result = OpenGL::ContextProperty::Sample_Buffers;                                break;
        case GL_SAMPLE_COVERAGE_INVERT:                        result = OpenGL::ContextProperty::Sample_Coverage_Invert;                        break;
        case GL_SAMPLE_COVERAGE_VALUE:                         result = OpenGL::ContextProperty::Sample_Coverage_Value;                         break;
        case GL_SCISSOR_BOX:                                   result = OpenGL::ContextProperty::Scissor_Box;                                   break;
        case GL_SCISSOR_TEST:                                  result = OpenGL::ContextProperty::Scissor_Test;                                  break;
        case GL_SHADING_LANGUAGE_VERSION:                      result = OpenGL::ContextProperty::Shading_Language_Version;                      break;
        case GL_SMOOTH_LINE_WIDTH_GRANULARITY:                 result = OpenGL::ContextProperty::Smooth_Line_Width_Granularity;                 break;
        case GL_SMOOTH_LINE_WIDTH_RANGE:                       result = OpenGL::ContextProperty::Smooth_Line_Width_Range;                       break;
        case GL_STENCIL_BACK_FAIL:                             result = OpenGL::ContextProperty::Stencil_Back_Fail;                             break;
        case GL_STENCIL_BACK_FUNC:                             result = OpenGL::ContextProperty::Stencil_Back_Func;                             break;
        case GL_STENCIL_BACK_PASS_DEPTH_FAIL:                  result = OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Fail;                  break;
        case GL_STENCIL_BACK_PASS_DEPTH_PASS:                  result = OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Pass;                  break;
        case GL_STENCIL_BACK_REF:                              result = OpenGL::ContextProperty::Stencil_Back_Ref;                              break;
        case GL_STENCIL_BACK_VALUE_MASK:                       result = OpenGL::ContextProperty::Stencil_Back_Value_Mask;                       break;
        case GL_STENCIL_BACK_WRITEMASK:                        result = OpenGL::ContextProperty::Stencil_Back_Writemask;                        break;
        case GL_STENCIL_CLEAR_VALUE:                           result = OpenGL::ContextProperty::Stencil_Clear_Value;                           break;
        case GL_STENCIL_FAIL:                                  result = OpenGL::ContextProperty::Stencil_Fail;                                  break;
        case GL_STENCIL_FUNC:                                  result = OpenGL::ContextProperty::Stencil_Func;                                  break;
        case GL_STENCIL_PASS_DEPTH_FAIL:                       result = OpenGL::ContextProperty::Stencil_Pass_Depth_Fail;                       break;
        case GL_STENCIL_PASS_DEPTH_PASS:                       result = OpenGL::ContextProperty::Stencil_Pass_Depth_Pass;                       break;
        case GL_STENCIL_REF:                                   result = OpenGL::ContextProperty::Stencil_Ref;                                   break;
        case GL_STENCIL_TEST:                                  result = OpenGL::ContextProperty::Stencil_Test;                                  break;
        case GL_STENCIL_VALUE_MASK:                            result = OpenGL::ContextProperty::Stencil_Value_Mask;                            break;
        case GL_STENCIL_WRITEMASK:                             result = OpenGL::ContextProperty::Stencil_Writemask;                             break;
        case GL_STEREO:                                        result = OpenGL::ContextProperty::Stereo;                                        break;
        case GL_SUBPIXEL_BITS:                                 result = OpenGL::ContextProperty::Subpixel_Bits;                                 break;
        case GL_TEXTURE_BINDING_1D:                            result = OpenGL::ContextProperty::Texture_Binding_1D;                            break;
        case GL_TEXTURE_BINDING_1D_ARRAY:                      result = OpenGL::ContextProperty::Texture_Binding_1D_Array;                      break;
        case GL_TEXTURE_BINDING_2D:                            result = OpenGL::ContextProperty::Texture_Binding_2D;                            break;
        case GL_TEXTURE_BINDING_2D_ARRAY:                      result = OpenGL::ContextProperty::Texture_Binding_2D_Array;                      break;
        case GL_TEXTURE_BINDING_2D_MULTISAMPLE:                result = OpenGL::ContextProperty::Texture_Binding_2D_Multisample;                break;
        case GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY:          result = OpenGL::ContextProperty::Texture_Binding_2D_Multisample_Array;          break;
        case GL_TEXTURE_BINDING_3D:                            result = OpenGL::ContextProperty::Texture_Binding_3D;                            break;
        case GL_TEXTURE_BINDING_BUFFER:                        result = OpenGL::ContextProperty::Texture_Binding_Buffer;                        break;
        case GL_TEXTURE_BINDING_CUBE_MAP:                      result = OpenGL::ContextProperty::Texture_Binding_Cube_Map;                      break;
        case GL_TEXTURE_BINDING_RECTANGLE:                     result = OpenGL::ContextProperty::Texture_Binding_Rectangle;                     break;
        case GL_TEXTURE_COMPRESSION_HINT:                      result = OpenGL::ContextProperty::Texture_Compression_Hint;                      break;
        case GL_TIMESTAMP:                                     result = OpenGL::ContextProperty::Timestamp;                                     break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_BINDING:             result = OpenGL::ContextProperty::Transform_Feedback_Buffer_Binding;             break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_SIZE:                result = OpenGL::ContextProperty::Transform_Feedback_Buffer_Size;                break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_START:               result = OpenGL::ContextProperty::Transform_Feedback_Buffer_Start;               break;
        case GL_UNIFORM_BUFFER_BINDING:                        result = OpenGL::ContextProperty::Uniform_Buffer_Binding;                        break;
        case GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT:               result = OpenGL::ContextProperty::Uniform_Buffer_Offset_Alignment;               break;
        case GL_UNIFORM_BUFFER_SIZE:                           result = OpenGL::ContextProperty::Uniform_Buffer_Size;                           break;
        case GL_UNIFORM_BUFFER_START:                          result = OpenGL::ContextProperty::Uniform_Buffer_Start;                          break;
        case GL_UNPACK_ALIGNMENT:                              result = OpenGL::ContextProperty::Unpack_Alignment;                              break;
        case GL_UNPACK_IMAGE_HEIGHT:                           result = OpenGL::ContextProperty::Unpack_Image_Height;                           break;
        case GL_UNPACK_LSB_FIRST:                              result = OpenGL::ContextProperty::Unpack_LSB_First;                              break;
        case GL_UNPACK_ROW_LENGTH:                             result = OpenGL::ContextProperty::Unpack_Row_Length;                             break;
        case GL_UNPACK_SKIP_IMAGES:                            result = OpenGL::ContextProperty::Unpack_Skip_Images;                            break;
        case GL_UNPACK_SKIP_PIXELS:                            result = OpenGL::ContextProperty::Unpack_Skip_Pixels;                            break;
        case GL_UNPACK_SKIP_ROWS:                              result = OpenGL::ContextProperty::Unpack_Skip_Rows;                              break;
        case GL_UNPACK_SWAP_BYTES:                             result = OpenGL::ContextProperty::Unpack_Swap_Bytes;                             break;
        case GL_VERSION:                                       result = OpenGL::ContextProperty::Version;                                       break;
        case GL_VIEWPORT:                                      result = OpenGL::ContextProperty::Viewport;                                      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::DrawCallIndexType OpenGL::Utils::get_draw_call_index_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::DrawCallIndexType result = OpenGL::DrawCallIndexType::Unknown;

    switch (in_enum)
    {
        case GL_UNSIGNED_BYTE:  result = OpenGL::DrawCallIndexType::Unsigned_Byte;  break;
        case GL_UNSIGNED_SHORT: result = OpenGL::DrawCallIndexType::Unsigned_Short; break;
        case GL_UNSIGNED_INT:   result = OpenGL::DrawCallIndexType::Unsigned_Int;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::DrawCallMode OpenGL::Utils::get_draw_call_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::DrawCallMode result = OpenGL::DrawCallMode::Unknown;

    switch (in_enum)
    {
        default:
        {
            case GL_LINES:                    result = OpenGL::DrawCallMode::Lines;                    break;
            case GL_LINES_ADJACENCY:          result = OpenGL::DrawCallMode::Lines_Adjacency;          break;
            case GL_LINE_LOOP:                result = OpenGL::DrawCallMode::Line_Loop;                break;
            case GL_LINE_STRIP:               result = OpenGL::DrawCallMode::Line_Strip;               break;
            case GL_LINE_STRIP_ADJACENCY:     result = OpenGL::DrawCallMode::Line_Strip_Adjacency;     break;
            case GL_PATCHES:                  result = OpenGL::DrawCallMode::Patches;                  break;
            case GL_POINTS:                   result = OpenGL::DrawCallMode::Points;                   break;
            case GL_TRIANGLE_FAN:             result = OpenGL::DrawCallMode::Triangle_Fan;             break;
            case GL_TRIANGLE_STRIP:           result = OpenGL::DrawCallMode::Triangle_Strip;           break;
            case GL_TRIANGLE_STRIP_ADJACENCY: result = OpenGL::DrawCallMode::Triangle_Strip_Adjacency; break;
            case GL_TRIANGLES:                result = OpenGL::DrawCallMode::Triangles;                break;
            case GL_TRIANGLES_ADJACENCY:      result = OpenGL::DrawCallMode::Triangles_Adjacency;      break;

            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ErrorCode OpenGL::Utils::get_error_code_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ErrorCode result = OpenGL::ErrorCode::Unknown;

    switch (in_enum)
    {
        case GL_INVALID_ENUM:                  result = OpenGL::ErrorCode::Invalid_Enum;                  break;
        case GL_INVALID_FRAMEBUFFER_OPERATION: result = OpenGL::ErrorCode::Invalid_Framebuffer_Operation; break;
        case GL_INVALID_OPERATION:             result = OpenGL::ErrorCode::Invalid_Operation;             break;
        case GL_INVALID_VALUE:                 result = OpenGL::ErrorCode::Invalid_Value;                 break;
        case GL_NO_ERROR:                      result = OpenGL::ErrorCode::No_Error;                      break;
        case GL_OUT_OF_MEMORY:                 result = OpenGL::ErrorCode::Out_Of_Memory;                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FramebufferStatus OpenGL::Utils::get_framebuffer_status_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FramebufferStatus result = OpenGL::FramebufferStatus::Unknown;

    switch (in_enum)
    {
        case GL_FRAMEBUFFER_COMPLETE:                      result = OpenGL::FramebufferStatus::Complete;                      break;
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:         result = OpenGL::FramebufferStatus::Incomplete_Attachment;         break;
        case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:        result = OpenGL::FramebufferStatus::Incomplete_Draw_Buffer;        break;
        case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:      result = OpenGL::FramebufferStatus::Incomplete_Layer_Targets;      break;
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT: result = OpenGL::FramebufferStatus::Incomplete_Missing_Attachment; break;
        case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:        result = OpenGL::FramebufferStatus::Incomplete_Multisample;        break;
        case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:        result = OpenGL::FramebufferStatus::Incomplete_Read_Buffer;        break;
        case GL_FRAMEBUFFER_UNDEFINED:                     result = OpenGL::FramebufferStatus::Undefined;                     break;
        case GL_FRAMEBUFFER_UNSUPPORTED:                   result = OpenGL::FramebufferStatus::Unsupported;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_context_property(const OpenGL::ContextProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::ContextProperty::Active_Texture:                                result = GL_ACTIVE_TEXTURE;                                break;
        case OpenGL::ContextProperty::Aliased_Line_Width_Range:                      result = GL_ALIASED_LINE_WIDTH_RANGE;                      break;
        case OpenGL::ContextProperty::Array_Buffer_Binding:                          result = GL_ARRAY_BUFFER_BINDING;                          break;
        case OpenGL::ContextProperty::Blend:                                         result = GL_BLEND;                                         break;
        case OpenGL::ContextProperty::Blend_Color:                                   result = GL_BLEND_COLOR;                                   break;
        case OpenGL::ContextProperty::Blend_Dst_Alpha:                               result = GL_BLEND_DST_ALPHA;                               break;
        case OpenGL::ContextProperty::Blend_Dst_RGB:                                 result = GL_BLEND_DST_RGB;                                 break;
        case OpenGL::ContextProperty::Blend_Equation_Alpha:                          result = GL_BLEND_EQUATION_ALPHA;                          break;
        case OpenGL::ContextProperty::Blend_Equation_RGB:                            result = GL_BLEND_EQUATION_RGB;                            break;
        case OpenGL::ContextProperty::Blend_Src_Alpha:                               result = GL_BLEND_SRC_ALPHA;                               break;
        case OpenGL::ContextProperty::Blend_Src_RGB:                                 result = GL_BLEND_SRC_RGB;                                 break;
        case OpenGL::ContextProperty::Color_Clear_Value:                             result = GL_COLOR_CLEAR_VALUE;                             break;
        case OpenGL::ContextProperty::Color_Logic_Op:                                result = GL_COLOR_LOGIC_OP;                                break;
        case OpenGL::ContextProperty::Color_Writemask:                               result = GL_COLOR_WRITEMASK;                               break;
        case OpenGL::ContextProperty::Compressed_Texture_Formats:                    result = GL_COMPRESSED_TEXTURE_FORMATS;                    break;
        case OpenGL::ContextProperty::Context_Flags:                                 result = GL_CONTEXT_FLAGS;                                 break;
        case OpenGL::ContextProperty::Context_Profile_Mask:                          result = GL_CONTEXT_PROFILE_MASK;                          break;
        case OpenGL::ContextProperty::Cull_Face:                                     result = GL_CULL_FACE;                                     break;
        case OpenGL::ContextProperty::Current_Program:                               result = GL_CURRENT_PROGRAM;                               break;
        case OpenGL::ContextProperty::Depth_Clear_Value:                             result = GL_DEPTH_CLEAR_VALUE;                             break;
        case OpenGL::ContextProperty::Depth_Func:                                    result = GL_DEPTH_FUNC;                                    break;
        case OpenGL::ContextProperty::Depth_Range:                                   result = GL_DEPTH_RANGE;                                   break;
        case OpenGL::ContextProperty::Depth_Test:                                    result = GL_DEPTH_TEST;                                    break;
        case OpenGL::ContextProperty::Depth_Writemask:                               result = GL_DEPTH_WRITEMASK;                               break;
        case OpenGL::ContextProperty::Dither:                                        result = GL_DITHER;                                        break;
        case OpenGL::ContextProperty::Doublebuffer:                                  result = GL_DOUBLEBUFFER;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer:                                   result = GL_DRAW_BUFFER;                                   break;
        case OpenGL::ContextProperty::Draw_Buffer0:                                  result = GL_DRAW_BUFFER0;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer1:                                  result = GL_DRAW_BUFFER1;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer2:                                  result = GL_DRAW_BUFFER2;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer3:                                  result = GL_DRAW_BUFFER3;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer4:                                  result = GL_DRAW_BUFFER4;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer5:                                  result = GL_DRAW_BUFFER5;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer6:                                  result = GL_DRAW_BUFFER6;                                  break;
        case OpenGL::ContextProperty::Draw_Buffer7:                                  result = GL_DRAW_BUFFER7;                                  break;
        case OpenGL::ContextProperty::Draw_Framebuffer_Binding:                      result = GL_DRAW_FRAMEBUFFER_BINDING;                      break;
        case OpenGL::ContextProperty::Element_Array_Buffer_Binding:                  result = GL_ELEMENT_ARRAY_BUFFER_BINDING;                  break;
        case OpenGL::ContextProperty::Extensions:                                    result = GL_EXTENSIONS;                                    break;
        case OpenGL::ContextProperty::Fragment_Shader_Derivative_Hint:               result = GL_FRAGMENT_SHADER_DERIVATIVE_HINT;               break;
        case OpenGL::ContextProperty::Line_Smooth:                                   result = GL_LINE_SMOOTH;                                   break;
        case OpenGL::ContextProperty::Line_Smooth_Hint:                              result = GL_LINE_SMOOTH_HINT;                              break;
        case OpenGL::ContextProperty::Line_Width:                                    result = GL_LINE_WIDTH;                                    break;
        case OpenGL::ContextProperty::Logic_Op_Mode:                                 result = GL_LOGIC_OP_MODE;                                 break;
        case OpenGL::ContextProperty::Major_Version:                                 result = GL_MAJOR_VERSION;                                 break;
        case OpenGL::ContextProperty::Max_3D_Texture_Size:                           result = GL_MAX_3D_TEXTURE_SIZE;                           break;
        case OpenGL::ContextProperty::Max_Array_Texture_Layers:                      result = GL_MAX_ARRAY_TEXTURE_LAYERS;                      break;
        case OpenGL::ContextProperty::Max_Clip_Distances:                            result = GL_MAX_CLIP_DISTANCES;                            break;
        case OpenGL::ContextProperty::Max_Color_Attachments:                         result = GL_MAX_COLOR_ATTACHMENTS;                         break;
        case OpenGL::ContextProperty::Max_Color_Texture_Samples:                     result = GL_MAX_COLOR_TEXTURE_SAMPLES;                     break;
        case OpenGL::ContextProperty::Max_Combined_Fragment_Uniform_Components:      result = GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS;      break;
        case OpenGL::ContextProperty::Max_Combined_Geometry_Uniform_Components:      result = GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS;      break;
        case OpenGL::ContextProperty::Max_Combined_Texture_Image_Units:              result = GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS;              break;
        case OpenGL::ContextProperty::Max_Combined_Uniform_Blocks:                   result = GL_MAX_COMBINED_UNIFORM_BLOCKS;                   break;
        case OpenGL::ContextProperty::Max_Combined_Vertex_Uniform_Components:        result = GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS;        break;
        case OpenGL::ContextProperty::Max_Cube_Map_Texture_Size:                     result = GL_MAX_CUBE_MAP_TEXTURE_SIZE;                     break;
        case OpenGL::ContextProperty::Max_Depth_Texture_Samples:                     result = GL_MAX_DEPTH_TEXTURE_SAMPLES;                     break;
        case OpenGL::ContextProperty::Max_Draw_Buffers:                              result = GL_MAX_DRAW_BUFFERS;                              break;
        case OpenGL::ContextProperty::Max_Dual_Source_Draw_Buffers:                  result = GL_MAX_DUAL_SOURCE_DRAW_BUFFERS;                  break;
        case OpenGL::ContextProperty::Max_Elements_Indices:                          result = GL_MAX_ELEMENTS_INDICES;                          break;
        case OpenGL::ContextProperty::Max_Elements_Vertices:                         result = GL_MAX_ELEMENTS_VERTICES;                         break;
        case OpenGL::ContextProperty::Max_Fragment_Input_Components:                 result = GL_MAX_FRAGMENT_INPUT_COMPONENTS;                 break;
        case OpenGL::ContextProperty::Max_Fragment_Uniform_Blocks:                   result = GL_MAX_FRAGMENT_UNIFORM_BLOCKS;                   break;
        case OpenGL::ContextProperty::Max_Fragment_Uniform_Components:               result = GL_MAX_FRAGMENT_UNIFORM_COMPONENTS;               break;
        case OpenGL::ContextProperty::Max_Geometry_Input_Components:                 result = GL_MAX_GEOMETRY_INPUT_COMPONENTS;                 break;
        case OpenGL::ContextProperty::Max_Geometry_Output_Components:                result = GL_MAX_GEOMETRY_OUTPUT_COMPONENTS;                break;
        case OpenGL::ContextProperty::Max_Geometry_Output_Vertices:                  result = GL_MAX_GEOMETRY_OUTPUT_VERTICES;                  break;
        case OpenGL::ContextProperty::Max_Geometry_Texture_Image_Units:              result = GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS;              break;
        case OpenGL::ContextProperty::Max_Geometry_Total_Output_Components:          result = GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS;          break;
        case OpenGL::ContextProperty::Max_Geometry_Uniform_Blocks:                   result = GL_MAX_GEOMETRY_UNIFORM_BLOCKS;                   break;
        case OpenGL::ContextProperty::Max_Geometry_Uniform_Components:               result = GL_MAX_GEOMETRY_UNIFORM_COMPONENTS;               break;
        case OpenGL::ContextProperty::Max_Integer_Samples:                           result = GL_MAX_INTEGER_SAMPLES;                           break;
        case OpenGL::ContextProperty::Max_Program_Texel_Offset:                      result = GL_MAX_PROGRAM_TEXEL_OFFSET;                      break;
        case OpenGL::ContextProperty::Max_Rectangle_Texture_Size:                    result = GL_MAX_RECTANGLE_TEXTURE_SIZE;                    break;
        case OpenGL::ContextProperty::Max_Renderbuffer_Size:                         result = GL_MAX_RENDERBUFFER_SIZE;                         break;
        case OpenGL::ContextProperty::Max_Sample_Mask_Words:                         result = GL_MAX_SAMPLE_MASK_WORDS;                         break;
        case OpenGL::ContextProperty::Max_Samples:                                   result = GL_MAX_SAMPLES;                                   break;
        case OpenGL::ContextProperty::Max_Server_Wait_Timeout:                       result = GL_MAX_SERVER_WAIT_TIMEOUT;                       break;
        case OpenGL::ContextProperty::Max_Texture_Buffer_Size:                       result = GL_MAX_TEXTURE_BUFFER_SIZE;                       break;
        case OpenGL::ContextProperty::Max_Texture_Image_Units:                       result = GL_MAX_TEXTURE_IMAGE_UNITS;                       break;
        case OpenGL::ContextProperty::Max_Texture_LOD_Bias:                          result = GL_MAX_TEXTURE_LOD_BIAS;                          break;
        case OpenGL::ContextProperty::Max_Texture_Size:                              result = GL_MAX_TEXTURE_SIZE;                              break;
        case OpenGL::ContextProperty::Max_Transform_Feedback_Buffers:                result = GL_MAX_TRANSFORM_FEEDBACK_BUFFERS;                break;
        case OpenGL::ContextProperty::Max_Transform_Feedback_Interleaved_Components: result = GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS; break;
        case OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Attribs:       result = GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS;       break;
        case OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Components:    result = GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS;    break;
        case OpenGL::ContextProperty::Max_Uniform_Block_Size:                        result = GL_MAX_UNIFORM_BLOCK_SIZE;                        break;
        case OpenGL::ContextProperty::Max_Uniform_Buffer_Bindings:                   result = GL_MAX_UNIFORM_BUFFER_BINDINGS;                   break;
        case OpenGL::ContextProperty::Max_Varying_Components:                        result = GL_MAX_VARYING_COMPONENTS;                        break;
        case OpenGL::ContextProperty::Max_Vertex_Attribs:                            result = GL_MAX_VERTEX_ATTRIBS;                            break;
        case OpenGL::ContextProperty::Max_Vertex_Output_Components:                  result = GL_MAX_VERTEX_OUTPUT_COMPONENTS;                  break;
        case OpenGL::ContextProperty::Max_Vertex_Texture_Image_Units:                result = GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS;                break;
        case OpenGL::ContextProperty::Max_Vertex_Uniform_Blocks:                     result = GL_MAX_VERTEX_UNIFORM_BLOCKS;                     break;
        case OpenGL::ContextProperty::Max_Vertex_Uniform_Components:                 result = GL_MAX_VERTEX_UNIFORM_COMPONENTS;                 break;
        case OpenGL::ContextProperty::Max_Viewport_Dims:                             result = GL_MAX_VIEWPORT_DIMS;                             break;
        case OpenGL::ContextProperty::Minor_Version:                                 result = GL_MINOR_VERSION;                                 break;
        case OpenGL::ContextProperty::Min_Program_Texel_Offset:                      result = GL_MIN_PROGRAM_TEXEL_OFFSET;                      break;
        case OpenGL::ContextProperty::Num_Compressed_Texture_Formats:                result = GL_NUM_COMPRESSED_TEXTURE_FORMATS;                break;
        case OpenGL::ContextProperty::Num_Extensions:                                result = GL_NUM_EXTENSIONS;                                break;
        case OpenGL::ContextProperty::Pack_Alignment:                                result = GL_PACK_ALIGNMENT;                                break;
        case OpenGL::ContextProperty::Pack_Image_Height:                             result = GL_PACK_IMAGE_HEIGHT;                             break;
        case OpenGL::ContextProperty::Pack_LSB_First:                                result = GL_PACK_LSB_FIRST;                                break;
        case OpenGL::ContextProperty::Pack_Row_Length:                               result = GL_PACK_ROW_LENGTH;                               break;
        case OpenGL::ContextProperty::Pack_Skip_Images:                              result = GL_PACK_SKIP_IMAGES;                              break;
        case OpenGL::ContextProperty::Pack_Skip_Pixels:                              result = GL_PACK_SKIP_PIXELS;                              break;
        case OpenGL::ContextProperty::Pack_Skip_Rows:                                result = GL_PACK_SKIP_ROWS;                                break;
        case OpenGL::ContextProperty::Pack_Swap_Bytes:                               result = GL_PACK_SWAP_BYTES;                               break;
        case OpenGL::ContextProperty::Pixel_Pack_Buffer_Binding:                     result = GL_PIXEL_PACK_BUFFER_BINDING;                     break;
        case OpenGL::ContextProperty::Pixel_Unpack_Buffer_Binding:                   result = GL_PIXEL_UNPACK_BUFFER_BINDING;                   break;
        case OpenGL::ContextProperty::Point_Fade_Threshold_Size:                     result = GL_POINT_FADE_THRESHOLD_SIZE;                     break;
        case OpenGL::ContextProperty::Point_Size:                                    result = GL_POINT_SIZE;                                    break;
        case OpenGL::ContextProperty::Point_Size_Granularity:                        result = GL_POINT_SIZE_GRANULARITY;                        break;
        case OpenGL::ContextProperty::Point_Size_Range:                              result = GL_POINT_SIZE_RANGE;                              break;
        case OpenGL::ContextProperty::Polygon_Offset_Factor:                         result = GL_POLYGON_OFFSET_FACTOR;                         break;
        case OpenGL::ContextProperty::Polygon_Offset_Fill:                           result = GL_POLYGON_OFFSET_FILL;                           break;
        case OpenGL::ContextProperty::Polygon_Offset_Line:                           result = GL_POLYGON_OFFSET_LINE;                           break;
        case OpenGL::ContextProperty::Polygon_Offset_Point:                          result = GL_POLYGON_OFFSET_POINT;                          break;
        case OpenGL::ContextProperty::Polygon_Offset_Units:                          result = GL_POLYGON_OFFSET_UNITS;                          break;
        case OpenGL::ContextProperty::Polygon_Smooth:                                result = GL_POLYGON_SMOOTH;                                break;
        case OpenGL::ContextProperty::Polygon_Smooth_Hint:                           result = GL_POLYGON_SMOOTH_HINT;                           break;
        case OpenGL::ContextProperty::Primitive_Restart_Index:                       result = GL_PRIMITIVE_RESTART_INDEX;                       break;
        case OpenGL::ContextProperty::Program_Point_Size:                            result = GL_PROGRAM_POINT_SIZE;                            break;
        case OpenGL::ContextProperty::Provoking_Vertex:                              result = GL_PROVOKING_VERTEX;                              break;
        case OpenGL::ContextProperty::Query_Counter_Bits:                            result = GL_QUERY_COUNTER_BITS;                            break;
        case OpenGL::ContextProperty::Read_Buffer:                                   result = GL_READ_BUFFER;                                   break;
        case OpenGL::ContextProperty::Read_Framebuffer_Binding:                      result = GL_READ_FRAMEBUFFER_BINDING;                      break;
        case OpenGL::ContextProperty::Renderer:                                      result = GL_RENDERER;                                      break;
        case OpenGL::ContextProperty::Renderbuffer_Binding:                          result = GL_RENDERBUFFER_BINDING;                          break;
        case OpenGL::ContextProperty::Sampler_Binding:                               result = GL_SAMPLER_BINDING;                               break;
        case OpenGL::ContextProperty::Samples:                                       result = GL_SAMPLES;                                       break;
        case OpenGL::ContextProperty::Sample_Buffers:                                result = GL_SAMPLE_BUFFERS;                                break;
        case OpenGL::ContextProperty::Sample_Coverage_Invert:                        result = GL_SAMPLE_COVERAGE_INVERT;                        break;
        case OpenGL::ContextProperty::Sample_Coverage_Value:                         result = GL_SAMPLE_COVERAGE_VALUE;                         break;
        case OpenGL::ContextProperty::Scissor_Box:                                   result = GL_SCISSOR_BOX;                                   break;
        case OpenGL::ContextProperty::Scissor_Test:                                  result = GL_SCISSOR_TEST;                                  break;
        case OpenGL::ContextProperty::Shading_Language_Version:                      result = GL_SHADING_LANGUAGE_VERSION;                      break;
        case OpenGL::ContextProperty::Smooth_Line_Width_Granularity:                 result = GL_SMOOTH_LINE_WIDTH_GRANULARITY;                 break;
        case OpenGL::ContextProperty::Smooth_Line_Width_Range:                       result = GL_SMOOTH_LINE_WIDTH_RANGE;                       break;
        case OpenGL::ContextProperty::Stencil_Back_Fail:                             result = GL_STENCIL_BACK_FAIL;                             break;
        case OpenGL::ContextProperty::Stencil_Back_Func:                             result = GL_STENCIL_BACK_FUNC;                             break;
        case OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Fail:                  result = GL_STENCIL_BACK_PASS_DEPTH_FAIL;                  break;
        case OpenGL::ContextProperty::Stencil_Back_Pass_Depth_Pass:                  result = GL_STENCIL_BACK_PASS_DEPTH_PASS;                  break;
        case OpenGL::ContextProperty::Stencil_Back_Ref:                              result = GL_STENCIL_BACK_REF;                              break;
        case OpenGL::ContextProperty::Stencil_Back_Value_Mask:                       result = GL_STENCIL_BACK_VALUE_MASK;                       break;
        case OpenGL::ContextProperty::Stencil_Back_Writemask:                        result = GL_STENCIL_BACK_WRITEMASK;                        break;
        case OpenGL::ContextProperty::Stencil_Clear_Value:                           result = GL_STENCIL_CLEAR_VALUE;                           break;
        case OpenGL::ContextProperty::Stencil_Fail:                                  result = GL_STENCIL_FAIL;                                  break;
        case OpenGL::ContextProperty::Stencil_Func:                                  result = GL_STENCIL_FUNC;                                  break;
        case OpenGL::ContextProperty::Stencil_Pass_Depth_Fail:                       result = GL_STENCIL_PASS_DEPTH_FAIL;                       break;
        case OpenGL::ContextProperty::Stencil_Pass_Depth_Pass:                       result = GL_STENCIL_PASS_DEPTH_PASS;                       break;
        case OpenGL::ContextProperty::Stencil_Ref:                                   result = GL_STENCIL_REF;                                   break;
        case OpenGL::ContextProperty::Stencil_Test:                                  result = GL_STENCIL_TEST;                                  break;
        case OpenGL::ContextProperty::Stencil_Value_Mask:                            result = GL_STENCIL_VALUE_MASK;                            break;
        case OpenGL::ContextProperty::Stencil_Writemask:                             result = GL_STENCIL_WRITEMASK;                             break;
        case OpenGL::ContextProperty::Stereo:                                        result = GL_STEREO;                                        break;
        case OpenGL::ContextProperty::Subpixel_Bits:                                 result = GL_SUBPIXEL_BITS;                                 break;
        case OpenGL::ContextProperty::Texture_Binding_1D:                            result = GL_TEXTURE_BINDING_1D;                            break;
        case OpenGL::ContextProperty::Texture_Binding_1D_Array:                      result = GL_TEXTURE_BINDING_1D_ARRAY;                      break;
        case OpenGL::ContextProperty::Texture_Binding_2D:                            result = GL_TEXTURE_BINDING_2D;                            break;
        case OpenGL::ContextProperty::Texture_Binding_2D_Array:                      result = GL_TEXTURE_BINDING_2D_ARRAY;                      break;
        case OpenGL::ContextProperty::Texture_Binding_2D_Multisample:                result = GL_TEXTURE_BINDING_2D_MULTISAMPLE;                break;
        case OpenGL::ContextProperty::Texture_Binding_2D_Multisample_Array:          result = GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY;          break;
        case OpenGL::ContextProperty::Texture_Binding_3D:                            result = GL_TEXTURE_BINDING_3D;                            break;
        case OpenGL::ContextProperty::Texture_Binding_Buffer:                        result = GL_TEXTURE_BINDING_BUFFER;                        break;
        case OpenGL::ContextProperty::Texture_Binding_Cube_Map:                      result = GL_TEXTURE_BINDING_CUBE_MAP;                      break;
        case OpenGL::ContextProperty::Texture_Binding_Rectangle:                     result = GL_TEXTURE_BINDING_RECTANGLE;                     break;
        case OpenGL::ContextProperty::Texture_Compression_Hint:                      result = GL_TEXTURE_COMPRESSION_HINT;                      break;
        case OpenGL::ContextProperty::Timestamp:                                     result = GL_TIMESTAMP;                                     break;
        case OpenGL::ContextProperty::Transform_Feedback_Buffer_Binding:             result = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING;             break;
        case OpenGL::ContextProperty::Transform_Feedback_Buffer_Size:                result = GL_TRANSFORM_FEEDBACK_BUFFER_SIZE;                break;
        case OpenGL::ContextProperty::Transform_Feedback_Buffer_Start:               result = GL_TRANSFORM_FEEDBACK_BUFFER_START;               break;
        case OpenGL::ContextProperty::Uniform_Buffer_Binding:                        result = GL_UNIFORM_BUFFER_BINDING;                        break;
        case OpenGL::ContextProperty::Uniform_Buffer_Offset_Alignment:               result = GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT;               break;
        case OpenGL::ContextProperty::Uniform_Buffer_Size:                           result = GL_UNIFORM_BUFFER_SIZE;                           break;
        case OpenGL::ContextProperty::Uniform_Buffer_Start:                          result = GL_UNIFORM_BUFFER_START;                          break;
        case OpenGL::ContextProperty::Unpack_Alignment:                              result = GL_UNPACK_ALIGNMENT;                              break;
        case OpenGL::ContextProperty::Unpack_Image_Height:                           result = GL_UNPACK_IMAGE_HEIGHT;                           break;
        case OpenGL::ContextProperty::Unpack_LSB_First:                              result = GL_UNPACK_LSB_FIRST;                              break;
        case OpenGL::ContextProperty::Unpack_Row_Length:                             result = GL_UNPACK_ROW_LENGTH;                             break;
        case OpenGL::ContextProperty::Unpack_Skip_Images:                            result = GL_UNPACK_SKIP_IMAGES;                            break;
        case OpenGL::ContextProperty::Unpack_Skip_Pixels:                            result = GL_UNPACK_SKIP_PIXELS;                            break;
        case OpenGL::ContextProperty::Unpack_Skip_Rows:                              result = GL_UNPACK_SKIP_ROWS;                              break;
        case OpenGL::ContextProperty::Unpack_Swap_Bytes:                             result = GL_UNPACK_SWAP_BYTES;                             break;
        case OpenGL::ContextProperty::Version:                                       result = GL_VERSION;                                       break;
        case OpenGL::ContextProperty::Viewport:                                      result = GL_VIEWPORT;                                      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_error_code(const OpenGL::ErrorCode& in_error)
{
    GLenum result = 0;

    switch (in_error)
    {
        case OpenGL::ErrorCode::Invalid_Enum:                  result = GL_INVALID_ENUM;                  break;
        case OpenGL::ErrorCode::Invalid_Framebuffer_Operation: result = GL_INVALID_FRAMEBUFFER_OPERATION; break;
        case OpenGL::ErrorCode::Invalid_Operation:             result = GL_INVALID_OPERATION;             break;
        case OpenGL::ErrorCode::Invalid_Value:                 result = GL_INVALID_VALUE;                 break;
        case OpenGL::ErrorCode::No_Error:                      result = GL_NO_ERROR;                      break;
        case OpenGL::ErrorCode::Out_Of_Memory:                 result = GL_OUT_OF_MEMORY;                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::CullMode OpenGL::Utils::get_cull_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::CullMode result = OpenGL::CullMode::Unknown;

    switch (in_enum)
    {
        case GL_BACK:           result = OpenGL::CullMode::Back;       break;
        case GL_FRONT:          result = OpenGL::CullMode::Front;      break;
        case GL_FRONT_AND_BACK: result = OpenGL::CullMode::Front_Back; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::DepthFunction OpenGL::Utils::get_depth_function_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::DepthFunction result = OpenGL::DepthFunction::Unknown;

    switch (in_enum)
    {
        case GL_ALWAYS:   result = OpenGL::DepthFunction::Always;   break;
        case GL_EQUAL:    result = OpenGL::DepthFunction::Equal;    break;
        case GL_GEQUAL:   result = OpenGL::DepthFunction::GEqual;   break;
        case GL_GREATER:  result = OpenGL::DepthFunction::Greater;  break;
        case GL_LEQUAL:   result = OpenGL::DepthFunction::LEqual;   break;
        case GL_LESS:     result = OpenGL::DepthFunction::Less;     break;
        case GL_NEVER:    result = OpenGL::DepthFunction::Never;    break;
        case GL_NOTEQUAL: result = OpenGL::DepthFunction::NotEqual; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::DepthStencilTextureMode OpenGL::Utils::get_depth_stencil_texture_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::DepthStencilTextureMode result = OpenGL::DepthStencilTextureMode::Unknown;

    switch (in_enum)
    {
        case GL_DEPTH_COMPONENT: result = OpenGL::DepthStencilTextureMode::Depth_Component; break;
        case GL_STENCIL_INDEX:   result = OpenGL::DepthStencilTextureMode::Stencil_Index;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::DrawBuffer OpenGL::Utils::get_draw_buffer_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::DrawBuffer result = OpenGL::DrawBuffer::Unknown;

    switch (in_enum)
    {
        case GL_BACK:              result = OpenGL::DrawBuffer::Back;              break;
        case GL_BACK_LEFT:         result = OpenGL::DrawBuffer::Back_Left;         break;
        case GL_BACK_RIGHT:        result = OpenGL::DrawBuffer::Back_Right;        break;
        case GL_COLOR_ATTACHMENT0: result = OpenGL::DrawBuffer::Color_Attachment0; break;
        case GL_COLOR_ATTACHMENT1: result = OpenGL::DrawBuffer::Color_Attachment1; break;
        case GL_COLOR_ATTACHMENT2: result = OpenGL::DrawBuffer::Color_Attachment2; break;
        case GL_COLOR_ATTACHMENT3: result = OpenGL::DrawBuffer::Color_Attachment3; break;
        case GL_COLOR_ATTACHMENT4: result = OpenGL::DrawBuffer::Color_Attachment4; break;
        case GL_COLOR_ATTACHMENT5: result = OpenGL::DrawBuffer::Color_Attachment5; break;
        case GL_COLOR_ATTACHMENT6: result = OpenGL::DrawBuffer::Color_Attachment6; break;
        case GL_COLOR_ATTACHMENT7: result = OpenGL::DrawBuffer::Color_Attachment7; break;
        case GL_FRONT:             result = OpenGL::DrawBuffer::Front;             break;
        case GL_FRONT_AND_BACK:    result = OpenGL::DrawBuffer::Front_And_Back;    break;
        case GL_FRONT_LEFT:        result = OpenGL::DrawBuffer::Front_Left;        break;
        case GL_FRONT_RIGHT:       result = OpenGL::DrawBuffer::Front_Right;       break;
        case GL_LEFT:              result = OpenGL::DrawBuffer::Left;              break;
        case GL_RIGHT:             result = OpenGL::DrawBuffer::Right;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FramebufferAttachmentComponentType OpenGL::Utils::get_framebuffer_attachment_component_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FramebufferAttachmentComponentType result = OpenGL::FramebufferAttachmentComponentType::Unknown;

    switch (in_enum)
    {
        case GL_FLOAT:               result = OpenGL::FramebufferAttachmentComponentType::Float;               break;
        case GL_INT:                 result = OpenGL::FramebufferAttachmentComponentType::Int;                 break;
        case GL_NONE:                result = OpenGL::FramebufferAttachmentComponentType::None;                break;
        case GL_SIGNED_NORMALIZED:   result = OpenGL::FramebufferAttachmentComponentType::Signed_Normalized;   break;
        case GL_UNSIGNED_INT:        result = OpenGL::FramebufferAttachmentComponentType::Unsigned_Int;        break;
        case GL_UNSIGNED_NORMALIZED: result = OpenGL::FramebufferAttachmentComponentType::Unsigned_Normalized; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FramebufferAttachmentObjectType OpenGL::Utils::get_framebuffer_attachment_object_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FramebufferAttachmentObjectType result = OpenGL::FramebufferAttachmentObjectType::Unknown;

    switch (in_enum)
    {
        case GL_FRAMEBUFFER_DEFAULT: result = OpenGL::FramebufferAttachmentObjectType::Framebuffer_Default; break;
        case GL_NONE:                result = OpenGL::FramebufferAttachmentObjectType::None;                break;
        case GL_RENDERBUFFER:        result = OpenGL::FramebufferAttachmentObjectType::Renderbuffer;        break;
        case GL_TEXTURE:             result = OpenGL::FramebufferAttachmentObjectType::Texture;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FramebufferAttachmentPoint OpenGL::Utils::get_framebuffer_attachment_point_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FramebufferAttachmentPoint result = OpenGL::FramebufferAttachmentPoint::Unknown;

    switch (in_enum)
    {
        case GL_COLOR_ATTACHMENT0:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment0;        break;
        case GL_COLOR_ATTACHMENT1:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment1;        break;
        case GL_COLOR_ATTACHMENT2:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment2;        break;
        case GL_COLOR_ATTACHMENT3:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment3;        break;
        case GL_COLOR_ATTACHMENT4:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment4;        break;
        case GL_COLOR_ATTACHMENT5:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment5;        break;
        case GL_COLOR_ATTACHMENT6:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment6;        break;
        case GL_COLOR_ATTACHMENT7:        result = OpenGL::FramebufferAttachmentPoint::Color_Attachment7;        break;
        case GL_DEPTH_ATTACHMENT:         result = OpenGL::FramebufferAttachmentPoint::Depth_Attachment;         break;
        case GL_DEPTH_STENCIL_ATTACHMENT: result = OpenGL::FramebufferAttachmentPoint::Depth_Stencil_Attachment; break;
        case GL_STENCIL_ATTACHMENT:       result = OpenGL::FramebufferAttachmentPoint::Stencil_Attachment;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FramebufferAttachmentProperty OpenGL::Utils::get_framebuffer_attachment_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FramebufferAttachmentProperty result = OpenGL::FramebufferAttachmentProperty::Unknown;

    switch (in_enum)
    {
        case GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE:            result = OpenGL::FramebufferAttachmentProperty::Alpha_Size;             break;
        case GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE:             result = OpenGL::FramebufferAttachmentProperty::Blue_Size;              break;
        case GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING:        result = OpenGL::FramebufferAttachmentProperty::Color_Encoding;         break;
        case GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE:        result = OpenGL::FramebufferAttachmentProperty::Component_Type;         break;
        case GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE:            result = OpenGL::FramebufferAttachmentProperty::Depth_Size;             break;
        case GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE:            result = OpenGL::FramebufferAttachmentProperty::Green_Size;             break;
        case GL_FRAMEBUFFER_ATTACHMENT_LAYERED:               result = OpenGL::FramebufferAttachmentProperty::Layered;                break;
        case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME:           result = OpenGL::FramebufferAttachmentProperty::Object_Name;            break;
        case GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE:           result = OpenGL::FramebufferAttachmentProperty::Object_Type;            break;
        case GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE:              result = OpenGL::FramebufferAttachmentProperty::Red_Size;               break;
        case GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE:          result = OpenGL::FramebufferAttachmentProperty::Stencil_Size;           break;
        case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE: result = OpenGL::FramebufferAttachmentProperty::Texture_Cube_Map_Face;  break;
        case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER:         result = OpenGL::FramebufferAttachmentProperty::Texture_Layer;          break;
        case GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL:         result = OpenGL::FramebufferAttachmentProperty::Texture_Level;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FramebufferTarget OpenGL::Utils::get_framebuffer_target_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FramebufferTarget result = OpenGL::FramebufferTarget::Unknown;

    switch (in_enum)
    {
        case GL_DRAW_FRAMEBUFFER: result = OpenGL::FramebufferTarget::Draw_Framebuffer; break;
        case GL_FRAMEBUFFER:      result = OpenGL::FramebufferTarget::Framebuffer;      break;
        case GL_READ_FRAMEBUFFER: result = OpenGL::FramebufferTarget::Read_Framebuffer; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::FrontFaceOrientation OpenGL::Utils::get_front_face_orientation_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::FrontFaceOrientation result = OpenGL::FrontFaceOrientation::Unknown;

    switch (in_enum)
    {
        case GL_CW:  result = OpenGL::FrontFaceOrientation::Clockwise;         break;
        case GL_CCW: result = OpenGL::FrontFaceOrientation::Counter_Clockwise; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::GeometryInputType OpenGL::Utils::get_geometry_input_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::GeometryInputType result = OpenGL::GeometryInputType::Unknown;

    switch (in_enum)
    {
        case GL_LINES:               result = OpenGL::GeometryInputType::Lines;               break;
        case GL_LINES_ADJACENCY:     result = OpenGL::GeometryInputType::Lines_Adjacency;     break;
        case GL_POINTS:              result = OpenGL::GeometryInputType::Points;              break;
        case GL_TRIANGLES:           result = OpenGL::GeometryInputType::Triangles;           break;
        case GL_TRIANGLES_ADJACENCY: result = OpenGL::GeometryInputType::Triangles_Adjacency; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::GeometryOutputType OpenGL::Utils::get_geometry_output_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::GeometryOutputType result = OpenGL::GeometryOutputType::Unknown;

    switch (in_enum)
    {
        case GL_LINE_STRIP:     result = OpenGL::GeometryOutputType::Line_Strip;     break;
        case GL_POINTS:         result = OpenGL::GeometryOutputType::Points;         break;
        case GL_TRIANGLE_STRIP: result = OpenGL::GeometryOutputType::Triangle_Strip; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_buffer_pointer_property(const OpenGL::BufferPointerProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::BufferPointerProperty::Buffer_Map_Pointer: result = GL_BUFFER_MAP_POINTER; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_buffer_property(const OpenGL::BufferProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::BufferProperty::Buffer_Access: result = GL_BUFFER_ACCESS; break;
        case OpenGL::BufferProperty::Buffer_Mapped: result = GL_BUFFER_MAPPED; break;
        case OpenGL::BufferProperty::Buffer_Size:   result = GL_BUFFER_SIZE;   break;
        case OpenGL::BufferProperty::Buffer_Usage:  result = GL_BUFFER_USAGE;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_geometry_input_type(const OpenGL::GeometryInputType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::GeometryInputType::Lines:               result = GL_LINES;               break;
        case OpenGL::GeometryInputType::Lines_Adjacency:     result = GL_LINES_ADJACENCY;     break;
        case OpenGL::GeometryInputType::Points:              result = GL_POINTS;              break;
        case OpenGL::GeometryInputType::Triangles:           result = GL_TRIANGLES;           break;
        case OpenGL::GeometryInputType::Triangles_Adjacency: result = GL_TRIANGLES_ADJACENCY; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_geometry_output_type(const OpenGL::GeometryOutputType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::GeometryOutputType::Line_Strip:     result = GL_LINE_STRIP;     break;
        case OpenGL::GeometryOutputType::Points:         result = GL_POINTS;         break;
        case OpenGL::GeometryOutputType::Triangle_Strip: result = GL_TRIANGLE_STRIP; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_blend_equation(const OpenGL::BlendEquation& in_blend_equation)
{
    GLenum result = 0;

    switch (in_blend_equation)
    {
        case OpenGL::BlendEquation::Function_Add:              result = GL_FUNC_ADD;              break;
        case OpenGL::BlendEquation::Function_Reverse_Subtract: result = GL_FUNC_REVERSE_SUBTRACT; break;
        case OpenGL::BlendEquation::Function_Subtract:         result = GL_FUNC_SUBTRACT;         break;
        case OpenGL::BlendEquation::Max:                       result = GL_MAX;                   break;
        case OpenGL::BlendEquation::Min:                       result = GL_MIN;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_blend_function(const OpenGL::BlendFunction& in_blend_func)
{
    GLenum result = 0;

    switch (in_blend_func)
    {
        case OpenGL::BlendFunction::Constant_Alpha:           result = GL_CONSTANT_ALPHA;           break;
        case OpenGL::BlendFunction::Constant_Color:           result = GL_CONSTANT_COLOR;           break;
        case OpenGL::BlendFunction::Dst_Alpha:                result = GL_DST_ALPHA;                break;
        case OpenGL::BlendFunction::Dst_Color:                result = GL_DST_COLOR;                break;
        case OpenGL::BlendFunction::One:                      result = GL_ONE;                      break;
        case OpenGL::BlendFunction::One_Minus_Constant_Alpha: result = GL_ONE_MINUS_CONSTANT_ALPHA; break;
        case OpenGL::BlendFunction::One_Minus_Constant_Color: result = GL_ONE_MINUS_CONSTANT_COLOR; break;
        case OpenGL::BlendFunction::One_Minus_Dst_Alpha:      result = GL_ONE_MINUS_DST_ALPHA;      break;
        case OpenGL::BlendFunction::One_Minus_Dst_Color:      result = GL_ONE_MINUS_DST_COLOR;      break;
        case OpenGL::BlendFunction::One_Minus_Src_Alpha:      result = GL_ONE_MINUS_SRC_ALPHA;      break;
        case OpenGL::BlendFunction::One_Minus_Src_Color:      result = GL_ONE_MINUS_SRC_COLOR;      break;
        case OpenGL::BlendFunction::Src_Alpha:                result = GL_SRC_ALPHA;                break;
        case OpenGL::BlendFunction::Src_Alpha_Saturate:       result = GL_SRC_ALPHA_SATURATE;       break;
        case OpenGL::BlendFunction::Src_Color:                result = GL_SRC_COLOR;                break;
        case OpenGL::BlendFunction::Zero:                     result = GL_ZERO;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_blit_filter(const OpenGL::BlitFilter& in_filter)
{
    GLenum result = 0;

    switch (in_filter)
    {
        case OpenGL::BlitFilter::Linear:  result = GL_LINEAR;  break;
        case OpenGL::BlitFilter::Nearest: result = GL_NEAREST; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_blit_mask_bits(const OpenGL::BlitMaskBits& in_bits)
{
    GLenum result = 0;

    if (in_bits & OpenGL::BlitMaskBit::BLIT_MASK_BIT_COLOR_BUFFER)
    {
        result |= GL_COLOR_BUFFER_BIT;
    }

    if (in_bits & OpenGL::BlitMaskBit::BLIT_MASK_BIT_DEPTH_BUFFER)
    {
        result |= GL_DEPTH_BUFFER_BIT;
    }

    if (in_bits & OpenGL::BlitMaskBit::BLIT_MASK_BIT_STENCIL_BUFFER)
    {
        result |= GL_STENCIL_BUFFER_BIT;
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_buffer_access(const OpenGL::BufferAccess& in_access)
{
    GLenum result = 0;

    switch (in_access)
    {
        case OpenGL::BufferAccess::Read_Only:  result = GL_READ_ONLY;  break;
        case OpenGL::BufferAccess::Read_Write: result = GL_READ_WRITE; break;
        case OpenGL::BufferAccess::Write_Only: result = GL_WRITE_ONLY; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_buffer_target(const OpenGL::BufferTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case OpenGL::BufferTarget::Array_Buffer:              result = GL_ARRAY_BUFFER;              break;
        case OpenGL::BufferTarget::Copy_Read_Buffer:          result = GL_COPY_READ_BUFFER;          break;
        case OpenGL::BufferTarget::Copy_Write_Buffer:         result = GL_COPY_WRITE_BUFFER;         break;
        case OpenGL::BufferTarget::Element_Array_Buffer:      result = GL_ELEMENT_ARRAY_BUFFER;      break;
        case OpenGL::BufferTarget::Pixel_Pack_Buffer:         result = GL_PIXEL_PACK_BUFFER;         break;
        case OpenGL::BufferTarget::Pixel_Unpack_Buffer:       result = GL_PIXEL_UNPACK_BUFFER;       break;
        case OpenGL::BufferTarget::Texture_Buffer:            result = GL_TEXTURE_BUFFER;            break;
        case OpenGL::BufferTarget::Transform_Feedback_Buffer: result = GL_TRANSFORM_FEEDBACK_BUFFER; break;
        case OpenGL::BufferTarget::Uniform_Buffer:            result = GL_UNIFORM_BUFFER;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_buffer_usage(const OpenGL::BufferUsage& in_usage)
{
    GLenum result = 0;

    switch (in_usage)
    {
        case OpenGL::BufferUsage::Dynamic_Copy: result = GL_DYNAMIC_COPY; break;
        case OpenGL::BufferUsage::Dynamic_Draw: result = GL_DYNAMIC_DRAW; break;
        case OpenGL::BufferUsage::Dynamic_Read: result = GL_DYNAMIC_READ; break;
        case OpenGL::BufferUsage::Static_Copy:  result = GL_STATIC_COPY;  break;
        case OpenGL::BufferUsage::Static_Draw:  result = GL_STATIC_DRAW;  break;
        case OpenGL::BufferUsage::Static_Read:  result = GL_STATIC_READ;  break;
        case OpenGL::BufferUsage::Stream_Copy:  result = GL_STREAM_COPY;  break;
        case OpenGL::BufferUsage::Stream_Draw:  result = GL_STREAM_DRAW;  break;
        case OpenGL::BufferUsage::Stream_Read:  result = GL_STREAM_READ;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_clamp_read_color_mode(const OpenGL::ClampReadColorMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case OpenGL::ClampReadColorMode::False:      result = GL_FALSE;      break;
        case OpenGL::ClampReadColorMode::Fixed_Only: result = GL_FIXED_ONLY; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_clear_buffer(const OpenGL::ClearBuffer& in_clear_buffer)
{
    GLenum result = 0;

    switch (in_clear_buffer)
    {
        case OpenGL::ClearBuffer::Back:           result = GL_BACK;           break;
        case OpenGL::ClearBuffer::Color:          result = GL_COLOR;          break;
        case OpenGL::ClearBuffer::Depth:          result = GL_DEPTH;          break;
        case OpenGL::ClearBuffer::Depth_Stencil:  result = GL_DEPTH_STENCIL;  break;
        case OpenGL::ClearBuffer::Front:          result = GL_FRONT;          break;
        case OpenGL::ClearBuffer::Front_And_Back: result = GL_FRONT_AND_BACK; break;
        case OpenGL::ClearBuffer::Left:           result = GL_LEFT;           break;
        case OpenGL::ClearBuffer::Right:          result = GL_RIGHT;          break;
        case OpenGL::ClearBuffer::Stencil:        result = GL_STENCIL;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_clear_buffer_bits(const OpenGL::ClearBufferBits& in_buffers)
{
    GLenum result = 0;

    if (in_buffers & OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_COLOR)
    {
        result |= GL_COLOR_BUFFER_BIT;
    }

    if (in_buffers & OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_DEPTH)
    {
        result |= GL_DEPTH_BUFFER_BIT;
    }

    if (in_buffers & OpenGL::ClearBufferBit::CLEAR_BUFFER_BIT_STENCIL)
    {
        result |= GL_STENCIL_BUFFER_BIT;
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_conditional_render_mode(const OpenGL::ConditionalRenderMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case OpenGL::ConditionalRenderMode::Query_By_Region_No_Wait: result = GL_QUERY_BY_REGION_NO_WAIT; break;
        case OpenGL::ConditionalRenderMode::Query_By_Region_Wait:    result = GL_QUERY_BY_REGION_WAIT;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_cull_mode(const OpenGL::CullMode& in_cull_mode)
{
    GLenum result = 0;

    switch (in_cull_mode)
    {
        case OpenGL::CullMode::Back:       result = GL_BACK;           break;
        case OpenGL::CullMode::Front:      result = GL_FRONT;          break;
        case OpenGL::CullMode::Front_Back: result = GL_FRONT_AND_BACK; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_depth_function(const OpenGL::DepthFunction& in_depth_function)
{
    GLenum result = 0;

    switch (in_depth_function)
    {
        case OpenGL::DepthFunction::Always:   result = GL_ALWAYS;   break;
        case OpenGL::DepthFunction::Equal:    result = GL_EQUAL;    break;
        case OpenGL::DepthFunction::GEqual:   result = GL_GEQUAL;   break;
        case OpenGL::DepthFunction::Greater:  result = GL_GREATER;  break;
        case OpenGL::DepthFunction::LEqual:   result = GL_LEQUAL;   break;
        case OpenGL::DepthFunction::Less:     result = GL_LESS;     break;
        case OpenGL::DepthFunction::Never:    result = GL_NEVER;    break;
        case OpenGL::DepthFunction::NotEqual: result = GL_NOTEQUAL; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_depth_stencil_texture_mode(const OpenGL::DepthStencilTextureMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case OpenGL::DepthStencilTextureMode::Depth_Component: result = GL_DEPTH_COMPONENT; break;
        case OpenGL::DepthStencilTextureMode::Stencil_Index:   result = GL_STENCIL_INDEX;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_draw_buffer(const OpenGL::DrawBuffer& in_draw_buffer)
{
    GLenum result = 0;

    switch (in_draw_buffer)
    {
        case OpenGL::DrawBuffer::Back:              result = GL_BACK;              break;
        case OpenGL::DrawBuffer::Back_Left:         result = GL_BACK_LEFT;         break;
        case OpenGL::DrawBuffer::Back_Right:        result = GL_BACK_RIGHT;        break;
        case OpenGL::DrawBuffer::Color_Attachment0: result = GL_COLOR_ATTACHMENT0; break;
        case OpenGL::DrawBuffer::Color_Attachment1: result = GL_COLOR_ATTACHMENT1; break;
        case OpenGL::DrawBuffer::Color_Attachment2: result = GL_COLOR_ATTACHMENT2; break;
        case OpenGL::DrawBuffer::Color_Attachment3: result = GL_COLOR_ATTACHMENT3; break;
        case OpenGL::DrawBuffer::Color_Attachment4: result = GL_COLOR_ATTACHMENT4; break;
        case OpenGL::DrawBuffer::Color_Attachment5: result = GL_COLOR_ATTACHMENT5; break;
        case OpenGL::DrawBuffer::Color_Attachment6: result = GL_COLOR_ATTACHMENT6; break;
        case OpenGL::DrawBuffer::Color_Attachment7: result = GL_COLOR_ATTACHMENT7; break;
        case OpenGL::DrawBuffer::Front:             result = GL_FRONT;             break;
        case OpenGL::DrawBuffer::Front_And_Back:    result = GL_FRONT_AND_BACK;    break;
        case OpenGL::DrawBuffer::Front_Left:        result = GL_FRONT_LEFT;        break;
        case OpenGL::DrawBuffer::Front_Right:       result = GL_FRONT_RIGHT;       break;
        case OpenGL::DrawBuffer::Left:              result = GL_LEFT;              break;
        case OpenGL::DrawBuffer::Right:             result = GL_RIGHT;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_draw_call_index_type(const OpenGL::DrawCallIndexType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::DrawCallIndexType::Unsigned_Byte:  result = GL_UNSIGNED_BYTE;  break;
        case OpenGL::DrawCallIndexType::Unsigned_Short: result = GL_UNSIGNED_SHORT; break;
        case OpenGL::DrawCallIndexType::Unsigned_Int:   result = GL_UNSIGNED_INT;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_draw_call_mode(const OpenGL::DrawCallMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        default:
        {
            case OpenGL::DrawCallMode::Lines:                    result = GL_LINES;                    break;
            case OpenGL::DrawCallMode::Lines_Adjacency:          result = GL_LINES_ADJACENCY;          break;
            case OpenGL::DrawCallMode::Line_Loop:                result = GL_LINE_LOOP;                break;
            case OpenGL::DrawCallMode::Line_Strip:               result = GL_LINE_STRIP;               break;
            case OpenGL::DrawCallMode::Line_Strip_Adjacency:     result = GL_LINE_STRIP_ADJACENCY;     break;
            case OpenGL::DrawCallMode::Patches:                  result = GL_PATCHES;                  break;
            case OpenGL::DrawCallMode::Points:                   result = GL_POINTS;                   break;
            case OpenGL::DrawCallMode::Triangle_Fan:             result = GL_TRIANGLE_FAN;             break;
            case OpenGL::DrawCallMode::Triangle_Strip:           result = GL_TRIANGLE_STRIP;           break;
            case OpenGL::DrawCallMode::Triangle_Strip_Adjacency: result = GL_TRIANGLE_STRIP_ADJACENCY; break;
            case OpenGL::DrawCallMode::Triangles:                result = GL_TRIANGLES;                break;
            case OpenGL::DrawCallMode::Triangles_Adjacency:      result = GL_TRIANGLES_ADJACENCY;      break;

            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_framebuffer_attachment_component_type(const OpenGL::FramebufferAttachmentComponentType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::FramebufferAttachmentComponentType::Float:               result = GL_FLOAT;               break;
        case OpenGL::FramebufferAttachmentComponentType::Int:                 result = GL_INT;                 break;
        case OpenGL::FramebufferAttachmentComponentType::None:                result = GL_NONE;                break;
        case OpenGL::FramebufferAttachmentComponentType::Signed_Normalized:   result = GL_SIGNED_NORMALIZED;   break;
        case OpenGL::FramebufferAttachmentComponentType::Unsigned_Int:        result = GL_UNSIGNED_INT;        break;
        case OpenGL::FramebufferAttachmentComponentType::Unsigned_Normalized: result = GL_UNSIGNED_NORMALIZED; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_framebuffer_attachment_object_type(const OpenGL::FramebufferAttachmentObjectType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::FramebufferAttachmentObjectType::Framebuffer_Default: result = GL_FRAMEBUFFER_DEFAULT; break;
        case OpenGL::FramebufferAttachmentObjectType::None:                result = GL_NONE;                break;
        case OpenGL::FramebufferAttachmentObjectType::Renderbuffer:        result = GL_RENDERBUFFER;        break;
        case OpenGL::FramebufferAttachmentObjectType::Texture:             result = GL_TEXTURE;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_framebuffer_attachment_point(const OpenGL::FramebufferAttachmentPoint& in_fb_attachment_point)
{
    GLenum result = 0;

    switch (in_fb_attachment_point)
    {
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment0:        result = GL_COLOR_ATTACHMENT0;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment1:        result = GL_COLOR_ATTACHMENT1;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment2:        result = GL_COLOR_ATTACHMENT2;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment3:        result = GL_COLOR_ATTACHMENT3;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment4:        result = GL_COLOR_ATTACHMENT4;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment5:        result = GL_COLOR_ATTACHMENT5;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment6:        result = GL_COLOR_ATTACHMENT6;        break;
        case OpenGL::FramebufferAttachmentPoint::Color_Attachment7:        result = GL_COLOR_ATTACHMENT7;        break;
        case OpenGL::FramebufferAttachmentPoint::Depth_Attachment:         result = GL_DEPTH_ATTACHMENT;         break;
        case OpenGL::FramebufferAttachmentPoint::Depth_Stencil_Attachment: result = GL_DEPTH_STENCIL_ATTACHMENT; break;
        case OpenGL::FramebufferAttachmentPoint::Stencil_Attachment:       result = GL_STENCIL_ATTACHMENT;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_framebuffer_attachment_property(const OpenGL::FramebufferAttachmentProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case OpenGL::FramebufferAttachmentProperty::Alpha_Size:             result = GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE;            break;
        case OpenGL::FramebufferAttachmentProperty::Blue_Size:              result = GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE;             break;
        case OpenGL::FramebufferAttachmentProperty::Color_Encoding:         result = GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING;        break;
        case OpenGL::FramebufferAttachmentProperty::Component_Type:         result = GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE;        break;
        case OpenGL::FramebufferAttachmentProperty::Depth_Size:             result = GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE;            break;
        case OpenGL::FramebufferAttachmentProperty::Green_Size:             result = GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE;            break;
        case OpenGL::FramebufferAttachmentProperty::Layered:                result = GL_FRAMEBUFFER_ATTACHMENT_LAYERED;               break;
        case OpenGL::FramebufferAttachmentProperty::Object_Name:            result = GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME;           break;
        case OpenGL::FramebufferAttachmentProperty::Object_Type:            result = GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE;           break;
        case OpenGL::FramebufferAttachmentProperty::Red_Size:               result = GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE;              break;
        case OpenGL::FramebufferAttachmentProperty::Stencil_Size:           result = GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE;          break;
        case OpenGL::FramebufferAttachmentProperty::Texture_Cube_Map_Face:  result = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE; break;
        case OpenGL::FramebufferAttachmentProperty::Texture_Layer:          result = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER;         break;
        case OpenGL::FramebufferAttachmentProperty::Texture_Level:          result = GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL;         break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_framebuffer_status(const OpenGL::FramebufferStatus& in_status)
{
    GLenum result = 0;

    switch (in_status)
    {
        case OpenGL::FramebufferStatus::Complete:                      result = GL_FRAMEBUFFER_COMPLETE;                      break;
        case OpenGL::FramebufferStatus::Incomplete_Attachment:         result = GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT;         break;
        case OpenGL::FramebufferStatus::Incomplete_Draw_Buffer:        result = GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER;        break;
        case OpenGL::FramebufferStatus::Incomplete_Layer_Targets:      result = GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS;      break;
        case OpenGL::FramebufferStatus::Incomplete_Missing_Attachment: result = GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT; break;
        case OpenGL::FramebufferStatus::Incomplete_Multisample:        result = GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE;        break;
        case OpenGL::FramebufferStatus::Incomplete_Read_Buffer:        result = GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER;        break;
        case OpenGL::FramebufferStatus::Undefined:                     result = GL_FRAMEBUFFER_UNDEFINED;                     break;
        case OpenGL::FramebufferStatus::Unsupported:                   result = GL_FRAMEBUFFER_UNSUPPORTED;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_framebuffer_target(const OpenGL::FramebufferTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case OpenGL::FramebufferTarget::Draw_Framebuffer: result = GL_DRAW_FRAMEBUFFER; break;
        case OpenGL::FramebufferTarget::Framebuffer:      result = GL_FRAMEBUFFER;      break;
        case OpenGL::FramebufferTarget::Read_Framebuffer: result = GL_READ_FRAMEBUFFER; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation)
{
    GLenum result = 0;

    switch (in_orientation)
    {
        case OpenGL::FrontFaceOrientation::Clockwise:         result = GL_CW;  break;
        case OpenGL::FrontFaceOrientation::Counter_Clockwise: result = GL_CCW; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_hint_mode(const OpenGL::HintMode& in_hint_mode)
{
    GLenum result = 0;

    switch (in_hint_mode)
    {
        case OpenGL::HintMode::Dont_Care: result = GL_DONT_CARE; break;
        case OpenGL::HintMode::Fastest:   result = GL_FASTEST;   break;
        case OpenGL::HintMode::Nicest:    result = GL_NICEST;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_hint_target(const OpenGL::HintTarget& in_hint_target)
{
    GLenum result = 0;

    switch (in_hint_target)
    {
        case OpenGL::HintTarget::Fragment_Shader_Derivative: result = GL_FRAGMENT_SHADER_DERIVATIVE_HINT; break;
        case OpenGL::HintTarget::Line_Smooth:                result = GL_LINE_SMOOTH_HINT;               break;
        case OpenGL::HintTarget::Polygon_Smooth:             result = GL_POLYGON_SMOOTH_HINT;            break;
        case OpenGL::HintTarget::Texture_Compression:        result = GL_TEXTURE_COMPRESSION_HINT;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_indexed_capability(const OpenGL::Capability& in_capability,
                                                       const uint32_t&         in_index)
{
    GLenum result  = 0;

    switch (in_capability)
    {
        case OpenGL::Capability::Clip_Distance:
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

GLenum OpenGL::Utils::get_gl_enum_for_internal_format(const OpenGL::InternalFormat& in_internal_format)
{
    GLenum result = 0;

    switch (in_internal_format)
    {
        /* Base internal formats */
        case OpenGL::InternalFormat::Depth_Component: result = GL_DEPTH_COMPONENT; break;
        case OpenGL::InternalFormat::Depth_Stencil:   result = GL_DEPTH_STENCIL;   break;
        case OpenGL::InternalFormat::Red:             result = GL_RED;             break;
        case OpenGL::InternalFormat::RG:              result = GL_RG;              break;
        case OpenGL::InternalFormat::RGB:             result = GL_RGB;             break;
        case OpenGL::InternalFormat::RGBA:            result = GL_RGBA;            break;

        /* Sized internal formats */
        case OpenGL::InternalFormat::R11F_G11F_B10F: result = GL_R11F_G11F_B10F; break;
        case OpenGL::InternalFormat::R16:            result = GL_R16;            break;
        case OpenGL::InternalFormat::R16_SNorm:      result = GL_R16_SNORM;      break;
        case OpenGL::InternalFormat::R16F:           result = GL_R16F;           break;
        case OpenGL::InternalFormat::R16I:           result = GL_R16I;           break;
        case OpenGL::InternalFormat::R16UI:          result = GL_R16UI;          break;
        case OpenGL::InternalFormat::R3_G3_B2:       result = GL_R3_G3_B2;       break;
        case OpenGL::InternalFormat::R32F:           result = GL_R32F;           break;
        case OpenGL::InternalFormat::R32I:           result = GL_R32I;           break;
        case OpenGL::InternalFormat::R32UI:          result = GL_R32UI;          break;
        case OpenGL::InternalFormat::R8:             result = GL_R8;             break;
        case OpenGL::InternalFormat::R8_SNorm:       result = GL_R8_SNORM;       break;
        case OpenGL::InternalFormat::R8I:            result = GL_R8I;            break;
        case OpenGL::InternalFormat::R8UI:           result = GL_R8UI;           break;
        case OpenGL::InternalFormat::RG16:           result = GL_RG16;           break;
        case OpenGL::InternalFormat::RG16_SNorm:     result = GL_RG16_SNORM;     break;
        case OpenGL::InternalFormat::RG16F:          result = GL_RG16F;          break;
        case OpenGL::InternalFormat::RG16I:          result = GL_RG16I;          break;
        case OpenGL::InternalFormat::RG16UI:         result = GL_RG16UI;         break;
        case OpenGL::InternalFormat::RG32F:          result = GL_RG32F;          break;
        case OpenGL::InternalFormat::RG32I:          result = GL_RG32I;          break;
        case OpenGL::InternalFormat::RG32UI:         result = GL_RG32UI;         break;
        case OpenGL::InternalFormat::RG8:            result = GL_RG8;            break;
        case OpenGL::InternalFormat::RG8_SNorm:      result = GL_RG8_SNORM;      break;
        case OpenGL::InternalFormat::RG8I:           result = GL_RG8I;           break;
        case OpenGL::InternalFormat::RG8UI:          result = GL_RG8UI;          break;
        case OpenGL::InternalFormat::RGB10:          result = GL_RGB10;          break;
        case OpenGL::InternalFormat::RGB10_A2:       result = GL_RGB10_A2;       break;
        case OpenGL::InternalFormat::RGB10_A2UI:     result = GL_RGB10_A2UI;     break;
        case OpenGL::InternalFormat::RGB12:          result = GL_RGB12;          break;
        case OpenGL::InternalFormat::RGB16_SNorm:    result = GL_RGB16_SNORM;    break;
        case OpenGL::InternalFormat::RGB16F:         result = GL_RGB16F;         break;
        case OpenGL::InternalFormat::RGB16I:         result = GL_RGB16I;         break;
        case OpenGL::InternalFormat::RGB16UI:        result = GL_RGB16UI;        break;
        case OpenGL::InternalFormat::RGB32F:         result = GL_RGB32F;         break;
        case OpenGL::InternalFormat::RGB32I:         result = GL_RGB32I;         break;
        case OpenGL::InternalFormat::RGB32UI:        result = GL_RGB32UI;        break;
        case OpenGL::InternalFormat::RGB4:           result = GL_RGB4;           break;
        case OpenGL::InternalFormat::RGB5:           result = GL_RGB5;           break;
        case OpenGL::InternalFormat::RGB5_A1:        result = GL_RGB5_A1;        break;
        case OpenGL::InternalFormat::RGB8:           result = GL_RGB8;           break;
        case OpenGL::InternalFormat::RGB8_SNorm:     result = GL_RGB8_SNORM;     break;
        case OpenGL::InternalFormat::RGB8I:          result = GL_RGB8I;          break;
        case OpenGL::InternalFormat::RGB8UI:         result = GL_RGB8UI;         break;
        case OpenGL::InternalFormat::RGB9_E5:        result = GL_RGB9_E5;        break;
        case OpenGL::InternalFormat::RGBA12:         result = GL_RGBA12;         break;
        case OpenGL::InternalFormat::RGBA16:         result = GL_RGBA16;         break;
        case OpenGL::InternalFormat::RGBA16F:        result = GL_RGBA16F;        break;
        case OpenGL::InternalFormat::RGBA16I:        result = GL_RGBA16I;        break;
        case OpenGL::InternalFormat::RGBA16UI:       result = GL_RGBA16UI;       break;
        case OpenGL::InternalFormat::RGBA2:          result = GL_RGBA2;          break;
        case OpenGL::InternalFormat::RGBA32F:        result = GL_RGBA32F;        break;
        case OpenGL::InternalFormat::RGBA32I:        result = GL_RGBA32I;        break;
        case OpenGL::InternalFormat::RGBA32UI:       result = GL_RGBA32UI;       break;
        case OpenGL::InternalFormat::RGBA4:          result = GL_RGBA4;          break;
        case OpenGL::InternalFormat::RGBA8:          result = GL_RGBA8;          break;
        case OpenGL::InternalFormat::RGBA8_SNorm:    result = GL_RGBA8_SNORM;    break;
        case OpenGL::InternalFormat::RGBA8I:         result = GL_RGBA8I;         break;
        case OpenGL::InternalFormat::RGBA8UI:        result = GL_RGBA8UI;        break;
        case OpenGL::InternalFormat::SRGB8:          result = GL_SRGB8;          break;
        case OpenGL::InternalFormat::SRGB8_Alpha8:   result = GL_SRGB8_ALPHA8;   break;

        /* Compressed internal formats */
        case OpenGL::InternalFormat::Compressed_Red:                     result = GL_COMPRESSED_RED;                     break;
        case OpenGL::InternalFormat::Compressed_Red_RGTC1:               result = GL_COMPRESSED_RED_RGTC1;               break;
        case OpenGL::InternalFormat::Compressed_RG:                      result = GL_COMPRESSED_RG;                      break;
        case OpenGL::InternalFormat::Compressed_RG_RGTC2:                result = GL_COMPRESSED_RG_RGTC2;                break;
        case OpenGL::InternalFormat::Compressed_RGB:                     result = GL_COMPRESSED_RGB;                     break;
        case OpenGL::InternalFormat::Compressed_RGB_BPTC_Signed_Float:   result = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT;   break;
        case OpenGL::InternalFormat::Compressed_RGB_BPTC_Unsigned_Float: result = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT; break;
        case OpenGL::InternalFormat::Compressed_RGBA:                    result = GL_COMPRESSED_RGBA;                    break;
        case OpenGL::InternalFormat::Compressed_RGBA_BPTC_UNorm:         result = GL_COMPRESSED_RGBA_BPTC_UNORM;         break;
        case OpenGL::InternalFormat::Compressed_Signed_Red_RGTC1:        result = GL_COMPRESSED_SIGNED_RED_RGTC1;        break;
        case OpenGL::InternalFormat::Compressed_Signed_RG_RGTC2:         result = GL_COMPRESSED_SIGNED_RG_RGTC2;         break;
        case OpenGL::InternalFormat::Compressed_SRGB:                    result = GL_COMPRESSED_SRGB;                    break;
        case OpenGL::InternalFormat::Compressed_SRGB_Alpha:              result = GL_COMPRESSED_SRGB_ALPHA;              break;
        case OpenGL::InternalFormat::Compressed_SRGB_Alpha_BPTC_UNorm:   result = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_logic_op_mode(const OpenGL::LogicOpMode& in_logic_op_mode)
{
    GLenum result = 0;

    switch (in_logic_op_mode)
    {
        case OpenGL::LogicOpMode::And:           result = GL_AND;           break;
        case OpenGL::LogicOpMode::And_Inverted:  result = GL_AND_INVERTED;  break;
        case OpenGL::LogicOpMode::And_Reverse:   result = GL_AND_REVERSE;   break;
        case OpenGL::LogicOpMode::Clear:         result = GL_CLEAR;         break;
        case OpenGL::LogicOpMode::Copy:          result = GL_COPY;          break;
        case OpenGL::LogicOpMode::Copy_Inverted: result = GL_COPY_INVERTED; break;
        case OpenGL::LogicOpMode::Equiv:         result = GL_EQUIV;         break;
        case OpenGL::LogicOpMode::Invert:        result = GL_INVERT;        break;
        case OpenGL::LogicOpMode::Nand:          result = GL_NAND;          break;
        case OpenGL::LogicOpMode::Noop:          result = GL_NOOP;          break;
        case OpenGL::LogicOpMode::Nor:           result = GL_NOR;           break;
        case OpenGL::LogicOpMode::Or:            result = GL_OR;            break;
        case OpenGL::LogicOpMode::Or_Inverted:   result = GL_OR_INVERTED;   break;
        case OpenGL::LogicOpMode::Or_Reverse:    result = GL_OR_REVERSE;    break;
        case OpenGL::LogicOpMode::Set:           result = GL_SET;           break;
        case OpenGL::LogicOpMode::Xor:           result = GL_XOR;           break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_mipmap_generation_texture_target(const OpenGL::MipmapGenerationTextureTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case OpenGL::MipmapGenerationTextureTarget::Texture_1D:       result = GL_TEXTURE_1D;       break;
        case OpenGL::MipmapGenerationTextureTarget::Texture_1D_Array: result = GL_TEXTURE_1D_ARRAY; break;
        case OpenGL::MipmapGenerationTextureTarget::Texture_2D:       result = GL_TEXTURE_2D;       break;
        case OpenGL::MipmapGenerationTextureTarget::Texture_2D_Array: result = GL_TEXTURE_2D_ARRAY; break;
        case OpenGL::MipmapGenerationTextureTarget::Texture_3D:       result = GL_TEXTURE_3D;       break;
        case OpenGL::MipmapGenerationTextureTarget::Texture_Cube_Map: result = GL_TEXTURE_CUBE_MAP; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_nonindexed_capability(const OpenGL::Capability& in_capability)
{
    GLenum result = 0;

    switch (in_capability)
    {
        case OpenGL::Capability::Blend:                     result = GL_BLEND;                     break;
        case OpenGL::Capability::Color_Logic_Op:            result = GL_COLOR_LOGIC_OP;            break;
        case OpenGL::Capability::Cull_Face:                 result = GL_CULL_FACE;                 break;
        case OpenGL::Capability::Depth_Clamp:               result = GL_DEPTH_CLAMP;               break;
        case OpenGL::Capability::Depth_Test:                result = GL_DEPTH_TEST;                break;
        case OpenGL::Capability::Dither:                    result = GL_DITHER;                    break;
        case OpenGL::Capability::Framebuffer_SRGB:          result = GL_FRAMEBUFFER_SRGB;          break;
        case OpenGL::Capability::Line_Smooth:               result = GL_LINE_SMOOTH;               break;
        case OpenGL::Capability::Multisample:               result = GL_MULTISAMPLE;               break;
        case OpenGL::Capability::Polygon_Offset_Fill:       result = GL_POLYGON_OFFSET_FILL;       break;
        case OpenGL::Capability::Polygon_Offset_Line:       result = GL_POLYGON_OFFSET_LINE;       break;
        case OpenGL::Capability::Polygon_Offset_Point:      result = GL_POLYGON_OFFSET_POINT;      break;
        case OpenGL::Capability::Polygon_Smooth:            result = GL_POLYGON_SMOOTH;            break;
        case OpenGL::Capability::Primitive_Restart:         result = GL_PRIMITIVE_RESTART;         break;
        case OpenGL::Capability::Program_Point_Size:        result = GL_PROGRAM_POINT_SIZE;        break;
        case OpenGL::Capability::Sample_Alpha_To_Coverage:  result = GL_SAMPLE_ALPHA_TO_COVERAGE;  break;
        case OpenGL::Capability::Sample_Alpha_To_One:       result = GL_SAMPLE_ALPHA_TO_ONE;       break;
        case OpenGL::Capability::Sample_Coverage:           result = GL_SAMPLE_COVERAGE;           break;
        case OpenGL::Capability::Scissor_Test:              result = GL_SCISSOR_TEST;              break;
        case OpenGL::Capability::Stencil_Test:              result = GL_STENCIL_TEST;              break;
        case OpenGL::Capability::Texture_Cube_Map_Seamless: result = GL_TEXTURE_CUBE_MAP_SEAMLESS; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_pixel_format(const OpenGL::PixelFormat& in_pixel_format)
{
    GLenum result = 0;

    switch (in_pixel_format)
    {
        case OpenGL::PixelFormat::Blue:            result = GL_BLUE;            break;
        case OpenGL::PixelFormat::Blue_Integer:    result = GL_BLUE_INTEGER;    break;
        case OpenGL::PixelFormat::BGR:             result = GL_BGR;             break;
        case OpenGL::PixelFormat::BGR_Integer:     result = GL_BGR_INTEGER;     break;
        case OpenGL::PixelFormat::BGRA:            result = GL_BGRA;            break;
        case OpenGL::PixelFormat::BGRA_Integer:    result = GL_BGRA_INTEGER;    break;
        case OpenGL::PixelFormat::Depth_Component: result = GL_DEPTH_COMPONENT; break;
        case OpenGL::PixelFormat::Depth_Stencil:   result = GL_DEPTH_STENCIL;   break;
        case OpenGL::PixelFormat::Green:           result = GL_GREEN;           break;
        case OpenGL::PixelFormat::Green_Integer:   result = GL_GREEN_INTEGER;   break;
        case OpenGL::PixelFormat::Red:             result = GL_RED;             break;
        case OpenGL::PixelFormat::Red_Integer:     result = GL_RED_INTEGER;     break;
        case OpenGL::PixelFormat::RG:              result = GL_RG;              break;
        case OpenGL::PixelFormat::RG_Integer:      result = GL_RG_INTEGER;      break;
        case OpenGL::PixelFormat::RGB:             result = GL_RGB;             break;
        case OpenGL::PixelFormat::RGB_Integer:     result = GL_RGB_INTEGER;     break;
        case OpenGL::PixelFormat::RGBA:            result = GL_RGBA;            break;
        case OpenGL::PixelFormat::RGBA_Integer:    result = GL_RGBA_INTEGER;    break;
        case OpenGL::PixelFormat::Stencil_Index:   result = GL_STENCIL_INDEX;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_pixel_store_property(const OpenGL::PixelStoreProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::PixelStoreProperty::Pack_Alignment:      result = GL_PACK_ALIGNMENT;      break;
        case OpenGL::PixelStoreProperty::Pack_Image_Height:   result = GL_PACK_IMAGE_HEIGHT;   break;
        case OpenGL::PixelStoreProperty::Pack_LSB_First:      result = GL_PACK_LSB_FIRST;      break;
        case OpenGL::PixelStoreProperty::Pack_Row_Length:     result = GL_PACK_ROW_LENGTH;     break;
        case OpenGL::PixelStoreProperty::Pack_Skip_Images:    result = GL_PACK_SKIP_IMAGES;    break;
        case OpenGL::PixelStoreProperty::Pack_Skip_Pixels:    result = GL_PACK_SKIP_PIXELS;    break;
        case OpenGL::PixelStoreProperty::Pack_Skip_Rows:      result = GL_PACK_SKIP_ROWS;      break;
        case OpenGL::PixelStoreProperty::Pack_Swap_Bytes:     result = GL_PACK_SWAP_BYTES;     break;
        case OpenGL::PixelStoreProperty::Unpack_Alignment:    result = GL_UNPACK_ALIGNMENT;    break;
        case OpenGL::PixelStoreProperty::Unpack_Image_Height: result = GL_UNPACK_IMAGE_HEIGHT; break;
        case OpenGL::PixelStoreProperty::Unpack_LSB_First:    result = GL_UNPACK_LSB_FIRST;    break;
        case OpenGL::PixelStoreProperty::Unpack_Row_Length:   result = GL_UNPACK_ROW_LENGTH;   break;
        case OpenGL::PixelStoreProperty::Unpack_Skip_Images:  result = GL_UNPACK_SKIP_IMAGES;  break;
        case OpenGL::PixelStoreProperty::Unpack_Skip_Pixels:  result = GL_UNPACK_SKIP_PIXELS;  break;
        case OpenGL::PixelStoreProperty::Unpack_Skip_Rows:    result = GL_UNPACK_SKIP_ROWS;    break;
        case OpenGL::PixelStoreProperty::Unpack_Swap_Bytes:   result = GL_UNPACK_SWAP_BYTES;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_point_sprite_coord_origin(const OpenGL::PointSpriteCoordOrigin& in_origin)
{
    GLenum result = 0;

    switch (in_origin)
    {
        case OpenGL::PointSpriteCoordOrigin::Lower_Left: result = GL_LOWER_LEFT; break;
        case OpenGL::PointSpriteCoordOrigin::Upper_Left: result = GL_UPPER_LEFT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_polygon_mode(const OpenGL::PolygonMode& in_polygon_mode)
{
    GLenum result = 0;

    switch (in_polygon_mode)
    {
        case OpenGL::PolygonMode::Fill:  result = GL_FILL;  break;
        case OpenGL::PolygonMode::Line:  result = GL_LINE;  break;
        case OpenGL::PolygonMode::Point: result = GL_POINT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_pixel_type(const OpenGL::PixelType& in_pixel_type)
{
    GLenum result = 0;

    switch (in_pixel_type)
    {
        case OpenGL::PixelType::Float:                          result = GL_FLOAT;                          break;
        case OpenGL::PixelType::Float_32_Unsigned_Int_24_8_Rev: result = GL_FLOAT_32_UNSIGNED_INT_24_8_REV; break;
        case OpenGL::PixelType::Half_Float:                     result = GL_HALF_FLOAT;                     break;
        case OpenGL::PixelType::Int:                            result = GL_INT;                            break;
        case OpenGL::PixelType::Short:                          result = GL_SHORT;                          break;
        case OpenGL::PixelType::Unsigned_Byte:                  result = GL_UNSIGNED_BYTE;                  break;
        case OpenGL::PixelType::Unsigned_Byte_2_3_3_Rev:        result = GL_UNSIGNED_BYTE_2_3_3_REV;        break;
        case OpenGL::PixelType::Unsigned_Byte_3_3_2:            result = GL_UNSIGNED_BYTE_3_3_2;            break;
        case OpenGL::PixelType::Unsigned_Int:                   result = GL_UNSIGNED_INT;                   break;
        case OpenGL::PixelType::Unsigned_Int_10_10_10_2:        result = GL_UNSIGNED_INT_10_10_10_2;        break;
        case OpenGL::PixelType::Unsigned_Int_10F_11F_11F_Rev:   result = GL_UNSIGNED_INT_10F_11F_11F_REV;   break;
        case OpenGL::PixelType::Unsigned_Int_2_10_10_10_Rev:    result = GL_UNSIGNED_INT_2_10_10_10_REV;    break;
        case OpenGL::PixelType::Unsigned_Int_24_8:              result = GL_UNSIGNED_INT_24_8;              break;
        case OpenGL::PixelType::Unsigned_Int_5_9_9_9_Rev:       result = GL_UNSIGNED_INT_5_9_9_9_REV;       break;
        case OpenGL::PixelType::Unsigned_Int_8_8_8_8:           result = GL_UNSIGNED_INT_8_8_8_8;           break;
        case OpenGL::PixelType::Unsigned_Int_8_8_8_8_Rev:       result = GL_UNSIGNED_INT_8_8_8_8_REV;       break;
        case OpenGL::PixelType::Unsigned_Short:                 result = GL_UNSIGNED_SHORT;                 break;
        case OpenGL::PixelType::Unsigned_Short_1_5_5_5_Rev:     result = GL_UNSIGNED_SHORT_1_5_5_5_REV;     break;
        case OpenGL::PixelType::Unsigned_Short_4_4_4_4:         result = GL_UNSIGNED_SHORT_4_4_4_4;         break;
        case OpenGL::PixelType::Unsigned_Short_4_4_4_4_Rev:     result = GL_UNSIGNED_SHORT_4_4_4_4_REV;     break;
        case OpenGL::PixelType::Unsigned_Short_5_5_5_1:         result = GL_UNSIGNED_SHORT_5_5_5_1;         break;
        case OpenGL::PixelType::Unsigned_Short_5_6_5:           result = GL_UNSIGNED_SHORT_5_6_5;           break;
        case OpenGL::PixelType::Unsigned_Short_5_6_5_Rev:       result = GL_UNSIGNED_SHORT_5_6_5_REV;       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_point_property(const OpenGL::PointProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::PointProperty::Fade_Threshold_Size: result = GL_POINT_FADE_THRESHOLD_SIZE; break;
        case OpenGL::PointProperty::Sprite_Coord_Origin: result = GL_POINT_SPRITE_COORD_ORIGIN; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_program_property(const OpenGL::ProgramProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case OpenGL::ProgramProperty::Active_Attributes:                     result = GL_ACTIVE_ATTRIBUTES;                     break;
        case OpenGL::ProgramProperty::Active_Attribute_Max_Length:           result = GL_ACTIVE_ATTRIBUTE_MAX_LENGTH;           break;
        case OpenGL::ProgramProperty::Active_Uniforms:                       result = GL_ACTIVE_UNIFORMS;                       break;
        case OpenGL::ProgramProperty::Active_Uniform_Blocks:                 result = GL_ACTIVE_UNIFORM_BLOCKS;                 break;
        case OpenGL::ProgramProperty::Active_Uniform_Block_Max_Name_Length:  result = GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH;  break;
        case OpenGL::ProgramProperty::Active_Uniform_Max_Length:             result = GL_ACTIVE_UNIFORM_MAX_LENGTH;             break;
        case OpenGL::ProgramProperty::Attached_Shaders:                      result = GL_ATTACHED_SHADERS;                      break;
        case OpenGL::ProgramProperty::Delete_Status:                         result = GL_DELETE_STATUS;                         break;
        case OpenGL::ProgramProperty::Geometry_Input_Type:                   result = GL_GEOMETRY_INPUT_TYPE;                   break;
        case OpenGL::ProgramProperty::Geometry_Output_Type:                  result = GL_GEOMETRY_OUTPUT_TYPE;                  break;
        case OpenGL::ProgramProperty::Geometry_Vertices_Out:                 result = GL_GEOMETRY_VERTICES_OUT;                 break;
        case OpenGL::ProgramProperty::Info_Log_Length:                       result = GL_INFO_LOG_LENGTH;                       break;
        case OpenGL::ProgramProperty::Link_Status:                           result = GL_LINK_STATUS;                           break;
        case OpenGL::ProgramProperty::Transform_Feedback_Buffer_Mode:        result = GL_TRANSFORM_FEEDBACK_BUFFER_MODE;        break;
        case OpenGL::ProgramProperty::Transform_Feedback_Varyings:           result = GL_TRANSFORM_FEEDBACK_VARYINGS;           break;
        case OpenGL::ProgramProperty::Transform_Feedback_Varying_Max_Length: result = GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH; break;
        case OpenGL::ProgramProperty::Validate_Status:                       result = GL_VALIDATE_STATUS;                       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_provoking_vertex_convention(const OpenGL::ProvokingVertexConvention& in_convention)
{
    GLenum result = 0;

    switch (in_convention)
    {
        case OpenGL::ProvokingVertexConvention::First: result = GL_FIRST_VERTEX_CONVENTION; break;
        case OpenGL::ProvokingVertexConvention::Last:  result = GL_LAST_VERTEX_CONVENTION;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_query_property(const OpenGL::QueryProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::QueryProperty::Query_Result:           result = GL_QUERY_RESULT;           break;
        case OpenGL::QueryProperty::Query_Result_Available: result = GL_QUERY_RESULT_AVAILABLE; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_query_target(const OpenGL::QueryTarget& in_target)
{
    GLenum result = 0;

    switch (in_target)
    {
        case OpenGL::QueryTarget::Primitives_Generated:                  result = GL_PRIMITIVES_GENERATED;                  break;
        case OpenGL::QueryTarget::Samples_Passed:                        result = GL_SAMPLES_PASSED;                        break;
        case OpenGL::QueryTarget::Transform_Feedback_Primitives_Written: result = GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_query_target_property(const OpenGL::QueryTargetProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::QueryTargetProperty::Current_Query:      result = GL_CURRENT_QUERY;      break;
        case OpenGL::QueryTargetProperty::Query_Counter_Bits: result = GL_QUERY_COUNTER_BITS; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_read_buffer(const OpenGL::ReadBuffer& in_read_buffer)
{
    GLenum result = 0;

    switch (in_read_buffer)
    {
        case OpenGL::ReadBuffer::Back:              result = GL_BACK;              break;
        case OpenGL::ReadBuffer::Back_Left:         result = GL_BACK_LEFT;         break;
        case OpenGL::ReadBuffer::Back_Right:        result = GL_BACK_RIGHT;        break;
        case OpenGL::ReadBuffer::Color_Attachment0: result = GL_COLOR_ATTACHMENT0; break;
        case OpenGL::ReadBuffer::Color_Attachment1: result = GL_COLOR_ATTACHMENT1; break;
        case OpenGL::ReadBuffer::Color_Attachment2: result = GL_COLOR_ATTACHMENT2; break;
        case OpenGL::ReadBuffer::Color_Attachment3: result = GL_COLOR_ATTACHMENT3; break;
        case OpenGL::ReadBuffer::Color_Attachment4: result = GL_COLOR_ATTACHMENT4; break;
        case OpenGL::ReadBuffer::Color_Attachment5: result = GL_COLOR_ATTACHMENT5; break;
        case OpenGL::ReadBuffer::Color_Attachment6: result = GL_COLOR_ATTACHMENT6; break;
        case OpenGL::ReadBuffer::Color_Attachment7: result = GL_COLOR_ATTACHMENT7; break;
        case OpenGL::ReadBuffer::Front:             result = GL_FRONT;             break;
        case OpenGL::ReadBuffer::Front_And_Back:    result = GL_FRONT_AND_BACK;    break;
        case OpenGL::ReadBuffer::Front_Left:        result = GL_FRONT_LEFT;        break;
        case OpenGL::ReadBuffer::Front_Right:       result = GL_FRONT_RIGHT;       break;
        case OpenGL::ReadBuffer::Left:              result = GL_LEFT;              break;
        case OpenGL::ReadBuffer::Right:             result = GL_RIGHT;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_renderbuffer_property(const OpenGL::RenderbufferProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case OpenGL::RenderbufferProperty::Alpha_Size:      result = GL_RENDERBUFFER_ALPHA_SIZE;
        case OpenGL::RenderbufferProperty::Blue_Size:       result = GL_RENDERBUFFER_BLUE_SIZE;
        case OpenGL::RenderbufferProperty::Depth_Size:      result = GL_RENDERBUFFER_DEPTH_SIZE;
        case OpenGL::RenderbufferProperty::Green_Size:      result = GL_RENDERBUFFER_GREEN_SIZE;
        case OpenGL::RenderbufferProperty::Height:          result = GL_RENDERBUFFER_HEIGHT;
        case OpenGL::RenderbufferProperty::Internal_Format: result = GL_RENDERBUFFER_INTERNAL_FORMAT;
        case OpenGL::RenderbufferProperty::Red_Size:        result = GL_RENDERBUFFER_RED_SIZE;
        case OpenGL::RenderbufferProperty::Samples:         result = GL_RENDERBUFFER_SAMPLES;
        case OpenGL::RenderbufferProperty::Stencil_Size:    result = GL_RENDERBUFFER_STENCIL_SIZE;
        case OpenGL::RenderbufferProperty::Width:           result = GL_RENDERBUFFER_WIDTH;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_renderbuffer_target(const OpenGL::RenderbufferTarget& in_target)
{
    vkgl_assert(in_target == OpenGL::RenderbufferTarget::Renderbuffer);

    return GL_RENDERBUFFER;
}

GLenum OpenGL::Utils::get_gl_enum_for_shader_property(const OpenGL::ShaderProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case OpenGL::ShaderProperty::Compile_Status:       result = GL_COMPILE_STATUS;       break;
        case OpenGL::ShaderProperty::Delete_Status:        result = GL_DELETE_STATUS;        break;
        case OpenGL::ShaderProperty::Info_Log_Length:      result = GL_INFO_LOG_LENGTH;      break;
        case OpenGL::ShaderProperty::Shader_Source_Length: result = GL_SHADER_SOURCE_LENGTH; break;
        case OpenGL::ShaderProperty::Shader_Type:          result = GL_SHADER_TYPE;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_shader_type(const OpenGL::ShaderType& in_shader_type)
{
    GLenum result = 0;

    switch (in_shader_type)
    {
        case OpenGL::ShaderType::Fragment: result = GL_FRAGMENT_SHADER; break;
        case OpenGL::ShaderType::Geometry: result = GL_GEOMETRY_SHADER; break;
        case OpenGL::ShaderType::Vertex:   result = GL_VERTEX_SHADER;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_stencil_function(const OpenGL::StencilFunction& in_stencil_function)
{
    GLenum result = 0;

    switch (in_stencil_function)
    {
        case OpenGL::StencilFunction::Always:   result = GL_ALWAYS;   break;
        case OpenGL::StencilFunction::Equal:    result = GL_EQUAL;    break;
        case OpenGL::StencilFunction::GEqual:   result = GL_GEQUAL;   break;
        case OpenGL::StencilFunction::Greater:  result = GL_GREATER;  break;
        case OpenGL::StencilFunction::LEqual:   result = GL_LEQUAL;   break;
        case OpenGL::StencilFunction::Less:     result = GL_LESS;     break;
        case OpenGL::StencilFunction::Never:    result = GL_NEVER;    break;
        case OpenGL::StencilFunction::NotEqual: result = GL_NOTEQUAL; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_stencil_operation(const OpenGL::StencilOperation& in_operation)
{
    GLenum result = 0;

    switch (in_operation)
    {
        case OpenGL::StencilOperation::Decr:      result = GL_DECR;      break;
        case OpenGL::StencilOperation::Decr_Wrap: result = GL_DECR_WRAP; break;
        case OpenGL::StencilOperation::Incr:      result = GL_INCR;      break;
        case OpenGL::StencilOperation::Incr_Wrap: result = GL_INCR_WRAP; break;
        case OpenGL::StencilOperation::Invert:    result = GL_INVERT;    break;
        case OpenGL::StencilOperation::Keep:      result = GL_KEEP;      break;
        case OpenGL::StencilOperation::Replace:   result = GL_REPLACE;   break;
        case OpenGL::StencilOperation::Zero:      result = GL_ZERO;      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_stencil_state_face(const OpenGL::StencilStateFace& in_face)
{
    GLenum result = 0;

    switch (in_face)
    {
        case OpenGL::StencilStateFace::Back:           result = GL_BACK;           break;
        case OpenGL::StencilStateFace::Front:          result = GL_FRONT;          break;
        case OpenGL::StencilStateFace::Front_And_Back: result = GL_FRONT_AND_BACK; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_sync_condition(const OpenGL::SyncCondition& in_condition)
{
    GLenum result = 0;

    switch (in_condition)
    {
        case OpenGL::SyncCondition::Sync_GPU_Commands_Complete: result = GL_SYNC_GPU_COMMANDS_COMPLETE; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_sync_property(const OpenGL::SyncProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case OpenGL::SyncProperty::Condition:   result = GL_SYNC_CONDITION; break;
        case OpenGL::SyncProperty::Flags:       result = GL_SYNC_FLAGS;     break;
        case OpenGL::SyncProperty::Object_Type: result = GL_OBJECT_TYPE;    break;
        case OpenGL::SyncProperty::Status:      result = GL_SYNC_STATUS;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_compare_function(const OpenGL::TextureCompareFunction& in_compare_function)
{
    GLenum result = 0;

    switch (in_compare_function)
    {
        case OpenGL::TextureCompareFunction::Always:   result = GL_ALWAYS;   break;
        case OpenGL::TextureCompareFunction::Equal:    result = GL_EQUAL;    break;
        case OpenGL::TextureCompareFunction::GEqual:   result = GL_GEQUAL;   break;
        case OpenGL::TextureCompareFunction::Greater:  result = GL_GREATER;  break;
        case OpenGL::TextureCompareFunction::LEqual:   result = GL_LEQUAL;   break;
        case OpenGL::TextureCompareFunction::Less:     result = GL_LESS;     break;
        case OpenGL::TextureCompareFunction::Never:    result = GL_NEVER;    break;
        case OpenGL::TextureCompareFunction::NotEqual: result = GL_NOTEQUAL; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_compare_mode(const OpenGL::TextureCompareMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case OpenGL::TextureCompareMode::Compare_Ref_to_Texture: result = GL_COMPARE_REF_TO_TEXTURE; break;
        case OpenGL::TextureCompareMode::None:                   result = GL_NONE;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_cube_map_face(const OpenGL::TextureCubeMapFace& in_face)
{
    GLenum result = 0;

    switch (in_face)
    {
        case OpenGL::TextureCubeMapFace::Negative_X: result = GL_TEXTURE_CUBE_MAP_NEGATIVE_X; break;
        case OpenGL::TextureCubeMapFace::Negative_Y: result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y; break;
        case OpenGL::TextureCubeMapFace::Negative_Z: result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z; break;
        case OpenGL::TextureCubeMapFace::None:       result = GL_NONE;                        break;
        case OpenGL::TextureCubeMapFace::Positive_X: result = GL_TEXTURE_CUBE_MAP_POSITIVE_X; break;
        case OpenGL::TextureCubeMapFace::Positive_Y: result = GL_TEXTURE_CUBE_MAP_POSITIVE_Y; break;
        case OpenGL::TextureCubeMapFace::Positive_Z: result = GL_TEXTURE_CUBE_MAP_POSITIVE_Z; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_level_property(const OpenGL::TextureLevelProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::TextureLevelProperty::Texture_Alpha_Size:            result = GL_TEXTURE_ALPHA_SIZE;            break;
        case OpenGL::TextureLevelProperty::Texture_Blue_Size:             result = GL_TEXTURE_BLUE_SIZE;             break;
        case OpenGL::TextureLevelProperty::Texture_Buffer_Offset:         result = GL_TEXTURE_BUFFER_OFFSET;         break;
        case OpenGL::TextureLevelProperty::Texture_Compressed:            result = GL_TEXTURE_COMPRESSED;            break;
        case OpenGL::TextureLevelProperty::Texture_Compressed_Image_Size: result = GL_TEXTURE_COMPRESSED_IMAGE_SIZE; break;
        case OpenGL::TextureLevelProperty::Texture_Depth:                 result = GL_TEXTURE_DEPTH;                 break;
        case OpenGL::TextureLevelProperty::Texture_Depth_Size:            result = GL_TEXTURE_DEPTH_SIZE;            break;
        case OpenGL::TextureLevelProperty::Texture_Green_Size:            result = GL_TEXTURE_GREEN_SIZE;            break;
        case OpenGL::TextureLevelProperty::Texture_Height:                result = GL_TEXTURE_HEIGHT;                break;
        case OpenGL::TextureLevelProperty::Texture_Internal_Format:       result = GL_TEXTURE_INTERNAL_FORMAT;       break;
        case OpenGL::TextureLevelProperty::Texture_Red_Size:              result = GL_TEXTURE_RED_SIZE;              break;
        case OpenGL::TextureLevelProperty::Texture_Width:                 result = GL_TEXTURE_WIDTH;                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_mag_filter(const OpenGL::TextureMagFilter& in_filter)
{
    GLenum result = 0;

    switch (in_filter)
    {
        case OpenGL::TextureMagFilter::Linear:  result = GL_LINEAR;  break;
        case OpenGL::TextureMagFilter::Nearest: result = GL_NEAREST; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_min_filter(const OpenGL::TextureMinFilter& in_filter)
{
    GLenum result = 0;

    switch (in_filter)
    {
        case OpenGL::TextureMinFilter::Linear:                 result = GL_LINEAR;                 break;
        case OpenGL::TextureMinFilter::Linear_Mipmap_Linear:   result = GL_LINEAR_MIPMAP_LINEAR;   break;
        case OpenGL::TextureMinFilter::Linear_Mipmap_Nearest:  result = GL_LINEAR_MIPMAP_NEAREST;  break;
        case OpenGL::TextureMinFilter::Nearest:                result = GL_NEAREST;                break;
        case OpenGL::TextureMinFilter::Nearest_Mipmap_Linear:  result = GL_NEAREST_MIPMAP_LINEAR;  break;
        case OpenGL::TextureMinFilter::Nearest_Mipmap_Nearest: result = GL_NEAREST_MIPMAP_NEAREST; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_property(const OpenGL::TextureProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::TextureProperty::Depth_Stencil_Texture_Mode: result = GL_DEPTH_STENCIL_TEXTURE_MODE; break;
        case OpenGL::TextureProperty::Texture_Base_Level:         result = GL_TEXTURE_BASE_LEVEL;         break;
        case OpenGL::TextureProperty::Texture_Compare_Func:       result = GL_TEXTURE_COMPARE_FUNC;       break;
        case OpenGL::TextureProperty::Texture_Compare_Mode:       result = GL_TEXTURE_COMPARE_MODE;       break;
        case OpenGL::TextureProperty::Texture_Lod_Bias:           result = GL_TEXTURE_LOD_BIAS;           break;
        case OpenGL::TextureProperty::Texture_Mag_Filter:         result = GL_TEXTURE_MAG_FILTER;         break;
        case OpenGL::TextureProperty::Texture_Max_Level:          result = GL_TEXTURE_MAX_LEVEL;          break;
        case OpenGL::TextureProperty::Texture_Max_Lod:            result = GL_TEXTURE_MAX_LOD;            break;
        case OpenGL::TextureProperty::Texture_Min_Filter:         result = GL_TEXTURE_MIN_FILTER;         break;
        case OpenGL::TextureProperty::Texture_Min_Lod:            result = GL_TEXTURE_MIN_LOD;            break;
        case OpenGL::TextureProperty::Texture_Swizzle_A:          result = GL_TEXTURE_SWIZZLE_A;          break;
        case OpenGL::TextureProperty::Texture_Swizzle_B:          result = GL_TEXTURE_SWIZZLE_B;          break;
        case OpenGL::TextureProperty::Texture_Swizzle_G:          result = GL_TEXTURE_SWIZZLE_G;          break;
        case OpenGL::TextureProperty::Texture_Swizzle_R:          result = GL_TEXTURE_SWIZZLE_R;          break;
        case OpenGL::TextureProperty::Texture_Wrap_R:             result = GL_TEXTURE_WRAP_R;             break;
        case OpenGL::TextureProperty::Texture_Wrap_S:             result = GL_TEXTURE_WRAP_S;             break;
        case OpenGL::TextureProperty::Texture_Wrap_T:             result = GL_TEXTURE_WRAP_T;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_swizzle(const OpenGL::TextureSwizzle& in_swizzle)
{
    GLenum result = 0;

    switch (in_swizzle)
    {
        case OpenGL::TextureSwizzle::Alpha: result = GL_ALPHA; break;
        case OpenGL::TextureSwizzle::Blue:  result = GL_BLUE;  break;
        case OpenGL::TextureSwizzle::Green: result = GL_GREEN; break;
        case OpenGL::TextureSwizzle::One:   result = GL_ONE;   break;
        case OpenGL::TextureSwizzle::Red:   result = GL_RED;   break;
        case OpenGL::TextureSwizzle::Zero:  result = GL_ZERO;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_target(const OpenGL::TextureTarget& in_texture_target)
{
    GLenum result = 0;

    switch (in_texture_target)
    {
        case OpenGL::TextureTarget::_1D:                                result = GL_TEXTURE_1D;                         break;
        case OpenGL::TextureTarget::_1D_Array:                          result = GL_TEXTURE_1D_ARRAY;                   break;
        case OpenGL::TextureTarget::_2D:                                result = GL_TEXTURE_2D;                         break;
        case OpenGL::TextureTarget::_2D_Array:                          result = GL_TEXTURE_2D_ARRAY;                   break;
        case OpenGL::TextureTarget::_2D_Multisample:                    result = GL_TEXTURE_2D_MULTISAMPLE;             break;
        case OpenGL::TextureTarget::_2D_Multisample_Array:              result = GL_TEXTURE_2D_MULTISAMPLE_ARRAY;       break;
        case OpenGL::TextureTarget::_3D:                                result = GL_TEXTURE_3D;                         break;
        case OpenGL::TextureTarget::Cube_Map_Negative_X:                result = GL_TEXTURE_CUBE_MAP_NEGATIVE_X;        break;
        case OpenGL::TextureTarget::Cube_Map_Negative_Y:                result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;        break;
        case OpenGL::TextureTarget::Cube_Map_Negative_Z:                result = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;        break;
        case OpenGL::TextureTarget::Cube_Map_Positive_X:                result = GL_TEXTURE_CUBE_MAP_POSITIVE_X;        break;
        case OpenGL::TextureTarget::Cube_Map_Positive_Y:                result = GL_TEXTURE_CUBE_MAP_POSITIVE_Y;        break;
        case OpenGL::TextureTarget::Cube_Map_Positive_Z:                result = GL_TEXTURE_CUBE_MAP_POSITIVE_Z;        break;
        case OpenGL::TextureTarget::Proxy_Texture_1D:                   result = GL_PROXY_TEXTURE_1D;                   break;
        case OpenGL::TextureTarget::Proxy_Texture_1D_Array:             result = GL_PROXY_TEXTURE_1D_ARRAY;             break;
        case OpenGL::TextureTarget::Proxy_Texture_2D:                   result = GL_PROXY_TEXTURE_2D;                   break;
        case OpenGL::TextureTarget::Proxy_Texture_2D_Array:             result = GL_PROXY_TEXTURE_2D_ARRAY;             break;
        case OpenGL::TextureTarget::Proxy_Texture_2D_Multisample:       result = GL_PROXY_TEXTURE_2D_MULTISAMPLE;       break;
        case OpenGL::TextureTarget::Proxy_Texture_2D_Multisample_Array: result = GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY; break;
        case OpenGL::TextureTarget::Proxy_Texture_3D:                   result = GL_PROXY_TEXTURE_3D;                   break;
        case OpenGL::TextureTarget::Proxy_Texture_Cube_Map:             result = GL_PROXY_TEXTURE_CUBE_MAP;             break;
        case OpenGL::TextureTarget::Proxy_Texture_Rectangle:            result = GL_PROXY_TEXTURE_RECTANGLE;            break;
        case OpenGL::TextureTarget::Rectangle:                          result = GL_TEXTURE_RECTANGLE;                  break;
        case OpenGL::TextureTarget::Texture_Buffer:                     result = GL_TEXTURE_BUFFER;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_texture_wrap_mode(const OpenGL::TextureWrapMode& in_wrap_mode)
{
    GLenum result = 0;

    switch (in_wrap_mode)
    {
        case OpenGL::TextureWrapMode::Clamp_To_Border:      result = GL_CLAMP_TO_BORDER;      break;
        case OpenGL::TextureWrapMode::Clamp_To_Edge:        result = GL_CLAMP_TO_EDGE;        break;
        case OpenGL::TextureWrapMode::Mirror_Clamp_to_Edge: result = GL_MIRROR_CLAMP_TO_EDGE; break;
        case OpenGL::TextureWrapMode::Mirrored_Repeat:      result = GL_MIRRORED_REPEAT;      break;
        case OpenGL::TextureWrapMode::Repeat:               result = GL_REPEAT;               break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_transform_feedback_buffer_mode(const OpenGL::TransformFeedbackBufferMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case OpenGL::TransformFeedbackBufferMode::Interleaved_Attribs: result = GL_INTERLEAVED_ATTRIBS; break;
        case OpenGL::TransformFeedbackBufferMode::Separate_Attribs:    result = GL_SEPARATE_ATTRIBS;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_transform_feedback_primitive_mode(const OpenGL::TransformFeedbackPrimitiveMode& in_mode)
{
    GLenum result = 0;

    switch (in_mode)
    {
        case OpenGL::TransformFeedbackPrimitiveMode::Lines:     result = GL_LINES;     break;
        case OpenGL::TransformFeedbackPrimitiveMode::Points:    result = GL_POINTS;    break;
        case OpenGL::TransformFeedbackPrimitiveMode::Triangles: result = GL_TRIANGLES; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_uniform_block_property(const OpenGL::UniformBlockProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::UniformBlockProperty::Binding:                       result = GL_UNIFORM_BLOCK_BINDING;                       break;
        case OpenGL::UniformBlockProperty::Block_Active_Uniforms:         result = GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS;               break;
        case OpenGL::UniformBlockProperty::Block_Active_Uniform_Indices:  result = GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES;        break;
        case OpenGL::UniformBlockProperty::Block_Data_Size:               result = GL_UNIFORM_BLOCK_DATA_SIZE;                     break;
        case OpenGL::UniformBlockProperty::Block_Name_Length:             result = GL_UNIFORM_BLOCK_NAME_LENGTH;                   break;
        case OpenGL::UniformBlockProperty::Referenced_By_Fragment_Shader: result = GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER; break;
        case OpenGL::UniformBlockProperty::Referenced_By_Geometry_Shader: result = GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER; break;
        case OpenGL::UniformBlockProperty::Referenced_By_Vertex_Shader:   result = GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_uniform_property(const OpenGL::UniformProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::UniformProperty::Array_Stride:  result = GL_UNIFORM_ARRAY_STRIDE;  break;
        case OpenGL::UniformProperty::Block_Index:   result = GL_UNIFORM_BLOCK_INDEX;   break;
        case OpenGL::UniformProperty::Is_Row_Major:  result = GL_UNIFORM_IS_ROW_MAJOR;  break;
        case OpenGL::UniformProperty::Matrix_Stride: result = GL_UNIFORM_MATRIX_STRIDE; break;
        case OpenGL::UniformProperty::Name_Length:   result = GL_UNIFORM_NAME_LENGTH;   break;
        case OpenGL::UniformProperty::Offset:        result = GL_UNIFORM_OFFSET;        break;
        case OpenGL::UniformProperty::Size:          result = GL_UNIFORM_SIZE;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_variable_type(const VariableType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::VariableType::Bool:                 result = GL_BOOL;                                      break;
        case OpenGL::VariableType::Bvec2:                result = GL_BOOL_VEC2;                                 break;
        case OpenGL::VariableType::Bvec3:                result = GL_BOOL_VEC3;                                 break;
        case OpenGL::VariableType::Bvec4:                result = GL_BOOL_VEC4;                                 break;
        case OpenGL::VariableType::Float:                result = GL_FLOAT;                                     break;
        case OpenGL::VariableType::Int:                  result = GL_INT;                                       break;
        case OpenGL::VariableType::Isampler1D:           result = GL_INT_SAMPLER_1D;                            break;
        case OpenGL::VariableType::Isampler1DArray:      result = GL_INT_SAMPLER_1D_ARRAY;                      break;
        case OpenGL::VariableType::Isampler2D:           result = GL_INT_SAMPLER_2D;                            break;
        case OpenGL::VariableType::Isampler2DArray:      result = GL_INT_SAMPLER_2D_ARRAY;                      break;
        case OpenGL::VariableType::Isampler2DMS:         result = GL_INT_SAMPLER_2D_MULTISAMPLE;                break;
        case OpenGL::VariableType::Isampler2DMSArray:    result = GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY;          break;
        case OpenGL::VariableType::Isampler2DRect:       result = GL_INT_SAMPLER_2D_RECT;                       break;
        case OpenGL::VariableType::Isampler3D:           result = GL_INT_SAMPLER_3D;                            break;
        case OpenGL::VariableType::IsamplerBuffer:       result = GL_INT_SAMPLER_BUFFER;                        break;
        case OpenGL::VariableType::IsamplerCube:         result = GL_INT_SAMPLER_CUBE;                          break;
        case OpenGL::VariableType::Ivec2:                result = GL_INT_VEC2;                                  break;
        case OpenGL::VariableType::Ivec3:                result = GL_INT_VEC3;                                  break;
        case OpenGL::VariableType::Ivec4:                result = GL_INT_VEC4;                                  break;
        case OpenGL::VariableType::Mat2:                 result = GL_FLOAT_MAT2;                                break;
        case OpenGL::VariableType::Mat3:                 result = GL_FLOAT_MAT3;                                break;
        case OpenGL::VariableType::Mat4:                 result = GL_FLOAT_MAT4;                                break;
        case OpenGL::VariableType::Mat2x3:               result = GL_FLOAT_MAT2x3;                              break;
        case OpenGL::VariableType::Mat2x4:               result = GL_FLOAT_MAT2x4;                              break;
        case OpenGL::VariableType::Mat3x2:               result = GL_FLOAT_MAT3x2;                              break;
        case OpenGL::VariableType::Mat3x4:               result = GL_FLOAT_MAT3x4;                              break;
        case OpenGL::VariableType::Mat4x2:               result = GL_FLOAT_MAT4x2;                              break;
        case OpenGL::VariableType::Mat4x3:               result = GL_FLOAT_MAT4x3;                              break;
        case OpenGL::VariableType::Sampler1D:            result = GL_SAMPLER_1D;                                break;
        case OpenGL::VariableType::Sampler1DArray:       result = GL_SAMPLER_1D_ARRAY;                          break;
        case OpenGL::VariableType::Sampler1DArrayShadow: result = GL_SAMPLER_1D_ARRAY_SHADOW;                   break;
        case OpenGL::VariableType::Sampler1DShadow:      result = GL_SAMPLER_1D_SHADOW;                         break;
        case OpenGL::VariableType::Sampler2D:            result = GL_SAMPLER_2D;                                break;
        case OpenGL::VariableType::Sampler2DArray:       result = GL_SAMPLER_2D_ARRAY;                          break;
        case OpenGL::VariableType::Sampler2DArrayShadow: result = GL_SAMPLER_2D_ARRAY_SHADOW;                   break;
        case OpenGL::VariableType::Sampler2DMS:          result = GL_SAMPLER_2D_MULTISAMPLE;                    break;
        case OpenGL::VariableType::Sampler2DMSArray:     result = GL_SAMPLER_2D_MULTISAMPLE_ARRAY;              break;
        case OpenGL::VariableType::Sampler2DRect:        result = GL_SAMPLER_2D_RECT;                           break;
        case OpenGL::VariableType::Sampler2DRectShadow:  result = GL_SAMPLER_2D_RECT_SHADOW;                    break;
        case OpenGL::VariableType::Sampler2DShadow:      result = GL_SAMPLER_2D_SHADOW;                         break;
        case OpenGL::VariableType::Sampler3D:            result = GL_SAMPLER_3D;                                break;
        case OpenGL::VariableType::SamplerBuffer:        result = GL_SAMPLER_BUFFER;                            break;
        case OpenGL::VariableType::SamplerCube:          result = GL_SAMPLER_CUBE;                              break;
        case OpenGL::VariableType::SamplerCubeShadow:    result = GL_SAMPLER_CUBE_SHADOW;                       break;
        case OpenGL::VariableType::Uint:                 result = GL_UNSIGNED_INT;                              break;
        case OpenGL::VariableType::Usampler1D:           result = GL_UNSIGNED_INT_SAMPLER_1D;                   break;
        case OpenGL::VariableType::Usampler1DArray:      result = GL_UNSIGNED_INT_SAMPLER_1D_ARRAY;             break;
        case OpenGL::VariableType::Usampler2D:           result = GL_UNSIGNED_INT_SAMPLER_2D;                   break;
        case OpenGL::VariableType::Usampler2DArray:      result = GL_UNSIGNED_INT_SAMPLER_2D_ARRAY;             break;
        case OpenGL::VariableType::Usampler2DMS:         result = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE;       break;
        case OpenGL::VariableType::Usampler2DMSArray:    result = GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY; break;
        case OpenGL::VariableType::Usampler2DRect:       result = GL_UNSIGNED_INT_SAMPLER_2D_RECT;              break;
        case OpenGL::VariableType::Usampler3D:           result = GL_UNSIGNED_INT_SAMPLER_3D;                   break;
        case OpenGL::VariableType::UsamplerBuffer:       result = GL_UNSIGNED_INT_SAMPLER_BUFFER;               break;
        case OpenGL::VariableType::UsamplerCube:         result = GL_UNSIGNED_INT_SAMPLER_CUBE;                 break;
        case OpenGL::VariableType::Uvec2:                result = GL_UNSIGNED_INT_VEC2;                         break;
        case OpenGL::VariableType::Uvec3:                result = GL_UNSIGNED_INT_VEC3;                         break;
        case OpenGL::VariableType::Uvec4:                result = GL_UNSIGNED_INT_VEC4;                         break;
        case OpenGL::VariableType::Vec2:                 result = GL_FLOAT_VEC2;                                break;
        case OpenGL::VariableType::Vec3:                 result = GL_FLOAT_VEC3;                                break;
        case OpenGL::VariableType::Vec4:                 result = GL_FLOAT_VEC4;                                break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_vertex_attribute_pointer_property(const OpenGL::VertexAttributePointerProperty& in_pname)
{
    GLenum result = 0;

    switch (in_pname)
    {
        case OpenGL::VertexAttributePointerProperty::Vertex_Attribute_Array_Pointer: result = GL_VERTEX_ATTRIB_ARRAY_POINTER; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_vertex_attribute_array_type(const OpenGL::VertexAttributeArrayType& in_type)
{
    GLenum result = 0;

    switch (in_type)
    {
        case OpenGL::VertexAttributeArrayType::Byte:           result = GL_BYTE;           break;
        case OpenGL::VertexAttributeArrayType::Double:         result = GL_DOUBLE;         break;
        case OpenGL::VertexAttributeArrayType::Float:          result = GL_FLOAT;          break;
        case OpenGL::VertexAttributeArrayType::Int:            result = GL_INT;            break;
        case OpenGL::VertexAttributeArrayType::Short:          result = GL_SHORT;          break;
        case OpenGL::VertexAttributeArrayType::Unsigned_Byte:  result = GL_UNSIGNED_BYTE;  break;
        case OpenGL::VertexAttributeArrayType::Unsigned_Int:   result = GL_UNSIGNED_INT;   break;
        case OpenGL::VertexAttributeArrayType::Unsigned_Short: result = GL_UNSIGNED_SHORT; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_vertex_attribute_property(const OpenGL::VertexAttributeProperty& in_property)
{
    GLenum result = 0;

    switch (in_property)
    {
        case OpenGL::VertexAttributeProperty::Array_Size:               result = GL_VERTEX_ATTRIB_ARRAY_SIZE;           break;
        case OpenGL::VertexAttributeProperty::Array_Type:               result = GL_VERTEX_ATTRIB_ARRAY_TYPE;           break;
        case OpenGL::VertexAttributeProperty::Buffer_Binding:           result = GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING; break;
        case OpenGL::VertexAttributeProperty::Current_Vertex_Attribute: result = GL_CURRENT_VERTEX_ATTRIB;              break;
        case OpenGL::VertexAttributeProperty::Enabled:                  result = GL_VERTEX_ATTRIB_ARRAY_ENABLED;        break;
        case OpenGL::VertexAttributeProperty::Integer:                  result = GL_VERTEX_ATTRIB_ARRAY_INTEGER;        break;
        case OpenGL::VertexAttributeProperty::Normalized:               result = GL_VERTEX_ATTRIB_ARRAY_NORMALIZED;     break;
        case OpenGL::VertexAttributeProperty::Stride:                   result = GL_VERTEX_ATTRIB_ARRAY_STRIDE;         break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_wait_result(const OpenGL::WaitResult& in_result)
{
    GLenum result = 0;

    switch (in_result)
    {
        case OpenGL::WaitResult::Already_Signaled:    result = GL_ALREADY_SIGNALED;    break;
        case OpenGL::WaitResult::Condition_Satisfied: result = GL_CONDITION_SATISFIED; break;
        case OpenGL::WaitResult::Timeout_Expired:     result = GL_TIMEOUT_EXPIRED;     break;
        case OpenGL::WaitResult::Wait_Failed:         result = GL_WAIT_FAILED;         break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::WaitResult OpenGL::Utils::get_wait_result_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::WaitResult result = OpenGL::WaitResult::Unknown;

    switch (in_enum)
    {
        case GL_ALREADY_SIGNALED:    result = OpenGL::WaitResult::Already_Signaled;    break;
        case GL_CONDITION_SATISFIED: result = OpenGL::WaitResult::Condition_Satisfied; break;
        case GL_TIMEOUT_EXPIRED:     result = OpenGL::WaitResult::Timeout_Expired;     break;
        case GL_WAIT_FAILED:         result = OpenGL::WaitResult::Wait_Failed;         break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

GLenum OpenGL::Utils::get_gl_enum_for_wait_sync_bits(const OpenGL::WaitSyncBits& in_bits)
{
    GLenum result = 0;

    if (in_bits & OpenGL::WaitSyncBit::Sync_Flush_Commands_Bit)
    {
        result |= GL_SYNC_FLUSH_COMMANDS_BIT;
    }

    return result;
}

OpenGL::HintMode OpenGL::Utils::get_hint_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::HintMode result = OpenGL::HintMode::Unknown;

    switch (in_enum)
    {
        case GL_DONT_CARE: result = OpenGL::HintMode::Dont_Care; break;
        case GL_FASTEST:   result = OpenGL::HintMode::Fastest;   break;
        case GL_NICEST:    result = OpenGL::HintMode::Nicest;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

void OpenGL::Utils::get_indexed_capability_for_gl_enum(const GLenum&    in_enum,
                                                    OpenGL::Capability* out_capability_ptr,
                                                    uint32_t*         out_index_ptr)
{
    if (in_enum >= GL_CLIP_DISTANCE0 &&
        in_enum <= GL_CLIP_DISTANCE7)   /* todo: there may be more clip distances supported ! */
    {
        *out_capability_ptr = OpenGL::Capability::Clip_Distance;
        *out_index_ptr      = in_enum - GL_CLIP_DISTANCE0;
    }
    else
    {
        vkgl_assert_fail();

        *out_capability_ptr = OpenGL::Capability::Unknown;
    }
}

OpenGL::HintTarget OpenGL::Utils::get_hint_target_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::HintTarget result = OpenGL::HintTarget::Unknown;

    switch (in_enum)
    {
        case GL_FRAGMENT_SHADER_DERIVATIVE_HINT: result = OpenGL::HintTarget::Fragment_Shader_Derivative; break;
        case GL_LINE_SMOOTH_HINT:                result = OpenGL::HintTarget::Line_Smooth;                break;
        case GL_POLYGON_SMOOTH_HINT:             result = OpenGL::HintTarget::Polygon_Smooth;             break;
        case GL_TEXTURE_COMPRESSION_HINT:        result = OpenGL::HintTarget::Texture_Compression;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::InternalFormat OpenGL::Utils::get_internal_format_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::InternalFormat result = OpenGL::InternalFormat::Unknown;

    switch (in_enum)
    {
        /* Base internal formats */
        case GL_DEPTH_COMPONENT: result = OpenGL::InternalFormat::Depth_Component; break;
        case GL_DEPTH_STENCIL:   result = OpenGL::InternalFormat::Depth_Stencil;   break;
        case GL_RED:             result = OpenGL::InternalFormat::Red;             break;
        case GL_RG:              result = OpenGL::InternalFormat::RG;              break;
        case GL_RGB:             result = OpenGL::InternalFormat::RGB;             break;
        case GL_RGBA:            result = OpenGL::InternalFormat::RGBA;            break;

        /* Sized internal formats */
        case GL_R11F_G11F_B10F: result = OpenGL::InternalFormat::R11F_G11F_B10F; break;
        case GL_R16:            result = OpenGL::InternalFormat::R16;            break;
        case GL_R16_SNORM:      result = OpenGL::InternalFormat::R16_SNorm;      break;
        case GL_R16F:           result = OpenGL::InternalFormat::R16F;           break;
        case GL_R16I:           result = OpenGL::InternalFormat::R16I;           break;
        case GL_R16UI:          result = OpenGL::InternalFormat::R16UI;          break;
        case GL_R3_G3_B2:       result = OpenGL::InternalFormat::R3_G3_B2;       break;
        case GL_R32F:           result = OpenGL::InternalFormat::R32F;           break;
        case GL_R32I:           result = OpenGL::InternalFormat::R32I;           break;
        case GL_R32UI:          result = OpenGL::InternalFormat::R32UI;          break;
        case GL_R8:             result = OpenGL::InternalFormat::R8;             break;
        case GL_R8_SNORM:       result = OpenGL::InternalFormat::R8_SNorm;       break;
        case GL_R8I:            result = OpenGL::InternalFormat::R8I;            break;
        case GL_R8UI:           result = OpenGL::InternalFormat::R8UI;           break;
        case GL_RG16:           result = OpenGL::InternalFormat::RG16;           break;
        case GL_RG16_SNORM:     result = OpenGL::InternalFormat::RG16_SNorm;     break;
        case GL_RG16F:          result = OpenGL::InternalFormat::RG16F;          break;
        case GL_RG16I:          result = OpenGL::InternalFormat::RG16I;          break;
        case GL_RG16UI:         result = OpenGL::InternalFormat::RG16UI;         break;
        case GL_RG32F:          result = OpenGL::InternalFormat::RG32F;          break;
        case GL_RG32I:          result = OpenGL::InternalFormat::RG32I;          break;
        case GL_RG32UI:         result = OpenGL::InternalFormat::RG32UI;         break;
        case GL_RG8:            result = OpenGL::InternalFormat::RG8;            break;
        case GL_RG8_SNORM:      result = OpenGL::InternalFormat::RG8_SNorm;      break;
        case GL_RG8I:           result = OpenGL::InternalFormat::RG8I;           break;
        case GL_RG8UI:          result = OpenGL::InternalFormat::RG8UI;          break;
        case GL_RGB10:          result = OpenGL::InternalFormat::RGB10;          break;
        case GL_RGB10_A2:       result = OpenGL::InternalFormat::RGB10_A2;       break;
        case GL_RGB10_A2UI:     result = OpenGL::InternalFormat::RGB10_A2UI;     break;
        case GL_RGB12:          result = OpenGL::InternalFormat::RGB12;          break;
        case GL_RGB16_SNORM:    result = OpenGL::InternalFormat::RGB16_SNorm;    break;
        case GL_RGB16F:         result = OpenGL::InternalFormat::RGB16F;         break;
        case GL_RGB16I:         result = OpenGL::InternalFormat::RGB16I;         break;
        case GL_RGB16UI:        result = OpenGL::InternalFormat::RGB16UI;        break;
        case GL_RGB32F:         result = OpenGL::InternalFormat::RGB32F;         break;
        case GL_RGB32I:         result = OpenGL::InternalFormat::RGB32I;         break;
        case GL_RGB32UI:        result = OpenGL::InternalFormat::RGB32UI;        break;
        case GL_RGB4:           result = OpenGL::InternalFormat::RGB4;           break;
        case GL_RGB5:           result = OpenGL::InternalFormat::RGB5;           break;
        case GL_RGB5_A1:        result = OpenGL::InternalFormat::RGB5_A1;        break;
        case GL_RGB8:           result = OpenGL::InternalFormat::RGB8;           break;
        case GL_RGB8_SNORM:     result = OpenGL::InternalFormat::RGB8_SNorm;     break;
        case GL_RGB8I:          result = OpenGL::InternalFormat::RGB8I;          break;
        case GL_RGB8UI:         result = OpenGL::InternalFormat::RGB8UI;         break;
        case GL_RGB9_E5:        result = OpenGL::InternalFormat::RGB9_E5;        break;
        case GL_RGBA12:         result = OpenGL::InternalFormat::RGBA12;         break;
        case GL_RGBA16:         result = OpenGL::InternalFormat::RGBA16;         break;
        case GL_RGBA16F:        result = OpenGL::InternalFormat::RGBA16F;        break;
        case GL_RGBA16I:        result = OpenGL::InternalFormat::RGBA16I;        break;
        case GL_RGBA16UI:       result = OpenGL::InternalFormat::RGBA16UI;       break;
        case GL_RGBA2:          result = OpenGL::InternalFormat::RGBA2;          break;
        case GL_RGBA32F:        result = OpenGL::InternalFormat::RGBA32F;        break;
        case GL_RGBA32I:        result = OpenGL::InternalFormat::RGBA32I;        break;
        case GL_RGBA32UI:       result = OpenGL::InternalFormat::RGBA32UI;       break;
        case GL_RGBA4:          result = OpenGL::InternalFormat::RGBA4;          break;
        case GL_RGBA8:          result = OpenGL::InternalFormat::RGBA8;          break;
        case GL_RGBA8_SNORM:    result = OpenGL::InternalFormat::RGBA8_SNorm;    break;
        case GL_RGBA8I:         result = OpenGL::InternalFormat::RGBA8I;         break;
        case GL_RGBA8UI:        result = OpenGL::InternalFormat::RGBA8UI;        break;
        case GL_SRGB8:          result = OpenGL::InternalFormat::SRGB8;          break;
        case GL_SRGB8_ALPHA8:   result = OpenGL::InternalFormat::SRGB8_Alpha8;   break;

        /* Compressed internal formats */
        case GL_COMPRESSED_RED:                     result = OpenGL::InternalFormat::Compressed_Red;                     break;
        case GL_COMPRESSED_RED_RGTC1:               result = OpenGL::InternalFormat::Compressed_Red_RGTC1;               break;
        case GL_COMPRESSED_RG:                      result = OpenGL::InternalFormat::Compressed_RG;                      break;
        case GL_COMPRESSED_RG_RGTC2:                result = OpenGL::InternalFormat::Compressed_RG_RGTC2;                break;
        case GL_COMPRESSED_RGB:                     result = OpenGL::InternalFormat::Compressed_RGB;                     break;
        case GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:   result = OpenGL::InternalFormat::Compressed_RGB_BPTC_Signed_Float;   break;
        case GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT: result = OpenGL::InternalFormat::Compressed_RGB_BPTC_Unsigned_Float; break;
        case GL_COMPRESSED_RGBA:                    result = OpenGL::InternalFormat::Compressed_RGBA;                    break;
        case GL_COMPRESSED_RGBA_BPTC_UNORM:         result = OpenGL::InternalFormat::Compressed_RGBA_BPTC_UNorm;         break;
        case GL_COMPRESSED_SIGNED_RED_RGTC1:        result = OpenGL::InternalFormat::Compressed_Signed_Red_RGTC1;        break;
        case GL_COMPRESSED_SIGNED_RG_RGTC2:         result = OpenGL::InternalFormat::Compressed_Signed_RG_RGTC2;         break;
        case GL_COMPRESSED_SRGB:                    result = OpenGL::InternalFormat::Compressed_SRGB;                    break;
        case GL_COMPRESSED_SRGB_ALPHA:              result = OpenGL::InternalFormat::Compressed_SRGB_Alpha;              break;
        case GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:   result = OpenGL::InternalFormat::Compressed_SRGB_Alpha_BPTC_UNorm;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::LogicOpMode OpenGL::Utils::get_logic_op_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::LogicOpMode result = OpenGL::LogicOpMode::Unknown;

    switch (in_enum)
    {
        case GL_AND:           result = OpenGL::LogicOpMode::And;            break;
        case GL_AND_INVERTED:  result = OpenGL::LogicOpMode::And_Inverted;   break;
        case GL_AND_REVERSE:   result = OpenGL::LogicOpMode::And_Reverse;    break;
        case GL_CLEAR:         result = OpenGL::LogicOpMode::Clear;          break;
        case GL_COPY:          result = OpenGL::LogicOpMode::Copy;           break;
        case GL_COPY_INVERTED: result = OpenGL::LogicOpMode::Copy_Inverted;  break;
        case GL_EQUIV:         result = OpenGL::LogicOpMode::Equiv;          break;
        case GL_INVERT:        result = OpenGL::LogicOpMode::Invert;         break;
        case GL_NAND:          result = OpenGL::LogicOpMode::Nand;           break;
        case GL_NOOP:          result = OpenGL::LogicOpMode::Noop;           break;
        case GL_NOR:           result = OpenGL::LogicOpMode::Nor;            break;
        case GL_OR:            result = OpenGL::LogicOpMode::Or;             break;
        case GL_OR_INVERTED:   result = OpenGL::LogicOpMode::Or_Inverted;    break;
        case GL_OR_REVERSE:    result = OpenGL::LogicOpMode::Or_Reverse;     break;
        case GL_SET:           result = OpenGL::LogicOpMode::Set;            break;
        case GL_XOR:           result = OpenGL::LogicOpMode::Xor;            break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::MipmapGenerationTextureTarget OpenGL::Utils::get_mipmap_generation_texture_target_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::MipmapGenerationTextureTarget result = OpenGL::MipmapGenerationTextureTarget::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_1D:       result = OpenGL::MipmapGenerationTextureTarget::Texture_1D;       break;
        case GL_TEXTURE_1D_ARRAY: result = OpenGL::MipmapGenerationTextureTarget::Texture_1D_Array; break;
        case GL_TEXTURE_2D:       result = OpenGL::MipmapGenerationTextureTarget::Texture_2D;       break;
        case GL_TEXTURE_2D_ARRAY: result = OpenGL::MipmapGenerationTextureTarget::Texture_2D_Array; break;
        case GL_TEXTURE_3D:       result = OpenGL::MipmapGenerationTextureTarget::Texture_3D;       break;
        case GL_TEXTURE_CUBE_MAP: result = OpenGL::MipmapGenerationTextureTarget::Texture_Cube_Map; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::Capability OpenGL::Utils::get_nonindexed_capability_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::Capability result = OpenGL::Capability::Unknown;

    switch (in_enum)
    {
        case GL_BLEND:                     result = OpenGL::Capability::Blend;                     break;
        case GL_COLOR_LOGIC_OP:            result = OpenGL::Capability::Color_Logic_Op;            break;
        case GL_CULL_FACE:                 result = OpenGL::Capability::Cull_Face;                 break;
        case GL_DEPTH_CLAMP:               result = OpenGL::Capability::Depth_Clamp;               break;
        case GL_DEPTH_TEST:                result = OpenGL::Capability::Depth_Test;                break;
        case GL_DITHER:                    result = OpenGL::Capability::Dither;                    break;
        case GL_FRAMEBUFFER_SRGB:          result = OpenGL::Capability::Framebuffer_SRGB;          break;
        case GL_LINE_SMOOTH:               result = OpenGL::Capability::Line_Smooth;               break;
        case GL_MULTISAMPLE:               result = OpenGL::Capability::Multisample;               break;
        case GL_POLYGON_OFFSET_FILL:       result = OpenGL::Capability::Polygon_Offset_Fill;       break;
        case GL_POLYGON_OFFSET_LINE:       result = OpenGL::Capability::Polygon_Offset_Line;       break;
        case GL_POLYGON_OFFSET_POINT:      result = OpenGL::Capability::Polygon_Offset_Point;      break;
        case GL_POLYGON_SMOOTH:            result = OpenGL::Capability::Polygon_Smooth;            break;
        case GL_PRIMITIVE_RESTART:         result = OpenGL::Capability::Primitive_Restart;         break;
        case GL_PROGRAM_POINT_SIZE:        result = OpenGL::Capability::Program_Point_Size;        break;
        case GL_SAMPLE_ALPHA_TO_COVERAGE:  result = OpenGL::Capability::Sample_Alpha_To_Coverage;  break;
        case GL_SAMPLE_ALPHA_TO_ONE:       result = OpenGL::Capability::Sample_Alpha_To_One;       break;
        case GL_SAMPLE_COVERAGE:           result = OpenGL::Capability::Sample_Coverage;           break;
        case GL_SCISSOR_TEST:              result = OpenGL::Capability::Scissor_Test;              break;
        case GL_STENCIL_TEST:              result = OpenGL::Capability::Stencil_Test;              break;
        case GL_TEXTURE_CUBE_MAP_SEAMLESS: result = OpenGL::Capability::Texture_Cube_Map_Seamless; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::PixelFormat OpenGL::Utils::get_pixel_format_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::PixelFormat result = OpenGL::PixelFormat::Unknown;

    switch (in_enum)
    {
        case GL_BLUE:            result = OpenGL::PixelFormat::Blue;            break;
        case GL_BLUE_INTEGER:    result = OpenGL::PixelFormat::Blue_Integer;    break;
        case GL_BGR:             result = OpenGL::PixelFormat::BGR;             break;
        case GL_BGR_INTEGER:     result = OpenGL::PixelFormat::BGR_Integer;     break;
        case GL_BGRA:            result = OpenGL::PixelFormat::BGRA;            break;
        case GL_BGRA_INTEGER:    result = OpenGL::PixelFormat::BGRA_Integer;    break;
        case GL_DEPTH_COMPONENT: result = OpenGL::PixelFormat::Depth_Component; break;
        case GL_DEPTH_STENCIL:   result = OpenGL::PixelFormat::Depth_Stencil;   break;
        case GL_GREEN:           result = OpenGL::PixelFormat::Green;           break;
        case GL_GREEN_INTEGER:   result = OpenGL::PixelFormat::Green_Integer;   break;
        case GL_RED:             result = OpenGL::PixelFormat::Red;             break;
        case GL_RED_INTEGER:     result = OpenGL::PixelFormat::Red_Integer;     break;
        case GL_RG:              result = OpenGL::PixelFormat::RG;              break;
        case GL_RG_INTEGER:      result = OpenGL::PixelFormat::RG_Integer;      break;
        case GL_RGB:             result = OpenGL::PixelFormat::RGB;             break;
        case GL_RGB_INTEGER:     result = OpenGL::PixelFormat::RGB_Integer;     break;
        case GL_RGBA:            result = OpenGL::PixelFormat::RGBA;            break;
        case GL_RGBA_INTEGER:    result = OpenGL::PixelFormat::RGBA_Integer;    break;
        case GL_STENCIL_INDEX:   result = OpenGL::PixelFormat::Stencil_Index;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::PixelStoreProperty OpenGL::Utils::get_pixel_store_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::PixelStoreProperty result = OpenGL::PixelStoreProperty::Unknown;

    switch (in_enum)
    {
        case GL_PACK_ALIGNMENT:      result = OpenGL::PixelStoreProperty::Pack_Alignment;      break;
        case GL_PACK_IMAGE_HEIGHT:   result = OpenGL::PixelStoreProperty::Pack_Image_Height;   break;
        case GL_PACK_LSB_FIRST:      result = OpenGL::PixelStoreProperty::Pack_LSB_First;      break;
        case GL_PACK_ROW_LENGTH:     result = OpenGL::PixelStoreProperty::Pack_Row_Length;     break;
        case GL_PACK_SKIP_IMAGES:    result = OpenGL::PixelStoreProperty::Pack_Skip_Images;    break;
        case GL_PACK_SKIP_PIXELS:    result = OpenGL::PixelStoreProperty::Pack_Skip_Pixels;    break;
        case GL_PACK_SKIP_ROWS:      result = OpenGL::PixelStoreProperty::Pack_Skip_Rows;      break;
        case GL_PACK_SWAP_BYTES:     result = OpenGL::PixelStoreProperty::Pack_Swap_Bytes;     break;
        case GL_UNPACK_ALIGNMENT:    result = OpenGL::PixelStoreProperty::Unpack_Alignment;    break;
        case GL_UNPACK_IMAGE_HEIGHT: result = OpenGL::PixelStoreProperty::Unpack_Image_Height; break;
        case GL_UNPACK_LSB_FIRST:    result = OpenGL::PixelStoreProperty::Unpack_LSB_First;    break;
        case GL_UNPACK_ROW_LENGTH:   result = OpenGL::PixelStoreProperty::Unpack_Row_Length;   break;
        case GL_UNPACK_SKIP_IMAGES:  result = OpenGL::PixelStoreProperty::Unpack_Skip_Images;  break;
        case GL_UNPACK_SKIP_PIXELS:  result = OpenGL::PixelStoreProperty::Unpack_Skip_Pixels;  break;
        case GL_UNPACK_SKIP_ROWS:    result = OpenGL::PixelStoreProperty::Unpack_Skip_Rows;    break;
        case GL_UNPACK_SWAP_BYTES:   result = OpenGL::PixelStoreProperty::Unpack_Swap_Bytes;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::PixelStoreProperty OpenGL::Utils::get_pixel_store_property_from_context_property(const OpenGL::ContextProperty& in_context_property)
{
    OpenGL::PixelStoreProperty result = OpenGL::PixelStoreProperty::Unknown;

    switch (in_context_property)
    {
        case OpenGL::ContextProperty::Pack_Alignment:      result = OpenGL::PixelStoreProperty::Pack_Alignment;      break;
        case OpenGL::ContextProperty::Pack_Image_Height:   result = OpenGL::PixelStoreProperty::Pack_Image_Height;   break;
        case OpenGL::ContextProperty::Pack_LSB_First:      result = OpenGL::PixelStoreProperty::Pack_LSB_First;      break;
        case OpenGL::ContextProperty::Pack_Row_Length:     result = OpenGL::PixelStoreProperty::Pack_Row_Length;     break;
        case OpenGL::ContextProperty::Pack_Skip_Images:    result = OpenGL::PixelStoreProperty::Pack_Skip_Images;    break;
        case OpenGL::ContextProperty::Pack_Skip_Pixels:    result = OpenGL::PixelStoreProperty::Pack_Skip_Pixels;    break;
        case OpenGL::ContextProperty::Pack_Skip_Rows:      result = OpenGL::PixelStoreProperty::Pack_Skip_Rows;      break;
        case OpenGL::ContextProperty::Pack_Swap_Bytes:     result = OpenGL::PixelStoreProperty::Pack_Swap_Bytes;     break;
        case OpenGL::ContextProperty::Unpack_Alignment:    result = OpenGL::PixelStoreProperty::Unpack_Alignment;    break;
        case OpenGL::ContextProperty::Unpack_Image_Height: result = OpenGL::PixelStoreProperty::Unpack_Image_Height; break;
        case OpenGL::ContextProperty::Unpack_LSB_First:    result = OpenGL::PixelStoreProperty::Unpack_LSB_First;    break;
        case OpenGL::ContextProperty::Unpack_Row_Length:   result = OpenGL::PixelStoreProperty::Unpack_Row_Length;   break;
        case OpenGL::ContextProperty::Unpack_Skip_Images:  result = OpenGL::PixelStoreProperty::Unpack_Skip_Images;  break;
        case OpenGL::ContextProperty::Unpack_Skip_Pixels:  result = OpenGL::PixelStoreProperty::Unpack_Skip_Pixels;  break;
        case OpenGL::ContextProperty::Unpack_Skip_Rows:    result = OpenGL::PixelStoreProperty::Unpack_Skip_Rows;    break;
        case OpenGL::ContextProperty::Unpack_Swap_Bytes:   result = OpenGL::PixelStoreProperty::Unpack_Swap_Bytes;   break;
    }

    return result;
}

OpenGL::PixelType OpenGL::Utils::get_pixel_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::PixelType result = OpenGL::PixelType::Unknown;

    switch (in_enum)
    {
        case GL_FLOAT:                          result = OpenGL::PixelType::Float;                           break;
        case GL_FLOAT_32_UNSIGNED_INT_24_8_REV: result = OpenGL::PixelType::Float_32_Unsigned_Int_24_8_Rev;  break;
        case GL_HALF_FLOAT:                     result = OpenGL::PixelType::Half_Float;                      break;
        case GL_INT:                            result = OpenGL::PixelType::Int;                             break;
        case GL_SHORT:                          result = OpenGL::PixelType::Short;                           break;
        case GL_UNSIGNED_BYTE:                  result = OpenGL::PixelType::Unsigned_Byte;                   break;
        case GL_UNSIGNED_BYTE_2_3_3_REV:        result = OpenGL::PixelType::Unsigned_Byte_2_3_3_Rev;         break;
        case GL_UNSIGNED_BYTE_3_3_2:            result = OpenGL::PixelType::Unsigned_Byte_3_3_2;             break;
        case GL_UNSIGNED_INT:                   result = OpenGL::PixelType::Unsigned_Int;                    break;
        case GL_UNSIGNED_INT_10_10_10_2:        result = OpenGL::PixelType::Unsigned_Int_10_10_10_2;         break;
        case GL_UNSIGNED_INT_10F_11F_11F_REV:   result = OpenGL::PixelType::Unsigned_Int_10F_11F_11F_Rev;    break;
        case GL_UNSIGNED_INT_2_10_10_10_REV:    result = OpenGL::PixelType::Unsigned_Int_2_10_10_10_Rev;     break;
        case GL_UNSIGNED_INT_24_8:              result = OpenGL::PixelType::Unsigned_Int_24_8;               break;
        case GL_UNSIGNED_INT_5_9_9_9_REV:       result = OpenGL::PixelType::Unsigned_Int_5_9_9_9_Rev;        break;
        case GL_UNSIGNED_INT_8_8_8_8:           result = OpenGL::PixelType::Unsigned_Int_8_8_8_8;            break;
        case GL_UNSIGNED_INT_8_8_8_8_REV:       result = OpenGL::PixelType::Unsigned_Int_8_8_8_8_Rev;        break;
        case GL_UNSIGNED_SHORT:                 result = OpenGL::PixelType::Unsigned_Short;                  break;
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:     result = OpenGL::PixelType::Unsigned_Short_1_5_5_5_Rev;      break;
        case GL_UNSIGNED_SHORT_4_4_4_4:         result = OpenGL::PixelType::Unsigned_Short_4_4_4_4;          break;
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:     result = OpenGL::PixelType::Unsigned_Short_4_4_4_4_Rev;      break;
        case GL_UNSIGNED_SHORT_5_5_5_1:         result = OpenGL::PixelType::Unsigned_Short_5_5_5_1;          break;
        case GL_UNSIGNED_SHORT_5_6_5:           result = OpenGL::PixelType::Unsigned_Short_5_6_5;            break;
        case GL_UNSIGNED_SHORT_5_6_5_REV:       result = OpenGL::PixelType::Unsigned_Short_5_6_5_Rev;        break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::PointProperty OpenGL::Utils::get_point_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::PointProperty result = OpenGL::PointProperty::Unknown;

    switch (in_enum)
    {
        case GL_POINT_FADE_THRESHOLD_SIZE: result = OpenGL::PointProperty::Fade_Threshold_Size; break;
        case GL_POINT_SPRITE_COORD_ORIGIN: result = OpenGL::PointProperty::Sprite_Coord_Origin; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::PointSpriteCoordOrigin OpenGL::Utils::get_point_sprite_coord_origin_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::PointSpriteCoordOrigin result = OpenGL::PointSpriteCoordOrigin::Unknown;

    switch (in_enum)
    {
        case GL_LOWER_LEFT: result = OpenGL::PointSpriteCoordOrigin::Lower_Left; break;
        case GL_UPPER_LEFT: result = OpenGL::PointSpriteCoordOrigin::Upper_Left; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::PolygonMode OpenGL::Utils::get_polygon_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::PolygonMode result = OpenGL::PolygonMode::Unknown;

    switch (in_enum)
    {
        case GL_FILL:  result = OpenGL::PolygonMode::Fill;  break;
        case GL_LINE:  result = OpenGL::PolygonMode::Line;  break;
        case GL_POINT: result = OpenGL::PolygonMode::Point; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ProgramProperty OpenGL::Utils::get_program_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ProgramProperty result = OpenGL::ProgramProperty::Unknown;

    switch (in_enum)
    {
        case GL_ACTIVE_ATTRIBUTES:                     result = OpenGL::ProgramProperty::Active_Attributes;                     break;
        case GL_ACTIVE_ATTRIBUTE_MAX_LENGTH:           result = OpenGL::ProgramProperty::Active_Attribute_Max_Length;           break;
        case GL_ACTIVE_UNIFORMS:                       result = OpenGL::ProgramProperty::Active_Uniforms;                       break;
        case GL_ACTIVE_UNIFORM_BLOCKS:                 result = OpenGL::ProgramProperty::Active_Uniform_Blocks;                 break;
        case GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH:  result = OpenGL::ProgramProperty::Active_Uniform_Block_Max_Name_Length;  break;
        case GL_ACTIVE_UNIFORM_MAX_LENGTH:             result = OpenGL::ProgramProperty::Active_Uniform_Max_Length;             break;
        case GL_ATTACHED_SHADERS:                      result = OpenGL::ProgramProperty::Attached_Shaders;                      break;
        case GL_DELETE_STATUS:                         result = OpenGL::ProgramProperty::Delete_Status;                         break;
        case GL_GEOMETRY_INPUT_TYPE:                   result = OpenGL::ProgramProperty::Geometry_Input_Type;                   break;
        case GL_GEOMETRY_OUTPUT_TYPE:                  result = OpenGL::ProgramProperty::Geometry_Output_Type;                  break;
        case GL_GEOMETRY_VERTICES_OUT:                 result = OpenGL::ProgramProperty::Geometry_Vertices_Out;                 break;
        case GL_INFO_LOG_LENGTH:                       result = OpenGL::ProgramProperty::Info_Log_Length;                       break;
        case GL_LINK_STATUS:                           result = OpenGL::ProgramProperty::Link_Status;                           break;
        case GL_TRANSFORM_FEEDBACK_BUFFER_MODE:        result = OpenGL::ProgramProperty::Transform_Feedback_Buffer_Mode;        break;
        case GL_TRANSFORM_FEEDBACK_VARYINGS:           result = OpenGL::ProgramProperty::Transform_Feedback_Varyings;           break;
        case GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH: result = OpenGL::ProgramProperty::Transform_Feedback_Varying_Max_Length; break;
        case GL_VALIDATE_STATUS:                       result = OpenGL::ProgramProperty::Validate_Status;                       break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ProvokingVertexConvention OpenGL::Utils::get_provoking_vertex_convention_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ProvokingVertexConvention result = OpenGL::ProvokingVertexConvention::Unknown;

    switch (in_enum)
    {
        case GL_FIRST_VERTEX_CONVENTION: result = OpenGL::ProvokingVertexConvention::First; break;
        case GL_LAST_VERTEX_CONVENTION:  result = OpenGL::ProvokingVertexConvention::Last;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::QueryProperty OpenGL::Utils::get_query_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::QueryProperty result = OpenGL::QueryProperty::Unknown;

    switch (in_enum)
    {
        case GL_QUERY_RESULT:           result = OpenGL::QueryProperty::Query_Result;           break;
        case GL_QUERY_RESULT_AVAILABLE: result = OpenGL::QueryProperty::Query_Result_Available; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::QueryTarget OpenGL::Utils::get_query_target_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::QueryTarget result = OpenGL::QueryTarget::Unknown;

    switch (in_enum)
    {
        case GL_PRIMITIVES_GENERATED:                  result = OpenGL::QueryTarget::Primitives_Generated;                  break;
        case GL_SAMPLES_PASSED:                        result = OpenGL::QueryTarget::Samples_Passed;                        break;
        case GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN: result = OpenGL::QueryTarget::Transform_Feedback_Primitives_Written; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::QueryTargetProperty OpenGL::Utils::get_query_target_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::QueryTargetProperty result = OpenGL::QueryTargetProperty::Unknown;

    switch (in_enum)
    {
        case GL_CURRENT_QUERY:      result = OpenGL::QueryTargetProperty::Current_Query;      break;
        case GL_QUERY_COUNTER_BITS: result = OpenGL::QueryTargetProperty::Query_Counter_Bits; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

const char* OpenGL::Utils::get_raw_string_for_gl_bitfield(const OpenGL::BitfieldType& in_bitfield,
                                                          const GLenum&               in_enum)
{
    static VKGL_THREADLOCAL char result[MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE];

    switch (in_bitfield)
    {
        case OpenGL::BitfieldType::Blit_Mask:
        case OpenGL::BitfieldType::Clear_Buffer_Mask:
        {
            snprintf(result,
                     sizeof(result),
                     "%s | %s | %s",
                     (in_enum & GL_COLOR_BUFFER_BIT)   ? "GL_COLOR_BUFFER_BIT"   : "0",
                     (in_enum & GL_DEPTH_BUFFER_BIT)   ? "GL_DEPTH_BUFFER_BIT"   : "0",
                     (in_enum & GL_STENCIL_BUFFER_BIT) ? "GL_STENCIL_BUFFER_BIT" : "0");

            break;
        }

        case OpenGL::BitfieldType::Buffer_Access_Mask:
        {
            snprintf(result,
                     sizeof(result),
                     "%s | %s | %s | %s | %s | %s",
                     (in_enum & GL_MAP_FLUSH_EXPLICIT_BIT)    ? "GL_MAP_FLUSH_EXPLICIT_BIT"    : "0",
                     (in_enum & GL_MAP_INVALIDATE_BUFFER_BIT) ? "GL_MAP_INVALIDATE_BUFFER_BIT" : "0",
                     (in_enum & GL_MAP_INVALIDATE_RANGE_BIT)  ? "GL_MAP_INVALIDATE_RANGE_BIT"  : "0",
                     (in_enum & GL_MAP_READ_BIT)              ? "GL_MAP_READ_BIT"              : "0",
                     (in_enum & GL_MAP_WRITE_BIT)             ? "GL_MAP_WRITE_BIT"             : "0",
                     (in_enum & GL_MAP_UNSYNCHRONIZED_BIT)    ? "GL_MAP_UNSYNCHRONIZED_BIT"    : "0");

            break;

        }

        case OpenGL::BitfieldType::Sync_Condition_Mask:
        {
            vkgl_assert(in_enum == GL_SYNC_GPU_COMMANDS_COMPLETE);

            snprintf(result,
                     sizeof(result),
                     "GL_SYNC_GPU_COMMANDS_COMPLETE");

            break;
        }

        case OpenGL::BitfieldType::Wait_Sync_Mask:
        {
            snprintf(result,
                     sizeof(result),
                     "%s",
                     (in_enum & GL_SYNC_FLUSH_COMMANDS_BIT) ? "GL_SYNC_FLUSH_COMMANDS_BIT" : "0");

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

const char* OpenGL::Utils::get_raw_string_for_gl_enum(const GLenum& in_enum)
{
    const char* result = "???";

    /* Holds enums up to GL 3.2 (core profile). Does not include _BIT #defines. */
    static const std::unordered_map<GLenum, std::string> entries =
    {
        /* GL 1.0 */
        {GL_FALSE,                   "GL_FALSE"},
        {GL_TRUE,                    "GL_TRUE"},
        {GL_POINTS,                  "GL_POINTS"},
        {GL_LINES,                   "GL_LINES"},
        {GL_LINE_LOOP,               "GL_LINE_LOOP"},
        {GL_LINE_STRIP,              "GL_LINE_STRIP"},
        {GL_TRIANGLES,               "GL_TRIANGLES"},
        {GL_TRIANGLE_STRIP,          "GL_TRIANGLE_STRIP"},
        {GL_TRIANGLE_FAN,            "GL_TRIANGLE_FAN"},
        {GL_QUADS,                   "GL_QUADS"},
        {GL_NEVER,                   "GL_NEVER"},
        {GL_LESS,                    "GL_LESS"},
        {GL_EQUAL,                   "GL_EQUAL"},
        {GL_LEQUAL,                  "GL_LEQUAL"},
        {GL_GREATER,                 "GL_GREATER"},
        {GL_NOTEQUAL,                "GL_NOTEQUAL"},
        {GL_GEQUAL,                  "GL_GEQUAL"},
        {GL_ALWAYS,                  "GL_ALWAYS"},
        {GL_ZERO,                    "GL_ZERO"},
        {GL_ONE,                     "GL_ONE"},
        {GL_SRC_COLOR,               "GL_SRC_COLOR"},
        {GL_ONE_MINUS_SRC_COLOR,     "GL_ONE_MINUS_SRC_COLOR"},
        {GL_SRC_ALPHA,               "GL_SRC_ALPHA"},
        {GL_ONE_MINUS_SRC_ALPHA,     "GL_ONE_MINUS_SRC_ALPHA"},
        {GL_DST_ALPHA,               "GL_DST_ALPHA"},
        {GL_ONE_MINUS_DST_ALPHA,     "GL_ONE_MINUS_DST_ALPHA"},
        {GL_DST_COLOR,               "GL_DST_COLOR"},
        {GL_ONE_MINUS_DST_COLOR,     "GL_ONE_MINUS_DST_COLOR"},
        {GL_SRC_ALPHA_SATURATE,      "GL_SRC_ALPHA_SATURATE"},
        {GL_NONE,                    "GL_NONE"},
        {GL_FRONT_LEFT,              "GL_FRONT_LEFT"},
        {GL_FRONT_RIGHT,             "GL_FRONT_RIGHT"},
        {GL_BACK_LEFT,               "GL_BACK_LEFT"},
        {GL_BACK_RIGHT,              "GL_BACK_RIGHT"},
        {GL_FRONT,                   "GL_FRONT"},
        {GL_BACK,                    "GL_BACK"},
        {GL_LEFT,                    "GL_LEFT"},
        {GL_RIGHT,                   "GL_RIGHT"},
        {GL_FRONT_AND_BACK,          "GL_FRONT_AND_BACK"},
        {GL_NO_ERROR,                "GL_NO_ERROR"},
        {GL_INVALID_ENUM,            "GL_INVALID_ENUM"},
        {GL_INVALID_VALUE,           "GL_INVALID_VALUE"},
        {GL_INVALID_OPERATION,       "GL_INVALID_OPERATION"},
        {GL_OUT_OF_MEMORY,           "GL_OUT_OF_MEMORY"},
        {GL_CW,                      "GL_CW"},
        {GL_CCW,                     "GL_CCW"},
        {GL_POINT_SIZE,              "GL_POINT_SIZE"},
        {GL_POINT_SIZE_RANGE,        "GL_POINT_SIZE_RANGE"},
        {GL_POINT_SIZE_GRANULARITY,  "GL_POINT_SIZE_GRANULARITY"},
        {GL_LINE_SMOOTH,             "GL_LINE_SMOOTH"},
        {GL_LINE_WIDTH,              "GL_LINE_WIDTH"},
        {GL_LINE_WIDTH_RANGE,        "GL_LINE_WIDTH_RANGE"},
        {GL_LINE_WIDTH_GRANULARITY,  "GL_LINE_WIDTH_GRANULARITY"},
        {GL_POLYGON_MODE,            "GL_POLYGON_MODE"},
        {GL_POLYGON_SMOOTH,          "GL_POLYGON_SMOOTH"},
        {GL_CULL_FACE,               "GL_CULL_FACE"},
        {GL_CULL_FACE_MODE,          "GL_CULL_FACE_MODE"},
        {GL_FRONT_FACE,              "GL_FRONT_FACE"},
        {GL_DEPTH_RANGE,             "GL_DEPTH_RANGE"},
        {GL_DEPTH_TEST,              "GL_DEPTH_TEST"},
        {GL_DEPTH_WRITEMASK,         "GL_DEPTH_WRITEMASK"},
        {GL_DEPTH_CLEAR_VALUE,       "GL_DEPTH_CLEAR_VALUE"},
        {GL_DEPTH_FUNC,              "GL_DEPTH_FUNC"},
        {GL_STENCIL_TEST,            "GL_STENCIL_TEST"},
        {GL_STENCIL_CLEAR_VALUE,     "GL_STENCIL_CLEAR_VALUE"},
        {GL_STENCIL_FUNC,            "GL_STENCIL_FUNC"},
        {GL_STENCIL_VALUE_MASK,      "GL_STENCIL_VALUE_MASK"},
        {GL_STENCIL_FAIL,            "GL_STENCIL_FAIL"},
        {GL_STENCIL_PASS_DEPTH_FAIL, "GL_STENCIL_PASS_DEPTH_FAIL"},
        {GL_STENCIL_PASS_DEPTH_PASS, "GL_STENCIL_PASS_DEPTH_PASS"},
        {GL_STENCIL_REF,             "GL_STENCIL_REF"},
        {GL_STENCIL_WRITEMASK,       "GL_STENCIL_WRITEMASK"},
        {GL_VIEWPORT,                "GL_VIEWPORT"},
        {GL_DITHER,                  "GL_DITHER"},
        {GL_BLEND_DST,               "GL_BLEND_DST"},
        {GL_BLEND_SRC,               "GL_BLEND_SRC"},
        {GL_BLEND,                   "GL_BLEND"},
        {GL_LOGIC_OP_MODE,           "GL_LOGIC_OP_MODE"},
        {GL_DRAW_BUFFER,             "GL_DRAW_BUFFER"},
        {GL_READ_BUFFER,             "GL_READ_BUFFER"},
        {GL_SCISSOR_BOX,             "GL_SCISSOR_BOX"},
        {GL_SCISSOR_TEST,            "GL_SCISSOR_TEST"},
        {GL_COLOR_CLEAR_VALUE,       "GL_COLOR_CLEAR_VALUE"},
        {GL_COLOR_WRITEMASK,         "GL_COLOR_WRITEMASK"},
        {GL_DOUBLEBUFFER,            "GL_DOUBLEBUFFER"},
        {GL_STEREO,                  "GL_STEREO"},
        {GL_LINE_SMOOTH_HINT,        "GL_LINE_SMOOTH_HINT"},
        {GL_POLYGON_SMOOTH_HINT,     "GL_POLYGON_SMOOTH_HINT"},
        {GL_UNPACK_SWAP_BYTES,       "GL_UNPACK_SWAP_BYTES"},
        {GL_UNPACK_LSB_FIRST,        "GL_UNPACK_LSB_FIRST"},
        {GL_UNPACK_ROW_LENGTH,       "GL_UNPACK_ROW_LENGTH"},
        {GL_UNPACK_SKIP_ROWS,        "GL_UNPACK_SKIP_ROWS"},
        {GL_UNPACK_SKIP_PIXELS,      "GL_UNPACK_SKIP_PIXELS"},
        {GL_UNPACK_ALIGNMENT,        "GL_UNPACK_ALIGNMENT"},
        {GL_PACK_SWAP_BYTES,         "GL_PACK_SWAP_BYTES"},
        {GL_PACK_LSB_FIRST,          "GL_PACK_LSB_FIRST"},
        {GL_PACK_ROW_LENGTH,         "GL_PACK_ROW_LENGTH"},
        {GL_PACK_SKIP_ROWS,          "GL_PACK_SKIP_ROWS"},
        {GL_PACK_SKIP_PIXELS,        "GL_PACK_SKIP_PIXELS"},
        {GL_PACK_ALIGNMENT,          "GL_PACK_ALIGNMENT"},
        {GL_MAX_TEXTURE_SIZE,        "GL_MAX_TEXTURE_SIZE"},
        {GL_MAX_VIEWPORT_DIMS,       "GL_MAX_VIEWPORT_DIMS"},
        {GL_SUBPIXEL_BITS,           "GL_SUBPIXEL_BITS"},
        {GL_TEXTURE_1D,              "GL_TEXTURE_1D"},
        {GL_TEXTURE_2D,              "GL_TEXTURE_2D"},
        {GL_TEXTURE_WIDTH,           "GL_TEXTURE_WIDTH"},
        {GL_TEXTURE_HEIGHT,          "GL_TEXTURE_HEIGHT"},
        {GL_TEXTURE_BORDER_COLOR,    "GL_TEXTURE_BORDER_COLOR"},
        {GL_DONT_CARE,               "GL_DONT_CARE"},
        {GL_FASTEST,                 "GL_FASTEST"},
        {GL_NICEST,                  "GL_NICEST"},
        {GL_BYTE,                    "GL_BYTE"},
        {GL_UNSIGNED_BYTE,           "GL_UNSIGNED_BYTE"},
        {GL_SHORT,                   "GL_SHORT"},
        {GL_UNSIGNED_SHORT,          "GL_UNSIGNED_SHORT"},
        {GL_INT,                     "GL_INT"},
        {GL_UNSIGNED_INT,            "GL_UNSIGNED_INT"},
        {GL_FLOAT,                   "GL_FLOAT"},
        {GL_STACK_OVERFLOW,          "GL_STACK_OVERFLOW"},
        {GL_STACK_UNDERFLOW,         "GL_STACK_UNDERFLOW"},
        {GL_CLEAR,                   "GL_CLEAR"},
        {GL_AND,                     "GL_AND"},
        {GL_AND_REVERSE,             "GL_AND_REVERSE"},
        {GL_COPY,                    "GL_COPY"},
        {GL_AND_INVERTED,            "GL_AND_INVERTED"},
        {GL_NOOP,                    "GL_NOOP"},
        {GL_XOR,                     "GL_XOR"},
        {GL_OR,                      "GL_OR"},
        {GL_NOR,                     "GL_NOR"},
        {GL_EQUIV,                   "GL_EQUIV"},
        {GL_INVERT,                  "GL_INVERT"},
        {GL_OR_REVERSE,              "GL_OR_REVERSE"},
        {GL_COPY_INVERTED,           "GL_COPY_INVERTED"},
        {GL_OR_INVERTED,             "GL_OR_INVERTED"},
        {GL_NAND,                    "GL_NAND"},
        {GL_SET,                     "GL_SET"},
        {GL_TEXTURE,                 "GL_TEXTURE"},
        {GL_COLOR,                   "GL_COLOR"},
        {GL_DEPTH,                   "GL_DEPTH"},
        {GL_STENCIL,                 "GL_STENCIL"},
        {GL_STENCIL_INDEX,           "GL_STENCIL_INDEX"},
        {GL_DEPTH_COMPONENT,         "GL_DEPTH_COMPONENT"},
        {GL_RED,                     "GL_RED"},
        {GL_GREEN,                   "GL_GREEN"},
        {GL_BLUE,                    "GL_BLUE"},
        {GL_ALPHA,                   "GL_ALPHA"},
        {GL_RGB,                     "GL_RGB"},
        {GL_RGBA,                    "GL_RGBA"},
        {GL_POINT,                   "GL_POINT"},
        {GL_LINE,                    "GL_LINE"},
        {GL_FILL,                    "GL_FILL"},
        {GL_KEEP,                    "GL_KEEP"},
        {GL_REPLACE,                 "GL_REPLACE"},
        {GL_INCR,                    "GL_INCR"},
        {GL_DECR,                    "GL_DECR"},
        {GL_VENDOR,                  "GL_VENDOR"},
        {GL_RENDERER,                "GL_RENDERER"},
        {GL_VERSION,                 "GL_VERSION"},
        {GL_EXTENSIONS,              "GL_EXTENSIONS"},
        {GL_NEAREST,                 "GL_NEAREST"},
        {GL_LINEAR,                  "GL_LINEAR"},
        {GL_NEAREST_MIPMAP_NEAREST,  "GL_NEAREST_MIPMAP_NEAREST"},
        {GL_LINEAR_MIPMAP_NEAREST,   "GL_LINEAR_MIPMAP_NEAREST"},
        {GL_NEAREST_MIPMAP_LINEAR,   "GL_NEAREST_MIPMAP_LINEAR"},
        {GL_LINEAR_MIPMAP_LINEAR,    "GL_LINEAR_MIPMAP_LINEAR"},
        {GL_TEXTURE_MAG_FILTER,      "GL_TEXTURE_MAG_FILTER"},
        {GL_TEXTURE_MIN_FILTER,      "GL_TEXTURE_MIN_FILTER"},
        {GL_TEXTURE_WRAP_S,          "GL_TEXTURE_WRAP_S"},
        {GL_TEXTURE_WRAP_T,          "GL_TEXTURE_WRAP_T"},
        {GL_REPEAT,                  "GL_REPEAT"},

        /* GL 1.1 */
        {GL_COLOR_LOGIC_OP,          "GL_COLOR_LOGIC_OP"},
        {GL_POLYGON_OFFSET_UNITS,    "GL_POLYGON_OFFSET_UNITS"},
        {GL_POLYGON_OFFSET_POINT,    "GL_POLYGON_OFFSET_POINT"},
        {GL_POLYGON_OFFSET_LINE,     "GL_POLYGON_OFFSET_LINE"},
        {GL_POLYGON_OFFSET_FILL,     "GL_POLYGON_OFFSET_FILL"},
        {GL_POLYGON_OFFSET_FACTOR,   "GL_POLYGON_OFFSET_FACTOR"},
        {GL_TEXTURE_BINDING_1D,      "GL_TEXTURE_BINDING_1D"},
        {GL_TEXTURE_BINDING_2D,      "GL_TEXTURE_BINDING_2D"},
        {GL_TEXTURE_INTERNAL_FORMAT, "GL_TEXTURE_INTERNAL_FORMAT"},
        {GL_TEXTURE_RED_SIZE,        "GL_TEXTURE_RED_SIZE"},
        {GL_TEXTURE_GREEN_SIZE,      "GL_TEXTURE_GREEN_SIZE"},
        {GL_TEXTURE_BLUE_SIZE,       "GL_TEXTURE_BLUE_SIZE"},
        {GL_TEXTURE_ALPHA_SIZE,      "GL_TEXTURE_ALPHA_SIZE"},
        {GL_DOUBLE,                  "GL_DOUBLE"},
        {GL_PROXY_TEXTURE_1D,        "GL_PROXY_TEXTURE_1D"},
        {GL_PROXY_TEXTURE_2D,        "GL_PROXY_TEXTURE_2D"},
        {GL_R3_G3_B2,                "GL_R3_G3_B2"},
        {GL_RGB4,                    "GL_RGB4"},
        {GL_RGB5,                    "GL_RGB5"},
        {GL_RGB8,                    "GL_RGB8"},
        {GL_RGB10,                   "GL_RGB10"},
        {GL_RGB12,                   "GL_RGB12"},
        {GL_RGB16,                   "GL_RGB16"},
        {GL_RGBA2,                   "GL_RGBA2"},
        {GL_RGBA4,                   "GL_RGBA4"},
        {GL_RGB5_A1,                 "GL_RGB5_A1"},
        {GL_RGBA8,                   "GL_RGBA8"},
        {GL_RGB10_A2,                "GL_RGB10_A2"},
        {GL_RGBA12,                  "GL_RGBA12"},
        {GL_RGBA16,                  "GL_RGBA16"},
        {GL_VERTEX_ARRAY,            "GL_VERTEX_ARRAY"},

        /* GL 1.2 */
        {GL_UNSIGNED_BYTE_3_3_2,            "GL_UNSIGNED_BYTE_3_3_2"},
        {GL_UNSIGNED_SHORT_4_4_4_4,         "GL_UNSIGNED_SHORT_4_4_4_4"},
        {GL_UNSIGNED_SHORT_5_5_5_1,         "GL_UNSIGNED_SHORT_5_5_5_1"},
        {GL_UNSIGNED_INT_8_8_8_8,           "GL_UNSIGNED_INT_8_8_8_8"},
        {GL_UNSIGNED_INT_10_10_10_2,        "GL_UNSIGNED_INT_10_10_10_2"},
        {GL_TEXTURE_BINDING_3D,             "GL_TEXTURE_BINDING_3D"},
        {GL_PACK_SKIP_IMAGES,               "GL_PACK_SKIP_IMAGES"},
        {GL_PACK_IMAGE_HEIGHT,              "GL_PACK_IMAGE_HEIGHT"},
        {GL_UNPACK_SKIP_IMAGES,             "GL_UNPACK_SKIP_IMAGES"},
        {GL_UNPACK_IMAGE_HEIGHT,            "GL_UNPACK_IMAGE_HEIGHT"},
        {GL_TEXTURE_3D,                     "GL_TEXTURE_3D"},
        {GL_PROXY_TEXTURE_3D,               "GL_PROXY_TEXTURE_3D"},
        {GL_TEXTURE_DEPTH,                  "GL_TEXTURE_DEPTH"},
        {GL_TEXTURE_WRAP_R,                 "GL_TEXTURE_WRAP_R"},
        {GL_MAX_3D_TEXTURE_SIZE,            "GL_MAX_3D_TEXTURE_SIZE"},
        {GL_UNSIGNED_BYTE_2_3_3_REV,        "GL_UNSIGNED_BYTE_2_3_3_REV"},
        {GL_UNSIGNED_SHORT_5_6_5,           "GL_UNSIGNED_SHORT_5_6_5"},
        {GL_UNSIGNED_SHORT_5_6_5_REV,       "GL_UNSIGNED_SHORT_5_6_5_REV"},
        {GL_UNSIGNED_SHORT_4_4_4_4_REV,     "GL_UNSIGNED_SHORT_4_4_4_4_REV"},
        {GL_UNSIGNED_SHORT_1_5_5_5_REV,     "GL_UNSIGNED_SHORT_1_5_5_5_REV"},
        {GL_UNSIGNED_INT_8_8_8_8_REV,       "GL_UNSIGNED_INT_8_8_8_8_REV"},
        {GL_UNSIGNED_INT_2_10_10_10_REV,    "GL_UNSIGNED_INT_2_10_10_10_REV"},
        {GL_BGR,                            "GL_BGR"},
        {GL_BGRA,                           "GL_BGRA"},
        {GL_MAX_ELEMENTS_VERTICES,          "GL_MAX_ELEMENTS_VERTICES"},
        {GL_MAX_ELEMENTS_INDICES,           "GL_MAX_ELEMENTS_INDICES"},
        {GL_CLAMP_TO_EDGE,                  "GL_CLAMP_TO_EDGE"},
        {GL_TEXTURE_MIN_LOD,                "GL_TEXTURE_MIN_LOD"},
        {GL_TEXTURE_MAX_LOD,                "GL_TEXTURE_MAX_LOD"},
        {GL_TEXTURE_BASE_LEVEL,             "GL_TEXTURE_BASE_LEVEL"},
        {GL_TEXTURE_MAX_LEVEL,              "GL_TEXTURE_MAX_LEVEL"},
        {GL_SMOOTH_POINT_SIZE_RANGE,        "GL_SMOOTH_POINT_SIZE_RANGE"},
        {GL_SMOOTH_POINT_SIZE_GRANULARITY,  "GL_SMOOTH_POINT_SIZE_GRANULARITY"},
        {GL_SMOOTH_LINE_WIDTH_RANGE,        "GL_SMOOTH_LINE_WIDTH_RANGE"},
        {GL_SMOOTH_LINE_WIDTH_GRANULARITY,  "GL_SMOOTH_LINE_WIDTH_GRANULARITY"},
        {GL_ALIASED_LINE_WIDTH_RANGE,       "GL_ALIASED_LINE_WIDTH_RANGE"},
        {GL_TEXTURE0,                       "GL_TEXTURE0"},
        {GL_TEXTURE1,                       "GL_TEXTURE1"},
        {GL_TEXTURE2,                       "GL_TEXTURE2"},
        {GL_TEXTURE3,                       "GL_TEXTURE3"},
        {GL_TEXTURE4,                       "GL_TEXTURE4"},
        {GL_TEXTURE5,                       "GL_TEXTURE5"},
        {GL_TEXTURE6,                       "GL_TEXTURE6"},
        {GL_TEXTURE7,                       "GL_TEXTURE7"},
        {GL_TEXTURE8,                       "GL_TEXTURE8"},
        {GL_TEXTURE9,                       "GL_TEXTURE9"},
        {GL_TEXTURE10,                      "GL_TEXTURE10"},
        {GL_TEXTURE11,                      "GL_TEXTURE11"},
        {GL_TEXTURE12,                      "GL_TEXTURE12"},
        {GL_TEXTURE13,                      "GL_TEXTURE13"},
        {GL_TEXTURE14,                      "GL_TEXTURE14"},
        {GL_TEXTURE15,                      "GL_TEXTURE15"},
        {GL_TEXTURE16,                      "GL_TEXTURE16"},
        {GL_TEXTURE17,                      "GL_TEXTURE17"},
        {GL_TEXTURE18,                      "GL_TEXTURE18"},
        {GL_TEXTURE19,                      "GL_TEXTURE19"},
        {GL_TEXTURE20,                      "GL_TEXTURE20"},
        {GL_TEXTURE21,                      "GL_TEXTURE21"},
        {GL_TEXTURE22,                      "GL_TEXTURE22"},
        {GL_TEXTURE23,                      "GL_TEXTURE23"},
        {GL_TEXTURE24,                      "GL_TEXTURE24"},
        {GL_TEXTURE25,                      "GL_TEXTURE25"},
        {GL_TEXTURE26,                      "GL_TEXTURE26"},
        {GL_TEXTURE27,                      "GL_TEXTURE27"},
        {GL_TEXTURE28,                      "GL_TEXTURE28"},
        {GL_TEXTURE29,                      "GL_TEXTURE29"},
        {GL_TEXTURE30,                      "GL_TEXTURE30"},
        {GL_TEXTURE31,                      "GL_TEXTURE31"},
        {GL_ACTIVE_TEXTURE,                 "GL_ACTIVE_TEXTURE"},
        {GL_MULTISAMPLE,                    "GL_MULTISAMPLE"},
        {GL_SAMPLE_ALPHA_TO_COVERAGE,       "GL_SAMPLE_ALPHA_TO_COVERAGE"},
        {GL_SAMPLE_ALPHA_TO_ONE,            "GL_SAMPLE_ALPHA_TO_ONE"},
        {GL_SAMPLE_COVERAGE,                "GL_SAMPLE_COVERAGE"},
        {GL_SAMPLE_BUFFERS,                 "GL_SAMPLE_BUFFERS"},
        {GL_SAMPLES,                        "GL_SAMPLES"},
        {GL_SAMPLE_COVERAGE_VALUE,          "GL_SAMPLE_COVERAGE_VALUE"},
        {GL_SAMPLE_COVERAGE_INVERT,         "GL_SAMPLE_COVERAGE_INVERT"},
        {GL_TEXTURE_CUBE_MAP,               "GL_TEXTURE_CUBE_MAP"},
        {GL_TEXTURE_BINDING_CUBE_MAP,       "GL_TEXTURE_BINDING_CUBE_MAP"},
        {GL_TEXTURE_CUBE_MAP_POSITIVE_X,    "GL_TEXTURE_CUBE_MAP_POSITIVE_X"},
        {GL_TEXTURE_CUBE_MAP_NEGATIVE_X,    "GL_TEXTURE_CUBE_MAP_NEGATIVE_X"},
        {GL_TEXTURE_CUBE_MAP_POSITIVE_Y,    "GL_TEXTURE_CUBE_MAP_POSITIVE_Y"},
        {GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,    "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y"},
        {GL_TEXTURE_CUBE_MAP_POSITIVE_Z,    "GL_TEXTURE_CUBE_MAP_POSITIVE_Z"},
        {GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,    "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z"},
        {GL_PROXY_TEXTURE_CUBE_MAP,         "GL_PROXY_TEXTURE_CUBE_MAP"},
        {GL_MAX_CUBE_MAP_TEXTURE_SIZE,      "GL_MAX_CUBE_MAP_TEXTURE_SIZE"},
        {GL_COMPRESSED_RGB,                 "GL_COMPRESSED_RGB"},
        {GL_COMPRESSED_RGBA,                "GL_COMPRESSED_RGBA"},
        {GL_TEXTURE_COMPRESSION_HINT,       "GL_TEXTURE_COMPRESSION_HINT"},
        {GL_TEXTURE_COMPRESSED_IMAGE_SIZE,  "GL_TEXTURE_COMPRESSED_IMAGE_SIZE"},
        {GL_TEXTURE_COMPRESSED,             "GL_TEXTURE_COMPRESSED"},
        {GL_NUM_COMPRESSED_TEXTURE_FORMATS, "GL_NUM_COMPRESSED_TEXTURE_FORMATS"},
        {GL_COMPRESSED_TEXTURE_FORMATS,     "GL_COMPRESSED_TEXTURE_FORMATS"},
        {GL_CLAMP_TO_BORDER,                "GL_CLAMP_TO_BORDER"},

        /* GL 1.4 */
        {GL_BLEND_DST_RGB,              "GL_BLEND_DST_RGB"},
        {GL_BLEND_SRC_RGB,              "GL_BLEND_SRC_RGB"},
        {GL_BLEND_DST_ALPHA,            "GL_BLEND_DST_ALPHA"},
        {GL_BLEND_SRC_ALPHA,            "GL_BLEND_SRC_ALPHA"},
        {GL_POINT_FADE_THRESHOLD_SIZE,  "GL_POINT_FADE_THRESHOLD_SIZE"},
        {GL_DEPTH_COMPONENT16,          "GL_DEPTH_COMPONENT16"},
        {GL_DEPTH_COMPONENT24,          "GL_DEPTH_COMPONENT24"},
        {GL_DEPTH_COMPONENT32,          "GL_DEPTH_COMPONENT32"},
        {GL_MIRRORED_REPEAT,            "GL_MIRRORED_REPEAT"},
        {GL_MAX_TEXTURE_LOD_BIAS,       "GL_MAX_TEXTURE_LOD_BIAS"},
        {GL_TEXTURE_LOD_BIAS,           "GL_TEXTURE_LOD_BIAS"},
        {GL_INCR_WRAP,                  "GL_INCR_WRAP"},
        {GL_DECR_WRAP,                  "GL_DECR_WRAP"},
        {GL_TEXTURE_DEPTH_SIZE,         "GL_TEXTURE_DEPTH_SIZE"},
        {GL_TEXTURE_COMPARE_MODE,       "GL_TEXTURE_COMPARE_MODE"},
        {GL_TEXTURE_COMPARE_FUNC,       "GL_TEXTURE_COMPARE_FUNC"},
        {GL_BLEND_COLOR,                "GL_BLEND_COLOR"},
        {GL_BLEND_EQUATION,             "GL_BLEND_EQUATION"},
        {GL_CONSTANT_COLOR,             "GL_CONSTANT_COLOR"},
        {GL_ONE_MINUS_CONSTANT_COLOR,   "GL_ONE_MINUS_CONSTANT_COLOR"},
        {GL_CONSTANT_ALPHA,             "GL_CONSTANT_ALPHA"},
        {GL_ONE_MINUS_CONSTANT_ALPHA,   "GL_ONE_MINUS_CONSTANT_ALPHA"},
        {GL_FUNC_ADD,                   "GL_FUNC_ADD"},
        {GL_FUNC_REVERSE_SUBTRACT,      "GL_FUNC_REVERSE_SUBTRACT"},
        {GL_FUNC_SUBTRACT,              "GL_FUNC_SUBTRACT"},
        {GL_MIN,                        "GL_MIN"},
        {GL_MAX,                        "GL_MAX"},

        /* GL 1.5 */
        {GL_BUFFER_SIZE,                        "GL_BUFFER_SIZE"},
        {GL_BUFFER_USAGE,                       "GL_BUFFER_USAGE"},
        {GL_QUERY_COUNTER_BITS,                 "GL_QUERY_COUNTER_BITS"},
        {GL_CURRENT_QUERY,                      "GL_CURRENT_QUERY"},
        {GL_QUERY_RESULT,                       "GL_QUERY_RESULT"},
        {GL_QUERY_RESULT_AVAILABLE,             "GL_QUERY_RESULT_AVAILABLE"},
        {GL_ARRAY_BUFFER,                       "GL_ARRAY_BUFFER"},
        {GL_ELEMENT_ARRAY_BUFFER,               "GL_ELEMENT_ARRAY_BUFFER"},
        {GL_ARRAY_BUFFER_BINDING,               "GL_ARRAY_BUFFER_BINDING"},
        {GL_ELEMENT_ARRAY_BUFFER_BINDING,       "GL_ELEMENT_ARRAY_BUFFER_BINDING"},
        {GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"},
        {GL_READ_ONLY,                          "GL_READ_ONLY"},
        {GL_WRITE_ONLY,                         "GL_WRITE_ONLY"},
        {GL_READ_WRITE,                         "GL_READ_WRITE"},
        {GL_BUFFER_ACCESS,                      "GL_BUFFER_ACCESS"},
        {GL_BUFFER_MAPPED,                      "GL_BUFFER_MAPPED"},
        {GL_BUFFER_MAP_POINTER,                 "GL_BUFFER_MAP_POINTER"},
        {GL_STREAM_DRAW,                        "GL_STREAM_DRAW"},
        {GL_STREAM_READ,                        "GL_STREAM_READ"},
        {GL_STREAM_COPY,                        "GL_STREAM_COPY"},
        {GL_STATIC_DRAW,                        "GL_STATIC_DRAW"},
        {GL_STATIC_READ,                        "GL_STATIC_READ"},
        {GL_STATIC_COPY,                        "GL_STATIC_COPY"},
        {GL_DYNAMIC_DRAW,                       "GL_DYNAMIC_DRAW"},
        {GL_DYNAMIC_READ,                       "GL_DYNAMIC_READ"},
        {GL_DYNAMIC_COPY,                       "GL_DYNAMIC_COPY"},
        {GL_SAMPLES_PASSED,                     "GL_SAMPLES_PASSED"},
        {GL_SRC1_ALPHA,                         "GL_SRC1_ALPHA"},

        /* GL 2.0 */
        {GL_BLEND_EQUATION_RGB,               "GL_BLEND_EQUATION_RGB"},
        {GL_VERTEX_ATTRIB_ARRAY_ENABLED,      "GL_VERTEX_ATTRIB_ARRAY_ENABLED"},
        {GL_VERTEX_ATTRIB_ARRAY_SIZE,         "GL_VERTEX_ATTRIB_ARRAY_SIZE"},
        {GL_VERTEX_ATTRIB_ARRAY_STRIDE,       "GL_VERTEX_ATTRIB_ARRAY_STRIDE"},
        {GL_VERTEX_ATTRIB_ARRAY_TYPE,         "GL_VERTEX_ATTRIB_ARRAY_TYPE"},
        {GL_CURRENT_VERTEX_ATTRIB,            "GL_CURRENT_VERTEX_ATTRIB"},
        {GL_VERTEX_PROGRAM_POINT_SIZE,        "GL_VERTEX_PROGRAM_POINT_SIZE"},
        {GL_VERTEX_ATTRIB_ARRAY_POINTER,      "GL_VERTEX_ATTRIB_ARRAY_POINTER"},
        {GL_STENCIL_BACK_FUNC,                "GL_STENCIL_BACK_FUNC"},
        {GL_STENCIL_BACK_FAIL,                "GL_STENCIL_BACK_FAIL"},
        {GL_STENCIL_BACK_PASS_DEPTH_FAIL,     "GL_STENCIL_BACK_PASS_DEPTH_FAIL"},
        {GL_STENCIL_BACK_PASS_DEPTH_PASS,     "GL_STENCIL_BACK_PASS_DEPTH_PASS"},
        {GL_MAX_DRAW_BUFFERS,                 "GL_MAX_DRAW_BUFFERS"},
        {GL_DRAW_BUFFER0,                     "GL_DRAW_BUFFER0"},
        {GL_DRAW_BUFFER1,                     "GL_DRAW_BUFFER1"},
        {GL_DRAW_BUFFER2,                     "GL_DRAW_BUFFER2"},
        {GL_DRAW_BUFFER3,                     "GL_DRAW_BUFFER3"},
        {GL_DRAW_BUFFER4,                     "GL_DRAW_BUFFER4"},
        {GL_DRAW_BUFFER5,                     "GL_DRAW_BUFFER5"},
        {GL_DRAW_BUFFER6,                     "GL_DRAW_BUFFER6"},
        {GL_DRAW_BUFFER7,                     "GL_DRAW_BUFFER7"},
        {GL_DRAW_BUFFER8,                     "GL_DRAW_BUFFER8"},
        {GL_DRAW_BUFFER9,                     "GL_DRAW_BUFFER9"},
        {GL_DRAW_BUFFER10,                    "GL_DRAW_BUFFER10"},
        {GL_DRAW_BUFFER11,                    "GL_DRAW_BUFFER11"},
        {GL_DRAW_BUFFER12,                    "GL_DRAW_BUFFER12"},
        {GL_DRAW_BUFFER13,                    "GL_DRAW_BUFFER13"},
        {GL_DRAW_BUFFER14,                    "GL_DRAW_BUFFER14"},
        {GL_DRAW_BUFFER15,                    "GL_DRAW_BUFFER15"},
        {GL_BLEND_EQUATION_ALPHA,             "GL_BLEND_EQUATION_ALPHA"},
        {GL_MAX_VERTEX_ATTRIBS,               "GL_MAX_VERTEX_ATTRIBS"},
        {GL_VERTEX_ATTRIB_ARRAY_NORMALIZED,   "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED"},
        {GL_MAX_TEXTURE_IMAGE_UNITS,          "GL_MAX_TEXTURE_IMAGE_UNITS"},
        {GL_FRAGMENT_SHADER,                  "GL_FRAGMENT_SHADER"},
        {GL_VERTEX_SHADER,                    "GL_VERTEX_SHADER"},
        {GL_MAX_FRAGMENT_UNIFORM_COMPONENTS,  "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS"},
        {GL_MAX_VERTEX_UNIFORM_COMPONENTS,    "GL_MAX_VERTEX_UNIFORM_COMPONENTS"},
        {GL_MAX_VARYING_FLOATS,               "GL_MAX_VARYING_FLOATS"},
        {GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,   "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS"},
        {GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS"},
        {GL_SHADER_TYPE,                      "GL_SHADER_TYPE"},
        {GL_FLOAT_VEC2,                       "GL_FLOAT_VEC2"},
        {GL_FLOAT_VEC3,                       "GL_FLOAT_VEC3"},
        {GL_FLOAT_VEC4,                       "GL_FLOAT_VEC4"},
        {GL_INT_VEC2,                         "GL_INT_VEC2"},
        {GL_INT_VEC3,                         "GL_INT_VEC3"},
        {GL_INT_VEC4,                         "GL_INT_VEC4"},
        {GL_BOOL,                             "GL_BOOL"},
        {GL_BOOL_VEC2,                        "GL_BOOL_VEC2"},
        {GL_BOOL_VEC3,                        "GL_BOOL_VEC3"},
        {GL_BOOL_VEC4,                        "GL_BOOL_VEC4"},
        {GL_FLOAT_MAT2,                       "GL_FLOAT_MAT2"},
        {GL_FLOAT_MAT3,                       "GL_FLOAT_MAT3"},
        {GL_FLOAT_MAT4,                       "GL_FLOAT_MAT4"},
        {GL_SAMPLER_1D,                       "GL_SAMPLER_1D"},
        {GL_SAMPLER_2D,                       "GL_SAMPLER_2D"},
        {GL_SAMPLER_3D,                       "GL_SAMPLER_3D"},
        {GL_SAMPLER_CUBE,                     "GL_SAMPLER_CUBE"},
        {GL_SAMPLER_1D_SHADOW,                "GL_SAMPLER_1D_SHADOW"},
        {GL_SAMPLER_2D_SHADOW,                "GL_SAMPLER_2D_SHADOW"},
        {GL_DELETE_STATUS,                    "GL_DELETE_STATUS"},
        {GL_COMPILE_STATUS,                   "GL_COMPILE_STATUS"},
        {GL_LINK_STATUS,                      "GL_LINK_STATUS"},
        {GL_VALIDATE_STATUS,                  "GL_VALIDATE_STATUS"},
        {GL_INFO_LOG_LENGTH,                  "GL_INFO_LOG_LENGTH"},
        {GL_ATTACHED_SHADERS,                 "GL_ATTACHED_SHADERS"},
        {GL_ACTIVE_UNIFORMS,                  "GL_ACTIVE_UNIFORMS"},
        {GL_ACTIVE_UNIFORM_MAX_LENGTH,        "GL_ACTIVE_UNIFORM_MAX_LENGTH"},
        {GL_SHADER_SOURCE_LENGTH,             "GL_SHADER_SOURCE_LENGTH"},
        {GL_ACTIVE_ATTRIBUTES,                "GL_ACTIVE_ATTRIBUTES"},
        {GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,      "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH"},
        {GL_FRAGMENT_SHADER_DERIVATIVE_HINT,  "GL_FRAGMENT_SHADER_DERIVATIVE_HINT"},
        {GL_SHADING_LANGUAGE_VERSION,         "GL_SHADING_LANGUAGE_VERSION"},
        {GL_CURRENT_PROGRAM,                  "GL_CURRENT_PROGRAM"},
        {GL_POINT_SPRITE_COORD_ORIGIN,        "GL_POINT_SPRITE_COORD_ORIGIN"},
        {GL_LOWER_LEFT,                       "GL_LOWER_LEFT"},
        {GL_UPPER_LEFT,                       "GL_UPPER_LEFT"},
        {GL_STENCIL_BACK_REF,                 "GL_STENCIL_BACK_REF"},
        {GL_STENCIL_BACK_VALUE_MASK,          "GL_STENCIL_BACK_VALUE_MASK"},
        {GL_STENCIL_BACK_WRITEMASK,           "GL_STENCIL_BACK_WRITEMASK"},

        /* GL 2.1 */
        {GL_PIXEL_PACK_BUFFER,           "GL_PIXEL_PACK_BUFFER"},
        {GL_PIXEL_UNPACK_BUFFER,         "GL_PIXEL_UNPACK_BUFFER"},
        {GL_PIXEL_PACK_BUFFER_BINDING,   "GL_PIXEL_PACK_BUFFER_BINDING"},
        {GL_PIXEL_UNPACK_BUFFER_BINDING, "GL_PIXEL_UNPACK_BUFFER_BINDING"},
        {GL_FLOAT_MAT2x3,                "GL_FLOAT_MAT2x3"},
        {GL_FLOAT_MAT2x4,                "GL_FLOAT_MAT2x4"},
        {GL_FLOAT_MAT3x2,                "GL_FLOAT_MAT3x2"},
        {GL_FLOAT_MAT3x4,                "GL_FLOAT_MAT3x4"},
        {GL_FLOAT_MAT4x2,                "GL_FLOAT_MAT4x2"},
        {GL_FLOAT_MAT4x3,                "GL_FLOAT_MAT4x3"},
        {GL_SRGB,                        "GL_SRGB"},
        {GL_SRGB8,                       "GL_SRGB8"},
        {GL_SRGB_ALPHA,                  "GL_SRGB_ALPHA"},
        {GL_SRGB8_ALPHA8,                "GL_SRGB8_ALPHA8"},
        {GL_COMPRESSED_SRGB,             "GL_COMPRESSED_SRGB"},
        {GL_COMPRESSED_SRGB_ALPHA,       "GL_COMPRESSED_SRGB_ALPHA"},

        /* GL 3.0 */
        {GL_COMPARE_REF_TO_TEXTURE,                         "GL_COMPARE_REF_TO_TEXTURE"},
        {GL_CLIP_DISTANCE0,                                 "GL_CLIP_DISTANCE0"},
        {GL_CLIP_DISTANCE1,                                 "GL_CLIP_DISTANCE1"},
        {GL_CLIP_DISTANCE2,                                 "GL_CLIP_DISTANCE2"},
        {GL_CLIP_DISTANCE3,                                 "GL_CLIP_DISTANCE3"},
        {GL_CLIP_DISTANCE4,                                 "GL_CLIP_DISTANCE4"},
        {GL_CLIP_DISTANCE5,                                 "GL_CLIP_DISTANCE5"},
        {GL_CLIP_DISTANCE6,                                 "GL_CLIP_DISTANCE6"},
        {GL_CLIP_DISTANCE7,                                 "GL_CLIP_DISTANCE7"},
        {GL_MAX_CLIP_DISTANCES,                             "GL_MAX_CLIP_DISTANCES"},
        {GL_MAJOR_VERSION,                                  "GL_MAJOR_VERSION"},
        {GL_MINOR_VERSION,                                  "GL_MINOR_VERSION"},
        {GL_NUM_EXTENSIONS,                                 "GL_NUM_EXTENSIONS"},
        {GL_CONTEXT_FLAGS,                                  "GL_CONTEXT_FLAGS"},
        {GL_COMPRESSED_RED,                                 "GL_COMPRESSED_RED"},
        {GL_COMPRESSED_RG,                                  "GL_COMPRESSED_RG"},
        {GL_RGBA32F,                                        "GL_RGBA32F"},
        {GL_RGB32F,                                         "GL_RGB32F"},
        {GL_RGBA16F,                                        "GL_RGBA16F"},
        {GL_RGB16F,                                         "GL_RGB16F"},
        {GL_VERTEX_ATTRIB_ARRAY_INTEGER,                    "GL_VERTEX_ATTRIB_ARRAY_INTEGER"},
        {GL_MAX_ARRAY_TEXTURE_LAYERS,                       "GL_MAX_ARRAY_TEXTURE_LAYERS"},
        {GL_MIN_PROGRAM_TEXEL_OFFSET,                       "GL_MIN_PROGRAM_TEXEL_OFFSET"},
        {GL_MAX_PROGRAM_TEXEL_OFFSET,                       "GL_MAX_PROGRAM_TEXEL_OFFSET"},
        {GL_CLAMP_READ_COLOR,                               "GL_CLAMP_READ_COLOR"},
        {GL_FIXED_ONLY,                                     "GL_FIXED_ONLY"},
        {GL_MAX_VARYING_COMPONENTS,                         "GL_MAX_VARYING_COMPONENTS"},
        {GL_TEXTURE_1D_ARRAY,                               "GL_TEXTURE_1D_ARRAY"},
        {GL_PROXY_TEXTURE_1D_ARRAY,                         "GL_PROXY_TEXTURE_1D_ARRAY"},
        {GL_TEXTURE_2D_ARRAY,                               "GL_TEXTURE_2D_ARRAY"},
        {GL_PROXY_TEXTURE_2D_ARRAY,                         "GL_PROXY_TEXTURE_2D_ARRAY"},
        {GL_TEXTURE_BINDING_1D_ARRAY,                       "GL_TEXTURE_BINDING_1D_ARRAY"},
        {GL_TEXTURE_BINDING_2D_ARRAY,                       "GL_TEXTURE_BINDING_2D_ARRAY"},
        {GL_R11F_G11F_B10F,                                 "GL_R11F_G11F_B10F"},
        {GL_UNSIGNED_INT_10F_11F_11F_REV,                   "GL_UNSIGNED_INT_10F_11F_11F_REV"},
        {GL_RGB9_E5,                                        "GL_RGB9_E5"},
        {GL_UNSIGNED_INT_5_9_9_9_REV,                       "GL_UNSIGNED_INT_5_9_9_9_REV"},
        {GL_TEXTURE_SHARED_SIZE,                            "GL_TEXTURE_SHARED_SIZE"},
        {GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH,          "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH"},
        {GL_TRANSFORM_FEEDBACK_BUFFER_MODE,                 "GL_TRANSFORM_FEEDBACK_BUFFER_MODE"},
        {GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS,     "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS"},
        {GL_TRANSFORM_FEEDBACK_VARYINGS,                    "GL_TRANSFORM_FEEDBACK_VARYINGS"},
        {GL_TRANSFORM_FEEDBACK_BUFFER_START,                "GL_TRANSFORM_FEEDBACK_BUFFER_START"},
        {GL_TRANSFORM_FEEDBACK_BUFFER_SIZE,                 "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE"},
        {GL_PRIMITIVES_GENERATED,                           "GL_PRIMITIVES_GENERATED"},
        {GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN,          "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN"},
        {GL_RASTERIZER_DISCARD,                             "GL_RASTERIZER_DISCARD"},
        {GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS,  "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS"},
        {GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS,        "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS"},
        {GL_INTERLEAVED_ATTRIBS,                            "GL_INTERLEAVED_ATTRIBS"},
        {GL_SEPARATE_ATTRIBS,                               "GL_SEPARATE_ATTRIBS"},
        {GL_TRANSFORM_FEEDBACK_BUFFER,                      "GL_TRANSFORM_FEEDBACK_BUFFER"},
        {GL_TRANSFORM_FEEDBACK_BUFFER_BINDING,              "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING"},
        {GL_RGBA32UI,                                       "GL_RGBA32UI"},
        {GL_RGB32UI,                                        "GL_RGB32UI"},
        {GL_RGBA16UI,                                       "GL_RGBA16UI"},
        {GL_RGB16UI,                                        "GL_RGB16UI"},
        {GL_RGBA8UI,                                        "GL_RGBA8UI"},
        {GL_RGB8UI,                                         "GL_RGB8UI"},
        {GL_RGBA32I,                                        "GL_RGBA32I"},
        {GL_RGB32I,                                         "GL_RGB32I"},
        {GL_RGBA16I,                                        "GL_RGBA16I"},
        {GL_RGB16I,                                         "GL_RGB16I"},
        {GL_RGBA8I,                                         "GL_RGBA8I"},
        {GL_RGB8I,                                          "GL_RGB8I"},
        {GL_RED_INTEGER,                                    "GL_RED_INTEGER"},
        {GL_GREEN_INTEGER,                                  "GL_GREEN_INTEGER"},
        {GL_BLUE_INTEGER,                                   "GL_BLUE_INTEGER"},
        {GL_RGB_INTEGER,                                    "GL_RGB_INTEGER"},
        {GL_RGBA_INTEGER,                                   "GL_RGBA_INTEGER"},
        {GL_BGR_INTEGER,                                    "GL_BGR_INTEGER"},
        {GL_BGRA_INTEGER,                                   "GL_BGRA_INTEGER"},
        {GL_SAMPLER_1D_ARRAY,                               "GL_SAMPLER_1D_ARRAY"},
        {GL_SAMPLER_2D_ARRAY,                               "GL_SAMPLER_2D_ARRAY"},
        {GL_SAMPLER_1D_ARRAY_SHADOW,                        "GL_SAMPLER_1D_ARRAY_SHADOW"},
        {GL_SAMPLER_2D_ARRAY_SHADOW,                        "GL_SAMPLER_2D_ARRAY_SHADOW"},
        {GL_SAMPLER_CUBE_SHADOW,                            "GL_SAMPLER_CUBE_SHADOW"},
        {GL_UNSIGNED_INT_VEC2,                              "GL_UNSIGNED_INT_VEC2"},
        {GL_UNSIGNED_INT_VEC3,                              "GL_UNSIGNED_INT_VEC3"},
        {GL_UNSIGNED_INT_VEC4,                              "GL_UNSIGNED_INT_VEC4"},
        {GL_INT_SAMPLER_1D,                                 "GL_INT_SAMPLER_1D"},
        {GL_INT_SAMPLER_2D,                                 "GL_INT_SAMPLER_2D"},
        {GL_INT_SAMPLER_3D,                                 "GL_INT_SAMPLER_3D"},
        {GL_INT_SAMPLER_CUBE,                               "GL_INT_SAMPLER_CUBE"},
        {GL_INT_SAMPLER_1D_ARRAY,                           "GL_INT_SAMPLER_1D_ARRAY"},
        {GL_INT_SAMPLER_2D_ARRAY,                           "GL_INT_SAMPLER_2D_ARRAY"},
        {GL_UNSIGNED_INT_SAMPLER_1D,                        "GL_UNSIGNED_INT_SAMPLER_1D"},
        {GL_UNSIGNED_INT_SAMPLER_2D,                        "GL_UNSIGNED_INT_SAMPLER_2D"},
        {GL_UNSIGNED_INT_SAMPLER_3D,                        "GL_UNSIGNED_INT_SAMPLER_3D"},
        {GL_UNSIGNED_INT_SAMPLER_CUBE,                      "GL_UNSIGNED_INT_SAMPLER_CUBE"},
        {GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,                  "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY"},
        {GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,                  "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY"},
        {GL_QUERY_WAIT,                                     "GL_QUERY_WAIT"},
        {GL_QUERY_NO_WAIT,                                  "GL_QUERY_NO_WAIT"},
        {GL_QUERY_BY_REGION_WAIT,                           "GL_QUERY_BY_REGION_WAIT"},
        {GL_QUERY_BY_REGION_NO_WAIT,                        "GL_QUERY_BY_REGION_NO_WAIT"},
        {GL_BUFFER_ACCESS_FLAGS,                            "GL_BUFFER_ACCESS_FLAGS"},
        {GL_BUFFER_MAP_LENGTH,                              "GL_BUFFER_MAP_LENGTH"},
        {GL_BUFFER_MAP_OFFSET,                              "GL_BUFFER_MAP_OFFSET"},
        {GL_DEPTH_COMPONENT32F,                             "GL_DEPTH_COMPONENT32F"},
        {GL_DEPTH32F_STENCIL8,                              "GL_DEPTH32F_STENCIL8"},
        {GL_FLOAT_32_UNSIGNED_INT_24_8_REV,                 "GL_FLOAT_32_UNSIGNED_INT_24_8_REV"},
        {GL_INVALID_FRAMEBUFFER_OPERATION,                  "GL_INVALID_FRAMEBUFFER_OPERATION"},
        {GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING,          "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING"},
        {GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE,          "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE"},
        {GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE,                "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE"},
        {GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE,              "GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE"},
        {GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE,               "GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE"},
        {GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE,              "GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE"},
        {GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE,              "GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE"},
        {GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE,            "GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE"},
        {GL_FRAMEBUFFER_DEFAULT,                            "GL_FRAMEBUFFER_DEFAULT"},
        {GL_FRAMEBUFFER_UNDEFINED,                          "GL_FRAMEBUFFER_UNDEFINED"},
        {GL_DEPTH_STENCIL_ATTACHMENT,                       "GL_DEPTH_STENCIL_ATTACHMENT"},
        {GL_MAX_RENDERBUFFER_SIZE,                          "GL_MAX_RENDERBUFFER_SIZE"},
        {GL_DEPTH_STENCIL,                                  "GL_DEPTH_STENCIL"},
        {GL_UNSIGNED_INT_24_8,                              "GL_UNSIGNED_INT_24_8"},
        {GL_DEPTH24_STENCIL8,                               "GL_DEPTH24_STENCIL8"},
        {GL_TEXTURE_STENCIL_SIZE,                           "GL_TEXTURE_STENCIL_SIZE"},
        {GL_TEXTURE_RED_TYPE,                               "GL_TEXTURE_RED_TYPE"},
        {GL_TEXTURE_GREEN_TYPE,                             "GL_TEXTURE_GREEN_TYPE"},
        {GL_TEXTURE_BLUE_TYPE,                              "GL_TEXTURE_BLUE_TYPE"},
        {GL_TEXTURE_ALPHA_TYPE,                             "GL_TEXTURE_ALPHA_TYPE"},
        {GL_TEXTURE_DEPTH_TYPE,                             "GL_TEXTURE_DEPTH_TYPE"},
        {GL_UNSIGNED_NORMALIZED,                            "GL_UNSIGNED_NORMALIZED"},
        {GL_FRAMEBUFFER_BINDING,                            "GL_FRAMEBUFFER_BINDING"},
        {GL_DRAW_FRAMEBUFFER_BINDING,                       "GL_DRAW_FRAMEBUFFER_BINDING"},
        {GL_RENDERBUFFER_BINDING,                           "GL_RENDERBUFFER_BINDING"},
        {GL_READ_FRAMEBUFFER,                               "GL_READ_FRAMEBUFFER"},
        {GL_DRAW_FRAMEBUFFER,                               "GL_DRAW_FRAMEBUFFER"},
        {GL_READ_FRAMEBUFFER_BINDING,                       "GL_READ_FRAMEBUFFER_BINDING"},
        {GL_RENDERBUFFER_SAMPLES,                           "GL_RENDERBUFFER_SAMPLES"},
        {GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,             "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE"},
        {GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,             "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME"},
        {GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL,           "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL"},
        {GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE,   "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE"},
        {GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER,           "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER"},
        {GL_FRAMEBUFFER_COMPLETE,                           "GL_FRAMEBUFFER_COMPLETE"},
        {GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT,              "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT"},
        {GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,      "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT"},
        {GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER,             "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER"},
        {GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER,             "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER"},
        {GL_FRAMEBUFFER_UNSUPPORTED,                        "GL_FRAMEBUFFER_UNSUPPORTED"},
        {GL_MAX_COLOR_ATTACHMENTS,                          "GL_MAX_COLOR_ATTACHMENTS"},
        {GL_COLOR_ATTACHMENT0,                              "GL_COLOR_ATTACHMENT0"},
        {GL_COLOR_ATTACHMENT1,                              "GL_COLOR_ATTACHMENT1"},
        {GL_COLOR_ATTACHMENT2,                              "GL_COLOR_ATTACHMENT2"},
        {GL_COLOR_ATTACHMENT3,                              "GL_COLOR_ATTACHMENT3"},
        {GL_COLOR_ATTACHMENT4,                              "GL_COLOR_ATTACHMENT4"},
        {GL_COLOR_ATTACHMENT5,                              "GL_COLOR_ATTACHMENT5"},
        {GL_COLOR_ATTACHMENT6,                              "GL_COLOR_ATTACHMENT6"},
        {GL_COLOR_ATTACHMENT7,                              "GL_COLOR_ATTACHMENT7"},
        {GL_COLOR_ATTACHMENT8,                              "GL_COLOR_ATTACHMENT8"},
        {GL_COLOR_ATTACHMENT9,                              "GL_COLOR_ATTACHMENT9"},
        {GL_COLOR_ATTACHMENT10,                             "GL_COLOR_ATTACHMENT10"},
        {GL_COLOR_ATTACHMENT11,                             "GL_COLOR_ATTACHMENT11"},
        {GL_COLOR_ATTACHMENT12,                             "GL_COLOR_ATTACHMENT12"},
        {GL_COLOR_ATTACHMENT13,                             "GL_COLOR_ATTACHMENT13"},
        {GL_COLOR_ATTACHMENT14,                             "GL_COLOR_ATTACHMENT14"},
        {GL_COLOR_ATTACHMENT15,                             "GL_COLOR_ATTACHMENT15"},
        {GL_COLOR_ATTACHMENT16,                             "GL_COLOR_ATTACHMENT16"},
        {GL_COLOR_ATTACHMENT17,                             "GL_COLOR_ATTACHMENT17"},
        {GL_COLOR_ATTACHMENT18,                             "GL_COLOR_ATTACHMENT18"},
        {GL_COLOR_ATTACHMENT19,                             "GL_COLOR_ATTACHMENT19"},
        {GL_COLOR_ATTACHMENT20,                             "GL_COLOR_ATTACHMENT20"},
        {GL_COLOR_ATTACHMENT21,                             "GL_COLOR_ATTACHMENT21"},
        {GL_COLOR_ATTACHMENT22,                             "GL_COLOR_ATTACHMENT22"},
        {GL_COLOR_ATTACHMENT23,                             "GL_COLOR_ATTACHMENT23"},
        {GL_COLOR_ATTACHMENT24,                             "GL_COLOR_ATTACHMENT24"},
        {GL_COLOR_ATTACHMENT25,                             "GL_COLOR_ATTACHMENT25"},
        {GL_COLOR_ATTACHMENT26,                             "GL_COLOR_ATTACHMENT26"},
        {GL_COLOR_ATTACHMENT27,                             "GL_COLOR_ATTACHMENT27"},
        {GL_COLOR_ATTACHMENT28,                             "GL_COLOR_ATTACHMENT28"},
        {GL_COLOR_ATTACHMENT29,                             "GL_COLOR_ATTACHMENT29"},
        {GL_COLOR_ATTACHMENT30,                             "GL_COLOR_ATTACHMENT30"},
        {GL_COLOR_ATTACHMENT31,                             "GL_COLOR_ATTACHMENT31"},
        {GL_DEPTH_ATTACHMENT,                               "GL_DEPTH_ATTACHMENT"},
        {GL_STENCIL_ATTACHMENT,                             "GL_STENCIL_ATTACHMENT"},
        {GL_FRAMEBUFFER,                                    "GL_FRAMEBUFFER"},
        {GL_RENDERBUFFER,                                   "GL_RENDERBUFFER"},
        {GL_RENDERBUFFER_WIDTH,                             "GL_RENDERBUFFER_WIDTH"},
        {GL_RENDERBUFFER_HEIGHT,                            "GL_RENDERBUFFER_HEIGHT"},
        {GL_RENDERBUFFER_INTERNAL_FORMAT,                   "GL_RENDERBUFFER_INTERNAL_FORMAT"},
        {GL_STENCIL_INDEX1,                                 "GL_STENCIL_INDEX1"},
        {GL_STENCIL_INDEX4,                                 "GL_STENCIL_INDEX4"},
        {GL_STENCIL_INDEX8,                                 "GL_STENCIL_INDEX8"},
        {GL_STENCIL_INDEX16,                                "GL_STENCIL_INDEX16"},
        {GL_RENDERBUFFER_RED_SIZE,                          "GL_RENDERBUFFER_RED_SIZE"},
        {GL_RENDERBUFFER_GREEN_SIZE,                        "GL_RENDERBUFFER_GREEN_SIZE"},
        {GL_RENDERBUFFER_BLUE_SIZE,                         "GL_RENDERBUFFER_BLUE_SIZE"},
        {GL_RENDERBUFFER_ALPHA_SIZE,                        "GL_RENDERBUFFER_ALPHA_SIZE"},
        {GL_RENDERBUFFER_DEPTH_SIZE,                        "GL_RENDERBUFFER_DEPTH_SIZE"},
        {GL_RENDERBUFFER_STENCIL_SIZE,                      "GL_RENDERBUFFER_STENCIL_SIZE"},
        {GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE,             "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE"},
        {GL_MAX_SAMPLES,                                    "GL_MAX_SAMPLES"},
        {GL_FRAMEBUFFER_SRGB,                               "GL_FRAMEBUFFER_SRGB"},
        {GL_HALF_FLOAT,                                     "GL_HALF_FLOAT"},
        {GL_COMPRESSED_RED_RGTC1,                           "GL_COMPRESSED_RED_RGTC1"},
        {GL_COMPRESSED_SIGNED_RED_RGTC1,                    "GL_COMPRESSED_SIGNED_RED_RGTC1"},
        {GL_COMPRESSED_RG_RGTC2,                            "GL_COMPRESSED_RG_RGTC2"},
        {GL_COMPRESSED_SIGNED_RG_RGTC2,                     "GL_COMPRESSED_SIGNED_RG_RGTC2"},
        {GL_RG,                                             "GL_RG"},
        {GL_RG_INTEGER,                                     "GL_RG_INTEGER"},
        {GL_R8,                                             "GL_R8"},
        {GL_R16,                                            "GL_R16"},
        {GL_RG8,                                            "GL_RG8"},
        {GL_RG16,                                           "GL_RG16"},
        {GL_R16F,                                           "GL_R16F"},
        {GL_R32F,                                           "GL_R32F"},
        {GL_RG16F,                                          "GL_RG16F"},
        {GL_RG32F,                                          "GL_RG32F"},
        {GL_R8I,                                            "GL_R8I"},
        {GL_R8UI,                                           "GL_R8UI"},
        {GL_R16I,                                           "GL_R16I"},
        {GL_R16UI,                                          "GL_R16UI"},
        {GL_R32I,                                           "GL_R32I"},
        {GL_R32UI,                                          "GL_R32UI"},
        {GL_RG8I,                                           "GL_RG8I"},
        {GL_RG8UI,                                          "GL_RG8UI"},
        {GL_RG16I,                                          "GL_RG16I"},
        {GL_RG16UI,                                         "GL_RG16UI"},
        {GL_RG32I,                                          "GL_RG32I"},
        {GL_RG32UI,                                         "GL_RG32UI"},
        {GL_VERTEX_ARRAY_BINDING,                           "GL_VERTEX_ARRAY_BINDING"},

        /* GL 3.1 */

        {GL_SAMPLER_2D_RECT,                             "GL_SAMPLER_2D_RECT"},
        {GL_SAMPLER_2D_RECT_SHADOW,                      "GL_SAMPLER_2D_RECT_SHADOW"},
        {GL_SAMPLER_BUFFER,                              "GL_SAMPLER_BUFFER"},
        {GL_INT_SAMPLER_2D_RECT,                         "GL_INT_SAMPLER_2D_RECT"},
        {GL_INT_SAMPLER_BUFFER,                          "GL_INT_SAMPLER_BUFFER"},
        {GL_UNSIGNED_INT_SAMPLER_2D_RECT,                "GL_UNSIGNED_INT_SAMPLER_2D_RECT"},
        {GL_UNSIGNED_INT_SAMPLER_BUFFER,                 "GL_UNSIGNED_INT_SAMPLER_BUFFER"},
        {GL_TEXTURE_BUFFER,                              "GL_TEXTURE_BUFFER"},
        {GL_MAX_TEXTURE_BUFFER_SIZE,                     "GL_MAX_TEXTURE_BUFFER_SIZE"},
        {GL_TEXTURE_BINDING_BUFFER,                      "GL_TEXTURE_BINDING_BUFFER"},
        {GL_TEXTURE_BUFFER_DATA_STORE_BINDING,           "GL_TEXTURE_BUFFER_DATA_STORE_BINDING"},
        {GL_TEXTURE_RECTANGLE,                           "GL_TEXTURE_RECTANGLE"},
        {GL_TEXTURE_BINDING_RECTANGLE,                   "GL_TEXTURE_BINDING_RECTANGLE"},
        {GL_PROXY_TEXTURE_RECTANGLE,                     "GL_PROXY_TEXTURE_RECTANGLE"},
        {GL_MAX_RECTANGLE_TEXTURE_SIZE,                  "GL_MAX_RECTANGLE_TEXTURE_SIZE"},
        {GL_R8_SNORM,                                    "GL_R8_SNORM"},
        {GL_RG8_SNORM,                                   "GL_RG8_SNORM"},
        {GL_RGB8_SNORM,                                  "GL_RGB8_SNORM"},
        {GL_RGBA8_SNORM,                                 "GL_RGBA8_SNORM"},
        {GL_R16_SNORM,                                   "GL_R16_SNORM"},
        {GL_RG16_SNORM,                                  "GL_RG16_SNORM"},
        {GL_RGB16_SNORM,                                 "GL_RGB16_SNORM"},
        {GL_RGBA16_SNORM,                                "GL_RGBA16_SNORM"},
        {GL_SIGNED_NORMALIZED,                           "GL_SIGNED_NORMALIZED"},
        {GL_PRIMITIVE_RESTART,                           "GL_PRIMITIVE_RESTART"},
        {GL_PRIMITIVE_RESTART_INDEX,                     "GL_PRIMITIVE_RESTART_INDEX"},
        {GL_COPY_READ_BUFFER,                            "GL_COPY_READ_BUFFER"},
        {GL_COPY_WRITE_BUFFER,                           "GL_COPY_WRITE_BUFFER"},
        {GL_UNIFORM_BUFFER,                              "GL_UNIFORM_BUFFER"},
        {GL_UNIFORM_BUFFER_BINDING,                      "GL_UNIFORM_BUFFER_BINDING"},
        {GL_UNIFORM_BUFFER_START,                        "GL_UNIFORM_BUFFER_START"},
        {GL_UNIFORM_BUFFER_SIZE,                         "GL_UNIFORM_BUFFER_SIZE"},
        {GL_MAX_VERTEX_UNIFORM_BLOCKS,                   "GL_MAX_VERTEX_UNIFORM_BLOCKS"},
        {GL_MAX_GEOMETRY_UNIFORM_BLOCKS,                 "GL_MAX_GEOMETRY_UNIFORM_BLOCKS"},
        {GL_MAX_FRAGMENT_UNIFORM_BLOCKS,                 "GL_MAX_FRAGMENT_UNIFORM_BLOCKS"},
        {GL_MAX_COMBINED_UNIFORM_BLOCKS,                 "GL_MAX_COMBINED_UNIFORM_BLOCKS"},
        {GL_MAX_UNIFORM_BUFFER_BINDINGS,                 "GL_MAX_UNIFORM_BUFFER_BINDINGS"},
        {GL_MAX_UNIFORM_BLOCK_SIZE,                      "GL_MAX_UNIFORM_BLOCK_SIZE"},
        {GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS,      "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS"},
        {GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS,    "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS"},
        {GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS,    "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS"},
        {GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT,             "GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT"},
        {GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH,        "GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH"},
        {GL_ACTIVE_UNIFORM_BLOCKS,                       "GL_ACTIVE_UNIFORM_BLOCKS"},
        {GL_UNIFORM_TYPE,                                "GL_UNIFORM_TYPE"},
        {GL_UNIFORM_SIZE,                                "GL_UNIFORM_SIZE"},
        {GL_UNIFORM_NAME_LENGTH,                         "GL_UNIFORM_NAME_LENGTH"},
        {GL_UNIFORM_BLOCK_INDEX,                         "GL_UNIFORM_BLOCK_INDEX"},
        {GL_UNIFORM_OFFSET,                              "GL_UNIFORM_OFFSET"},
        {GL_UNIFORM_ARRAY_STRIDE,                        "GL_UNIFORM_ARRAY_STRIDE"},
        {GL_UNIFORM_MATRIX_STRIDE,                       "GL_UNIFORM_MATRIX_STRIDE"},
        {GL_UNIFORM_IS_ROW_MAJOR,                        "GL_UNIFORM_IS_ROW_MAJOR"},
        {GL_UNIFORM_BLOCK_BINDING,                       "GL_UNIFORM_BLOCK_BINDING"},
        {GL_UNIFORM_BLOCK_DATA_SIZE,                     "GL_UNIFORM_BLOCK_DATA_SIZE"},
        {GL_UNIFORM_BLOCK_NAME_LENGTH,                   "GL_UNIFORM_BLOCK_NAME_LENGTH"},
        {GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS,               "GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS"},
        {GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES,        "GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES"},
        {GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER,   "GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER"},
        {GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER"},
        {GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER, "GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER"},

        /* GL 3.2 */

        {GL_LINES_ADJACENCY,                           "GL_LINES_ADJACENCY"},
        {GL_LINE_STRIP_ADJACENCY,                      "GL_LINE_STRIP_ADJACENCY"},
        {GL_TRIANGLES_ADJACENCY,                       "GL_TRIANGLES_ADJACENCY"},
        {GL_TRIANGLE_STRIP_ADJACENCY,                  "GL_TRIANGLE_STRIP_ADJACENCY"},
        {GL_PROGRAM_POINT_SIZE,                        "GL_PROGRAM_POINT_SIZE"},
        {GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS,          "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS"},
        {GL_FRAMEBUFFER_ATTACHMENT_LAYERED,            "GL_FRAMEBUFFER_ATTACHMENT_LAYERED"},
        {GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS,      "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS"},
        {GL_GEOMETRY_SHADER,                           "GL_GEOMETRY_SHADER"},
        {GL_GEOMETRY_VERTICES_OUT,                     "GL_GEOMETRY_VERTICES_OUT"},
        {GL_GEOMETRY_INPUT_TYPE,                       "GL_GEOMETRY_INPUT_TYPE"},
        {GL_GEOMETRY_OUTPUT_TYPE,                      "GL_GEOMETRY_OUTPUT_TYPE"},
        {GL_MAX_GEOMETRY_UNIFORM_COMPONENTS,           "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS"},
        {GL_MAX_GEOMETRY_OUTPUT_VERTICES,              "GL_MAX_GEOMETRY_OUTPUT_VERTICES"},
        {GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS,      "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS"},
        {GL_MAX_VERTEX_OUTPUT_COMPONENTS,              "GL_MAX_VERTEX_OUTPUT_COMPONENTS"},
        {GL_MAX_GEOMETRY_INPUT_COMPONENTS,             "GL_MAX_GEOMETRY_INPUT_COMPONENTS"},
        {GL_MAX_GEOMETRY_OUTPUT_COMPONENTS,            "GL_MAX_GEOMETRY_OUTPUT_COMPONENTS"},
        {GL_MAX_FRAGMENT_INPUT_COMPONENTS,             "GL_MAX_FRAGMENT_INPUT_COMPONENTS"},
        {GL_CONTEXT_PROFILE_MASK,                      "GL_CONTEXT_PROFILE_MASK"},
        {GL_DEPTH_CLAMP,                               "GL_DEPTH_CLAMP"},
        {GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION,  "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION"},
        {GL_FIRST_VERTEX_CONVENTION,                   "GL_FIRST_VERTEX_CONVENTION"},
        {GL_LAST_VERTEX_CONVENTION,                    "GL_LAST_VERTEX_CONVENTION"},
        {GL_PROVOKING_VERTEX,                          "GL_PROVOKING_VERTEX"},
        {GL_TEXTURE_CUBE_MAP_SEAMLESS,                 "GL_TEXTURE_CUBE_MAP_SEAMLESS"},
        {GL_MAX_SERVER_WAIT_TIMEOUT,                   "GL_MAX_SERVER_WAIT_TIMEOUT"},
        {GL_OBJECT_TYPE,                               "GL_OBJECT_TYPE"},
        {GL_SYNC_CONDITION,                            "GL_SYNC_CONDITION"},
        {GL_SYNC_STATUS,                               "GL_SYNC_STATUS"},
        {GL_SYNC_FLAGS,                                "GL_SYNC_FLAGS"},
        {GL_SYNC_FENCE,                                "GL_SYNC_FENCE"},
        {GL_SYNC_GPU_COMMANDS_COMPLETE,                "GL_SYNC_GPU_COMMANDS_COMPLETE"},
        {GL_UNSIGNALED,                                "GL_UNSIGNALED"},
        {GL_SIGNALED,                                  "GL_SIGNALED"},
        {GL_ALREADY_SIGNALED,                          "GL_ALREADY_SIGNALED"},
        {GL_TIMEOUT_EXPIRED,                           "GL_TIMEOUT_EXPIRED"},
        {GL_CONDITION_SATISFIED,                       "GL_CONDITION_SATISFIED"},
        {GL_WAIT_FAILED,                               "GL_WAIT_FAILED"},
        {GL_SAMPLE_POSITION,                           "GL_SAMPLE_POSITION"},
        {GL_SAMPLE_MASK,                               "GL_SAMPLE_MASK"},
        {GL_SAMPLE_MASK_VALUE,                         "GL_SAMPLE_MASK_VALUE"},
        {GL_MAX_SAMPLE_MASK_WORDS,                     "GL_MAX_SAMPLE_MASK_WORDS"},
        {GL_TEXTURE_2D_MULTISAMPLE,                    "GL_TEXTURE_2D_MULTISAMPLE"},
        {GL_PROXY_TEXTURE_2D_MULTISAMPLE,              "GL_PROXY_TEXTURE_2D_MULTISAMPLE"},
        {GL_TEXTURE_2D_MULTISAMPLE_ARRAY,              "GL_TEXTURE_2D_MULTISAMPLE_ARRAY"},
        {GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY,        "GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY"},
        {GL_TEXTURE_BINDING_2D_MULTISAMPLE,            "GL_TEXTURE_BINDING_2D_MULTISAMPLE"},
        {GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY,      "GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY"},
        {GL_TEXTURE_SAMPLES,                           "GL_TEXTURE_SAMPLES"},
        {GL_TEXTURE_FIXED_SAMPLE_LOCATIONS,            "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS"},
        {GL_SAMPLER_2D_MULTISAMPLE,                    "GL_SAMPLER_2D_MULTISAMPLE"},
        {GL_INT_SAMPLER_2D_MULTISAMPLE,                "GL_INT_SAMPLER_2D_MULTISAMPLE"},
        {GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,       "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE"},
        {GL_SAMPLER_2D_MULTISAMPLE_ARRAY,              "GL_SAMPLER_2D_MULTISAMPLE_ARRAY"},
        {GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,          "GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY"},
        {GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY, "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY"},
        {GL_MAX_COLOR_ATTACHMENTS,                     "GL_MAX_COLOR_ATTACHMENTS"},
        {GL_MAX_COLOR_TEXTURE_SAMPLES,                 "GL_MAX_COLOR_TEXTURE_SAMPLES"},
        {GL_MAX_DEPTH_TEXTURE_SAMPLES,                 "GL_MAX_DEPTH_TEXTURE_SAMPLES"},
        {GL_MAX_INTEGER_SAMPLES,                       "GL_MAX_INTEGER_SAMPLES"},
    };

    auto iterator = entries.find(in_enum);

    if (iterator != entries.end() )
    {
        result = iterator->second.c_str();
    }

    return result;
}

OpenGL::ReadBuffer OpenGL::Utils::get_read_buffer_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ReadBuffer result = OpenGL::ReadBuffer::Unknown;

    switch (in_enum)
    {
        case GL_BACK:              result = OpenGL::ReadBuffer::Back;              break;
        case GL_BACK_LEFT:         result = OpenGL::ReadBuffer::Back_Left;         break;
        case GL_BACK_RIGHT:        result = OpenGL::ReadBuffer::Back_Right;        break;
        case GL_COLOR_ATTACHMENT0: result = OpenGL::ReadBuffer::Color_Attachment0; break;
        case GL_COLOR_ATTACHMENT1: result = OpenGL::ReadBuffer::Color_Attachment1; break;
        case GL_COLOR_ATTACHMENT2: result = OpenGL::ReadBuffer::Color_Attachment2; break;
        case GL_COLOR_ATTACHMENT3: result = OpenGL::ReadBuffer::Color_Attachment3; break;
        case GL_COLOR_ATTACHMENT4: result = OpenGL::ReadBuffer::Color_Attachment4; break;
        case GL_COLOR_ATTACHMENT5: result = OpenGL::ReadBuffer::Color_Attachment5; break;
        case GL_COLOR_ATTACHMENT6: result = OpenGL::ReadBuffer::Color_Attachment6; break;
        case GL_COLOR_ATTACHMENT7: result = OpenGL::ReadBuffer::Color_Attachment7; break;
        case GL_FRONT:             result = OpenGL::ReadBuffer::Front;             break;
        case GL_FRONT_AND_BACK:    result = OpenGL::ReadBuffer::Front_And_Back;    break;
        case GL_FRONT_LEFT:        result = OpenGL::ReadBuffer::Front_Left;        break;
        case GL_FRONT_RIGHT:       result = OpenGL::ReadBuffer::Front_Right;       break;
        case GL_LEFT:              result = OpenGL::ReadBuffer::Left;              break;
        case GL_RIGHT:             result = OpenGL::ReadBuffer::Right;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::RenderbufferProperty OpenGL::Utils::get_renderbuffer_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::RenderbufferProperty result = OpenGL::RenderbufferProperty::Unknown;

    switch (in_enum)
    {
        case GL_RENDERBUFFER_ALPHA_SIZE:      result = OpenGL::RenderbufferProperty::Alpha_Size;      break;
        case GL_RENDERBUFFER_BLUE_SIZE:       result = OpenGL::RenderbufferProperty::Blue_Size;       break;
        case GL_RENDERBUFFER_DEPTH_SIZE:      result = OpenGL::RenderbufferProperty::Depth_Size;      break;
        case GL_RENDERBUFFER_GREEN_SIZE:      result = OpenGL::RenderbufferProperty::Green_Size;      break;
        case GL_RENDERBUFFER_HEIGHT:          result = OpenGL::RenderbufferProperty::Height;          break;
        case GL_RENDERBUFFER_INTERNAL_FORMAT: result = OpenGL::RenderbufferProperty::Internal_Format; break;
        case GL_RENDERBUFFER_RED_SIZE:        result = OpenGL::RenderbufferProperty::Red_Size;        break;
        case GL_RENDERBUFFER_SAMPLES:         result = OpenGL::RenderbufferProperty::Samples;         break;
        case GL_RENDERBUFFER_STENCIL_SIZE:    result = OpenGL::RenderbufferProperty::Stencil_Size;    break;
        case GL_RENDERBUFFER_WIDTH:           result = OpenGL::RenderbufferProperty::Width;           break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::RenderbufferTarget OpenGL::Utils::get_renderbuffer_target_for_gl_enum(const GLenum& in_enum)
{
    vkgl_assert(in_enum == GL_RENDERBUFFER);

    return OpenGL::RenderbufferTarget::Renderbuffer;
}

OpenGL::ShaderProperty OpenGL::Utils::get_shader_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ShaderProperty result = OpenGL::ShaderProperty::Unknown;

    switch (in_enum)
    {
        case GL_COMPILE_STATUS:       result = OpenGL::ShaderProperty::Compile_Status;       break;
        case GL_DELETE_STATUS:        result = OpenGL::ShaderProperty::Delete_Status;        break;
        case GL_INFO_LOG_LENGTH:      result = OpenGL::ShaderProperty::Info_Log_Length;      break;
        case GL_SHADER_SOURCE_LENGTH: result = OpenGL::ShaderProperty::Shader_Source_Length; break;
        case GL_SHADER_TYPE:          result = OpenGL::ShaderProperty::Shader_Type;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::ShaderType OpenGL::Utils::get_shader_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::ShaderType result = OpenGL::ShaderType::Unknown;

    switch (in_enum)
    {
        case GL_FRAGMENT_SHADER: result = OpenGL::ShaderType::Fragment; break;
        case GL_GEOMETRY_SHADER: result = OpenGL::ShaderType::Geometry; break;
        case GL_VERTEX_SHADER:   result = OpenGL::ShaderType::Vertex;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::StencilFunction OpenGL::Utils::get_stencil_function_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::StencilFunction result = OpenGL::StencilFunction::Unknown;

    switch (in_enum)
    {
        case GL_ALWAYS:   result = OpenGL::StencilFunction::Always;   break;
        case GL_EQUAL:    result = OpenGL::StencilFunction::Equal;    break;
        case GL_GEQUAL:   result = OpenGL::StencilFunction::GEqual;   break;
        case GL_GREATER:  result = OpenGL::StencilFunction::Greater;  break;
        case GL_LEQUAL:   result = OpenGL::StencilFunction::LEqual;   break;
        case GL_LESS:     result = OpenGL::StencilFunction::Less;     break;
        case GL_NEVER:    result = OpenGL::StencilFunction::Never;    break;
        case GL_NOTEQUAL: result = OpenGL::StencilFunction::NotEqual; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::StencilOperation OpenGL::Utils::get_stencil_operation_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::StencilOperation result = OpenGL::StencilOperation::Unknown;

    switch (in_enum)
    {
        case GL_DECR:      result = OpenGL::StencilOperation::Decr;      break;
        case GL_DECR_WRAP: result = OpenGL::StencilOperation::Decr_Wrap; break;
        case GL_INCR:      result = OpenGL::StencilOperation::Incr;      break;
        case GL_INCR_WRAP: result = OpenGL::StencilOperation::Incr_Wrap; break;
        case GL_INVERT:    result = OpenGL::StencilOperation::Invert;    break;
        case GL_KEEP:      result = OpenGL::StencilOperation::Keep;      break;
        case GL_REPLACE:   result = OpenGL::StencilOperation::Replace;   break;
        case GL_ZERO:      result = OpenGL::StencilOperation::Zero;      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::StencilStateFace OpenGL::Utils::get_stencil_state_face_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::StencilStateFace result = OpenGL::StencilStateFace::Unknown;

    switch (in_enum)
    {
        case GL_BACK:           result = OpenGL::StencilStateFace::Back;           break;
        case GL_FRONT:          result = OpenGL::StencilStateFace::Front;          break;
        case GL_FRONT_AND_BACK: result = OpenGL::StencilStateFace::Front_And_Back; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::SyncCondition OpenGL::Utils::get_sync_condition_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::SyncCondition result = OpenGL::SyncCondition::Unknown;

    switch (in_enum)
    {
        case GL_SYNC_GPU_COMMANDS_COMPLETE: result = OpenGL::SyncCondition::Sync_GPU_Commands_Complete; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::SyncProperty OpenGL::Utils::get_sync_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::SyncProperty result = OpenGL::SyncProperty::Unknown;

    switch (in_enum)
    {
        case GL_SYNC_CONDITION: result = OpenGL::SyncProperty::Condition;   break;
        case GL_SYNC_FLAGS:     result = OpenGL::SyncProperty::Flags;       break;
        case GL_OBJECT_TYPE:    result = OpenGL::SyncProperty::Object_Type; break;
        case GL_SYNC_STATUS:    result = OpenGL::SyncProperty::Status;      break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureBindingProperty OpenGL::Utils::get_texture_binding_property_for_context_property(const OpenGL::ContextProperty& in_pname)
{
    OpenGL::TextureBindingProperty result = OpenGL::TextureBindingProperty::Unknown;

    switch (in_pname)
    {
        case OpenGL::ContextProperty::Texture_Binding_1D:                   result = OpenGL::TextureBindingProperty::_1D;                   break;
        case OpenGL::ContextProperty::Texture_Binding_1D_Array:             result = OpenGL::TextureBindingProperty::_1D_Array;             break;
        case OpenGL::ContextProperty::Texture_Binding_2D:                   result = OpenGL::TextureBindingProperty::_2D;                   break;
        case OpenGL::ContextProperty::Texture_Binding_2D_Array:             result = OpenGL::TextureBindingProperty::_2D_Array;             break;
        case OpenGL::ContextProperty::Texture_Binding_2D_Multisample:       result = OpenGL::TextureBindingProperty::_2D_Multisample;       break;
        case OpenGL::ContextProperty::Texture_Binding_2D_Multisample_Array: result = OpenGL::TextureBindingProperty::_2D_Multisample_Array; break;
        case OpenGL::ContextProperty::Texture_Binding_3D:                   result = OpenGL::TextureBindingProperty::_3D;                   break;
        case OpenGL::ContextProperty::Texture_Binding_Buffer:               result = OpenGL::TextureBindingProperty::Buffer;                break;
        case OpenGL::ContextProperty::Texture_Binding_Cube_Map:             result = OpenGL::TextureBindingProperty::Cube_Map;              break;
        case OpenGL::ContextProperty::Texture_Binding_Rectangle:            result = OpenGL::TextureBindingProperty::Rectangle;             break;
    }

    return result;
}

OpenGL::TextureCompareFunction OpenGL::Utils::get_texture_compare_function_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureCompareFunction result = OpenGL::TextureCompareFunction::Unknown;

    switch (in_enum)
    {
        case GL_ALWAYS:   result = OpenGL::TextureCompareFunction::Always;   break;
        case GL_EQUAL:    result = OpenGL::TextureCompareFunction::Equal;    break;
        case GL_GEQUAL:   result = OpenGL::TextureCompareFunction::GEqual;   break;
        case GL_GREATER:  result = OpenGL::TextureCompareFunction::Greater;  break;
        case GL_LEQUAL:   result = OpenGL::TextureCompareFunction::LEqual;   break;
        case GL_LESS:     result = OpenGL::TextureCompareFunction::Less;     break;
        case GL_NEVER:    result = OpenGL::TextureCompareFunction::Never;    break;
        case GL_NOTEQUAL: result = OpenGL::TextureCompareFunction::NotEqual; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureCompareMode OpenGL::Utils::get_texture_compare_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureCompareMode result = OpenGL::TextureCompareMode::Unknown;

    switch (in_enum)
    {
        case GL_COMPARE_REF_TO_TEXTURE: result = OpenGL::TextureCompareMode::Compare_Ref_to_Texture; break;
        case GL_NONE:                   result = OpenGL::TextureCompareMode::None;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureCubeMapFace OpenGL::Utils::get_texture_cube_map_face_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureCubeMapFace result = OpenGL::TextureCubeMapFace::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X: result = OpenGL::TextureCubeMapFace::Negative_X; break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y: result = OpenGL::TextureCubeMapFace::Negative_Y; break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z: result = OpenGL::TextureCubeMapFace::Negative_Z; break;
        case GL_NONE:                        result = OpenGL::TextureCubeMapFace::None;       break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X: result = OpenGL::TextureCubeMapFace::Positive_X; break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y: result = OpenGL::TextureCubeMapFace::Positive_Y; break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z: result = OpenGL::TextureCubeMapFace::Positive_Z; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureLevelProperty OpenGL::Utils::get_texture_level_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureLevelProperty result = OpenGL::TextureLevelProperty::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_ALPHA_SIZE:            result = OpenGL::TextureLevelProperty::Texture_Alpha_Size;            break;
        case GL_TEXTURE_BLUE_SIZE:             result = OpenGL::TextureLevelProperty::Texture_Blue_Size;             break;
        case GL_TEXTURE_BUFFER_OFFSET:         result = OpenGL::TextureLevelProperty::Texture_Buffer_Offset;         break;
        case GL_TEXTURE_COMPRESSED:            result = OpenGL::TextureLevelProperty::Texture_Compressed;            break;
        case GL_TEXTURE_COMPRESSED_IMAGE_SIZE: result = OpenGL::TextureLevelProperty::Texture_Compressed_Image_Size; break;
        case GL_TEXTURE_DEPTH:                 result = OpenGL::TextureLevelProperty::Texture_Depth;                 break;
        case GL_TEXTURE_DEPTH_SIZE:            result = OpenGL::TextureLevelProperty::Texture_Depth_Size;            break;
        case GL_TEXTURE_GREEN_SIZE:            result = OpenGL::TextureLevelProperty::Texture_Green_Size;            break;
        case GL_TEXTURE_HEIGHT:                result = OpenGL::TextureLevelProperty::Texture_Height;                break;
        case GL_TEXTURE_INTERNAL_FORMAT:       result = OpenGL::TextureLevelProperty::Texture_Internal_Format;       break;
        case GL_TEXTURE_RED_SIZE:              result = OpenGL::TextureLevelProperty::Texture_Red_Size;              break;
        case GL_TEXTURE_WIDTH:                 result = OpenGL::TextureLevelProperty::Texture_Width;                 break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureMagFilter OpenGL::Utils::get_texture_mag_filter_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureMagFilter result = OpenGL::TextureMagFilter::Unknown;

    switch (in_enum)
    {
        case GL_LINEAR:  result = OpenGL::TextureMagFilter::Linear;  break;
        case GL_NEAREST: result = OpenGL::TextureMagFilter::Nearest; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureMinFilter OpenGL::Utils::get_texture_min_filter_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureMinFilter result = OpenGL::TextureMinFilter::Unknown;

    switch (in_enum)
    {
        case GL_LINEAR:                 result = OpenGL::TextureMinFilter::Linear;                 break;
        case GL_LINEAR_MIPMAP_LINEAR:   result = OpenGL::TextureMinFilter::Linear_Mipmap_Linear;   break;
        case GL_LINEAR_MIPMAP_NEAREST:  result = OpenGL::TextureMinFilter::Linear_Mipmap_Nearest;  break;
        case GL_NEAREST:                result = OpenGL::TextureMinFilter::Nearest;                break;
        case GL_NEAREST_MIPMAP_LINEAR:  result = OpenGL::TextureMinFilter::Nearest_Mipmap_Linear;  break;
        case GL_NEAREST_MIPMAP_NEAREST: result = OpenGL::TextureMinFilter::Nearest_Mipmap_Nearest; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureProperty OpenGL::Utils::get_texture_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureProperty result = OpenGL::TextureProperty::Unknown;

    switch (in_enum)
    {
        case GL_DEPTH_STENCIL_TEXTURE_MODE: result = OpenGL::TextureProperty::Depth_Stencil_Texture_Mode; break;
        case GL_TEXTURE_BASE_LEVEL:         result = OpenGL::TextureProperty::Texture_Base_Level;         break;
        case GL_TEXTURE_COMPARE_FUNC:       result = OpenGL::TextureProperty::Texture_Compare_Func;       break;
        case GL_TEXTURE_COMPARE_MODE:       result = OpenGL::TextureProperty::Texture_Compare_Mode;       break;
        case GL_TEXTURE_LOD_BIAS:           result = OpenGL::TextureProperty::Texture_Lod_Bias;           break;
        case GL_TEXTURE_MAG_FILTER:         result = OpenGL::TextureProperty::Texture_Mag_Filter;         break;
        case GL_TEXTURE_MAX_LEVEL:          result = OpenGL::TextureProperty::Texture_Max_Level;          break;
        case GL_TEXTURE_MAX_LOD:            result = OpenGL::TextureProperty::Texture_Max_Lod;            break;
        case GL_TEXTURE_MIN_FILTER:         result = OpenGL::TextureProperty::Texture_Min_Filter;         break;
        case GL_TEXTURE_MIN_LOD:            result = OpenGL::TextureProperty::Texture_Min_Lod;            break;
        case GL_TEXTURE_SWIZZLE_A:          result = OpenGL::TextureProperty::Texture_Swizzle_A;          break;
        case GL_TEXTURE_SWIZZLE_B:          result = OpenGL::TextureProperty::Texture_Swizzle_B;          break;
        case GL_TEXTURE_SWIZZLE_G:          result = OpenGL::TextureProperty::Texture_Swizzle_G;          break;
        case GL_TEXTURE_SWIZZLE_R:          result = OpenGL::TextureProperty::Texture_Swizzle_R;          break;
        case GL_TEXTURE_WRAP_R:             result = OpenGL::TextureProperty::Texture_Wrap_R;             break;
        case GL_TEXTURE_WRAP_S:             result = OpenGL::TextureProperty::Texture_Wrap_S;             break;
        case GL_TEXTURE_WRAP_T:             result = OpenGL::TextureProperty::Texture_Wrap_T;             break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureSwizzle OpenGL::Utils::get_texture_swizzle_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureSwizzle result = OpenGL::TextureSwizzle::Unknown;

    switch (in_enum)
    {
        case GL_ALPHA: result = OpenGL::TextureSwizzle::Alpha; break;
        case GL_BLUE:  result = OpenGL::TextureSwizzle::Blue;  break;
        case GL_GREEN: result = OpenGL::TextureSwizzle::Green; break;
        case GL_ONE:   result = OpenGL::TextureSwizzle::One;   break;
        case GL_RED:   result = OpenGL::TextureSwizzle::Red;   break;
        case GL_ZERO:  result = OpenGL::TextureSwizzle::Zero;  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureTarget OpenGL::Utils::get_texture_target_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureTarget result = OpenGL::TextureTarget::Unknown;

    switch (in_enum)
    {
        case GL_TEXTURE_1D:                         result = OpenGL::TextureTarget::_1D;                                break;
        case GL_TEXTURE_1D_ARRAY:                   result = OpenGL::TextureTarget::_1D_Array;                          break;
        case GL_TEXTURE_2D:                         result = OpenGL::TextureTarget::_2D;                                break;
        case GL_TEXTURE_2D_ARRAY:                   result = OpenGL::TextureTarget::_2D_Array;                          break;
        case GL_TEXTURE_2D_MULTISAMPLE:             result = OpenGL::TextureTarget::_2D_Multisample;                    break;
        case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:       result = OpenGL::TextureTarget::_2D_Multisample_Array;              break;
        case GL_TEXTURE_3D:                         result = OpenGL::TextureTarget::_3D;                                break;
        case GL_TEXTURE_CUBE_MAP:                   result = OpenGL::TextureTarget::Cube_Map;                           break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:        result = OpenGL::TextureTarget::Cube_Map_Negative_X;                break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:        result = OpenGL::TextureTarget::Cube_Map_Negative_Y;                break;
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:        result = OpenGL::TextureTarget::Cube_Map_Negative_Z;                break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X:        result = OpenGL::TextureTarget::Cube_Map_Positive_X;                break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:        result = OpenGL::TextureTarget::Cube_Map_Positive_Y;                break;
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:        result = OpenGL::TextureTarget::Cube_Map_Positive_Z;                break;
        case GL_PROXY_TEXTURE_1D:                   result = OpenGL::TextureTarget::Proxy_Texture_1D;                   break;
        case GL_PROXY_TEXTURE_1D_ARRAY:             result = OpenGL::TextureTarget::Proxy_Texture_1D_Array;             break;
        case GL_PROXY_TEXTURE_2D:                   result = OpenGL::TextureTarget::Proxy_Texture_2D;                   break;
        case GL_PROXY_TEXTURE_2D_ARRAY:             result = OpenGL::TextureTarget::Proxy_Texture_2D_Array;             break;
        case GL_PROXY_TEXTURE_2D_MULTISAMPLE:       result = OpenGL::TextureTarget::Proxy_Texture_2D_Multisample;       break;
        case GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY: result = OpenGL::TextureTarget::Proxy_Texture_2D_Multisample_Array; break;
        case GL_PROXY_TEXTURE_3D:                   result = OpenGL::TextureTarget::Proxy_Texture_3D;                   break;
        case GL_PROXY_TEXTURE_CUBE_MAP:             result = OpenGL::TextureTarget::Proxy_Texture_Cube_Map;             break;
        case GL_PROXY_TEXTURE_RECTANGLE:            result = OpenGL::TextureTarget::Proxy_Texture_Rectangle;            break;
        case GL_TEXTURE_RECTANGLE:                  result = OpenGL::TextureTarget::Rectangle;                          break;
        case GL_TEXTURE_BUFFER:                     result = OpenGL::TextureTarget::Texture_Buffer;                     break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TextureWrapMode OpenGL::Utils::get_texture_wrap_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TextureWrapMode result = OpenGL::TextureWrapMode::Unknown;

    switch (in_enum)
    {
        case GL_CLAMP_TO_BORDER:      result = OpenGL::TextureWrapMode::Clamp_To_Border;      break;
        case GL_CLAMP_TO_EDGE:        result = OpenGL::TextureWrapMode::Clamp_To_Edge;        break;
        case GL_MIRROR_CLAMP_TO_EDGE: result = OpenGL::TextureWrapMode::Mirror_Clamp_to_Edge; break;
        case GL_MIRRORED_REPEAT:      result = OpenGL::TextureWrapMode::Mirrored_Repeat;      break;
        case GL_REPEAT:               result = OpenGL::TextureWrapMode::Repeat;               break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::VariableType OpenGL::Utils::get_variable_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::VariableType result = OpenGL::VariableType::Unknown;

    switch (in_enum)
    {
        case GL_BOOL:                                      result = OpenGL::VariableType::Bool;                 break;
        case GL_BOOL_VEC2:                                 result = OpenGL::VariableType::Bvec2;                break;
        case GL_BOOL_VEC3:                                 result = OpenGL::VariableType::Bvec3;                break;
        case GL_BOOL_VEC4:                                 result = OpenGL::VariableType::Bvec4;                break;
        case GL_FLOAT:                                     result = OpenGL::VariableType::Float;                break;
        case GL_FLOAT_MAT2:                                result = OpenGL::VariableType::Mat2;                 break;
        case GL_FLOAT_MAT3:                                result = OpenGL::VariableType::Mat3;                 break;
        case GL_FLOAT_MAT4:                                result = OpenGL::VariableType::Mat4;                 break;
        case GL_FLOAT_MAT2x3:                              result = OpenGL::VariableType::Mat2x3;               break;
        case GL_FLOAT_MAT2x4:                              result = OpenGL::VariableType::Mat2x4;               break;
        case GL_FLOAT_MAT3x2:                              result = OpenGL::VariableType::Mat3x2;               break;
        case GL_FLOAT_MAT3x4:                              result = OpenGL::VariableType::Mat3x4;               break;
        case GL_FLOAT_MAT4x2:                              result = OpenGL::VariableType::Mat4x2;               break;
        case GL_FLOAT_MAT4x3:                              result = OpenGL::VariableType::Mat4x3;               break;
        case GL_FLOAT_VEC2:                                result = OpenGL::VariableType::Vec2;                 break;
        case GL_FLOAT_VEC3:                                result = OpenGL::VariableType::Vec3;                 break;
        case GL_FLOAT_VEC4:                                result = OpenGL::VariableType::Vec4;                 break;
        case GL_INT:                                       result = OpenGL::VariableType::Int;                  break;
        case GL_INT_SAMPLER_1D:                            result = OpenGL::VariableType::Isampler1D;           break;
        case GL_INT_SAMPLER_1D_ARRAY:                      result = OpenGL::VariableType::Isampler1DArray;      break;
        case GL_INT_SAMPLER_2D:                            result = OpenGL::VariableType::Isampler2D;           break;
        case GL_INT_SAMPLER_2D_ARRAY:                      result = OpenGL::VariableType::Isampler2DArray;      break;
        case GL_INT_SAMPLER_2D_MULTISAMPLE:                result = OpenGL::VariableType::Isampler2DMS;         break;
        case GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY:          result = OpenGL::VariableType::Isampler2DMSArray;    break;
        case GL_INT_SAMPLER_2D_RECT:                       result = OpenGL::VariableType::Isampler2DRect;       break;
        case GL_INT_SAMPLER_3D:                            result = OpenGL::VariableType::Isampler3D;           break;
        case GL_INT_SAMPLER_BUFFER:                        result = OpenGL::VariableType::IsamplerBuffer;       break;
        case GL_INT_SAMPLER_CUBE:                          result = OpenGL::VariableType::IsamplerCube;         break;
        case GL_INT_VEC2:                                  result = OpenGL::VariableType::Ivec2;                break;
        case GL_INT_VEC3:                                  result = OpenGL::VariableType::Ivec3;                break;
        case GL_INT_VEC4:                                  result = OpenGL::VariableType::Ivec4;                break;
        case GL_SAMPLER_1D:                                result = OpenGL::VariableType::Sampler1D;            break;
        case GL_SAMPLER_1D_ARRAY:                          result = OpenGL::VariableType::Sampler1DArray;       break;
        case GL_SAMPLER_1D_ARRAY_SHADOW:                   result = OpenGL::VariableType::Sampler1DArrayShadow; break;
        case GL_SAMPLER_1D_SHADOW:                         result = OpenGL::VariableType::Sampler1DShadow;      break;
        case GL_SAMPLER_2D:                                result = OpenGL::VariableType::Sampler2D;            break;
        case GL_SAMPLER_2D_ARRAY:                          result = OpenGL::VariableType::Sampler2DArray;       break;
        case GL_SAMPLER_2D_ARRAY_SHADOW:                   result = OpenGL::VariableType::Sampler2DArrayShadow; break;
        case GL_SAMPLER_2D_MULTISAMPLE:                    result = OpenGL::VariableType::Sampler2DMS;          break;
        case GL_SAMPLER_2D_MULTISAMPLE_ARRAY:              result = OpenGL::VariableType::Sampler2DMSArray;     break;
        case GL_SAMPLER_2D_RECT:                           result = OpenGL::VariableType::Sampler2DRect;        break;
        case GL_SAMPLER_2D_RECT_SHADOW:                    result = OpenGL::VariableType::Sampler2DRectShadow;  break;
        case GL_SAMPLER_2D_SHADOW:                         result = OpenGL::VariableType::Sampler2DShadow;      break;
        case GL_SAMPLER_3D:                                result = OpenGL::VariableType::Sampler3D;            break;
        case GL_SAMPLER_BUFFER:                            result = OpenGL::VariableType::SamplerBuffer;        break;
        case GL_SAMPLER_CUBE:                              result = OpenGL::VariableType::SamplerCube;          break;
        case GL_SAMPLER_CUBE_SHADOW:                       result = OpenGL::VariableType::SamplerCubeShadow;    break;
        case GL_UNSIGNED_INT:                              result = OpenGL::VariableType::Uint;                 break;
        case GL_UNSIGNED_INT_SAMPLER_1D:                   result = OpenGL::VariableType::Usampler1D;           break;
        case GL_UNSIGNED_INT_SAMPLER_1D_ARRAY:             result = OpenGL::VariableType::Usampler1DArray;      break;
        case GL_UNSIGNED_INT_SAMPLER_2D:                   result = OpenGL::VariableType::Usampler2D;           break;
        case GL_UNSIGNED_INT_SAMPLER_2D_ARRAY:             result = OpenGL::VariableType::Usampler2DArray;      break;
        case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE:       result = OpenGL::VariableType::Usampler2DMS;         break;
        case GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY: result = OpenGL::VariableType::Usampler2DMSArray;    break;
        case GL_UNSIGNED_INT_SAMPLER_2D_RECT:              result = OpenGL::VariableType::Usampler2DRect;       break;
        case GL_UNSIGNED_INT_SAMPLER_3D:                   result = OpenGL::VariableType::Usampler3D;           break;
        case GL_UNSIGNED_INT_SAMPLER_BUFFER:               result = OpenGL::VariableType::UsamplerBuffer;       break;
        case GL_UNSIGNED_INT_SAMPLER_CUBE:                 result = OpenGL::VariableType::UsamplerCube;         break;
        case GL_UNSIGNED_INT_VEC2:                         result = OpenGL::VariableType::Uvec2;                break;
        case GL_UNSIGNED_INT_VEC3:                         result = OpenGL::VariableType::Uvec3;                break;
        case GL_UNSIGNED_INT_VEC4:                         result = OpenGL::VariableType::Uvec4;                break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TransformFeedbackBufferMode OpenGL::Utils::get_transform_feedback_buffer_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TransformFeedbackBufferMode result = OpenGL::TransformFeedbackBufferMode::Unknown;

    switch (in_enum)
    {
        case GL_INTERLEAVED_ATTRIBS: result = OpenGL::TransformFeedbackBufferMode::Interleaved_Attribs; break;
        case GL_SEPARATE_ATTRIBS:    result = OpenGL::TransformFeedbackBufferMode::Separate_Attribs;    break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::TransformFeedbackPrimitiveMode OpenGL::Utils::get_transform_feedback_primitive_mode_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::TransformFeedbackPrimitiveMode result = OpenGL::TransformFeedbackPrimitiveMode::Unknown;

    switch (in_enum)
    {
        case GL_LINES:     result = OpenGL::TransformFeedbackPrimitiveMode::Lines;     break;
        case GL_POINTS:    result = OpenGL::TransformFeedbackPrimitiveMode::Points;    break;
        case GL_TRIANGLES: result = OpenGL::TransformFeedbackPrimitiveMode::Triangles; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::UniformBlockProperty OpenGL::Utils::get_uniform_block_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::UniformBlockProperty result = OpenGL::UniformBlockProperty::Unknown;

    switch (in_enum)
    {
        case GL_UNIFORM_BLOCK_BINDING:                       result = OpenGL::UniformBlockProperty::Binding;                       break;
        case GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS:               result = OpenGL::UniformBlockProperty::Block_Active_Uniforms;         break;
        case GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES:        result = OpenGL::UniformBlockProperty::Block_Active_Uniform_Indices;  break;
        case GL_UNIFORM_BLOCK_DATA_SIZE:                     result = OpenGL::UniformBlockProperty::Block_Data_Size;               break;
        case GL_UNIFORM_BLOCK_NAME_LENGTH:                   result = OpenGL::UniformBlockProperty::Block_Name_Length;             break;
        case GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER: result = OpenGL::UniformBlockProperty::Referenced_By_Fragment_Shader; break;
        case GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER: result = OpenGL::UniformBlockProperty::Referenced_By_Geometry_Shader; break;
        case GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER:   result = OpenGL::UniformBlockProperty::Referenced_By_Vertex_Shader;   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::UniformProperty OpenGL::Utils::get_uniform_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::UniformProperty result = OpenGL::UniformProperty::Unknown;

    switch (in_enum)
    {
        case GL_UNIFORM_ARRAY_STRIDE:  result = OpenGL::UniformProperty::Array_Stride;  break;
        case GL_UNIFORM_BLOCK_INDEX:   result = OpenGL::UniformProperty::Block_Index;   break;
        case GL_UNIFORM_IS_ROW_MAJOR:  result = OpenGL::UniformProperty::Is_Row_Major;  break;
        case GL_UNIFORM_MATRIX_STRIDE: result = OpenGL::UniformProperty::Matrix_Stride; break;
        case GL_UNIFORM_NAME_LENGTH:   result = OpenGL::UniformProperty::Name_Length;   break;
        case GL_UNIFORM_OFFSET:        result = OpenGL::UniformProperty::Offset;        break;
        case GL_UNIFORM_SIZE:          result = OpenGL::UniformProperty::Size;          break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::VertexAttributePointerProperty OpenGL::Utils::get_vertex_attribute_pointer_property_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::VertexAttributePointerProperty result = OpenGL::VertexAttributePointerProperty::Unknown;

    switch (in_enum)
    {
        case GL_VERTEX_ATTRIB_ARRAY_POINTER: result = OpenGL::VertexAttributePointerProperty::Vertex_Attribute_Array_Pointer; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::WaitSyncBits OpenGL::Utils::get_wait_sync_bits_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::WaitSyncBits result = 0;

    if (in_enum & GL_SYNC_FLUSH_COMMANDS_BIT)
    {
        result |= OpenGL::WaitSyncBit::Sync_Flush_Commands_Bit;
    }

    return result;
}

OpenGL::VertexAttributeArrayType OpenGL::Utils::get_vertex_attribute_array_type_for_gl_enum(const GLenum& in_enum)
{
    OpenGL::VertexAttributeArrayType result = OpenGL::VertexAttributeArrayType::Unknown;

    switch (in_enum)
    {
        case GL_BYTE:           result = OpenGL::VertexAttributeArrayType::Byte;           break;
        case GL_DOUBLE:         result = OpenGL::VertexAttributeArrayType::Double;         break;
        case GL_FLOAT:          result = OpenGL::VertexAttributeArrayType::Float;          break;
        case GL_INT:            result = OpenGL::VertexAttributeArrayType::Int;            break;
        case GL_SHORT:          result = OpenGL::VertexAttributeArrayType::Short;          break;
        case GL_UNSIGNED_BYTE:  result = OpenGL::VertexAttributeArrayType::Unsigned_Byte;  break;
        case GL_UNSIGNED_INT:   result = OpenGL::VertexAttributeArrayType::Unsigned_Int;   break;
        case GL_UNSIGNED_SHORT: result = OpenGL::VertexAttributeArrayType::Unsigned_Short; break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::VertexAttributeProperty OpenGL::Utils::get_vertex_attribute_property_for_gl_enum(const GLenum& in_pname)
{
    OpenGL::VertexAttributeProperty result = OpenGL::VertexAttributeProperty::Unknown;

    switch (in_pname)
    {
        case GL_VERTEX_ATTRIB_ARRAY_SIZE:           result = OpenGL::VertexAttributeProperty::Array_Size;               break;
        case GL_VERTEX_ATTRIB_ARRAY_TYPE:           result = OpenGL::VertexAttributeProperty::Array_Type;               break;
        case GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING: result = OpenGL::VertexAttributeProperty::Buffer_Binding;           break;
        case GL_CURRENT_VERTEX_ATTRIB:              result = OpenGL::VertexAttributeProperty::Current_Vertex_Attribute; break;
        case GL_VERTEX_ATTRIB_ARRAY_ENABLED:        result = OpenGL::VertexAttributeProperty::Enabled;                  break;
        case GL_VERTEX_ATTRIB_ARRAY_INTEGER:        result = OpenGL::VertexAttributeProperty::Integer;                  break;
        case GL_VERTEX_ATTRIB_ARRAY_NORMALIZED:     result = OpenGL::VertexAttributeProperty::Normalized;               break;
        case GL_VERTEX_ATTRIB_ARRAY_STRIDE:         result = OpenGL::VertexAttributeProperty::Stride;                   break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

bool OpenGL::Utils::is_context_property_gl_constant(const OpenGL::ContextProperty& in_pname)
{
    /* NOTE: Needs to stay in sync with GLConstants::GLConstants() ! */
    bool result = false;

    switch (in_pname)
    {
        case OpenGL::ContextProperty::Context_Flags:
        case OpenGL::ContextProperty::Context_Profile_Mask:
        case OpenGL::ContextProperty::Extensions:
        case OpenGL::ContextProperty::Major_Version:
        case OpenGL::ContextProperty::Minor_Version:
        case OpenGL::ContextProperty::Num_Extensions:
        case OpenGL::ContextProperty::Renderer:
        case OpenGL::ContextProperty::Shading_Language_Version:
        case OpenGL::ContextProperty::Vendor:
        case OpenGL::ContextProperty::Version:
        {
            result = true;
        }
    }

    return result;
}

bool OpenGL::Utils::is_context_property_gl_limit(const OpenGL::ContextProperty& in_pname)
{
    /* NOTE: Needs to stay in sync with GLLimits::GLLimits() ! */
    bool result = false;

    switch (in_pname)
    {
        case OpenGL::ContextProperty::Aliased_Line_Width_Range:
        case OpenGL::ContextProperty::Max_3D_Texture_Size:
        case OpenGL::ContextProperty::Max_Array_Texture_Layers:
        case OpenGL::ContextProperty::Max_Clip_Distances:
        case OpenGL::ContextProperty::Max_Color_Attachments:
        case OpenGL::ContextProperty::Max_Color_Texture_Samples:
        case OpenGL::ContextProperty::Max_Combined_Fragment_Uniform_Components:
        case OpenGL::ContextProperty::Max_Combined_Geometry_Uniform_Components:
        case OpenGL::ContextProperty::Max_Combined_Texture_Image_Units:
        case OpenGL::ContextProperty::Max_Combined_Uniform_Blocks:
        case OpenGL::ContextProperty::Max_Combined_Vertex_Uniform_Components:
        case OpenGL::ContextProperty::Max_Cube_Map_Texture_Size:
        case OpenGL::ContextProperty::Max_Depth_Texture_Samples:
        case OpenGL::ContextProperty::Max_Draw_Buffers:
        case OpenGL::ContextProperty::Max_Elements_Indices:
        case OpenGL::ContextProperty::Max_Elements_Vertices:
        case OpenGL::ContextProperty::Max_Fragment_Input_Components:
        case OpenGL::ContextProperty::Max_Fragment_Uniform_Blocks:
        case OpenGL::ContextProperty::Max_Fragment_Uniform_Components:
        case OpenGL::ContextProperty::Max_Geometry_Input_Components:
        case OpenGL::ContextProperty::Max_Geometry_Output_Components:
        case OpenGL::ContextProperty::Max_Geometry_Output_Vertices:
        case OpenGL::ContextProperty::Max_Geometry_Texture_Image_Units:
        case OpenGL::ContextProperty::Max_Geometry_Total_Output_Components:
        case OpenGL::ContextProperty::Max_Geometry_Uniform_Blocks:
        case OpenGL::ContextProperty::Max_Geometry_Uniform_Components:
        case OpenGL::ContextProperty::Max_Integer_Samples:
        case OpenGL::ContextProperty::Max_Program_Texel_Offset:
        case OpenGL::ContextProperty::Max_Rectangle_Texture_Size:
        case OpenGL::ContextProperty::Max_Renderbuffer_Size:
        case OpenGL::ContextProperty::Max_Sample_Mask_Words:
        case OpenGL::ContextProperty::Max_Samples:
        case OpenGL::ContextProperty::Max_Server_Wait_Timeout:
        case OpenGL::ContextProperty::Max_Texture_Buffer_Size:
        case OpenGL::ContextProperty::Max_Texture_Image_Units:
        case OpenGL::ContextProperty::Max_Texture_LOD_Bias:
        case OpenGL::ContextProperty::Max_Texture_Size:
        case OpenGL::ContextProperty::Max_Transform_Feedback_Buffers:
        case OpenGL::ContextProperty::Max_Transform_Feedback_Interleaved_Components:
        case OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Attribs:
        case OpenGL::ContextProperty::Max_Transform_Feedback_Separate_Components:
        case OpenGL::ContextProperty::Max_Uniform_Block_Size:
        case OpenGL::ContextProperty::Max_Uniform_Buffer_Bindings:
        case OpenGL::ContextProperty::Max_Varying_Components:
        case OpenGL::ContextProperty::Max_Vertex_Attribs:
        case OpenGL::ContextProperty::Max_Vertex_Output_Components:
        case OpenGL::ContextProperty::Max_Vertex_Texture_Image_Units:
        case OpenGL::ContextProperty::Max_Vertex_Uniform_Blocks:
        case OpenGL::ContextProperty::Max_Vertex_Uniform_Components:
        case OpenGL::ContextProperty::Max_Viewport_Dims:
        case OpenGL::ContextProperty::Min_Program_Texel_Offset:
        case OpenGL::ContextProperty::Point_Fade_Threshold_Size:
        case OpenGL::ContextProperty::Point_Size_Granularity:
        case OpenGL::ContextProperty::Point_Size_Range:
        case OpenGL::ContextProperty::Query_Counter_Bits:
        case OpenGL::ContextProperty::Smooth_Line_Width_Granularity:
        case OpenGL::ContextProperty::Smooth_Line_Width_Range:
        case OpenGL::ContextProperty::Subpixel_Bits:
        case OpenGL::ContextProperty::Uniform_Buffer_Offset_Alignment:
        {
            result = true;

            break;
        }

        default:
        {
            result = false;
        }
    }

    return result;
}

bool OpenGL::Utils::is_texture_binding_pname(const OpenGL::ContextProperty& in_pname)
{
    return (in_pname == OpenGL::ContextProperty::Texture_Binding_1D                   ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_1D_Array             ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_2D                   ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_2D_Array             ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_2D_Multisample       ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_2D_Multisample_Array ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_3D                   ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_Buffer               ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_Cube_Map             ||
            in_pname == OpenGL::ContextProperty::Texture_Binding_Rectangle);
}
