/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_PRESENT_SWAPCHAIN_IMAGE_NODE_H
#define VKGL_VK_PRESENT_SWAPCHAIN_IMAGE_NODE_H

#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_frame_graph_node.h"

namespace OpenGL
{
    namespace VKNodes
    {
        class PresentSwapchainImage : public OpenGL::IVKFrameGraphNode
        {
        public:
            /* Public functions */
            static VKFrameGraphNodeUniquePtr create(const IContextObjectManagers*         in_frontend_ptr,
                                                    IBackend*                             in_backend_ptr,
                                                    OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr);

            ~PresentSwapchainImage();

        private:
            /* IVKFrameGraphNode */
            void do_cpu_prepass(IVKFrameGraphNodeCallback*) final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            void execute_cpu_side(IVKFrameGraphNodeCallback*) final;

            void get_gl_context_state(const OpenGL::ContextState**                    out_context_state_ptr_ptr,
                                      const OpenGL::GLContextStateBindingReferences** out_context_state_binding_references_ptr_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            const VKFrameGraphNodeInfo* get_info_ptr() const final
            {
                return m_info_ptr.get();
            }

            RenderpassSupportScope get_renderpass_support_scope() const final
            {
                return RenderpassSupportScope::Not_Supported;
            }

            void get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                              const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            FrameGraphNodeType get_type() const final
            {
                return FrameGraphNodeType::Present_Swapchain_Image;
            }

            void record_commands(Anvil::CommandBufferBase*  in_cmd_buffer_ptr,
                                 const bool&                in_inside_renderpass,
                                 IVKFrameGraphNodeCallback* in_graph_callback_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            bool requires_cpu_prepass() const final
            {
                return false;
            }

            bool requires_cpu_side_execution() const final
            {
                return true;
            }

            bool requires_gpu_side_execution() const final
            {
                /* Nothing to do */
                return false;
            }

            bool requires_manual_wait_sem_sync() const final
            {
                /* For presentation purposes, we must manually provide the list of semaphores presentation engine must wait upon
                 * before proceeding.
                 */
                return true;
            }

            bool supports_primary_command_buffers() const final
            {
                /* Should never be called. */
                vkgl_assert_fail();

                return false;
            }

            bool supports_secondary_command_buffers() const final
            {
                /* Should never be called. */
                vkgl_assert_fail();

                return false;
            }

            /* Private functions */

            PresentSwapchainImage(const IContextObjectManagers*         in_frontend_ptr,
                                  OpenGL::IBackend*                     in_backend_ptr,
                                  OpenGL::VKSwapchainReferenceUniquePtr in_swapchain_reference_ptr);

            /* Private variables */
            IBackend*                             m_backend_ptr;
            const IContextObjectManagers*         m_frontend_ptr;
            OpenGL::VKFrameGraphNodeInfoUniquePtr m_info_ptr;
            OpenGL::VKSwapchainReferenceUniquePtr m_swapchain_reference_ptr;
        };
    };
};

#endif /* VKGL_VK_PRESENT_SWAPCHAIN_IMAGE_NODE_H */