/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_ACQUIRE_SWAPCHAIN_IMAGE_NODE_H
#define VKGL_VK_ACQUIRE_SWAPCHAIN_IMAGE_NODE_H

#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_frame_graph_node.h"

namespace OpenGL
{
    namespace VKNodes
    {
        class AcquireSwapchainImage : public OpenGL::IVKFrameGraphNode
        {
        public:
            /* Public functions */
            static VKFrameGraphNodeUniquePtr create(const IContextObjectManagers* in_frontend_ptr,
                                                    const IBackend*               in_backend_ptr);

            ~AcquireSwapchainImage();

        private:
            /* IVKFrameGraphNode */
            void do_cpu_prepass(IVKFrameGraphNodeCallback*) final;

            void execute_cpu_side(IVKFrameGraphNodeCallback*) final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

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
                return FrameGraphNodeType::Acquire_Swapchain_Image;
            }

            void record_commands(Anvil::CommandBufferBase*  in_cmd_buffer_ptr,
                                 const bool&                in_inside_renderpass,
                                 IVKFrameGraphNodeCallback* in_graph_callback_ptr) const final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            bool requires_cpu_side_execution() const final
            {
                /* None needed - image acquisition is handled in CPU prepass. */
                return false;
            }

            bool requires_cpu_prepass() const final
            {
                /* Image acquisition is a host-side operation. */
                return true;
            }

            bool requires_gpu_side_execution() const final
            {
                /* Nothing to do */
                return false;
            }

            bool requires_manual_wait_sem_sync() const final
            {
                /* Frame acquisition occurs at the beginning of the frame; no manual sync is needed,
                 * granted we maintain a set of required color/d/ds/s images per each swapchain image.
                 */
                return false;
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

            AcquireSwapchainImage(const IContextObjectManagers* in_frontend_ptr,
                                  const OpenGL::IBackend*       in_backend_ptr);

            /* Private variables */
            const IBackend*                       m_backend_ptr;
            const IContextObjectManagers*         m_frontend_ptr;
            OpenGL::VKFrameGraphNodeInfoUniquePtr m_info_ptr;
            OpenGL::VKSwapchainReferenceUniquePtr m_swapchain_reference_ptr;

            Anvil::SemaphoreUniquePtr             m_frame_acquire_sem_ptr;
        };
    };
};

#endif /* VKGL_VK_ACQUIRE_SWAPCHAIN_IMAGE_NODE_H */