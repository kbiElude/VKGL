/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/utils_enum.h"

static void convert_from_f32(const void*                       in_vals_ptr,
                             const uint32_t&                   in_n_vals,
                             const OpenGL::GetSetArgumentType& in_dst_type,
                             void*                             out_result_ptr)
{
    const float* in_vals_f32_ptr = reinterpret_cast<const float*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case OpenGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = !(fabs(in_vals_f32_ptr[n_val]) < 1e-5f);
                break;
            }

            case OpenGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_f32_ptr[n_val];
                break;
            }

            case OpenGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_f32_ptr[n_val];
                break;
            }

            case OpenGL::GetSetArgumentType::Int:
            {
                int32_t* result_ptr = reinterpret_cast<int32_t*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<int32_t>(in_vals_f32_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Unsigned_Int:
            {
                uint32_t* result_ptr = reinterpret_cast<uint32_t*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<uint32_t>(in_vals_f32_ptr[n_val]);
                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

static void convert_from_f64(const void*                       in_vals_ptr,
                             const uint32_t&                   in_n_vals,
                             const OpenGL::GetSetArgumentType& in_dst_type,
                             void*                             out_result_ptr)
{
    const double* in_vals_f64_ptr = reinterpret_cast<const double*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case OpenGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = !(fabs(in_vals_f64_ptr[n_val]) < 1e-5f);
                break;
            }

            case OpenGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_f64_ptr[n_val];
                break;
            }

            case OpenGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<float>(in_vals_f64_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Int:
            {
                int32_t* result_ptr = reinterpret_cast<int32_t*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<int32_t>(in_vals_f64_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Unsigned_Int:
            {
                uint32_t* result_ptr = reinterpret_cast<uint32_t*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<uint32_t>(in_vals_f64_ptr[n_val]);
                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

static void convert_from_i32(const void*                       in_vals_ptr,
                             const uint32_t&                   in_n_vals,
                             const OpenGL::GetSetArgumentType& in_dst_type,
                             void*                             out_result_ptr)
{
    const int32_t* in_vals_i32_ptr = reinterpret_cast<const int32_t*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case OpenGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = (in_vals_i32_ptr[n_val] != 0);
                break;
            }

            case OpenGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<double>(in_vals_i32_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<float>(in_vals_i32_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Int:
            {
                int32_t* result_ptr = reinterpret_cast<int32_t*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_i32_ptr[n_val];
                break;
            }

            case OpenGL::GetSetArgumentType::Unsigned_Int:
            {
                uint32_t* result_ptr = reinterpret_cast<uint32_t*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_i32_ptr[n_val];
                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

static void convert_from_u32(const void*                       in_vals_ptr,
                             const uint32_t&                   in_n_vals,
                             const OpenGL::GetSetArgumentType& in_dst_type,
                             void*                             out_result_ptr)
{
    const uint32_t* in_vals_i32_ptr = reinterpret_cast<const uint32_t*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case OpenGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = (in_vals_i32_ptr[n_val] != 0);
                break;
            }

            case OpenGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<double>(in_vals_i32_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<float>(in_vals_i32_ptr[n_val]);
                break;
            }

            case OpenGL::GetSetArgumentType::Int:
            {
                int32_t* result_ptr = reinterpret_cast<int32_t*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_i32_ptr[n_val];
                break;
            }

            case OpenGL::GetSetArgumentType::Unsigned_Int:
            {
                uint32_t* result_ptr = reinterpret_cast<uint32_t*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_i32_ptr[n_val];
                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

void OpenGL::Converters::convert(const OpenGL::GetSetArgumentType& in_src_type,
                                 const void*                       in_vals_ptr,
                                 const uint32_t&                   in_n_vals,
                                 const OpenGL::GetSetArgumentType& in_dst_type,
                                 void*                             out_result_ptr)
{
    switch (in_src_type)
    {
        case OpenGL::GetSetArgumentType::BlendEquationVKGL:
        {
            const GLenum blend_equation_gl = OpenGL::Utils::get_gl_enum_for_blend_equation(*reinterpret_cast<const OpenGL::BlendEquation*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                          &blend_equation_gl,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::BlendFunctionVKGL:
        {
            const GLenum blend_func_gl = OpenGL::Utils::get_gl_enum_for_blend_function(*reinterpret_cast<const OpenGL::BlendFunction*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                          &blend_func_gl,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::Boolean:
        {
            const uint32_t val = ((*reinterpret_cast<const bool*>(in_vals_ptr) ) == true);

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                          &val,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::BooleanFromInt32_Bit0:
        {
            const uint32_t val = ((*reinterpret_cast<const int32_t*>(in_vals_ptr) ) & (1 << 0) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                          &val,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::CullFaceVKGL:
        {
            const GLenum cull_face_gl = OpenGL::Utils::get_gl_enum_for_cull_mode(*reinterpret_cast<const OpenGL::CullMode*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &cull_face_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::DepthFunctionVKGL:
        {
            const GLenum depth_func_gl = OpenGL::Utils::get_gl_enum_for_depth_function(*reinterpret_cast<const OpenGL::DepthFunction*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &depth_func_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::Double:
        {
            return convert_from_f64(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::Float:
        {
            return convert_from_f32(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::HintModeVKGL:
        {
            const GLenum hint_mode_gl = OpenGL::Utils::get_gl_enum_for_hint_mode(*reinterpret_cast<const OpenGL::HintMode*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &hint_mode_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::Int:
        {
            return convert_from_i32(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::LogicOpModeVKGL:
        {
            const GLenum logic_op_mode_gl = OpenGL::Utils::get_gl_enum_for_logic_op_mode(*reinterpret_cast<const OpenGL::LogicOpMode*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &logic_op_mode_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::ProvokingVertexConventionVKGL:
        {
            const GLenum convention_gl = OpenGL::Utils::get_gl_enum_for_provoking_vertex_convention(*reinterpret_cast<const OpenGL::ProvokingVertexConvention*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &convention_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::StencilFunctionVKGL:
        {
            const GLenum stencil_func_gl = OpenGL::Utils::get_gl_enum_for_stencil_function(*reinterpret_cast<const OpenGL::StencilFunction*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &stencil_func_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::StencilOperationVKGL:
        {
            const GLenum stencil_op_gl = OpenGL::Utils::get_gl_enum_for_stencil_operation(*reinterpret_cast<const OpenGL::StencilOperation*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(OpenGL::GetSetArgumentType::Int,
                         &stencil_op_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case OpenGL::GetSetArgumentType::String:
        {
            vkgl_assert(in_dst_type == OpenGL::GetSetArgumentType::String);
            vkgl_assert(in_n_vals   == 1);

            *reinterpret_cast<const void**>(out_result_ptr) = reinterpret_cast<const void*>(in_vals_ptr);

            break;
        }

        case OpenGL::GetSetArgumentType::Unsigned_Int:
        {
            return convert_from_u32(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        default:
        {
            vkgl_assert_fail();
        }
    }
}
