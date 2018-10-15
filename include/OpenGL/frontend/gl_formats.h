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
        static OpenGL::FormatDataType get_format_data_type_for_non_base_internal_format   (const OpenGL::InternalFormat& in_format);
        static uint32_t               get_n_components_for_sized_internal_format          (const OpenGL::InternalFormat& in_format);
        static bool                   get_per_component_bit_size_for_sized_internal_format(const OpenGL::InternalFormat& in_format,
                                                                                           uint32_t*                     out_rgba_bit_size_ptr,
                                                                                           uint32_t*                     out_ds_size_ptr,
                                                                                           uint32_t*                     out_shared_size_ptr);
        static bool                   is_base_internal_format                             (const OpenGL::InternalFormat& in_format);
        static bool                   is_compressed_internal_format                       (const OpenGL::InternalFormat& in_format);
        static bool                   is_sized_internal_format                            (const OpenGL::InternalFormat& in_format);
    };
};

#endif /* VKGL_GL_FORMATS_H */
