/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_FRAME_GRAPH_H
#define VKGL_VK_FRAME_GRAPH_H

#include "Anvil/include/misc/types.h"
#include "OpenGL/backend/vk_commands.h"
#include "OpenGL/backend/vk_frame_graph_node.h"
#include "OpenGL/types.h"
#include <map>

namespace OpenGL
{
    class VKFrameGraph : public IVKFrameGraphNodeCallback
    {
    public:
        /* Public functions */
        static VKFrameGraphUniquePtr create(const OpenGL::IBackend* in_backend_ptr);

        ~VKFrameGraph();

        void add_node(OpenGL::VKFrameGraphNodeUniquePtr in_node_ptr);
        void clear   ();
        void execute ();

    private:
        /* Private type definitions */

        /* IVKFrameGraphNodeCallback functions */
        uint32_t          get_acquired_swapchain_image_index()                             const final;
        Anvil::Semaphore* get_swapchain_image_acquired_sem  ()                             const final;
        void              set_acquired_swapchain_image_index(const uint32_t&   in_index)         final;
        void              set_swapchain_image_acquired_sem  (Anvil::Semaphore* in_sem_ptr)       final;

        bool get_wait_sems(uint32_t*                         out_n_wait_sems_ptr,
                           Anvil::Semaphore**                out_wait_sems_ptr_ptr,
                           const Anvil::PipelineStageFlags** out_wait_sem_stage_mask_ptr_ptr) final;

        /* Private functions */

        VKFrameGraph(const OpenGL::IBackend* in_backend_ptr);

        /* Private variables */
        uint32_t                               m_acquired_swapchain_image_index;
        Anvil::Semaphore*                      m_swapchain_acquire_sem_ptr;

        const OpenGL::IBackend*                m_backend_ptr;
        std::vector<VKFrameGraphNodeUniquePtr> m_node_ptrs;
    };
};

#endif /* VKGL_VK_FRAME_GRAPH_H */