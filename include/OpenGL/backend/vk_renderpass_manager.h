/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_RENDERPASS_MANAGER_H
#define VKGL_VK_RENDERPASS_MANAGER_H

#include "Common/shared_mutex.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    class VKRenderpassManager
    {
    public:
        /* Public functions */

        static VKRenderpassManagerUniquePtr create(IBackend* in_backend_ptr);

        ~VKRenderpassManager();

        Anvil::RenderPass* get_render_pass(const Anvil::RenderPassCreateInfo* in_rp_create_info_ptr);

    private:
        /* Private functions */
        VKRenderpassManager(IBackend* in_backend_ptr);

        bool is_rp_compatible(const Anvil::RenderPassCreateInfo* in_rp1_create_info_ptr,
                              const Anvil::RenderPassCreateInfo* in_rp2_create_info_ptr) const;

        /* Private variables */
        IBackend* const   m_backend_ptr;
        VKGL::SharedMutex m_rw_mutex;
    };
};

#endif /* VKGL_VK_RENDERPASS_MANAGER_H */
