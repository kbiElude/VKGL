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

    class VKBufferManager : public IVKBufferManager
    {
    public:
        /* Public functions */

        static VKBufferManagerUniquePtr create(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                                               IBackend*                             in_backend_ptr);

        ~VKBufferManager();

        OpenGL::VKBufferReferenceUniquePtr acquire_object(const GLuint&             in_id,
                                                          OpenGL::TimeMarker        in_frontend_object_creation_time,
                                                          OpenGL::TimeMarker        in_buffer_time_marker);
        bool                               create_object (const GLuint&             in_id,
                                                          const OpenGL::TimeMarker& in_frontend_object_creation_time);
        bool                               destroy_object(const GLuint&             in_id,
                                                          const OpenGL::TimeMarker& in_frontend_object_creation_time);

        OpenGL::TimeMarker get_tot_buffer_time_marker(const GLuint&             in_id,
                                                      const OpenGL::TimeMarker& in_frontend_object_creation_time) const;

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

        typedef struct BufferData
        {
            /* Maintain "snapshots" of object instances until all references are destroyed.
             *
             * This is important because, even though an app requests object deletion, a VK object
             * might still be referenced by command buffers, buffer views, etc.
             */
            std::map<OpenGL::TimeMarker, BufferPropsUniquePtr> buffer_map;

            OpenGL::TimeMarker tot_buffer_time_marker;
            bool               has_been_destroyed;

            BufferData()
            {
                has_been_destroyed = false;
            }
        } BufferData;
        typedef std::unique_ptr<BufferData> BufferDataUniquePtr;

        typedef std::pair<GLuint, OpenGL::TimeMarker> BufferMapKey;

        /* Private functions */
        VKBufferManager(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                        IBackend*                             in_backend_ptr);

        bool                   can_buffer_handle_frontend_reqs(const Anvil::Buffer*        in_buffer_ptr,
                                                               const uint32_t&             in_n_buffer_targets,
                                                               const OpenGL::BufferTarget* in_buffer_targets_ptr,
                                                               const size_t&               in_size) const;
        Anvil::BufferUniquePtr create_vk_buffer               (const OpenGL::BufferState*  in_frontend_buffer_state_ptr) const;

        uint32_t get_n_references      (const BufferData*          in_buffer_data_ptr) const;
        void     on_reference_created  (BufferData*                in_buffer_data_ptr,
                                        OpenGL::VKBufferReference* in_reference_ptr);
        void     on_reference_destroyed(BufferData*                in_buffer_data_ptr,
                                        OpenGL::VKBufferReference* in_reference_ptr);

        /* Private variables */
        std::map<BufferMapKey, BufferDataUniquePtr> m_buffers;
        mutable std::mutex                          m_mutex;

        OpenGL::IBackend* const                     m_backend_ptr;
        const OpenGL::IContextObjectManagers* const m_frontend_ptr;
    };
};

#endif /* VKGL_VK_BUFFER_MANAGER_H */