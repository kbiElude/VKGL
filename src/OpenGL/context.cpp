/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/types.h"
#include "OpenGL/context.h"
#include "OpenGL/utils_enum.h"

OpenGL::Context::Context()
{
    /* Stub */
}

OpenGL::Context::~Context()
{
    /* Stub */
}

void OpenGL::Context::attach_shader(const GLuint& in_program,
                                    const GLuint& in_shader)
{
    vkgl_not_implemented();
}

void OpenGL::Context::begin_conditional_render(const GLuint&                        in_occlusion_query_id,
                                               const OpenGL::ConditionalRenderMode& in_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::begin_query(const OpenGL::QueryTarget& in_target,
                                  const uint32_t&            in_id)
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->begin_query(in_target,
                                        in_id);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::begin_transform_feedback(const OpenGL::TransformFeedbackPrimitiveMode& in_primitive_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_attrib_location(const GLuint& in_program,
                                           const GLuint& in_index,
                                           const GLchar* in_name)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_buffer(const OpenGL::BufferTarget& in_target,
                                  const uint32_t&             in_id)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_buffer_binding(in_target,
                                               in_id);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::bind_buffer_base(const OpenGL::BufferTarget& in_target,
                                       const GLuint&               in_index,
                                       const GLuint&               in_buffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLuint&               in_index,
                                        const GLuint&               in_buffer,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_size)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_frag_data_location(const GLuint& in_program,
                                              const GLuint& in_color,
                                              const GLchar* in_name)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_framebuffer(const OpenGL::FramebufferTarget& in_target,
                                       const GLuint&                    in_framebuffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_renderbuffer(const OpenGL::RenderbufferTarget& in_target,
                                        const GLuint&                     in_renderbuffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_texture(const OpenGL::TextureTarget& in_target,
                                   const uint32_t&              in_texture)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_texture_binding(m_gl_state_manager_ptr->get_state()->active_texture_unit,
                                                in_target,
                                                in_texture);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::bind_vertex_array(const GLuint& in_array)
{
    vkgl_not_implemented();
}

void OpenGL::Context::blit_framebuffer(const GLint&                in_src_x0,
                                       const GLint&                in_src_y0,
                                       const GLint&                in_src_x1,
                                       const GLint&                in_src_y1,
                                       const GLint&                in_dst_x0,
                                       const GLint&                in_dst_y0,
                                       const GLint&                in_dst_x1,
                                       const GLint&                in_dst_y1,
                                       const OpenGL::BlitMaskBits& in_mask,
                                       const OpenGL::BlitFilter&   in_filter)
{
    vkgl_not_implemented();
}

void OpenGL::Context::buffer_data(const OpenGL::BufferTarget& in_target,
                                  const GLsizeiptr&           in_size,
                                  const void*                 in_data_ptr,
                                  const OpenGL::BufferUsage&  in_usage)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    m_gl_buffer_manager_ptr->buffer_data(buffer_id,
                                         in_size,
                                         in_data_ptr,
                                         in_usage);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                      const GLintptr&             in_offset,
                                      const GLsizeiptr&           in_size,
                                      const void*                 in_data_ptr)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    m_gl_buffer_manager_ptr->buffer_sub_data(buffer_id,
                                             in_offset,
                                             in_size,
                                             in_data_ptr);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::FramebufferStatus OpenGL::Context::check_framebuffer_status(const OpenGL::FramebufferTarget& in_target) const
{
    vkgl_not_implemented();

    return OpenGL::FramebufferStatus::Unknown;
}

void OpenGL::Context::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->clear(in_buffers_to_clear);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::clear_buffer(const OpenGL::ClearBuffer&        in_buffer,
                                   const GLint&                      in_drawbuffer,
                                   const OpenGL::GetSetArgumentType& in_color_arg_type,
                                   const uint32_t&                   in_color_n_components,
                                   const void*                       in_color_data_ptr,
                                   const GLfloat&                    in_depth,
                                   const GLint&                      in_stencil)
{
    vkgl_not_implemented();
}

OpenGL::WaitResult OpenGL::Context::client_wait_sync(const GLsync&               in_sync,
                                                     const OpenGL::WaitSyncBits& in_flags,
                                                     const GLuint64&             in_timeout)
{
    vkgl_not_implemented();

    return OpenGL::WaitResult::Unknown;
}

void OpenGL::Context::compile_shader(const GLuint& in_shader)
{
    vkgl_not_implemented();
}

void OpenGL::Context::compressed_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei                 in_width,
                                              const GLint                   in_border,
                                              const GLsizei                 in_image_size,
                                              const void*                   in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_image_1d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_border,
                                             in_image_size,
                                             in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei&                in_width,
                                              const GLsizei&                in_height,
                                              const GLint&                  in_border,
                                              const GLsizei&                in_image_size,
                                              const void*                   in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_image_2d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_height,
                                             in_border,
                                             in_image_size,
                                             in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_image_3d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei&                in_width,
                                              const GLsizei&                in_height,
                                              const GLsizei&                in_depth,
                                              const GLint&                  in_border,
                                              const GLsizei&                in_image_size,
                                              const void*                   in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_image_3d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_height,
                                             in_depth,
                                             in_border,
                                             in_image_size,
                                             in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLsizei&               in_width,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_sub_image_1d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_width,
                                                 in_format,
                                                 in_image_size,
                                                 in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLint&                 in_yoffset,
                                                  const GLsizei&               in_width,
                                                  const GLsizei&               in_height,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_sub_image_2d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_yoffset,
                                                 in_width,
                                                 in_height,
                                                 in_format,
                                                 in_image_size,
                                                 in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLint&                 in_yoffset,
                                                  const GLint&                 in_zoffset,
                                                  const GLsizei&               in_width,
                                                  const GLsizei&               in_height,
                                                  const GLsizei&               in_depth,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_sub_image_3d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_yoffset,
                                                 in_zoffset,
                                                 in_width,
                                                 in_height,
                                                 in_depth,
                                                 in_format,
                                                 in_image_size,
                                                 in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_buffer_sub_data(const OpenGL::BufferTarget& in_read_target,
                                           const OpenGL::BufferTarget& in_write_target,
                                           const GLintptr&             in_read_offset,
                                           const GLintptr&             in_write_offset,
                                           const GLsizeiptr&           in_size)
{
    vkgl_not_implemented();
}

void OpenGL::Context::copy_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                        const GLint                   in_level,
                                        const OpenGL::InternalFormat& in_internalformat,
                                        const GLint&                  in_x,
                                        const GLint&                  in_y,
                                        const GLsizei&                in_width,
                                        const GLint&                  in_border)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_image_1d(texture_id,
                                       in_level,
                                       in_internalformat,
                                       in_x,
                                       in_y,
                                       in_width,
                                       in_border);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                        const GLint&                  in_level,
                                        const OpenGL::InternalFormat& in_internalformat,
                                        const GLint&                  in_x,
                                        const GLint&                  in_y,
                                        const GLsizei&                in_width,
                                        const GLsizei&                in_height,
                                        const GLint&                  in_border)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_image_2d(texture_id,
                                       in_level,
                                       in_internalformat,
                                       in_x,
                                       in_y,
                                       in_width,
                                       in_height,
                                       in_border);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_sub_image_1d(texture_id,
                                           in_level,
                                           in_xoffset,
                                           in_x,
                                           in_y,
                                           in_width);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_yoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width,
                                            const GLsizei&               in_height)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_sub_image_2d(texture_id,
                                           in_level,
                                           in_xoffset,
                                           in_yoffset,
                                           in_x,
                                           in_y,
                                           in_width,
                                           in_height);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_yoffset,
                                            const GLint&                 in_zoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width,
                                            const GLsizei&               in_height)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_sub_image_3d(texture_id,
                                           in_level,
                                           in_xoffset,
                                           in_yoffset,
                                           in_zoffset,
                                           in_x,
                                           in_y,
                                           in_width,
                                           in_height);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::ContextUniquePtr OpenGL::Context::create()
{
    OpenGL::ContextUniquePtr result_ptr;

    result_ptr.reset(
        new OpenGL::Context()
    );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

GLuint OpenGL::Context::create_program()
{
    vkgl_not_implemented();

    return 0;
}

GLuint OpenGL::Context::create_shader(const OpenGL::ShaderType& in_type)
{
    vkgl_not_implemented();

    return 0;
}

void OpenGL::Context::delete_buffers(const GLsizei&  in_n,
                                     const uint32_t* in_ids_ptr)
{
#if 0
    bool result;

    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    result = m_gl_buffer_manager_ptr->delete_ids(in_n,
                                                 in_ids_ptr);

    if (!result)
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_framebuffers(const GLsizei&  in_n,
                                          const uint32_t* in_framebuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_program (const GLuint& in_id)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_queries(const GLsizei&  in_n,
                                     const uint32_t* in_ids_ptr)
{
#if 0
    bool result;

    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    result = m_gl_query_manager_ptr->delete_ids(in_n,
                                                in_ids_ptr);

    if (!result)
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_renderbuffers(const GLsizei& in_n,
                                           const GLuint*  in_renderbuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_shader(const GLuint& in_id)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_sync(const GLsync& in_sync)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_textures(const GLsizei& in_n,
                                      const GLuint*  in_ids_ptr)
{
#if 0
    bool result;

    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    result = m_gl_texture_manager_ptr->delete_ids(in_n,
                                                  in_ids_ptr);

    if (!result)
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_vertex_arrays(const GLsizei& in_n,
                                           const GLuint*  in_arrays_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::detach_shader(const GLuint& in_program,
                                    const GLuint& in_shader)
{
    vkgl_not_implemented();
}

void OpenGL::Context::disable(const OpenGL::Capability& in_capability)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->disable(in_capability);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::disable_indexed(const OpenGL::Capability& in_capability,
                                      const GLuint&             in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::disable_vertex_attrib_array(const GLuint& in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                  const GLint&                in_first,
                                  const GLsizei&              in_count)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_arrays(in_mode,
                                 in_first,
                                 in_count);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_arrays_instanced(const OpenGL::DrawCallMode& in_mode,
                                            const GLint&                in_first,
                                            const GLsizei&              in_count,
                                            const GLsizei&              in_instancecount)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                    const GLsizei&                   in_count,
                                    const OpenGL::DrawCallIndexType& in_type,
                                    const void*                      in_indices)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_elements(in_mode,
                                   in_count,
                                   in_type,
                                   in_indices);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                const GLsizei&                   in_count,
                                                const OpenGL::DrawCallIndexType& in_type,
                                                const void*                      in_indices,
                                                const GLint&                     in_basevertex)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements_instanced(const OpenGL::DrawCallMode&      in_mode,
                                              const GLsizei&                   in_count,
                                              const OpenGL::DrawCallIndexType& in_type,
                                              const void*                      in_indices_ptr,
                                              const GLsizei&                   in_instancecount)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements_instanced_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                          const GLsizei&                   in_count,
                                                          const OpenGL::DrawCallIndexType& in_type,
                                                          const void*                      in_indices_ptr,
                                                          const GLsizei&                   in_instancecount,
                                                          const GLint&                     in_basevertex)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                          const GLuint&                    in_start,
                                          const GLuint&                    in_end,
                                          const GLsizei&                   in_count,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void*                      in_indices)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_range_elements(in_mode,
                                         in_start,
                                         in_end,
                                         in_count,
                                         in_type,
                                         in_indices);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_range_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                      const GLuint&                    in_start,
                                                      const GLuint&                    in_end,
                                                      const GLsizei&                   in_count,
                                                      const OpenGL::DrawCallIndexType& in_type,
                                                      const void*                      in_indices,
                                                      const GLint&                     in_basevertex)
{
    vkgl_not_implemented();
}

void OpenGL::Context::enable(const OpenGL::Capability& in_capability)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->enable(in_capability);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::enable_indexed(const OpenGL::Capability& in_capability,
                                     const GLuint&             in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::enable_vertex_attrib_array(const GLuint& in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::end_conditional_render()
{
    vkgl_not_implemented();
}

void OpenGL::Context::end_transform_feedback()
{
    vkgl_not_implemented();
}

void OpenGL::Context::end_query(const OpenGL::QueryTarget& in_target)
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    const auto query_id = m_gl_state_manager_ptr->get_query_binding(in_target);
    vkgl_assert(query_id != 0);

    m_gl_query_manager_ptr->end_query(query_id);
#else
    vkgl_not_implemented();
#endif
}

GLsync OpenGL::Context::fence_sync(const OpenGL::SyncCondition& in_condition)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::Context::finish()
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->finish();
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::flush()
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->flush();
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::flush_mapped_buffer_range(const OpenGL::BufferTarget& in_target,
                                                const GLintptr&             in_offset,
                                                const GLsizeiptr&           in_length)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_renderbuffer(const OpenGL::FramebufferTarget&          in_target,
                                               const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                               const OpenGL::RenderbufferTarget&         in_renderbuffertarget,
                                               const GLuint&                             in_renderbuffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture(const OpenGL::FramebufferTarget&          in_target,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          const GLuint&                             in_texture,
                                          const GLint&                              in_level)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_1D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_2D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_3D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level,
                                             const GLint&                              in_zoffset)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_layer(const OpenGL::FramebufferTarget&          in_target,
                                                const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                const GLuint&                             in_texture,
                                                const GLint&                              in_level,
                                                const GLint&                              in_layer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::generate_mipmap(const OpenGL::MipmapGenerationTextureTarget& in_target)
{
    vkgl_not_implemented();
}

void OpenGL::Context::gen_buffers(const uint32_t& in_n,
                                  uint32_t*       out_ids_ptr)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    if (!m_gl_buffer_manager_ptr->generate_ids(in_n,
                                               out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_framebuffers(const GLsizei& in_n,
                                       GLuint*        out_framebuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::gen_queries(const uint32_t& in_n,
                                  uint32_t*       out_ids_ptr)
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    if (!m_gl_query_manager_ptr->generate_ids(in_n,
                                              out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_renderbuffers(const GLsizei& in_n,
                                        GLuint*        out_renderbuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::gen_textures(const GLsizei& in_n,
                                   GLuint*        out_ids_ptr)
{
#if 0
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    if (!m_gl_texture_manager_ptr->generate_ids(in_n,
                                                in_textures) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_vertex_arrays(const GLsizei& in_n,
                                        GLuint*        out_arrays_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_attrib(const GLuint&         in_program,
                                        const GLuint&         in_index,
                                        const GLsizei&        in_buf_size,
                                        GLsizei*              out_length_ptr,
                                        GLint*                out_size_ptr,
                                        OpenGL::VariableType* out_type_ptr,
                                        GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform(const GLuint&         in_program,
                                         const GLuint&         in_index,
                                         const GLsizei&        in_buf_size,
                                         GLsizei*              out_length_ptr,
                                         GLint*                out_size_ptr,
                                         OpenGL::VariableType* out_type_ptr,
                                         GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform_block_name(const GLuint&  in_program,
                                                    const GLuint&  in_uniform_block_index,
                                                    const GLsizei& in_buf_size_ptr,
                                                    GLsizei*       inout_length_ptr,
                                                    GLchar*        out_uniform_block_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform_block_property(const GLuint&                       in_program,
                                                        const GLuint&                       in_uniform_block_index,
                                                        const OpenGL::UniformBlockProperty& in_pname,
                                                        const OpenGL::GetSetArgumentType&   in_params_type,
                                                        void*                               out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform_name(const GLuint&  in_program,
                                              const GLuint&  in_uniform_index,
                                              const GLsizei& in_buf_size,
                                              GLsizei*       inout_length_ptr,
                                              GLchar*        out_uniform_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniforms(const GLuint&                  in_program,
                                          const GLsizei&                 in_uniform_count,
                                          const GLuint*                  in_uniform_indices_ptr,
                                          const OpenGL::UniformProperty& in_pname,
                                          GLint*                         out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_attached_shaders(const GLuint&  in_program,
                                           const GLsizei& in_max_count,
                                           GLsizei*       out_count_ptr,
                                           GLuint*        out_shaders_ptr) const
{
    vkgl_not_implemented();
}

GLint OpenGL::Context::get_attrib_location(const GLuint& in_program,
                                           const GLchar* in_name) const
{
    vkgl_not_implemented();

    return -1;
}

void OpenGL::Context::get_buffer_pointerv(const OpenGL::BufferTarget&          in_target,
                                          const OpenGL::BufferPointerProperty& in_pname,
                                          void**                               out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);

    m_gl_buffer_manager_ptr->get_buffer_pointerv(buffer_id,
                                                 in_pname,
                                                 out_params_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_buffer_property(const OpenGL::BufferTarget&       in_target,
                                          const OpenGL::BufferProperty&     in_pname,
                                          const OpenGL::GetSetArgumentType& in_arg_type,
                                          const uint32_t&                   in_n_args,
                                          void*                             out_result_ptr) const
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);

    m_gl_buffer_manager_ptr->get_buffer_property(buffer_id,
                                                 in_pname,
                                                 in_arg_type,
                                                 in_n_args,
                                                 out_result_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                          const GLintptr&             in_offset,
                                          const GLsizeiptr&           in_size,
                                          void*                       out_data_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    m_scheduler_ptr->get_buffer_sub_data(buffer_id,
                                         in_offset,
                                         in_size,
                                         out_data_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_compressed_tex_image(const OpenGL::TextureTarget& in_target,
                                               const GLint&                 in_level,
                                               void*                        in_img)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    m_scheduler_ptr->get_compressed_tex_image(texture_id,
                                              in_level,
                                              in_img);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::ErrorCode OpenGL::Context::get_error()
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->get_error();
}

GLint OpenGL::Context::get_frag_data_location(const GLuint& in_program,
                                              const GLchar* in_name_ptr) const
{
    vkgl_not_implemented();

    return -1;
}

void OpenGL::Context::get_framebuffer_attachment_property(const OpenGL::FramebufferTarget&             in_target,
                                                          const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                                          const OpenGL::FramebufferAttachmentProperty& in_pname,
                                                          const OpenGL::GetSetArgumentType&            in_params_type,
                                                          void*                                        out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_parameter(const OpenGL::ContextProperty&    in_pname,
                                    const OpenGL::GetSetArgumentType& in_arg_type,
                                    void*                             out_arg_value_ptr) const
{
#if 0
    if (OpenGL::Utils::is_context_property_gl_limit(in_pname) )
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        m_gl_limits_ptr->get_parameter(in_pname,
                                       in_arg_type,
                                       out_arg_value_ptr);
    }
    else
    if (OpenGL::Utils::is_framebuffer_pname(in_pname) ) // todo: gl_doublebuffer, _drawbuffer, _drawbufferN, _readbuffer, samples, sample_buffers, stereo
    {
        todo;
    }
    else
    if (in_pname == OpenGL::ContextProperty::Renderbuffer_Binding) // todo
    {
    }
    else
    if (OpenGL::Utils::is_buffer_binding_pname(in_pname) ) // todo: buffer bindings
    {
        todo;
    }
    else
    if (OpenGL::Utils::is_gl_constant          (in_pname)  || // todo: gl_major_version, gl_minor_version, 
        OpenGL::Utils::is_texture_binding_pname(in_pname) )
    {
        vkgl_assert(m_gl_state_manager_ptr != nullptr);

        m_gl_state_manager_ptr->get_parameter(in_pname,
                                              in_arg_type,
                                              out_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_parameter_indexed(const OpenGL::ContextProperty&    in_pname,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            const GLuint&                     in_index,
                                            void*                             out_data_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_program_info_log(const GLuint&  in_program,
                                           const GLsizei& in_buf_size,
                                           GLsizei*       inout_length_ptr,
                                           GLchar*        out_info_log_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_program_property(const GLuint&                     in_program,
                                           const OpenGL::ProgramProperty&    in_pname,
                                           const OpenGL::GetSetArgumentType& in_params_type,
                                           const uint32_t&                   in_n_params_components,
                                           void*                             out_params_ptr) const
{
    vkgl_not_implemented();
}
void OpenGL::Context::get_query_property(const uint32_t&                   in_id,
                                         const OpenGL::QueryProperty&      in_pname,
                                         const OpenGL::GetSetArgumentType& in_arg_type,
                                         const uint32_t&                   in_n_args,
                                         void*                             out_result_ptr) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->get_query_property(in_id,
                                               in_pname,
                                               in_arg_type,
                                               in_n_args,
                                               out_result_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_query_target_property(const OpenGL::QueryTarget&         in_target,
                                                const OpenGL::QueryTargetProperty& in_pname,
                                                int32_t*                           out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->get_query_target_property(in_target,
                                                      in_pname,
                                                      out_params_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_renderbuffer_property(const OpenGL::RenderbufferTarget&   in_target,
                                                const OpenGL::RenderbufferProperty& in_pname,
                                                const OpenGL::GetSetArgumentType&   in_params_type,
                                                void*                               out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_sample_position(const GLuint& in_index,
                                          GLfloat*      out_val_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_info_log(const GLuint&  in_shader,
                                          const GLsizei& in_buf_size,
                                          GLsizei*       inout_length_ptr,
                                          GLchar*        out_info_log_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_property(const GLuint&                     in_shader,
                                          const OpenGL::ShaderProperty&     in_pname,
                                          const OpenGL::GetSetArgumentType& in_params_type,
                                          const uint32_t&                   in_n_params_components,
                                          GLint*                            out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_source(const GLuint&  in_shader,
                                        const GLsizei& in_buf_size,
                                        GLsizei*       inout_length_ptr,
                                        GLchar*        out_source_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_sync_property(const GLsync&                     in_sync,
                                        const GLenum&                     in_pname,
                                        const OpenGL::GetSetArgumentType& in_values_type,
                                        const GLsizei&                    in_buf_size,
                                        GLsizei*                          inout_length_ptr,
                                        void*                             out_values_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_texture_image(const OpenGL::TextureTarget& in_target,
                                        const uint32_t&              in_level,
                                        const OpenGL::PixelFormat&   in_format,
                                        const OpenGL::PixelType&     in_type,
                                        void*                        out_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    m_scheduler_ptr->get_texture_image(texture_id,
                                       in_level,
                                       in_format,
                                       in_type,
                                       out_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_texture_level_parameter(const OpenGL::TextureTarget&        in_target,
                                                  const int32_t&                      in_level,
                                                  const OpenGL::TextureLevelProperty& in_pname,
                                                  const OpenGL::GetSetArgumentType&   in_arg_type,
                                                  void*                               out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->get_texture_level_parameter(in_level,
                                                              in_pname,
                                                              in_arg_type,
                                                              out_params_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_texture_parameter(const OpenGL::TextureTarget&      in_target,
                                            const OpenGL::TextureProperty&    in_property,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            void*                             out_arg_value_ptr) const
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->get_texture_parameter(in_property,
                                                        in_arg_type,
                                                        out_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_transform_feedback_varying(const GLuint&         in_program,
                                                     const GLuint&         in_index,
                                                     const GLsizei&        in_buf_size,
                                                     GLsizei*              out_length_ptr,
                                                     GLsizei*              out_size_ptr,
                                                     OpenGL::VariableType* out_type_ptr,
                                                     GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

GLuint OpenGL::Context::get_uniform_block_index(const GLuint& in_program,
                                                const GLchar* in_uniform_block_name) const
{
    vkgl_not_implemented();

    return UINT32_MAX;
}

void OpenGL::Context::get_uniform_indices(const GLuint&        in_program,
                                          const GLsizei&       in_uniform_count,
                                          const GLchar* const* in_uniform_names_ptr_ptr,
                                          GLuint*              out_uniform_indices_ptr) const
{
    vkgl_not_implemented();
}

GLint OpenGL::Context::get_uniform_location(const GLuint& in_program,
                                            const GLchar* in_name) const
{
    vkgl_not_implemented();

    return -1;
}

void OpenGL::Context::get_uniform_value(const GLuint&                     in_program,
                                        const GLint&                      in_location,
                                        const OpenGL::GetSetArgumentType& in_params_type,
                                        void*                             out_params_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_vertex_attrib_pointer_property(const GLuint&                                 in_index,
                                                         const OpenGL::VertexAttributePointerProperty& in_pname,
                                                         void**                                        out_pointer_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_vertex_attribute_property(const GLuint&                          in_index,
                                                    const OpenGL::VertexAttributeProperty& in_pname,
                                                    const OpenGL::GetSetArgumentType&      in_src_type,
                                                    const OpenGL::GetSetArgumentType&      in_dst_type,
                                                    void*                                  out_params_ptr) const
{
    vkgl_not_implemented();
}

bool OpenGL::Context::init()
{
    bool result = false;

    /* Set up GL limits container */
    m_gl_limits_ptr.reset(
        new OpenGL::GLLimits()
    );

    if (m_gl_limits_ptr == nullptr)
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        goto end;
    }

    /* Set up GL state manager */
    m_gl_state_manager_ptr.reset(
        new OpenGL::GLStateManager(dynamic_cast<IGLLimits*>(m_gl_limits_ptr.get() ))
    );

    if (m_gl_state_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_state_manager_ptr != nullptr);

        goto end;
    }

    /* Set up task scheduler */
    m_scheduler_ptr = Scheduler::create();

    if (m_scheduler_ptr == nullptr)
    {
        vkgl_assert(m_scheduler_ptr != nullptr);

        goto end;
    }

    /* All done */
    result = true;
end:
    return result;
}

bool OpenGL::Context::is_buffer(const GLuint& in_id) const
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    return m_gl_buffer_manager_ptr->is_alive_id(in_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_enabled(const OpenGL::Capability& in_capability) const
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->is_enabled(in_capability);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_enabled_indexed(const OpenGL::Capability& in_capability,
                                         const GLuint&             in_index) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_framebuffer(const GLuint& in_framebuffer) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_program(const GLuint& in_program) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_query(const GLuint& in_id) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    return m_gl_query_manager_ptr->is_alive_id(in_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_renderbuffer(const GLuint& in_renderbuffer) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_shader(const GLuint& in_shader) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_sync(const GLsync& in_sync)
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_texture(const GLuint& in_texture) const
{
#if 0
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    return m_gl_texture_manager_ptr->is_alive_id(in_texture);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_vertex_array(const GLuint& in_array) const
{
    vkgl_not_implemented();

    return false;
}

void OpenGL::Context::link_program(const GLuint& in_program)
{
    vkgl_not_implemented();
}

void* OpenGL::Context::map_buffer(const OpenGL::BufferTarget& in_target,
                                  const OpenGL::BufferAccess& in_access)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    return m_scheduler_ptr->map_buffer(in_target,
                                       in_access);
#else
    vkgl_not_implemented();

    return nullptr;
#endif
}

void* OpenGL::Context::map_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_length,
                                        const OpenGL::BufferAccess& in_access)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::Context::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                        const GLint*                in_first_ptr,
                                        const GLsizei*              in_count_ptr,
                                        const GLsizei&              in_drawcount)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->multi_draw_arrays(in_mode,
                                       in_first_ptr,
                                       in_count_ptr,
                                       in_drawcount);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                          const GLsizei*                   in_count_ptr,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void* const*               in_indices_ptr,
                                          const GLsizei&                   in_drawcount)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->multi_draw_elements(in_mode,
                                         in_count_ptr,
                                         in_type,
                                         in_indices_ptr,
                                         in_drawcount);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::multi_draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                      const GLsizei*                   in_count_ptr,
                                                      const OpenGL::DrawCallIndexType& in_type,
                                                      const void* const*               in_indices_ptr,
                                                      const GLsizei&                   in_drawcount,
                                                      const GLint*                     in_basevertex_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::read_pixels(const int32_t&             in_x,
                                  const int32_t&             in_y,
                                  const size_t&              in_width,
                                  const size_t&              in_height,
                                  const OpenGL::PixelFormat& in_format,
                                  const OpenGL::PixelType&   in_type,
                                  void*                      out_pixels_ptr)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->read_pixels(in_x,
                                 in_y,
                                 in_width,
                                 in_height,
                                 in_format,
                                 in_type,
                                 out_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::set_active_texture(const uint32_t& in_n_texture_unit)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_active_texture(in_n_texture_unit);
}

void OpenGL::Context::set_blend_color(const float& in_red,
                                      const float& in_green,
                                      const float& in_blue,
                                      const float& in_alpha)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_color(in_red,
                                            in_green,
                                            in_blue,
                                            in_alpha);
}

void OpenGL::Context::set_blend_equation(const OpenGL::BlendEquation& in_blend_equation)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_equation(in_blend_equation);
}

void OpenGL::Context::set_blend_equation_separate(const OpenGL::BlendEquation& in_modeRGB,
                                                  const OpenGL::BlendEquation& in_modeAlpha)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_blend_functions(const OpenGL::BlendFunction& in_src_rgba_function,
                                          const OpenGL::BlendFunction& in_dst_rgba_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions(in_src_rgba_function,
                                                in_dst_rgba_function);
}

void OpenGL::Context::set_blend_functions_separate(const OpenGL::BlendFunction& in_src_rgb_function,
                                                   const OpenGL::BlendFunction& in_dst_rgb_function,
                                                   const OpenGL::BlendFunction& in_src_alpha_function,
                                                   const OpenGL::BlendFunction& in_dst_alpha_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions_separate(in_src_rgb_function,
                                                         in_dst_rgb_function,
                                                         in_src_alpha_function,
                                                         in_dst_alpha_function);
}

void OpenGL::Context::set_clamp_color(const bool& in_enable)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_clear_color_value(const float& in_red,
                                            const float& in_green,
                                            const float& in_blue,
                                            const float& in_alpha)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_color_value(in_red,
                                                  in_green,
                                                  in_blue,
                                                  in_alpha);
}

void OpenGL::Context::set_clear_depth_value(const double& in_value)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_depth_value(in_value);
}

void OpenGL::Context::set_clear_stencil_value(const int& in_value)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_stencil_value(in_value);
}

void OpenGL::Context::set_color_mask(const bool& in_red,
                                     const bool& in_green,
                                     const bool& in_blue,
                                     const bool& in_alpha)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_color_mask(in_red,
                                           in_green,
                                           in_blue,
                                           in_alpha);
}

void OpenGL::Context::set_color_mask_indexed(const GLuint& in_index,
                                             const bool&   in_r,
                                             const bool&   in_g,
                                             const bool&   in_b,
                                             const bool&   in_a)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_cull_mode(const OpenGL::CullMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_cull_mode(in_mode);
}

void OpenGL::Context::set_depth_function(const OpenGL::DepthFunction& in_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_function(in_function);
}

void OpenGL::Context::set_depth_mask(const bool& in_flag)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_mask(in_flag);
}

void OpenGL::Context::set_depth_range(const double& in_near,
                                      const double& in_far)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_range(in_near,
                                            in_far);
}

void OpenGL::Context::set_draw_buffer(const OpenGL::DrawBuffer& in_draw_buffer)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_draw_buffer(in_draw_buffer);
}

void OpenGL::Context::set_draw_buffers(const GLsizei&            in_n,
                                       const OpenGL::DrawBuffer* in_bufs_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_front_face_orientation(in_orientation);
}

void OpenGL::Context::set_hint(const OpenGL::HintTarget& in_target,
                               const OpenGL::HintMode&   in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_hint(in_target,
                                     in_mode);
}

void OpenGL::Context::set_line_width(const float& in_width)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_line_width(in_width);
}

void OpenGL::Context::set_logic_op(const OpenGL::LogicOpMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_logic_op(in_mode);
}

void OpenGL::Context::set_matrix_uniform(const GLint&    in_location,
                                         const uint32_t& in_n_columns,
                                         const uint32_t& in_n_rows,
                                         const uint32_t& in_n_array_items,
                                         const bool&     in_transpose,
                                         const GLfloat*  in_value_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_pixel_store_property(const OpenGL::PixelStoreProperty& in_property,
                                               const OpenGL::GetSetArgumentType& in_arg_type,
                                               const void*                     in_arg_value_ptr)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_pixel_store_property(in_property,
                                                     in_arg_type,
                                                     in_arg_value_ptr);
}

void OpenGL::Context::set_point_property(const OpenGL::PointProperty&      in_property,
                                         const OpenGL::GetSetArgumentType& in_arg_type,
                                         const void*                       in_arg_value_ptr)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_property(in_property,
                                               in_arg_type,
                                               in_arg_value_ptr);
}

void OpenGL::Context::set_point_size(const float& in_size)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_size(in_size);
}

void OpenGL::Context::set_polygon_mode(const OpenGL::PolygonMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_mode(in_mode);
}

void OpenGL::Context::set_polygon_offset(const GLfloat& in_factor,
                                         const GLfloat& in_units)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_offset(in_factor,
                                               in_units);
}

void OpenGL::Context::set_primitive_restart_index(const GLuint& in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_provoking_vertex(const OpenGL::ProvokingVertexConvention& in_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_read_buffer(const OpenGL::ReadBuffer& in_read_buffer)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_read_buffer(in_read_buffer);
}

void OpenGL::Context::set_renderbuffer_storage(const OpenGL::RenderbufferTarget& in_target,
                                               const OpenGL::InternalFormat&     in_internalformat,
                                               const GLsizei&                    in_width,
                                               const GLsizei&                    in_height)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_renderbuffer_storage_multisample(const OpenGL::RenderbufferTarget& in_target,
                                                           const GLsizei&                    in_samples,
                                                           const OpenGL::InternalFormat&     in_internalformat,
                                                           const GLsizei&                    in_width,
                                                           const GLsizei&                    in_height)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_sample_coverage(const GLfloat&   in_value,
                                          const GLboolean& in_invert)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_sample_coverage(in_value,
                                                (in_invert == GL_TRUE) );
}

void OpenGL::Context::set_sample_mask_indexed(const GLuint&     in_mask_number,
                                              const GLbitfield& in_mask)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_scissor(const int32_t& in_x,
                                  const int32_t& in_y,
                                  const size_t&  in_width,
                                  const size_t&  in_height)
{            
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_scissor(in_x,
                                        in_y,
                                        in_width,
                                        in_height);
}

void OpenGL::Context::set_shader_source(const GLuint&        in_shader,
                                        const GLsizei&       in_count,
                                        const GLchar* const* in_string_ptr_ptr,
                                        const GLint*         in_length_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_function(const OpenGL::StencilFunction& in_func,
                                           const int32_t&                 in_ref,
                                           const uint32_t&                in_mask)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_function(in_func,
                                                 in_ref,
                                                 in_mask);
}

void OpenGL::Context::set_stencil_function_separate(const OpenGL::StencilStateFace& in_face,
                                                    const OpenGL::StencilFunction&  in_func,
                                                    const GLint&                    in_ref,
                                                    const GLuint&                   in_mask)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_mask(const uint32_t& in_mask)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_mask(in_mask);
}

void OpenGL::Context::set_stencil_mask_separate(const OpenGL::StencilStateFace& in_face,
                                                const GLuint&                   in_mask)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_operations(const OpenGL::StencilOperation& in_fail,
                                             const OpenGL::StencilOperation& in_zfail,
                                             const OpenGL::StencilOperation& in_zpass)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_operations(in_fail,
                                                   in_zfail,
                                                   in_zpass);
}

void OpenGL::Context::set_stencil_operations_separate(const OpenGL::StencilStateFace& in_face,
                                                      const OpenGL::StencilOperation& in_sfail,
                                                      const OpenGL::StencilOperation& in_dpfail,
                                                      const OpenGL::StencilOperation& in_dppass)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_texture_parameter(const OpenGL::TextureTarget&      in_target,
                                            const OpenGL::TextureProperty&    in_property,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            const void*                       in_arg_value_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->set_texture_parameter(in_property,
                                                        in_arg_type,
                                                        in_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::set_transform_feedback_varyings(const GLuint&                              in_program,
                                                      const GLsizei&                             in_count,
                                                      const GLchar* const*                       in_varyings_ptr_ptr,
                                                      const OpenGL::TransformFeedbackBufferMode& in_buffer_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_uniform(const GLint&                      in_location,
                                  const OpenGL::GetSetArgumentType& in_data_type,
                                  const uint32_t&                   in_n_components,
                                  const uint32_t&                   in_n_array_items,
                                  const void*                       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_uniform_block_binding(const GLuint& in_program,
                                                const GLuint& in_uniform_block_index,
                                                const GLuint& in_uniform_block_binding)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_vertex_attribute(const GLuint&                     in_index,
                                           const OpenGL::GetSetArgumentType& in_src_type,
                                           const OpenGL::GetSetArgumentType& in_dst_type,
                                           const uint32_t&                   in_n_components,
                                           const bool&                       in_normalized,
                                           const void*                       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_vertex_attrib_pointer(const GLuint&                     in_index,
                                                const GLint&                      in_size,
                                                const OpenGL::VariableType&       in_type,
                                                const OpenGL::GetSetArgumentType& in_data_type,
                                                const bool&                       in_normalized,
                                                const GLsizei&                    in_stride,
                                                const void*                       in_pointer_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_viewport(const int32_t& in_x,
                                   const int32_t& in_y,
                                   const size_t&  in_width,
                                   const size_t&  in_height)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_viewport(in_x,
                                         in_y,
                                         in_width,
                                         in_height);
}

void OpenGL::Context::tex_buffer(const OpenGL::InternalFormat& in_internalformat,
                                 const GLuint&                 in_buffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                   const int32_t&                in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const int32_t&                in_width,
                                   const int32_t&                in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_image_1d(texture_id,
                                  in_level,
                                  in_internalformat,
                                  in_width,
                                  in_border,
                                  in_format,
                                  in_type,
                                  in_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                   const GLint&                  in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const GLsizei&                in_width,
                                   const GLsizei&                in_height,
                                   const GLint&                  in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_image_2d(texture_id,
                                  in_level,
                                  in_internalformat,
                                  in_width,
                                  in_height,
                                  in_border,
                                  in_format,
                                  in_type,
                                  in_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_image_2d_multisample(const OpenGL::TextureTarget&  in_target,
                                               const GLsizei&                in_samples,
                                               const OpenGL::InternalFormat& in_internalformat,
                                               const GLsizei&                in_width,
                                               const GLsizei&                in_height,
                                               const bool&                   in_fixedsamplelocations)
{
    vkgl_not_implemented();
}

void OpenGL::Context::tex_image_3d(const OpenGL::TextureTarget&  in_target,
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
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_image_3d(texture_id,
                                  in_level,
                                  in_internalformat,
                                  in_width,
                                  in_height,
                                  in_depth,
                                  in_border,
                                  in_format,
                                  in_type,
                                  in_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_image_3d_multisample(const OpenGL::TextureTarget&  in_target,
                                               const GLsizei&                in_samples,
                                               const OpenGL::InternalFormat& in_internalformat,
                                               const GLsizei&                in_width,
                                               const GLsizei&                in_height,
                                               const GLsizei&                in_depth,
                                               const bool&                   in_fixedsamplelocations)
{
    vkgl_not_implemented();
}

void OpenGL::Context::tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLsizei&               in_width,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_sub_image_1d(texture_id,
                                      in_level,
                                      in_xoffset,
                                      in_width,
                                      in_format,
                                      in_type,
                                      in_pixels);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLsizei&               in_width,
                                       const GLsizei&               in_height,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_sub_image_2d(texture_id,
                                      in_level,
                                      in_xoffset,
                                      in_yoffset,
                                      in_width,
                                      in_height,
                                      in_format,
                                      in_type,
                                      in_pixels);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLint&                 in_zoffset,
                                       const GLsizei&               in_width,
                                       const GLsizei&               in_height,
                                       const GLsizei&               in_depth,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_sub_image_3d(texture_id,
                                      in_level,
                                      in_xoffset,
                                      in_yoffset,
                                      in_zoffset,
                                      in_width,
                                      in_height,
                                      in_depth,
                                      in_format,
                                      in_type,
                                      in_pixels);
#else
    vkgl_not_implemented();
#endif
}

bool OpenGL::Context::unmap_buffer(const OpenGL::BufferTarget& in_target)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    return m_scheduler_ptr->unmap_buffer(buffer_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

void OpenGL::Context::use_program(const GLuint& in_program)
{
    vkgl_not_implemented();
}

void OpenGL::Context::validate_program(const GLuint& in_program)
{
    vkgl_not_implemented();
}

void OpenGL::Context::wait_sync(const GLsync&   in_sync,
                                const GLuint64& in_timeout)
{
    vkgl_not_implemented();
}
