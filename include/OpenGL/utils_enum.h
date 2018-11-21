/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_UTILS_ENUM_H
#define VKGL_UTILS_ENUM_H

#include "Anvil/deps/glslang/glslang/Public/ShaderLang.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    namespace Utils
    {
        EShLanguage get_sh_language_for_opengl_shader_type(const OpenGL::ShaderType& in_type);

        OpenGL::BlendEquation get_blend_equation_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_blend_equation(const OpenGL::BlendEquation& in_blend_equation);

        OpenGL::BlendFunction get_blend_function_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_blend_function(const OpenGL::BlendFunction& in_blend_func);

        OpenGL::BlitFilter get_blit_filter_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_blit_filter(const OpenGL::BlitFilter& in_filter);

        OpenGL::BlitMaskBits get_blit_mask_bits_for_gl_enum(const GLenum&               in_enum);
        GLenum               get_gl_enum_for_blit_mask_bits(const OpenGL::BlitMaskBits& in_bits);

        OpenGL::BufferAccess get_buffer_access_for_gl_enum(const GLenum&               in_enum);
        GLenum               get_gl_enum_for_buffer_access(const OpenGL::BufferAccess& in_access);

        OpenGL::BufferPointerProperty get_buffer_pointer_property_for_gl_enum(const GLenum&                        in_enum);
        GLenum                        get_gl_enum_for_buffer_pointer_property(const OpenGL::BufferPointerProperty& in_property);

        OpenGL::BufferProperty get_buffer_property_for_gl_enum(const GLenum&                 in_enum);
        GLenum                 get_gl_enum_for_buffer_property(const OpenGL::BufferProperty& in_property);

        OpenGL::BufferTarget get_buffer_target_for_gl_enum(const GLenum&               in_enum);
        GLenum               get_gl_enum_for_buffer_target(const OpenGL::BufferTarget& in_target);

        OpenGL::BufferUsage get_buffer_usage_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_buffer_usage(const OpenGL::BufferUsage& in_usage);

        GLenum             get_gl_enum_for_indexed_capability   (const OpenGL::Capability& in_capability,
                                                                 const uint32_t&           in_index);
        GLenum             get_gl_enum_for_nonindexed_capability(const OpenGL::Capability& in_capability);
        void               get_indexed_capability_for_gl_enum   (const GLenum&             in_enum,
                                                                 OpenGL::Capability*       out_capability_ptr,
                                                                 uint32_t*                 out_index_ptr);
        OpenGL::Capability get_nonindexed_capability_for_gl_enum(const GLenum&             in_enum);

        OpenGL::ClampReadColorMode get_clamp_read_color_mode_for_gl_enum(const GLenum&                     in_enum);
        GLenum                     get_gl_enum_for_clamp_read_color_mode(const OpenGL::ClampReadColorMode& in_mode);

        OpenGL::ClearBuffer get_clear_buffer_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_clear_buffer(const OpenGL::ClearBuffer& in_clear_buffer);

        OpenGL::ClearBufferBits get_clear_buffer_bits_for_gl_enum(const GLenum&                  in_enum);
        GLenum                  get_gl_enum_for_clear_buffer_bits(const OpenGL::ClearBufferBits& in_buffers);

        OpenGL::ConditionalRenderMode get_conditional_render_mode_for_gl_enum(const GLenum&                        in_enum);
        GLenum                        get_gl_enum_for_conditional_render_mode(const OpenGL::ConditionalRenderMode& in_mode);

        OpenGL::ContextProperty get_context_property_for_gl_enum(const GLenum&                  in_enum);
        GLenum                  get_gl_enum_for_context_property(const OpenGL::ContextProperty& in_property);

        OpenGL::CullMode get_cull_mode_for_gl_enum(const GLenum&           in_enum);
        GLenum           get_gl_enum_for_cull_mode(const OpenGL::CullMode& in_cull_mode);

        OpenGL::DepthFunction get_depth_function_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_depth_function(const OpenGL::DepthFunction& in_depth_function);

        OpenGL::DepthStencilTextureMode get_depth_stencil_texture_mode_for_gl_enum(const GLenum&                          in_enum);
        GLenum                          get_gl_enum_for_depth_stencil_texture_mode(const OpenGL::DepthStencilTextureMode& in_mode);

        OpenGL::DrawBuffer get_draw_buffer_for_gl_enum(const GLenum&     in_enum);
        GLenum             get_gl_enum_for_draw_buffer(const DrawBuffer& in_draw_buffer);

        OpenGL::DrawCallIndexType get_draw_call_index_type_for_gl_enum(const GLenum&                    in_enum);
        GLenum                    get_gl_enum_for_draw_call_index_type(const OpenGL::DrawCallIndexType& in_type);

        OpenGL::DrawCallMode get_draw_call_mode_for_gl_enum(const GLenum&               in_enum);
        GLenum               get_gl_enum_for_draw_call_mode(const OpenGL::DrawCallMode& in_mode);

        OpenGL::ErrorCode get_error_code_for_gl_enum(const GLenum&            in_enum);
        GLenum            get_gl_enum_for_error_code(const OpenGL::ErrorCode& in_error);

        OpenGL::FramebufferAttachmentComponentType get_framebuffer_attachment_component_type_for_gl_enum(const GLenum&                                     in_enum);
        GLenum                                     get_gl_enum_for_framebuffer_attachment_component_type(const OpenGL::FramebufferAttachmentComponentType& in_type);

        OpenGL::FramebufferAttachmentObjectType get_framebuffer_attachment_object_type_for_gl_enum(const GLenum&                                  in_enum);
        GLenum                                  get_gl_enum_for_framebuffer_attachment_object_type(const OpenGL::FramebufferAttachmentObjectType& in_type);

        OpenGL::FramebufferAttachmentPoint get_framebuffer_attachment_point_for_gl_enum(const GLenum&                             in_enum);
        GLenum                             get_gl_enum_for_framebuffer_attachment_point(const OpenGL::FramebufferAttachmentPoint& in_fb_attachment_point);

        OpenGL::FramebufferAttachmentProperty get_framebuffer_attachment_property_for_gl_enum(const GLenum&                                in_enum);
        GLenum                                get_gl_enum_for_framebuffer_attachment_property(const OpenGL::FramebufferAttachmentProperty& in_pname);

        OpenGL::FramebufferStatus get_framebuffer_status_for_gl_enum(const GLenum&                    in_enum);
        GLenum                    get_gl_enum_for_framebuffer_status(const OpenGL::FramebufferStatus& in_status);

        OpenGL::FramebufferTarget get_framebuffer_target_for_gl_enum(const GLenum&                    in_enum);
        GLenum                    get_gl_enum_for_framebuffer_target(const OpenGL::FramebufferTarget& in_target);

        OpenGL::FrontFaceOrientation get_front_face_orientation_for_gl_enum(const GLenum&                       in_enum);
        GLenum                       get_gl_enum_for_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation);

        OpenGL::GeometryInputType get_geometry_input_type_for_gl_enum(const GLenum&                    in_enum);
        GLenum                    get_gl_enum_for_geometry_input_type(const OpenGL::GeometryInputType& in_type);

        OpenGL::GeometryOutputType get_geometry_output_type_for_gl_enum(const GLenum&                     in_enum);
        GLenum                     get_gl_enum_for_geometry_output_type(const OpenGL::GeometryOutputType& in_type);

        GLenum           get_gl_enum_for_hint_mode(const OpenGL::HintMode& in_hint_mode);
        OpenGL::HintMode get_hint_mode_for_gl_enum(const GLenum&           in_enum);

        GLenum             get_gl_enum_for_hint_target(const OpenGL::HintTarget& in_hint_target);
        OpenGL::HintTarget get_hint_target_for_gl_enum(const GLenum&             in_enum);

        GLenum                 get_gl_enum_for_internal_format(const OpenGL::InternalFormat& in_internal_format);
        OpenGL::InternalFormat get_internal_format_for_gl_enum(const GLenum&                 in_enum);

        GLenum              get_gl_enum_for_logic_op_mode(const OpenGL::LogicOpMode& in_logic_op_mode);
        OpenGL::LogicOpMode get_logic_op_mode_for_gl_enum(const GLenum&              in_enum);

        GLenum                                get_gl_enum_for_mipmap_generation_texture_target(const OpenGL::MipmapGenerationTextureTarget& in_target);
        OpenGL::MipmapGenerationTextureTarget get_mipmap_generation_texture_target_for_gl_enum(const GLenum&                                in_enum);

        GLenum              get_gl_enum_for_pixel_format(const OpenGL::PixelFormat& in_pixel_format);
        OpenGL::PixelFormat get_pixel_format_for_gl_enum(const GLenum&              in_enum);

        GLenum                     get_gl_enum_for_pixel_store_property          (const OpenGL::PixelStoreProperty& in_property);
        PixelStoreProperty         get_pixel_store_property_from_context_property(const OpenGL::ContextProperty&    in_context_property);
        OpenGL::PixelStoreProperty get_pixel_store_property_for_gl_enum          (const GLenum&                     in_enum);

        GLenum            get_gl_enum_for_pixel_type(const OpenGL::PixelType& in_pixel_type);
        OpenGL::PixelType get_pixel_type_for_gl_enum(const GLenum&            in_enum);

        GLenum                get_gl_enum_for_point_property(const OpenGL::PointProperty& in_property);
        OpenGL::PointProperty get_point_property_for_gl_enum(const GLenum&                in_enum);

        GLenum                         get_gl_enum_for_point_sprite_coord_origin(const OpenGL::PointSpriteCoordOrigin& in_origin);
        OpenGL::PointSpriteCoordOrigin get_point_sprite_coord_origin_for_gl_enum(const GLenum&                         in_enum);

        GLenum              get_gl_enum_for_polygon_mode(const OpenGL::PolygonMode& in_polygon_mode);
        OpenGL::PolygonMode get_polygon_mode_for_gl_enum(const GLenum&              in_enum);

        GLenum                  get_gl_enum_for_program_property(const OpenGL::ProgramProperty& in_pname);
        OpenGL::ProgramProperty get_program_property_for_gl_enum(const GLenum&                  in_enum);

        GLenum                            get_gl_enum_for_provoking_vertex_convention(const OpenGL::ProvokingVertexConvention& in_convention);
        OpenGL::ProvokingVertexConvention get_provoking_vertex_convention_for_gl_enum(const GLenum&                            in_enum);

        GLenum                get_gl_enum_for_query_property(const OpenGL::QueryProperty& in_property);
        OpenGL::QueryProperty get_query_property_for_gl_enum(const GLenum&                in_enum);

        GLenum              get_gl_enum_for_query_target(const OpenGL::QueryTarget& in_target);
        OpenGL::QueryTarget get_query_target_for_gl_enum(const GLenum&              in_enum);

        GLenum                      get_gl_enum_for_query_target_property(const OpenGL::QueryTargetProperty& in_property);
        OpenGL::QueryTargetProperty get_query_target_property_for_gl_enum(const GLenum&                      in_enum);

        const char* get_raw_string_for_gl_bitfield(const OpenGL::BitfieldType& in_bitfield,
                                                   const GLenum&               in_Enum);

        const char* get_raw_string_for_gl_enum(const GLenum& in_enum);

        GLenum             get_gl_enum_for_read_buffer(const OpenGL::ReadBuffer& in_read_buffer);
        OpenGL::ReadBuffer get_read_buffer_for_gl_enum(const GLenum&             in_enum);

        GLenum                       get_gl_enum_for_renderbuffer_property(const OpenGL::RenderbufferProperty& in_pname);
        OpenGL::RenderbufferProperty get_renderbuffer_property_for_gl_enum(const GLenum&                       in_enum);

        GLenum                     get_gl_enum_for_renderbuffer_target(const OpenGL::RenderbufferTarget& in_target);
        OpenGL::RenderbufferTarget get_renderbuffer_target_for_gl_enum(const GLenum&                     in_enum);

        GLenum                 get_gl_enum_for_shader_property(const OpenGL::ShaderProperty& in_pname);
        OpenGL::ShaderProperty get_shader_property_for_gl_enum(const GLenum&                 in_enum);

        Anvil::ShaderStage get_anvil_shader_stage_for_shader_type(const OpenGL::ShaderType& in_shader_type);
        GLenum             get_gl_enum_for_shader_type           (const OpenGL::ShaderType& in_shader_type);
        OpenGL::ShaderType get_shader_type_for_gl_enum           (const GLenum&             in_enum);

        GLenum                  get_gl_enum_for_stencil_function(const OpenGL::StencilFunction& in_stencil_function);
        OpenGL::StencilFunction get_stencil_function_for_gl_enum(const GLenum&                  in_enum);

        GLenum                   get_gl_enum_for_stencil_operation(const OpenGL::StencilOperation& in_operation);
        OpenGL::StencilOperation get_stencil_operation_for_gl_enum(const GLenum&                   in_enum);

        GLenum                   get_gl_enum_for_stencil_state_face(const OpenGL::StencilStateFace& in_face);
        OpenGL::StencilStateFace get_stencil_state_face_for_gl_enum(const GLenum&                   in_enum);

        GLenum                get_gl_enum_for_sync_condition(const OpenGL::SyncCondition& in_condition);
        OpenGL::SyncCondition get_sync_condition_for_gl_enum(const GLenum&                in_enum);

        GLenum               get_gl_enum_for_sync_property(const OpenGL::SyncProperty& in_pname);
        OpenGL::SyncProperty get_sync_property_for_gl_enum(const GLenum&               in_enum);

        OpenGL::TextureBindingProperty get_texture_binding_property_for_context_property(const OpenGL::ContextProperty& in_pname);
        bool                           is_texture_binding_pname                         (const OpenGL::ContextProperty& in_pname);

        GLenum                         get_gl_enum_for_texture_compare_function(const OpenGL::TextureCompareFunction& in_compare_function);
        OpenGL::TextureCompareFunction get_texture_compare_function_for_gl_enum(const GLenum&                         in_enum);

        GLenum                     get_gl_enum_for_texture_compare_mode(const OpenGL::TextureCompareMode& in_mode);
        OpenGL::TextureCompareMode get_texture_compare_mode_for_gl_enum(const GLenum&                     in_enum);

        GLenum                     get_gl_enum_for_texture_cube_map_face(const OpenGL::TextureCubeMapFace& in_face);
        OpenGL::TextureCubeMapFace get_texture_cube_map_face_for_gl_enum(const GLenum&                     in_enum);

        GLenum                   get_gl_enum_for_texture_mag_filter(const OpenGL::TextureMagFilter& in_filter);
        OpenGL::TextureMagFilter get_texture_mag_filter_for_gl_enum(const GLenum&                   in_enum);

        GLenum                   get_gl_enum_for_texture_min_filter(const OpenGL::TextureMinFilter& in_filter);
        OpenGL::TextureMinFilter get_texture_min_filter_for_gl_enum(const GLenum&                   in_enum);

        GLenum                  get_gl_enum_for_texture_property(const OpenGL::TextureProperty& in_property);
        OpenGL::TextureProperty get_texture_property_for_gl_enum(const GLenum&                  in_enum);

        GLenum                       get_gl_enum_for_texture_level_property(const OpenGL::TextureLevelProperty& in_property);
        OpenGL::TextureLevelProperty get_texture_level_property_for_gl_enum(const GLenum&                       in_enum);

        GLenum                 get_gl_enum_for_texture_swizzle(const OpenGL::TextureSwizzle& in_swizzle);
        OpenGL::TextureSwizzle get_texture_swizzle_for_gl_enum(const GLenum&                 in_enum);

        GLenum                get_gl_enum_for_texture_target(const OpenGL::TextureTarget& in_texture_target);
        OpenGL::TextureTarget get_texture_target_for_gl_enum(const GLenum&                in_enum);

        GLenum                  get_gl_enum_for_texture_wrap_mode(const OpenGL::TextureWrapMode& in_wrap_mode);
        OpenGL::TextureWrapMode get_texture_wrap_mode_for_gl_enum(const GLenum&                  in_enum);

        GLenum                              get_gl_enum_for_transform_feedback_buffer_mode(const OpenGL::TransformFeedbackBufferMode& in_mode);
        OpenGL::TransformFeedbackBufferMode get_transform_feedback_buffer_mode_for_gl_enum(const GLenum&                              in_enum);

        GLenum                                 get_gl_enum_for_transform_feedback_primitive_mode(const OpenGL::TransformFeedbackPrimitiveMode& in_mode);
        OpenGL::TransformFeedbackPrimitiveMode get_transform_feedback_primitive_mode_for_gl_enum(const GLenum&                                 in_enum);

        GLenum                       get_gl_enum_for_uniform_block_property(const OpenGL::UniformBlockProperty& in_property);
        OpenGL::UniformBlockProperty get_uniform_block_property_for_gl_enum(const GLenum&                       in_enum);

        GLenum                  get_gl_enum_for_uniform_property(const OpenGL::UniformProperty& in_property);
        OpenGL::UniformProperty get_uniform_property_for_gl_enum(const GLenum&                  in_enum);

        GLenum             get_gl_enum_for_wait_result(const OpenGL::WaitResult& in_result);
        OpenGL::WaitResult get_wait_result_for_gl_enum(const GLenum&             in_enum);

        OpenGL::WaitSyncBits get_wait_sync_bits_for_gl_enum(const GLenum&               in_enum);
        GLenum               get_gl_enum_for_wait_sync_bits(const OpenGL::WaitSyncBits& in_bits);

        GLenum               get_gl_enum_for_variable_type(const VariableType& in_type);
        uint32_t             get_n_bytes_for_variable_type(const VariableType& in_type);
        OpenGL::VariableType get_variable_type_for_gl_enum(const GLenum&       in_enum);

        GLenum                           get_gl_enum_for_vertex_attribute_array_type(const OpenGL::VertexAttributeArrayType& in_type);
        uint32_t                         get_n_bytes_for_vertex_attribute_array_type(const OpenGL::VertexAttributeArrayType& in_type);
        OpenGL::VertexAttributeArrayType get_vertex_attribute_array_type_for_gl_enum(const GLenum&                           in_enum);

        GLenum                                 get_gl_enum_for_vertex_attribute_pointer_property(const OpenGL::VertexAttributePointerProperty& in_pname);
        OpenGL::VertexAttributePointerProperty get_vertex_attribute_pointer_property_for_gl_enum(const GLenum&                                 in_enum);

        GLenum                          get_gl_enum_for_vertex_attribute_property(const OpenGL::VertexAttributeProperty& in_property);
        OpenGL::VertexAttributeProperty get_vertex_attribute_property_for_gl_enum(const GLenum&                          in_pname);

        bool is_context_property_gl_constant(const OpenGL::ContextProperty& in_pname);
        bool is_context_property_gl_limit   (const OpenGL::ContextProperty& in_pname);

        uint32_t get_n_dimensions_for_texture_target(const OpenGL::TextureTarget& in_texture_target);
        bool     is_texture_target_arrayed          (const OpenGL::TextureTarget& in_texture_target);
        bool     is_texture_target_multisample      (const OpenGL::TextureTarget& in_texture_target);
    }
};

#endif /* VKGL_UTILS_ENUM_H */