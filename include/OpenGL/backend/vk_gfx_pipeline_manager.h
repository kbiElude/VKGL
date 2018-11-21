/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_GFX_PIPELINE_MANAGER_H
#define VKGL_VK_GFX_PIPELINE_MANAGER_H

#include "Common/shared_mutex.h"
#include "OpenGL/backend/vk_renderpass_manager.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef uint32_t GFXPipelineID;

    class VKGFXPipelineManager
    {
    public:
        /* Public functions */

        static VKGFXPipelineManagerUniquePtr create(IBackend* in_backend_ptr);

        GFXPipelineID get_pipeline_id(const OpenGL::ContextState* in_context_state_ptr) const;

        ~VKGFXPipelineManager();

    private:
        /* Private type definition */
        typedef struct GFXPipelineProps
        {
            typedef uint64_t GLStateHash;

            const struct GLState
            {
                /* The following state is assumed to be dynamic, hence is not used for hash calculation:
                 *
                 * - Blend constants
                 * - Line width
                 * - Scissor box
                 * - Stencil compare masks
                 * - Stencil reference value
                 * - Stencil write masks
                 * - Viewport
                 */
                const bool is_blend_enabled;
                const bool is_color_logic_op_enabled;
                const bool is_cull_face_enabled;
                const bool is_depth_clamp_enabled;
                const bool is_depth_test_enabled;
                const bool is_framebuffer_srgb_enabled;
                const bool is_line_smooth_enabled;
                const bool is_multisample_enabled;
                const bool is_polygon_offset_fill_enabled;
                const bool is_polygon_offset_line_enabled;
                const bool is_polygon_offset_point_enabled;
                const bool is_polygon_smooth_enabled;
                const bool is_primitive_restart_enabled;
                const bool is_program_point_size_enabled;
                const bool is_sample_alpha_to_coverage_enabled;
                const bool is_sample_alpha_to_one_enabled;
                const bool is_sample_coverage_enabled;
                const bool is_sample_coverage_invert_enabled;
                const bool is_sample_mask_enabled;
                const bool is_scissor_test_enabled;
                const bool is_stencil_test_enabled;
                const bool is_texture_cube_map_seamless_enabled;

                const int32_t primitive_restart_index;

                const std::array<double, 2> depth_range;
                const std::vector<bool>     user_clip_planes_enabled;

                const OpenGL::ClampReadColorMode        clamp_read_color;
                const OpenGL::ProvokingVertexConvention provoking_vertex;

                const float                          point_fade_threshold_size;
                const float                          point_size;
                const OpenGL::PointSpriteCoordOrigin point_sprite_coord_origin;

                const OpenGL::CullMode             cull_face_mode;
                const OpenGL::FrontFaceOrientation front_face;
                const float                        polygon_offset_factor;
                const float                        polygon_offset_units;

                const float    sample_coverage_value;
                const uint32_t sample_mask;

                const OpenGL::StencilFunction  stencil_function_back;
                const OpenGL::StencilFunction  stencil_function_front;
                const OpenGL::StencilOperation stencil_op_fail_back;
                const OpenGL::StencilOperation stencil_op_fail_front;
                const OpenGL::StencilOperation stencil_op_pass_depth_fail_back;
                const OpenGL::StencilOperation stencil_op_pass_depth_fail_front;
                const OpenGL::StencilOperation stencil_op_pass_depth_pass_back;
                const OpenGL::StencilOperation stencil_op_pass_depth_pass_front;

                const OpenGL::BlendEquation blend_equation_alpha;
                const OpenGL::BlendEquation blend_equation_rgb;
                const OpenGL::BlendFunction blend_func_dst_alpha;
                const OpenGL::BlendFunction blend_func_dst_rgb;
                const OpenGL::BlendFunction blend_func_src_alpha;
                const OpenGL::BlendFunction blend_func_src_rgb;
                const OpenGL::DepthFunction depth_function;
                const OpenGL::LogicOpMode   logic_op_mode;

                const uint32_t color_writemask_for_draw_buffers; /* 4-bits per each draw buffer. */
                const bool     depth_writemask;

                const PolygonMode polygon_mode;

                const OpenGL::GLPayload program_reference_payload;
                const OpenGL::GLPayload vao_reference_payload;


                GLState();
                GLState(const OpenGL::ContextState* in_context_state_ptr);

                GLStateHash get_hash() const;

                bool operator==(const OpenGL::ContextState* in_context_state_ptr);
            } gl_state;

            typedef struct PipelineData
            {
                Anvil::PipelineID        pipeline_id;
                Anvil::PrimitiveTopology primitive_topology;

                PipelineData()
                    :pipeline_id       (UINT32_MAX),
                     primitive_topology(Anvil::PrimitiveTopology::UNKNOWN)
                {
                    /* Stub */
                }

                PipelineData(const Anvil::PipelineID&        in_pipeline_id,
                             const Anvil::PrimitiveTopology& in_primitive_topology)
                    :pipeline_id       (in_pipeline_id),
                     primitive_topology(in_primitive_topology)
                {
                    /* Stub */
                }
            } PipelineData;

            const Anvil::BaseDevice* device_ptr;
            const Anvil::RenderPass* rp_ptr;

            GFXPipelineProps (const Anvil::BaseDevice*    in_device_ptr,
                              const OpenGL::ContextState* in_context_state_ptr,
                              const Anvil::RenderPass*    in_rp_ptr);

           ~GFXPipelineProps();

            Anvil::PipelineID get_pipeline_id(const Anvil::PrimitiveTopology&       in_primitive_topology,
                                              const Anvil::SubPassID&               in_subpass_id,
                                              const OpenGL::IBackend*               in_backend_ptr,
                                              const OpenGL::IContextObjectManagers* in_frontend_ptr);

            private:
                /* Private functions */
                Anvil::GraphicsPipelineCreateInfoUniquePtr create_create_info_ptr(const OpenGL::GLVAOManager*              in_vao_manager_ptr,
                                                                                  const OpenGL::VKSPIRVManager*            in_spirv_manager_ptr,
                                                                                  const Anvil::PrimitiveTopology&          in_primitive_topology,
                                                                                  const Anvil::SubPassID&                  in_subpass_id) const;
                Anvil::Format                              get_format_for_vaa    (const OpenGL::VertexAttributeArrayState& in_vaa) const;

            mutable VKGL::SharedMutex                                        rw_mutex;
            std::unordered_map<Anvil::SubPassID, std::vector<PipelineData> > subpass_id_to_pipeline_data_map;
        } GFXPipelineProps;

        typedef std::unique_ptr<GFXPipelineProps> GFXPipelinePropsUniquePtr;

        /* Private functions */
        VKGFXPipelineManager(IBackend* in_backend_ptr);

        /* Private variables */
        IBackend* const m_backend_ptr;

        std::unordered_map<OpenGL::RenderPassHash, GFXPipelinePropsUniquePtr> m_rp_hash_to_gfx_pipeline_props_ptr_map;
        mutable VKGL::SharedMutex                                             m_rw_mutex;
    };
}
#endif /* VKGL_VK_GFX_PIPELINE_MANAGER_H */
