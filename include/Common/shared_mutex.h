/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_COMMON_SHARED_MUTEX_H
#define VKGL_COMMON_SHARED_MUTEX_H

#include <condition_variable>
#include <mutex>

/* NOTE: Implemented by using ref impl @ http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2406.html#shared_mutex_imp
 *       Stuff not planned to be used was dropped.
 *
 *       Yes, I know Boost has this. And C++17, FWIW.
 */
namespace VKGL
{
    class SharedMutex
    {
    public:
        /* Public functions */
         SharedMutex();
        ~SharedMutex();

        void lock_unique  ();
        void unlock_unique();

        void lock_shared  ();
        void unlock_shared();

    private:
        /* Private variables */
        std::condition_variable m_gate1;
        std::condition_variable m_gate2;
        std::mutex              m_mutex;
        unsigned                m_state;

        /* Private functions */

        SharedMutex           (const SharedMutex&);
        SharedMutex& operator=(const SharedMutex&);
    };

    class SharedMutexReadLock
    {
    public:
        /* Public functions */
        SharedMutexReadLock(SharedMutex& in_mutex)
            :m_mutex(in_mutex)
        {
            /* Stub */
        }

        ~SharedMutexReadLock()
        {
            /* Stub */
        }

        void lock()
        {
            m_mutex.lock_shared();
        }

        void unlock()
        {
            m_mutex.unlock_shared();
        }

    private:
        /* Private variables */
        SharedMutex& m_mutex;
    };

    class SharedMutexWriteLock
    {
    public:
        /* Public functions */

        SharedMutexWriteLock(SharedMutex& in_mutex)
            :m_mutex(in_mutex)
        {
            /* Stub */
        }

        ~SharedMutexWriteLock()
        {
            /* Stub */
        }

        void lock()
        {
            m_mutex.lock_unique();
        }

        void unlock()
        {
            m_mutex.unlock_unique();
        }

    private:
        /* Private variables */

        SharedMutex& m_mutex;
    };
};

#endif /* VKGL_COMMON_SHARED_MUTEX_H */