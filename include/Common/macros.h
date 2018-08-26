/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

#include "Common/debug.h"

#ifdef _DEBUG
    #define vkgl_assert(assertion)                  \
        if (!(assertion))                           \
        {                                           \
            VKGL::Debug::assert_failed(__FILE__,    \
                                       __LINE__,    \
                                       #assertion); \
        }

    #define vkgl_assert_fail()                                      \
        VKGL::Debug::assert_failed(__FILE__,                        \
                                   __LINE__,                        \
                                   "Unexpected condition detected");
#else
    #define vkgl_assert(assertion)
    #define vkgl_assert_fail()
#endif

#endif /* COMMON_MACROS_H */