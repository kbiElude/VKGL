/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/types.h"
#include "OpenGL/converters.h"
#include "OpenGL/backend/vk_backend.h"

OpenGL::VKBackend::VKBackend()
{
    // todo
}

OpenGL::VKBackend::~VKBackend()
{
    // todo
}

void OpenGL::VKBackend::buffer_data(const GLuint&     in_id,
                                    const GLsizeiptr& in_size,
                                    const void*       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::buffer_sub_data(const GLuint&     in_id,
                                        const GLsizeiptr& in_start_offset,
                                        const GLsizeiptr& in_size,
                                        const void*       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
    vkgl_not_implemented();
}

void OpenGL::VKBackend::compile_shader(const GLuint& in_id)
{
    vkgl_not_implemented();
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

OpenGL::VKBackendUniquePtr OpenGL::VKBackend::create()
{
    OpenGL::VKBackendUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::VKBackend() );

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
    vkgl_not_implemented();
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
    vkgl_not_implemented();
}

void OpenGL::VKBackend::flush()
{
    vkgl_not_implemented();
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

    result = init_capabilities();

    return result;
}

bool OpenGL::VKBackend::init_capabilities()
{
    static const float    dummy_data_f32[2] = {0, 0}; /* todo */
    static const uint32_t dummy_data_u32[2] = {0, 0}; /* todo */

    m_capabilities = decltype(m_capabilities)
    {
        {OpenGL::BackendCapability::Aliased_Line_Width_Range,                      CapabilityData(dummy_data_f32, 2)},
        {OpenGL::BackendCapability::Max_3D_Texture_Size,                           CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Array_Texture_Layers,                      CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Clip_Distances,                            CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Color_Attachments,                         CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Color_Texture_Samples,                     CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Combined_Fragment_Uniform_Components,      CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Combined_Geometry_Uniform_Components,      CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Combined_Texture_Image_Units,              CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Combined_Vertex_Uniform_Components,        CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Combined_Uniform_Blocks,                   CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Cube_Map_Texture_Size,                     CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Depth_Texture_Samples,                     CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Draw_Buffers,                              CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Elements_Indices,                          CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Elements_Vertices,                         CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Fragment_Input_Components,                 CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Fragment_Uniform_Blocks,                   CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Fragment_Uniform_Components,               CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Input_Components,                 CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Output_Components,                CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Output_Vertices,                  CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Texture_Image_Units,              CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Total_Output_Components,          CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Uniform_Blocks,                   CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Geometry_Uniform_Components,               CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Integer_Samples,                           CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Program_Texel_Offset,                      CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Rectangle_Texture_Size,                    CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Renderbuffer_Size,                         CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Sample_Mask_Words,                         CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Samples,                                   CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Server_Wait_Timeout,                       CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Texture_Buffer_Size,                       CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Texture_Image_Units,                       CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Texture_LOD_Bias,                          CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Texture_Size,                              CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Buffers,                CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Interleaved_Components, CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Attribs,       CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Transform_Feedback_Separate_Components,    CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Uniform_Block_Size,                        CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Uniform_Buffer_Bindings,                   CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Varying_Components,                        CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Vertex_Attribs,                            CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Vertex_Output_Components,                  CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Vertex_Texture_Image_Units,                CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Vertex_Uniform_Blocks,                     CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Vertex_Uniform_Components,                 CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Max_Viewport_Dims,                             CapabilityData(dummy_data_u32, 2)},
        {OpenGL::BackendCapability::Min_Program_Texel_Offset,                      CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Point_Fade_Threshold_Size,                     CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Point_Size_Granularity,                        CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Point_Size_Range,                              CapabilityData(dummy_data_f32, 2)},
        {OpenGL::BackendCapability::Query_Counter_Bits,                            CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Smooth_Line_Width_Granularity,                 CapabilityData(dummy_data_f32, 1)},
        {OpenGL::BackendCapability::Smooth_Line_Width_Range,                       CapabilityData(dummy_data_f32, 2)},
        {OpenGL::BackendCapability::Subpixel_Bits,                                 CapabilityData(dummy_data_u32, 1)},
        {OpenGL::BackendCapability::Uniform_Buffer_Offset_Alignment,               CapabilityData(dummy_data_u32, 1)},
    };

    return true;
}

void OpenGL::VKBackend::link_program(const GLuint& in_program_id)
{
    vkgl_not_implemented();
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

