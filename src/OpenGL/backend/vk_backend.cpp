/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/misc/memory_allocator.h"
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/instance.h"
#include "Common/macros.h"
#include "OpenGL/types.h"
#include "OpenGL/converters.h"
#include "OpenGL/backend/thread_pool.h"
#include "OpenGL/backend/vk_backend.h"
#include "OpenGL/backend/vk_framebuffer_manager.h"
#include "OpenGL/backend/vk_gfx_pipeline_manager.h"
#include "OpenGL/backend/vk_renderpass_manager.h"
#include "OpenGL/backend/vk_scheduler.h"
#include "OpenGL/backend/vk_spirv_manager.h"
#include "OpenGL/backend/vk_utils.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "OpenGL/frontend/gl_program_manager.h"
#include "OpenGL/frontend/gl_shader_manager.h"
#include "OpenGL/frontend/gl_state_manager.h"
#include "OpenGL/utils_enum.h"
#include "WGL/context.h"
#include <sstream>

/* TODO: Touching heap memory is awful, but right now this happens in every command handler because
 *       command processing happens in scheduler's thread to ensure the app never gets blocked by VKGL.
 *
 *       A custom memory allocator relying on preallocated memory chunks should be fit in here, instead
 *       of the ugly new invocations.
 *
 *       What we do in here will work for a PoC but is expected to be one of the major bottlenecks in the
 *       near future.
 */
#ifdef min
    #undef min
#endif

OpenGL::VKBackend::VKBackend(const VKGL::IWSIContext* in_wsi_context_ptr)
    :m_frontend_ptr   (nullptr),
     m_wsi_context_ptr(in_wsi_context_ptr)
{
    vkgl_assert(m_wsi_context_ptr != nullptr);
}

OpenGL::VKBackend::~VKBackend()
{
    /* Make sure to release the scheduler before we go ahead and destroy core VK objects. */
    m_scheduler_ptr.reset();

    /* Flush the frame graph and CPU-wait till it finishes executing GPU-side before proceeding with deinitialization */
    {
        m_frame_graph_ptr->execute(true,
                                   nullptr); /* in_opt_fence_ptr */
    }

    m_frame_graph_ptr.reset();

    /* It should be safe to destroy remaining objects at this point */
    m_buffer_manager_ptr.reset      ();
    m_format_manager_ptr.reset      ();
    m_framebuffer_manager_ptr.reset ();
    m_gfx_pipeline_manager_ptr.reset();
    m_mem_allocator_ptr.reset       ();
    m_renderpass_manager_ptr.reset  ();
    m_swapchain_manager_ptr.reset   ();

    m_device_ptr.reset  ();
    m_instance_ptr.reset();
}

void OpenGL::VKBackend::buffer_data(const GLuint&     in_id,
                                    const GLsizeiptr& in_size,
                                    const void*       in_data_ptr)
{
    OpenGL::DataUniquePtr data_ptr(nullptr,
                                   [](void* in_ptr){if (in_ptr != nullptr) { delete [] reinterpret_cast<unsigned char*>(in_ptr);} });

    /* 1. Copy user-specified data to a temporary mem block */
    if (in_data_ptr != nullptr)
    {
        data_ptr.reset(reinterpret_cast<void*>(new unsigned char[in_size]) );
        vkgl_assert(data_ptr != nullptr);

        memcpy(data_ptr.get(),
               in_data_ptr,
               in_size);
    }

    /* 2. Grab the buffer reference. */
    auto buffer_reference_ptr = m_frontend_ptr->get_buffer_manager_ptr()->acquire_current_latest_snapshot_reference(in_id);

    vkgl_assert(buffer_reference_ptr != nullptr);

    /* 3. Spawn the command container .. */
    OpenGL::CommandBaseUniquePtr cmd_ptr(new OpenGL::BufferDataCommand(std::move(buffer_reference_ptr),
                                                                       std::move(data_ptr),
                                                                       in_size),
                                         std::default_delete<OpenGL::CommandBase>() );

    vkgl_assert(cmd_ptr != nullptr);

    m_scheduler_ptr->submit(std::move(cmd_ptr) );
}

void OpenGL::VKBackend::buffer_sub_data(const GLuint&     in_id,
                                        const GLsizeiptr& in_start_offset,
                                        const GLsizeiptr& in_size,
                                        const void*       in_data_ptr)
{
    OpenGL::DataUniquePtr data_ptr(nullptr,
                                   [](void* in_ptr){if (in_ptr != nullptr) { delete [] reinterpret_cast<unsigned char*>(in_ptr);} });

    /* 1. Copy user-specified data to a temporary mem block */
    vkgl_assert(in_data_ptr != nullptr);

    data_ptr.reset(reinterpret_cast<void*>(new unsigned char[in_size]) );
    vkgl_assert(data_ptr != nullptr);

    memcpy(data_ptr.get(),
           in_data_ptr,
           in_size);

    /* 2. Grab the buffer reference. */
    auto buffer_reference_ptr = m_frontend_ptr->get_buffer_manager_ptr()->acquire_current_latest_snapshot_reference(in_id);

    vkgl_assert(buffer_reference_ptr != nullptr);

    /* 3. Spawn the command container .. */
    OpenGL::CommandBaseUniquePtr cmd_ptr(new OpenGL::BufferSubDataCommand(std::move(buffer_reference_ptr),
                                                                          std::move(data_ptr),
                                                                          in_size,
                                                                          in_start_offset),
                                         std::default_delete<OpenGL::CommandBase>() );

    vkgl_assert(cmd_ptr != nullptr);

    m_scheduler_ptr->submit(std::move(cmd_ptr) );
}

void OpenGL::VKBackend::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
    auto context_state_reference_ptr = m_frontend_ptr->get_state_manager_ptr()->acquire_current_latest_snapshot_reference();

    OpenGL::CommandBaseUniquePtr cmd_ptr(new OpenGL::ClearCommand(in_buffers_to_clear,
                                                                  std::move(context_state_reference_ptr) ),
                                         std::default_delete<OpenGL::CommandBase>() );

    vkgl_assert(cmd_ptr != nullptr);

    m_scheduler_ptr->submit(std::move(cmd_ptr) );
}

void OpenGL::VKBackend::compile_shader(const GLuint& in_id)
{
    auto        frontend_shader_manager_ptr = m_frontend_ptr->get_shader_manager_ptr();
    const char* shader_glsl                 = nullptr;
    SPIRVBlobID spirv_blob_id               = UINT32_MAX;

    /* 1. Grab the shader reference. */
    auto shader_reference_ptr = m_frontend_ptr->get_shader_manager_ptr()->acquire_current_latest_snapshot_reference(in_id);
    vkgl_assert(shader_reference_ptr != nullptr);

    /* 2. Retrieve GLSL associated with the shader and:
     *
     * a) Schedule compilation, if no GLSL->SPIR-V conversion has already been initiated.
     * b) Assign corresponding SPIR-V blob ID to the frontend's shader object otherwise.
     */
    const auto time_marker = shader_reference_ptr->get_payload().time_marker;

    if (!frontend_shader_manager_ptr->get_shader_glsl(in_id,
                                                     &time_marker,
                                                     &shader_glsl) )
    {
        vkgl_assert_fail();

        goto end;
    }

    if (!m_spirv_manager_ptr->get_spirv_blob_id_for_glsl(shader_glsl,
                                                        &spirv_blob_id) )
    {
        /* a) */
        OpenGL::ShaderType shader_type  = OpenGL::ShaderType::Unknown;

        if (!frontend_shader_manager_ptr->get_shader_type(in_id,
                                                         &time_marker,
                                                         &shader_type) )
        {
            vkgl_assert_fail();

            goto end;
        }

        spirv_blob_id = m_spirv_manager_ptr->register_shader(shader_type,
                                                             shader_glsl);
    }
    else
    {
        /* b) - nop */
    }

    frontend_shader_manager_ptr->set_shader_backend_spirv_blob_id(in_id,
                                                                 &time_marker,
                                                                  spirv_blob_id);

end:
    ;
}

void OpenGL::VKBackend::compressed_tex_image_1d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei                 in_width,
                                                const GLint                   in_border,
                                                const GLsizei                 in_image_size,
                                                const void*                   in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_image_2d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei&                in_width,
                                                const GLsizei&                in_height,
                                                const GLint&                  in_border,
                                                const GLsizei&                in_image_size,
                                                const void*                   in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_image_3d(const GLuint&                 in_id,
                                                const GLint&                  in_level,
                                                const OpenGL::InternalFormat& in_internalformat,
                                                const GLsizei&                in_width,
                                                const GLsizei&                in_height,
                                                const GLsizei&                in_depth,
                                                const GLint&                  in_border,
                                                const GLsizei&                in_image_size,
                                                const void*                   in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_sub_image_1d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLsizei&             in_width,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_sub_image_2d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLint&               in_yoffset,
                                                    const GLsizei&             in_width,
                                                    const GLsizei&             in_height,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compressed_tex_sub_image_3d(const GLuint&              in_id,
                                                    const GLint&               in_level,
                                                    const GLint&               in_xoffset,
                                                    const GLint&               in_yoffset,
                                                    const GLint&               in_zoffset,
                                                    const GLsizei&             in_width,
                                                    const GLsizei&             in_height,
                                                    const GLsizei&             in_depth,
                                                    const OpenGL::PixelFormat& in_format,
                                                    const GLsizei&             in_image_size,
                                                    const void*                in_data)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_buffer_sub_data(const GLuint&     in_read_buffer_id,
                                             const GLuint&     in_write_buffer_id,
                                             const GLintptr&   in_read_offset,
                                             const GLintptr&   in_write_offset,
                                             const GLsizeiptr& in_size)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_image_1d(const GLuint&                 in_id,
                                          const GLint                   in_level,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const GLint&                  in_x,
                                          const GLint&                  in_y,
                                          const GLsizei&                in_width,
                                          const GLint&                  in_border)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_image_2d(const GLuint&                 in_id,
                                          const GLint&                  in_level,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const GLint&                  in_x,
                                          const GLint&                  in_y,
                                          const GLsizei&                in_width,
                                          const GLsizei&                in_height,
                                          const GLint&                  in_border)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_sub_image_1d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_sub_image_2d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_yoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width,
                                              const GLsizei& in_height)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::copy_tex_sub_image_3d(const GLuint&  in_id,
                                              const GLint&   in_level,
                                              const GLint&   in_xoffset,
                                              const GLint&   in_yoffset,
                                              const GLint&   in_zoffset,
                                              const GLint&   in_x,
                                              const GLint&   in_y,
                                              const GLsizei& in_width,
                                              const GLsizei& in_height)
{
    vkgl_not_implemented();
}

OpenGL::VKBackendUniquePtr OpenGL::VKBackend::create(const VKGL::IWSIContext* in_wsi_context_ptr)
{
    OpenGL::VKBackendUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::VKBackend(in_wsi_context_ptr) );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

void OpenGL::VKBackend::draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                    const GLint&                in_first,
                                    const GLsizei&              in_count)
{
    /* 1. Grab a snapshot of current context's state.
     *
     *    Context state holds so-called proxy references. Convert those we're going to need to be able to use into
     *    actual refs.
     **/
    auto state_manager_ptr   = m_frontend_ptr->get_state_manager_ptr();
    auto state_reference_ptr = state_manager_ptr->acquire_current_latest_snapshot_reference();

    vkgl_assert(state_reference_ptr != nullptr);

    auto state_binding_references_ptr = OpenGL::VKUtils::create_gl_context_state_binding_references(m_frontend_ptr,
                                                                                                    state_reference_ptr.get() );

    vkgl_assert(state_binding_references_ptr != nullptr);

    /* 2. Spawn the command container .. */
    OpenGL::CommandBaseUniquePtr cmd_ptr(new OpenGL::DrawArraysCommand(in_count,
                                                                       in_first,
                                                                       in_mode,
                                                                       std::move(state_reference_ptr),
                                                                       std::move(state_binding_references_ptr) ),
                                         std::default_delete<OpenGL::CommandBase>() );

    vkgl_assert(cmd_ptr != nullptr);

    /* 2. Submit the command */
    m_scheduler_ptr->submit(std::move(cmd_ptr) );
}

void OpenGL::VKBackend::draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                      const GLsizei&                   in_count,
                                      const OpenGL::DrawCallIndexType& in_type,
                                      const void*                      in_indices)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                            const GLuint&                    in_start,
                                            const GLuint&                    in_end,
                                            const GLsizei&                   in_count,
                                            const OpenGL::DrawCallIndexType& in_type,
                                            const void*                      in_indices)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::finish()
{
    OpenGL::CommandBaseUniquePtr cmd_ptr  (nullptr,
                                           std::default_delete<OpenGL::CommandBase>() );
    VKGL::FenceUniquePtr         fence_ptr(nullptr,
                                           std::default_delete<VKGL::Fence>() );

    /* Instantiate a fence we're going to use for app thread<->backend thread sync purposes */
    fence_ptr.reset(new VKGL::Fence() );
    vkgl_assert(fence_ptr != nullptr);

    /* Spawn the command container .. */
    cmd_ptr.reset(new OpenGL::FinishCommand(fence_ptr.get() ));
    vkgl_assert(cmd_ptr != nullptr);

    m_scheduler_ptr->submit(std::move(cmd_ptr) );

    /* Block until the scheduler finishes GPU-side execution. */
    fence_ptr->wait();
}

void OpenGL::VKBackend::flush(VKGL::Fence* in_opt_fence_ptr)
{
    /* Spawn the command container .. */
    OpenGL::CommandBaseUniquePtr cmd_ptr(new OpenGL::FlushCommand(in_opt_fence_ptr),
                                         std::default_delete<OpenGL::CommandBase>() );

    vkgl_assert(cmd_ptr != nullptr);

    m_scheduler_ptr->submit(std::move(cmd_ptr) );
}

void OpenGL::VKBackend::flush_mapped_buffer_range(const GLuint&     in_id,
                                                  const GLintptr&   in_offset,
                                                  const GLsizeiptr& in_length)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::get_buffer_sub_data(const GLuint&     in_id,
                                            const GLintptr&   in_offset,
                                            const GLsizeiptr& in_size,
                                            void*             out_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::get_capability(const OpenGL::BackendCapability&  in_capability,
                                       const OpenGL::GetSetArgumentType& in_arg_type,
                                       const uint32_t&                   in_n_vals,
                                       void*                             out_result_ptr) const
{
    const auto cap_iterator = m_capabilities.find(in_capability);

    if (cap_iterator == m_capabilities.end() )
    {
        vkgl_assert(cap_iterator != m_capabilities.end() );

        goto end;
    }

    if (cap_iterator->second.n_vals < in_n_vals)
    {
        vkgl_assert(cap_iterator->second.n_vals >= in_n_vals);

        goto end;
    }

    OpenGL::Converters::convert(cap_iterator->second.data_type,
                                cap_iterator->second.data.u32,
                                cap_iterator->second.n_vals,
                                in_arg_type,
                                out_result_ptr);

end:
    ;
}

void OpenGL::VKBackend::get_compressed_tex_image(const GLuint& in_id,
                                                 const GLint&  in_level,
                                                 void*         in_img)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::get_texture_image(const GLuint&              in_id,
                                          const uint32_t&            in_level,
                                          const OpenGL::PixelFormat& in_format,
                                          const OpenGL::PixelType&   in_type,
                                          void*                      out_pixels_ptr)
{
    vkgl_not_implemented();
}

bool OpenGL::VKBackend::init()
{
    bool result = false;

    /* Init low-level Vulkan guts provider facility first.. */
    if (!init_anvil() )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* Init all the caps we expose to the frontend .. */
    if (!init_capabilities() )
    {
        vkgl_assert_fail();

        goto end;
    }

    /* Init various object managers .. */
    m_framebuffer_manager_ptr = OpenGL::VKFramebufferManager::create(this);

    if (m_framebuffer_manager_ptr == nullptr)
    {
        vkgl_assert(m_framebuffer_manager_ptr != nullptr);

        goto end;
    }

    m_renderpass_manager_ptr = OpenGL::VKRenderpassManager::create(this);

    if (m_renderpass_manager_ptr == nullptr)
    {
        vkgl_assert(m_renderpass_manager_ptr != nullptr);

        goto end;
    }

    m_swapchain_manager_ptr = OpenGL::VKSwapchainManager::create(this,
                                                                 2, /* in_n_swapchain_images - by GL's design */
                                                                 m_wsi_context_ptr->get_pixel_format_requirements() );

    if (m_swapchain_manager_ptr == nullptr)
    {
        vkgl_assert(m_swapchain_manager_ptr != nullptr);

        goto end;
    }

    m_format_manager_ptr = OpenGL::VKFormatManager::create(dynamic_cast<Anvil::SGPUDevice*>(get_device_ptr()) );

    if (m_format_manager_ptr == nullptr)
    {
        vkgl_assert(m_format_manager_ptr != nullptr);

        goto end;
    }

    m_mem_allocator_ptr = Anvil::MemoryAllocator::create_vma(m_device_ptr.get() );

    if (m_mem_allocator_ptr == nullptr)
    {
        vkgl_assert(m_mem_allocator_ptr != nullptr);

        goto end;
    }

    m_thread_pool_ptr = OpenGL::ThreadPool::create();

    if (m_thread_pool_ptr == nullptr)
    {
        vkgl_assert(m_thread_pool_ptr != nullptr);

        goto end;
    }

    /* NOTE: We postpone creation of SPIR-V manager, frame graph and scheduler to set_frontend_callback(), since we need to be able to pass
     *       a ptr to the frontend at scheduler creation time. However, in order to create the frontend, backend
     *       instance need to be specified.
     */

    /* All done */
    result = true;
end:
    return result;
}

bool OpenGL::VKBackend::init_anvil()
{
    const Anvil::PhysicalDevice* physical_device_ptr = nullptr;
    bool                         result              = false;

    /* Create a Vulkan instance. */
    m_instance_ptr = Anvil::Instance::create("VKGL",
                                             "VKGL",
#if defined(_DEBUG)
                                             std::bind(&OpenGL::VKBackend::on_debug_callback_received,
                                                       this,
                                                       std::placeholders::_1,
                                                       std::placeholders::_2),
#else
                                             Anvil::DebugCallbackFunction(),
#endif
                                             true); /* in_mt_safe */

    if (m_instance_ptr == nullptr)
    {
        vkgl_assert(m_instance_ptr != nullptr);

        goto end;
    }

    /* Pick the zerorth physical device reported. */
    physical_device_ptr = m_instance_ptr->get_physical_device(0);

    /* Create a Vulkan device */
    {
        Anvil::DeviceExtensionConfiguration dev_exts;

        /* VK_KHR_maintenance1 is required for viewport origin flipping */
        dev_exts.extension_status[VK_KHR_MAINTENANCE1_EXTENSION_NAME] = Anvil::ExtensionAvailability::REQUIRE;

        m_device_ptr = Anvil::SGPUDevice::create(physical_device_ptr,
                                                 true, /* in_enable_shader_module_cache */
                                                 dev_exts,
                                                 std::vector<std::string>(),
                                                 false, /* in_transient_command_buffer_allocs_only     */
                                                 true,  /* in_support_resettable_command_buffer_allocs */
                                                 true); /* in_mt_safe                                  */
    }

    if (m_device_ptr == nullptr)
    {
        vkgl_assert(m_device_ptr != nullptr);

        goto end;
    }

    result = true;
end:
    return result;
}

bool OpenGL::VKBackend::init_capabilities()
{
    /* NOTE: Taken from GL 3.2 spec */
    const float    min_aliased_line_width_range[2]                   = {1.0f, 1.0f};
    const auto     min_max_3d_texture_size                           = 256;
    const auto     min_max_array_texture_layers                      = 256;
    const auto     min_max_clip_distances                            = 8;
    const auto     min_max_color_attachments                         = 8;
    const auto     min_max_color_texture_samples                     = 1;
    const auto     min_max_combined_texture_image_units              = 48;
    const auto     min_max_combined_uniform_blocks                   = 36;
    const auto     min_max_cube_map_texture_size                     = 1024;
    const auto     min_max_depth_texture_samples                     = 1;
    const auto     min_max_draw_buffers                              = 8;
    const auto     min_max_fragment_input_components                 = 128;
    const auto     min_max_fragment_uniform_blocks                   = 12;
    const auto     min_max_fragment_uniform_components               = 1024;
    const auto     min_max_geometry_input_components                 = 64;
    const auto     min_max_geometry_output_components                = 128;
    const auto     min_max_geometry_output_vertices                  = 256;
    const auto     min_max_geometry_texture_image_units              = 16;
    const auto     min_max_geometry_total_output_components          = 1024;
    const auto     min_max_geometry_uniform_blocks                   = 12;
    const auto     min_max_geometry_uniform_components               = 1024; /* missing in 3.2 and 4.0? */
    const auto     min_max_integer_samples                           = 1;
    const auto     min_max_program_texel_offset                      = 7;
    const auto     min_max_rectangle_texture_size                    = 1024;
    const auto     min_max_renderbuffer_size                         = 1024;
    const auto     min_max_sample_mask_words                         = 1;
    const auto     min_max_samples                                   = 4;
    const auto     min_max_server_wait_timeout                       = 0LL;
    const auto     min_max_texture_buffer_size                       = 65536;
    const auto     min_max_texture_image_units                       = 16;
    const auto     min_max_texture_lod_bias                          = 2.0f;
    const auto     min_max_transform_feedback_buffers                = 4; /* taken from GL 4.0 spec, apparently missing in 3.2 */
    const auto     min_max_transform_feedback_interleaved_components = 64;
    const auto     min_max_transform_feedback_separate_attribs       = 4;
    const auto     min_max_transform_feedback_separate_components    = 4;
    const auto     min_max_uniform_block_size                        = 16384;
    const auto     min_max_uniform_buffer_bindings                   = 36;
    const auto     min_max_varying_components                        = 60;
    const auto     min_max_vertex_attribs                            = 16;
    const auto     min_max_vertex_output_components                  = 64;
    const auto     min_max_vertex_texture_image_units                = 16;
    const auto     min_max_vertex_uniform_blocks                     = 12;
    const auto     min_max_vertex_uniform_components                 = 1024;
    const auto     max_min_program_texel_offset                      = -8;
    const auto     min_point_size_granularity                        = 0.0f; /* as per 3.4 */
    const float    min_point_size_range[2]                           = {1.0f, 1.0f};
    const auto     min_query_counter_bits                            = 0; /* as per 6.1.6 */
    const float    min_smooth_line_width_range                   [2] = {1.0f, 1.0f};
    const auto     min_subpixel_bits                                 = 4;
    const auto     min_max_combined_fragment_uniform_components      = sizeof(uint32_t) / (min_max_fragment_uniform_blocks * min_max_uniform_block_size + min_max_fragment_uniform_components);
    const auto     min_max_combined_geometry_uniform_components      = sizeof(uint32_t) / (min_max_geometry_uniform_blocks * min_max_uniform_block_size + min_max_geometry_uniform_components);
    const auto     min_max_combined_vertex_uniform_components        = sizeof(uint32_t) / (min_max_vertex_uniform_blocks   * min_max_uniform_block_size + min_max_vertex_uniform_components);
    const auto     min_max_texture_size                              = std::min(std::min(min_max_3d_texture_size, min_max_cube_map_texture_size),
                                                                                min_max_rectangle_texture_size);


    const auto&           physical_device_limits                   = m_device_ptr->get_physical_device_properties().core_vk1_0_properties_ptr->limits;
    static const uint32_t max_combined_fragment_uniform_components = physical_device_limits.max_uniform_buffer_range  / sizeof(uint32_t);
    static const uint32_t max_combined_geometry_uniform_components = physical_device_limits.max_uniform_buffer_range  / sizeof(uint32_t);
    static const uint32_t max_combined_vertex_uniform_components   = physical_device_limits.max_uniform_buffer_range  / sizeof(uint32_t);
    static const uint32_t max_texture_buffer_size                  = physical_device_limits.max_texel_buffer_elements / sizeof(uint32_t); /* worst-case scenario */
    static const uint32_t query_counter_bits                       = 64;
    static const uint32_t uint32_max_u32                           = UINT32_MAX;
    static const uint64_t uint64_max_u64                           = UINT64_MAX;

    /* NOTE: These are examples of over-simpification but should be harmless. */
    static const uint32_t max_fragment_uniform_components          = max_combined_fragment_uniform_components;
    static const uint32_t max_geometry_uniform_components          = max_combined_geometry_uniform_components;
    static const uint32_t max_vertex_uniform_components            = max_combined_vertex_uniform_components;

    /* NOTE: These are arbitrary to an extent. Let's shoot for GL 3.2 core profile min maxes for now. */
    static const uint32_t max_varying_components                        = 60;
    static const uint32_t max_transform_feedback_buffers                = 4; /* NOTE: no min-max defined in GL 3.2 spec? Value comes from 4.0 */
    static const uint32_t max_transform_feedback_interleaved_components = 64;
    static const uint32_t max_transform_feedback_separate_attribs       = 4;
    static const uint32_t max_transform_feedback_separate_components    = 4;

    /* TODO: MS support is not implemented yet so report up to 1 sample for each renderable format. */
    static const uint32_t max_color_texture_samples = 1;
    static const uint32_t max_depth_texture_samples = 1;
    static const uint32_t max_integer_samples       = 1;
    static const uint32_t max_samples               = 1;

    m_capabilities = decltype(m_capabilities)
    {
        {OpenGL::BackendCapability::Aliased_Line_Width_Range,                      CapabilityData( physical_device_limits.line_width_range,                         2)},
        {OpenGL::BackendCapability::Max_3D_Texture_Size,                           CapabilityData(&physical_device_limits.max_image_dimension_3D,                   1)},
        {OpenGL::BackendCapability::Max_Array_Texture_Layers,                      CapabilityData(&physical_device_limits.max_image_array_layers,                   1)},
        {OpenGL::BackendCapability::Max_Clip_Distances,                            CapabilityData(&physical_device_limits.max_clip_distances,                       1)},
        {OpenGL::BackendCapability::Max_Color_Attachments,                         CapabilityData(&physical_device_limits.max_color_attachments,                    1)},
        {OpenGL::BackendCapability::Max_Color_Texture_Samples,                     CapabilityData(&max_color_texture_samples,                                       1)},
        {OpenGL::BackendCapability::Max_Combined_Fragment_Uniform_Components,      CapabilityData(&max_combined_fragment_uniform_components,                        1)},
        {OpenGL::BackendCapability::Max_Combined_Geometry_Uniform_Components,      CapabilityData(&max_combined_geometry_uniform_components,                        1)},
        {OpenGL::BackendCapability::Max_Combined_Texture_Image_Units,              CapabilityData(&physical_device_limits.max_per_stage_descriptor_samplers,        1)},
        {OpenGL::BackendCapability::Max_Combined_Vertex_Uniform_Components,        CapabilityData(&max_combined_vertex_uniform_components,                          1)},
        {OpenGL::BackendCapability::Max_Combined_Uniform_Blocks,                   CapabilityData(&physical_device_limits.max_descriptor_set_uniform_buffers,       1)},
        {OpenGL::BackendCapability::Max_Cube_Map_Texture_Size,                     CapabilityData(&physical_device_limits.max_image_dimension_cube,                 1)},
        {OpenGL::BackendCapability::Max_Depth_Texture_Samples,                     CapabilityData(&max_depth_texture_samples,                                       1)},
        {OpenGL::BackendCapability::Max_Draw_Buffers,                              CapabilityData(&physical_device_limits.max_color_attachments,                    1)},
        {OpenGL::BackendCapability::Max_Elements_Indices,                          CapabilityData(&physical_device_limits.max_draw_indexed_index_value,             1)},
        {OpenGL::BackendCapability::Max_Elements_Vertices,                         CapabilityData(&uint32_max_u32,                                                  1)},
        {OpenGL::BackendCapability::Max_Fragment_Input_Components,                 CapabilityData(&physical_device_limits.max_fragment_input_components,            1)},
        {OpenGL::BackendCapability::Max_Fragment_Uniform_Blocks,                   CapabilityData(&physical_device_limits.max_per_stage_descriptor_uniform_buffers, 1)},
        {OpenGL::BackendCapability::Max_Fragment_Uniform_Components,               CapabilityData(&max_fragment_uniform_components,                                 1)},
        {OpenGL::BackendCapability::Max_Geometry_Input_Components,                 CapabilityData(&physical_device_limits.max_geometry_input_components,            1)},
        {OpenGL::BackendCapability::Max_Geometry_Output_Components,                CapabilityData(&physical_device_limits.max_geometry_output_components,           1)},
        {OpenGL::BackendCapability::Max_Geometry_Output_Vertices,                  CapabilityData(&physical_device_limits.max_geometry_output_vertices,             1)},
        {OpenGL::BackendCapability::Max_Geometry_Texture_Image_Units,              CapabilityData(&physical_device_limits.max_per_stage_descriptor_samplers,        1)},
        {OpenGL::BackendCapability::Max_Geometry_Total_Output_Components,          CapabilityData(&physical_device_limits.max_geometry_total_output_components,     1)},
        {OpenGL::BackendCapability::Max_Geometry_Uniform_Blocks,                   CapabilityData(&physical_device_limits.max_per_stage_descriptor_uniform_buffers, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Uniform_Components,               CapabilityData(&max_geometry_uniform_components,                                 1)},
        {OpenGL::BackendCapability::Max_Integer_Samples,                           CapabilityData(&max_integer_samples,                                             1)},
        {OpenGL::BackendCapability::Max_Program_Texel_Offset,                      CapabilityData(&physical_device_limits.max_texel_offset,                         1)},
        {OpenGL::BackendCapability::Max_Rectangle_Texture_Size,                    CapabilityData(&physical_device_limits.max_image_dimension_2D,                   1)},
        {OpenGL::BackendCapability::Max_Renderbuffer_Size,                         CapabilityData(&physical_device_limits.max_image_dimension_2D,                   1)},
        {OpenGL::BackendCapability::Max_Sample_Mask_Words,                         CapabilityData(&physical_device_limits.max_sample_mask_words,                    1)},
        {OpenGL::BackendCapability::Max_Samples,                                   CapabilityData(&max_samples,                                                     1)},
        {OpenGL::BackendCapability::Max_Server_Wait_Timeout,                       CapabilityData(&uint64_max_u64,                                                  1)},
        {OpenGL::BackendCapability::Max_Texture_Buffer_Size,                       CapabilityData(&max_texture_buffer_size,                                         1)},
        {OpenGL::BackendCapability::Max_Texture_Image_Units,                       CapabilityData(&physical_device_limits.max_per_stage_descriptor_samplers,        1)},
        {OpenGL::BackendCapability::Max_Texture_LOD_Bias,                          CapabilityData(&physical_device_limits.max_sampler_lod_bias,                     1)},
        {OpenGL::BackendCapability::Max_Texture_Size,                              CapabilityData(&physical_device_limits.max_image_dimension_cube,                 1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Buffers,                CapabilityData(&max_transform_feedback_buffers,                                  1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Interleaved_Components, CapabilityData(&max_transform_feedback_interleaved_components,                   1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Attribs,       CapabilityData(&max_transform_feedback_separate_attribs,                         1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Components,    CapabilityData(&max_transform_feedback_separate_components,                      1)},
        {OpenGL::BackendCapability::Max_Uniform_Block_Size,                        CapabilityData(&physical_device_limits.max_uniform_buffer_range,                 1)},
        {OpenGL::BackendCapability::Max_Uniform_Buffer_Bindings,                   CapabilityData(&physical_device_limits.max_descriptor_set_uniform_buffers,       1)},
        {OpenGL::BackendCapability::Max_Varying_Components,                        CapabilityData(&max_varying_components,                                          1)},
        {OpenGL::BackendCapability::Max_Vertex_Attribs,                            CapabilityData(&physical_device_limits.max_vertex_input_attributes,              1)},
        {OpenGL::BackendCapability::Max_Vertex_Output_Components,                  CapabilityData(&physical_device_limits.max_vertex_output_components,             1)},
        {OpenGL::BackendCapability::Max_Vertex_Texture_Image_Units,                CapabilityData(&physical_device_limits.max_per_stage_descriptor_samplers,        1)},
        {OpenGL::BackendCapability::Max_Vertex_Uniform_Blocks,                     CapabilityData(&physical_device_limits.max_per_stage_descriptor_uniform_buffers, 1)},
        {OpenGL::BackendCapability::Max_Vertex_Uniform_Components,                 CapabilityData(&max_vertex_uniform_components,                                   1)},
        {OpenGL::BackendCapability::Min_Program_Texel_Offset,                      CapabilityData(&physical_device_limits.min_texel_offset,                         1)},
        {OpenGL::BackendCapability::Point_Size_Granularity,                        CapabilityData(&physical_device_limits.point_size_granularity,                   1)},
        {OpenGL::BackendCapability::Point_Size_Range,                              CapabilityData( physical_device_limits.point_size_range,                         2)},
        {OpenGL::BackendCapability::Query_Counter_Bits,                            CapabilityData(&query_counter_bits,                                              1)},
        {OpenGL::BackendCapability::Smooth_Line_Width_Granularity,                 CapabilityData(&physical_device_limits.line_width_granularity,                   1)},
        {OpenGL::BackendCapability::Smooth_Line_Width_Range,                       CapabilityData( physical_device_limits.line_width_range,                         2)},
        {OpenGL::BackendCapability::Subpixel_Bits,                                 CapabilityData(&physical_device_limits.viewport_sub_pixel_bits,                  1)},
        {OpenGL::BackendCapability::Uniform_Buffer_Offset_Alignment,               CapabilityData(&physical_device_limits.min_uniform_buffer_offset_alignment,      1)},
    };

    /* Verify the values we have at this point are not lower than the required min maxes, as per GL 3.2 spec. */
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Aliased_Line_Width_Range).data.f32[0]                      <= min_aliased_line_width_range[0]);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Aliased_Line_Width_Range).data.f32[1]                      >= min_aliased_line_width_range[1]);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_3D_Texture_Size).data.u32[0]                           >= min_max_3d_texture_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Array_Texture_Layers).data.u32[0]                      >= min_max_array_texture_layers);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Clip_Distances).data.u32[0]                            >= min_max_clip_distances);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Color_Attachments).data.u32[0]                         >= min_max_color_attachments);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Color_Texture_Samples).data.u32[0]                     >= min_max_color_texture_samples);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Fragment_Uniform_Components).data.u32[0]      >= min_max_combined_fragment_uniform_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Geometry_Uniform_Components).data.u32[0]      >= min_max_combined_geometry_uniform_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Texture_Image_Units).data.u32[0]              >= min_max_combined_texture_image_units);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Uniform_Blocks).data.u32[0]                   >= min_max_combined_uniform_blocks);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Vertex_Uniform_Components).data.u32[0]        >= min_max_combined_vertex_uniform_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Cube_Map_Texture_Size).data.u32[0]                     >= min_max_cube_map_texture_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Depth_Texture_Samples).data.u32[0]                     >= min_max_depth_texture_samples);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Draw_Buffers).data.u32[0]                              >= min_max_draw_buffers);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Fragment_Input_Components).data.u32[0]                 >= min_max_fragment_input_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Fragment_Uniform_Blocks).data.u32[0]                   >= min_max_fragment_uniform_blocks);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Fragment_Uniform_Components).data.u32[0]               >= min_max_fragment_uniform_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Input_Components).data.u32[0]                 >= min_max_geometry_input_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Output_Components).data.u32[0]                >= min_max_geometry_output_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Output_Vertices).data.u32[0]                  >= min_max_geometry_output_vertices);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Texture_Image_Units).data.u32[0]              >= min_max_geometry_texture_image_units);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Total_Output_Components).data.u32[0]          >= min_max_geometry_total_output_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Uniform_Blocks).data.u32[0]                   >= min_max_geometry_uniform_blocks);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Uniform_Components).data.u32[0]               >= min_max_geometry_uniform_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Integer_Samples).data.u32[0]                           >= min_max_integer_samples);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Program_Texel_Offset).data.i32[0]                      >= min_max_program_texel_offset);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Rectangle_Texture_Size).data.u32[0]                    >= min_max_rectangle_texture_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Renderbuffer_Size).data.u32[0]                         >= min_max_renderbuffer_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Sample_Mask_Words).data.u32[0]                         >= min_max_sample_mask_words);
    // TODO (MS SUPPORT): vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Samples).data.u32[0]                                   >= min_max_samples);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Server_Wait_Timeout).data.u64[0]                       >= min_max_server_wait_timeout);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Texture_Buffer_Size).data.u32[0]                       >= min_max_texture_buffer_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Texture_Image_Units).data.u32[0]                       >= min_max_texture_image_units);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Texture_LOD_Bias).data.f32[0]                          >= min_max_texture_lod_bias);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Texture_Size).data.u32[0]                              >= min_max_texture_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Buffers).data.u32[0]                >= min_max_transform_feedback_buffers);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Interleaved_Components).data.u32[0] >= min_max_transform_feedback_interleaved_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Attribs).data.u32[0]       >= min_max_transform_feedback_separate_attribs);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Components).data.u32[0]    >= min_max_transform_feedback_separate_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Uniform_Block_Size).data.u32[0]                        >= min_max_uniform_block_size);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Uniform_Buffer_Bindings).data.u32[0]                   >= min_max_uniform_buffer_bindings);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Varying_Components).data.u32[0]                        >= min_max_varying_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Attribs).data.u32[0]                            >= min_max_vertex_attribs);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Output_Components).data.u32[0]                  >= min_max_vertex_output_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Texture_Image_Units).data.u32[0]                >= min_max_vertex_texture_image_units);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Uniform_Blocks).data.u32[0]                     >= min_max_vertex_uniform_blocks);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Uniform_Components).data.u32[0]                 >= min_max_vertex_uniform_components);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Min_Program_Texel_Offset).data.i32[0]                      <= max_min_program_texel_offset);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Point_Size_Granularity).data.f32[0]                        >= min_point_size_granularity);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Point_Size_Range).data.f32[0]                              <= min_point_size_range[0]);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Point_Size_Range).data.f32[1]                              >= min_point_size_range[1]);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Query_Counter_Bits).data.u32[0]                            >= min_query_counter_bits);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Smooth_Line_Width_Range).data.f32[0]                       <= min_smooth_line_width_range[0]);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Smooth_Line_Width_Range).data.f32[1]                       >= min_smooth_line_width_range[1]);
    vkgl_assert(m_capabilities.at(OpenGL::BackendCapability::Subpixel_Bits).data.u32[0]                                 >= min_subpixel_bits);

    /* Clamp the values to the min maxes. No need to expose more than we are obliged to handle. */
    m_capabilities.at(OpenGL::BackendCapability::Aliased_Line_Width_Range).data.f32[0]                      = min_aliased_line_width_range[0];
    m_capabilities.at(OpenGL::BackendCapability::Aliased_Line_Width_Range).data.f32[1]                      = min_aliased_line_width_range[1];
    m_capabilities.at(OpenGL::BackendCapability::Max_3D_Texture_Size).data.u32[0]                           = min_max_3d_texture_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Array_Texture_Layers).data.u32[0]                      = min_max_array_texture_layers;
    m_capabilities.at(OpenGL::BackendCapability::Max_Clip_Distances).data.u32[0]                            = min_max_clip_distances;
    m_capabilities.at(OpenGL::BackendCapability::Max_Color_Attachments).data.u32[0]                         = min_max_color_attachments;
    m_capabilities.at(OpenGL::BackendCapability::Max_Color_Texture_Samples).data.u32[0]                     = min_max_color_texture_samples;
    m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Fragment_Uniform_Components).data.u32[0]      = min_max_combined_fragment_uniform_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Geometry_Uniform_Components).data.u32[0]      = min_max_combined_geometry_uniform_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Texture_Image_Units).data.u32[0]              = min_max_combined_texture_image_units;
    m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Uniform_Blocks).data.u32[0]                   = min_max_combined_uniform_blocks;
    m_capabilities.at(OpenGL::BackendCapability::Max_Combined_Vertex_Uniform_Components).data.u32[0]        = min_max_combined_vertex_uniform_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Cube_Map_Texture_Size).data.u32[0]                     = min_max_cube_map_texture_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Depth_Texture_Samples).data.u32[0]                     = min_max_depth_texture_samples;
    m_capabilities.at(OpenGL::BackendCapability::Max_Draw_Buffers).data.u32[0]                              = min_max_draw_buffers;
    m_capabilities.at(OpenGL::BackendCapability::Max_Fragment_Input_Components).data.u32[0]                 = min_max_fragment_input_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Fragment_Uniform_Blocks).data.u32[0]                   = min_max_fragment_uniform_blocks;
    m_capabilities.at(OpenGL::BackendCapability::Max_Fragment_Uniform_Components).data.u32[0]               = min_max_fragment_uniform_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Input_Components).data.u32[0]                 = min_max_geometry_input_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Output_Components).data.u32[0]                = min_max_geometry_output_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Output_Vertices).data.u32[0]                  = min_max_geometry_output_vertices;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Texture_Image_Units).data.u32[0]              = min_max_geometry_texture_image_units;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Total_Output_Components).data.u32[0]          = min_max_geometry_total_output_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Uniform_Blocks).data.u32[0]                   = min_max_geometry_uniform_blocks;
    m_capabilities.at(OpenGL::BackendCapability::Max_Geometry_Uniform_Components).data.u32[0]               = min_max_geometry_uniform_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Integer_Samples).data.u32[0]                           = min_max_integer_samples;
    m_capabilities.at(OpenGL::BackendCapability::Max_Program_Texel_Offset).data.i32[0]                      = min_max_program_texel_offset;
    m_capabilities.at(OpenGL::BackendCapability::Max_Rectangle_Texture_Size).data.u32[0]                    = min_max_rectangle_texture_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Renderbuffer_Size).data.u32[0]                         = min_max_renderbuffer_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Sample_Mask_Words).data.u32[0]                         = min_max_sample_mask_words;
    // TODO (MS SUPPORT): m_capabilities.at(OpenGL::BackendCapability::Max_Samples).data.u32[0]                                   = min_max_samples;
    m_capabilities.at(OpenGL::BackendCapability::Max_Server_Wait_Timeout).data.u64[0]                       = min_max_server_wait_timeout;
    m_capabilities.at(OpenGL::BackendCapability::Max_Texture_Buffer_Size).data.u32[0]                       = min_max_texture_buffer_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Texture_Image_Units).data.u32[0]                       = min_max_texture_image_units;
    m_capabilities.at(OpenGL::BackendCapability::Max_Texture_LOD_Bias).data.f32[0]                          = min_max_texture_lod_bias;
    m_capabilities.at(OpenGL::BackendCapability::Max_Texture_Size).data.u32[0]                              = min_max_texture_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Buffers).data.u32[0]                = min_max_transform_feedback_buffers;
    m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Interleaved_Components).data.u32[0] = min_max_transform_feedback_interleaved_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Attribs).data.u32[0]       = min_max_transform_feedback_separate_attribs;
    m_capabilities.at(OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Components).data.u32[0]    = min_max_transform_feedback_separate_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Uniform_Block_Size).data.u32[0]                        = min_max_uniform_block_size;
    m_capabilities.at(OpenGL::BackendCapability::Max_Uniform_Buffer_Bindings).data.u32[0]                   = min_max_uniform_buffer_bindings;
    m_capabilities.at(OpenGL::BackendCapability::Max_Varying_Components).data.u32[0]                        = min_max_varying_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Attribs).data.u32[0]                            = min_max_vertex_attribs;
    m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Output_Components).data.u32[0]                  = min_max_vertex_output_components;
    m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Texture_Image_Units).data.u32[0]                = min_max_vertex_texture_image_units;
    m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Uniform_Blocks).data.u32[0]                     = min_max_vertex_uniform_blocks;
    m_capabilities.at(OpenGL::BackendCapability::Max_Vertex_Uniform_Components).data.u32[0]                 = min_max_vertex_uniform_components;
    m_capabilities.at(OpenGL::BackendCapability::Min_Program_Texel_Offset).data.i32[0]                      = max_min_program_texel_offset;
    m_capabilities.at(OpenGL::BackendCapability::Point_Size_Granularity).data.f32[0]                        = min_point_size_granularity;
    m_capabilities.at(OpenGL::BackendCapability::Point_Size_Range).data.f32[0]                              = min_point_size_range[0];
    m_capabilities.at(OpenGL::BackendCapability::Point_Size_Range).data.f32[1]                              = min_point_size_range[1];
    m_capabilities.at(OpenGL::BackendCapability::Query_Counter_Bits).data.u32[0]                            = min_query_counter_bits;
    m_capabilities.at(OpenGL::BackendCapability::Smooth_Line_Width_Range).data.f32[0]                       = min_smooth_line_width_range[0];
    m_capabilities.at(OpenGL::BackendCapability::Smooth_Line_Width_Range).data.f32[1]                       = min_smooth_line_width_range[1];
    m_capabilities.at(OpenGL::BackendCapability::Subpixel_Bits).data.u32[0]                                 = min_subpixel_bits;

    return true;
}

void OpenGL::VKBackend::link_program(const GLuint& in_program_id)
{
    auto        frontend_program_manager_ptr = m_frontend_ptr->get_program_manager_ptr();
    SPIRVBlobID spirv_blob_id                = UINT32_MAX;

    /* 1. Grab the program reference. */
    auto program_reference_ptr = frontend_program_manager_ptr->acquire_current_latest_snapshot_reference(in_program_id);

    vkgl_assert(program_reference_ptr != nullptr);

    /* 2. Schedule linking for the program reference. Two cases here:
     *
     * a) Given program ID + timestamp is not recognized. Linking needs to be performed.
     * b) Otherwise, the request is redundant.
     */
    const auto time_marker = program_reference_ptr->get_payload().time_marker;

    if (!m_spirv_manager_ptr->get_spirv_blob_id_for_program_reference(in_program_id,
                                                                      time_marker,
                                                                     &spirv_blob_id) )
    {
        /* a) */
        m_spirv_manager_ptr->register_program(std::move(program_reference_ptr) );
    }
    else
    {
        /* b) - nop */
    }
}

void* OpenGL::VKBackend::map_buffer(const GLuint&               in_id,
                                    const OpenGL::BufferAccess& in_access,
                                    const GLintptr&             in_start_offset,
                                    const GLsizeiptr&           in_length)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::VKBackend::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                          const GLint*                in_first_ptr,
                                          const GLsizei*              in_count_ptr,
                                          const GLsizei&              in_drawcount)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                            const GLsizei*                   in_count_ptr,
                                            const OpenGL::DrawCallIndexType& in_type,
                                            const void* const*               in_indices_ptr,
                                            const GLsizei&                   in_drawcount)
{
    vkgl_not_implemented();
}

VkBool32 OpenGL::VKBackend::on_debug_callback_received(Anvil::DebugMessageSeverityFlags in_severity,
                                                       const char*                      in_message_ptr) const
{
    VkBool32 result = VK_SUCCESS;

    if ((in_severity & Anvil::DebugMessageSeverityFlagBits::ERROR_BIT)   != 0  ||
        (in_severity & Anvil::DebugMessageSeverityFlagBits::WARNING_BIT) != 0)
    {
        #if defined(_WIN32)
        {
            std::stringstream error_sstream;

            error_sstream << "[VALIDATION ERROR]: "
                          << in_message_ptr
                          << "\n";

            ::OutputDebugStringA(error_sstream.str().c_str() );
        }
        #else
        {
            #error Unsupported OS
        }
        #endif
    }

    return false;

}

void OpenGL::VKBackend::on_objects_created(const OpenGL::ObjectType& in_object_type,
                                           const uint32_t&           in_n_ids,
                                           const GLuint*             in_ids_ptr)
{
    /* NOTE: Called from application's rendering thread. */

    switch (in_object_type)
    {
        case OpenGL::ObjectType::Buffer:
        {
            auto gl_buffer_manager_ptr = m_frontend_ptr->get_buffer_manager_ptr();

            for (uint32_t n_id = 0;
                          n_id < in_n_ids;
                        ++n_id)
            {
                const auto object_id            = in_ids_ptr[n_id];
                const auto object_creation_time = gl_buffer_manager_ptr->get_object_creation_time(object_id);
                bool       result;

                result = m_buffer_manager_ptr->create_object(object_id,
                                                             object_creation_time);

                vkgl_assert(result);
            }

            break;
        }

        case OpenGL::ObjectType::Program:
        {
            /* This backend impl doesn't care */

            break;
        }

        case OpenGL::ObjectType::Shader:
        {
            /* This backend impl doesn't care */

            break;
        }

        case OpenGL::ObjectType::Texture:
        {
            vkgl_not_implemented();

            break;
        }

        case OpenGL::ObjectType::Vertex_Array_Object:
        {
            /* This backend impl doesn't care */

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }
}

void OpenGL::VKBackend::on_objects_destroyed(const OpenGL::ObjectType& in_object_type,
                                             const uint32_t&           in_n_ids,
                                             const GLuint*             in_ids_ptr)
{
    switch (in_object_type)
    {
        case OpenGL::ObjectType::Buffer:
        {
            /* This backend impl doesn't care */

            break;
        }

        case OpenGL::ObjectType::Program:
        {
            for (uint32_t n_id = 0;
                          n_id < in_n_ids;
                        ++n_id)
            {
                m_spirv_manager_ptr->unregister_program(in_ids_ptr[n_id]);
            }

            break;
        }

        case OpenGL::ObjectType::Shader:
        {
            /* This backend impl doesn't care */

            break;
        }

        case OpenGL::ObjectType::Texture:
        {
            vkgl_not_implemented();

            break;
        }

        case OpenGL::ObjectType::Vertex_Array_Object:
        {
            /* This backend impl doesn't care */

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }
}

void OpenGL::VKBackend::present()
{
    {
        /* Submit the request to the backend thread. */
        OpenGL::CommandBaseUniquePtr cmd_ptr(new OpenGL::PresentCommand(),
                                             std::default_delete<OpenGL::CommandBase>() );
        vkgl_assert(cmd_ptr != nullptr);

        m_scheduler_ptr->submit(std::move(cmd_ptr) );
    }

    /* ALSO, make sure to flush the command stream, to ensure the frame is actually presented to the end user!
     *
     * NOTE: Since backend lives in a separate thread, we need to manually ensure app's rendering thread never gets
     *       to issue more present requests than there are swapchain images available. Doing so prevents the backend
     *       from getting too much behind the frontend.
     */
    VKGL::FenceUniquePtr new_fence_ptr      = VKGL::FenceUniquePtr(nullptr,
                                                                   std::default_delete<VKGL::Fence>() );
    VKGL::Fence*         new_fence_raw_ptr  = nullptr;
    const auto           n_swapchain_images = m_swapchain_manager_ptr->get_n_swapchain_images();

    new_fence_ptr.reset(new VKGL::Fence() );
    vkgl_assert(new_fence_ptr != nullptr);

    while (m_enqueued_present_fence_ptrs.size() >= n_swapchain_images)
    {
        (*m_enqueued_present_fence_ptrs.begin() )->wait();

        m_enqueued_present_fence_ptrs.erase(m_enqueued_present_fence_ptrs.begin() );
    }

    new_fence_raw_ptr = new_fence_ptr.get();

    m_enqueued_present_fence_ptrs.push_back(std::move(new_fence_ptr) );
    flush                                  (new_fence_raw_ptr);
}

void OpenGL::VKBackend::read_pixels(const int32_t&             in_x,
                                    const int32_t&             in_y,
                                    const size_t&              in_width,
                                    const size_t&              in_height,
                                    const OpenGL::PixelFormat& in_format,
                                    const OpenGL::PixelType&   in_type,
                                    void*                      out_pixels_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::renderbuffer_storage(const GLuint&                 in_id,
                                             const OpenGL::InternalFormat& in_internalformat,
                                             const uint32_t&               in_width,
                                             const uint32_t&               in_height,
                                             const uint32_t&               in_samples)

{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::set_frontend_callback(const OpenGL::IContextObjectManagers* in_callback_ptr)
{
    vkgl_assert(in_callback_ptr != nullptr);
    vkgl_assert(m_frontend_ptr  == nullptr);
    vkgl_assert(m_scheduler_ptr == nullptr);

    m_frontend_ptr = in_callback_ptr;

    /* Create the frame graph, now that we know where the frontend is. */
    m_frame_graph_ptr = OpenGL::VKFrameGraph::create(m_frontend_ptr,
                                                     this);

    if (m_frame_graph_ptr == nullptr)
    {
        vkgl_assert(m_frame_graph_ptr != nullptr);

        goto end;
    }

    /* Continue with other managers.. */
    m_buffer_manager_ptr = OpenGL::VKBufferManager::create(m_frontend_ptr,
                                                           this);

    if (m_buffer_manager_ptr == nullptr)
    {
        vkgl_assert(m_buffer_manager_ptr != nullptr);

        goto end;
    }

    m_gfx_pipeline_manager_ptr = OpenGL::VKGFXPipelineManager::create(this,
                                                                      m_frontend_ptr);

    if (m_gfx_pipeline_manager_ptr == nullptr)
    {
        vkgl_assert(m_gfx_pipeline_manager_ptr != nullptr);

        goto end;
    }

    m_spirv_manager_ptr = OpenGL::VKSPIRVManager::create(this,
                                                         m_frontend_ptr);

    if (m_spirv_manager_ptr == nullptr)
    {
        vkgl_assert(m_spirv_manager_ptr != nullptr);

        goto end;
    }

    /* OK, go ahead and proceed with kicking off the scheduler. */
    m_scheduler_ptr = OpenGL::VKScheduler::create(in_callback_ptr,
                                                  this);

    if (m_scheduler_ptr == nullptr)
    {
        vkgl_assert(m_scheduler_ptr != nullptr);
    }

end:
    ;
}

void OpenGL::VKBackend::set_target_window(HWND in_opt_window_handle)
{
    /* Forward the notification to swapchain manager. */
    vkgl_assert(m_swapchain_manager_ptr != nullptr);

    m_swapchain_manager_ptr->set_target_window(in_opt_window_handle);
}

void OpenGL::VKBackend::tex_image_1d(const GLuint&                 in_id,
                                     const int32_t&                in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const int32_t&                in_width,
                                     const int32_t&                in_border,
                                     const OpenGL::PixelFormat&    in_format,
                                     const OpenGL::PixelType&      in_type,
                                     const void*                   in_pixels_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_image_2d(const GLuint&                 in_id,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei&                in_width,
                                     const GLsizei&                in_height,
                                     const GLint&                  in_border,
                                     const OpenGL::PixelFormat&    in_format,
                                     const OpenGL::PixelType&      in_type,
                                     const void*                   in_pixels_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_image_3d(const GLuint&                 in_id,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei&                in_width,
                                     const GLsizei&                in_height,
                                     const GLsizei&                in_depth,
                                     const GLint&                  in_border,
                                     const OpenGL::PixelFormat&    in_format,
                                     const OpenGL::PixelType&      in_type,
                                     const void*                   in_pixels_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_sub_image_1d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLsizei&             in_width,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_sub_image_2d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLint&               in_yoffset,
                                         const GLsizei&             in_width,
                                         const GLsizei&             in_height,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::tex_sub_image_3d(const GLuint&              in_id,
                                         const GLint&               in_level,
                                         const GLint&               in_xoffset,
                                         const GLint&               in_yoffset,
                                         const GLint&               in_zoffset,
                                         const GLsizei&             in_width,
                                         const GLsizei&             in_height,
                                         const GLsizei&             in_depth,
                                         const OpenGL::PixelFormat& in_format,
                                         const OpenGL::PixelType&   in_type,
                                         const void*                in_pixels)
{
    vkgl_not_implemented();
}

bool OpenGL::VKBackend::unmap_buffer(const GLuint& in_id)
{
    vkgl_not_implemented();

    return false;
}

void OpenGL::VKBackend::validate_program(const GLuint& in_program_id)
{
    vkgl_not_implemented();
}

