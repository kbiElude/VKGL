/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_FRAME_GRAPH_NODE_H
#define VKGL_VK_FRAME_GRAPH_NODE_H

#include "Anvil/include/misc/types.h"
#include "OpenGL/backend/vk_commands.h"
#include "OpenGL/types.h"
#include <map>

namespace OpenGL
{
    enum class NodeIOType
    {
        Buffer,
        Image,
        Swapchain_Image,

        Unknown
    };

    typedef struct NodeIO
    {
        union
        {
            VKBufferReference*    buffer_reference_ptr;
            // VKImageReference*  image_reference_ptr; - todo
            VKSwapchainReference* swapchain_reference_ptr;
        };

        NodeIOType type;

        struct BufferProps
        {
            VkDeviceSize size;
            VkDeviceSize start_offset;

            BufferProps()
            {
                /* Stub */
            }

            BufferProps(const VkDeviceSize& in_start_offset,
                        const VkDeviceSize& in_size)
                :size        (in_size),
                 start_offset(in_start_offset)
            {
                /* Stub */
            }
        } buffer_props;

        struct ImageProps
        {
            Anvil::ImageSubresourceRange subresource_range;

            ImageProps()
            {
                /* Stub */
            }

            ImageProps(const Anvil::ImageSubresourceRange& in_subresource_range)
                :subresource_range(subresource_range)
            {
                /* Stub */
            }
        } image_props;

        struct SwapchainImageProps
        {
            Anvil::AccessFlags        access;
            Anvil::ImageLayout        image_layout; //< for inputs:  layout the image must be in prior node execution;
                                                    //< for outputs: layout the image is in after node finishes executing.
            Anvil::PipelineStageFlags pipeline_stages;

            SwapchainImageProps()
            {
                /* Stub */
            }

            SwapchainImageProps(const Anvil::ImageLayout&        in_image_layout,
                                const Anvil::PipelineStageFlags& in_pipeline_stages,
                                const Anvil::AccessFlags&        in_access)
                :access         (in_access),
                 image_layout   (in_image_layout),
                 pipeline_stages(in_pipeline_stages)
            {
                /* Stub */
            }
        } swapchain_image_props;

        NodeIO()
            :type(NodeIOType::Unknown)
        {
            /* Stub */
        }

        explicit NodeIO(VKBufferReference*  in_vk_buffer_reference_ptr,
                        const VkDeviceSize& in_start_offset,
                        const VkDeviceSize& in_size)
            :buffer_props        (in_start_offset,
                                  in_size),
             buffer_reference_ptr(in_vk_buffer_reference_ptr),
             type                (NodeIOType::Buffer)
        {
            /* Stub */
        }

#if 0
        TODO

        explicit NodeIO(VKImageReference*                   in_vk_image_reference_ptr,
                        const Anvil::ImageSubresourceRange& in_subresource_range)
            :image_props        (in_subresource_range),
             image_reference_ptr(in_vk_image_reference_ptr),
             type               (NodeIOType::Image)
        {
            /* Stub */
        }
#endif
        explicit NodeIO(VKSwapchainReference*            in_vk_swapchain_reference_ptr,
                        const Anvil::ImageLayout&        in_image_layout,
                        const Anvil::PipelineStageFlags& in_pipeline_stages,
                        const Anvil::AccessFlags&        in_access)
            :swapchain_image_props  (in_image_layout,
                                     in_pipeline_stages,
                                     in_access),
             swapchain_reference_ptr(in_vk_swapchain_reference_ptr),
             type                   (NodeIOType::Swapchain_Image)
        {
            /* Stub */
        }
    } NodeIO;

    struct VKFrameGraphNodeInfo
    {
        std::vector<NodeIO> inputs;
        std::vector<NodeIO> outputs;

        Anvil::Event*     opt_post_sync_event_ptr;     //< if not null, scheduler will use the event to sync with subsequent nodes
        Anvil::Fence*     opt_post_sync_fence_ptr;     //< if not null, scheduler will use the fence to sync with subsequent nodes
        Anvil::Semaphore* opt_post_sync_semaphore_ptr; //< if not null, scheduler will use the sem to sync with subsequent nodes

        VKFrameGraphNodeInfo()
        {
            opt_post_sync_event_ptr     = nullptr;
            opt_post_sync_fence_ptr     = nullptr;
            opt_post_sync_semaphore_ptr = nullptr;
        }
    };
    typedef std::unique_ptr<VKFrameGraphNodeInfo, std::function<void(VKFrameGraphNodeInfo*)> > VKFrameGraphNodeInfoUniquePtr;

    class IVKFrameGraphNode
    {
    public:
        virtual ~IVKFrameGraphNode()
        {
            /* Stub */
        }

        virtual void do_cpu_prepass(IVKFrameGraphNodeCallback* in_callback_ptr) = 0; //< see requires_cpu_prepass(). called from within a random worker thread, make no assumptions.

        virtual void execute_cpu_side(IVKFrameGraphNodeCallback* in_callback_ptr) = 0; //< called from within a random worker thread, make no assumptions. only invoked if requires_cpu_side_execution() returns true.

        virtual const VKFrameGraphNodeInfo* get_info_ptr() const = 0; //< contents may be altered by do_cpu_prepass() invocations.

        virtual bool get_input_access_properties (const uint32_t&                    in_n_input,
                                                  Anvil::PipelineStageFlags*         out_pipeline_stages_ptr,
                                                  Anvil::AccessFlags*                out_access_flags_ptr)   const = 0;
        virtual bool get_output_access_properties(const uint32_t&                    in_n_output,
                                                  Anvil::PipelineStageFlags*         out_pipeline_stages_ptr,
                                                  Anvil::AccessFlags*                out_access_flags_ptr)   const = 0;
        virtual void get_supported_queue_families(uint32_t*                          out_n_queue_fams_ptr,
                                                  const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const = 0; //< return in preferred order

        virtual void on_commands_finished_executing_gpu_side() = 0;

        virtual void record_commands(Anvil::CommandBufferBase* in_cmd_buffer_ptr,
                                     const bool&               in_inside_renderpass) const = 0;

        virtual bool requires_cpu_side_execution       () const = 0;
        virtual bool requires_cpu_prepass              () const = 0; //< true if needs a do_cpu_prepass() invocation prior to cmd buffer recording
        virtual bool requires_gpu_side_execution       () const = 0;
        virtual bool requires_manual_wait_sem_sync     () const = 0; //< true if node must be provided a list of semaphores required for synchronization.
                                                                     //< Nodes acknowledge they will wait on the provided sems prior to proceeding with their work.
                                                                     //<
                                                                     //< By default, this is handled by the scheduler but certain nodes (eg. present node) may need to handle this on their own.
                                                                     //<
                                                                     //< If true, requires_cpu_side_execution() must return true and requires_gpu_side_execution() must return false.
                                                                     //<
                                                                     //< If true, the list must be obtained by calling IVKFrameGraphNodeCallback::get_wait_sems() at execute_cpu_side() call time.
                                                                     //<
                                                                     //< If false, all necessary sync is performed automatically by the scheduler, using node info exposed by nodes.
        virtual bool supports_primary_command_buffers  () const = 0;
        virtual bool supports_renderpasses             () const = 0;
        virtual bool supports_secondary_command_buffers() const = 0;
    };

    typedef std::unique_ptr<IVKFrameGraphNode, std::function<void(IVKFrameGraphNode*)> > VKFrameGraphNodeUniquePtr;
};

#endif /* VKGL_VK_FRAME_GRAPH_NODE_H */