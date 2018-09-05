/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/entrypoints/WGL_ARB_create_context/wgl_create_context_attribs_arb.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/utils_trace.h"

HGLRC WINAPI WGL::create_context_attribs_arb(HDC        in_hdc,
                                             HGLRC      in_share_context_handle,
                                             const int* in_attrib_list_ptr)
{
    WGL::Context* result_ptr = nullptr;

    VKGL_TRACE("wglCreateContextAttribsARB(\n"
               " in_hdc                  = [%p]\n"
               " in_share_context_handle = [%p]\n"
               " in_attrib_list_ptr      = %s)",
               in_hdc,
               in_share_context_handle,
               WGL::convert_context_attrib_list_to_raw_string(in_attrib_list_ptr) );

    result_ptr = WGL::Context::create(in_hdc,
                                      reinterpret_cast<WGL::Context*>(in_share_context_handle),
                                      in_attrib_list_ptr);

    vkgl_assert(result_ptr != nullptr);
    return reinterpret_cast<HGLRC>(result_ptr);
}
