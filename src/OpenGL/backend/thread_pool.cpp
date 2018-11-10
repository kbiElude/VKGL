/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/thread_pool.h"

OpenGL::ThreadPool::ThreadPool()
{
    /* Stub */
}

OpenGL::ThreadPool::~ThreadPool()
{
    /* Stub */
}

OpenGL::ThreadPoolUniquePtr OpenGL::ThreadPool::create()
{
    OpenGL::ThreadPoolUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::ThreadPool() );

    vkgl_assert(result_ptr != nullptr);
    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

bool OpenGL::ThreadPool::init()
{
    bool result = false;

    vkgl_not_implemented();

    result = true;
    return result;
}

void OpenGL::ThreadPool::submit_task(std::function<void()> in_callback)
{
    vkgl_not_implemented();
}
