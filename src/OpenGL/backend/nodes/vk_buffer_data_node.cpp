/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/backend/nodes/vk_buffer_data_node.h"
#include "OpenGL/frontend/gl_buffer_manager.h"


OpenGL::VKNodes::BufferData::BufferData(VKFrameGraphNodeCreateInfoUniquePtr in_create_info_ptr,
                                        const IContextObjectManagers*       in_frontend_ptr,
                                        IVKBufferManager*                   in_backend_buffer_manager_ptr)
    :m_backend_buffer_manager_ptr(in_backend_buffer_manager_ptr),
     m_create_info_ptr           (std::move(in_create_info_ptr) ),
     m_frontend_ptr              (in_frontend_ptr)
{
    vkgl_assert(m_create_info_ptr                    != nullptr);
    vkgl_assert(m_create_info_ptr->command_ptr       != nullptr);
    vkgl_assert(m_create_info_ptr->command_ptr->type == OpenGL::CommandType::BUFFER_DATA);
    vkgl_assert(m_frontend_ptr                       != nullptr);
}

OpenGL::VKNodes::BufferData::~BufferData()
{
     /* Stub */
}

OpenGL::VKFrameGraphNodeUniquePtr OpenGL::VKNodes::BufferData::create(VKFrameGraphNodeCreateInfoUniquePtr in_create_info_ptr,
                                                                      const IContextObjectManagers*       in_frontend_ptr,
                                                                      IVKBufferManager*                   in_backend_buffer_manager_ptr)
{
    OpenGL::VKFrameGraphNodeUniquePtr result_ptr(nullptr,
                                                 std::default_delete<OpenGL::IVKFrameGraphNode>() );

    result_ptr.reset(
        new OpenGL::VKNodes::BufferData(std::move(in_create_info_ptr),
                                        in_frontend_ptr,
                                        in_backend_buffer_manager_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::VKNodes::BufferData::do_cpu_prepass()
{
    /* NOTE: "Buffer data" command drops existing memory storage. For perf reasons, we can skip this step IF
     *
     *       1) the new storage size and usage property matches the former one's.
     *       2) the buffer has already been created, and has been bound actual storage.
     *
     *       If both hold, we can proceed directly with a data copy, granted new data has been provided. Otherwise, we're also going
     *       to need to make sure both buffer and mem block objects have been created.
     */
    auto                        backend_buffer_ptr                      = m_create_info_ptr->inputs.at(0).buffer_reference_ptr->get_payload().buffer_ptr;
    auto                        backend_mem_block_ptr                   = m_create_info_ptr->inputs.at(0).buffer_reference_ptr->get_payload().memory_block_ptr;
    auto                        command_ptr                             = dynamic_cast<const OpenGL::BufferDataCommand*>(m_create_info_ptr->command_ptr.get() );
    const auto&                 frontend_buffer_creation_time           = command_ptr->buffer_reference_ptr->get_payload().object_creation_time;
    const auto&                 frontend_buffer_id                      = command_ptr->buffer_reference_ptr->get_payload().id;
    uint32_t                    frontend_buffer_n_used_buffer_targets   = 0;
    size_t                      frontend_buffer_size                    = 0;
    OpenGL::BufferUsage         frontend_buffer_usage                   = OpenGL::BufferUsage::Unknown;
    const OpenGL::BufferTarget* frontend_buffer_used_buffer_targets_ptr = nullptr;

    vkgl_assert(*m_create_info_ptr->inputs.at(0).buffer_reference_ptr == *m_create_info_ptr->outputs.at(0).buffer_reference_ptr);

    /* 1. Retrieve frontend buffer's properties */
    {
        auto gl_buffer_manager_ptr = m_frontend_ptr->get_buffer_manager_ptr();

        frontend_buffer_size  = gl_buffer_manager_ptr->get_buffer_size (frontend_buffer_id,
                                                                       &frontend_buffer_creation_time);
        frontend_buffer_usage = gl_buffer_manager_ptr->get_buffer_usage(frontend_buffer_id,
                                                                       &frontend_buffer_creation_time);

        gl_buffer_manager_ptr->get_buffer_used_buffer_targets(frontend_buffer_id,
                                                             &frontend_buffer_creation_time,
                                                             &frontend_buffer_n_used_buffer_targets,
                                                             &frontend_buffer_used_buffer_targets_ptr);
    }

    /* 2. Do we need a new VK buffer instance? */
    {
        bool need_new_backend_buffer = true;

        if (backend_buffer_ptr != nullptr)
        {
            vkgl_not_implemented(); // todo
        }

        if (need_new_backend_buffer)
        {
            vkgl_not_implemented(); // todo
        }
    }

    /* 3. Do we need a new VK mem block instance? */
    {
        bool need_new_backend_mem_block = true;

        if (backend_mem_block_ptr != nullptr)
        {
            vkgl_not_implemented(); // todo 
        }

        if (need_new_backend_mem_block)
        {
            vkgl_not_implemented(); // todo
        }
    }

    /* 4. Create a staging buffer, bind memory to it, move the user-specified data there.
     *
     * TODO: Backend should host a pool of staging buffers to reuse. We should not be re-creating these buffers here
     *       all the time.
     */
}

bool OpenGL::VKNodes::BufferData::get_input_access_properties(const uint32_t&            in_n_input,
                                                              Anvil::PipelineStageFlags* out_pipeline_stages_ptr,
                                                              Anvil::AccessFlags*        out_access_flags_ptr) const
{
    /* Protect against {R, W}aWs. */
    *out_access_flags_ptr    = Anvil::AccessFlagBits::TRANSFER_WRITE_BIT;
    *out_pipeline_stages_ptr = Anvil::PipelineStageFlagBits::TRANSFER_BIT;

    vkgl_assert(in_n_input == 0);
    return (in_n_input == 0);
}

bool OpenGL::VKNodes::BufferData::get_output_access_properties(const uint32_t&            in_n_output,
                                                               Anvil::PipelineStageFlags* out_pipeline_stages_ptr,
                                                               Anvil::AccessFlags*        out_access_flags_ptr) const
{
    /* Protect against {R, W}aWs. */
    *out_access_flags_ptr    = Anvil::AccessFlagBits::TRANSFER_WRITE_BIT;
    *out_pipeline_stages_ptr = Anvil::PipelineStageFlagBits::TRANSFER_BIT;

    vkgl_assert(in_n_output == 0);
    return (in_n_output == 0);
}

void OpenGL::VKNodes::BufferData::get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                                               const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const
{
    static const Anvil::QueueFamilyFlagBits compatible_queue_fams[] =
    {
        Anvil::QueueFamilyFlagBits::DMA_BIT,
        Anvil::QueueFamilyFlagBits::COMPUTE_BIT,
        Anvil::QueueFamilyFlagBits::GRAPHICS_BIT,
    };

    *out_n_queue_fams_ptr   = sizeof(compatible_queue_fams) / sizeof(compatible_queue_fams[0]);
    *out_queue_fams_ptr_ptr = compatible_queue_fams;
}

bool OpenGL::VKNodes::BufferData::record_commands(Anvil::CommandBufferBase* in_cmd_buffer_ptr,
                                                  const bool&               in_inside_renderpass) const
{
    vkgl_not_implemented();

    return false;
}
