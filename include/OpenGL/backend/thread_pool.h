/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_THREAD_POOL_H
#define VKGL_VK_THREAD_POOL_H

#include "enkiTS/src/TaskScheduler_c.h"
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
        class EnkiTaskSet
        {
        public:
            EnkiTaskSet(enkiTaskScheduler*   in_task_scheduler_ptr,
                        enkiTaskExecuteRange in_task_func_ptr)
                :m_task_scheduler_ptr(in_task_scheduler_ptr),
                 m_task_set_ptr      (nullptr)
            {
                m_task_set_ptr = enkiCreateTaskSet(in_task_scheduler_ptr,
                                                   in_task_func_ptr);

                vkgl_assert(m_task_set_ptr != nullptr);
            }

            ~EnkiTaskSet()
            {
                enkiDeleteTaskSet(m_task_set_ptr);
            }

            enkiTaskScheduler* get_task_scheduler_ptr()
            {
                return m_task_scheduler_ptr;
            }

            enkiTaskSet* get_enki_task_set_ptr()
            {
                return m_task_set_ptr;
            }

        private:
            enkiTaskScheduler* m_task_scheduler_ptr;
            enkiTaskSet*       m_task_set_ptr;

            ANVIL_DISABLE_ASSIGNMENT_OPERATOR(EnkiTaskSet);
            ANVIL_DISABLE_COPY_CONSTRUCTOR   (EnkiTaskSet);
        };
        typedef std::unique_ptr<EnkiTaskSet> EnkiTaskSetUniquePtr;

        class Task
        {
        public:
            Task(std::function<void()> in_callback_func,
                 EnkiTaskSetUniquePtr  in_enki_task_set_ptr);

            EnkiTaskSet* get_enki_task_set_ptr()
            {
                return m_enki_task_set_ptr.get();
            }

            static void handle_callback(uint32_t in_start,
                                        uint32_t in_end,
                                        uint32_t in_n_thread,
                                        void*    in_args_ptr);

        private:
            std::function<void()> m_callback_func;
            EnkiTaskSetUniquePtr  m_enki_task_set_ptr;
        };

        /* Private functions */
        ThreadPool();

        bool init();

        /* Private variables */
        enkiTaskScheduler* m_task_scheduler_ptr;
    };
}
#endif /* VKGL_VK_THREAD_POOL_H */
