/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_frame_graph_node.h"

OpenGL::NodeIO::NodeIO(const NodeIO& in_node_io)
    :type(in_node_io.type)
{
    switch (type)
    {
        case OpenGL::NodeIOType::Buffer:
        {
            buffer_props         = in_node_io.buffer_props;
            buffer_reference_ptr = in_node_io.buffer_reference_ptr->clone();

            break;
        }

        case OpenGL::NodeIOType::Image:
        {
            vkgl_not_implemented();
        }

        default:
        {
            vkgl_assert_fail();
        }
    }
}
