/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_INTERCEPTORS_H
#define WGL_INTERCEPTORS_H

#include "Common/globals.h"
#include <vector>

extern std::vector<FunctionInterceptor> get_wgl_function_interceptors();

#endif /* WGL_INTERCEPTORS_H */