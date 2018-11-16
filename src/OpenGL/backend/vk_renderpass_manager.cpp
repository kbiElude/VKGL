/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_renderpass_manager.h"
#include "Anvil/include/misc/render_pass_create_info.h"
#include "Anvil/include/wrappers/render_pass.h"

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

Anvil::RenderPass* OpenGL::VKRenderpassManager::get_render_pass(Anvil::RenderPassCreateInfoUniquePtr in_rp_create_info_ptr)
{
    Anvil::RenderPass* result_ptr = nullptr;
    const uint64_t     rp_hash    = get_rp_hash(in_rp_create_info_ptr.get() );

    m_rw_mutex.lock_shared();
    {
        auto iterator = m_renderpass_ptr_map.find(rp_hash);

        if (iterator != m_renderpass_ptr_map.end() )
        {
            result_ptr = iterator->second;
        }
    }
    m_rw_mutex.unlock_shared();

    if (result_ptr == nullptr)
    {
        m_rw_mutex.lock_unique();
        {
            auto iterator = m_renderpass_ptr_map.find(rp_hash);

            if (iterator != m_renderpass_ptr_map.end() )
            {
                result_ptr = iterator->second;
            }
            else
            {
                auto rp_ptr = Anvil::RenderPass::create(std::move(in_rp_create_info_ptr),
                                                        nullptr); /* in_opt_swapchain_ptr */

                vkgl_assert(rp_ptr != nullptr);

                m_renderpass_ptr_map[rp_hash] = rp_ptr.get();
                m_renderpass_ptrs.push_back(std::move(rp_ptr) );
            }
        }
        m_rw_mutex.unlock_unique();
    }

    vkgl_assert(result_ptr                                                  != nullptr);
    vkgl_assert(is_rp_compatible(result_ptr->get_render_pass_create_info(),
                                 in_rp_create_info_ptr.get() ) );

    return result_ptr;
}

uint64_t OpenGL::VKRenderpassManager::get_rp_hash(const Anvil::RenderPassCreateInfo* in_rp_create_info_ptr) const
{
    /* NOTE: When calculating a hash for the renderpass, we intentionally exclude all information which is irrelevant
     *       in light of renderpass compatibility rules. By doing so, we implicitly introduce support for RP reuse */
    const uint32_t n_rp_attachments = in_rp_create_info_ptr->get_n_attachments ();
    const uint32_t n_rp_deps        = in_rp_create_info_ptr->get_n_dependencies();
    const uint32_t n_rp_subpasses   = in_rp_create_info_ptr->get_n_subpasses   ();
    uint64_t       result_hash      = 0;

    vkgl_assert(in_rp_create_info_ptr != nullptr);

    result_hash  = n_rp_attachments;
    result_hash |= static_cast<uint64_t>(n_rp_deps)      << 16;
    result_hash |= static_cast<uint64_t>(n_rp_subpasses) << 32;

    for (uint32_t n_rp_attachment = 0;
                  n_rp_attachment < n_rp_attachments;
                ++n_rp_attachment)
    {
        Anvil::AttachmentType rp_attachment_type = Anvil::AttachmentType::UNKNOWN;

        if (!in_rp_create_info_ptr->get_attachment_type(n_rp_attachment,
                                                       &rp_attachment_type) )
        {
            vkgl_assert_fail();
        }

        switch (rp_attachment_type)
        {
            case Anvil::AttachmentType::COLOR:
            {
                /* NOTE: Layouts and load/store ops are irrelevant for the purpose of renderpass compatibility, so don't include them
                 *       in the hash.
                 */
                Anvil::Format              format        = Anvil::Format::UNKNOWN;
                bool                       may_alias    = false;
                Anvil::SampleCountFlagBits sample_count = Anvil::SampleCountFlagBits::NONE;

                result_hash ^= 0x123456789012345;

                in_rp_create_info_ptr->get_color_attachment_properties(n_rp_attachment,
                                                                      &format,
                                                                      &sample_count,
                                                                       nullptr, /* out_opt_load_op_ptr        */
                                                                       nullptr, /* out_opt_store_op_ptr       */
                                                                       nullptr, /* out_opt_initial_layout_ptr */
                                                                       nullptr, /* out_opt_final_layout_ptr   */
                                                                      &may_alias);

                vkgl_assert(format       != Anvil::Format::UNKNOWN);
                vkgl_assert(sample_count != Anvil::SampleCountFlagBits::NONE);

                result_hash ^= static_cast<uint64_t>(sample_count) +
                               static_cast<uint64_t>(format)       +
                               ((may_alias) ? 0xdeadf00dbabecafe : 0);

                break;
            }

            case Anvil::AttachmentType::DEPTH_STENCIL:
            {
                Anvil::Format              format       = Anvil::Format::UNKNOWN;
                bool                       may_alias    = false;
                Anvil::SampleCountFlagBits sample_count = Anvil::SampleCountFlagBits::NONE;

                result_hash ^= 0x234567890123456;

                in_rp_create_info_ptr->get_depth_stencil_attachment_properties(n_rp_attachment,
                                                                              &format,
                                                                              &sample_count,
                                                                               nullptr, /* out_opt_depth_load_op_ptr    */
                                                                               nullptr, /* out_opt_depth_store_op_ptr   */
                                                                               nullptr, /* out_opt_stencil_load_op_ptr  */
                                                                               nullptr, /* out_opt_stencil_store_op_ptr */
                                                                               nullptr, /* out_opt_initial_layout_ptr   */
                                                                               nullptr, /* out_opt_final_layout_ptr     */
                                                                              &may_alias);

                result_hash ^= static_cast<uint64_t>(sample_count) +
                               static_cast<uint64_t>(format)       +
                               ((may_alias) ? 0xf00dbabecafedead : 0);

                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }

    for (uint32_t n_rp_dep = 0;
                  n_rp_dep < n_rp_deps;
                ++n_rp_dep)
    {
        Anvil::AccessFlags        dst_access_mask = Anvil::AccessFlagBits::NONE;
        Anvil::PipelineStageFlags dst_stage_mask  = Anvil::PipelineStageFlagBits::NONE;
        Anvil::SubPassID          dst_subpass_id  = 0;
        Anvil::DependencyFlags    flags           = Anvil::DependencyFlagBits::NONE;
        Anvil::AccessFlags        src_access_mask = Anvil::AccessFlagBits::NONE;
        Anvil::PipelineStageFlags src_stage_mask  = Anvil::PipelineStageFlagBits::NONE;
        Anvil::SubPassID          src_subpass_id  = 0;

        in_rp_create_info_ptr->get_dependency_properties(n_rp_dep,
                                                        &dst_subpass_id,
                                                        &src_subpass_id,
                                                        &dst_stage_mask,
                                                        &src_stage_mask,
                                                        &dst_access_mask,
                                                        &src_access_mask,
                                                        &flags);

        result_hash ^= static_cast<uint32_t>(dst_access_mask.get_vk() );
        result_hash ^= static_cast<uint64_t>(dst_stage_mask.get_vk ()  ) << 32;
        result_hash ^= static_cast<uint32_t>(dst_subpass_id)             << 16;
        result_hash ^= static_cast<uint64_t>(flags.get_vk          () );
        result_hash ^= static_cast<uint64_t>(src_access_mask.get_vk() )  << 32;
        result_hash ^= static_cast<uint64_t>(src_stage_mask.get_vk ()  ) << 0;
        result_hash ^= static_cast<uint64_t>(src_subpass_id)             << 48;
    }

    for (uint32_t n_rp_subpass = 0;
                  n_rp_subpass < n_rp_subpasses;
                ++n_rp_subpass)
    {
        static const Anvil::AttachmentType subpass_attachment_types[] =
        {
            Anvil::AttachmentType::COLOR,
            Anvil::AttachmentType::DEPTH_STENCIL,
        };

        for (const auto& current_subpass_attachment_type : subpass_attachment_types)
        {
            uint32_t n_subpass_attachments = 0;

            if (!in_rp_create_info_ptr->get_subpass_n_attachments(n_rp_subpass,
                                                                  current_subpass_attachment_type,
                                                                 &n_subpass_attachments) )
            {
                vkgl_assert_fail();
            }

            result_hash ^= (n_subpass_attachments) << static_cast<uint32_t>(current_subpass_attachment_type);

            for (uint32_t n_subpass_attachment = 0;
                          n_subpass_attachment < n_subpass_attachments;
                        ++n_subpass_attachment)
            {
                /* NOTE: Layouts are irrelevant for RP compatibility, ignore. */
                Anvil::ImageAspectFlags       aspects_accessed = Anvil::ImageAspectFlagBits::NONE;
                Anvil::RenderPassAttachmentID rp_attachment_id = UINT32_MAX;

                if (!in_rp_create_info_ptr->get_subpass_attachment_properties(n_rp_subpass,
                                                                              current_subpass_attachment_type,
                                                                              n_subpass_attachment,
                                                                             &rp_attachment_id,
                                                                              nullptr,   /* out_layout_ptr */
                                                                             &aspects_accessed) )
                {
                    vkgl_assert_fail();

                    continue;
                }

                result_hash ^= ((1 << n_subpass_attachment)                              |
                               (rp_attachment_id                                  << 10) |
                               (static_cast<uint32_t>(aspects_accessed.get_vk() ) << 20) );
            }
        }
    }

    return result_hash;
}

bool OpenGL::VKRenderpassManager::is_rp_compatible(const Anvil::RenderPassCreateInfo* in_rp1_create_info_ptr,
                                                   const Anvil::RenderPassCreateInfo* in_rp2_create_info_ptr) const
{
    const uint32_t n_rp_attachments = in_rp1_create_info_ptr->get_n_attachments ();
    const uint32_t n_rp_deps        = in_rp1_create_info_ptr->get_n_dependencies();
    const uint32_t n_rp_subpasses   = in_rp1_create_info_ptr->get_n_subpasses   ();
    bool           result           = false;

    if (n_rp_attachments != in_rp2_create_info_ptr->get_n_attachments() )
    {
        goto end;
    }

    if (n_rp_deps != in_rp2_create_info_ptr->get_n_dependencies() )
    {
        goto end;
    }

    if (n_rp_subpasses != in_rp2_create_info_ptr->get_n_subpasses() )
    {
        goto end;
    }

    for (uint32_t n_rp_attachment = 0;
                  n_rp_attachment < n_rp_attachments;
                ++n_rp_attachment)
    {
        Anvil::AttachmentType rp1_attachment_type = Anvil::AttachmentType::UNKNOWN;
        Anvil::AttachmentType rp2_attachment_type = Anvil::AttachmentType::UNKNOWN;

        if (!in_rp1_create_info_ptr->get_attachment_type(n_rp_attachment,
                                                        &rp1_attachment_type) ||
            !in_rp2_create_info_ptr->get_attachment_type(n_rp_attachment,
                                                        &rp2_attachment_type) )
        {
            vkgl_assert_fail();
        }

        if (rp1_attachment_type != rp2_attachment_type)
        {
            goto end;
        }

        switch (rp1_attachment_type)
        {
            case Anvil::AttachmentType::COLOR:
            {
                Anvil::Format              rp1_format       = Anvil::Format::UNKNOWN;
                bool                       rp1_may_alias    = false;
                Anvil::SampleCountFlagBits rp1_sample_count = Anvil::SampleCountFlagBits::NONE;
                Anvil::Format              rp2_format       = Anvil::Format::UNKNOWN;
                bool                       rp2_may_alias    = false;
                Anvil::SampleCountFlagBits rp2_sample_count = Anvil::SampleCountFlagBits::NONE;

                in_rp1_create_info_ptr->get_color_attachment_properties(n_rp_attachment,
                                                                      &rp1_format,
                                                                      &rp1_sample_count,
                                                                       nullptr, /* out_opt_load_op_ptr        */
                                                                       nullptr, /* out_opt_store_op_ptr       */
                                                                       nullptr, /* out_opt_initial_layout_ptr */
                                                                       nullptr, /* out_opt_final_layout_ptr   */
                                                                      &rp1_may_alias);
                in_rp2_create_info_ptr->get_color_attachment_properties(n_rp_attachment,
                                                                      &rp2_format,
                                                                      &rp2_sample_count,
                                                                       nullptr, /* out_opt_load_op_ptr        */
                                                                       nullptr, /* out_opt_store_op_ptr       */
                                                                       nullptr, /* out_opt_initial_layout_ptr */
                                                                       nullptr, /* out_opt_final_layout_ptr   */
                                                                      &rp2_may_alias);

                if (rp1_format       != rp2_format       ||
                    rp1_sample_count != rp1_sample_count ||
                    rp1_may_alias    != rp2_may_alias)
                {
                    goto end;
                }

                break;
            }

            case Anvil::AttachmentType::DEPTH_STENCIL:
            {
                Anvil::Format              rp1_format       = Anvil::Format::UNKNOWN;
                bool                       rp1_may_alias    = false;
                Anvil::SampleCountFlagBits rp1_sample_count = Anvil::SampleCountFlagBits::NONE;
                Anvil::Format              rp2_format       = Anvil::Format::UNKNOWN;
                bool                       rp2_may_alias    = false;
                Anvil::SampleCountFlagBits rp2_sample_count = Anvil::SampleCountFlagBits::NONE;

                in_rp1_create_info_ptr->get_depth_stencil_attachment_properties(n_rp_attachment,
                                                                               &rp1_format,
                                                                               &rp1_sample_count,
                                                                                nullptr, /* out_opt_depth_load_op_ptr    */
                                                                                nullptr, /* out_opt_depth_store_op_ptr   */
                                                                                nullptr, /* out_opt_stencil_load_op_ptr  */
                                                                                nullptr, /* out_opt_stencil_store_op_ptr */
                                                                                nullptr, /* out_opt_initial_layout_ptr   */
                                                                                nullptr, /* out_opt_final_layout_ptr     */
                                                                               &rp1_may_alias);
                in_rp2_create_info_ptr->get_depth_stencil_attachment_properties(n_rp_attachment,
                                                                               &rp2_format,
                                                                               &rp2_sample_count,
                                                                                nullptr, /* out_opt_depth_load_op_ptr    */
                                                                                nullptr, /* out_opt_depth_store_op_ptr   */
                                                                                nullptr, /* out_opt_stencil_load_op_ptr  */
                                                                                nullptr, /* out_opt_stencil_store_op_ptr */
                                                                                nullptr, /* out_opt_initial_layout_ptr   */
                                                                                nullptr, /* out_opt_final_layout_ptr     */
                                                                               &rp2_may_alias);

                if (rp1_format       != rp2_format       ||
                    rp1_may_alias    != rp2_may_alias    ||
                    rp1_sample_count != rp2_sample_count)
                {
                    goto end;
                }

                break;
            }

            default:
            {
                vkgl_assert_fail();
            }
        }
    }

    for (uint32_t n_rp_dep = 0;
                  n_rp_dep < n_rp_deps;
                ++n_rp_dep)
    {
        Anvil::AccessFlags        rp1_dst_access_mask = Anvil::AccessFlagBits::NONE;
        Anvil::PipelineStageFlags rp1_dst_stage_mask  = Anvil::PipelineStageFlagBits::NONE;
        Anvil::SubPassID          rp1_dst_subpass_id  = 0;
        Anvil::DependencyFlags    rp1_flags           = Anvil::DependencyFlagBits::NONE;
        Anvil::AccessFlags        rp1_src_access_mask = Anvil::AccessFlagBits::NONE;
        Anvil::PipelineStageFlags rp1_src_stage_mask  = Anvil::PipelineStageFlagBits::NONE;
        Anvil::SubPassID          rp1_src_subpass_id  = 0;
        Anvil::AccessFlags        rp2_dst_access_mask = Anvil::AccessFlagBits::NONE;
        Anvil::PipelineStageFlags rp2_dst_stage_mask  = Anvil::PipelineStageFlagBits::NONE;
        Anvil::SubPassID          rp2_dst_subpass_id  = 0;
        Anvil::DependencyFlags    rp2_flags           = Anvil::DependencyFlagBits::NONE;
        Anvil::AccessFlags        rp2_src_access_mask = Anvil::AccessFlagBits::NONE;
        Anvil::PipelineStageFlags rp2_src_stage_mask  = Anvil::PipelineStageFlagBits::NONE;
        Anvil::SubPassID          rp2_src_subpass_id  = 0;

        in_rp1_create_info_ptr->get_dependency_properties(n_rp_dep,
                                                         &rp1_dst_subpass_id,
                                                         &rp1_src_subpass_id,
                                                         &rp1_dst_stage_mask,
                                                         &rp1_src_stage_mask,
                                                         &rp1_dst_access_mask,
                                                         &rp1_src_access_mask,
                                                         &rp1_flags);
        in_rp2_create_info_ptr->get_dependency_properties(n_rp_dep,
                                                         &rp2_dst_subpass_id,
                                                         &rp2_src_subpass_id,
                                                         &rp2_dst_stage_mask,
                                                         &rp2_src_stage_mask,
                                                         &rp2_dst_access_mask,
                                                         &rp2_src_access_mask,
                                                         &rp2_flags);

        if (rp1_dst_subpass_id  != rp2_dst_subpass_id  ||
            rp1_src_subpass_id  != rp2_src_subpass_id  ||
            rp1_dst_stage_mask  != rp2_dst_stage_mask  ||
            rp1_src_stage_mask  != rp2_src_stage_mask  ||
            rp1_dst_access_mask != rp2_dst_access_mask ||
            rp1_src_access_mask != rp2_src_access_mask ||
            rp1_flags           != rp2_flags)
        {
            goto end;
        }
    }

    for (uint32_t n_rp_subpass = 0;
                  n_rp_subpass < n_rp_subpasses;
                ++n_rp_subpass)
    {
        static const Anvil::AttachmentType subpass_attachment_types[] =
        {
            Anvil::AttachmentType::COLOR,
            Anvil::AttachmentType::DEPTH_STENCIL,
        };

        for (const auto& current_subpass_attachment_type : subpass_attachment_types)
        {
            uint32_t n_rp1_subpass_attachments = 0;
            uint32_t n_rp2_subpass_attachments = 0;

            if (!in_rp1_create_info_ptr->get_subpass_n_attachments(n_rp_subpass,
                                                                   current_subpass_attachment_type,
                                                                  &n_rp1_subpass_attachments)      ||
                !in_rp2_create_info_ptr->get_subpass_n_attachments(n_rp_subpass,
                                                                   current_subpass_attachment_type,
                                                                  &n_rp2_subpass_attachments) )
            {
                vkgl_assert_fail();
            }

            if (n_rp1_subpass_attachments != n_rp2_subpass_attachments)
            {
                goto end;
            }

            for (uint32_t n_subpass_attachment = 0;
                          n_subpass_attachment < n_rp1_subpass_attachments;
                        ++n_subpass_attachment)
            {
                /* NOTE: Layouts are irrelevant for RP compatibility, ignore. */
                Anvil::ImageAspectFlags       rp1_aspects_accessed = Anvil::ImageAspectFlagBits::NONE;
                Anvil::RenderPassAttachmentID rp1_attachment_id = UINT32_MAX;
                Anvil::ImageAspectFlags       rp2_aspects_accessed = Anvil::ImageAspectFlagBits::NONE;
                Anvil::RenderPassAttachmentID rp2_attachment_id = UINT32_MAX;

                if (!in_rp1_create_info_ptr->get_subpass_attachment_properties(n_rp_subpass,
                                                                               current_subpass_attachment_type,
                                                                               n_subpass_attachment,
                                                                              &rp1_attachment_id,
                                                                               nullptr,   /* out_layout_ptr */
                                                                              &rp1_aspects_accessed) ||
                    !in_rp2_create_info_ptr->get_subpass_attachment_properties(n_rp_subpass,
                                                                               current_subpass_attachment_type,
                                                                               n_subpass_attachment,
                                                                              &rp2_attachment_id,
                                                                               nullptr,   /* out_layout_ptr */
                                                                              &rp2_aspects_accessed) )
                {
                    vkgl_assert_fail();

                    continue;
                }

                if (rp1_aspects_accessed != rp2_aspects_accessed ||
                    rp1_attachment_id    != rp2_attachment_id)
                {
                    goto end;
                }
            }
        }
    }

    result = true;
end:
    return result;
}