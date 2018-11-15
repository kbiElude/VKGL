/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_renderpass_manager.h"

OpenGL::VKRenderpassManager::VKRenderpassManager(IBackend* in_backend_ptr)
    :m_backend_ptr(in_backend_ptr)
{
    vkgl_assert(in_backend_ptr != nullptr);
}

OpenGL::VKRenderpassManager::~VKRenderpassManager()
{
    /* Stub for now */

}

OpenGL::VKRenderpassManagerUniquePtr OpenGL::VKRenderpassManager::create(IBackend* in_backend_ptr)
{
    OpenGL::VKRenderpassManagerUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::VKRenderpassManager(in_backend_ptr) );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}


Anvil::RenderPass* OpenGL::VKRenderpassManager::get_render_pass(const Anvil::RenderPassCreateInfo* in_rp_create_info_ptr)
{
    vkgl_not_implemented();

    return nullptr;
}

bool OpenGL::VKRenderpassManager::is_rp_compatible(const Anvil::RenderPassCreateInfo* in_rp1_create_info_ptr,
                                                   const Anvil::RenderPassCreateInfo* in_rp2_create_info_ptr) const
{
    vkgl_not_implemented();

    return false;
}