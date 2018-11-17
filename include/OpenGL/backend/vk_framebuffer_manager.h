/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_FRAMEBUFFER_MANAGER_H
#define VKGL_VK_FRAMEBUFFER_MANAGER_H

#include "Common/shared_mutex.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    class VKFramebufferManager
    {
    public:
        /* Public functions */
        static VKFramebufferManagerUniquePtr create(IBackend* in_backend_ptr);

        Anvil::Framebuffer* get_framebuffer(const std::vector<Anvil::ImageView*>& in_attachments_ptr,
                                            const uint32_t&                       in_width,
                                            const uint32_t&                       in_height,
                                            const uint32_t&                       in_n_layers,
                                            const Anvil::RenderPass*              in_rp_ptr);

        ~VKFramebufferManager();

    private:
        /* Private type definitions */
        typedef struct FramebufferData
        {
            std::vector<Anvil::ImageView*> attachment_ptrs;
            Anvil::FramebufferUniquePtr    framebuffer_ptr;
            const Anvil::RenderPass*       renderpass_ptr;

            FramebufferData(const Anvil::RenderPass* in_renderpass_ptr)
                :renderpass_ptr(in_renderpass_ptr)
            {
                vkgl_assert(renderpass_ptr != nullptr);
            }
        } FramebufferData;

        /* Private functions */
        VKFramebufferManager(IBackend* in_backend_ptr);

        uint64_t get_framebuffer_hash(const uint32_t&          in_n_attachments,
                                      const uint32_t&          in_width,
                                      const uint32_t&          in_height,
                                      const uint32_t&          in_n_layers,
                                      const Anvil::RenderPass* in_rp_ptr) const;

        /* Private variables */
        IBackend* const m_backend_ptr;

        std::unordered_map<uint64_t, std::vector<std::unique_ptr<FramebufferData> > > m_framebuffer_ptr_map;
        VKGL::SharedMutex                                                             m_rw_mutex;
    };
}
#endif /* VKGL_VK_FRAMEBUFFER_MANAGER_H */
