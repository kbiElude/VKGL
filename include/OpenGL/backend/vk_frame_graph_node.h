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
        Image
    };

    typedef struct NodeIO
    {
        Anvil::AccessFlagBits      pre_access_flags;
        Anvil::PipelineStageFlags  pre_pipeline_stages;

        VKBufferReferenceUniquePtr buffer_reference_ptr;
        // VKImageReferenceUniquePtr image_reference_ptr; - todo
        const NodeIOType           type;

        union
        {
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
        };

        explicit NodeIO(VKBufferReferenceUniquePtr in_vk_buffer_reference_ptr,
                        const VkDeviceSize&        in_start_offset,
                        const VkDeviceSize&        in_size)
            :buffer_props        (in_start_offset,
                                  in_size),
             buffer_reference_ptr(std::move(in_vk_buffer_reference_ptr) ),
             type                (NodeIOType::Buffer)
        {
            /* Stub */
        }

#if 0
        TODO

        explicit NodeIO(VKImageReferenceUniquePtr           in_vk_image_reference_ptr,
                        const Anvil::ImageSubresourceRange& in_subresource_range)
            :image_props        (in_subresource_range),
             image_reference_ptr(std::move(in_vk_image_reference_ptr) ),
             type               (NodeIOType::Image)
        {
            /* Stub */
        }
#endif

    } NodeIO;

    struct VKFrameGraphNodeCreateInfo
    {
        OpenGL::CommandBaseUniquePtr command_ptr;
        std::vector<NodeIO>          inputs;
        std::vector<NodeIO>          outputs;
    };

    class IVKFrameGraphNode
    {
    public:
        virtual ~IVKFrameGraphNode()
        {
            /* Stub */
        }

        virtual bool get_input_access_properties       (const uint32_t&                    in_n_input,
                                                        Anvil::PipelineStageFlags*         out_pipeline_stages_ptr,
                                                        Anvil::AccessFlags*                out_access_flags_ptr)         = 0;
        virtual bool get_output_access_properties      (const uint32_t&                    in_n_output,
                                                        Anvil::PipelineStageFlags*         out_pipeline_stages_ptr,
                                                        Anvil::AccessFlags*                out_access_flags_ptr)         = 0;
        virtual void get_supported_queue_families      (uint32_t*                          out_n_queue_fams_ptr,
                                                        const Anvil::QueueFamilyFlagBits** out_queue_fams_ptr_ptr) const = 0; //< return in preferred order
        virtual bool record_commands                   (Anvil::CommandBufferBase*          in_cmd_buffer_ptr)            = 0;
        virtual bool requires_cpu_side_execution       ()                                                          const = 0; //< for stuff like mem block alloc + bind (buffer data cmd), etc.
        virtual bool supports_primary_command_buffers  ()                                                          const = 0;
        virtual bool supports_renderpasses             ()                                                          const = 0;
        virtual bool supports_secondary_command_buffers()                                                          const = 0;
    };

    typedef std::unique_ptr<IVKFrameGraphNode, std::function<void(IVKFrameGraphNode*)> > VKFrameGraphNodeUniquePtr;
};

#endif /* VKGL_VK_FRAME_GRAPH_NODE_H */