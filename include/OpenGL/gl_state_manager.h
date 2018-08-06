/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STATE_MANAGER_H
#define VKGL_GL_STATE_MANAGER_H

#include "OpenGL/types.h"


namespace VKGL
{
    class GLStateManager
    {
    public:
        GLStateManager(const IGLLimits* in_limits_ptr);
       ~GLStateManager();

        VKGL::ErrorCode     get_error                    (const bool&                         in_reset_error_code = true);
        void                get_parameter                (const VKGL::ContextProperty&        in_pname,
                                                          const VKGL::GetSetArgumentType&     in_arg_type,
                                                          void*                               out_arg_value_ptr) const;
        void                get_pixel_store_parameter    (const VKGL::PixelStoreProperty&     in_pname,
                                                          const VKGL::GetSetArgumentType&     in_arg_type,
                                                          void*                               out_arg_value_ptr) const;
        const ContextState* get_state                    ()                                                      const;
        void                get_texture_binding_parameter(const VKGL::TextureBindingProperty& in_pname,
                                                          const VKGL::GetSetArgumentType&     in_arg_type,
                                                          void*                               out_arg_value_ptr) const;

        void set_blend_functions       (const VKGL::BlendFunction&        in_src_rgba_function,
                                        const VKGL::BlendFunction&        in_dst_rgba_function);
        void set_clear_color_value     (const float&                      in_red,
                                        const float&                      in_green,
                                        const float&                      in_blue,
                                        const float&                      in_alpha);
        void set_clear_depth_value     (const double&                     in_value);
        void set_clear_stencil_value   (const int&                        in_value);
        void set_color_mask            (const bool&                       in_red,
                                        const bool&                       in_green,
                                        const bool&                       in_blue,
                                        const bool&                       in_alpha);
        void set_cull_mode             (const VKGL::CullMode&             in_mode);
        void set_depth_function        (const VKGL::DepthFunction&        in_function);
        void set_depth_mask            (const bool&                       in_flag);
        void set_depth_range           (const double&                     in_near,
                                        const double&                     in_far);
        void set_draw_buffer           (const VKGL::DrawBuffer&           in_draw_buffer);
        void set_front_face_orientation(const VKGL::FrontFaceOrientation& in_orientation);
        void set_hint                  (const VKGL::HintTarget&           in_target,
                                        const VKGL::HintMode&             in_mode);
        void set_line_width            (const float&                      in_width);
        void set_logic_op              (const VKGL::LogicOpMode&          in_mode);
        void set_pixel_store_property  (const VKGL::PixelStoreProperty&   in_property,
                                        const VKGL::GetSetArgumentType&   in_arg_type,
                                        const void*                       in_arg_value_ptr);
        void set_point_size            (const float&                      in_size);
        void set_polygon_mode          (const VKGL::PolygonMode&          in_mode);
        void set_polygon_offset        (const float&                      in_factor,
                                        const float&                      in_units);
        void set_read_buffer           (const VKGL::ReadBuffer&           in_read_buffer);
        void set_scissor               (const int32_t&                    in_x,
                                        const int32_t&                    in_y,
                                        const size_t&                     in_width,
                                        const size_t&                     in_height);
        void set_stencil_function      (const VKGL::StencilFunction&      in_func,
                                        const int32_t&                    in_ref,
                                        const uint32_t&                   in_mask);
        void set_stencil_mask          (const uint32_t&                   in_mask);
        void set_stencil_operations    (const VKGL::StencilOperation&     in_fail,
                                        const VKGL::StencilOperation&     in_zfail,
                                        const VKGL::StencilOperation&     in_zpass);
        void set_viewport              (const int32_t&                    in_x,
                                        const int32_t&                    in_y,
                                        const size_t&                     in_width,
                                        const size_t&                     in_height);

        bool is_enabled(const VKGL::Capability& in_capability) const;

        void disable(const VKGL::Capability& in_capability);
        void enable (const VKGL::Capability& in_capability);

        GLuint get_texture_binding(const uint32_t&            in_n_texture_unit,
                                   const VKGL::TextureTarget& in_texture_target) const;
        void   set_texture_binding(const uint32_t&            in_n_texture_unit,
                                   const VKGL::TextureTarget& in_texture_target,
                                   const GLuint&              in_texture_id);

    private:
        /* Private type definitions */

        typedef struct PropertyData
        {
            VKGL::GetSetArgumentType getter_value_type;
            uint32_t                 n_value_components;
            void*                    value_ptr;
        }
        PropertyData;

        typedef uint32_t TextureUnit;

        /* Private functions */

        void init_prop_maps    ();
        void init_texture_units();

        /* Private variables */

        VKGL::ErrorCode                                                  m_current_error_code;
        const IGLLimits* const                                           m_limits_ptr;
        ContextStateUniquePtr                                            m_state_ptr;
        std::unordered_map<TextureUnit, VKGL::TextureUnitStateUniquePtr> m_texture_unit_to_state_ptr_map;

        std::unordered_map<VKGL::ContextProperty,    PropertyData> m_context_prop_map;
        std::unordered_map<VKGL::PixelStoreProperty, PropertyData> m_pixel_store_prop_map;
    };

    typedef std::unique_ptr<GLStateManager> GLStateManagerUniquePtr;
}

#endif /* VKGL_GL_STATE_MANAGER_H */