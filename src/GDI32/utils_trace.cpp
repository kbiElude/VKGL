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

    result_sstream << "\n"
                      "+ ::bReserved       = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->bReserved)        << "\n"
                   << "+ ::cAccumAlphaBits = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAccumAlphaBits)  << "\n"
                   << "+ ::cAccumBits      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAccumBits)       << "\n"
                   << "+ ::cAccumBlueBits  = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAccumBlueBits)   << "\n"
                   << "+ ::cAccumGreenBits = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAccumGreenBits)  << "\n"
                   << "+ ::cAccumRedBits   = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAccumRedBits)    << "\n"
                   << "+ ::cAlphaBits      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAlphaBits)       << "\n"
                   << "+ ::cAlphaShift     = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAlphaShift)      << "\n"
                   << "+ ::cAuxBuffers     = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cAuxBuffers)      << "\n"
                   << "+ ::cBlueBits       = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cBlueBits)        << "\n"
                   << "+ ::cBlueShift      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cBlueShift)       << "\n"
                   << "+ ::cColorBits      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cColorBits)       << "\n"
                   << "+ ::cDepthBits      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cDepthBits)       << "\n"
                   << "+ ::cGreenBits      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cGreenBits)       << "\n"
                   << "+ ::cGreenShift     = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cGreenShift)      << "\n"
                   << "+ ::cRedBits        = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cRedBits)         << "\n"
                   << "+ ::cRedShift       = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cRedShift)        << "\n"
                   << "+ ::cStencilBits    = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->cStencilBits)     << "\n"
                   << "+ ::dwDamageMask    = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->dwDamageMask)     << "\n"
                   << "+ ::dwFlags         = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->dwFlags)          << "\n"
                   << "+ ::dwLayerMask     = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->dwLayerMask)      << "\n"
                   << "+ ::dwVisibleMask   = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->dwVisibleMask)    << "\n"
                   << "+ ::iPixelType      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->iPixelType)       << "\n"
                   << "+ ::iLayerType      = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->iLayerType)       << "\n"
                   << "+ ::nSize           = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->nSize)            << "\n"
                   << "+ ::nVersion        = " << static_cast<uint32_t>(in_pixel_format_descriptor_ptr->nVersion)         << "\n";

    result_string = result_sstream.str().substr(0, MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE - 1 /* terminator */);

    memcpy(cache,
          &result_string.at  (0),
           result_string.length() );

    cache[result_string.length()] = 0;
    return cache;
}