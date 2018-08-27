/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_create_context.h"

HGLRC WINAPI WGL::create_context(HDC in_hdc)
{
    WGL::Context* result_ptr = nullptr;

    VKGL_TRACE("wglCreateContext(in_hdc=[%p])",
               in_hdc);

    result_ptr = WGL::Context::create(in_hdc,
                                      nullptr,  /* in_opt_share_context_ptr */
                                      nullptr); /* in_attribute_list_ptr    */

    vkgl_assert(result_ptr != nullptr);
    return reinterpret_cast<HGLRC>(result_ptr);
}
