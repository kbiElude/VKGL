/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_BACKEND_H
#define VKGL_VK_BACKEND_H

#include "Anvil/include/misc/types.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    class VKBackend : public IBackendCapabilities,
                      public IBackendGLCallbacks
    {
    public:
        /* Public functions */

        static VKBackendUniquePtr create();

        ~VKBackend();

    private:
        /* Private type definitions */
        typedef struct CapabilityData
        {
            union
            {
                float    f32[2];
                int32_t  i32[2];
                uint32_t u32[2];
                uint64_t u64[2];
            } data;

            OpenGL::GetSetArgumentType data_type;
            uint32_t                   n_vals;

            CapabilityData()
            {
                data.u32[0] = 0;
                data.u32[1] = 0;
                data_type   = OpenGL::GetSetArgumentType::Unknown;
                n_vals      = 0;
            }

            CapabilityData(const float*    in_data_f32_ptr,
                           const uint32_t& in_data_n_vals)
            {
                vkgl_assert(in_data_n_vals < 3);

                data.f32[0] = (in_data_n_vals >= 1) ? in_data_f32_ptr[0] : 0;
                data.f32[1] = (in_data_n_vals >= 2) ? in_data_f32_ptr[1] : 0;
                data_type   = OpenGL::GetSetArgumentType::Float;
                n_vals      = in_data_n_vals;

            }
            CapabilityData(const int32_t*  in_data_i32_ptr,
                           const uint32_t& in_data_n_vals)
            {
                vkgl_assert(in_data_n_vals < 3);

                data.i32[0] = (in_data_n_vals >= 1) ? in_data_i32_ptr[0] : 0;
                data.i32[1] = (in_data_n_vals >= 2) ? in_data_i32_ptr[1] : 0;
                data_type   = OpenGL::GetSetArgumentType::Int;
                n_vals      = in_data_n_vals;
            }
            CapabilityData(const uint32_t* in_data_u32_ptr,
                           const uint32_t& in_data_n_vals)
            {
                vkgl_assert(in_data_n_vals < 3);

                data.u32[0] = (in_data_n_vals >= 1) ? in_data_u32_ptr[0] : 0;
                data.u32[1] = (in_data_n_vals >= 2) ? in_data_u32_ptr[1] : 0;
                data_type   = OpenGL::GetSetArgumentType::Unsigned_Int;
                n_vals      = in_data_n_vals;
            }
            CapabilityData(const uint64_t* in_data_u64_ptr,
                           const uint32_t& in_data_n_vals)
            {
                vkgl_assert(in_data_n_vals < 3);

                data.u64[0] = (in_data_n_vals >= 1) ? in_data_u64_ptr[0] : 0;
                data.u64[1] = (in_data_n_vals >= 2) ? in_data_u64_ptr[1] : 0;
                data_type   = OpenGL::GetSetArgumentType::Unsigned_Int64;
                n_vals      = in_data_n_vals;
            }
        } CapabilityData;

        /* IBackendCapabilities functions */

        void get_capability(const OpenGL::BackendCapability&  in_capability,
                            const OpenGL::GetSetArgumentType& in_arg_type,
                            const uint32_t&                   in_n_vals,
                            void*                             out_result_ptr) const final;

        /* IBackendGLCallbacks functions */

        void  buffer_data              (const GLuint&               in_id,
                                        const GLsizeiptr&           in_size,
                                        const void*                 in_data_ptr) final;
        void  buffer_sub_data          (const GLuint&               in_id,
                                        const GLsizeiptr&           in_start_offset,
                                        const GLsizeiptr&           in_size,
                                        const void*                 in_data_ptr) final;
        void  copy_buffer_sub_data     (const GLuint&               in_read_buffer_id,
                                        const GLuint&               in_write_buffer_id,
                                        const GLintptr&             in_read_offset,
                                        const GLintptr&             in_write_offset,
                                        const GLsizeiptr&           in_size) final;
        void  flush_mapped_buffer_range(const GLuint&               in_id,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_length) final;
        void  get_buffer_sub_data      (const GLuint&               in_id,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_size,
                                        void*                       out_data_ptr) final;
        void* map_buffer               (const GLuint&               in_id,
                                        const OpenGL::BufferAccess& in_access,
                                        const GLintptr&             in_start_offset,
                                        const GLsizeiptr&           in_length) final;
        bool  unmap_buffer             (const GLuint&               in_id)     final;

        void compile_shader  (const GLuint& in_id)         final;
        void link_program    (const GLuint& in_program_id) final;
        void validate_program(const GLuint& in_program_id) final;

        void draw_arrays        (const OpenGL::DrawCallMode&      in_mode,
                                 const GLint&                     in_first,
                                 const GLsizei&                   in_count) final;
        void draw_elements      (const OpenGL::DrawCallMode&      in_mode,
                                 const GLsizei&                   in_count,
                                 const OpenGL::DrawCallIndexType& in_type,
                                 const void*                      in_indices) final;
        void draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                 const GLuint&                    in_start,
                                 const GLuint&                    in_end,
                                 const GLsizei&                   in_count,
                                 const OpenGL::DrawCallIndexType& in_type,
                                 const void*                      in_indices) final;
        void multi_draw_arrays  (const OpenGL::DrawCallMode&      in_mode,
                                 const GLint*                     in_first_ptr,
                                 const GLsizei*                   in_count_ptr,
                                 const GLsizei&                   in_drawcount) final;
        void multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                 const GLsizei*                   in_count_ptr,
                                 const OpenGL::DrawCallIndexType& in_type,
                                 const void* const*               in_indices_ptr,
                                 const GLsizei&                   in_drawcount) final;

        void finish() final;
        void flush () final;

        void clear                   (const OpenGL::ClearBufferBits& in_buffers_to_clear) final;
        void get_compressed_tex_image(const GLuint&                  in_id,
                                      const GLint&                   in_level,
                                      void*                          in_img) final;
        void get_texture_image       (const GLuint&                  in_id,
                                      const uint32_t&                in_level,
                                      const OpenGL::PixelFormat&     in_format,
                                      const OpenGL::PixelType&       in_type,
                                      void*                          out_pixels_ptr) final;
        void read_pixels             (const int32_t&                 in_x,
                                      const int32_t&                 in_y,
                                      const size_t&                  in_width,
                                      const size_t&                  in_height,
                                      const OpenGL::PixelFormat&     in_format,
                                      const OpenGL::PixelType&       in_type,
                                      void*                          out_pixels_ptr) final;

        void copy_tex_image_1d(const GLuint&                 in_id,
                               const GLint                   in_level,
                               const OpenGL::InternalFormat& in_internalformat,
                               const GLint&                  in_x,
                               const GLint&                  in_y,
                               const GLsizei&                in_width,
                               const GLint&                  in_border) final;
        void copy_tex_image_2d(const GLuint&                 in_id,
                               const GLint&                  in_level,
                               const OpenGL::InternalFormat& in_internalformat,
                               const GLint&                  in_x,
                               const GLint&                  in_y,
                               const GLsizei&                in_width,
                               const GLsizei&                in_height,
                               const GLint&                  in_border) final;

        void copy_tex_sub_image_1d(const GLuint&  in_id,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width) final;
        void copy_tex_sub_image_2d(const GLuint&  in_id,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_yoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width,
                                   const GLsizei& in_height) final;
        void copy_tex_sub_image_3d(const GLuint&  in_id,
                                   const GLint&   in_level,
                                   const GLint&   in_xoffset,
                                   const GLint&   in_yoffset,
                                   const GLint&   in_zoffset,
                                   const GLint&   in_x,
                                   const GLint&   in_y,
                                   const GLsizei& in_width,
                                   const GLsizei& in_height) final;

        void compressed_tex_image_1d(const GLuint&                  in_id,
                                     const GLint&                   in_level,
                                     const OpenGL::InternalFormat&  in_internalformat,
                                     const GLsizei                  in_width,
                                     const GLint                    in_border,
                                     const GLsizei                  in_image_size,
                                     const void*                    in_data) final;
        void compressed_tex_image_2d(const GLuint&                  in_id,
                                     const GLint&                   in_level,
                                     const OpenGL::InternalFormat&  in_internalformat,
                                     const GLsizei&                 in_width,
                                     const GLsizei&                 in_height,
                                     const GLint&                   in_border,
                                     const GLsizei&                 in_image_size,
                                     const void*                    in_data) final;
        void compressed_tex_image_3d(const GLuint&                  in_id,
                                     const GLint&                   in_level,
                                     const OpenGL::InternalFormat&  in_internalformat,
                                     const GLsizei&                 in_width,
                                     const GLsizei&                 in_height,
                                     const GLsizei&                 in_depth,
                                     const GLint&                   in_border,
                                     const GLsizei&                 in_image_size,
                                     const void*                    in_data) final;

        void compressed_tex_sub_image_1d(const GLuint&                in_id,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLsizei&               in_width,
                                         const OpenGL::PixelFormat&   in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data) final;
        void compressed_tex_sub_image_2d(const GLuint&                in_id,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLint&                 in_yoffset,
                                         const GLsizei&               in_width,
                                         const GLsizei&               in_height,
                                         const OpenGL::PixelFormat&   in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data) final;
        void compressed_tex_sub_image_3d(const GLuint&                in_id,
                                         const GLint&                 in_level,
                                         const GLint&                 in_xoffset,
                                         const GLint&                 in_yoffset,
                                         const GLint&                 in_zoffset,
                                         const GLsizei&               in_width,
                                         const GLsizei&               in_height,
                                         const GLsizei&               in_depth,
                                         const OpenGL::PixelFormat&   in_format,
                                         const GLsizei&               in_image_size,
                                         const void*                  in_data) final;

        void tex_image_1d(const GLuint&                 in_id,
                          const int32_t&                in_level,
                          const OpenGL::InternalFormat& in_internalformat,
                          const int32_t&                in_width,
                          const int32_t&                in_border,
                          const OpenGL::PixelFormat&    in_format,
                          const OpenGL::PixelType&      in_type,
                          const void*                   in_pixels_ptr) final;
        void tex_image_2d(const GLuint&                 in_id,
                          const GLint&                  in_level,
                          const OpenGL::InternalFormat& in_internalformat,
                          const GLsizei&                in_width,
                          const GLsizei&                in_height,
                          const GLint&                  in_border,
                          const OpenGL::PixelFormat&    in_format,
                          const OpenGL::PixelType&      in_type,
                          const void*                   in_pixels_ptr) final;
        void tex_image_3d(const GLuint&                 in_id,
                          const GLint&                  in_level,
                          const OpenGL::InternalFormat& in_internalformat,
                          const GLsizei&                in_width,
                          const GLsizei&                in_height,
                          const GLsizei&                in_depth,
                          const GLint&                  in_border,
                          const OpenGL::PixelFormat&    in_format,
                          const OpenGL::PixelType&      in_type,
                          const void*                   in_pixels_ptr) final;

        void tex_sub_image_1d(const GLuint&              in_id,
                              const GLint&               in_level,
                              const GLint&               in_xoffset,
                              const GLsizei&             in_width,
                              const OpenGL::PixelFormat& in_format,
                              const OpenGL::PixelType&   in_type,
                              const void*                in_pixels) final;
        void tex_sub_image_2d(const GLuint&              in_id,
                              const GLint&               in_level,
                              const GLint&               in_xoffset,
                              const GLint&               in_yoffset,
                              const GLsizei&             in_width,
                              const GLsizei&             in_height,
                              const OpenGL::PixelFormat& in_format,
                              const OpenGL::PixelType&   in_type,
                              const void*                in_pixels) final;
        void tex_sub_image_3d(const GLuint&              in_id,
                              const GLint&               in_level,
                              const GLint&               in_xoffset,
                              const GLint&               in_yoffset,
                              const GLint&               in_zoffset,
                              const GLsizei&             in_width,
                              const GLsizei&             in_height,
                              const GLsizei&             in_depth,
                              const OpenGL::PixelFormat& in_format,
                              const OpenGL::PixelType&   in_type,
                              const void*                in_pixels) final;

        /* Private functions */

        VKBackend();

        bool init             ();
        bool init_anvil       ();
        bool init_capabilities();

        /* Private variables */

        std::unordered_map<OpenGL::BackendCapability, CapabilityData> m_capabilities;
        Anvil::SGPUDeviceUniquePtr                                    m_device_ptr;
        Anvil::InstanceUniquePtr                                      m_instance_ptr;
        OpenGL::VKSchedulerUniquePtr                                  m_scheduler_ptr;
    };
};
#endif /* VKGL_VK_BACKEND_H */