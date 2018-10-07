/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_FRAME_GRAPH_H
#define VKGL_VK_FRAME_GRAPH_H

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

    struct VKFrameGraphNode
    {
        CommandBaseUniquePtr command_ptr;
        std::vector<NodeIO>  inputs;
        std::vector<NodeIO>  outputs;
    };

    typedef std::unique_ptr<VKFrameGraphNode, std::function<void(VKFrameGraphNode*)> > VKFrameGraphNodeUniquePtr;

    class VKFrameGraph
    {
    public:
        /* Public functions */
        static VKFrameGraphUniquePtr create();

        ~VKFrameGraph();

        void add_node(OpenGL::VKFrameGraphNodeUniquePtr in_node_ptr);
        void clear   ();
        void execute ();

    private:
        /* Private type definitions */

        /* Private functions */

        VKFrameGraph();

        /* Private variables */
        std::vector<VKFrameGraphNodeUniquePtr> m_node_ptrs;
    };
};

#endif /* VKGL_VK_FRAME_GRAPH_H */