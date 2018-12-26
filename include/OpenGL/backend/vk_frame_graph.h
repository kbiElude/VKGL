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

        typedef struct BarrierData
        {
            Anvil::PipelineStageFlags dst_pipeline_stages;
            Anvil::PipelineStageFlags src_pipeline_stages;

            std::vector<Anvil::BufferBarrier> buffer_barriers;
            std::vector<Anvil::ImageBarrier>  image_barriers;

            BarrierData()
                :dst_pipeline_stages(Anvil::PipelineStageFlagBits::NONE),
                 src_pipeline_stages(Anvil::PipelineStageFlagBits::NONE)
            {
                /* Stub */
            }
        } BarrierData;

        typedef struct BufferInfo
        {
            uint32_t owning_queue_family_index;

            BufferInfo()
                :owning_queue_family_index(UINT32_MAX)
            {
                /* Stub */
            }
        } BufferInfo;

        struct CommandBufferDynamicState
        {
            Anvil::PipelineID bound_gfx_pipeline_id;
            bool              is_gfx_pipeline_id_bound;

            float             bound_dynamic_blend_color_state[4];
            bool              is_dynamic_blend_color_state_bound;

            float             bound_dynamic_line_width_state;
            bool              is_dynamic_line_width_state_bound;

            VkRect2D          bound_dynamic_scissor_state;
            bool              is_dynamic_scissor_state_bound;

            int32_t           bound_dynamic_stencil_compare_mask_back_state;
            bool              is_dynamic_stencil_compare_mask_back_state_bound;

            int32_t           bound_dynamic_stencil_compare_mask_front_state;
            bool              is_dynamic_stencil_compare_mask_front_state_bound;

            int32_t           bound_dynamic_stencil_reference_back_state;
            bool              is_dynamic_stencil_reference_back_state_bound;

            int32_t           bound_dynamic_stencil_reference_front_state;
            bool              is_dynamic_stencil_reference_front_state_bound;

            int32_t           bound_dynamic_stencil_write_mask_back_state;
            bool              is_dynamic_stencil_write_mask_back_state_bound;

            int32_t           bound_dynamic_stencil_write_mask_front_state;
            bool              is_dynamic_stencil_write_mask_front_state_bound;

            VkViewport        bound_dynamic_viewport_state;
            bool              is_dynamic_viewport_state_bound;

            CommandBufferDynamicState();
        };

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
            GroupNode* parent_group_node_ptr;

            std::vector<Anvil::PrimaryCommandBuffer*> command_buffers_ptr;
            std::vector<Anvil::Semaphore*>            signal_semaphore_ptrs;
            std::vector<Anvil::PipelineStageFlags>    wait_dst_stage_masks;
            std::vector<Anvil::Semaphore*>            wait_semaphore_ptrs;

            CommandBufferSubmission(GroupNode* in_parent_group_node_ptr)
                :parent_group_node_ptr(in_parent_group_node_ptr)
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

        typedef struct IntraGraphNodeConnectionInfo
        {
            uint32_t n_dst_graph_node;
            uint32_t n_dst_graph_node_input;

            uint32_t n_src_graph_node;
            uint32_t n_src_graph_node_output;

            IntraGraphNodeConnectionInfo()
                :n_dst_graph_node       (UINT32_MAX),
                 n_dst_graph_node_input (UINT32_MAX),
                 n_src_graph_node       (UINT32_MAX),
                 n_src_graph_node_output(UINT32_MAX)
            {
                /* Stub */
            }

            IntraGraphNodeConnectionInfo(const uint32_t& in_n_src_graph_node,
                                         const uint32_t& in_n_src_graph_node_output,
                                         const uint32_t& in_n_dst_graph_node,
                                         const uint32_t& in_n_dst_graph_node_input)
                :n_dst_graph_node       (in_n_dst_graph_node),
                 n_dst_graph_node_input (in_n_dst_graph_node_input),
                 n_src_graph_node       (in_n_src_graph_node),
                 n_src_graph_node_output(in_n_src_graph_node_output)
            {
                vkgl_assert(n_dst_graph_node != n_src_graph_node);
            }
        } IntraGraphNodeConnectionInfo;

        typedef struct GroupNode
        {
            Anvil::QueueFamilyType queue_family;
            Anvil::Queue*          queue_ptr;      //< possibly null if this is a CPU-based submission.

            uint32_t            framebuffer_n_layers; //< only valid if uses_renderpass is true.
            Anvil::Framebuffer* framebuffer_ptr;      //< only valid if uses_renderpass is true.
            uint32_t            framebuffer_size[2];  //< only valid if uses_renderpass is true.
            Anvil::RenderPass*  renderpass_ptr;       //< only valid if uses_renderpass is true.
            bool                uses_renderpass;      //< only valid for UNIVERSAL queue families.

            std::vector<OpenGL::IVKFrameGraphNode*> graph_node_ptrs;
            std::vector<OpenGL::NodeIOUniquePtr>    input_ptrs;
            std::vector<OpenGL::NodeIOUniquePtr>    output_ptrs;

            std::vector<GroupNodeConnectionInfoUniquePtr>              incoming_group_node_connections_ptr; //< TODO: this is somewhat duplicate to *src_dst_group_node_connections* used elsewhere in this header.
                                                                                                            //<       the ways the two are used are tad different but ultimately serve similar purpose; any way we could merge them?
            std::vector<IntraGraphNodeConnectionInfo>                  intra_graph_node_connections;

            std::unordered_map<const OpenGL::NodeIO*, OpenGL::NodeIO*> node_io_ptr_to_group_node_io_ptr_map;
            CommandBufferSubmission*                                   parent_submission_ptr;
            bool                                                       needs_post_submission_cpu_execution;

            BarrierData              group_node_pre_barriers;
            std::vector<BarrierData> intra_graph_node_pre_barriers;

            GroupNode()
                :framebuffer_n_layers               (0),
                 framebuffer_ptr                    (nullptr),
                 needs_post_submission_cpu_execution(false),
                 parent_submission_ptr              (nullptr),
                 queue_family                       (Anvil::QueueFamilyType::UNDEFINED),
                 queue_ptr                          (nullptr),
                 renderpass_ptr                     (nullptr),
                 uses_renderpass                    (false)
            {
                framebuffer_size[0] = 0;
                framebuffer_size[1] = 0;
            }

            GroupNode(const Anvil::QueueFamilyType& in_queue_family,
                      const bool&                   in_uses_renderpass)
                :framebuffer_n_layers               (0),
                 framebuffer_ptr                    (nullptr),
                 needs_post_submission_cpu_execution(false),
                 queue_family                       (in_queue_family),
                 queue_ptr                          (nullptr),
                 parent_submission_ptr              (nullptr),
                 renderpass_ptr                     (nullptr),
                 uses_renderpass                    (in_uses_renderpass)
            {
                vkgl_assert((!in_uses_renderpass) ||
                            ( in_uses_renderpass && in_queue_family == Anvil::QueueFamilyType::UNIVERSAL) );

                framebuffer_size[0] = 0;
                framebuffer_size[1] = 0;
            }

            ~GroupNode();

            void add_io(const OpenGL::NodeIO& in_io,
                        const bool&           in_is_input);
        } GroupNode;
        typedef std::unique_ptr<GroupNode, std::function<void(GroupNode*)> > GroupNodeUniquePtr;

        typedef struct GroupNodeToGroupNodeSquashedConnection
        {
            Anvil::AccessFlags        dst_access_flags;
            const GroupNode*          dst_node_ptr;
            Anvil::PipelineStageFlags dst_pipeline_stages;
            Anvil::AccessFlags        src_access_flags;
            Anvil::PipelineStageFlags src_pipeline_stages;

            GroupNodeToGroupNodeSquashedConnection()
                :dst_access_flags   (Anvil::AccessFlagBits::NONE),
                 dst_node_ptr       (nullptr),
                 dst_pipeline_stages(Anvil::PipelineStageFlagBits::NONE),
                 src_access_flags   (Anvil::AccessFlagBits::NONE),
                 src_pipeline_stages(Anvil::PipelineStageFlagBits::NONE)

            {
                /* Stub */
            }

            GroupNodeToGroupNodeSquashedConnection(const Anvil::PipelineStageFlags& in_dst_pipeline_stages,
                                                   const Anvil::AccessFlags&        in_dst_access_flags,
                                                   const GroupNode*                 in_dst_node_ptr,
                                                   const Anvil::PipelineStageFlags& in_src_pipeline_stages,
                                                   const Anvil::AccessFlags&        in_src_access_flags)
                :dst_access_flags   (in_dst_access_flags),
                 dst_node_ptr       (in_dst_node_ptr),
                 dst_pipeline_stages(in_dst_pipeline_stages),
                 src_access_flags   (in_src_access_flags),
                 src_pipeline_stages(in_src_pipeline_stages)
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

        typedef struct ActiveSubmission
        {
            Anvil::FenceUniquePtr                  fence_ptr;
            std::vector<GroupNodeUniquePtr>        group_node_ptrs_vec;
            std::vector<VKFrameGraphNodeUniquePtr> node_ptrs_vec;

            ActiveSubmission(Anvil::FenceUniquePtr                   in_fence_ptr,
                             std::vector<GroupNodeUniquePtr>&        inout_group_node_ptrs_vec,
                             std::vector<VKFrameGraphNodeUniquePtr>& inout_node_ptrs_vec)
                :fence_ptr          (std::move(in_fence_ptr) ),
                 group_node_ptrs_vec(std::move(inout_group_node_ptrs_vec) ),
                 node_ptrs_vec      (std::move(inout_node_ptrs_vec) )
            {
                /* Stub */
            }
        } ActiveSubmission;

        /* IVKFrameGraphNodeCallback functions */
        uint32_t          get_acquired_swapchain_image_index()                                              const final;
        Anvil::PipelineID get_pipeline_id                   (const OpenGL::DrawCallMode& in_draw_call_mode)       final;
        Anvil::Semaphore* get_swapchain_image_acquired_sem  ()                                              const final;
        void              set_acquired_swapchain_image_index(const uint32_t&   in_index)                          final;
        void              set_swapchain_image_acquired_sem  (Anvil::Semaphore* in_sem_ptr)                        final;

        bool get_wait_sems(uint32_t*                         out_n_wait_sems_ptr,
                           Anvil::Semaphore***               out_wait_sems_ptr_ptr_ptr,
                           const Anvil::PipelineStageFlags** out_wait_sem_stage_mask_ptr_ptr) final;

        bool get_bound_dynamic_blend_color_state               (float*             out_result_vec4_ptr) const final;
        bool get_bound_dynamic_line_width_state                (float*             out_result_ptr)      const final;
        bool get_bound_dynamic_scissor_state                   (VkRect2D*          out_result_ptr)      const final;
        bool get_bound_dynamic_stencil_compare_mask_back_state (int32_t*           out_result_ptr)      const final;
        bool get_bound_dynamic_stencil_compare_mask_front_state(int32_t*           out_result_ptr)      const final;
        bool get_bound_dynamic_stencil_reference_back_state    (int32_t*           out_result_ptr)      const final;
        bool get_bound_dynamic_stencil_reference_front_state   (int32_t*           out_result_ptr)      const final;
        bool get_bound_dynamic_stencil_write_mask_back_state   (int32_t*           out_result_ptr)      const final;
        bool get_bound_dynamic_stencil_write_mask_front_state  (int32_t*           out_result_ptr)      const final;
        bool get_bound_dynamic_viewport_state                  (VkViewport*        out_result_ptr)      const final;
        bool get_bound_pipeline_id                             (Anvil::PipelineID* out_result_ptr)      const final;

        void set_bound_dynamic_blend_color_state               (const float*             in_data_vec4_ptr) final;
        void set_bound_dynamic_line_width_state                (const float&             in_line_width)    final;
        void set_bound_dynamic_scissor_state                   (const VkRect2D&          in_scissor)       final;
        void set_bound_dynamic_stencil_compare_mask_back_state (const int32_t&           in_value)         final;
        void set_bound_dynamic_stencil_compare_mask_front_state(const int32_t&           in_value)         final;
        void set_bound_dynamic_stencil_reference_back_state    (const int32_t&           in_value)         final;
        void set_bound_dynamic_stencil_reference_front_state   (const int32_t&           in_value)         final;
        void set_bound_dynamic_stencil_write_mask_back_state   (const int32_t&           in_value)         final;
        void set_bound_dynamic_stencil_write_mask_front_state  (const int32_t&           in_value)         final;
        void set_bound_dynamic_viewport_state                  (const VkViewport&        in_viewport)      final;
        void set_bound_pipeline_id                             (const Anvil::PipelineID& in_pipeline_id)   final;

        /* Private functions */

        VKFrameGraph(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                     const OpenGL::IBackend*               in_backend_ptr);

        void process_buffer_node_input                     (std::vector<Anvil::BufferBarrier>& inout_buffer_barriers,
                                                            const NodeIO*                      in_input_ptr,
                                                            const Anvil::Queue*                in_opt_queue_ptr,
                                                            const Anvil::AccessFlags&          in_access_mask,
                                                            Anvil::PipelineStageFlags&         inout_src_pipeline_stages);
        void process_swapchain_image_node_input            (std::vector<Anvil::ImageBarrier>&  inout_image_barriers,
                                                            const NodeIO*                      in_input_ptr,
                                                            const Anvil::Queue*                in_opt_queue_ptr,
                                                            const Anvil::AccessFlags&          in_access_mask_for_color_aspect,
                                                            const Anvil::AccessFlags&          in_access_mask_for_ds_aspects,
                                                            Anvil::PipelineStageFlags&         inout_src_pipeline_stages,
                                                            const bool&                        in_parent_group_node_uses_renderpass);
        void split_access_mask_to_color_and_ds_access_masks(const Anvil::AccessFlags&          in_access_mask,
                                                            Anvil::AccessFlags*                out_color_aspect_access_mask_ptr,
                                                            Anvil::AccessFlags*                out_ds_aspects_access_mask_ptr) const;

        bool bake_barriers                 (const std::vector<GroupNodeUniquePtr>&                                                            in_group_nodes_ptr);
        bool bake_framebuffers             (const std::vector<GroupNodeUniquePtr>&                                                            in_group_nodes_ptr);
        bool bake_renderpasses             (const std::vector<GroupNodeUniquePtr>&                                                            in_group_nodes_ptr,
                                            const std::unordered_map<const GroupNode*, std::vector<GroupNodeToGroupNodeSquashedConnection> >* in_src_dst_group_node_connections_ptr);
        bool coalesce_to_group_nodes       (const std::vector<VKFrameGraphNodeUniquePtr>&                                                     in_node_ptrs,
                                            std::vector<GroupNodeUniquePtr>*                                                                  out_group_nodes_ptr,
                                            std::unordered_map<const GroupNode*, std::vector<GroupNodeToGroupNodeSquashedConnection> >*       out_src_dst_group_node_connections_ptr);
        bool execute_cpu_prepass           (const std::vector<VKFrameGraphNodeUniquePtr>&                                                     in_node_ptrs);
        bool inject_swapchain_acquire_nodes(std::vector<VKFrameGraphNodeUniquePtr>&                                                           inout_node_ptrs);
        bool record_command_buffers        (const std::vector<GroupNodeUniquePtr>&                                                            in_group_nodes_ptr,
                                            const std::unordered_map<const GroupNode*, std::vector<GroupNodeToGroupNodeSquashedConnection> >& in_src_dst_group_node_connections,
                                            std::vector<CommandBufferSubmissionUniquePtr>*                                                    out_cmd_buffer_submissions_ptr);
        bool submit_command_buffers        (const std::vector<CommandBufferSubmissionUniquePtr>&                                              in_cmd_buffer_submissions_ptr,
                                            Anvil::Fence*                                                                                     in_opt_wait_fence_ptr);

        bool init                ();
        bool init_per_object_data();
        bool init_queue_rings    ();

        bool do_group_nodes_encapsulate_swapchain_acquire_present_command_stream(const std::vector<GroupNodeUniquePtr>& in_group_nodes_ptr) const;

        /* Private variables */
        uint32_t                               m_acquired_swapchain_image_index;
        OpenGL::IVKFrameGraphNode*             m_active_graph_node_ptr;
        GroupNode*                             m_active_group_node_ptr;
        Anvil::SubPassID                       m_active_subpass_id;
        Anvil::Semaphore*                      m_swapchain_acquire_sem_ptr;

        const OpenGL::IBackend*                m_backend_ptr;
        const OpenGL::IContextObjectManagers*  m_frontend_ptr;
        std::vector<VKFrameGraphNodeUniquePtr> m_node_ptrs;

        std::unordered_map<Anvil::Buffer*, BufferInfo> m_buffer_data; //< todo: Use binary tree or a more fancy structure to speed up coalesce/split ops
                                                                      //< todo: Use buffer memory subregions instead of buffer instances.
        std::vector<SwapchainImageInfo>                m_swapchain_image_data;

        std::vector<Anvil::PipelineStageFlags> m_wait_sem_stage_masks_for_current_cpu_node;
        std::vector<Anvil::Semaphore*>         m_wait_sem_vec_for_current_cpu_node;

        std::unordered_map<Anvil::QueueFamilyType, QueueRingUniquePtr> m_queue_ring_ptr_per_queue_fam;

        //< todo: this holds sems which have been used for submission and no fence has been used which would let us determine
        //<       the status of the sem.. Once we're sure they're no longer used, they should be destroyed or released back to the sem pool.
        //<       One way of determining this would be to spawn a "cleanup" task every second which would device-idle and wipe out all
        //<       sems from the graveyard (the list would've had to be cached before the wait op, of course).
        //<       Other types of graveyards are also used. Same rules apply.
        std::vector<Anvil::PrimaryCommandBufferUniquePtr> m_cmd_buffer_ptr_graveyard;
        std::vector<Anvil::SemaphoreUniquePtr>            m_sem_ptr_graveyard;

        //< Only used at command buffer recording time.
        CommandBufferDynamicState m_current_cmd_buffer_dynamic_state;

        //< Vulkan objects must not be released until command buffer submissions that consume them
        //< finish executing GPU-side. We need to take this into account:
        //<
        //< * Group nodes may use various staging object.
        //< * Group nodes hold references to objects owned by the backend. These are usually accessed
        //<   by commands recorded to command buffers.
        //<
        //< Each submission chain is therefore cached by storing a fence used for the last submission,
        //< along with all nodes that contributed to the submission. Once the fence is set, it is safe
        //< to release all objects.
        std::vector<ActiveSubmission> m_active_submissions;

        std::mutex m_execute_mutex;
        std::mutex m_general_mutex;
    };
};

#endif /* VKGL_VK_FRAME_GRAPH_H */