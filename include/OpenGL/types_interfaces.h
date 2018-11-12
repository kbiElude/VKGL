/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_INTERFACES_H
#define VKGL_TYPES_INTERFACES_H

namespace OpenGL
{
    class IBackend
    {
    public:
        virtual ~IBackend()
        {
            /* Stub */
        }

        virtual VKBufferManager*        get_buffer_manager_ptr   () const = 0;
        virtual Anvil::BaseDevice*      get_device_ptr           () const = 0;
        virtual VKFormatManager*        get_format_manager_ptr   () const = 0;
        virtual VKFrameGraph*           get_frame_graph_ptr      () const = 0;
        virtual Anvil::MemoryAllocator* get_memory_allocator_ptr () const = 0;
        virtual VKSPIRVManager*         get_spirv_manager_ptr    () const = 0;
        virtual VKSwapchainManager*     get_swapchain_manager_ptr() const = 0;
        virtual ThreadPool*             get_thread_pool_ptr      () const = 0;
    };

    class IBackendCapabilities
    {
    public:
        virtual ~IBackendCapabilities()
        {
            /* Stub */
        }

        virtual void get_capability(const OpenGL::BackendCapability&  in_capability,
                                    const OpenGL::GetSetArgumentType& in_arg_type,
                                    const uint32_t&                   in_n_vals,
                                    void*                             out_result_ptr) const = 0;
    };

    class IBackendGLCallbacks
    {
    public:
        virtual ~IBackendGLCallbacks()
        {
            /* Stub */
        }

        virtual VKSPIRVManager* get_spirv_manager_ptr() const = 0;

        virtual void on_objects_created  (const OpenGL::ObjectType& in_object_type,
                                          const uint32_t&           in_n_ids,
                                          const GLuint*             in_ids_ptr)    = 0;
        virtual void on_objects_destroyed(const OpenGL::ObjectType& in_object_type,
                                          const uint32_t&           in_n_ids,
                                          const GLuint*             in_ids_ptr)    = 0;

        virtual void  buffer_data              (const GLuint&               in_id,
                                                const GLsizeiptr&           in_size,
                                                const void*                 in_data_ptr) = 0;
        virtual void  buffer_sub_data          (const GLuint&               in_id,
                                                const GLsizeiptr&           in_start_offset,
                                                const GLsizeiptr&           in_size,
                                                const void*                 in_data_ptr) = 0;
        virtual void  copy_buffer_sub_data     (const GLuint&               in_read_buffer_id,
                                                const GLuint&               in_write_buffer_id,
                                                const GLintptr&             in_read_offset,
                                                const GLintptr&             in_write_offset,
                                                const GLsizeiptr&           in_size) = 0;
        virtual void  flush_mapped_buffer_range(const GLuint&               in_id,
                                                const GLintptr&             in_offset,
                                                const GLsizeiptr&           in_length) = 0;
        virtual void  get_buffer_sub_data      (const GLuint&               in_id,
                                                const GLintptr&             in_offset,
                                                const GLsizeiptr&           in_size,
                                                void*                       out_data_ptr) = 0;
        virtual void* map_buffer               (const GLuint&               in_id,
                                                const OpenGL::BufferAccess& in_access,
                                                const GLintptr&             in_start_offset,
                                                const GLsizeiptr&           in_length) = 0;
        virtual bool  unmap_buffer             (const GLuint&               in_id) = 0;

        virtual void compile_shader  (const GLuint& in_id)         = 0;
        virtual void link_program    (const GLuint& in_program_id) = 0;
        virtual void validate_program(const GLuint& in_program_id) = 0;

        virtual void draw_arrays        (const OpenGL::DrawCallMode&      in_mode,
                                         const GLint&                     in_first,
                                         const GLsizei&                   in_count) = 0;
        virtual void draw_elements      (const OpenGL::DrawCallMode&      in_mode,
                                         const GLsizei&                   in_count,
                                         const OpenGL::DrawCallIndexType& in_type,
                                         const void*                      in_indices) = 0;
        virtual void draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                         const GLuint&                    in_start,
                                         const GLuint&                    in_end,
                                         const GLsizei&                   in_count,
                                         const OpenGL::DrawCallIndexType& in_type,
                                         const void*                      in_indices) = 0;
        virtual void multi_draw_arrays  (const OpenGL::DrawCallMode&      in_mode,
                                         const GLint*                     in_first_ptr,
                                         const GLsizei*                   in_count_ptr,
                                         const GLsizei&                   in_drawcount) = 0;
        virtual void multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                         const GLsizei*                   in_count_ptr,
                                         const OpenGL::DrawCallIndexType& in_type,
                                         const void* const*               in_indices_ptr,
                                         const GLsizei&                   in_drawcount) = 0;

        virtual void finish() = 0;
        virtual void flush () = 0;

        virtual void clear                   (const OpenGL::ClearBufferBits& in_buffers_to_clear) = 0;
        virtual void get_compressed_tex_image(const GLuint&                  in_id,
                                              const GLint&                   in_level,
                                              void*                          in_img) = 0;
        virtual void get_texture_image       (const GLuint&                  in_id,
                                              const uint32_t&                in_level,
                                              const OpenGL::PixelFormat&     in_format,
                                              const OpenGL::PixelType&       in_type,
                                              void*                          out_pixels_ptr) = 0;
        virtual void read_pixels             (const int32_t&                 in_x,
                                              const int32_t&                 in_y,
                                              const size_t&                  in_width,
                                              const size_t&                  in_height,
                                              const OpenGL::PixelFormat&     in_format,
                                              const OpenGL::PixelType&       in_type,
                                              void*                          out_pixels_ptr) = 0;

        virtual void renderbuffer_storage(const GLuint&                 in_id,
                                          const OpenGL::InternalFormat& in_internalformat,
                                          const uint32_t&               in_width,
                                          const uint32_t&               in_height,
                                          const uint32_t&               in_samples) = 0;

        virtual void copy_tex_image_1d(const GLuint&                 in_id,
                                       const GLint                   in_level,
                                       const OpenGL::InternalFormat& in_internalformat,
                                       const GLint&                  in_x,
                                       const GLint&                  in_y,
                                       const GLsizei&                in_width,
                                       const GLint&                  in_border) = 0;
        virtual void copy_tex_image_2d(const GLuint&                 in_id,
                                       const GLint&                  in_level,
                                       const OpenGL::InternalFormat& in_internalformat,
                                       const GLint&                  in_x,
                                       const GLint&                  in_y,
                                       const GLsizei&                in_width,
                                       const GLsizei&                in_height,
                                       const GLint&                  in_border) = 0;

        virtual void copy_tex_sub_image_1d(const GLuint&  in_id,
                                           const GLint&   in_level,
                                           const GLint&   in_xoffset,
                                           const GLint&   in_x,
                                           const GLint&   in_y,
                                           const GLsizei& in_width) = 0;
        virtual void copy_tex_sub_image_2d(const GLuint&  in_id,
                                           const GLint&   in_level,
                                           const GLint&   in_xoffset,
                                           const GLint&   in_yoffset,
                                           const GLint&   in_x,
                                           const GLint&   in_y,
                                           const GLsizei& in_width,
                                           const GLsizei& in_height) = 0;
        virtual void copy_tex_sub_image_3d(const GLuint&  in_id,
                                           const GLint&   in_level,
                                           const GLint&   in_xoffset,
                                           const GLint&   in_yoffset,
                                           const GLint&   in_zoffset,
                                           const GLint&   in_x,
                                           const GLint&   in_y,
                                           const GLsizei& in_width,
                                           const GLsizei& in_height) = 0;

        virtual void compressed_tex_image_1d(const GLuint&                  in_id,
                                             const GLint&                   in_level,
                                             const OpenGL::InternalFormat&  in_internalformat,
                                             const GLsizei                  in_width,
                                             const GLint                    in_border,
                                             const GLsizei                  in_image_size,
                                             const void*                    in_data) = 0;
        virtual void compressed_tex_image_2d(const GLuint&                  in_id,
                                             const GLint&                   in_level,
                                             const OpenGL::InternalFormat&  in_internalformat,
                                             const GLsizei&                 in_width,
                                             const GLsizei&                 in_height,
                                             const GLint&                   in_border,
                                             const GLsizei&                 in_image_size,
                                             const void*                    in_data) = 0;
        virtual void compressed_tex_image_3d(const GLuint&                  in_id,
                                             const GLint&                   in_level,
                                             const OpenGL::InternalFormat&  in_internalformat,
                                             const GLsizei&                 in_width,
                                             const GLsizei&                 in_height,
                                             const GLsizei&                 in_depth,
                                             const GLint&                   in_border,
                                             const GLsizei&                 in_image_size,
                                             const void*                    in_data) = 0;

        virtual void compressed_tex_sub_image_1d(const GLuint&                in_id,
                                                 const GLint&                 in_level,
                                                 const GLint&                 in_xoffset,
                                                 const GLsizei&               in_width,
                                                 const OpenGL::PixelFormat&   in_format,
                                                 const GLsizei&               in_image_size,
                                                 const void*                  in_data) = 0;
        virtual void compressed_tex_sub_image_2d(const GLuint&                in_id,
                                                 const GLint&                 in_level,
                                                 const GLint&                 in_xoffset,
                                                 const GLint&                 in_yoffset,
                                                 const GLsizei&               in_width,
                                                 const GLsizei&               in_height,
                                                 const OpenGL::PixelFormat&   in_format,
                                                 const GLsizei&               in_image_size,
                                                 const void*                  in_data) = 0;
        virtual void compressed_tex_sub_image_3d(const GLuint&                in_id,
                                                 const GLint&                 in_level,
                                                 const GLint&                 in_xoffset,
                                                 const GLint&                 in_yoffset,
                                                 const GLint&                 in_zoffset,
                                                 const GLsizei&               in_width,
                                                 const GLsizei&               in_height,
                                                 const GLsizei&               in_depth,
                                                 const OpenGL::PixelFormat&   in_format,
                                                 const GLsizei&               in_image_size,
                                                 const void*                  in_data) = 0;

        virtual void tex_image_1d(const GLuint&                 in_id,
                                  const int32_t&                in_level,
                                  const OpenGL::InternalFormat& in_internalformat,
                                  const int32_t&                in_width,
                                  const int32_t&                in_border,
                                  const OpenGL::PixelFormat&    in_format,
                                  const OpenGL::PixelType&      in_type,
                                  const void*                   in_pixels_ptr) = 0;
        virtual void tex_image_2d(const GLuint&                 in_id,
                                  const GLint&                  in_level,
                                  const OpenGL::InternalFormat& in_internalformat,
                                  const GLsizei&                in_width,
                                  const GLsizei&                in_height,
                                  const GLint&                  in_border,
                                  const OpenGL::PixelFormat&    in_format,
                                  const OpenGL::PixelType&      in_type,
                                  const void*                   in_pixels_ptr) = 0;
        virtual void tex_image_3d(const GLuint&                 in_id,
                                  const GLint&                  in_level,
                                  const OpenGL::InternalFormat& in_internalformat,
                                  const GLsizei&                in_width,
                                  const GLsizei&                in_height,
                                  const GLsizei&                in_depth,
                                  const GLint&                  in_border,
                                  const OpenGL::PixelFormat&    in_format,
                                  const OpenGL::PixelType&      in_type,
                                  const void*                   in_pixels_ptr) = 0;

        virtual void tex_sub_image_1d(const GLuint&              in_id,
                                      const GLint&               in_level,
                                      const GLint&               in_xoffset,
                                      const GLsizei&             in_width,
                                      const OpenGL::PixelFormat& in_format,
                                      const OpenGL::PixelType&   in_type,
                                      const void*                in_pixels) = 0;
        virtual void tex_sub_image_2d(const GLuint&              in_id,
                                      const GLint&               in_level,
                                      const GLint&               in_xoffset,
                                      const GLint&               in_yoffset,
                                      const GLsizei&             in_width,
                                      const GLsizei&             in_height,
                                      const OpenGL::PixelFormat& in_format,
                                      const OpenGL::PixelType&   in_type,
                                      const void*                in_pixels) = 0;
        virtual void tex_sub_image_3d(const GLuint&              in_id,
                                      const GLint&               in_level,
                                      const GLint&               in_xoffset,
                                      const GLint&               in_yoffset,
                                      const GLint&               in_zoffset,
                                      const GLsizei&             in_width,
                                      const GLsizei&             in_height,
                                      const GLsizei&             in_depth,
                                      const OpenGL::PixelFormat& in_format,
                                      const OpenGL::PixelType&   in_type,
                                      const void*                in_pixels) = 0;

        virtual void present() = 0;
    };

    class IContext
    {
    public:
        virtual ~IContext()
        {
            /* Stub */
        }

        virtual const OpenGL::DispatchTable*    get_dispatch_table      () const = 0;
        virtual const std::vector<std::string>& get_supported_extensions() const = 0;
    };

    class IContextObjectManagers
    {
    public:
        virtual ~IContextObjectManagers()
        {
            /* Stub */
        }

        /* TODO: Replace with per-manager interfaces allowing to acquire references + retrieve object properties. */
        virtual OpenGL::GLBufferManager*       get_buffer_manager_ptr      () const = 0;
        virtual OpenGL::GLFramebufferManager*  get_framebuffer_manager_ptr () const = 0;
        virtual OpenGL::GLLimits*              get_limits_ptr              () const = 0;
        virtual OpenGL::GLProgramManager*      get_program_manager_ptr     () const = 0;
        virtual OpenGL::GLRenderbufferManager* get_renderbuffer_manager_ptr() const = 0;
        virtual OpenGL::GLShaderManager*       get_shader_manager_ptr      () const = 0;
        virtual OpenGL::GLStateManager*        get_state_manager_ptr       () const = 0;
        virtual OpenGL::GLTextureManager*      get_texture_manager_ptr     () const = 0;
        virtual OpenGL::GLVAOManager*          get_vao_manager_ptr         () const = 0;
    };

    class IGLConstants
    {
    public:
        virtual ~IGLConstants()
        {
            /* Stub */
        }

        virtual const uint32_t& get_context_flags           () const = 0;
        virtual const uint32_t& get_context_profile_mask    () const = 0;
        virtual const char*     get_extensions              () const = 0;
        virtual const uint32_t& get_major_version           () const = 0;
        virtual const uint32_t& get_minor_version           () const = 0;
        virtual const char*     get_renderer                () const = 0;
        virtual const char*     get_shading_language_version() const = 0;
        virtual const char*     get_vendor                  () const = 0;
    };

    class IGLLimits
    {
    public:
        virtual ~IGLLimits()
        {
            /* Stub */
        }

        virtual const float*                               get_aliased_line_width_range_vec2                () const = 0;
        virtual const std::vector<OpenGL::InternalFormat>& get_compressed_texture_formats                   () const = 0;
        virtual uint32_t                                   get_max_3d_texture_size                          () const = 0;
        virtual uint32_t                                   get_max_array_texture_layers                     () const = 0;
        virtual uint32_t                                   get_max_clip_distances                           () const = 0;
        virtual uint32_t                                   get_max_color_attachments                        () const = 0;
        virtual uint32_t                                   get_max_color_texture_samples                    () const = 0;
        virtual uint32_t                                   get_max_combined_fragment_uniform_components     () const = 0;
        virtual uint32_t                                   get_max_combined_geometry_uniform_components     () const = 0;
        virtual uint32_t                                   get_max_combined_texture_image_units             () const = 0;
        virtual uint32_t                                   get_max_combined_vertex_uniform_components       () const = 0;
        virtual uint32_t                                   get_max_combined_uniform_blocks                  () const = 0;
        virtual uint32_t                                   get_max_cube_map_texture_size                    () const = 0;
        virtual uint32_t                                   get_max_depth_texture_samples                    () const = 0;
        virtual uint32_t                                   get_max_draw_buffers                             () const = 0;
        virtual uint32_t                                   get_max_elements_indices                         () const = 0;
        virtual uint32_t                                   get_max_elements_vertices                        () const = 0;
        virtual uint32_t                                   get_max_fragment_input_components                () const = 0;
        virtual uint32_t                                   get_max_fragment_uniform_blocks                  () const = 0;
        virtual uint32_t                                   get_max_fragment_uniform_components              () const = 0;
        virtual uint32_t                                   get_max_geometry_input_components                () const = 0;
        virtual uint32_t                                   get_max_geometry_output_components               () const = 0;
        virtual uint32_t                                   get_max_geometry_output_vertices                 () const = 0;
        virtual uint32_t                                   get_max_geometry_texture_image_units             () const = 0;
        virtual uint32_t                                   get_max_geometry_total_output_components         () const = 0;
        virtual uint32_t                                   get_max_geometry_uniform_blocks                  () const = 0;
        virtual uint32_t                                   get_max_geometry_uniform_components              () const = 0;
        virtual uint32_t                                   get_max_integer_samples                          () const = 0;
        virtual uint32_t                                   get_max_program_texel_offset                     () const = 0;
        virtual uint32_t                                   get_max_rectangle_texture_size                   () const = 0;
        virtual uint32_t                                   get_max_renderbuffer_size                        () const = 0;
        virtual uint32_t                                   get_max_sample_mask_words                        () const = 0;
        virtual uint32_t                                   get_max_samples                                  () const = 0;
        virtual uint32_t                                   get_max_server_wait_timeout                      () const = 0;
        virtual uint32_t                                   get_max_texture_buffer_size                      () const = 0;
        virtual uint32_t                                   get_max_texture_image_units                      () const = 0;
        virtual float                                      get_max_texture_lod_bias                         () const = 0;
        virtual uint32_t                                   get_max_texture_size                             () const = 0;
        virtual uint32_t                                   get_max_transform_feedback_buffers               () const = 0;
        virtual uint32_t                                   get_max_transform_feedback_interleaved_components() const = 0;
        virtual uint32_t                                   get_max_transform_feedback_separate_attribs      () const = 0;
        virtual uint32_t                                   get_max_transform_feedback_separate_components   () const = 0;
        virtual uint32_t                                   get_max_uniform_block_size                       () const = 0;
        virtual uint32_t                                   get_max_uniform_buffer_bindings                  () const = 0;
        virtual uint32_t                                   get_max_varying_components                       () const = 0;
        virtual uint32_t                                   get_max_vertex_attribs                           () const = 0;
        virtual uint32_t                                   get_max_vertex_output_components                 () const = 0;
        virtual uint32_t                                   get_max_vertex_texture_image_units               () const = 0;
        virtual uint32_t                                   get_max_vertex_uniform_blocks                    () const = 0;
        virtual uint32_t                                   get_max_vertex_uniform_components                () const = 0;
        virtual int32_t                                    get_min_program_texel_offset                     () const = 0;
        virtual float                                      get_point_size_granularity                       () const = 0;
        virtual const float*                               get_point_size_range_vec2                        () const = 0;
        virtual uint32_t                                   get_query_counter_bits                           () const = 0;
        virtual float                                      get_smooth_line_width_granularity                () const = 0;
        virtual const float*                               get_smooth_line_width_range_vec2                 () const = 0;
        virtual uint32_t                                   get_subpixel_bits                                () const = 0;
        virtual uint32_t                                   get_uniform_buffer_offset_alignment              () const = 0;
    };

    template<typename ObjectReferenceUniquePtr>
    class IGLObjectManager
    {
    public:
        virtual ~IGLObjectManager()
        {
            /* Stub */
        }

        virtual ObjectReferenceUniquePtr get_default_object_reference()                    const = 0;
        virtual bool                     is_object_deleted           (const GLuint& in_id) const = 0;
    };

    class IStateSnapshotAccessors
    {
    public:
        virtual ~IStateSnapshotAccessors()
        {
            /* Stub */
        }

        virtual std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr)     = 0;
        virtual void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                               void*       in_dst_ptr) = 0;
        virtual std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                       = 0;
    };

    class IVKBufferManager
    {
    public:
        virtual ~IVKBufferManager()
        {
            /* Stub */
        }

        virtual OpenGL::VKBufferReferenceUniquePtr acquire_object            (const GLuint&             in_id,
                                                                              OpenGL::TimeMarker        in_frontend_object_creation_time,
                                                                              OpenGL::TimeMarker        in_buffer_time_marker)                  = 0;
        virtual bool                               create_object             (const GLuint&             in_id,
                                                                              const OpenGL::TimeMarker& in_frontend_object_creation_time)       = 0;

        virtual OpenGL::TimeMarker                 get_tot_buffer_time_marker(const GLuint&             in_id,
                                                                              const OpenGL::TimeMarker& in_frontend_object_creation_time) const = 0;
    };

    class IVKFrameGraphNodeCallback
    {
    public:
        virtual ~IVKFrameGraphNodeCallback()
        {
            /* Stub */
        }

        virtual uint32_t          get_acquired_swapchain_image_index() const = 0;
        virtual Anvil::Semaphore* get_swapchain_image_acquired_sem  () const = 0;

        //< Provides a list of wait semaphores the node must wait on before proceeding with work.
        //<
        //< Can only be called by nodes reporting true via IVKFrameGraphNode::requires_manual_wait_sem_sync().
        //< Otherwise, the function will trigger an assertion failure and fail.
        virtual bool get_wait_sems(uint32_t*                         out_n_wait_sems_ptr,
                                   Anvil::Semaphore***               out_wait_sems_ptr_ptr_ptr,
                                   const Anvil::PipelineStageFlags** out_wait_sem_stage_mask_ptr_ptr) = 0;

        virtual void set_acquired_swapchain_image_index(const uint32_t&   in_index)   = 0;
        virtual void set_swapchain_image_acquired_sem  (Anvil::Semaphore* in_sem_ptr) = 0;
    };
};

#endif /* VKGL_TYPES_INTERFACES_H */