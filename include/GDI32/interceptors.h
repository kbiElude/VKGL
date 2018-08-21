/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef GDI32_INTERCEPTORS_H
#define GDI32_INTERCEPTORS_H

#include "Common/globals.h"
#include <vector>

extern std::vector<FunctionInterceptor> get_gdi32_function_interceptors();

#endif /* GDI32_INTERCEPTORS_H */