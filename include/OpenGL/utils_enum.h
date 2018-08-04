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

        VKGL::BufferAccess get_buffer_access_for_gl_enum(const GLenum&             in_enum);
        GLenum             get_gl_enum_for_buffer_access(const VKGL::BufferAccess& in_access);

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

        VKGL::ClearBufferBits get_clear_buffer_bits_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_clear_buffer_bits(const VKGL::ClearBufferBits& in_buffers);

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

        VKGL::ErrorCode get_error_code_for_gl_enum(const GLenum&          in_enum);
        GLenum          get_gl_enum_for_error_code(const VKGL::ErrorCode& in_error);

        VKGL::FramebufferAttachmentComponentType get_framebuffer_attachment_component_type_for_gl_enum(const GLenum&                                   in_enum);
        GLenum                                   get_gl_enum_for_framebuffer_attachment_component_type(const VKGL::FramebufferAttachmentComponentType& in_type);

        VKGL::FramebufferAttachmentObjectType get_framebuffer_attachment_object_type_for_gl_enum(const GLenum&                                in_enum);
        GLenum                                get_gl_enum_for_framebuffer_attachment_object_type(const VKGL::FramebufferAttachmentObjectType& in_type);

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

        GLenum            get_gl_enum_for_pixel_format(const VKGL::PixelFormat& in_pixel_format);
        VKGL::PixelFormat get_pixel_format_for_gl_enum(const GLenum&            in_enum);

        GLenum                   get_gl_enum_for_pixel_store_property          (const VKGL::PixelStoreProperty& in_property);
        PixelStoreProperty       get_pixel_store_property_from_context_property(const VKGL::ContextProperty&    in_context_property);
        VKGL::PixelStoreProperty get_pixel_store_property_for_gl_enum          (const GLenum&                   in_enum);

        GLenum          get_gl_enum_for_pixel_type(const VKGL::PixelType& in_pixel_type);
        VKGL::PixelType get_pixel_type_for_gl_enum(const GLenum&          in_enum);

        GLenum                       get_gl_enum_for_point_sprite_coord_origin(const VKGL::PointSpriteCoordOrigin& in_origin);
        VKGL::PointSpriteCoordOrigin get_point_sprite_coord_origin_for_gl_enum(const GLenum&                       in_enum);

        GLenum            get_gl_enum_for_polygon_mode(const VKGL::PolygonMode& in_polygon_mode);
        VKGL::PolygonMode get_polygon_mode_for_gl_enum(const GLenum&            in_enum);

        GLenum                          get_gl_enum_for_provoking_vertex_convention(const VKGL::ProvokingVertexConvention& in_convention);
        VKGL::ProvokingVertexConvention get_provoking_vertex_convention_for_gl_enum(const GLenum&                          in_enum);

        VKGL::ReadBuffer get_read_buffer_for_gl_enum(const GLenum&           in_enum);
        GLenum           get_gl_enum_for_read_buffer(const VKGL::ReadBuffer& in_read_buffer);

        GLenum           get_gl_enum_for_shader_type(const VKGL::ShaderType& in_shader_type);
        VKGL::ShaderType get_shader_type_for_gl_enum(const GLenum&           in_enum);

        GLenum                get_gl_enum_for_stencil_function(const VKGL::StencilFunction& in_stencil_function);
        VKGL::StencilFunction get_stencil_function_for_gl_enum(const GLenum&                in_enum);

        GLenum                 get_gl_enum_for_stencil_operation(const VKGL::StencilOperation& in_operation);
        VKGL::StencilOperation get_stencil_operation_for_gl_enum(const GLenum&                 in_enum);

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

        GLenum             get_gl_enum_for_variable_type(const VariableType& in_type);
        VKGL::VariableType get_variable_type_for_gl_enum(const GLenum&       in_enum);

        GLenum                         get_gl_enum_for_vertex_attribute_array_type(const VKGL::VertexAttributeArrayType& in_type);
        VKGL::VertexAttributeArrayType get_vertex_attribute_array_type_for_gl_enum(const GLenum&                         in_enum);

        bool is_context_property_gl_limit(const VKGL::ContextProperty& in_pname);
    }
};

#endif /* VKGL_UTILS_ENUM_H */