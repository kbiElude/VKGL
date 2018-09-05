/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_COPY_CONTEXT_H
#define WGL_COPY_CONTEXT_H

#include <windows.h>

namespace WGL
{
    BOOL WINAPI copy_context(HGLRC in_hglrc_source,
                             HGLRC in_hglrc_destination,
                             UINT  in_mask);
}

#endif /* WGL_COPY_CONTEXT_H */