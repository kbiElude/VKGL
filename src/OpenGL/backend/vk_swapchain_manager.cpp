/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/formats.h"
#include "Anvil/include/misc/image_create_info.h"
#include "Anvil/include/misc/image_view_create_info.h"
#include "Anvil/include/misc/memory_allocator.h"
#include "Anvil/include/misc/semaphore_create_info.h"
#include "Anvil/include/misc/swapchain_create_info.h"
#include "Anvil/include/misc/window_factory.h"
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/image.h"
#include "Anvil/include/wrappers/image_view.h"
#include "Anvil/include/wrappers/rendering_surface.h"
#include "Anvil/include/wrappers/semaphore.h"
#include "Anvil/include/wrappers/swapchain.h"
#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_swapchain_manager.h"
#include "OpenGL/frontend/gl_formats.h"
#include "OpenGL/frontend/snapshot_manager.h"
#include "Common/logger.h"
#include "Common/macros.h"

OpenGL::VKSwapchainManager::VKSwapchainManager(OpenGL::IBackend*                    in_backend_ptr,
                                               const uint32_t&                      in_n_swapchain_images,
                                               const VKGL::PixelFormatRequirements& in_pixel_format_reqs)
    :m_backend_ptr              (in_backend_ptr),
     m_n_swapchain_images       (in_n_swapchain_images),
     m_pixel_format_reqs        (in_pixel_format_reqs),
     m_should_recreate_swapchain(false)
{
    vkgl_assert(m_backend_ptr        != nullptr);
    vkgl_assert(m_n_swapchain_images != 0);
}

OpenGL::VKSwapchainManager::~VKSwapchainManager()
{
}

OpenGL::VKSwapchainReferenceUniquePtr OpenGL::VKSwapchainManager::acquire_swapchain(const OpenGL::TimeMarker& in_time_marker)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    decltype(m_time_marker_to_internal_swapchain_data_map)::const_iterator internal_swapchain_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);
    OpenGL::VKSwapchainReferenceUniquePtr                                  result_ptr;
    auto                                                                   snapshot_ptr                     = reinterpret_cast<const SwapchainPropsSnapshot*>  (m_snapshot_manager_ptr->get_readonly_snapshot(in_time_marker) );

    if (snapshot_ptr == nullptr)
    {
        vkgl_assert(snapshot_ptr != nullptr);

        goto end;
    }

    if (internal_swapchain_data_iterator == m_time_marker_to_internal_swapchain_data_map.end() ||
        m_should_recreate_swapchain)
    {
        if (m_should_recreate_swapchain)
        {
            vkgl_assert(m_time_marker_to_internal_swapchain_data_map.find(in_time_marker) != m_time_marker_to_internal_swapchain_data_map.end() );
        }

        auto internal_data_ptr = create_swapchain(snapshot_ptr,
                                                  (m_should_recreate_swapchain) ? std::move(m_time_marker_to_internal_swapchain_data_map[in_time_marker])
                                                                                : InternalSwapchainDataUniquePtr() );

        if (internal_data_ptr == nullptr)
        {
            vkgl_assert(internal_data_ptr != nullptr);

            goto end;
        }

        m_backend_ptr->get_frame_graph_ptr()->on_swapchain_recreated();

        m_should_recreate_swapchain                                  = false;
        m_time_marker_to_internal_swapchain_data_map[in_time_marker] = std::move(internal_data_ptr);
        internal_swapchain_data_iterator                             = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);

        vkgl_assert(internal_swapchain_data_iterator != m_time_marker_to_internal_swapchain_data_map.end() );
    }

    result_ptr = m_snapshot_manager_ptr->acquire_reference(
        OpenGL::VKSwapchainPayload(internal_swapchain_data_iterator->second->swapchain_ptr.get(),
                                   in_time_marker)
    );

    vkgl_assert(result_ptr != nullptr);
end:
    return result_ptr;
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::VKSwapchainManager::clone_internal_data_object(const void* in_ptr)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){ delete reinterpret_cast<SwapchainPropsSnapshot*>(in_ptr); });

    result_ptr.reset(
        new SwapchainPropsSnapshot(*reinterpret_cast<const SwapchainPropsSnapshot*>(in_ptr) )
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void OpenGL::VKSwapchainManager::copy_internal_data_object(const void* in_src_ptr,
                                                           void*       in_dst_ptr)
{
    memcpy(in_dst_ptr,
           in_src_ptr,

           sizeof(SwapchainPropsSnapshot) );
}

OpenGL::VKSwapchainManagerUniquePtr OpenGL::VKSwapchainManager::create(IBackend*                            in_backend_ptr,
                                                                       const uint32_t&                      in_n_swapchain_images,
                                                                       const VKGL::PixelFormatRequirements& in_pixel_format_reqs)
{
    OpenGL::VKSwapchainManagerUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::VKSwapchainManager(in_backend_ptr,
                                                    in_n_swapchain_images,
                                                    in_pixel_format_reqs) );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

bool OpenGL::VKSwapchainManager::create_ds_image_views(const Anvil::Format&                    in_format,
                                                       const uint32_t&                         in_width,
                                                       const uint32_t&                         in_height,
                                                       std::vector<Anvil::ImageUniquePtr>&     out_ds_image_ptrs,
                                                       std::vector<Anvil::ImageViewUniquePtr>& out_ds_image_view_ptrs) const
{
    auto       allocator_ptr       = m_backend_ptr->get_memory_allocator_ptr();
    auto       device_ptr          = dynamic_cast<Anvil::SGPUDevice*>(m_backend_ptr->get_device_ptr() );
    bool       result              = false;
    const bool uses_depth_aspect   = Anvil::Formats::has_depth_aspect  (in_format);
    const bool uses_stencil_aspect = Anvil::Formats::has_stencil_aspect(in_format);

    vkgl_assert(allocator_ptr                 != nullptr);
    vkgl_assert(m_n_swapchain_images          != 0);
    vkgl_assert(out_ds_image_ptrs.size     () == 0);
    vkgl_assert(out_ds_image_view_ptrs.size() == 0);

    for (uint32_t n_image = 0;
                  n_image < m_n_swapchain_images;
                ++n_image)
    {
        auto image_create_info_ptr = Anvil::ImageCreateInfo::create_no_alloc(device_ptr,
                                                                             Anvil::ImageType::_2D,
                                                                             in_format,
                                                                             Anvil::ImageTiling::OPTIMAL,
                                                                             Anvil::ImageUsageFlagBits::DEPTH_STENCIL_ATTACHMENT_BIT,
                                                                             in_width,
                                                                             in_height,
                                                                             1, /* in_base_mipmap_depth */
                                                                             1, /* in_n_layers          */
                                                                             Anvil::SampleCountFlagBits::_1_BIT,
                                                                             Anvil::QueueFamilyFlagBits::COMPUTE_BIT | Anvil::QueueFamilyFlagBits::GRAPHICS_BIT | Anvil::QueueFamilyFlagBits::DMA_BIT,
                                                                             Anvil::SharingMode::EXCLUSIVE,
                                                                             false, /* in_use_full_mipmap_chain */
                                                                             Anvil::ImageCreateFlagBits::NONE);
        auto image_ptr              = Anvil::Image::create                  (std::move(image_create_info_ptr) );

        if (image_ptr == nullptr)
        {
            vkgl_assert(image_ptr != nullptr);

            goto end;
        }

        allocator_ptr->add_image_whole(image_ptr.get(),
                                       Anvil::MemoryFeatureFlagBits::DEVICE_LOCAL_BIT);

        out_ds_image_ptrs.push_back(std::move(image_ptr) );
    }

    for (uint32_t n_image_view = 0;
                  n_image_view < m_n_swapchain_images;
                ++n_image_view)
    {
        auto create_info_ptr = Anvil::ImageViewCreateInfo::create_2D(device_ptr,
                                                                     out_ds_image_ptrs.at(n_image_view).get(),
                                                                     0, /* in_n_base_layer */
                                                                     0, /* in_n_base_mipmap_level */
                                                                     1, /* in_n_mimaps */
                                                                     ((uses_depth_aspect)   ? Anvil::ImageAspectFlagBits::DEPTH_BIT   : Anvil::ImageAspectFlagBits::NONE) |
                                                                     ((uses_stencil_aspect) ? Anvil::ImageAspectFlagBits::STENCIL_BIT : Anvil::ImageAspectFlagBits::NONE),
                                                                     in_format,
                                                                     Anvil::ComponentSwizzle::IDENTITY, /* in_swizzle_red   */
                                                                     Anvil::ComponentSwizzle::IDENTITY, /* in_swizzle_green */
                                                                     Anvil::ComponentSwizzle::IDENTITY, /* in_swizzle_blue  */
                                                                     Anvil::ComponentSwizzle::IDENTITY);/* in_swizzle_alpha */
        auto image_view_ptr  = Anvil::ImageView::create             (std::move(create_info_ptr) );

        if (image_view_ptr == nullptr)
        {
            vkgl_assert(image_view_ptr != nullptr);

            goto end;
        }

        out_ds_image_view_ptrs.push_back(std::move(image_view_ptr) );
    }

    /* All done */
    result = true;
end:
    return result;
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::VKSwapchainManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){ delete reinterpret_cast<SwapchainPropsSnapshot*>(in_ptr); });

    result_ptr.reset(
        new SwapchainPropsSnapshot()
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

OpenGL::VKSwapchainManager::InternalSwapchainDataUniquePtr OpenGL::VKSwapchainManager::create_swapchain(const SwapchainPropsSnapshot*  in_swapchain_props_ptr,
                                                                                                        InternalSwapchainDataUniquePtr in_opt_former_swapchain_data_ptr) const
{
    auto                                   device_ptr                  = m_backend_ptr->get_device_ptr();
    std::vector<Anvil::ImageUniquePtr>     ds_images;
    std::vector<Anvil::ImageViewUniquePtr> ds_image_views;
    auto                                   format_manager_ptr          = m_backend_ptr->get_format_manager_ptr();
    std::vector<Anvil::SemaphoreUniquePtr> frame_acquire_sems;
    InternalSwapchainDataUniquePtr         internal_swapchain_data_ptr;
    const bool                             is_recreate_request         = (in_opt_former_swapchain_data_ptr != nullptr);
    std::vector<Anvil::Queue*>             presentable_queue_ptrs;
    Anvil::RenderingSurfaceUniquePtr       rendering_surface_ptr;
    Anvil::SwapchainUniquePtr              swapchain_ptr;
    Anvil::WindowUniquePtr                 window_ptr;

    vkgl_assert(device_ptr != nullptr);

    if (is_recreate_request)
    {
        if (in_opt_former_swapchain_data_ptr->outdated_swapchain_data_item_ptrs.size() > 0)
        {
            /* Swapchain is only recreated (if necessary) at swapchain creation time. Any other entrypoint that returns suboptimal
             * or out-of-date status for current swapchain will set a "reset swapchain" flag but will continue to use an already
             * acquired swapchain until presentation time.
             *
             * Hence, if we reached this point, a swapchain presentation request (vkQueuePresentKHR() ) must have already been dispatched
             * for the outdated swapchain. Therefore, it's fine to release the swapchain at this point.
             *
             * NOTE: There could STILL be cmd buffers in flight which refer to image views created off the deprecated swapchain. A wait-idle
             *       call is a safeguard against these situations. It's ugly but swapchain resize events are not expected to happen at time-critical
             *       moments of app lifetime.
             */
            device_ptr->wait_idle();

            in_opt_former_swapchain_data_ptr->outdated_swapchain_data_item_ptrs.erase(in_opt_former_swapchain_data_ptr->outdated_swapchain_data_item_ptrs.begin() );
        }
    }

    /* 1. Create a window wrapper for the window handle specified by the app. */
    if (!is_recreate_request)
    {
        window_ptr = Anvil::WindowFactory::create_window(Anvil::WINDOW_PLATFORM_SYSTEM,
                                                         in_swapchain_props_ptr->window_handle);

        if (window_ptr == nullptr)
        {
            vkgl_assert(window_ptr != nullptr);

            goto end;
        }
    }
    else
    {
        /* Re-use the window instance we already created */
        window_ptr = std::move(in_opt_former_swapchain_data_ptr->window_ptr);

        vkgl_assert(window_ptr != nullptr);
    }

    /* 2. Create a rendering surface for the window */
    if (!is_recreate_request)
    {
        /* FIXME: Anvil interface flaw - fix Anvil-side and then get rid of the const_cast */
        rendering_surface_ptr = Anvil::RenderingSurface::create(const_cast<Anvil::Instance*>(device_ptr->get_parent_instance() ),
                                                                device_ptr,
                                                                window_ptr.get(),
                                                                Anvil::MTSafety::DISABLED);

        if (rendering_surface_ptr == nullptr)
        {
            vkgl_assert(rendering_surface_ptr != nullptr);

            goto end;
        }
    }
    else
    {
        /* Re-use the already created instance. */
        rendering_surface_ptr = std::move(in_opt_former_swapchain_data_ptr->rendering_surface_ptr);

        vkgl_assert(rendering_surface_ptr != nullptr);
    }

    /* 3. Create the swapchain */
    {
        Anvil::SwapchainCreateInfoUniquePtr create_info_ptr;
        const Anvil::ImageUsageFlags        image_usage_flags = get_swapchain_image_usage_flags     (rendering_surface_ptr.get() );
        const Anvil::PresentModeKHR         present_mode      = get_present_mode_for_swapchain_props(in_swapchain_props_ptr,
                                                                                                     rendering_surface_ptr.get() );
        const Anvil::Format                 swapchain_format  = get_swapchain_format                (in_swapchain_props_ptr,
                                                                                                     rendering_surface_ptr.get());

        create_info_ptr = Anvil::SwapchainCreateInfo::create(device_ptr,
                                                             rendering_surface_ptr.get(),
                                                             window_ptr.get           (),
                                                             swapchain_format,
                                                             Anvil::ColorSpaceKHR::SRGB_NONLINEAR_KHR, //< TODO: prettify me
                                                             present_mode,
                                                             image_usage_flags,
                                                             m_n_swapchain_images,
                                                             true, /* in_clipped */
                                                             (is_recreate_request) ? in_opt_former_swapchain_data_ptr->swapchain_ptr.get()
                                                                                   : nullptr);

        if (create_info_ptr == nullptr)
        {
            vkgl_assert(create_info_ptr != nullptr);

            goto end;
        }

        swapchain_ptr = Anvil::Swapchain::create(std::move(create_info_ptr) );

        if (swapchain_ptr == nullptr)
        {
            vkgl_assert(swapchain_ptr != nullptr);

            goto end;
        }
    }

    /* 4. Create D/DS/S image & image views, if such were requested for the rendering surface */
    if (m_pixel_format_reqs.n_depth_bits   != 0 ||
        m_pixel_format_reqs.n_stencil_bits != 0)
    {
        auto          format_gl = OpenGL::GLFormats::get_best_fit_ds_internal_format(m_pixel_format_reqs.n_depth_bits,
                                                                                     m_pixel_format_reqs.n_stencil_bits);
        Anvil::Format format_vk = Anvil::Format::UNKNOWN;

        if (format_gl == OpenGL::InternalFormat::Unknown)
        {
            vkgl_assert(format_gl != OpenGL::InternalFormat::Unknown);

            goto end;
        }

        format_vk = format_manager_ptr->get_best_fit_anvil_format(format_gl,
                                                                  Anvil::FormatFeatureFlagBits::DEPTH_STENCIL_ATTACHMENT_BIT); //< TODO: is this good enough?

        if (format_vk == Anvil::Format::UNKNOWN)
        {
            vkgl_assert(format_vk != Anvil::Format::UNKNOWN);

            goto end;
        }

        if (!create_ds_image_views(format_vk,
                                   window_ptr->get_width_at_creation_time (),
                                   window_ptr->get_height_at_creation_time(),
                                   ds_images,
                                   ds_image_views) )
        {
            vkgl_assert_fail();

            goto end;
        }
    }

    /* 5. Instantiate semaphores we're going to use for frame acquisition purposes.
     *
     * NOTE: Yes, semaphores in Vulkan are NOT recyclable. However, Anvil provides a nifty reset method
     *       which handles the recreation process under the hood. And we get RAII for free.
     */
    for (uint32_t n_semaphore = 0;
                  n_semaphore < m_n_swapchain_images;
                ++n_semaphore)
    {
        auto create_info_ptr = Anvil::SemaphoreCreateInfo::create(device_ptr);
        auto semaphore_ptr   = Anvil::Semaphore::create          (std::move(create_info_ptr) );

        if (semaphore_ptr == nullptr)
        {
            vkgl_assert(semaphore_ptr != nullptr);

            goto end;
        }

        frame_acquire_sems.push_back(std::move(semaphore_ptr) );
    }

    /* 6. Cache all queues which can be used for presentation purposes */
    if (!is_recreate_request)
    {
        auto                         device_sgpu_ptr                     = dynamic_cast<Anvil::SGPUDevice*>(device_ptr);
        const std::vector<uint32_t>* presentable_queue_fam_index_vec_ptr = nullptr;

        if (!rendering_surface_ptr->get_queue_families_with_present_support(device_sgpu_ptr->get_physical_device(),
                                                                           &presentable_queue_fam_index_vec_ptr) )
        {
            vkgl_assert_fail();

            goto end;
        }

        for (const auto& current_queue_fam_index : *presentable_queue_fam_index_vec_ptr)
        {
            const auto n_queues = device_ptr->get_n_queues(current_queue_fam_index);

            for (uint32_t n_queue = 0;
                          n_queue < n_queues;
                        ++n_queue)
            {
                auto current_queue_ptr = device_ptr->get_queue_for_queue_family_index(current_queue_fam_index,
                                                                                      n_queue);

                vkgl_assert(current_queue_ptr != nullptr);
                vkgl_assert(std::find(presentable_queue_ptrs.begin(),
                                      presentable_queue_ptrs.end  (),
                                      current_queue_ptr)             == presentable_queue_ptrs.end() );

                presentable_queue_ptrs.push_back(current_queue_ptr);
            }
        }
    }
    else
    {
        presentable_queue_ptrs = in_opt_former_swapchain_data_ptr->presentable_queue_ptrs;
    }

    /* 7. Pack all the stuff together. */
    internal_swapchain_data_ptr.reset(
        new InternalSwapchainData(std::move(rendering_surface_ptr),
                                  std::move(swapchain_ptr),
                                  std::move(window_ptr),
                                  presentable_queue_ptrs,
                                  frame_acquire_sems,
                                  ds_images,
                                  ds_image_views)
    );

    if (internal_swapchain_data_ptr == nullptr)
    {
        vkgl_assert(internal_swapchain_data_ptr != nullptr);

        goto end;
    }

    if (is_recreate_request)
    {
        internal_swapchain_data_ptr->outdated_swapchain_data_item_ptrs = std::move(in_opt_former_swapchain_data_ptr->outdated_swapchain_data_item_ptrs);

        internal_swapchain_data_ptr->outdated_swapchain_data_item_ptrs.push_back(std::move(in_opt_former_swapchain_data_ptr) );
    }

    /* Done */
end:
    return internal_swapchain_data_ptr;
}

Anvil::Image* OpenGL::VKSwapchainManager::get_ds_image(const OpenGL::TimeMarker& in_time_marker,
                                                       const uint32_t&           in_n_swapchain_image)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto internal_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);
    vkgl_assert(internal_data_iterator != m_time_marker_to_internal_swapchain_data_map.end() );

    vkgl_assert(internal_data_iterator->second->ds_image_ptrs.size() > in_n_swapchain_image);
    return internal_data_iterator->second->ds_image_ptrs.at(in_n_swapchain_image).get();
}

Anvil::ImageView* OpenGL::VKSwapchainManager::get_ds_image_view(const OpenGL::TimeMarker& in_time_marker,
                                                                const uint32_t&           in_n_swapchain_image)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto internal_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);
    vkgl_assert(internal_data_iterator != m_time_marker_to_internal_swapchain_data_map.end() );

    vkgl_assert(internal_data_iterator->second->ds_image_view_ptrs.size() > in_n_swapchain_image);
    return internal_data_iterator->second->ds_image_view_ptrs.at(in_n_swapchain_image).get();
}

Anvil::PresentModeKHR OpenGL::VKSwapchainManager::get_present_mode_for_swapchain_props(const SwapchainPropsSnapshot*  in_swapchain_props_ptr,
                                                                                       const Anvil::RenderingSurface* in_surface_ptr) const
{
    Anvil::PresentModeKHR result = Anvil::PresentModeKHR::UNKNOWN;

    /* What's the preferred present mode, given swap interval setting? */
    if (in_swapchain_props_ptr->swap_interval == 0)
    {
        result = Anvil::PresentModeKHR::IMMEDIATE_KHR;
    }
    else
    if (in_swapchain_props_ptr->swap_interval == 1)
    {
        result = Anvil::PresentModeKHR::FIFO_KHR;
    }
    else
    {
        /* TODO: We do NOT report support for EXT_swap_control_tear yet. */
        vkgl_assert(in_swapchain_props_ptr->swap_interval == -1);

        result = Anvil::PresentModeKHR::FIFO_RELAXED_KHR;
    }

    /* Is the preferred present mode supported? */
    {
        bool is_supported = false;

        if (!in_surface_ptr->supports_presentation_mode(dynamic_cast<Anvil::SGPUDevice*>(m_backend_ptr->get_device_ptr() )->get_physical_device(),
                                                        result,
                                                       &is_supported) )
        {
            vkgl_assert_fail();

            goto end;
        }

        if (!is_supported)
        {
            /* Fall back to FIFO_KHR which should be available everywhere we care..? */
            VKGL::g_logger_ptr->log(VKGL::LogLevel::Warning,
                                    "Requested present mode is unavailable. Falling back to FIFO_KHR");

            result = Anvil::PresentModeKHR::FIFO_KHR;

            if (in_surface_ptr->supports_presentation_mode(dynamic_cast<Anvil::SGPUDevice*>(m_backend_ptr->get_device_ptr() )->get_physical_device(),
                                                           result,
                                                          &is_supported) )
            {
                vkgl_assert(is_supported);
            }
        }
    }

end:
    return result;
}

Anvil::Queue* OpenGL::VKSwapchainManager::get_presentable_queue(const OpenGL::TimeMarker& in_time_marker)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto internal_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);

    vkgl_assert(internal_data_iterator != m_time_marker_to_internal_swapchain_data_map.end() );

    /* Push the ring buffer start index.. */
    internal_data_iterator->second->n_last_returned_presentable_queue = (1 + internal_data_iterator->second->n_last_returned_presentable_queue) % internal_data_iterator->second->presentable_queue_ptrs.size();

    /* Return the queue */
    return internal_data_iterator->second->presentable_queue_ptrs.at(internal_data_iterator->second->n_last_returned_presentable_queue);
}

Anvil::Format OpenGL::VKSwapchainManager::get_swapchain_format(const SwapchainPropsSnapshot*  in_swapchain_props_ptr,
                                                               const Anvil::RenderingSurface* in_surface_ptr) const
{
    /* TODO: For now, stick to BGRA8_UNORM.
     *
     *       We should actually be picking a supported format which most closely matches the requested configuration.
     */
    Anvil::Format result = Anvil::Format::B8G8R8A8_UNORM;

    vkgl_assert(m_pixel_format_reqs.n_blue_bits  == 8);
    vkgl_assert(m_pixel_format_reqs.n_green_bits == 8);
    vkgl_assert(m_pixel_format_reqs.n_red_bits   == 8);

    {
        bool format_accepted = false;

        vkgl_assert(in_surface_ptr->is_compatible_with_image_format(dynamic_cast<Anvil::SGPUDevice*>(m_backend_ptr->get_device_ptr() )->get_physical_device(),
                                                                    Anvil::Format::B8G8R8A8_UNORM,
                                                                   &format_accepted) );

        format_accepted = true;
    }

    return result;
}

Anvil::ImageUsageFlags OpenGL::VKSwapchainManager::get_swapchain_image_usage_flags(const Anvil::RenderingSurface* in_surface_ptr) const
{
    Anvil::ImageUsageFlags     result        = Anvil::ImageUsageFlagBits::NONE;
    Anvil::SurfaceCapabilities surface_caps;

    if (!in_surface_ptr->get_capabilities(dynamic_cast<Anvil::SGPUDevice*>(m_backend_ptr->get_device_ptr() )->get_physical_device(),
                                         &surface_caps) )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* Color renderability is a must. */
    if ((surface_caps.supported_usage_flags & Anvil::ImageUsageFlagBits::COLOR_ATTACHMENT_BIT) != 0)
    {
        result |= Anvil::ImageUsageFlagBits::COLOR_ATTACHMENT_BIT;
    }
    else
    {
        VKGL::g_logger_ptr->log(VKGL::LogLevel::Error,
                                "No COLOR_ATTACHMENT_BIT image usage flag support reported for the rendering surface.");

        vkgl_assert_fail();
    }

    /* TODO: Lack of support for TRANSFER_SRC can be worked around but for now that's not supported.. */
    if ((surface_caps.supported_usage_flags & Anvil::ImageUsageFlagBits::TRANSFER_SRC_BIT) != 0)
    {
        result |= Anvil::ImageUsageFlagBits::TRANSFER_SRC_BIT;
    }
    else
    {
        VKGL::g_logger_ptr->log(VKGL::LogLevel::Error,
                                "No TRANSFER_SRC_BIT image usage flag support reported for the rendering surface.");

        vkgl_assert_fail();
    }

    /* TODO: Lack of support for TRANSFER_DST can be worked around but for now that's not supported.. */
    if ((surface_caps.supported_usage_flags & Anvil::ImageUsageFlagBits::TRANSFER_DST_BIT) != 0)
    {
        result |= Anvil::ImageUsageFlagBits::TRANSFER_DST_BIT;
    }
    else
    {
        VKGL::g_logger_ptr->log(VKGL::LogLevel::Error,
                                "No TRANSFER_DST_BIT image usage flag support reported for the rendering surface.");

        vkgl_assert_fail();
    }

end:
    return result;
}

OpenGL::TimeMarker OpenGL::VKSwapchainManager::get_tot_time_marker() const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    vkgl_assert(m_snapshot_manager_ptr != nullptr);

    return m_snapshot_manager_ptr->get_last_modified_time();
}

bool OpenGL::VKSwapchainManager::init()
{
    bool result = false;

    /* Initialize the swapchain snapshot manager. */
    const auto time_now = std::chrono::high_resolution_clock::now();

    m_snapshot_manager_ptr.reset(
        new decltype(m_snapshot_manager_ptr)::element_type(0,    /* in_object_id                    */
                                                           this, /* in_state_snapshot_accessors_ptr */
                                                           time_now,
                                                           std::bind(&OpenGL::VKSwapchainManager::on_all_swapchain_snapshots_out_of_scope,
                                                                     this)
                                                                    ) );

    if (m_snapshot_manager_ptr == nullptr)
    {
        vkgl_assert(m_snapshot_manager_ptr != nullptr);

        goto end;
    }

    /* All done */
    result = true;
end:
    return result;
}

void OpenGL::VKSwapchainManager::on_all_swapchain_snapshots_out_of_scope()
{
    /* When this function is called, none of the swapchains are being referenced. While we must not assume ToT
     * swapchain is not being used at this point, anything older than ToT should technically no longer be in use.
     * Hence, this is a good opportunity to do some housekeeping */
    std::lock_guard<std::mutex> lock        (m_mutex);
    const uint32_t              n_swapchains(static_cast<uint32_t>(m_time_marker_to_internal_swapchain_data_map.size() ));

    if (n_swapchains > 1)
    {
        const auto tot_time_marker = m_snapshot_manager_ptr->get_last_modified_time();

        while (m_time_marker_to_internal_swapchain_data_map.size() > 1)
        {
            for (auto map_iterator  = m_time_marker_to_internal_swapchain_data_map.begin();
                      map_iterator != m_time_marker_to_internal_swapchain_data_map.end  ();
                      map_iterator ++)
            {
                if (map_iterator->first != tot_time_marker)
                {
                    vkgl_assert(map_iterator->first < tot_time_marker);

                    m_time_marker_to_internal_swapchain_data_map.erase(map_iterator);

                    /* Iterators are no longer valid, need to restart. */
                    break;
                }
            }
        }
    }
}

void OpenGL::VKSwapchainManager::on_frame_acquisition_semaphore_out_of_scope(InternalSwapchainData* in_swapchain_data_ptr,
                                                                             Anvil::Semaphore*      in_sem_ptr)
{
    vkgl_assert(in_sem_ptr != nullptr);

    if (!in_sem_ptr->reset() )
    {
        vkgl_assert_fail();
    }

    Anvil::SemaphoreUniquePtr sem_ptr(in_sem_ptr,
                                      [](Anvil::Semaphore* sem_ptr){delete sem_ptr;});

    in_swapchain_data_ptr->frame_acquisition_semaphore_ptrs.push_back(std::move(sem_ptr) );
}

Anvil::SemaphoreUniquePtr OpenGL::VKSwapchainManager::pop_frame_acquisition_semaphore(const OpenGL::TimeMarker& in_time_marker)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    auto                        internal_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);

    vkgl_assert(internal_data_iterator                                                  != m_time_marker_to_internal_swapchain_data_map.end() );
    vkgl_assert(internal_data_iterator->second->frame_acquisition_semaphore_ptrs.size() >  0);

    auto                      internal_data_ptr = internal_data_iterator->second.get();
    Anvil::SemaphoreUniquePtr result_sem_ptr    = std::move(internal_data_ptr->frame_acquisition_semaphore_ptrs.back() );

    internal_data_ptr->frame_acquisition_semaphore_ptrs.pop_back();

    return Anvil::SemaphoreUniquePtr(result_sem_ptr.release(),
                                     std::bind(&OpenGL::VKSwapchainManager::on_frame_acquisition_semaphore_out_of_scope,
                                               this,
                                               internal_data_ptr,
                                               result_sem_ptr.get() ));
}

void OpenGL::VKSwapchainManager::recreate_swapchain(const bool& in_defer_till_acquisition)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_should_recreate_swapchain = true;

    if (!in_defer_till_acquisition)
    {
        /* NOTE: Ignore the result reference. All we need here is re-creation of the swapchain. The caller
         *       is expected to call acquire_swapchain() again to retrieve the latest swapchain payload
         *       after this func leaves.
         */
        auto result_reference_ptr = acquire_swapchain(get_tot_time_marker() );

        vkgl_assert(result_reference_ptr != nullptr);
    }
}

void OpenGL::VKSwapchainManager::set_swap_interval(const int32_t& in_swap_interval)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    SwapchainPropsSnapshot*     tot_swapchain_ptr = reinterpret_cast<SwapchainPropsSnapshot*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    vkgl_assert(tot_swapchain_ptr != nullptr);

    if (tot_swapchain_ptr->swap_interval != in_swap_interval)
    {
        tot_swapchain_ptr->swap_interval = in_swap_interval;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::VKSwapchainManager::set_target_window(HWND in_window_handle)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    SwapchainPropsSnapshot*     tot_swapchain_ptr = reinterpret_cast<SwapchainPropsSnapshot*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    vkgl_assert(tot_swapchain_ptr != nullptr);

    if (tot_swapchain_ptr->window_handle != in_window_handle)
    {
        tot_swapchain_ptr->window_handle = in_window_handle;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}
