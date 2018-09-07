/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/globals.h"
#include "WGL/context.h"
#include "WGL/globals.h"
#include "WGL/entrypoints/wgl_make_current.h"

#if defined(VKGL_INCLUDE_OPENGL)
    #include "OpenGL/context.h"
    #include "OpenGL/globals.h"
#endif

BOOL WINAPI WGL::make_current(HDC   in_hdc,
                              HGLRC in_hglrc)
{
    VKGL_TRACE("wglMakeCurrent(in_hdc=[%p] in_hglrc=[%p])",
               in_hdc,
               in_hglrc);

    WGL::g_current_wgl_context_ptr = reinterpret_cast<WGL::Context*>(in_hglrc);

    if (WGL::g_current_wgl_context_ptr != nullptr)
    {
        WGL::g_current_wgl_context_ptr->set_current_hdc(in_hdc);

        #if defined(VKGL_INCLUDE_OPENGL)
        {
            OpenGL::g_dispatch_table_ptr = WGL::g_current_wgl_context_ptr->get_gl_context_ptr()->get_dispatch_table();
        }
        #endif
    }
    else
    {
        #if defined(VKGL_INCLUDE_OPENGL)
        {
            OpenGL::g_dispatch_table_ptr = nullptr;
        }
        #endif
    }

    return TRUE;
}
