/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include "Common/macros.h"
#include <cstdint>

namespace VKGL
{
    /* Forward declarations */
    class Fence;

    struct FunctionInterceptor
    {
        void** pfn_func_to_intercept_ptr_ptr;
        void*  pfn_interceptor_func_ptr;

        FunctionInterceptor()
        {
            pfn_func_to_intercept_ptr_ptr = nullptr;
            pfn_interceptor_func_ptr      = nullptr;
        }

        FunctionInterceptor(void** in_pfn_func_to_intercept_ptr_ptr,
                            void*  in_pfn_interceptor_func_ptr)
        {
            pfn_func_to_intercept_ptr_ptr = in_pfn_func_to_intercept_ptr_ptr;
            pfn_interceptor_func_ptr      = in_pfn_interceptor_func_ptr;
        }
    };

    typedef struct PixelFormatRequirements
    {
        uint32_t n_alpha_bits;
        uint32_t n_alpha_shift_bits;
        uint32_t n_blue_bits;
        uint32_t n_blue_shift_bits;
        uint32_t n_depth_bits;
        uint32_t n_green_bits;
        uint32_t n_green_shift_bits;
        uint32_t n_red_bits;
        uint32_t n_red_shift_bits;
        uint32_t n_stencil_bits;

        PixelFormatRequirements()
            :n_alpha_bits      (0),
             n_alpha_shift_bits(0),
             n_blue_bits       (0),
             n_blue_shift_bits (0),
             n_depth_bits      (0),
             n_green_bits      (0),
             n_green_shift_bits(0),
             n_red_bits        (0),
             n_red_shift_bits  (0),
             n_stencil_bits    (0)
        {
            /* Stub */
        }

        PixelFormatRequirements(const uint32_t& in_n_alpha_bits,
                                const uint32_t& in_n_blue_bits,
                                const uint32_t& in_n_depth_bits,
                                const uint32_t& in_n_green_bits,
                                const uint32_t& in_n_red_bits,
                                const uint32_t& in_n_stencil_bits)
            :n_alpha_bits  (in_n_alpha_bits),
             n_blue_bits   (in_n_blue_bits),
             n_depth_bits  (in_n_depth_bits),
             n_green_bits  (in_n_green_bits),
             n_red_bits    (in_n_red_bits),
             n_stencil_bits(in_n_stencil_bits)
        {
            /* Stub */
        }
    } PixelFormatRequirements;

    class IWSIContext
    {
    public:
        virtual ~IWSIContext()
        {
            /* Stub */
        }

        virtual const VKGL::PixelFormatRequirements& get_pixel_format_requirements() const = 0;
        virtual const int&                           get_swap_interval            () const = 0;
        virtual const bool&                          is_debug_context             () const = 0;
        virtual const bool&                          is_forward_compatible_context() const = 0;
        virtual const uint32_t&                      get_major_version            () const = 0;
        virtual const uint32_t&                      get_minor_version            () const = 0;
        virtual const uint32_t&                      get_n_layer_plane            () const = 0;
    };
}

#endif /* COMMON_TYPES_H */