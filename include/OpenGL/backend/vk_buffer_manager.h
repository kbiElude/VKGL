/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_BUFFER_MANAGER_H
#define VKGL_VK_BUFFER_MANAGER_H

#include "Anvil/include/misc/types.h"
#include "OpenGL/backend/vk_reference.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef std::unique_ptr<VKBufferManager> VKBufferManagerUniquePtr;

    class VKBufferManager
    {
    public:
        /* Public functions */

        static VKBufferManagerUniquePtr create();

        ~VKBufferManager();

        OpenGL::VKBufferReferenceUniquePtr acquire_object(const GLuint&             in_id,
                                                          OpenGL::TimeMarker        in_frontend_object_creation_time,
                                                          OpenGL::TimeMarker        in_buffer_time_marker,
                                                          OpenGL::TimeMarker        in_mem_block_time_marker);
        bool                               create_object (const GLuint&             in_id,
                                                          const OpenGL::TimeMarker& in_frontend_object_creation_time);
        bool                               destroy_object(const GLuint&             in_id,
                                                          const OpenGL::TimeMarker& in_frontend_object_creation_time);

        OpenGL::TimeMarker get_tot_buffer_time_marker      (const GLuint&             in_id,
                                                            const OpenGL::TimeMarker& in_frontend_object_creation_time) const;
        OpenGL::TimeMarker get_tot_memory_block_time_marker(const GLuint&             in_id,
                                                            const OpenGL::TimeMarker& in_frontend_object_creation_time) const;

        OpenGL::TimeMarker set_tot_buffer_object      (const GLuint&               in_id,
                                                       const OpenGL::TimeMarker&   in_frontend_object_creation_time,
                                                       Anvil::BufferUniquePtr      in_buffer_ptr);
        OpenGL::TimeMarker set_tot_memory_block_object(const GLuint&               in_id,
                                                       const OpenGL::TimeMarker&   in_frontend_object_creation_time,
                                                       Anvil::MemoryBlockUniquePtr in_memory_block_ptr);

    private:
        /* Private type definitions */
        typedef struct BufferProps
        {
            Anvil::BufferUniquePtr                  buffer_ptr;
            std::vector<OpenGL::VKBufferReference*> reference_ptrs;

            BufferProps(Anvil::BufferUniquePtr in_buffer_ptr)
                :buffer_ptr(std::move(in_buffer_ptr) )
            {
                /* Stub */
            }
        } BufferProps;
        typedef std::unique_ptr<BufferProps> BufferPropsUniquePtr;

        typedef struct MemoryBlockProps
        {
            Anvil::MemoryBlockUniquePtr             memory_block_ptr;
            std::vector<OpenGL::VKBufferReference*> reference_ptrs;

            MemoryBlockProps(Anvil::MemoryBlockUniquePtr in_mem_block_ptr)
                :memory_block_ptr(std::move(in_mem_block_ptr) )
            {
                /* Stub */
            }
        } MemoryBlockProps;
        typedef std::unique_ptr<MemoryBlockProps> MemoryBlockPropsUniquePtr;

        typedef struct BufferData
        {
            /* Maintain "snapshots" of object instances until all references are destroyed.
             *
             * This is important because, even though an app requests object deletion, a VK object
             * might still be referenced by command buffers, buffer views, etc.
             */
            std::map<OpenGL::TimeMarker, BufferPropsUniquePtr>      buffer_map;
            std::map<OpenGL::TimeMarker, MemoryBlockPropsUniquePtr> memory_block_map;

            OpenGL::TimeMarker tot_buffer_time_marker;
            OpenGL::TimeMarker tot_memory_block_time_marker;

            bool has_been_destroyed;

            BufferData()
            {
                has_been_destroyed = false;
            }
        } BufferData;
        typedef std::unique_ptr<BufferData> BufferDataUniquePtr;

        typedef std::pair<GLuint, OpenGL::TimeMarker> BufferMapKey;

        /* Private functions */
        uint32_t get_n_references      (const BufferData*          in_buffer_data_ptr) const;
        void     on_reference_created  (BufferData*                in_buffer_data_ptr,
                                        OpenGL::VKBufferReference* in_reference_ptr);
        void     on_reference_destroyed(BufferData*                in_buffer_data_ptr,
                                        OpenGL::VKBufferReference* in_reference_ptr);

        /* Private variables */
        std::map<BufferMapKey, BufferDataUniquePtr> m_buffers;
        mutable std::mutex                          m_mutex;
    };
};

#endif /* VKGL_VK_BUFFER_MANAGER_H */