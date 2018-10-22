/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_BUFFER_DATA_NODE_H
#define VKGL_VK_BUFFER_DATA_NODE_H

#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_frame_graph_node.h"

namespace OpenGL
{
    namespace VKNodes
    {
        class BufferData : public OpenGL::IVKFrameGraphNode
        {
        public:
            /* Public functions */
            static VKFrameGraphNodeUniquePtr create(const IContextObjectManagers*      in_frontend_ptr,
                                                    IBackend*                          in_backend_ptr,
                                                    OpenGL::VKBufferReferenceUniquePtr in_backend_buffer_reference_ptr,
                                                    OpenGL::GLBufferReferenceUniquePtr in_frontend_buffer_reference_ptr,
                                                    OpenGL::DataUniquePtr              in_opt_data_ptr);

            ~BufferData();

        private:
            /* IVKFrameGraphNode */
            void do_cpu_prepass(IVKFrameGraphNodeCallback*);

            void execute_cpu_side(IVKFrameGraphNodeCallback*) final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            const VKFrameGraphNodeInfo* get_info_ptr() const final
            {
                return m_info_ptr.get();
            }

            bool get_input_access_properties (const uint32_t&                    in_n_input,
                                              Anvil::PipelineStageFlags*         out_pipeline_stages_ptr,
                                              Anvil::AccessFlags*                out_access_flags_ptr) const final;
            bool get_output_access_properties(const uint32_t&                    in_n_output,
                                              Anvil::PipelineStageFlags*         out_pipeline_stages_ptr,
                                              Anvil::AccessFlags*                out_access_flags_ptr) const final;
            void get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                              const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const final;

            void on_commands_finished_executing_gpu_side() final;

            void record_commands(Anvil::CommandBufferBase* in_cmd_buffer_ptr,
                                 const bool&               in_inside_renderpass) const final;

            bool requires_cpu_side_execution() const final
            {
                /* None needed */
                return false;
            }

            bool requires_cpu_prepass() const final
            {
                /* We might need to do mem block allocation + binding, before we can actually record the commands. */
                return true;
            }

            bool requires_gpu_side_execution() const final;

            bool requires_manual_wait_sem_sync() const final
            {
                return false;
            }

            bool supports_primary_command_buffers() const final
            {
                return true;
            }

            bool supports_renderpasses() const final;

            bool supports_secondary_command_buffers() const final
            {
                return true;
            }

            /* Private functions */

            BufferData(const IContextObjectManagers*      in_frontend_ptr,
                       OpenGL::IBackend*                  in_backend_ptr,
                       OpenGL::VKBufferReferenceUniquePtr in_backend_buffer_reference_ptr,
                       OpenGL::GLBufferReferenceUniquePtr in_frontend_buffer_reference_ptr,
                       OpenGL::DataUniquePtr              in_opt_data_ptr);

            bool can_buffer_handle_frontend_reqs      (const Anvil::Buffer*        in_buffer_ptr,
                                                       const uint32_t&             in_n_buffer_targets,
                                                       const OpenGL::BufferTarget* in_buffer_targets_ptr,
                                                       const size_t&               in_size) const;
            bool can_memory_block_handle_frontend_reqs(const Anvil::MemoryBlock*   in_mem_block_ptr,
                                                       const size_t&               in_size,
                                                       const OpenGL::BufferUsage&  in_buffer_usage) const;

            Anvil::BufferCreateInfoUniquePtr get_buffer_create_info_for_gl_buffer (const uint32_t&             in_n_buffer_targets,
                                                                                   const OpenGL::BufferTarget* in_buffer_targets_ptr,
                                                                                   const size_t&               in_size) const;

            /* Private variables */
            IBackend*                          m_backend_ptr;
            OpenGL::VKBufferReferenceUniquePtr m_backend_buffer_reference_ptr;
            OpenGL::GLBufferReferenceUniquePtr m_frontend_buffer_reference_ptr;
            VKFrameGraphNodeInfoUniquePtr      m_info_ptr;
            OpenGL::DataUniquePtr              m_data_ptr;
            const IContextObjectManagers*      m_frontend_ptr;
            Anvil::BufferUniquePtr             m_staging_buffer_ptr;
        };
    };
};

#endif /* VKGL_VK_BUFFER_DATA_NODE_H */