/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef COMMON_GLOBALS_H
#define COMMON_GLOBALS_H

#include "vkgl_config.h"
#include "Common/types.h"
#include "VKGL/logger.h"

#define MAX_PER_FUNC_LOCAL_HELPER_STORAGE_SIZE (4096)

#if defined(_WIN32)
    #define VKGL_THREADLOCAL __declspec(thread)
#else
    #error todo
#endif

#endif /* COMMON_GLOBALS_H */