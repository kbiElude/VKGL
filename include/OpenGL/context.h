/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_CONTEXT_H
#define VKGL_CONTEXT_H

#include "Common/types.h"
#include "OpenGL/gl_buffer_manager.h"
#include "OpenGL/gl_constants.h"
#include "OpenGL/gl_limits.h"
#include "OpenGL/gl_shader_manager.h"
#include "OpenGL/gl_state_manager.h"
#include "OpenGL/gl_texture_manager.h"
#include "OpenGL/gl_vao_manager.h"
#include "OpenGL/scheduler.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef std::unique_ptr<OpenGL::Context> ContextUniquePtr;

    class Context : public IContext
    {
    public:
        /* Public functions */

        static ContextUniquePtr create(const VKGL::IWSIContext* in_wsi_context_ptr);

        ~Context();


        const OpenGL::DispatchTable* get_dispatch_table() const
        {
            return &m_dispatch_table;
        }

        const std::vector<std::string>& get_supported_extensions() const
        {
            return m_supported_extensions;
        }

        /* Object generation routines: */
        GLuint create_program   ();
        GLuint create_shader    (const OpenGL::ShaderType& in_type);
        void   gen_buffers      (const uint32_t&           in_n,
                                 uint32_t*                 out_ids_ptr);
        void   gen_framebuffers (const GLsizei&            in_n,
                                 GLuint*                   out_framebuffers_ptr);
        void   gen_queries      (const uint32_t&           in_n,
                                 uint32_t*                 out_ids_ptr);
        void   gen_renderbuffers(const GLsizei&            in_n,
                                 GLuint*                   out_renderbuffers_ptr);
        void   gen_textures     (const GLsizei&            in_n,
                                 GLuint*                   out_ids_ptr);
        void   gen_vertex_arrays(const GLsizei&            in_n,
                                 GLuint*                   out_arrays_ptr);


        /* Object delete routines: */
        void delete_buffers      (const GLsizei&  in_n,
                                  const uint32_t* in_ids_ptr);
        void delete_framebuffers (const GLsizei&  in_n,
                                  const uint32_t* in_framebuffers_ptr);
        void delete_program      (const GLuint&   in_id);
        void delete_queries      (const GLsizei&  in_n,
                                  const uint32_t* in_ids_ptr);
        void delete_renderbuffers(const GLsizei&  in_n,
                                  const GLuint*   in_renderbuffers_ptr);
        void delete_shader       (const GLuint&   in_id);
        void delete_sync         (const GLsync&   in_sync);
        void delete_textures     (const GLsizei&  in_n,
                                  const GLuint*   in_ids_ptr);
        void delete_vertex_arrays(const GLsizei&  in_n,
                                  const GLuint*   in_arrays_ptr);


        /* Shader objects (getters): */
        void get_shader_info_log(const GLuint&                     in_shader,
                                 const GLsizei&                    in_buf_size,
                                 GLsizei*                          inout_length_ptr,
                                 GLchar*                           out_info_log_ptr)       const;
        void get_shader_property(const GLuint&                     in_shader,
                                 const OpenGL::ShaderProperty&     in_pname,
                                 const OpenGL::GetSetArgumentType& in_params_type,
                                 const uint32_t&                   in_n_params_components,
                                 GLint*                            out_params_ptr)         const;
        void get_shader_source  (const GLuint&                     in_shader,
                                 const GLsizei&                    in_buf_size,
                                 GLsizei*                          inout_length_ptr,
                                 GLchar*                           out_source_ptr)         const;
        bool is_shader          (const GLuint&                     in_shader)              const;

        /* Shader objects (operations): */
        void compile_shader(const GLuint& in_shader);


        /* Program objects (getters): */
        void  get_active_attrib  (const GLuint&         in_program,
                                  const GLuint&         in_index,
                                  const GLsizei&        in_buf_size,
                                  GLsizei*              out_length_ptr,
                                  GLint*                out_size_ptr,
                                  OpenGL::VariableType* out_type_ptr,
                                  GLchar*               out_name_ptr) const;
        GLint get_attrib_location(const GLuint&         in_program,
                                  const GLchar*         in_name)      const;

        void  get_active_uniform     (const GLuint&                     in_program,
                                      const GLuint&                     in_index,
                                      const GLsizei&                    in_buf_size,
                                      GLsizei*                          out_length_ptr,
                                      GLint*                            out_size_ptr,
                                      OpenGL::VariableType*             out_type_ptr,
                                      GLchar*                           out_name_ptr) const;
        void  get_active_uniform_name(const GLuint&                     in_program,
                                      const GLuint&                     in_uniform_index,
                                      const GLsizei&                    in_buf_size,
                                      GLsizei*                          inout_length_ptr,
                                      GLchar*                           out_uniform_name_ptr) const;
        void  get_active_uniforms    (const GLuint&                     in_program,
                                      const GLsizei&                    in_uniform_count,
                                      const GLuint*                     in_uniform_indices_ptr,
                                      const OpenGL::UniformProperty&    in_pname,
                                      GLint*                            out_params_ptr) const;
        void  get_uniform_indices    (const GLuint&                     in_program,
                                      const GLsizei&                    in_uniform_count,
                                      const GLchar* const*              in_uniform_names_ptr_ptr,
                                      GLuint*                           out_uniform_indices_ptr) const;
        GLint get_uniform_location   (const GLuint&                     in_program,
                                      const GLchar*                     in_name) const;
        void  get_uniform_value      (const GLuint&                     in_program,
                                      const GLint&                      in_location,
                                      const OpenGL::GetSetArgumentType& in_params_type,
                                      void*                             out_params_ptr);

        void   get_active_uniform_block_name    (const GLuint&                       in_program,
                                                 const GLuint&                       in_uniform_block_index,
                                                 const GLsizei&                      in_buf_size_ptr,
                                                 GLsizei*                            inout_length_ptr,
                                                 GLchar*                             out_uniform_block_name_ptr) const;
        void   get_active_uniform_block_property(const GLuint&                       in_program,
                                                 const GLuint&                       in_uniform_block_index,
                                                 const OpenGL::UniformBlockProperty& in_pname,
                                                 const OpenGL::GetSetArgumentType&   in_params_type,
                                                 void*                               out_params_ptr) const;
        GLuint get_uniform_block_index          (const GLuint&                       in_program,
                                                 const GLchar*                       in_uniform_block_name) const;

        void  get_attached_shaders  (const GLuint&                     in_program,
                                     const GLsizei&                    in_max_count,
                                     GLsizei*                          out_count_ptr,
                                     GLuint*                           out_shaders_ptr)       const;
        GLint get_frag_data_location(const GLuint&                     in_program,
                                     const GLchar*                     in_name_ptr)           const;
        void  get_program_info_log  (const GLuint&                     in_program,
                                     const GLsizei&                    in_buf_size,
                                     GLsizei*                          inout_length_ptr,
                                     GLchar*                           out_info_log_ptr)      const;
        void  get_program_property  (const GLuint&                     in_program,
                                     const OpenGL::ProgramProperty&    in_pname,
                                     const OpenGL::GetSetArgumentType& in_params_type,
                                     const uint32_t&                   in_n_params_components,
                                     void*                             out_params_ptr)        const;
        bool  is_program            (const GLuint&                     in_program)            const;

        /* Program objects (operations): */
        void attach_shader          (const GLuint& in_program,
                                     const GLuint& in_shader);
        void bind_attrib_location   (const GLuint& in_program,
                                     const GLuint& in_index,
                                     const GLchar* in_name);
        void bind_frag_data_location(const GLuint& in_program,
                                     const GLuint& in_color,
                                     const GLchar* in_name);
        void detach_shader          (const GLuint& in_program,
                                     const GLuint& in_shader);
        void link_program           (const GLuint& in_program);
        void use_program            (const GLuint& in_program);
        void validate_program       (const GLuint& in_program);

        /* Program objects (setters): */
        void set_matrix_uniform       (const GLint&                      in_location,
                                       const uint32_t&                   in_n_columns,
                                       const uint32_t&                   in_n_rows,
                                       const uint32_t&                   in_n_array_items,
                                       const bool&                       in_transpose,
                                       const GLfloat*                    in_value_ptr);
        void set_shader_source        (const GLuint&                     in_shader,
                                       const GLsizei&                    in_count,
                                       const GLchar* const*              in_string_ptr_ptr,
                                       const GLint*                      in_length_ptr);
        void set_uniform              (const GLint&                      in_location,
                                       const OpenGL::GetSetArgumentType& in_data_type,
                                       const uint32_t&                   in_n_components,
                                       const uint32_t&                   in_n_array_items,
                                       const void*                       in_data_ptr);
        void set_uniform_block_binding(const GLuint&                     in_program,
                                       const GLuint&                     in_uniform_block_index,
                                       const GLuint&                     in_uniform_block_binding);


        /* Conditional rendering (operations): */
        void begin_conditional_render(const GLuint&                        in_occlusion_query_id,
                                      const OpenGL::ConditionalRenderMode& in_mode);
        void end_conditional_render  ();


        /* Transform feedback (operations): */
        void begin_transform_feedback(const OpenGL::TransformFeedbackPrimitiveMode& in_primitive_mode);
        void end_transform_feedback  ();

        /* Transform feedback (getters): */
        void get_transform_feedback_varying(const GLuint&         in_program,
                                            const GLuint&         in_index,
                                            const GLsizei&        in_buf_size,
                                            GLsizei*              out_length_ptr,
                                            GLsizei*              out_size_ptr,
                                            OpenGL::VariableType* out_type_ptr,
                                            GLchar*               out_name_ptr) const;

        /* Transform feedback (setters): */
        void set_transform_feedback_varyings(const GLuint&                              in_program,
                                             const GLsizei&                             in_count,
                                             const GLchar* const*                       in_varyings_ptr_ptr,
                                             const OpenGL::TransformFeedbackBufferMode& in_buffer_mode);


        /* Framebuffer objects (getters): */
        OpenGL::FramebufferStatus check_framebuffer_status           (const OpenGL::FramebufferTarget&             in_target)      const;
        void                      get_framebuffer_attachment_property(const OpenGL::FramebufferTarget&             in_target,
                                                                      const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                                                      const OpenGL::FramebufferAttachmentProperty& in_pname,
                                                                      const OpenGL::GetSetArgumentType&            in_params_type,
                                                                      void*                                        out_params_ptr) const;
        bool                      is_framebuffer                     (const GLuint&                                in_framebuffer) const;

        /* Framebuffer objects (operations): */
        void blit_framebuffer(const GLint&                      in_src_x0,
                              const GLint&                      in_src_y0,
                              const GLint&                      in_src_x1,
                              const GLint&                      in_src_y1,
                              const GLint&                      in_dst_x0,
                              const GLint&                      in_dst_y0,
                              const GLint&                      in_dst_x1,
                              const GLint&                      in_dst_y1,
                              const OpenGL::BlitMaskBits&       in_mask,
                              const OpenGL::BlitFilter&         in_filter);
        void clear           (const OpenGL::ClearBufferBits&    in_buffers_to_clear);
        void clear_buffer    (const OpenGL::ClearBuffer&        in_buffer,
                              const GLint&                      in_drawbuffer,
                              const OpenGL::GetSetArgumentType& in_color_arg_type,
                              const uint32_t&                   in_color_n_components,
                              const void*                       in_color_data_ptr,
                              const GLfloat&                    in_depth,
                              const GLint&                      in_stencil);
        void read_pixels     (const int32_t&                    in_x,
                              const int32_t&                    in_y,
                              const size_t&                     in_width,
                              const size_t&                     in_height,
                              const OpenGL::PixelFormat&        in_format,
                              const OpenGL::PixelType&          in_type,
                              void*                             out_pixels_ptr);

        /* Framebuffer objects (setters): */
        void framebuffer_renderbuffer (const OpenGL::FramebufferTarget&             in_target,
                                       const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                       const OpenGL::RenderbufferTarget&            in_renderbuffertarget,
                                       const GLuint&                                in_renderbuffer);
        void framebuffer_texture      (const OpenGL::FramebufferTarget&             in_target,
                                       const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                       const GLuint&                                in_texture,
                                       const GLint&                                 in_level);
        void framebuffer_texture_1D   (const OpenGL::FramebufferTarget&             in_target,
                                       const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                       const OpenGL::TextureTarget&                 in_textarget,
                                       const GLuint&                                in_texture,
                                       const GLint&                                 in_level);
        void framebuffer_texture_2D   (const OpenGL::FramebufferTarget&             in_target,
                                       const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                       const OpenGL::TextureTarget&                 in_textarget,
                                       const GLuint&                                in_texture,
                                       const GLint&                                 in_level);
        void framebuffer_texture_3D   (const OpenGL::FramebufferTarget&             in_target,
                                       const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                       const OpenGL::TextureTarget&                 in_textarget,
                                       const GLuint&                                in_texture,
                                       const GLint&                                 in_level,
                                       const GLint&                                 in_zoffset);
        void framebuffer_texture_layer(const OpenGL::FramebufferTarget&             in_target,
                                       const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                       const GLuint&                                in_texture,
                                       const GLint&                                 in_level,
                                       const GLint&                                 in_layer);


        /* Renderbuffer objects (getters): */
        void get_renderbuffer_property(const OpenGL::RenderbufferTarget&   in_target,
                                       const OpenGL::RenderbufferProperty& in_pname,
                                       const OpenGL::GetSetArgumentType&   in_params_type,
                                       void*                               out_params_ptr) const;
        bool is_renderbuffer          (const GLuint&                       in_renderbuffer) const;

        /* Renderbuffer objects (setters): */
        void set_renderbuffer_storage            (const OpenGL::RenderbufferTarget& in_target,
                                                  const OpenGL::InternalFormat&     in_internalformat,
                                                  const GLsizei&                    in_width,
                                                  const GLsizei&                    in_height);
        void set_renderbuffer_storage_multisample(const OpenGL::RenderbufferTarget& in_target,
                                                  const GLsizei&                    in_samples,
                                                  const OpenGL::InternalFormat&     in_internalformat,
                                                  const GLsizei&                    in_width,
                                                  const GLsizei&                    in_height);


        /* Vertex attributes and attribute arrays (getters): */
        void get_vertex_attrib_pointer_property(const GLuint&                                 in_index,
                                                const OpenGL::VertexAttributePointerProperty& in_pname,
                                                void**                                        out_pointer_ptr) const;
        void get_vertex_attribute_property     (const GLuint&                                 in_index,
                                                const OpenGL::VertexAttributeProperty&        in_pname,
                                                const OpenGL::GetSetArgumentType&             in_src_type,
                                                const OpenGL::GetSetArgumentType&             in_dst_type,
                                                void*                                         out_params_ptr) const;
        bool is_vertex_array                   (const GLuint&                                 in_array) const;


        /* Vertex attributes and attribute arrays (setters): */
        void disable_vertex_attrib_array(const GLuint&                           in_index);
        void enable_vertex_attrib_array (const GLuint&                           in_index);
        void set_vertex_attribute       (const GLuint&                           in_index,
                                         const OpenGL::GetSetArgumentType&       in_src_type,
                                         const OpenGL::GetSetArgumentType&       in_dst_type,
                                         const uint32_t&                         in_n_components,
                                         const bool&                             in_normalized,
                                         const void*                             in_data_ptr);
        void set_vertex_attrib_pointer  (const GLuint&                           in_index,
                                         const GLint&                            in_size,
                                         const OpenGL::VertexAttributeArrayType& in_type,
                                         const OpenGL::GetSetArgumentType&       in_data_type,
                                         const bool&                             in_normalized,
                                         const GLsizei&                          in_stride,
                                         const void*                             in_pointer_ptr);


        /* Sync objects (getters): */
        void get_sync_property(const GLsync&                     in_sync,
                               const GLenum&                     in_pname,
                               const OpenGL::GetSetArgumentType& in_values_type,
                               const GLsizei&                    in_buf_size,
                               GLsizei*                          inout_length_ptr,
                               void*                             out_values_ptr) const;
        bool is_sync          (const GLsync&                     in_sync);

        /* Sync objects (operations): */
        OpenGL::WaitResult client_wait_sync(const GLsync&                in_sync,
                                            const OpenGL::WaitSyncBits&  in_flags,
                                            const GLuint64&              in_timeout);
        GLsync             fence_sync      (const OpenGL::SyncCondition& in_condition);
        void               wait_sync       (const GLsync&                in_sync,
                                            const GLuint64&              in_timeout);


        /* Buffer objects (getters): */
        void get_buffer_pointerv(const OpenGL::BufferTarget&          in_target,
                                 const OpenGL::BufferPointerProperty& in_pname,
                                 void**                               out_params_ptr) const;
        void get_buffer_property(const OpenGL::BufferTarget&          in_target,
                                 const OpenGL::BufferProperty&        in_pname,
                                 const OpenGL::GetSetArgumentType&    in_arg_type,
                                 const uint32_t&                      in_n_args,
                                 void*                                out_result_ptr) const;
        bool is_buffer          (const GLuint&                        in_id)          const;

        /* Buffer objects (operations): */
        void buffer_data        (const OpenGL::BufferTarget& in_target,
                                 const GLsizeiptr&           in_size,
                                 const void*                 in_data_ptr,
                                 const OpenGL::BufferUsage&  in_usage);
        void buffer_sub_data    (const OpenGL::BufferTarget& in_target,
                                 const GLintptr&             in_offset,
                                 const GLsizeiptr&           in_size,
                                 const void*                 in_data_ptr);
        void get_buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                 const GLintptr&             in_offset,
                                 const GLsizeiptr&           in_size,
                                 void*                       out_data_ptr);

        void copy_buffer_sub_data(const OpenGL::BufferTarget& in_read_target,
                                  const OpenGL::BufferTarget& in_write_target,
                                  const GLintptr&             in_read_offset,
                                  const GLintptr&             in_write_offset,
                                  const GLsizeiptr&           in_size);

        void  flush_mapped_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_length);
        void* map_buffer               (const OpenGL::BufferTarget& in_target,
                                        const OpenGL::BufferAccess& in_access);
        void* map_buffer_range         (const OpenGL::BufferTarget& in_target,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_length,
                                        const OpenGL::BufferAccess& in_access);
        bool  unmap_buffer             (const OpenGL::BufferTarget& in_target);


        /* Texture objects (getters): */
        void get_texture_level_parameter(const OpenGL::TextureTarget&        in_target,
                                         const int32_t&                      in_level,
                                         const OpenGL::TextureLevelProperty& in_pname,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         void*                               out_params_ptr) const;
        void get_texture_parameter      (const OpenGL::TextureTarget&        in_target,
                                         const OpenGL::TextureProperty&      in_property,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         void*                               out_arg_value_ptr) const;
        bool is_texture                 (const GLuint&                       in_texture)        const;

        /* Texture objects (operations): */
        void compressed_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei                 in_width,
                                     const GLint                   in_border,
                                     const GLsizei                 in_image_size,
                                     const void*                   in_data);
        void compressed_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei&                in_width,
                                     const GLsizei&                in_height,
                                     const GLint&                  in_border,
                                     const GLsizei&                in_image_size,
                                     const void*                   in_data);
        void compressed_tex_image_3d(const OpenGL::TextureTarget&  in_target,
                                     const GLint&                  in_level,
                                     const OpenGL::InternalFormat& in_internalformat,
                                     const GLsizei&                in_width,
                                     const GLsizei&                in_height,
                                     const GLsizei&                in_depth,
                                     const GLint&                  in_border,
                                     const GLsizei&                in_image_size,
                                     const void*                   in_data);

        void compressed_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLsizei&               in_width,
                                         const OpenGL::PixelFormat&   in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data);
        void compressed_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLint&                 in_yoffset,
                                         const GLsizei&               in_width,
                                         const GLsizei&               in_height,
                                         const OpenGL::PixelFormat&   in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data);
        void compressed_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLint&                 in_yoffset,
                                         const GLint&                 in_zoffset,
                                         const GLsizei&               in_width,
                                         const GLsizei&               in_height,
                                         const GLsizei&               in_depth,
                                         const OpenGL::PixelFormat&   in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data);

        void copy_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                               const GLint                   in_level,
                               const OpenGL::InternalFormat& in_internalformat,
                               const GLint&                  in_x,
                               const GLint&                  in_y,
                               const GLsizei&                in_width,
                               const GLint&                  in_border);
        void copy_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                               const GLint&                  in_level,
                               const OpenGL::InternalFormat& in_internalformat,
                               const GLint&                  in_x,
                               const GLint&                  in_y,
                               const GLsizei&                in_width,
                               const GLsizei&                in_height,
                               const GLint&                  in_border);

        void copy_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width);
        void copy_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLint&                 in_yoffset,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width,
                                   const GLsizei&               in_height);
        void copy_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                   const GLint&                 in_level,
                                   const GLint&                 in_xoffset,
                                   const GLint&                 in_yoffset,
                                   const GLint&                 in_zoffset,
                                   const GLint&                 in_x,
                                   const GLint&                 in_y,
                                   const GLsizei&               in_width,
                                   const GLsizei&               in_height);

        void generate_mipmap(const OpenGL::MipmapGenerationTextureTarget& in_target);

        void get_compressed_tex_image(const OpenGL::TextureTarget& in_target,
                                      const GLint&                 in_level,
                                      void*                        in_img);
        void get_texture_image       (const OpenGL::TextureTarget& in_target,
                                      const uint32_t&              in_level,
                                      const OpenGL::PixelFormat&   in_format,
                                      const OpenGL::PixelType&     in_type,
                                      void*                        out_pixels_ptr);

        void tex_buffer(const OpenGL::InternalFormat& in_internalformat,
                        const GLuint&                 in_buffer);

        void tex_image_1d            (const OpenGL::TextureTarget&  in_target,
                                      const int32_t&                in_level,
                                      const OpenGL::InternalFormat& in_internalformat,
                                      const int32_t&                in_width,
                                      const int32_t&                in_border,
                                      const OpenGL::PixelFormat&    in_format,
                                      const OpenGL::PixelType&      in_type,
                                      const void*                   in_pixels_ptr);
        void tex_image_2d            (const OpenGL::TextureTarget&  in_target,
                                      const GLint&                  in_level,
                                      const OpenGL::InternalFormat& in_internalformat,
                                      const GLsizei&                in_width,
                                      const GLsizei&                in_height,
                                      const GLint&                  in_border,
                                      const OpenGL::PixelFormat&    in_format,
                                      const OpenGL::PixelType&      in_type,
                                      const void*                   in_pixels_ptr);
        void tex_image_2d_multisample(const OpenGL::TextureTarget&  in_target,
                                      const GLsizei&                in_samples,
                                      const OpenGL::InternalFormat& in_internalformat,
                                      const GLsizei&                in_width,
                                      const GLsizei&                in_height,
                                      const bool&                   in_fixedsamplelocations);
        void tex_image_3d            (const OpenGL::TextureTarget&  in_target,
                                      const GLint&                  in_level,
                                      const OpenGL::InternalFormat& in_internalformat,
                                      const GLsizei&                in_width,
                                      const GLsizei&                in_height,
                                      const GLsizei&                in_depth,
                                      const GLint&                  in_border,
                                      const OpenGL::PixelFormat&    in_format,
                                      const OpenGL::PixelType&      in_type,
                                      const void*                   in_pixels_ptr);
        void tex_image_3d_multisample(const OpenGL::TextureTarget&  in_target,
                                      const GLsizei&                in_samples,
                                      const OpenGL::InternalFormat& in_internalformat,
                                      const GLsizei&                in_width,
                                      const GLsizei&                in_height,
                                      const GLsizei&                in_depth,
                                      const bool&                   in_fixedsamplelocations);

        void tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                              const GLint&                 in_level,
                              const GLint&                 in_xoffset,
                              const GLsizei&               in_width,
                              const OpenGL::PixelFormat&   in_format,
                              const OpenGL::PixelType&     in_type,
                              const void*                  in_pixels);
        void tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                              const GLint&                 in_level,
                              const GLint&                 in_xoffset,
                              const GLint&                 in_yoffset,
                              const GLsizei&               in_width,
                              const GLsizei&               in_height,
                              const OpenGL::PixelFormat&   in_format,
                              const OpenGL::PixelType&     in_type,
                              const void*                  in_pixels);
        void tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                              const GLint&                 in_level,
                              const GLint&                 in_xoffset,
                              const GLint&                 in_yoffset,
                              const GLint&                 in_zoffset,
                              const GLsizei&               in_width,
                              const GLsizei&               in_height,
                              const GLsizei&               in_depth,
                              const OpenGL::PixelFormat&   in_format,
                              const OpenGL::PixelType&     in_type,
                              const void*                  in_pixels);


        /* Query objects (getters): */
        void get_query_property       (const uint32_t&                    in_id,
                                       const OpenGL::QueryProperty&       in_pname,
                                       const OpenGL::GetSetArgumentType&  in_arg_type,
                                       const uint32_t&                    in_n_args,
                                       void*                              out_result_ptr) const;
        void get_query_target_property(const OpenGL::QueryTarget&         in_target,
                                       const OpenGL::QueryTargetProperty& in_pname,
                                       int32_t*                           out_params_ptr) const;
        bool is_query                 (const GLuint&                      in_id)          const;

        /* Query objects (operations): */
        void begin_query(const OpenGL::QueryTarget& in_target,
                         const uint32_t&            in_id);
        void end_query  (const OpenGL::QueryTarget& in_target);


        /* Draw calls: */
        void draw_arrays                        (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLint&                     in_first,
                                                 const GLsizei&                   in_count);
        void draw_arrays_instanced              (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLint&                     in_first,
                                                 const GLsizei&                   in_count,
                                                 const GLsizei&                   in_instancecount);
        void draw_elements                      (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLsizei&                   in_count,
                                                 const OpenGL::DrawCallIndexType& in_type,
                                                 const void*                      in_indices);
        void draw_elements_base_vertex          (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLsizei&                   in_count,
                                                 const OpenGL::DrawCallIndexType& in_type,
                                                 const void*                      in_indices,
                                                 const GLint&                     in_basevertex);
        void draw_elements_instanced            (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLsizei&                   in_count,
                                                 const OpenGL::DrawCallIndexType& in_type,
                                                 const void*                      in_indices_ptr,
                                                 const GLsizei&                   in_instancecount);
        void draw_elements_instanced_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                 const GLsizei&                   in_count,
                                                 const OpenGL::DrawCallIndexType& in_type,
                                                 const void*                      in_indices_ptr,
                                                 const GLsizei&                   in_instancecount,
                                                 const GLint&                     in_basevertex);
        void draw_range_elements                (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLuint&                    in_start,
                                                 const GLuint&                    in_end,
                                                 const GLsizei&                   in_count,
                                                 const OpenGL::DrawCallIndexType& in_type,
                                                 const void*                      in_indices);
        void draw_range_elements_base_vertex    (const OpenGL::DrawCallMode&      in_mode,
                                                 const GLuint&                    in_start,
                                                 const GLuint&                    in_end,
                                                 const GLsizei&                   in_count,
                                                 const OpenGL::DrawCallIndexType& in_type,
                                                 const void*                      in_indices,
                                                 const GLint&                     in_basevertex);

        void multi_draw_arrays              (const OpenGL::DrawCallMode&      in_mode,
                                             const GLint*                     in_first_ptr,
                                             const GLsizei*                   in_count_ptr,
                                             const GLsizei&                   in_drawcount);
        void multi_draw_elements            (const OpenGL::DrawCallMode&      in_mode,
                                             const GLsizei*                   in_count_ptr,
                                             const OpenGL::DrawCallIndexType& in_type,
                                             const void* const*               in_indices_ptr,
                                             const GLsizei&                   in_drawcount);
        void multi_draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                             const GLsizei*                   in_count_ptr,
                                             const OpenGL::DrawCallIndexType& in_type,
                                             const void* const*               in_indices_ptr,
                                             const GLsizei&                   in_drawcount,
                                             const GLint*                     in_basevertex_ptr);

        /* General context-wide state (getters): */
        OpenGL::ErrorCode get_error            ();
        void              get_parameter        (const OpenGL::ContextProperty&    in_pname,
                                                const OpenGL::GetSetArgumentType& in_arg_type,
                                                void*                             out_arg_value_ptr) const;
        void              get_parameter_indexed(const OpenGL::ContextProperty&    in_pname,
                                                const OpenGL::GetSetArgumentType& in_arg_type,
                                                const GLuint&                     in_index,
                                                void*                             out_data_ptr)      const;
        void              get_sample_position  (const GLuint&                     in_index,
                                                GLfloat*                          out_val_ptr)       const;
        bool              is_enabled           (const OpenGL::Capability&         in_capability)     const;
        bool              is_enabled_indexed   (const OpenGL::Capability&         in_capability,
                                                const GLuint&                     in_index)          const;

        /* General context-wide state (setters): */
        void bind_buffer      (const OpenGL::BufferTarget&       in_target,
                               const uint32_t&                   in_id);
        void bind_buffer_base (const OpenGL::BufferTarget&       in_target,
                               const GLuint&                     in_index,
                               const GLuint&                     in_buffer);
        void bind_buffer_range(const OpenGL::BufferTarget&       in_target,
                               const GLuint&                     in_index,
                               const GLuint&                     in_buffer,
                               const GLintptr&                   in_offset,
                               const GLsizeiptr&                 in_size);
        void bind_framebuffer (const OpenGL::FramebufferTarget&  in_target,
                               const GLuint&                     in_framebuffer);
        void bind_renderbuffer(const OpenGL::RenderbufferTarget& in_target,
                               const GLuint&                     in_renderbuffer);
        void bind_texture     (const OpenGL::TextureTarget&      in_target,
                               const uint32_t&                   in_texture);
        void bind_vertex_array(const GLuint&                     in_array);

        void disable        (const OpenGL::Capability& in_capability);
        void disable_indexed(const OpenGL::Capability& in_capability,
                             const GLuint&             in_index);
        void enable         (const OpenGL::Capability& in_capability);
        void enable_indexed (const OpenGL::Capability& in_capability,
                             const GLuint&             in_index);

        void set_active_texture             (const uint32_t&                          in_n_texture_unit);
        void set_blend_color                (const float&                             in_red,
                                             const float&                             in_green,
                                             const float&                             in_blue,
                                             const float&                             in_alpha);
        void set_blend_equation             (const OpenGL::BlendEquation&             in_blend_equation);
        void set_blend_equation_separate    (const OpenGL::BlendEquation&             in_modeRGB,
                                             const OpenGL::BlendEquation&             in_modeAlpha);
        void set_blend_functions            (const OpenGL::BlendFunction&             in_src_rgba_function,
                                             const OpenGL::BlendFunction&             in_dst_rgba_function);
        void set_blend_functions_separate   (const OpenGL::BlendFunction&             in_src_rgb_function,
                                             const OpenGL::BlendFunction&             in_dst_rgb_function,
                                             const OpenGL::BlendFunction&             in_src_alpha_function,
                                             const OpenGL::BlendFunction&             in_dst_alpha_function);
        void set_clamp_color                (const bool&                              in_enable);
        void set_clear_color_value          (const float&                             in_red,
                                             const float&                             in_green,
                                             const float&                             in_blue,
                                             const float&                             in_alpha);
        void set_clear_depth_value          (const double&                            in_value);
        void set_clear_stencil_value        (const int&                               in_value);
        void set_color_mask                 (const bool&                              in_red,
                                             const bool&                              in_green,
                                             const bool&                              in_blue,
                                             const bool&                              in_alpha);
        void set_color_mask_indexed         (const GLuint&                            in_index,
                                             const bool&                              in_r,
                                             const bool&                              in_g,
                                             const bool&                              in_b,
                                             const bool&                              in_a);
        void set_cull_mode                  (const OpenGL::CullMode&                  in_mode);
        void set_depth_function             (const OpenGL::DepthFunction&             in_function);
        void set_depth_mask                 (const bool&                              in_flag);
        void set_depth_range                (const double&                            in_near,
                                             const double&                            in_far);
        void set_draw_buffer                (const OpenGL::DrawBuffer&                in_draw_buffer);
        void set_draw_buffers               (const GLsizei&                           in_n,
                                             const OpenGL::DrawBuffer*                in_bufs_ptr);
        void set_front_face_orientation     (const OpenGL::FrontFaceOrientation&      in_orientation);
        void set_hint                       (const OpenGL::HintTarget&                in_target,
                                             const OpenGL::HintMode&                  in_mode);
        void set_line_width                 (const float&                             in_width);
        void set_logic_op                   (const OpenGL::LogicOpMode&               in_mode);
        void set_pixel_store_property       (const OpenGL::PixelStoreProperty&        in_property,
                                             const OpenGL::GetSetArgumentType&        in_arg_type,
                                             const void*                              in_arg_value_ptr);
        void set_point_property             (const OpenGL::PointProperty&             in_property,
                                             const OpenGL::GetSetArgumentType&        in_arg_type,
                                             const void*                              in_arg_value_ptr);
        void set_point_size                 (const float&                             in_size);
        void set_polygon_mode               (const OpenGL::PolygonMode&               in_mode);
        void set_polygon_offset             (const GLfloat&                           in_factor,
                                             const GLfloat&                           in_units);
        void set_primitive_restart_index    (const GLuint&                            in_index);
        void set_provoking_vertex           (const OpenGL::ProvokingVertexConvention& in_mode);
        void set_read_buffer                (const OpenGL::ReadBuffer&                in_read_buffer);
        void set_sample_coverage            (const GLfloat&                           in_value,
                                             const GLboolean&                         in_invert);
        void set_sample_mask_indexed        (const GLuint&                            in_mask_number,
                                             const GLbitfield&                        in_mask);
        void set_scissor                    (const int32_t&                           in_x,
                                             const int32_t&                           in_y,
                                             const size_t&                            in_width,
                                             const size_t&                            in_height);
        void set_stencil_function           (const OpenGL::StencilFunction&           in_func,
                                             const int32_t&                           in_ref,
                                             const uint32_t&                          in_mask);
        void set_stencil_function_separate  (const OpenGL::StencilStateFace&          in_face,
                                             const OpenGL::StencilFunction&           in_func,
                                             const GLint&                             in_ref,
                                             const GLuint&                            in_mask);
        void set_stencil_mask               (const uint32_t&                          in_mask);
        void set_stencil_mask_separate      (const OpenGL::StencilStateFace&          in_face,
                                             const GLuint&                            in_mask);
        void set_stencil_operations         (const OpenGL::StencilOperation&          in_fail,
                                             const OpenGL::StencilOperation&          in_zfail,
                                             const OpenGL::StencilOperation&          in_zpass);
        void set_stencil_operations_separate(const OpenGL::StencilStateFace&          in_face,
                                             const OpenGL::StencilOperation&          in_sfail,
                                             const OpenGL::StencilOperation&          in_dpfail,
                                             const OpenGL::StencilOperation&          in_dppass);
        void set_texture_parameter          (const OpenGL::TextureTarget&             in_target,
                                             const OpenGL::TextureProperty&           in_property,
                                             const OpenGL::GetSetArgumentType&        in_arg_type,
                                             const void*                              in_arg_value_ptr);
        void set_viewport                   (const int32_t&                           in_x,
                                             const int32_t&                           in_y,
                                             const size_t&                            in_width,
                                             const size_t&                            in_height);

        /* Other: */
        void finish();
        void flush ();

    private:
        /* Private functions */

        Context(const VKGL::IWSIContext* in_wsi_context_ptr);

        bool init                     ();
        bool init_dispatch_table      ();
        bool init_supported_extensions();

        bool set_vaa_enabled_state(const GLuint& in_index,
                                   const bool&   in_new_state);

        /* Private variables */
        OpenGL::DispatchTable    m_dispatch_table;
        std::vector<std::string> m_supported_extensions;
        const VKGL::IWSIContext* m_wsi_context_ptr;

        GLBufferManagerUniquePtr  m_gl_buffer_manager_ptr;
        GLConstantsUniquePtr      m_gl_constants_ptr;
        GLLimitsUniquePtr         m_gl_limits_ptr;
        GLShaderManagerUniquePtr  m_gl_shader_manager_ptr;
        GLStateManagerUniquePtr   m_gl_state_manager_ptr;
        GLTextureManagerUniquePtr m_gl_texture_manager_ptr;
        GLVAOManagerUniquePtr     m_gl_vao_manager_ptr;
        SchedulerUniquePtr        m_scheduler_ptr;
    };
}

#endif /* VKGL_CONTEXT_H */