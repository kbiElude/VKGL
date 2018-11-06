/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_COMMON_FENCE_H
#define VKGL_COMMON_FENCE_H

#include <chrono>
#include <condition_variable>
#include <mutex>

namespace VKGL
{
    /* Derivation of Common::Semaphore where the wait operation does NOT change the status of the signalled flag. */
    class Fence
    {
    public:
        /* Public functions */
         Fence();
        ~Fence();

        void signal           ();
        void wait             ();
        bool wait_with_timeout(std::chrono::milliseconds in_timeout);

    private:
        /* Private variables */
        std::condition_variable m_condition;
        bool                    m_flag;
        std::mutex              m_mutex;

        /* Private functions */

        Fence           (const Fence&);
        Fence& operator=(const Fence&);
    };
    typedef std::unique_ptr<Fence, std::function<void(Fence*)> > FenceUniquePtr;
};

#endif /* VKGL_COMMON_FENCE_H */