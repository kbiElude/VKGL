#ifndef VKGL_UTILS_ENUM_H
#define VKGL_UTILS_ENUM_H

#include "OpenGL/types.h"

namespace VKGL
{
    namespace Utils
    {
        VKGL::BlendFunction get_blend_function_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_blend_function(const VKGL::BlendFunction& in_blend_func);

        GLenum           get_gl_enum_for_indexed_capability   (const VKGL::Capability& in_capability,
                                                               const uint32_t&         in_index);
        GLenum           get_gl_enum_for_nonindexed_capability(const VKGL::Capability& in_capability);
        void             get_indexed_capability_for_gl_enum   (const GLenum&           in_enum,
                                                               VKGL::Capability*       out_capability_ptr,
                                                               uint32_t*               out_index_ptr);
        VKGL::Capability get_nonindexed_capability_for_gl_enum(const GLenum&           in_enum);

        VKGL::ClearBufferBits get_clear_buffer_bits_for_gl_enum(const GLenum&                in_enum);
        GLenum                get_gl_enum_for_clear_buffer_bits(const VKGL::ClearBufferBits& in_buffers);

        VKGL::CullMode get_cull_mode_for_gl_enum(const GLenum&         in_enum);
        GLenum         get_gl_enum_for_cull_mode(const VKGL::CullMode& in_cull_mode);

        VKGL::DepthFunction get_depth_function_for_gl_enum(const GLenum&              in_enum);
        GLenum              get_gl_enum_for_depth_function(const VKGL::DepthFunction& in_depth_function);

        VKGL::DepthStencilTextureMode get_depth_stencil_texture_mode_for_gl_enum(const GLenum&                        in_enum);
        GLenum                        get_gl_enum_for_depth_stencil_texture_mode(const VKGL::DepthStencilTextureMode& in_mode);

        VKGL::FrontFaceOrientation get_front_face_orientation_for_gl_enum(const GLenum&                     in_enum);
        GLenum                     get_gl_enum_for_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation);

        GLenum         get_gl_enum_for_hint_mode(const VKGL::HintMode& in_hint_mode);
        VKGL::HintMode get_hint_mode_for_gl_enum(const GLenum&         in_enum);

        GLenum               get_gl_enum_for_internal_format(const VKGL::InternalFormat& in_internal_format);
        VKGL::InternalFormat get_internal_format_for_gl_enum(const GLenum&               in_enum);

        GLenum            get_gl_enum_for_logic_op_mode(const VKGL::LogicOpMode& in_logic_op_mode);
        VKGL::LogicOpMode get_logic_op_mode_for_gl_enum(const GLenum&            in_enum);

        GLenum            get_gl_enum_for_pixel_format(const VKGL::PixelFormat& in_pixel_format);
        VKGL::PixelFormat get_pixel_format_for_gl_enum(const GLenum&            in_enum);

        GLenum          get_gl_enum_for_pixel_type(const VKGL::PixelType& in_pixel_type);
        VKGL::PixelType get_pixel_type_for_gl_enum(const GLenum&          in_enum);

        GLenum            get_gl_enum_for_polygon_mode(const VKGL::PolygonMode& in_polygon_mode);
        VKGL::PolygonMode get_polygon_mode_for_gl_enum(const GLenum&            in_enum);

        GLenum                get_gl_enum_for_stencil_function(const VKGL::StencilFunction& in_stencil_function);
        VKGL::StencilFunction get_stencil_function_for_gl_enum(const GLenum&                in_enum);

        GLenum                 get_gl_enum_for_stencil_operation(const VKGL::StencilOperation& in_operation);
        VKGL::StencilOperation get_stencil_operation_for_gl_enum(const GLenum&                 in_enum);

        VKGL::TextureCompareFunction get_texture_compare_function_for_gl_enum(const GLenum&                       in_enum);
        GLenum                       get_gl_enum_for_texture_compare_function(const VKGL::TextureCompareFunction& in_compare_function);

        GLenum                   get_gl_enum_for_texture_compare_mode(const VKGL::TextureCompareMode& in_mode);
        VKGL::TextureCompareMode get_texture_compare_mode_for_gl_enum(const GLenum&                   in_enum);

        GLenum                 get_gl_enum_for_texture_mag_filter(const VKGL::TextureMagFilter& in_filter);
        VKGL::TextureMagFilter get_texture_mag_filter_for_gl_enum(const GLenum&                 in_enum);

        GLenum                 get_gl_enum_for_texture_min_filter(const VKGL::TextureMinFilter& in_filter);
        VKGL::TextureMinFilter get_texture_min_filter_for_gl_enum(const GLenum&                 in_enum);

        GLenum               get_gl_enum_for_texture_swizzle(const VKGL::TextureSwizzle& in_swizzle);
        VKGL::TextureSwizzle get_texture_swizzle_for_gl_enum(const GLenum&               in_enum);

        GLenum              get_gl_enum_for_texture_target(const VKGL::TextureTarget& in_texture_target);
        VKGL::TextureTarget get_texture_target_for_gl_enum(const GLenum&              in_enum);

        GLenum                get_gl_enum_for_texture_wrap_mode(const VKGL::TextureWrapMode& in_wrap_mode);
        VKGL::TextureWrapMode get_texture_wrap_mode_for_gl_enum(const GLenum&                in_enum);
    }
};

#endif /* VKGL_UTILS_ENUM_H */