/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "GDI32/utils_trace.h"
#include <string>
#include <sstream>

const char* GDI32::convert_pixel_format_descriptor_to_raw_string(const PIXELFORMATDESCRIPTOR* in_pixel_format_descriptor_ptr)
{
    static VKGL_THREADLOCAL char cache[MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE];
    std::stringstream            result_sstream;
    std::string                  result_string;

    result_sstream << "+ ::bReserved       = " << in_pixel_format_descriptor_ptr->bReserved        << "\n"
                   << "+ ::cAccumAlphaBits = " << in_pixel_format_descriptor_ptr->cAccumAlphaBits  << "\n"
                   << "+ ::cAccumBits      = " << in_pixel_format_descriptor_ptr->cAccumBits       << "\n"
                   << "+ ::cAccumBlueBits  = " << in_pixel_format_descriptor_ptr->cAccumBlueBits   << "\n"
                   << "+ ::cAccumGreenBits = " << in_pixel_format_descriptor_ptr->cAccumGreenBits  << "\n"
                   << "+ ::cAccumRedBits   = " << in_pixel_format_descriptor_ptr->cAccumRedBits    << "\n"
                   << "+ ::cAlphaBits      = " << in_pixel_format_descriptor_ptr->cAlphaBits       << "\n"
                   << "+ ::cAlphaShift     = " << in_pixel_format_descriptor_ptr->cAlphaShift      << "\n"
                   << "+ ::cAuxBuffers     = " << in_pixel_format_descriptor_ptr->cAuxBuffers      << "\n"
                   << "+ ::cBlueBits       = " << in_pixel_format_descriptor_ptr->cBlueBits        << "\n"
                   << "+ ::cBlueShift      = " << in_pixel_format_descriptor_ptr->cBlueShift       << "\n"
                   << "+ ::cColorBits      = " << in_pixel_format_descriptor_ptr->cColorBits       << "\n"
                   << "+ ::cDepthBits      = " << in_pixel_format_descriptor_ptr->cDepthBits       << "\n"
                   << "+ ::cGreenBits      = " << in_pixel_format_descriptor_ptr->cGreenBits       << "\n"
                   << "+ ::cGreenShift     = " << in_pixel_format_descriptor_ptr->cGreenShift      << "\n"
                   << "+ ::cRedBits        = " << in_pixel_format_descriptor_ptr->cRedBits         << "\n"
                   << "+ ::cRedShift       = " << in_pixel_format_descriptor_ptr->cRedShift        << "\n"
                   << "+ ::cStencilBits    = " << in_pixel_format_descriptor_ptr->cStencilBits     << "\n"
                   << "+ ::dwDamageMask    = " << in_pixel_format_descriptor_ptr->dwDamageMask     << "\n"
                   << "+ ::dwFlags         = " << in_pixel_format_descriptor_ptr->dwFlags          << "\n"
                   << "+ ::dwLayerMask     = " << in_pixel_format_descriptor_ptr->dwLayerMask      << "\n"
                   << "+ ::dwVisibleMask   = " << in_pixel_format_descriptor_ptr->dwVisibleMask    << "\n"
                   << "+ ::iPixelType      = " << in_pixel_format_descriptor_ptr->iPixelType       << "\n"
                   << "+ ::iLayerType      = " << in_pixel_format_descriptor_ptr->iLayerType       << "\n"
                   << "+ ::nSize           = " << in_pixel_format_descriptor_ptr->nSize            << "\n"
                   << "+ ::nVersion        = " << in_pixel_format_descriptor_ptr->nVersion         << "\n";

    result_string = result_sstream.str().substr(0, MAX_PERF_OBJECTS_IN_QUERY_FUNCTION - 1 /* terminator */);

    memcpy(cache,
          &result_string.at  (0),
           result_string.length() );

    cache[result_string.length()] = 0;
    return cache;
}