/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "GDI32/entrypoints/swap_buffers.h"
#include "GDI32/globals.h"
#include "OpenGL/context.h"
#include "WGL/context.h"

#if !defined(VKGL_INCLUDE_WGL)
    #error "swapBuffers() implementation requires WGL inclusion."
#endif

BOOL WINAPI GDI32::swap_buffers(HDC in_hdc)
{
    VKGL_TRACE("SwapBuffers(in_hdc=[%p])",
               in_hdc);

    /* NOTE: This call must be forwarded to the backend associated with this thread. */
    BOOL result          = FALSE;
    auto wgl_context_ptr = WGL::get_wgl_context_for_hdc(in_hdc);

    vkgl_assert(wgl_context_ptr != nullptr);
    if (wgl_context_ptr != nullptr)
    {
        auto gl_context_ptr = wgl_context_ptr->get_gl_context_ptr();

        vkgl_assert(gl_context_ptr != nullptr);
        if (gl_context_ptr != nullptr)
        {
            gl_context_ptr->present();

            result = TRUE;
        }
    }

    /* NOTE: Do NOT call OS impl for the function. We don't care. The backend handles everything for us. */
    return result;
}