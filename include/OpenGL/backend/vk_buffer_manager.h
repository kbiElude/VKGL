/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_BUFFER_MANAGER_H
#define VKGL_VK_BUFFER_MANAGER_H

#include "Anvil/include/misc/types.h"
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

        bool create_object (const GLuint&             in_id,
                            const OpenGL::TimeMarker& in_frontend_object_creation_time);
        bool destroy_object(const GLuint&             in_id,
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
        typedef struct BufferData
        {
            Anvil::BufferUniquePtr                  buffer_ptr;
            std::vector<OpenGL::ReferenceUniquePtr> reference_ptrs;
        } BufferData;
        typedef std::unique_ptr<BufferData> BufferDataUniquePtr;

        typedef struct MemoryBlockData
        {
            Anvil::MemoryBlockUniquePtr             memory_block_ptr;
            std::vector<OpenGL::ReferenceUniquePtr> reference_ptrs;
        } MemoryBlockData;
        typedef std::unique_ptr<MemoryBlockData> MemoryBlockDataUniquePtr;

        typedef struct VKBufferData
        {
            std::map<OpenGL::TimeMarker, BufferDataUniquePtr>      buffer_map;
            std::map<OpenGL::TimeMarker, MemoryBlockDataUniquePtr> memory_block_map;

            OpenGL::TimeMarker tot_buffer_time_marker;
            OpenGL::TimeMarker tot_memory_block_time_marker;

        } VKBufferData;

        /* Private functions */

        /* Private variables */
    };
};

#endif /* VKGL_VK_BUFFER_MANAGER_H */