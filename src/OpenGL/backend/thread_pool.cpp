/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/thread_pool.h"

OpenGL::ThreadPool::Task::Task(std::function<void()> in_callback_func,
                               EnkiTaskSetUniquePtr  in_enki_task_set_ptr)
    :m_callback_func              (in_callback_func),
     m_enki_task_set_ptr(std::move(in_enki_task_set_ptr) )
{
    enkiAddTaskSetToPipe(in_enki_task_set_ptr->get_task_scheduler_ptr(),
                         in_enki_task_set_ptr->get_enki_task_set_ptr (),
                         this,
                         1); /* setSize_ */
}

void OpenGL::ThreadPool::Task::handle_callback(uint32_t in_start,
                                               uint32_t in_end,
                                               uint32_t in_n_thread,
                                               void*    in_args_ptr)
{
    Task* task_ptr = reinterpret_cast<Task*>(in_args_ptr);

    vkgl_assert(in_start    == 0);
    vkgl_assert(in_end      == 1);
    vkgl_assert(in_args_ptr != nullptr);

    task_ptr->m_callback_func();

    delete task_ptr;
}

OpenGL::ThreadPool::ThreadPool()
    :m_task_scheduler_ptr(nullptr)
{
    /* Stub */
}

OpenGL::ThreadPool::~ThreadPool()
{
    vkgl_assert(m_task_scheduler_ptr != nullptr);

    enkiWaitForAll         (m_task_scheduler_ptr);
    enkiDeleteTaskScheduler(m_task_scheduler_ptr);
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

    m_task_scheduler_ptr = enkiNewTaskScheduler();
    vkgl_assert(m_task_scheduler_ptr != nullptr);

    enkiInitTaskScheduler(m_task_scheduler_ptr);

    result = true;
    return result;
}

void OpenGL::ThreadPool::submit_task(std::function<void()> in_callback)
{
    EnkiTaskSetUniquePtr enki_task_set_ptr;
    Task*                task_ptr          = nullptr;

    enki_task_set_ptr.reset(
        new EnkiTaskSet(m_task_scheduler_ptr,
                        OpenGL::ThreadPool::Task::handle_callback)
    );
    vkgl_assert(enki_task_set_ptr != nullptr);

    /* NOTE: Task instance deletes itself upon completion */
    task_ptr = new Task(in_callback,
                        std::move(enki_task_set_ptr) );
    vkgl_assert(task_ptr != nullptr);
}
