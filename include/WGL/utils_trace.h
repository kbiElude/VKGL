/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_UTILS_TRACE_H
#define WGL_UTILS_TRACE_H

namespace WGL
{
    const char* convert_context_attrib_list_to_raw_string(const int* in_attrib_list);
    const char* get_context_attribute_name               (const int& in_attrib_name);

}

#endif /* WGL_UTILS_TRACE_H */