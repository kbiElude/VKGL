/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_COMMON_RING_BUFFER_H
#define VKGL_COMMON_RING_BUFFER_H

#include "Common/macros.h"
#include "Common/semaphore.h"
#include <chrono>
#include <vector>

/* NOTE: Shamelessly based on https://github.com/angrave/SystemProgramming/wiki/Synchronization,-Part-8:-Ring-Buffer-Example */
namespace VKGL
{
    template<class ItemUniquePtrType>
    class RingBuffer
    {
    public:
        /* Public functions */
         RingBuffer(const uint8_t& in_n_max_items_log_2)
             :m_counter_in     (0),
              m_counter_out    (0),
              m_count_semaphore(0),
              m_space_semaphore(1 << in_n_max_items_log_2)
         {
             vkgl_assert(in_n_max_items_log_2 > 0);
             vkgl_assert(in_n_max_items_log_2 < sizeof(uint32_t) * 8 /* bits per byte */);

             m_items.resize(1 << in_n_max_items_log_2);
         }

        ~RingBuffer()
        {
            /* Stub */
        }

        ItemUniquePtrType grab()
        {
            ItemUniquePtrType result_ptr;

            m_count_semaphore.wait();

            {
                std::lock_guard<std::mutex> lock   (m_mutex);
                const uint32_t              n_items(static_cast<uint32_t>(m_items.size() ));

                result_ptr = std::move(m_items.at( (m_counter_out++) & (n_items - 1)) );
            }

            vkgl_assert(result_ptr != nullptr);

            m_space_semaphore.signal();
            return result_ptr;
        }

        bool grab_with_timeout(const std::chrono::milliseconds& in_timeout,
                               ItemUniquePtrType*               out_result_ptr)
        {
            bool              result     = false;
            ItemUniquePtrType result_ptr;

            if (!m_count_semaphore.wait_with_timeout(in_timeout) )
            {
                goto end;
            }

            {
                std::lock_guard<std::mutex> lock   (m_mutex);
                const uint32_t              n_items(static_cast<uint32_t>(m_items.size() ));

                result_ptr = std::move(m_items.at( (m_counter_out++) & (n_items - 1)) );
            }

            vkgl_assert(result_ptr != nullptr);

            m_space_semaphore.signal();

            *out_result_ptr = std::move(result_ptr);
            result          = true;
        end:
            return result;
        }

        void stash(ItemUniquePtrType item_ptr)
        {
            vkgl_assert(item_ptr != nullptr);

            m_space_semaphore.wait();

            {
                std::lock_guard<std::mutex> lock   (m_mutex);
                const uint32_t              n_items(static_cast<uint32_t>(m_items.size() ));

                m_items.at( (m_counter_in++) & (n_items - 1) ) = std::move(item_ptr);
            }

            m_count_semaphore.signal();
        }

    private:
        /* Private variables */
        uint32_t        m_counter_in;
        uint32_t        m_counter_out;
        VKGL::Semaphore m_count_semaphore;
        std::mutex      m_mutex;
        VKGL::Semaphore m_space_semaphore;

        std::vector<ItemUniquePtrType> m_items;

        /* Private functions */

        RingBuffer           (const RingBuffer&);
        RingBuffer& operator=(const RingBuffer&);
    };
};

#endif /* VKGL_COMMON_RING_BUFFER_H */