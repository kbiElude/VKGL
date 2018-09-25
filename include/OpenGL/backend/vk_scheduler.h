/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_SCHEDULER_H
#define VKGL_VK_SCHEDULER_H

#include "Common/ring_buffer.h"
#include "OpenGL/types.h"
#include "OpenGL/backend/vk_commands.h"
#include <atomic>
#include <thread>

namespace OpenGL
{
    class VKScheduler
    {
    public:
        /* Public functions */
        static VKSchedulerUniquePtr create();

        ~VKScheduler();

        void submit(OpenGL::CommandBaseUniquePtr in_command_ptr);

    private:
        /* Private functions */
        VKScheduler();

        bool init                  ();
        void main_thread_entrypoint();
        void process_command       (OpenGL::CommandBaseUniquePtr in_command_ptr);

        /* Private variables */
        std::unique_ptr<VKGL::RingBuffer<CommandBaseUniquePtr> > m_command_ring_buffer_ptr;
        std::unique_ptr<std::thread>                             m_scheduler_thread_ptr;
        std::atomic_bool                                         m_terminating;
    };
};

#endif /* VKGL_VK_SCHEDULER_H */