/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_DRAW_NODE_H
#define VKGL_VK_DRAW_NODE_H

#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_frame_graph_node.h"

namespace OpenGL
{
    namespace VKNodes
    {
        class Draw : public OpenGL::IVKFrameGraphNode
        {
        public:
            /* Public functions */
            static VKFrameGraphNodeUniquePtr create_arrays(const IContextObjectManagers*                    in_frontend_ptr,
                                                           IBackend*                                        in_backend_ptr,
                                                           OpenGL::GLContextStateReferenceUniquePtr         in_frontend_context_state_reference_ptr,
                                                           OpenGL::GLContextStateBindingReferencesUniquePtr in_frontend_context_state_binding_references_ptr,
                                                           const GLint&                                     in_first,
                                                           const GLsizei&                                   in_count,
                                                           const OpenGL::DrawCallMode&                      in_mode);

            ~Draw();

        private:
            /* IVKFrameGraphNode */
            void do_cpu_prepass(IVKFrameGraphNodeCallback*);

            void execute_cpu_side(IVKFrameGraphNodeCallback*) final
            {
                /* Should never be called */
                vkgl_assert_fail();
            }

            void get_gl_context_state(const OpenGL::ContextState**                    out_context_state_ptr_ptr,
                                      const OpenGL::GLContextStateBindingReferences** out_context_state_binding_references_ptr_ptr) const final
            {
                vkgl_assert(m_frontend_context_state_binding_references_ptr != nullptr);
                vkgl_assert(m_frontend_context_state_ptr                    != nullptr);

                *out_context_state_binding_references_ptr_ptr = m_frontend_context_state_binding_references_ptr.get();
                *out_context_state_ptr_ptr                    = m_frontend_context_state_ptr;
            }

            const VKFrameGraphNodeInfo* get_info_ptr() const final
            {
                return m_info_ptr.get();
            }

            RenderpassSupportScope get_renderpass_support_scope() const final
            {
                /* Yup, no draw calls outside of renderpasses. */
                return RenderpassSupportScope::Required;
            }

            void get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                              const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const final
            {
                static const Anvil::QueueFamilyFlagBits supported_queue_fam = Anvil::QueueFamilyFlagBits::GRAPHICS_BIT;

                *out_n_queue_fams_ptr   = 1;
                *out_queue_fams_ptr_ptr = &supported_queue_fam;
            }

            FrameGraphNodeType get_type() const final
            {
                return FrameGraphNodeType::Draw;
            }

            void record_commands(Anvil::CommandBufferBase*  in_cmd_buffer_ptr,
                                 const bool&                in_inside_renderpass,
                                 IVKFrameGraphNodeCallback* in_graph_callback_ptr) const final;

            bool requires_cpu_side_execution() const final
            {
                /* None needed */
                return false;
            }

            bool requires_cpu_prepass() const final
            {
                /* Need to schedule various work chunks to the thread pool. */
                return true;
            }

            bool requires_gpu_side_execution() const final
            {
                return true;
            }

            bool requires_manual_wait_sem_sync() const final
            {
                return false;
            }

            bool supports_primary_command_buffers() const final
            {
                return true;
            }

            bool supports_secondary_command_buffers() const final
            {
                return true;
            }

            /* Private functions */

            Draw(const IContextObjectManagers*                    in_frontend_ptr,
                 OpenGL::IBackend*                                in_backend_ptr,
                 OpenGL::GLContextStateReferenceUniquePtr         in_frontend_context_state_reference_ptr,
                 OpenGL::GLContextStateBindingReferencesUniquePtr in_frontend_context_state_binding_references_ptr);

            /* Private variables */
            IBackend*                                        m_backend_ptr;
            const IContextObjectManagers*                    m_frontend_ptr;
            OpenGL::GLContextStateBindingReferencesUniquePtr m_frontend_context_state_binding_references_ptr;
            const OpenGL::ContextState*                      m_frontend_context_state_ptr;
            OpenGL::GLContextStateReferenceUniquePtr         m_frontend_context_state_reference_ptr;
            VKFrameGraphNodeInfoUniquePtr                    m_info_ptr;

            std::vector<OpenGL::VKBufferReferenceUniquePtr> m_owned_buffer_reference_ptrs;

            struct Args
            {
                GLsizei              count;
                GLint                first;
                OpenGL::DrawCallMode mode;

                Args()
                    :count(0),
                     first(0),
                     mode(OpenGL::DrawCallMode::Unknown)
                {
                    /* Stub */
                }
            } m_args;
        };
    };
};

#endif /* VKGL_VK_DRAW_NODE_H */
