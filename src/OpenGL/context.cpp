/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/types.h"
#include "OpenGL/context.h"
#include "OpenGL/utils_enum.h"

VKGL::Context::Context()
{
    /* Stub */
}

VKGL::Context::~Context()
{
    /* Stub */
}

void VKGL::Context::bind_texture(const VKGL::TextureTarget& in_target,
                                 const GLuint&              in_texture)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_texture_binding(m_gl_state_manager_ptr->get_state()->active_texture_unit,
                                                in_target,
                                                in_texture);
}

void VKGL::Context::clear(const VKGL::ClearBufferBits& in_buffers_to_clear)
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->clear(in_buffers_to_clear);
}

void VKGL::Context::copy_tex_image_1d(const VKGL::TextureTarget&  in_target,
                                      const GLint                 in_level,
                                      const VKGL::InternalFormat& in_internalformat,
                                      const GLint&                in_x,
                                      const GLint&                in_y,
                                      const GLsizei&              in_width,
                                      const GLint&                in_border)
{
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
}

void VKGL::Context::copy_tex_image_2d(const VKGL::TextureTarget&  in_target,
                                      const GLint&                in_level,
                                      const VKGL::InternalFormat& in_internalformat,
                                      const GLint&                in_x,
                                      const GLint&                in_y,
                                      const GLsizei&              in_width,
                                      const GLsizei&              in_height,
                                      const GLint&                in_border)
{
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
}

void VKGL::Context::copy_tex_sub_image_1d(const VKGL::TextureTarget& in_target,
                                          const GLint&               in_level,
                                          const GLint&               in_xoffset,
                                          const GLint&               in_x,
                                          const GLint&               in_y,
                                          const GLsizei&             in_width)
{
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
}

void VKGL::Context::copy_tex_sub_image_2d(const VKGL::TextureTarget& in_target,
                                          const GLint&               in_level,
                                          const GLint&               in_xoffset,
                                          const GLint&               in_yoffset,
                                          const GLint&               in_x,
                                          const GLint&               in_y,
                                          const GLsizei&             in_width,
                                          const GLsizei&             in_height)
{
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
}

void VKGL::Context::copy_tex_sub_image_3d(const VKGL::TextureTarget& in_target,
                                          const GLint&               in_level,
                                          const GLint&               in_xoffset,
                                          const GLint&               in_yoffset,
                                          const GLint&               in_zoffset,
                                          const GLint&               in_x,
                                          const GLint&               in_y,
                                          const GLsizei&             in_width,
                                          const GLsizei&             in_height)
{
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
}

VKGL::ContextUniquePtr VKGL::Context::create()
{
    VKGL::ContextUniquePtr result_ptr;

    result_ptr.reset(
        new VKGL::Context()
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

void VKGL::Context::delete_textures(const GLsizei& in_n,
                                    const GLuint*  in_textures)
{
    bool result;

    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    result = m_gl_texture_manager_ptr->delete_ids(in_n,
                                                  in_textures);

    if (!result)
    {
        vkgl_assert_fail();
    }
}

void VKGL::Context::disable(const VKGL::Capability& in_capability)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->disable(in_capability);
}

void VKGL::Context::draw_arrays(const VKGL::DrawCallMode& in_mode,
                                const GLint&              in_first,
                                const GLsizei&            in_count)
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_arrays(in_mode,
                                 in_first,
                                 in_count);
}

void VKGL::Context::draw_elements(const VKGL::DrawCallMode&      in_mode,
                                  const GLsizei&                 in_count,
                                  const VKGL::DrawCallIndexType& in_type,
                                  const void*                    in_indices)
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_elements(in_mode,
                                   in_count,
                                   in_type,
                                   in_indices);
}

void VKGL::Context::draw_range_elements(const VKGL::DrawCallMode&      in_mode,
                                        const GLuint&                  in_start,
                                        const GLuint&                  in_end,
                                        const GLsizei&                 in_count,
                                        const VKGL::DrawCallIndexType& in_type,
                                        const void*                    in_indices)
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_range_elements(in_mode,
                                         in_start,
                                         in_end,
                                         in_count,
                                         in_type,
                                         in_indices);
}

void VKGL::Context::enable(const VKGL::Capability& in_capability)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->enable(in_capability);
}

void VKGL::Context::finish()
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->finish();
}

void VKGL::Context::flush()
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->flush();
}

void VKGL::Context::gen_textures(const GLsizei& in_n,
                                 GLuint*        in_textures)
{
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    if (!m_gl_texture_manager_ptr->generate_ids(in_n,
                                                in_textures) )
    {
        vkgl_assert_fail();
    }
}

VKGL::ErrorCode VKGL::Context::get_error()
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->get_error();
}

void VKGL::Context::get_parameter(const VKGL::ContextProperty&    in_pname,
                                  const VKGL::GetSetArgumentType& in_arg_type,
                                  void*                           out_arg_value_ptr) const
{
    if (VKGL::Utils::is_context_property_gl_limit(in_pname) )
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        m_gl_limits_ptr->get_parameter(in_pname,
                                       in_arg_type,
                                       out_arg_value_ptr);
    }
    else
    if (VKGL::Utils::is_framebuffer_pname(in_pname) ) // todo: gl_doublebuffer, _drawbuffer, _drawbufferN, _readbuffer, samples, sample_buffers, stereo
    {
        todo;
    }
    else
    if (in_pname == VKGL::ContextProperty::Renderbuffer_Binding) // todo
    {
    }
    else
    if (VKGL::Utils::is_buffer_binding_pname(in_pname) ) // todo: buffer bindings
    {
        todo;
    }
    else
    if (VKGL::Utils::is_gl_constant          (in_pname)  || // todo: gl_major_version, gl_minor_version, 
        VKGL::Utils::is_texture_binding_pname(in_pname) )
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
}

void VKGL::Context::get_texture_image(const VKGL::TextureTarget& in_target,
                                      const uint32_t&            in_level,
                                      const VKGL::PixelFormat&   in_format,
                                      const VKGL::PixelType&     in_type,
                                      void*                      out_pixels_ptr)
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->get_texture_image(in_target,
                                       in_level,
                                       in_format,
                                       in_type,
                                       out_pixels_ptr);
}

void VKGL::Context::get_texture_level_parameter(const VKGL::TextureTarget&        in_target,
                                                const int32_t&                    in_level,
                                                const VKGL::TextureLevelProperty& in_pname,
                                                const VKGL::GetSetArgumentType&   in_arg_type,
                                                void*                             out_params_ptr) const
{
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
}

void VKGL::Context::get_texture_parameter(const VKGL::TextureTarget&      in_target,
                                          const VKGL::TextureProperty&    in_property,
                                          const VKGL::GetSetArgumentType& in_arg_type,
                                          void*                           out_arg_value_ptr) const
{
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
}

bool VKGL::Context::init()
{
    bool result = false;

    /* Set up GL limits container */
    m_gl_limits_ptr.reset(
        new VKGL::GLLimits()
    );

    if (m_gl_limits_ptr == nullptr)
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        goto end;
    }

    /* Set up GL state manager */
    m_gl_state_manager_ptr.reset(
        new VKGL::GLStateManager(dynamic_cast<IGLLimits*>(m_gl_limits_ptr.get() ))
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

bool VKGL::Context::is_enabled(const VKGL::Capability& in_capability) const
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->is_enabled(in_capability);
}

bool VKGL::Context::is_texture(const GLuint& in_texture)
{
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    return m_gl_texture_manager_ptr->is_alive_id(in_texture);
}

void VKGL::Context::read_pixels(const int32_t&           in_x,
                                const int32_t&           in_y,
                                const size_t&            in_width,
                                const size_t&            in_height,
                                const VKGL::PixelFormat& in_format,
                                const VKGL::PixelType&   in_type,
                                void*                    out_pixels_ptr)
{
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->read_pixels(in_x,
                                 in_y,
                                 in_width,
                                 in_height,
                                 in_format,
                                 in_type,
                                 out_pixels_ptr);
}

void VKGL::Context::set_blend_functions(const VKGL::BlendFunction& in_src_rgba_function,
                                        const VKGL::BlendFunction& in_dst_rgba_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions(in_src_rgba_function,
                                                 in_dst_rgba_function);
}

void VKGL::Context::set_clear_color_value(const float& in_red,
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

void VKGL::Context::set_clear_depth_value(const double& in_value)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_depth_value(in_value);
}

void VKGL::Context::set_clear_stencil_value(const int& in_value)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_stencil_value(in_value);
}

void VKGL::Context::set_color_mask(const bool& in_red,
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

void VKGL::Context::set_cull_mode(const VKGL::CullMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_cull_mode(in_mode);
}

void VKGL::Context::set_depth_function(const VKGL::DepthFunction& in_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_function(in_function);
}

void VKGL::Context::set_depth_mask(const bool& in_flag)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_mask(in_flag);
}

void VKGL::Context::set_depth_range(const double& in_near,
                                    const double& in_far)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_range(in_near,
                                            in_far);
}

void VKGL::Context::set_draw_buffer(const VKGL::DrawBuffer& in_draw_buffer)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_draw_buffer(in_draw_buffer);
}

void VKGL::Context::set_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_front_face_orientation(in_orientation);
}

void VKGL::Context::set_hint(const VKGL::HintTarget& in_target,
                             const VKGL::HintMode&   in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_hint(in_target,
                                     in_mode);
}

void VKGL::Context::set_line_width(const float& in_width)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_line_width(in_width);
}

void VKGL::Context::set_logic_op(const VKGL::LogicOpMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_logic_op(in_mode);
}

void VKGL::Context::set_pixel_store_property(const VKGL::PixelStoreProperty& in_property,
                                             const VKGL::GetSetArgumentType& in_arg_type,
                                             const void*                     in_arg_value_ptr)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_pixel_store_property(in_property,
                                                     in_arg_type,
                                                     in_arg_value_ptr);
}

void VKGL::Context::set_point_size(const float& in_size)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_size(in_size);
}

void VKGL::Context::set_polygon_mode(const VKGL::PolygonMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_mode(in_mode);
}

void VKGL::Context::set_polygon_offset(const GLfloat& in_factor,
                                       const GLfloat& in_units)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_offset(in_factor,
                                               in_units);
}

void VKGL::Context::set_read_buffer(const VKGL::ReadBuffer& in_read_buffer)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_read_buffer(in_read_buffer);
}

void VKGL::Context::set_scissor(const int32_t& in_x,
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

void VKGL::Context::set_stencil_function(const VKGL::StencilFunction& in_func,
                                         const int32_t&               in_ref,
                                         const uint32_t&              in_mask)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_function(in_func,
                                                 in_ref,
                                                 in_mask);
}

void VKGL::Context::set_stencil_mask(const uint32_t& in_mask)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_mask(in_mask);
}

void VKGL::Context::set_stencil_operations(const VKGL::StencilOperation& in_fail,
                                           const VKGL::StencilOperation& in_zfail,
                                           const VKGL::StencilOperation& in_zpass)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_operations(in_fail,
                                                   in_zfail,
                                                   in_zpass);
}

void VKGL::Context::set_texture_parameter(const VKGL::TextureTarget&      in_target,
                                          const VKGL::TextureProperty&    in_property,
                                          const VKGL::GetSetArgumentType& in_arg_type,
                                          const void*                     in_arg_value_ptr)
{
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
}

void VKGL::Context::set_viewport(const int32_t& in_x,
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

void VKGL::Context::tex_image_1d(const VKGL::TextureTarget&  in_target,
                                 const int32_t&              in_level,
                                 const VKGL::InternalFormat& in_internalformat,
                                 const int32_t&              in_width,
                                 const int32_t&              in_border,
                                 const VKGL::PixelFormat&    in_format,
                                 const VKGL::PixelType&      in_type,
                                 const void*                 in_pixels_ptr)
{
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
}

void VKGL::Context::tex_image_2d(const VKGL::TextureTarget&  in_target,
                                 const GLint&                in_level,
                                 const VKGL::InternalFormat& in_internalformat,
                                 const GLsizei&              in_width,
                                 const GLsizei&              in_height,
                                 const GLint&                in_border,
                                 const VKGL::PixelFormat&    in_format,
                                 const VKGL::PixelType&      in_type,
                                 const void*                 in_pixels_ptr)
{
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
}

void VKGL::Context::tex_image_3d(const VKGL::TextureTarget&     in_target,
                                 const GLint&                   in_level,
                                 const VKGL::InternalFormat&    in_internalformat,
                                 const GLsizei&                 in_width,
                                 const GLsizei&                 in_height,
                                 const GLsizei&                 in_depth,
                                 const GLint&                   in_border,
                                 const VKGL::PixelFormat&       in_format,
                                 const VKGL::PixelType&         in_type,
                                 const void*                    in_pixels_ptr)
{
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
}

void VKGL::Context::tex_sub_image_1d(const VKGL::TextureTarget& in_target,
                                     const GLint&               in_level,
                                     const GLint&               in_xoffset,
                                     const GLsizei&             in_width,
                                     const VKGL::PixelFormat&   in_format,
                                     const VKGL::PixelType&     in_type,
                                     const void*                in_pixels)
{
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
}

void VKGL::Context::tex_sub_image_2d(const VKGL::TextureTarget& in_target,
                                     const GLint&               in_level,
                                     const GLint&               in_xoffset,
                                     const GLint&               in_yoffset,
                                     const GLsizei&             in_width,
                                     const GLsizei&             in_height,
                                     const VKGL::PixelFormat&   in_format,
                                     const VKGL::PixelType&     in_type,
                                     const void*                in_pixels)
{
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
}

void VKGL::Context::tex_sub_image_3d(const VKGL::TextureTarget& in_target,
                                     const GLint&               in_level,
                                     const GLint&               in_xoffset,
                                     const GLint&               in_yoffset,
                                     const GLint&               in_zoffset,
                                     const GLsizei&             in_width,
                                     const GLsizei&             in_height,
                                     const GLsizei&             in_depth,
                                     const VKGL::PixelFormat&   in_format,
                                     const VKGL::PixelType&     in_type,
                                     const void*                in_pixels)
{
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
}