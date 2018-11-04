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
        static VKFrameGraphUniquePtr create(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                                            const OpenGL::IBackend*               in_backend_ptr);

        ~VKFrameGraph();

        void add_node(OpenGL::VKFrameGraphNodeUniquePtr in_node_ptr);
        void execute (const bool&                       in_block_until_finished);

        void on_buffer_deleted(Anvil::Buffer* in_buffer_ptr);
        void on_image_deleted (Anvil::Image*  in_image_ptr);

    private:
        /* Private type definitions */
        struct GroupNode;

        typedef struct BufferSubRangeInfo
        {
            VkDeviceSize start_offset;
            VkDeviceSize size;

            Anvil::QueueFamilyType owning_family_type;

            BufferSubRangeInfo()
                :owning_family_type(Anvil::QueueFamilyType::UNDEFINED),
                 size              (0),
                 start_offset      (0)
            {
                /* Stub */
            }

            BufferSubRangeInfo(const Anvil::QueueFamilyType& in_owning_family_type,
                               const VkDeviceSize&           in_start_offset,
                               const VkDeviceSize&           in_size)
                :owning_family_type(in_owning_family_type),
                 size              (in_size),
                 start_offset      (in_start_offset)
            {
                /* Stub */
            }
        } BufferSubRangeInfo;

        typedef struct SwapchainImageInfo
        {
            /* NOTE: In OpenGL, default framebuffer encapsulates up to 3 aspects at once. In Vulkan, a swapchain only holds color data.
             *       From frame graph's perspective, we still need to make sure we keep track of information necessary to correctly sync all
             *       aspects of the default FB's state.
             */
            Anvil::ImageLayout color_aspect_layout;
            Anvil::ImageLayout ds_aspect_layout;
            uint32_t           owning_queue_family_index;

            SwapchainImageInfo()
                :color_aspect_layout      (Anvil::ImageLayout::UNDEFINED),    //< default value as per spec
                 ds_aspect_layout         (Anvil::ImageLayout::UNDEFINED),
                 owning_queue_family_index(UINT32_MAX)
            {
                /* Stub */
            }
        } SwapchainImageInfo;

        typedef struct CommandBufferSubmission
        {
            GroupNode*    parent_group_node_ptr;
            Anvil::Queue* queue_ptr; //< possibly null if this is a CPU-based submission.

            std::vector<Anvil::PrimaryCommandBufferUniquePtr> command_buffers_ptr;
            std::vector<Anvil::Semaphore*>                    signal_semaphore_ptrs;
            std::vector<Anvil::PipelineStageFlags>            wait_dst_stage_masks;
            std::vector<Anvil::Semaphore*>                    wait_semaphore_ptrs;

            std::vector<Anvil::SemaphoreUniquePtr> owned_semaphore_ptrs;

            CommandBufferSubmission(GroupNode*    in_parent_group_node_ptr,
                                    Anvil::Queue* in_queue_ptr)
                :parent_group_node_ptr(in_parent_group_node_ptr),
                 queue_ptr            (in_queue_ptr)
            {
                vkgl_assert(parent_group_node_ptr != nullptr);
            }
        } CommandBufferSubmission;
        typedef std::unique_ptr<CommandBufferSubmission, std::function<void(CommandBufferSubmission*)> > CommandBufferSubmissionUniquePtr;

        typedef struct GroupNodeConnectionInfo
        {
            const GroupNode*      src_group_node_ptr;
            const OpenGL::NodeIO* src_group_node_io_ptr; // output

            uint32_t n_dst_group_node;
            uint32_t n_dst_group_node_input;

            GroupNodeConnectionInfo()
                :n_dst_group_node      (UINT32_MAX),
                 n_dst_group_node_input(UINT32_MAX),
                 src_group_node_io_ptr (nullptr),
                 src_group_node_ptr    (nullptr)
            {
                /* Stub */
            }

            GroupNodeConnectionInfo(const GroupNode*      in_src_group_node_ptr,
                                    const OpenGL::NodeIO* in_src_group_node_io_ptr,
                                    const uint32_t&       in_n_dst_group_node,
                                    const uint32_t&       in_n_dst_group_node_input)
                :n_dst_group_node      (in_n_dst_group_node),
                 n_dst_group_node_input(in_n_dst_group_node_input),
                 src_group_node_io_ptr (in_src_group_node_io_ptr),
                 src_group_node_ptr    (in_src_group_node_ptr)
            {
                /* Stub */
            }
        } GroupNodeConnectionInfo;
        typedef std::unique_ptr<GroupNodeConnectionInfo, std::function<void(GroupNodeConnectionInfo*)> > GroupNodeConnectionInfoUniquePtr;

        typedef struct GroupNode
        {
            Anvil::QueueFamilyType queue_family;

            std::vector<OpenGL::IVKFrameGraphNode*> graph_node_ptrs;
            std::vector<OpenGL::NodeIOUniquePtr>    input_ptrs;
            std::vector<OpenGL::NodeIOUniquePtr>    output_ptrs;

            std::vector<GroupNodeConnectionInfoUniquePtr>              incoming_connections_ptr;
            std::unordered_map<const OpenGL::NodeIO*, OpenGL::NodeIO*> node_io_ptr_to_group_node_io_ptr_map;
            CommandBufferSubmission*                                   parent_submission_ptr;
            bool                                                       needs_post_submission_cpu_execution;

            GroupNode()
                :needs_post_submission_cpu_execution(false),
                 parent_submission_ptr              (nullptr),
                 queue_family                       (Anvil::QueueFamilyType::UNDEFINED)
            {
                /* Stub */
            }

            GroupNode(const Anvil::QueueFamilyType& in_queue_family)
                :needs_post_submission_cpu_execution(false),
                 queue_family                       (in_queue_family),
                 parent_submission_ptr              (nullptr)
            {
                /* Stub */
            }

            ~GroupNode();

            void add_io(const OpenGL::NodeIO& in_io,
                        const bool&           in_is_input);
        } GroupNode;
        typedef std::unique_ptr<GroupNode, std::function<void(GroupNode*)> > GroupNodeUniquePtr;

        typedef struct GroupNodeToGroupNodeSquashedConnection
        {
            const GroupNode*          dst_node_ptr;
            Anvil::PipelineStageFlags dst_pipeline_stages;

            GroupNodeToGroupNodeSquashedConnection()
                :dst_node_ptr       (nullptr),
                 dst_pipeline_stages(Anvil::PipelineStageFlagBits::NONE)
            {
                /* Stub */
            }

            GroupNodeToGroupNodeSquashedConnection(const Anvil::PipelineStageFlags& in_dst_pipeline_stages,
                                                   const GroupNode*                 in_dst_node_ptr)
                :dst_node_ptr       (in_dst_node_ptr),
                 dst_pipeline_stages(in_dst_pipeline_stages)
            {
                vkgl_assert(dst_node_ptr != nullptr);
            }

            bool operator==(const GroupNode* in_dst_node_ptr) const
            {
                return (dst_node_ptr == in_dst_node_ptr);
            }
        } GroupNodeToGroupNodeSquashedConnection;

        typedef struct QueueRing
        {
            QueueRing(const uint32_t&      in_n_queues,
                      Anvil::Queue** const in_queues_ptr)
                :n_last_queue_grabbed(in_n_queues - 1),
                 queue_ptrs          (in_n_queues)
            {
                memcpy(queue_ptrs.data(),
                       in_queues_ptr,
                       in_n_queues * sizeof(Anvil::Queue*) );
            }

            Anvil::Queue* get_queue_ptr()
            {
                const auto queue_index = ((++n_last_queue_grabbed) % static_cast<uint32_t>(queue_ptrs.size() ));

                return queue_ptrs.at(queue_index);
            }

        private:
            std::vector<Anvil::Queue*> queue_ptrs;
            uint32_t                   n_last_queue_grabbed;
        } QueueRing;
        typedef std::unique_ptr<QueueRing> QueueRingUniquePtr;

        /* IVKFrameGraphNodeCallback functions */
        uint32_t          get_acquired_swapchain_image_index()                             const final;
        Anvil::Semaphore* get_swapchain_image_acquired_sem  ()                             const final;
        void              set_acquired_swapchain_image_index(const uint32_t&   in_index)         final;
        void              set_swapchain_image_acquired_sem  (Anvil::Semaphore* in_sem_ptr)       final;

        bool get_wait_sems(uint32_t*                         out_n_wait_sems_ptr,
                           Anvil::Semaphore***               out_wait_sems_ptr_ptr_ptr,
                           const Anvil::PipelineStageFlags** out_wait_sem_stage_mask_ptr_ptr) final;

        /* Private functions */

        VKFrameGraph(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                     const OpenGL::IBackend*               in_backend_ptr);

        void process_swapchain_image_node_input            (std::vector<Anvil::ImageBarrier>& inout_image_barriers,
                                                            const NodeIO*                     in_input_ptr,
                                                            const Anvil::Queue*               in_opt_queue_ptr,
                                                            const Anvil::AccessFlags&         in_access_mask_for_color_aspect,
                                                            const Anvil::AccessFlags&         in_access_mask_for_ds_aspects,
                                                            Anvil::PipelineStageFlags&        inout_src_pipeline_stages);
        void split_access_mask_to_color_and_ds_access_masks(const Anvil::AccessFlags&         in_access_mask,
                                                            Anvil::AccessFlags*               out_color_aspect_access_mask_ptr,
                                                            Anvil::AccessFlags*               out_ds_aspects_access_mask_ptr) const;

        bool coalesce_to_group_nodes       (const std::vector<VKFrameGraphNodeUniquePtr>&                                                     in_node_ptrs,
                                            std::vector<GroupNodeUniquePtr>*                                                                  out_group_nodes_ptr,
                                            std::unordered_map<const GroupNode*, std::vector<GroupNodeToGroupNodeSquashedConnection> >*       out_src_dst_group_node_connections_ptr);
        bool execute_cpu_prepass           (const std::vector<VKFrameGraphNodeUniquePtr>&                                                     in_node_ptrs);
        bool inject_swapchain_acquire_nodes(std::vector<VKFrameGraphNodeUniquePtr>&                                                           inout_node_ptrs);
        bool record_command_buffers        (const std::vector<GroupNodeUniquePtr>&                                                            in_group_nodes_ptr,
                                            const std::unordered_map<const GroupNode*, std::vector<GroupNodeToGroupNodeSquashedConnection> >& in_src_dst_group_node_connections_ptr,
                                            std::vector<CommandBufferSubmissionUniquePtr>*                                                    out_cmd_buffer_submissions_ptr);
        bool submit_command_buffers        (const std::vector<CommandBufferSubmissionUniquePtr>&                                              in_cmd_buffer_submissions_ptr,
                                            Anvil::Fence*                                                                                     in_opt_wait_fence_ptr);

        bool init                ();
        bool init_per_object_data();
        bool init_queue_rings    ();

        bool do_group_nodes_encapsulate_swapchain_acquire_present_command_stream(const std::vector<GroupNodeUniquePtr>& in_group_nodes_ptr) const;

        /* Private variables */
        uint32_t                               m_acquired_swapchain_image_index;
        Anvil::Semaphore*                      m_swapchain_acquire_sem_ptr;

        const OpenGL::IBackend*                m_backend_ptr;
        const OpenGL::IContextObjectManagers*  m_frontend_ptr;
        std::vector<VKFrameGraphNodeUniquePtr> m_node_ptrs;

        std::unordered_map<Anvil::Buffer*, std::vector<BufferSubRangeInfo> > m_buffer_data; //< todo: Use binary tree or a more fancy structure to speed up coalesce/split ops
        std::vector<SwapchainImageInfo>                                      m_swapchain_image_data;

        std::vector<Anvil::PipelineStageFlags> m_wait_sem_stage_masks_for_current_cpu_node;
        std::vector<Anvil::Semaphore*>         m_wait_sem_vec_for_current_cpu_node;

        std::unordered_map<Anvil::QueueFamilyType, QueueRingUniquePtr> m_queue_ring_ptr_per_queue_fam;

        std::mutex m_execute_mutex;
        std::mutex m_general_mutex;
    };
};

#endif /* VKGL_VK_FRAME_GRAPH_H */