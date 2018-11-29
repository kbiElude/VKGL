/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/backend/vk_buffer_manager.h"
#include "OpenGL/backend/vk_reference.h"
#include "OpenGL/backend/vk_utils.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "Anvil/include/misc/buffer_create_info.h"
#include "Anvil/include/wrappers/buffer.h"

OpenGL::VKBufferManager::VKBufferManager(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                                         IBackend*                             in_backend_ptr)
    :m_backend_ptr (in_backend_ptr),
     m_frontend_ptr(in_frontend_ptr)
{
    vkgl_assert(m_backend_ptr  != nullptr);
    vkgl_assert(m_frontend_ptr != nullptr);
}

OpenGL::VKBufferManager::~VKBufferManager()
{
    /*  Stub */
}

OpenGL::VKBufferReferenceUniquePtr OpenGL::VKBufferManager::acquire_object(const GLuint&      in_id,
                                                                           OpenGL::TimeMarker in_frontend_object_creation_time,
                                                                           OpenGL::TimeMarker in_buffer_time_marker)
{
    std::lock_guard<std::mutex>        lock                 (m_mutex);
    BufferData*                        buffer_data_ptr      (nullptr);
    const auto                         buffer_map_key       (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                               buffer_props_iterator(m_buffers.find(buffer_map_key) );
    OpenGL::VKBufferReferenceUniquePtr new_reference_ptr    (nullptr,
                                                             [](OpenGL::VKBufferReference* in_ref_ptr){ delete in_ref_ptr; });
    Anvil::Buffer*                     ref_buffer_ptr       (nullptr);

    vkgl_assert(buffer_props_iterator != m_buffers.end() );

    buffer_data_ptr = buffer_props_iterator->second.get();

    {
        auto buffer_iterator = buffer_data_ptr->buffer_map.find(in_buffer_time_marker);

        if (buffer_iterator != buffer_data_ptr->buffer_map.end() )
        {
            ref_buffer_ptr = buffer_iterator->second->buffer_ptr.get();
            vkgl_assert(ref_buffer_ptr != nullptr);
        }
        else
        {
            auto                       frontend_buffer_manager_ptr = m_frontend_ptr->get_buffer_manager_ptr();
            const OpenGL::BufferState* frontend_buffer_state_ptr   = nullptr;

            frontend_buffer_manager_ptr->get_buffer_state_ptr(in_id,
                                                             &in_buffer_time_marker,
                                                             &frontend_buffer_state_ptr);
            vkgl_assert(frontend_buffer_state_ptr != nullptr);

            auto new_buffer_ptr = create_vk_buffer(frontend_buffer_state_ptr);
            vkgl_assert(new_buffer_ptr != nullptr);

            ref_buffer_ptr = new_buffer_ptr.get();

            buffer_data_ptr->buffer_map[in_buffer_time_marker].reset(
                new BufferProps(std::move(new_buffer_ptr) )
            );
            vkgl_assert(buffer_data_ptr->buffer_map[in_buffer_time_marker] != nullptr);

            buffer_data_ptr->tot_buffer_time_marker = in_buffer_time_marker;
        }
    }

    new_reference_ptr.reset(
        new OpenGL::VKBufferReference(OpenGL::VKBufferPayload(in_id,
                                                              in_frontend_object_creation_time,
                                                              ref_buffer_ptr,
                                                              in_buffer_time_marker),
                                      std::bind(&OpenGL::VKBufferManager::on_reference_created,
                                                this,
                                                buffer_data_ptr,
                                                std::placeholders::_1),
                                      std::bind(&OpenGL::VKBufferManager::on_reference_destroyed,
                                                this,
                                                buffer_data_ptr,
                                                std::placeholders::_1),
                                      std::bind(&OpenGL::VKBufferManager::acquire_object,
                                                this,
                                                in_id,
                                                in_frontend_object_creation_time,
                                                in_buffer_time_marker) )
    );
    vkgl_assert(new_reference_ptr != nullptr);

    return new_reference_ptr;
}

bool OpenGL::VKBufferManager::can_buffer_handle_frontend_reqs(const Anvil::Buffer*        in_buffer_ptr,
                                                              const uint32_t&             in_n_buffer_targets,
                                                              const OpenGL::BufferTarget* in_buffer_targets_ptr,
                                                              const size_t&               in_size) const
{
    const auto buffer_create_info_ptr = in_buffer_ptr->get_create_info_ptr                   ();
    const auto required_usage_flags   = OpenGL::VKUtils::get_buffer_usage_flags_for_gl_buffer(in_n_buffer_targets,
                                                                                              in_buffer_targets_ptr);
    bool       result                 = true;

    if ((buffer_create_info_ptr->get_usage_flags() & required_usage_flags) != required_usage_flags)
    {
        /* Specified buffer's usage flags are a subset of what's required. */
        result = false;

        goto end;
    }

    if (buffer_create_info_ptr->get_size() < in_size)
    {
        /* Too little space available .. */
        result = false;

        goto end;
    }

end:
    return result;
}

OpenGL::VKBufferManagerUniquePtr OpenGL::VKBufferManager::create(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                                                                 OpenGL::IBackend*                     in_backend_ptr)
{
    OpenGL::VKBufferManagerUniquePtr result_ptr;

    result_ptr.reset(
        new VKBufferManager(in_frontend_ptr,
                            in_backend_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

bool OpenGL::VKBufferManager::create_object(const GLuint&             in_id,
                                            const OpenGL::TimeMarker& in_frontend_object_creation_time)
{
    /* NOTE: This function is only called from within the rendering context thread */
    BufferDataUniquePtr         buffer_data_ptr(nullptr);
    const auto                  buffer_map_key (BufferMapKey(in_id, in_frontend_object_creation_time) );
    std::lock_guard<std::mutex> lock           (m_mutex);
    bool                        result         (false);

    vkgl_assert(m_buffers.find(buffer_map_key) == m_buffers.end() );

    /* Only instantiate the structure for now. We're going to create the buffer instance, as well as the corresponding
     * memory instance, later on when the application actually specifies storage details.
     */
    buffer_data_ptr.reset(
        new BufferData()
    );

    if (buffer_data_ptr == nullptr)
    {
        goto end;
    }

    m_buffers[buffer_map_key] = std::move(buffer_data_ptr);
    result                    = true;
end:
    return result;
}

Anvil::BufferUniquePtr OpenGL::VKBufferManager::create_vk_buffer(const OpenGL::BufferState* in_frontend_buffer_state_ptr) const
{
    Anvil::BufferCreateInfoUniquePtr create_info_ptr;
    auto                             device_ptr            = m_backend_ptr->get_device_ptr();
    const uint32_t                   n_buffer_targets_used = static_cast<uint32_t>(in_frontend_buffer_state_ptr->buffer_targets_used.size() );
    Anvil::BufferUniquePtr           result_ptr;
    const Anvil::BufferUsageFlags    usage_flags           = OpenGL::VKUtils::get_buffer_usage_flags_for_gl_buffer(n_buffer_targets_used,
                                                                                                             (n_buffer_targets_used > 0) ? &in_frontend_buffer_state_ptr->buffer_targets_used.at(0) : nullptr);

    vkgl_assert(in_frontend_buffer_state_ptr->buffer_targets_used.size() > 0);

    create_info_ptr = Anvil::BufferCreateInfo::create_no_alloc(device_ptr,
                                                               in_frontend_buffer_state_ptr->size,
                                                               Anvil::QueueFamilyFlagBits::COMPUTE_BIT | Anvil::QueueFamilyFlagBits::DMA_BIT | Anvil::QueueFamilyFlagBits::GRAPHICS_BIT,
                                                               Anvil::SharingMode::EXCLUSIVE,
                                                               Anvil::BufferCreateFlagBits::NONE,
                                                               usage_flags);
    vkgl_assert(create_info_ptr != nullptr);

    result_ptr = Anvil::Buffer::create(std::move(create_info_ptr) );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

bool OpenGL::VKBufferManager::destroy_object(const GLuint&             in_id,
                                             const OpenGL::TimeMarker& in_frontend_object_creation_time)
{
    /* NOTE: This function is only called from within the rendering context thread */
    std::lock_guard<std::mutex> lock           (m_mutex);
    const auto                  buffer_map_key (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                        buffer_iterator(m_buffers.find(buffer_map_key) );
    bool                        result         (false);

    vkgl_assert(buffer_iterator != m_buffers.end() );
    if (buffer_iterator != m_buffers.end() )
    {
        /* Mark the buffer instance as destroyed. */
        auto buffer_data_ptr = buffer_iterator->second.get();

        vkgl_assert(!buffer_data_ptr->has_been_destroyed);
        buffer_data_ptr->has_been_destroyed = true;

        /* Check if no further references for the instance exist. If none do, go ahead and free the descriptor. */
        if (get_n_references(buffer_data_ptr) == 0)
        {
            m_buffers.erase(buffer_iterator);

            /* NOTE: buffer_data_ptr at this point is dead. */
        }
        else
        {
            /* Wait till the reference counter drops to 0. */
        }

        result = true;
    }

    return result;
}

uint32_t OpenGL::VKBufferManager::get_n_references(const BufferData* in_buffer_data_ptr) const
{
    /* NOTE: This function assumes m_mutex is locked! */
    uint32_t result = 0;

    for (const auto& current_buffer_props : in_buffer_data_ptr->buffer_map)
    {
        result += static_cast<uint32_t>(current_buffer_props.second->reference_ptrs.size() );
    }

    return result;
}

OpenGL::TimeMarker OpenGL::VKBufferManager::get_tot_buffer_time_marker(const GLuint&             in_id,
                                                                       const OpenGL::TimeMarker& in_frontend_object_creation_time) const
{
    std::lock_guard<std::mutex> lock                 (m_mutex);
    const auto                  buffer_map_key       (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                        buffer_props_iterator(m_buffers.find(buffer_map_key) );

    vkgl_assert(buffer_props_iterator != m_buffers.end() );

    return buffer_props_iterator->second->tot_buffer_time_marker;
}

void OpenGL::VKBufferManager::on_reference_created(BufferData*                in_buffer_data_ptr,
                                                   OpenGL::VKBufferReference* in_reference_ptr)
{
    /* NOTE: m_mutex is assumed to be locked when this func is called */
    auto buffer_iterator = in_buffer_data_ptr->buffer_map.find(in_reference_ptr->get_payload().backend_buffer_creation_time_marker);

    if (buffer_iterator != in_buffer_data_ptr->buffer_map.end() )
    {
        buffer_iterator->second->reference_ptrs.push_back(in_reference_ptr);
    }
}

void OpenGL::VKBufferManager::on_reference_destroyed(BufferData*                in_buffer_data_ptr,
                                                     OpenGL::VKBufferReference* in_reference_ptr)
{
    std::lock_guard<std::mutex> lock           (m_mutex);
    auto                        buffer_iterator(in_buffer_data_ptr->buffer_map.find(in_reference_ptr->get_payload().backend_buffer_creation_time_marker) );

    if (buffer_iterator != in_buffer_data_ptr->buffer_map.end() )
    {
        auto ref_iterator = std::find(buffer_iterator->second->reference_ptrs.begin(),
                                      buffer_iterator->second->reference_ptrs.end(),
                                      in_reference_ptr);

        if (ref_iterator != buffer_iterator->second->reference_ptrs.end() )
        {
            buffer_iterator->second->reference_ptrs.erase(ref_iterator);
        }
    }

    if (get_n_references(in_buffer_data_ptr)   == 0 &&
        in_buffer_data_ptr->has_been_destroyed)
    {
        /* This buffer can be safely released. */
        const auto key             = BufferMapKey  (in_reference_ptr->get_payload().id,
                                                    in_reference_ptr->get_payload().frontend_object_creation_time_marker);
        auto       object_iterator = m_buffers.find(key);

        vkgl_assert(object_iterator != m_buffers.end() );
        if (object_iterator != m_buffers.end() )
        {
            m_buffers.erase(object_iterator);
        }

        /* NOTE: in_buffer_data_ptr is dead at this point. */
    }
}

