/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/converters.h"
#include "OpenGL/utils_enum.h"

static void convert_from_f32(const void*                     in_vals_ptr,
                             const uint32_t&                 in_n_vals,
                             const VKGL::GetSetArgumentType& in_dst_type,
                             void*                           out_result_ptr)
{
    const float* in_vals_f32_ptr = reinterpret_cast<const float*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case VKGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = !(fabs(in_vals_f32_ptr[n_val]) < 1e-5f);
                break;
            }

            case VKGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_f32_ptr[n_val];
                break;
            }

            case VKGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_f32_ptr[n_val];
                break;
            }

            case VKGL::GetSetArgumentType::Int:
            {
                int* result_ptr = reinterpret_cast<int*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<int>(in_vals_f32_ptr[n_val]);
                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

static void convert_from_f64(const void*                     in_vals_ptr,
                             const uint32_t&                 in_n_vals,
                             const VKGL::GetSetArgumentType& in_dst_type,
                             void*                           out_result_ptr)
{
    const double* in_vals_f64_ptr = reinterpret_cast<const double*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case VKGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = !(fabs(in_vals_f64_ptr[n_val]) < 1e-5f);
                break;
            }

            case VKGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = in_vals_f64_ptr[n_val];
                break;
            }

            case VKGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<float>(in_vals_f64_ptr[n_val]);
                break;
            }

            case VKGL::GetSetArgumentType::Int:
            {
                int* result_ptr = reinterpret_cast<int*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<int>(in_vals_f64_ptr[n_val]);
                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }
}

static void convert_from_i32(const void*                     in_vals_ptr,
                             const uint32_t&                 in_n_vals,
                             const VKGL::GetSetArgumentType& in_dst_type,
                             void*                           out_result_ptr)
{
    const int32_t* in_vals_i32_ptr = reinterpret_cast<const int32_t*>(in_vals_ptr);

    for (uint32_t n_val = 0;
                  n_val < in_n_vals;
                ++n_val)
    {
        switch (in_dst_type)
        {
            case VKGL::GetSetArgumentType::Boolean:
            {
                bool* result_ptr = reinterpret_cast<bool*>(out_result_ptr) + n_val;

                *result_ptr = (in_vals_i32_ptr[n_val] != 0);
                break;
            }

            case VKGL::GetSetArgumentType::Double:
            {
                double* result_ptr = reinterpret_cast<double*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<double>(in_vals_i32_ptr[n_val]);
                break;
            }

            case VKGL::GetSetArgumentType::Float:
            {
                float* result_ptr = reinterpret_cast<float*>(out_result_ptr) + n_val;

                *result_ptr = static_cast<float>(in_vals_i32_ptr[n_val]);
                break;
            }

            case VKGL::GetSetArgumentType::Int:
            {
                int* result_ptr = reinterpret_cast<int*>(out_result_ptr) + n_val;

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

void VKGL::Converters::convert(const VKGL::GetSetArgumentType& in_src_type,
                               const void*                     in_vals_ptr,
                               const uint32_t&                 in_n_vals,
                               const VKGL::GetSetArgumentType& in_dst_type,
                               void*                           out_result_ptr)
{
    switch (in_src_type)
    {
        case VKGL::GetSetArgumentType::BlendEquationVKGL:
        {
            const GLenum blend_equation_gl = VKGL::Utils::get_gl_enum_for_blend_equation(*reinterpret_cast<const VKGL::BlendEquation*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                          &blend_equation_gl,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case VKGL::GetSetArgumentType::BlendFunctionVKGL:
        {
            const GLenum blend_func_gl = VKGL::Utils::get_gl_enum_for_blend_function(*reinterpret_cast<const VKGL::BlendFunction*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                          &blend_func_gl,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case VKGL::GetSetArgumentType::Boolean:
        {
            const uint32_t val = ((*reinterpret_cast<const bool*>(in_vals_ptr) ) == true);

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                          &val,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case VKGL::GetSetArgumentType::BooleanFromInt32_Bit0:
        {
            const uint32_t val = ((*reinterpret_cast<const int32_t*>(in_vals_ptr) ) & (1 << 0) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                          &val,
                           1, /* in_n_vals */
                           in_dst_type,
                           out_result_ptr);
        }

        case VKGL::GetSetArgumentType::CullFaceVKGL:
        {
            const GLenum cull_face_gl = VKGL::Utils::get_gl_enum_for_cull_mode(*reinterpret_cast<const VKGL::CullMode*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &cull_face_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::DepthFunctionVKGL:
        {
            const GLenum depth_func_gl = VKGL::Utils::get_gl_enum_for_depth_function(*reinterpret_cast<const VKGL::DepthFunction*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &depth_func_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::Double:
        {
            return convert_from_f64(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        case VKGL::GetSetArgumentType::Float:
        {
            return convert_from_f32(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        case VKGL::GetSetArgumentType::HintModeVKGL:
        {
            const GLenum hint_mode_gl = VKGL::Utils::get_gl_enum_for_hint_mode(*reinterpret_cast<const VKGL::HintMode*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &hint_mode_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::Int:
        {
            return convert_from_i32(in_vals_ptr,
                                    in_n_vals,
                                    in_dst_type,
                                    out_result_ptr);
        }

        case VKGL::GetSetArgumentType::LogicOpModeVKGL:
        {
            const GLenum logic_op_mode_gl = VKGL::Utils::get_gl_enum_for_logic_op_mode(*reinterpret_cast<const VKGL::LogicOpMode*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &logic_op_mode_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::ProvokingVertexConventionVKGL:
        {
            const GLenum convention_gl = VKGL::Utils::get_gl_enum_for_provoking_vertex_convention(*reinterpret_cast<const VKGL::ProvokingVertexConvention*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &convention_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::StencilFunctionVKGL:
        {
            const GLenum stencil_func_gl = VKGL::Utils::get_gl_enum_for_stencil_function(*reinterpret_cast<const VKGL::StencilFunction*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &stencil_func_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::StencilOperationVKGL:
        {
            const GLenum stencil_op_gl = VKGL::Utils::get_gl_enum_for_stencil_operation(*reinterpret_cast<const VKGL::StencilOperation*>(in_vals_ptr) );

            vkgl_assert(in_n_vals == 1);

            return convert(VKGL::GetSetArgumentType::Int,
                         &stencil_op_gl,
                          1, /* in_n_vals */
                          in_dst_type,
                          out_result_ptr);
        }

        case VKGL::GetSetArgumentType::String:
        default:
        {
            vkgl_assert_fail();
        }
    }
}
