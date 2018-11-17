/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/framebuffer_create_info.h"
#include "Anvil/include/wrappers/framebuffer.h"
#include "Anvil/include/wrappers/render_pass.h"
#include "OpenGL/backend/vk_framebuffer_manager.h"
#include "OpenGL/backend/vk_renderpass_manager.h"

OpenGL::VKFramebufferManager::VKFramebufferManager(IBackend* in_backend_ptr)
    :m_backend_ptr(in_backend_ptr)
{
    vkgl_assert(in_backend_ptr != nullptr);
}

OpenGL::VKFramebufferManager::~VKFramebufferManager()
{
    /* Stub for now */
}

OpenGL::VKFramebufferManagerUniquePtr OpenGL::VKFramebufferManager::create(IBackend* in_backend_ptr)
{
    OpenGL::VKFramebufferManagerUniquePtr result_ptr;

    result_ptr.reset(new VKFramebufferManager(in_backend_ptr) );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

Anvil::Framebuffer* OpenGL::VKFramebufferManager::get_framebuffer(const std::vector<Anvil::ImageView*>& in_attachments_ptr,
                                                                  const uint32_t&                       in_width,
                                                                  const uint32_t&                       in_height,
                                                                  const uint32_t&                       in_n_layers,
                                                                  const Anvil::RenderPass*              in_rp_ptr)
{
    const auto          fb_hash    = get_framebuffer_hash(static_cast<uint32_t>(in_attachments_ptr.size() ),
                                                          in_width,
                                                          in_height,
                                                          in_n_layers,
                                                          in_rp_ptr);
    Anvil::Framebuffer* result_ptr = nullptr;

    for (uint32_t n_iteration = 0;
                  n_iteration < 2 && (result_ptr == nullptr); /* shared access / unique access */
                ++n_iteration)
    {
        if (n_iteration == 0)
        {
            m_rw_mutex.lock_shared();
        }
        else
        {
            m_rw_mutex.lock_unique();
        }
        {
            const auto map_iterator = m_framebuffer_ptr_map.find(fb_hash);

            if (map_iterator != m_framebuffer_ptr_map.end() )
            {
                const auto& fb_data_ptr_vec = map_iterator->second;

                for (const auto& current_fb_data_ptr : fb_data_ptr_vec)
                {
                    vkgl_assert(OpenGL::VKRenderpassManager::is_rp_compatible(current_fb_data_ptr->renderpass_ptr->get_render_pass_create_info(),
                                                                              in_rp_ptr->get_render_pass_create_info                          () ) );

                    if (current_fb_data_ptr->attachment_ptrs == in_attachments_ptr)
                    {
                        result_ptr = current_fb_data_ptr->framebuffer_ptr.get();

                        break;
                    }
                }
            }

            if (result_ptr  == nullptr &&
                n_iteration == 1)
            {
                auto                             fb_create_info_ptr = Anvil::FramebufferCreateInfo::create(m_backend_ptr->get_device_ptr(),
                                                                                                           in_width,
                                                                                                           in_height,
                                                                                                           in_n_layers);
                std::unique_ptr<FramebufferData> result_fb_data_ptr;
                Anvil::FramebufferUniquePtr      result_fb_ptr;

                vkgl_assert(fb_create_info_ptr != nullptr);

                for (auto& current_attachment_ptr : in_attachments_ptr)
                {
                    fb_create_info_ptr->add_attachment(current_attachment_ptr,
                                                       nullptr); /* out_opt_attachment_id_ptr */
                }

                result_fb_ptr = Anvil::Framebuffer::create(std::move(fb_create_info_ptr) );
                result_ptr    = result_fb_ptr.get();
                vkgl_assert(result_fb_ptr != nullptr);

                result_fb_data_ptr.reset(new FramebufferData(in_rp_ptr) );
                vkgl_assert(result_fb_data_ptr != nullptr);

                result_fb_data_ptr->attachment_ptrs = in_attachments_ptr;
                result_fb_data_ptr->framebuffer_ptr = std::move(result_fb_ptr);

                m_framebuffer_ptr_map[fb_hash].push_back(std::move(result_fb_data_ptr) );
            }
        }
        if (n_iteration == 0)
        {
            m_rw_mutex.unlock_shared();
        }
        else
        {
            m_rw_mutex.unlock_unique();
        }
    }

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

uint64_t OpenGL::VKFramebufferManager::get_framebuffer_hash(const uint32_t&          in_n_attachments,
                                                            const uint32_t&          in_width,
                                                            const uint32_t&          in_height,
                                                            const uint32_t&          in_n_layers,
                                                            const Anvil::RenderPass* in_rp_ptr) const
{
    uint64_t hash = 0;

    hash |= static_cast<uint64_t>(in_width);
    hash |= static_cast<uint64_t>(in_height)        << 14;
    hash |= static_cast<uint64_t>(in_n_layers)      << 28;
    hash |= static_cast<uint64_t>(in_n_attachments) << 42;

    hash ^= OpenGL::VKRenderpassManager::get_rp_hash(in_rp_ptr->get_render_pass_create_info() );

    return hash;
}
