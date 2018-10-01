/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_STATE_MANAGER_H
#define VKGL_GL_STATE_MANAGER_H

#include "OpenGL/types.h"
#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/frontend/snapshot_manager.h"

namespace OpenGL
{
    class GLStateManager : public IStateSnapshotAccessors
    {
    public:
        GLStateManager(const IGLLimits*        in_limits_ptr,
                       const IGLObjectManager* in_buffer_manager_ptr,
                       const IGLObjectManager* in_vao_manager_ptr);
       ~GLStateManager();

       OpenGL::ErrorCode   get_error                    (const bool&                           in_reset_error_code = true);
       void                get_parameter                (const OpenGL::ContextProperty&        in_pname,
                                                         const OpenGL::GetSetArgumentType&     in_arg_type,
                                                         void*                                 out_arg_value_ptr) const;
       void                get_pixel_store_parameter    (const OpenGL::PixelStoreProperty&     in_pname,
                                                         const OpenGL::GetSetArgumentType&     in_arg_type,
                                                         void*                                 out_arg_value_ptr) const;
       const ContextState* get_state                    ()                                                        const;
       void                get_texture_binding_parameter(const OpenGL::TextureBindingProperty& in_pname,
                                                         const OpenGL::GetSetArgumentType&     in_arg_type,
                                                         void*                                 out_arg_value_ptr) const;

       const OpenGL::GLReference* get_bound_buffer_object      (const OpenGL::BufferTarget& in_target) const;
       const OpenGL::GLReference* get_bound_buffer_object      (const OpenGL::BufferTarget& in_target,
                                                                const uint32_t&             in_index) const;
       const OpenGL::GLReference* get_bound_vertex_array_object() const;

       void set_bound_buffer_object      (const OpenGL::BufferTarget&  in_target,
                                          OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr);
       void set_bound_buffer_object      (const OpenGL::BufferTarget&  in_target,
                                          const uint32_t&              in_index,
                                          OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                                          const size_t&                in_start_offset,
                                          const size_t&                in_size);
       void set_bound_program_object     (OpenGL::GLReferenceUniquePtr in_program_reference_ptr);
       void set_bound_vertex_array_object(OpenGL::GLReferenceUniquePtr in_vao_reference_ptr);

       void set_active_texture          (const uint32_t&                     in_n_texture_unit);
       void set_blend_color             (const float&                        in_red,
                                         const float&                        in_green,
                                         const float&                        in_blue,
                                         const float&                        in_alpha);
       void set_blend_equation          (const OpenGL::BlendEquation&        in_blend_equation);
       void set_blend_functions         (const OpenGL::BlendFunction&        in_src_rgba_function,
                                         const OpenGL::BlendFunction&        in_dst_rgba_function);
       void set_blend_functions_separate(const OpenGL::BlendFunction&        in_src_rgb_function,
                                         const OpenGL::BlendFunction&        in_dst_rgb_function,
                                         const OpenGL::BlendFunction&        in_src_alpha_function,
                                         const OpenGL::BlendFunction&        in_dst_alpha_function);
       void set_clear_color_value       (const float&                        in_red,
                                         const float&                        in_green,
                                         const float&                        in_blue,
                                         const float&                        in_alpha);
       void set_clear_depth_value       (const double&                       in_value);
       void set_clear_stencil_value     (const int&                          in_value);
       void set_color_mask              (const bool&                         in_red,
                                         const bool&                         in_green,
                                         const bool&                         in_blue,
                                         const bool&                         in_alpha);
       void set_cull_mode               (const OpenGL::CullMode&             in_mode);
       void set_depth_function          (const OpenGL::DepthFunction&        in_function);
       void set_depth_mask              (const bool&                         in_flag);
       void set_depth_range             (const double&                       in_near,
                                         const double&                       in_far);
       void set_draw_buffer             (const OpenGL::DrawBuffer&           in_draw_buffer);
       void set_front_face_orientation  (const OpenGL::FrontFaceOrientation& in_orientation);
       void set_hint                    (const OpenGL::HintTarget&           in_target,
                                         const OpenGL::HintMode&             in_mode);
       void set_line_width              (const float&                        in_width);
       void set_logic_op                (const OpenGL::LogicOpMode&          in_mode);
       void set_pixel_store_property    (const OpenGL::PixelStoreProperty&   in_property,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         const void*                         in_arg_value_ptr);
       void set_point_property          (const OpenGL::PointProperty&        in_property,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         const void*                         in_arg_value_ptr);
       void set_point_size              (const float&                        in_size);
       void set_polygon_mode            (const OpenGL::PolygonMode&          in_mode);
       void set_polygon_offset          (const float&                        in_factor,
                                         const float&                        in_units);
       void set_read_buffer             (const OpenGL::ReadBuffer&           in_read_buffer);
       void set_sample_coverage         (const float&                        in_value,
                                         const bool&                         in_invert);
       void set_scissor                 (const int32_t&                      in_x,
                                         const int32_t&                      in_y,
                                         const size_t&                       in_width,
                                         const size_t&                       in_height);
       void set_stencil_function        (const OpenGL::StencilFunction&      in_func,
                                         const int32_t&                      in_ref,
                                         const uint32_t&                     in_mask);
       void set_stencil_mask            (const uint32_t&                     in_mask);
       void set_stencil_operations      (const OpenGL::StencilOperation&     in_fail,
                                         const OpenGL::StencilOperation&     in_zfail,
                                         const OpenGL::StencilOperation&     in_zpass);
       void set_viewport                (const int32_t&                      in_x,
                                         const int32_t&                      in_y,
                                         const size_t&                       in_width,
                                         const size_t&                       in_height);

       bool is_enabled(const OpenGL::Capability& in_capability) const;

       void disable(const OpenGL::Capability& in_capability);
       void enable (const OpenGL::Capability& in_capability);

       GLuint get_texture_binding(const uint32_t&              in_n_texture_unit,
                                  const OpenGL::TextureTarget& in_texture_target) const;
       void   set_texture_binding(const uint32_t&              in_n_texture_unit,
                                  const OpenGL::TextureTarget& in_texture_target,
                                  const GLuint&                in_texture_id);

    private:
        /* Private type definitions */

        typedef struct PropertyData
        {
            OpenGL::GetSetArgumentType getter_value_type;
            uint32_t                   n_value_components;
            size_t                     value_offset;
        }
        PropertyData;

        /* IStateSnapshotAccessors */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr)     final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr) final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                       final;

        /* Private functions */

        void init_prop_maps    ();
        void init_texture_units();

        /* Private variables */

        const IGLObjectManager*                  m_buffer_manager_ptr;
        OpenGL::ErrorCode                        m_current_error_code;
        const IGLLimits* const                   m_limits_ptr;
        std::unique_ptr<OpenGL::SnapshotManager> m_snapshot_manager_ptr;
        const IGLObjectManager*                  m_vao_manager_ptr;

        std::unordered_map<OpenGL::ContextProperty,    PropertyData> m_context_prop_map;
        std::unordered_map<OpenGL::PixelStoreProperty, PropertyData> m_pixel_store_prop_map;
        std::unordered_map<OpenGL::PointProperty,      PropertyData> m_point_prop_map;
    };

    typedef std::unique_ptr<GLStateManager> GLStateManagerUniquePtr;
}

#endif /* VKGL_GL_STATE_MANAGER_H */