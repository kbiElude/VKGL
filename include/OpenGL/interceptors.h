/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef OPENGL_INTERCEPTORS_H
#define OPENGL_INTERCEPTORS_H

#include "Common/globals.h"
#include <unordered_map>
#include <vector>

namespace OpenGL
{
    extern std::vector<VKGL::FunctionInterceptor> get_function_interceptors    ();
    extern std::unordered_map<std::string, void*> get_func_name_to_func_ptr_map();
}

#endif /* OPENGL_INTERCEPTORS_H */