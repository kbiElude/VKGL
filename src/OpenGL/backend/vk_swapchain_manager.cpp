/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/swapchain_create_info.h"
#include "Anvil/include/misc/window_factory.h"
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/rendering_surface.h"
#include "Anvil/include/wrappers/swapchain.h"
#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_swapchain_manager.h"
#include "OpenGL/frontend/snapshot_manager.h"
#include "Common/logger.h"
#include "Common/macros.h"

OpenGL::VKSwapchainManager::VKSwapchainManager(OpenGL::IBackend*                    in_backend_ptr,
                                               const uint32_t&                      in_n_swapchain_images,
                                               const VKGL::PixelFormatRequirements& in_pixel_format_reqs)
    :m_backend_ptr       (in_backend_ptr),
     m_n_swapchain_images(in_n_swapchain_images),
     m_pixel_format_reqs (in_pixel_format_reqs)
{
    vkgl_assert(m_backend_ptr        != nullptr);
    vkgl_assert(m_n_swapchain_images != 0);
}

OpenGL::VKSwapchainManager::~VKSwapchainManager()
{
}

OpenGL::VKSwapchainReferenceUniquePtr OpenGL::VKSwapchainManager::acquire_swapchain(const OpenGL::TimeMarker& in_time_marker)
{
    decltype(m_time_marker_to_internal_swapchain_data_map)::const_iterator internal_swapchain_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);
    OpenGL::VKSwapchainReferenceUniquePtr                                  result_ptr;
    auto                                                                   snapshot_ptr                     = reinterpret_cast<const SwapchainPropsSnapshot*>  (m_snapshot_manager_ptr->get_readonly_snapshot(in_time_marker) );

    if (snapshot_ptr == nullptr)
    {
        vkgl_assert(snapshot_ptr != nullptr);

        goto end;
    }

    if (internal_swapchain_data_iterator == m_time_marker_to_internal_swapchain_data_map.end() )
    {
        /* Need to spawn a new swapchain instance */
        auto internal_data_ptr = create_swapchain(snapshot_ptr);

        if (internal_data_ptr == nullptr)
        {
            vkgl_assert(internal_data_ptr != nullptr);

            goto end;
        }

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

OpenGL::VKSwapchainManager::InternalSwapchainDataUniquePtr OpenGL::VKSwapchainManager::create_swapchain(const SwapchainPropsSnapshot* in_swapchain_props_ptr) const
{
    auto                             device_ptr                  = m_backend_ptr->get_device_ptr();
    InternalSwapchainDataUniquePtr   internal_swapchain_data_ptr;
    Anvil::RenderingSurfaceUniquePtr rendering_surface_ptr;
    Anvil::SwapchainUniquePtr        swapchain_ptr;
    Anvil::WindowUniquePtr           window_ptr;

    vkgl_assert(device_ptr != nullptr);

    /* 1. Create a window wrapper for the window handle specified by the app. */
    {
        window_ptr = Anvil::WindowFactory::create_window(Anvil::WINDOW_PLATFORM_DUMMY,
                                                         in_swapchain_props_ptr->window_handle);

        if (window_ptr == nullptr)
        {
            vkgl_assert(window_ptr != nullptr);

            goto end;
        }
    }

    /* 2. Create a rendering surface for the window */
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
                                                             present_mode,
                                                             image_usage_flags,
                                                             m_n_swapchain_images);

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

    /* 4. Pack all the dependencies together. */
    internal_swapchain_data_ptr.reset(
        new InternalSwapchainData(std::move(rendering_surface_ptr),
                                  std::move(swapchain_ptr),
                                  std::move(window_ptr) )
    );

    if (internal_swapchain_data_ptr == nullptr)
    {
        vkgl_assert(internal_swapchain_data_ptr != nullptr);

        goto end;
    }

    /* Done */
end:
    return internal_swapchain_data_ptr;
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
        /* TODO: We do NOT support EXT_swap_control_tear at this point. */
        vkgl_assert_fail();
        vkgl_assert     (in_swapchain_props_ptr->swap_interval == -1);

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

Anvil::Format OpenGL::VKSwapchainManager::get_swapchain_format(const SwapchainPropsSnapshot*  in_swapchain_props_ptr,
                                                               const Anvil::RenderingSurface* in_surface_ptr) const
{
    Anvil::Format result = Anvil::Format::UNKNOWN;

    /* TODO: For now, stick to RGBA8_UNORM.
     *
     *       We should actually be picking a supported format which most closely matches the requested configuration.
     */
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
    vkgl_assert(m_snapshot_manager_ptr != nullptr);

    return m_snapshot_manager_ptr->get_last_modified_time();
}

bool OpenGL::VKSwapchainManager::init()
{
    bool result = false;

    /* Initialize the swapchain snapshot manager. */
    const auto time_now = std::chrono::high_resolution_clock::now();

    m_snapshot_manager_ptr.reset(
        new decltype(m_snapshot_manager_ptr)::element_type(0, /* in_object_id */
                                                           this, /* in_state_snapshot_accessors_ptr */
                                                           time_now,
                                                           std::bind(&OpenGL::VKSwapchainManager::on_swapchain_snapshot_out_of_scope,
                                                                     this,
                                                                     time_now)
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

void OpenGL::VKSwapchainManager::on_swapchain_snapshot_out_of_scope(OpenGL::TimeMarker in_time_marker)
{
    /* Release the swapchain instance. */
    auto internal_data_iterator = m_time_marker_to_internal_swapchain_data_map.find(in_time_marker);

    vkgl_assert(internal_data_iterator != m_time_marker_to_internal_swapchain_data_map.end() );

    m_time_marker_to_internal_swapchain_data_map.erase(internal_data_iterator);
}

void OpenGL::VKSwapchainManager::set_swap_interval(const int32_t& in_swap_interval)
{
    SwapchainPropsSnapshot* tot_swapchain_ptr = reinterpret_cast<SwapchainPropsSnapshot*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    vkgl_assert(tot_swapchain_ptr != nullptr);

    if (tot_swapchain_ptr->swap_interval != in_swap_interval)
    {
        tot_swapchain_ptr->swap_interval = in_swap_interval;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}

void OpenGL::VKSwapchainManager::set_target_window(HWND in_window_handle)
{
    SwapchainPropsSnapshot* tot_swapchain_ptr = reinterpret_cast<SwapchainPropsSnapshot*>(m_snapshot_manager_ptr->get_rw_tot_snapshot() );

    vkgl_assert(tot_swapchain_ptr != nullptr);

    if (tot_swapchain_ptr->window_handle != in_window_handle)
    {
        tot_swapchain_ptr->window_handle = in_window_handle;

        m_snapshot_manager_ptr->update_last_modified_time();
    }
}
