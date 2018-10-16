/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FORMATS_H
#define VKGL_GL_FORMATS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    namespace GLFormats
    {
        OpenGL::InternalFormat get_best_fit_color_internal_format                  (const uint32_t*               in_bits_per_rgba_component_uvec4_ptr,
                                                                                    const uint32_t&               in_shared_bits);
        OpenGL::InternalFormat get_best_fit_ds_internal_format                     (const uint32_t&               in_depth_bits,
                                                                                    const uint32_t&               in_stencil_bits);
        OpenGL::FormatDataType get_format_data_type_for_non_base_internal_format   (const OpenGL::InternalFormat& in_format);
        uint32_t               get_n_components_for_sized_internal_format          (const OpenGL::InternalFormat& in_format);
        bool                   get_per_component_bit_size_for_sized_internal_format(const OpenGL::InternalFormat& in_format,
                                                                                    uint32_t*                     out_rgba_bit_size_ptr,
                                                                                    uint32_t*                     out_ds_size_ptr,
                                                                                    uint32_t*                     out_shared_size_ptr);
        bool                   is_base_internal_format                             (const OpenGL::InternalFormat& in_format);
        bool                   is_compressed_internal_format                       (const OpenGL::InternalFormat& in_format);
        bool                   is_sized_internal_format                            (const OpenGL::InternalFormat& in_format);
    };
};

#endif /* VKGL_GL_FORMATS_H */
