/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/backend/vk_buffer_manager.h"
#include "OpenGL/backend/vk_reference.h"

/* TODO: This is an experimental version. OpenGL::Reference needs to be reworked to hold arbitrary info.
 *       In this case, we need to be able to hold time markers separately for the buffer and the memory block
 *       instances. With existing Reference, this is not possible.
 */


OpenGL::VKBufferManagerUniquePtr OpenGL::VKBufferManager::create()
{
    OpenGL::VKBufferManagerUniquePtr result_ptr;

    result_ptr.reset(
        new VKBufferManager()
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

OpenGL::VKBufferManager::~VKBufferManager()
{
    /*  Stub */
}

OpenGL::VKBufferReferenceUniquePtr OpenGL::VKBufferManager::acquire_object(const GLuint&      in_id,
                                                                           OpenGL::TimeMarker in_frontend_object_creation_time,
                                                                           OpenGL::TimeMarker in_buffer_time_marker,
                                                                           OpenGL::TimeMarker in_mem_block_time_marker)
{
    /* TODO: Rework the interface so that returned objects are instead stored inside the reference object..*/
    std::lock_guard<std::mutex>        lock                 (m_mutex);
    BufferData*                        buffer_data_ptr      (nullptr);
    const auto                         buffer_map_key       (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                               buffer_props_iterator(m_buffers.find(buffer_map_key) );
    OpenGL::VKBufferReferenceUniquePtr new_reference_ptr    (nullptr,
                                                             [](OpenGL::VKBufferReference* in_ref_ptr){ delete in_ref_ptr; });
    Anvil::Buffer*                     ref_buffer_ptr       (nullptr);
    Anvil::MemoryBlock*                ref_mem_block_ptr    (nullptr);

    vkgl_assert(buffer_props_iterator != m_buffers.end() );

    {
        auto buffer_iterator    = buffer_data_ptr->buffer_map.find      (in_buffer_time_marker);
        auto mem_block_iterator = buffer_data_ptr->memory_block_map.find(in_mem_block_time_marker);

        if (buffer_iterator != buffer_data_ptr->buffer_map.end() )
        {
            ref_buffer_ptr = nullptr;
        }

        if (mem_block_iterator != buffer_data_ptr->memory_block_map.end() )
        {
            ref_mem_block_ptr = mem_block_iterator->second->memory_block_ptr.get();
        }
    }

    buffer_data_ptr = buffer_props_iterator->second.get();

    new_reference_ptr.reset(
        new OpenGL::VKBufferReference(OpenGL::VKBufferPayload(in_id,
                                                              in_frontend_object_creation_time,
                                                              ref_buffer_ptr,
                                                              in_buffer_time_marker,
                                                              ref_mem_block_ptr,
                                                              in_mem_block_time_marker),
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
                                                in_buffer_time_marker,
                                                in_mem_block_time_marker) )
    );
    vkgl_assert(new_reference_ptr != nullptr);

    return new_reference_ptr;
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

    for (const auto& current_mem_block_props : in_buffer_data_ptr->memory_block_map)
    {
        result += static_cast<uint32_t>(current_mem_block_props.second->reference_ptrs.size() );
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

OpenGL::TimeMarker OpenGL::VKBufferManager::get_tot_memory_block_time_marker(const GLuint&             in_id,
                                                                             const OpenGL::TimeMarker& in_frontend_object_creation_time) const
{
    std::lock_guard<std::mutex> lock                 (m_mutex);
    const auto                  buffer_map_key       (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                        buffer_props_iterator(m_buffers.find(buffer_map_key) );

    vkgl_assert(buffer_props_iterator != m_buffers.end() );

    return buffer_props_iterator->second->tot_memory_block_time_marker;
}

void OpenGL::VKBufferManager::on_reference_created(BufferData*                in_buffer_data_ptr,
                                                   OpenGL::VKBufferReference* in_reference_ptr)
{
    /* NOTE: m_mutex is assumed to be locked when this func is called */
    auto buffer_iterator    = in_buffer_data_ptr->buffer_map.find      (in_reference_ptr->get_payload().backend_buffer_creation_time_marker);
    auto mem_block_iterator = in_buffer_data_ptr->memory_block_map.find(in_reference_ptr->get_payload().backend_mem_block_creation_time_marker);

    if (buffer_iterator != in_buffer_data_ptr->buffer_map.end() )
    {
        buffer_iterator->second->reference_ptrs.push_back(in_reference_ptr);
    }

    if (mem_block_iterator != in_buffer_data_ptr->memory_block_map.end() )
    {
        mem_block_iterator->second->reference_ptrs.push_back(in_reference_ptr);
    }
}

void OpenGL::VKBufferManager::on_reference_destroyed(BufferData*                in_buffer_data_ptr,
                                                     OpenGL::VKBufferReference* in_reference_ptr)
{
    std::lock_guard<std::mutex> lock              (m_mutex);
    auto                        buffer_iterator   (in_buffer_data_ptr->buffer_map.find      (in_reference_ptr->get_payload().backend_buffer_creation_time_marker) );
    auto                        mem_block_iterator(in_buffer_data_ptr->memory_block_map.find(in_reference_ptr->get_payload().backend_mem_block_creation_time_marker) );

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

    if (mem_block_iterator != in_buffer_data_ptr->memory_block_map.end() )
    {
        auto ref_iterator = std::find(mem_block_iterator->second->reference_ptrs.begin(),
                                      mem_block_iterator->second->reference_ptrs.end(),
                                      in_reference_ptr);

        if (ref_iterator != mem_block_iterator->second->reference_ptrs.end() )
        {
            mem_block_iterator->second->reference_ptrs.erase(ref_iterator);
        }
    }

    if (get_n_references(in_buffer_data_ptr) == 0)
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

OpenGL::TimeMarker OpenGL::VKBufferManager::set_tot_buffer_object(const GLuint&             in_id,
                                                                  const OpenGL::TimeMarker& in_frontend_object_creation_time,
                                                                  Anvil::BufferUniquePtr    in_buffer_ptr)
{
    std::lock_guard<std::mutex> lock                (m_mutex);
    const auto                  buffer_map_key      (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                        buffer_data_iterator(m_buffers.find(buffer_map_key) );
    OpenGL::TimeMarker          result              (std::chrono::high_resolution_clock::now() );

    vkgl_assert(buffer_data_iterator != m_buffers.end() );
    vkgl_assert(buffer_data_iterator->second->buffer_map.find(result) == buffer_data_iterator->second->buffer_map.end() );

    {
        BufferPropsUniquePtr new_props_ptr(new BufferProps(std::move(in_buffer_ptr) ));

        vkgl_assert(new_props_ptr != nullptr);

        buffer_data_iterator->second->buffer_map[result] = std::move(new_props_ptr);
    }

    buffer_data_iterator->second->tot_buffer_time_marker = result;

    return result;
}

OpenGL::TimeMarker OpenGL::VKBufferManager::set_tot_memory_block_object(const GLuint&               in_id,
                                                                        const OpenGL::TimeMarker&   in_frontend_object_creation_time,
                                                                        Anvil::MemoryBlockUniquePtr in_memory_block_ptr)
{
    std::lock_guard<std::mutex> lock                (m_mutex);
    const auto                  buffer_map_key      (BufferMapKey(in_id, in_frontend_object_creation_time) );
    auto                        buffer_data_iterator(m_buffers.find(buffer_map_key) );
    OpenGL::TimeMarker          result              (std::chrono::high_resolution_clock::now() );

    vkgl_assert(buffer_data_iterator != m_buffers.end() );
    vkgl_assert(buffer_data_iterator->second->memory_block_map.find(result) == buffer_data_iterator->second->memory_block_map.end() );

    {
        MemoryBlockPropsUniquePtr new_props_ptr(new MemoryBlockProps(std::move(in_memory_block_ptr) ));

        vkgl_assert(new_props_ptr != nullptr);

        buffer_data_iterator->second->memory_block_map[result] = std::move(new_props_ptr);
    }

    buffer_data_iterator->second->tot_buffer_time_marker = result;

    return result;
}