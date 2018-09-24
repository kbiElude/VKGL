/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/shared_mutex.h"

static const unsigned g_write_entered = 1U << (sizeof(unsigned) * CHAR_BIT - 1);
static const unsigned g_n_readers     = ~g_write_entered;

VKGL::SharedMutex::SharedMutex()
    :m_state(0)
{
    /* Stub */
}

VKGL::SharedMutex::~SharedMutex()
{
    /* Stub */
}

void VKGL::SharedMutex::lock_unique()
{
    std::unique_lock<std::mutex> lock(m_mutex);

    while (m_state & g_write_entered)
    {
        m_gate1.wait(lock);
    }

    m_state |= g_write_entered;

    while (m_state & g_n_readers)
    {
        m_gate2.wait(lock);
    }
}

void VKGL::SharedMutex::unlock_unique()
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        m_state = 0;
    }

    m_gate1.notify_all();
}

void VKGL::SharedMutex::lock_shared()
{
    std::unique_lock<std::mutex> lock(m_mutex);

    while ((m_state & g_write_entered)                ||
           (m_state & g_n_readers)     == g_n_readers)
    {
        m_gate1.wait(lock);
    }

    unsigned num_readers = (m_state & g_n_readers) + 1;

    m_state &= ~g_n_readers;
    m_state |=  num_readers;
}

void VKGL::SharedMutex::unlock_shared()
{
    std::unique_lock<std::mutex> lock       (m_mutex);
    unsigned                     num_readers((m_state & g_n_readers) - 1);

    m_state &= ~g_n_readers;
    m_state |= num_readers;

    if (m_state & g_write_entered)
    {
        if (num_readers == 0)
        {
            m_gate2.notify_one();
        }
    }
    else
    {
        if (num_readers == g_n_readers - 1)
        {
            m_gate1.notify_one();
        }
    }
}