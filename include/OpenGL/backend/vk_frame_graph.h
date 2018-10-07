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