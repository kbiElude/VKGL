/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef COMMON_GLOBALS_H
#define COMMON_GLOBALS_H

struct FunctionInterceptor
{
    void** pfn_func_to_intercept_ptr_ptr;
    void*  pfn_interceptor_func_ptr;

    FunctionInterceptor()
    {
        pfn_func_to_intercept_ptr_ptr = nullptr;
        pfn_interceptor_func_ptr      = nullptr;
    }

    FunctionInterceptor(void** in_pfn_func_to_intercept_ptr_ptr,
                        void*  in_pfn_interceptor_func_ptr)
    {
        pfn_func_to_intercept_ptr_ptr = in_pfn_func_to_intercept_ptr_ptr;
        pfn_interceptor_func_ptr      = in_pfn_interceptor_func_ptr;
    }
};

#endif /* COMMON_GLOBALS_H */