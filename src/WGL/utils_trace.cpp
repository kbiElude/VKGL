/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "Common/types.h"
#include "Khronos/GL/glcorearb.h"
#include "Khronos/GL/wglext.h"
#include "WGL/utils_trace.h"
#include <sstream>
#include <string>

const char* WGL::convert_context_attrib_list_to_raw_string(const int* in_attrib_list)
{
    static VKGL_THREADLOCAL char cache[MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE];
    std::stringstream            result_sstream;
    std::string                  result_string;
    const int*                   traveller_ptr   = in_attrib_list;

    cache[0] = 0;

    result_sstream << "{\n";

    while (*traveller_ptr != 0)
    {
        const auto  attribute_name          = *traveller_ptr;
        auto        attribute_name_string   = WGL::get_context_attribute_name(attribute_name);
        const auto  attribute_value         = *(traveller_ptr + 1);
        std::string attribute_value_string;

        switch (attribute_name)
        {
            case WGL_CONTEXT_MAJOR_VERSION_ARB:
            case WGL_CONTEXT_MINOR_VERSION_ARB:
            case WGL_CONTEXT_LAYER_PLANE_ARB:
            {
                attribute_value_string = std::to_string(attribute_value);

                break;
            }

            case WGL_CONTEXT_FLAGS_ARB:
            {
                int helper_int = 0;

                if (attribute_value & WGL_CONTEXT_DEBUG_BIT_ARB)
                {
                    attribute_value_string  = "WGL_CONTEXT_DEBUG_BIT_ARB";
                    helper_int             |=  WGL_CONTEXT_DEBUG_BIT_ARB;
                }

                if (attribute_value & WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB)
                {
                    attribute_value_string += ((attribute_value_string.size() > 0) ? " " : "");
                    attribute_value_string += "WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB";
                    helper_int             |=  WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB;
                }

                vkgl_assert(helper_int == attribute_value);

                break;
            }

            case WGL_CONTEXT_PROFILE_MASK_ARB:
            {
                int helper_int = 0;

                if (attribute_value & WGL_CONTEXT_CORE_PROFILE_BIT_ARB)
                {
                    attribute_value_string  = "WGL_CONTEXT_CORE_PROFILE_BIT_ARB";
                    helper_int             |=  WGL_CONTEXT_CORE_PROFILE_BIT_ARB;
                }

                if (attribute_value & WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB)
                {
                    attribute_value_string += ((attribute_value_string.size() > 0) ? " " : "");
                    attribute_value_string += "WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB";
                    helper_int             |=  WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB;
                }

                vkgl_assert(helper_int == attribute_value);

                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }

        result_sstream << " + [" << attribute_name_string << "]"
                       << " = "
                       << attribute_value_string
                       << "\n";
        traveller_ptr += 2; /* name, value */
    }

    result_sstream << "}";

    result_string = result_sstream.str  ();
    result_string = result_string.substr(0, MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE - 1 /* terminator */);

    memcpy(cache,
           result_string.c_str(),
           result_string.length() );

    cache[result_string.length()] = 0;

    return cache;
}

const char* WGL::get_context_attribute_name(const int& in_attrib_name)
{
    const char* result_ptr = "???";

    switch (in_attrib_name)
    {
        case WGL_CONTEXT_MAJOR_VERSION_ARB: result_ptr = "WGL_CONTEXT_MAJOR_VERSION_ARB"; break;
        case WGL_CONTEXT_MINOR_VERSION_ARB: result_ptr = "WGL_CONTEXT_MINOR_VERSION_ARB"; break;
        case WGL_CONTEXT_LAYER_PLANE_ARB:   result_ptr = "WGL_CONTEXT_LAYER_PLANE_ARB";   break;
        case WGL_CONTEXT_FLAGS_ARB:         result_ptr = "WGL_CONTEXT_FLAGS_ARB";         break;
        case WGL_CONTEXT_PROFILE_MASK_ARB:  result_ptr = "WGL_CONTEXT_PROFILE_MASK_ARB";  break;

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result_ptr;
}