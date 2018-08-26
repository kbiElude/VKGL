/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef GDI32_UTILS_TRACE_H
#define GDI32_UTILS_TRACE_H

#include <windows.h>

namespace GDI32
{
    const char* convert_pixel_format_descriptor_to_raw_string(const PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr);
}

#endif /* GDI32_UTILS_TRACE_H */