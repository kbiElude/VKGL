/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_UTILS_ENUM_H
#define VKGL_UTILS_ENUM_H

#include "OpenGL/types.h"

namespace VKGL
{
    namespace Utils
    {
        VKGL::BlendEquation get_blend_equation_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_blend_equation(const VKGL::BlendEquation& in_blend_equation);

        VKGL::BlendFunction get_blend_function_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_blend_function(const VKGL::BlendFunction& in_blend_func);

        VKGL::BlitFilter get_blit_filter_for_gl_enum(const GLenum&           in_enum);
        GLenum           get_gl_enum_for_blit_filter(const VKGL::BlitFilter& in_filter);

        VKGL::BlitMaskBits get_blit_mask_bits_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_blit_mask_bits(const VKGL::BlitMaskBits& in_bits);

        VKGL::BufferAccess get_buffer_access_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_buffer_access(const VKGL::BufferAccess& in_access);

        VKGL::BufferPointerProperty get_buffer_pointer_property_for_gl_enum(const GLenum&                      in_enum);
        GLenum                      get_gl_enum_for_buffer_pointer_property(const VKGL::BufferPointerProperty& in_property);

        VKGL::BufferProperty get_buffer_property_for_gl_enum(const GLenum&               in_enum);
        GLenum               get_gl_enum_for_buffer_property(const VKGL::BufferProperty& in_property);

        VKGL::BufferTarget get_buffer_target_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_buffer_target(const VKGL::BufferTarget& in_target);

        VKGL::BufferUsage get_buffer_usage_for_gl_enum(const GLenum&            in_enum);
        GLenum            get_gl_enum_for_buffer_usage(const VKGL::BufferUsage& in_usage);

        GLenum           get_gl_enum_for_indexed_capability   (const VKGL::Capability& in_capability,
                                                               const uint32_t&         in_index);
        GLenum           get_gl_enum_for_nonindexed_capability(const VKGL::Capability& in_capability);
        void             get_indexed_capability_for_gl_enum   (const GLenum&           in_enum,
                                                               VKGL::Capability*       out_capability_ptr,
                                                               uint32_t*               out_index_ptr);
        VKGL::Capability get_nonindexed_capability_for_gl_enum(const GLenum&           in_enum);

        VKGL::ClampReadColorMode get_clamp_read_color_mode_for_gl_enum(const GLenum&                   in_enum);
        GLenum                   get_gl_enum_for_clamp_read_color_mode(const VKGL::ClampReadColorMode& in_mode);

        VKGL::ClearBuffer get_clear_buffer_for_gl_enum(const GLenum&            in_enum);
        GLenum            get_gl_enum_for_clear_buffer(const VKGL::ClearBuffer& in_clear_buffer);

        VKGL::ClearBufferBits get_clear_buffer_bits_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_clear_buffer_bits(const VKGL::ClearBufferBits& in_buffers);

        VKGL::ConditionalRenderMode get_conditional_render_mode_for_gl_enum(const GLenum&                      in_enum);
        GLenum                      get_gl_enum_for_conditional_render_mode(const VKGL::ConditionalRenderMode& in_mode);

        VKGL::ContextProperty get_context_property_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_context_property(const VKGL::ContextProperty& in_property);

        VKGL::CullMode get_cull_mode_for_gl_enum(const GLenum&         in_enum);
        GLenum         get_gl_enum_for_cull_mode(const VKGL::CullMode& in_cull_mode);

        VKGL::DepthFunction get_depth_function_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_depth_function(const VKGL::DepthFunction& in_depth_function);

        VKGL::DepthStencilTextureMode get_depth_stencil_texture_mode_for_gl_enum(const GLenum&                        in_enum);
        GLenum                        get_gl_enum_for_depth_stencil_texture_mode(const VKGL::DepthStencilTextureMode& in_mode);

        VKGL::DrawBuffer get_draw_buffer_for_gl_enum(const GLenum&     in_enum);
        GLenum           get_gl_enum_for_draw_buffer(const DrawBuffer& in_draw_buffer);

        VKGL::DrawCallIndexType get_draw_call_index_type_for_gl_enum(const GLenum&                  in_enum);
        GLenum                  get_gl_enum_for_draw_call_index_type(const VKGL::DrawCallIndexType& in_type);

        VKGL::DrawCallMode get_draw_call_mode_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_draw_call_mode(const VKGL::DrawCallMode& in_mode);

        VKGL::ErrorCode get_error_code_for_gl_enum(const GLenum&          in_enum);
        GLenum          get_gl_enum_for_error_code(const VKGL::ErrorCode& in_error);

        VKGL::FramebufferAttachmentComponentType get_framebuffer_attachment_component_type_for_gl_enum(const GLenum&                                   in_enum);
        GLenum                                   get_gl_enum_for_framebuffer_attachment_component_type(const VKGL::FramebufferAttachmentComponentType& in_type);

        VKGL::FramebufferAttachmentObjectType get_framebuffer_attachment_object_type_for_gl_enum(const GLenum&                                in_enum);
        GLenum                                get_gl_enum_for_framebuffer_attachment_object_type(const VKGL::FramebufferAttachmentObjectType& in_type);

        VKGL::FramebufferAttachmentPoint get_framebuffer_attachment_point_for_gl_enum(const GLenum&                           in_enum);
        GLenum                           get_gl_enum_for_framebuffer_attachment_point(const VKGL::FramebufferAttachmentPoint& in_fb_attachment_point);

        VKGL::FramebufferAttachmentProperty get_framebuffer_attachment_property_for_gl_enum(const GLenum&                              in_enum);
        GLenum                              get_gl_enum_for_framebuffer_attachment_property(const VKGL::FramebufferAttachmentProperty& in_pname);

        VKGL::FramebufferStatus get_framebuffer_status_for_gl_enum(const GLenum&                  in_enum);
        GLenum                  get_gl_enum_for_framebuffer_status(const VKGL::FramebufferStatus& in_status);

        VKGL::FramebufferTarget get_framebuffer_target_for_gl_enum(const GLenum&                  in_enum);
        GLenum                  get_gl_enum_for_framebuffer_target(const VKGL::FramebufferTarget& in_target);

        VKGL::FrontFaceOrientation get_front_face_orientation_for_gl_enum(const GLenum&                     in_enum);
        GLenum                     get_gl_enum_for_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation);

        VKGL::GeometryInputType get_geometry_input_type_for_gl_enum(const GLenum&                  in_enum);
        GLenum                  get_gl_enum_for_geometry_input_type(const VKGL::GeometryInputType& in_type);

        VKGL::GeometryOutputType get_geometry_output_type_for_gl_enum(const GLenum&                   in_enum);
        GLenum                   get_gl_enum_for_geometry_output_type(const VKGL::GeometryOutputType& in_type);

        GLenum         get_gl_enum_for_hint_mode(const VKGL::HintMode& in_hint_mode);
        VKGL::HintMode get_hint_mode_for_gl_enum(const GLenum&         in_enum);

        GLenum           get_gl_enum_for_hint_target(const VKGL::HintTarget& in_hint_target);
        VKGL::HintTarget get_hint_target_for_gl_enum(const GLenum&           in_enum);

        GLenum               get_gl_enum_for_internal_format(const VKGL::InternalFormat& in_internal_format);
        VKGL::InternalFormat get_internal_format_for_gl_enum(const GLenum&               in_enum);

        GLenum            get_gl_enum_for_logic_op_mode(const VKGL::LogicOpMode& in_logic_op_mode);
        VKGL::LogicOpMode get_logic_op_mode_for_gl_enum(const GLenum&            in_enum);

        GLenum                              get_gl_enum_for_mipmap_generation_texture_target(const VKGL::MipmapGenerationTextureTarget& in_target);
        VKGL::MipmapGenerationTextureTarget get_mipmap_generation_texture_target_for_gl_enum(const GLenum&                              in_enum);

        GLenum            get_gl_enum_for_pixel_format(const VKGL::PixelFormat& in_pixel_format);
        VKGL::PixelFormat get_pixel_format_for_gl_enum(const GLenum&            in_enum);

        GLenum                   get_gl_enum_for_pixel_store_property          (const VKGL::PixelStoreProperty& in_property);
        PixelStoreProperty       get_pixel_store_property_from_context_property(const VKGL::ContextProperty&    in_context_property);
        VKGL::PixelStoreProperty get_pixel_store_property_for_gl_enum          (const GLenum&                   in_enum);

        GLenum          get_gl_enum_for_pixel_type(const VKGL::PixelType& in_pixel_type);
        VKGL::PixelType get_pixel_type_for_gl_enum(const GLenum&          in_enum);

        GLenum              get_gl_enum_for_point_property(const VKGL::PointProperty& in_property);
        VKGL::PointProperty get_point_property_for_gl_enum(const GLenum&              in_enum);

        GLenum                       get_gl_enum_for_point_sprite_coord_origin(const VKGL::PointSpriteCoordOrigin& in_origin);
        VKGL::PointSpriteCoordOrigin get_point_sprite_coord_origin_for_gl_enum(const GLenum&                       in_enum);

        GLenum            get_gl_enum_for_polygon_mode(const VKGL::PolygonMode& in_polygon_mode);
        VKGL::PolygonMode get_polygon_mode_for_gl_enum(const GLenum&            in_enum);

        GLenum                get_gl_enum_for_program_property(const VKGL::ProgramProperty& in_pname);
        VKGL::ProgramProperty get_program_property_for_gl_enum(const GLenum&                in_enum);

        GLenum                          get_gl_enum_for_provoking_vertex_convention(const VKGL::ProvokingVertexConvention& in_convention);
        VKGL::ProvokingVertexConvention get_provoking_vertex_convention_for_gl_enum(const GLenum&                          in_enum);

        GLenum              get_gl_enum_for_query_property(const VKGL::QueryProperty& in_property);
        VKGL::QueryProperty get_query_property_for_gl_enum(const GLenum&              in_enum);

        GLenum            get_gl_enum_for_query_target(const VKGL::QueryTarget& in_target);
        VKGL::QueryTarget get_query_target_for_gl_enum(const GLenum&            in_enum);

        GLenum                    get_gl_enum_for_query_target_property(const VKGL::QueryTargetProperty& in_property);
        VKGL::QueryTargetProperty get_query_target_property_for_gl_enum(const GLenum&                    in_enum);

        GLenum           get_gl_enum_for_read_buffer(const VKGL::ReadBuffer& in_read_buffer);
        VKGL::ReadBuffer get_read_buffer_for_gl_enum(const GLenum&           in_enum);

        GLenum                     get_gl_enum_for_renderbuffer_property(const VKGL::RenderbufferProperty& in_pname);
        VKGL::RenderbufferProperty get_renderbuffer_property_for_gl_enum(const GLenum&                     in_enum);

        GLenum                   get_gl_enum_for_renderbuffer_target(const VKGL::RenderbufferTarget& in_target);
        VKGL::RenderbufferTarget get_renderbuffer_target_for_gl_enum(const GLenum&                   in_enum);

        GLenum               get_gl_enum_for_shader_property(const VKGL::ShaderProperty& in_pname);
        VKGL::ShaderProperty get_shader_property_for_gl_enum(const GLenum&               in_enum);

        GLenum           get_gl_enum_for_shader_type(const VKGL::ShaderType& in_shader_type);
        VKGL::ShaderType get_shader_type_for_gl_enum(const GLenum&           in_enum);

        GLenum                get_gl_enum_for_stencil_function(const VKGL::StencilFunction& in_stencil_function);
        VKGL::StencilFunction get_stencil_function_for_gl_enum(const GLenum&                in_enum);

        GLenum                 get_gl_enum_for_stencil_operation(const VKGL::StencilOperation& in_operation);
        VKGL::StencilOperation get_stencil_operation_for_gl_enum(const GLenum&                 in_enum);

        GLenum                 get_gl_enum_for_stencil_state_face(const VKGL::StencilStateFace& in_face);
        VKGL::StencilStateFace get_stencil_state_face_for_gl_enum(const GLenum&                 in_enum);

        GLenum              get_gl_enum_for_sync_condition(const VKGL::SyncCondition& in_condition);
        VKGL::SyncCondition get_sync_condition_for_gl_enum(const GLenum&              in_enum);

        GLenum             get_gl_enum_for_sync_property(const VKGL::SyncProperty& in_pname);
        VKGL::SyncProperty get_sync_property_for_gl_enum(const GLenum&             in_enum);

        VKGL::TextureBindingProperty get_texture_binding_property_for_context_property(const VKGL::ContextProperty& in_pname);
        bool                         is_texture_binding_pname                         (const VKGL::ContextProperty& in_pname);

        GLenum                       get_gl_enum_for_texture_compare_function(const VKGL::TextureCompareFunction& in_compare_function);
        VKGL::TextureCompareFunction get_texture_compare_function_for_gl_enum(const GLenum&                       in_enum);

        GLenum                   get_gl_enum_for_texture_compare_mode(const VKGL::TextureCompareMode& in_mode);
        VKGL::TextureCompareMode get_texture_compare_mode_for_gl_enum(const GLenum&                   in_enum);

        GLenum                   get_gl_enum_for_texture_cube_map_face(const VKGL::TextureCubeMapFace& in_face);
        VKGL::TextureCubeMapFace get_texture_cube_map_face_for_gl_enum(const GLenum&                   in_enum);

        GLenum                 get_gl_enum_for_texture_mag_filter(const VKGL::TextureMagFilter& in_filter);
        VKGL::TextureMagFilter get_texture_mag_filter_for_gl_enum(const GLenum&                 in_enum);

        GLenum                 get_gl_enum_for_texture_min_filter(const VKGL::TextureMinFilter& in_filter);
        VKGL::TextureMinFilter get_texture_min_filter_for_gl_enum(const GLenum&                 in_enum);

        GLenum                get_gl_enum_for_texture_property(const VKGL::TextureProperty& in_property);
        VKGL::TextureProperty get_texture_property_for_gl_enum(const GLenum&                in_enum);

        GLenum                     get_gl_enum_for_texture_level_property(const VKGL::TextureLevelProperty& in_property);
        VKGL::TextureLevelProperty get_texture_level_property_for_gl_enum(const GLenum&                     in_enum);

        GLenum               get_gl_enum_for_texture_swizzle(const VKGL::TextureSwizzle& in_swizzle);
        VKGL::TextureSwizzle get_texture_swizzle_for_gl_enum(const GLenum&               in_enum);

        GLenum              get_gl_enum_for_texture_target(const VKGL::TextureTarget& in_texture_target);
        VKGL::TextureTarget get_texture_target_for_gl_enum(const GLenum&              in_enum);

        GLenum                get_gl_enum_for_texture_wrap_mode(const VKGL::TextureWrapMode& in_wrap_mode);
        VKGL::TextureWrapMode get_texture_wrap_mode_for_gl_enum(const GLenum&                in_enum);

        GLenum                            get_gl_enum_for_transform_feedback_buffer_mode(const VKGL::TransformFeedbackBufferMode& in_mode);
        VKGL::TransformFeedbackBufferMode get_transform_feedback_buffer_mode_for_gl_enum(const GLenum&                            in_enum);

        GLenum                               get_gl_enum_for_transform_feedback_primitive_mode(const VKGL::TransformFeedbackPrimitiveMode& in_mode);
        VKGL::TransformFeedbackPrimitiveMode get_transform_feedback_primitive_mode_for_gl_enum(const GLenum&                               in_enum);

        GLenum                     get_gl_enum_for_uniform_block_property(const VKGL::UniformBlockProperty& in_property);
        VKGL::UniformBlockProperty get_uniform_block_property_for_gl_enum(const GLenum&                     in_enum);

        GLenum                get_gl_enum_for_uniform_property(const VKGL::UniformProperty& in_property);
        VKGL::UniformProperty get_uniform_property_for_gl_enum(const GLenum&                in_enum);

        GLenum           get_gl_enum_for_wait_result(const VKGL::WaitResult& in_result);
        VKGL::WaitResult get_wait_result_for_gl_enum(const GLenum&           in_enum);

        VKGL::WaitSyncBits get_wait_sync_bits_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_wait_sync_bits(const VKGL::WaitSyncBits& in_bits);

        GLenum             get_gl_enum_for_variable_type(const VariableType& in_type);
        VKGL::VariableType get_variable_type_for_gl_enum(const GLenum&       in_enum);

        GLenum                         get_gl_enum_for_vertex_attribute_array_type(const VKGL::VertexAttributeArrayType& in_type);
        VKGL::VertexAttributeArrayType get_vertex_attribute_array_type_for_gl_enum(const GLenum&                         in_enum);

        GLenum                               get_gl_enum_for_vertex_attribute_pointer_property(const VKGL::VertexAttributePointerProperty& in_pname);
        VKGL::VertexAttributePointerProperty get_vertex_attribute_pointer_property_for_gl_enum(const GLenum&                               in_enum);

        GLenum                        get_gl_enum_for_vertex_attribute_property(const VKGL::VertexAttributeProperty& in_property);
        VKGL::VertexAttributeProperty get_vertex_attribute_property_for_gl_enum(const GLenum&                        in_pname);

        bool is_context_property_gl_limit(const VKGL::ContextProperty& in_pname);
    }
};

#endif /* VKGL_UTILS_ENUM_H */