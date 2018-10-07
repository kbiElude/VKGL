/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_frame_graph.h"

OpenGL::VKFrameGraph::VKFrameGraph()
{
    /* Stub */
}

OpenGL::VKFrameGraph::~VKFrameGraph()
{
    /* Stub */
}

void OpenGL::VKFrameGraph::add_node(OpenGL::VKFrameGraphNodeUniquePtr in_node_ptr)
{
    /* todo */

    m_node_ptrs.push_back(
        std::move(in_node_ptr)
    );
}

void OpenGL::VKFrameGraph::clear()
{
    /* todo */

    m_node_ptrs.clear();
}

OpenGL::VKFrameGraphUniquePtr OpenGL::VKFrameGraph::create()
{
    OpenGL::VKFrameGraphUniquePtr result_ptr(nullptr,
                                             [](OpenGL::VKFrameGraph* in_ptr){ delete in_ptr; });

    result_ptr.reset(
        new OpenGL::VKFrameGraph()
    );

    vkgl_assert(result_ptr != nullptr);
    if (result_ptr != nullptr)
    {
        /* Nothing to do for now. */
    }

    return result_ptr;
}

void OpenGL::VKFrameGraph::execute()
{
    vkgl_not_implemented();
}

