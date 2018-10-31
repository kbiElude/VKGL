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

        typedef struct GroupNodeConnectionInfo
        {
            const GroupNode*      src_group_node_ptr;
            const OpenGL::NodeIO* src_group_node_io_ptr; // output

            uint32_t n_dst_group_node_input;

            GroupNodeConnectionInfo()
                :n_dst_group_node_input(UINT32_MAX),
                 src_group_node_io_ptr (nullptr),
                 src_group_node_ptr    (nullptr)
            {
                /* Stub */
            }

            GroupNodeConnectionInfo(const GroupNode*      in_src_group_node_ptr,
                                    const OpenGL::NodeIO* in_src_group_node_io_ptr,
                                    const uint32_t&       in_n_dst_group_node_input)
                :n_dst_group_node_input(in_n_dst_group_node_input),
                 src_group_node_io_ptr (in_src_group_node_io_ptr),
                 src_group_node_ptr    (in_src_group_node_ptr)
            {
                /* Stub */
            }
        } GroupNodeConnectionInfo;
        typedef std::unique_ptr<GroupNodeConnectionInfo, std::function<void(GroupNodeConnectionInfo*)> > GroupNodeConnectionInfoUniquePtr;

        typedef struct GroupNode
        {
            Anvil::QueueFamilyFlagBits queue_family;

            std::vector<OpenGL::IVKFrameGraphNode*> graph_node_ptrs;
            std::vector<OpenGL::NodeIOUniquePtr>    input_ptrs;
            std::vector<OpenGL::NodeIOUniquePtr>    output_ptrs;

            std::unordered_map<const OpenGL::NodeIO*, OpenGL::NodeIO*> node_io_ptr_to_group_node_io_ptr_map;

            GroupNode()
                :queue_family(Anvil::QueueFamilyFlagBits::NONE)
            {
                /* Stub */
            }

            GroupNode(const Anvil::QueueFamilyFlagBits& in_queue_family)
                :queue_family(in_queue_family)
            {
                /* Stub */
            }

            ~GroupNode();

            void add_io(const OpenGL::NodeIO& in_io,
                        const bool&           in_is_input);
        } GroupNode;
        typedef std::unique_ptr<GroupNode, std::function<void(GroupNode*)> > GroupNodeUniquePtr;

        /* IVKFrameGraphNodeCallback functions */
        uint32_t          get_acquired_swapchain_image_index()                             const final;
        Anvil::Semaphore* get_swapchain_image_acquired_sem  ()                             const final;
        void              set_acquired_swapchain_image_index(const uint32_t&   in_index)         final;
        void              set_swapchain_image_acquired_sem  (Anvil::Semaphore* in_sem_ptr)       final;

        bool get_wait_sems(uint32_t*                         out_n_wait_sems_ptr,
                           Anvil::Semaphore**                out_wait_sems_ptr_ptr,
                           const Anvil::PipelineStageFlags** out_wait_sem_stage_mask_ptr_ptr) final;

        /* Private functions */

        VKFrameGraph(const OpenGL::IContextObjectManagers* in_frontend_ptr,
                     const OpenGL::IBackend*               in_backend_ptr);

        bool coalesce_to_group_nodes       (const std::vector<VKFrameGraphNodeUniquePtr>&                          in_node_ptrs,
                                            std::vector<GroupNodeUniquePtr>*                                       out_group_nodes_ptr,
                                            std::unordered_map<const GroupNode*, std::vector<const GroupNode* > >* out_src_dst_group_node_connections_ptr);
        bool execute_cpu_prepass           (const std::vector<VKFrameGraphNodeUniquePtr>&                          in_node_ptrs);
        bool inject_swapchain_acquire_nodes(std::vector<VKFrameGraphNodeUniquePtr>&                                inout_node_ptrs);

        /* Private variables */
        uint32_t                               m_acquired_swapchain_image_index;
        Anvil::Semaphore*                      m_swapchain_acquire_sem_ptr;

        const OpenGL::IBackend*                m_backend_ptr;
        const OpenGL::IContextObjectManagers*  m_frontend_ptr;
        std::vector<VKFrameGraphNodeUniquePtr> m_node_ptrs;

        std::unordered_map<Anvil::Buffer*, std::vector<BufferSubRangeInfo> > m_buffer_data; //< todo: Use binary tree or a more fancy structure to speed up coalesce/split ops

        std::mutex m_execute_mutex;
        std::mutex m_general_mutex;
    };
};

#endif /* VKGL_VK_FRAME_GRAPH_H */