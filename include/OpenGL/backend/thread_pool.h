/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_THREAD_POOL_H
#define VKGL_VK_THREAD_POOL_H

#include "OpenGL/types.h"

namespace OpenGL
{
    class ThreadPool
    {
    public:
        /* Public functions */
        static ThreadPoolUniquePtr create();

        ~ThreadPool();

        void submit_task(std::function<void()> in_callback);

    private:
        /* Private type definitions */

        /* Private functions */
        ThreadPool();

        bool init();

        /* Private variables */
    };
}
#endif /* VKGL_VK_THREAD_POOL_H */
