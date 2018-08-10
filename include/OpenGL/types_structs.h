/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_STRUCTS_H
#define VKGL_TYPES_STRUCTS_H

namespace VKGL
{
    /* Forward declarations */
    struct VertexAttributeArrayState;

    typedef union UniformValue
    {
        int32_t  ivec4[4];
        uint32_t uvec4[4];
        float    vec4 [4];

        UniformValue();
    } UniformValue;

    typedef struct ActiveAttributeState
    {
        std::string  name;
        uint32_t     size;
        VariableType type;

        ActiveAttributeState();
    } ActiveAttributeState;

    typedef struct ActiveUniformBlock
    {
        std::vector<uint32_t> active_uniform_indices;
        uint32_t              binding;
        uint32_t              data_size;
        bool                  referenced_by_fragment_shader;
        bool                  referenced_by_geometry_shader;
        bool                  referenced_by_vertex_shader;

        ActiveUniformBlock();
    } ActiveUniformBlock;

    typedef struct ActiveUniformState
    {
        bool         is_row_major;
        uint32_t     location;
        std::string  name;
        uint32_t     size;
        VariableType type;
        uint32_t     uniform_array_stride;
        uint32_t     uniform_block_index;
        uint32_t     uniform_block_offset;
        uint32_t     uniform_matrix_stride;
        UniformValue value;

        ActiveUniformState();
    } ActiveUniformState;

    typedef struct BufferState
    {
        VKGL::BufferAccess access;
        uint64_t           map_size;
        uint64_t           map_start_offset;
        bool               mapped;
        uint64_t           size;
        VKGL::BufferUsage  usage;

        BufferState();
    } BufferState;

    typedef struct RangedBufferBinding
    {
        GLuint   buffer_id;
        uint64_t size;
        uint64_t start_offset;

        RangedBufferBinding();
    } RangedBufferBinding;

    typedef struct SamplePosition
    {
        float x;
        float y;

        SamplePosition();
    } SamplePosition;

    typedef struct TransformFeedbackVaryingState
    {
        std::string  name;
        uint32_t     size;
        VariableType type;

        TransformFeedbackVaryingState();
    } TransformFeedbackVaryingState;

    /* Dispatch table - holds all function pointers as well as miscellaneous context-specific information.
     *
     * NOTE: The reason behind the additional indirection here is to support extensions such as no_error in the future.
     */
    struct DispatchTable
    {
        Context* bound_context_ptr;

        /* GL 1.0 */
        PFNVKGLBLENDFUNCPROC              pGLBlendFunc;
        PFNVKGLCLEARPROC                  pGLClear;
        PFNVKGLCLEARCOLORPROC             pGLClearColor;
        PFNVKGLCLEARDEPTHPROC             pGLClearDepth;
        PFNVKGLCLEARSTENCILPROC           pGLClearStencil;
        PFNVKGLCOLORMASKPROC              pGLColorMask;
        PFNVKGLCULLFACEPROC               pGLCullFace;
        PFNVKGLDEPTHFUNCPROC              pGLDepthFunc;
        PFNVKGLDEPTHMASKPROC              pGLDepthMask;
        PFNVKGLDEPTHRANGEPROC             pGLDepthRange;
        PFNVKGLDISABLEPROC                pGLDisable;
        PFNVKGLDRAWBUFFERPROC             pGLDrawBuffer;
        PFNVKGLENABLEPROC                 pGLEnable;
        PFNVKGLFINISHPROC                 pGLFinish;
        PFNVKGLFLUSHPROC                  pGLFlush;
        PFNVKGLFRONTFACEPROC              pGLFrontFace;
        PFNVKGLGETBOOLEANVPROC            pGLGetBooleanv;
        PFNVKGLGETDOUBLEVPROC             pGLGetDoublev;
        PFNVKGLGETERRORPROC               pGLGetError;
        PFNVKGLGETFLOATVPROC              pGLGetFloatv;
        PFNVKGLGETINTEGERVPROC            pGLGetIntegerv;
        PFNVKGLGETSTRINGPROC              pGLGetString;
        PFNVKGLGETTEXIMAGEPROC            pGLGetTexImage;
        PFNVKGLGETTEXLEVELPARAMETERFVPROC pGLGetTexLevelParameterfv;
        PFNVKGLGETTEXLEVELPARAMETERIVPROC pGLGetTexLevelParameteriv;
        PFNVKGLGETTEXPARAMETERFVPROC      pGLGetTexParameterfv;
        PFNVKGLGETTEXPARAMETERIVPROC      pGLGetTexParameteriv;
        PFNVKGLHINTPROC                   pGLHint;
        PFNVKGLISENABLEDPROC              pGLIsEnabled;
        PFNVKGLLINEWIDTHPROC              pGLLineWidth;
        PFNVKGLLOGICOPPROC                pGLLogicOp;
        PFNVKGLPIXELSTOREFPROC            pGLPixelStoref;
        PFNVKGLPIXELSTOREIPROC            pGLPixelStorei;
        PFNVKGLPOINTSIZEPROC              pGLPointSize;
        PFNVKGLPOLYGONMODEPROC            pGLPolygonMode;
        PFNVKGLREADBUFFERPROC             pGLReadBuffer;
        PFNVKGLREADPIXELSPROC             pGLReadPixels;
        PFNVKGLSCISSORPROC                pGLScissor;
        PFNVKGLSTENCILFUNCPROC            pGLStencilFunc;
        PFNVKGLSTENCILMASKPROC            pGLStencilMask;
        PFNVKGLSTENCILOPPROC              pGLStencilOp;
        PFNVKGLTEXIMAGE1DPROC             pGLTexImage1D;
        PFNVKGLTEXIMAGE2DPROC             pGLTexImage2D;
        PFNVKGLTEXPARAMETERFPROC          pGLTexParameterf;
        PFNVKGLTEXPARAMETERFVPROC         pGLTexParameterfv;
        PFNVKGLTEXPARAMETERIPROC          pGLTexParameteri;
        PFNVKGLTEXPARAMETERIVPROC         pGLTexParameteriv;
        PFNVKGLVIEWPORTPROC               pGLViewport;

        /* GL 1.1 */
        PFNVKGLBINDTEXTUREPROC       pGLBindTexture;
        PFNVKGLCOPYTEXIMAGE1DPROC    pGLCopyTexImage1D;
        PFNVKGLCOPYTEXIMAGE2DPROC    pGLCopyTexImage2D;
        PFNVKGLCOPYTEXSUBIMAGE1DPROC pGLCopyTexSubImage1D;
        PFNVKGLCOPYTEXSUBIMAGE2DPROC pGLCopyTexSubImage2D;
        PFNVKGLDELETETEXTURESPROC    pGLDeleteTextures;
        PFNVKGLDRAWARRAYSPROC        pGLDrawArrays;
        PFNVKGLDRAWELEMENTSPROC      pGLDrawElements;
        PFNVKGLGENTEXTURESPROC       pGLGenTextures;
        PFNVKGLISTEXTUREPROC         pGLIsTexture;
        PFNVKGLPOLYGONOFFSETPROC     pGLPolygonOffset;
        PFNVKGLTEXSUBIMAGE1DPROC     pGLTexSubImage1D;
        PFNVKGLTEXSUBIMAGE2DPROC     pGLTexSubImage2D;

        /* GL 1.2 */
        PFNVKGLCOPYTEXSUBIMAGE3DPROC pGLCopyTexSubImage3D;
        PFNVKGLDRAWRANGEELEMENTSPROC pGLDrawRangeElements;
        PFNVKGLTEXIMAGE3DPROC        pGLTexImage3D;
        PFNVKGLTEXSUBIMAGE3DPROC     pGLTexSubImage3D;

        /* GL 1.3 */
        PFNVKGLACTIVETEXTUREPROC           pGLActiveTexture;
        PFNVKGLCOMPRESSEDTEXIMAGE1DPROC    pGLCompressedTexImage1D;
        PFNVKGLCOMPRESSEDTEXIMAGE2DPROC    pGLCompressedTexImage2D;
        PFNVKGLCOMPRESSEDTEXIMAGE3DPROC    pGLCompressedTexImage3D;
        PFNVKGLCOMPRESSEDTEXSUBIMAGE1DPROC pGLCompressedTexSubImage1D;
        PFNVKGLCOMPRESSEDTEXSUBIMAGE2DPROC pGLCompressedTexSubImage2D;
        PFNVKGLCOMPRESSEDTEXSUBIMAGE3DPROC pGLCompressedTexSubImage3D;
        PFNVKGLGETCOMPRESSEDTEXIMAGEPROC   pGLGetCompressedTexImage;
        PFNVKGLSAMPLECOVERAGEPROC          pGLSampleCoverage;

        /* GL 1.4 */
        PFNVKGLBLENDCOLORPROC        pGLBlendColor;
        PFNVKGLBLENDEQUATIONPROC     pGLBlendEquation;
        PFNVKGLBLENDFUNCSEPARATEPROC pGLBlendFuncSeparate;
        PFNVKGLMULTIDRAWARRAYSPROC   pGLMultiDrawArrays;
        PFNVKGLMULTIDRAWELEMENTSPROC pGLMultiDrawElements;
        PFNVKGLPOINTPARAMETERFPROC   pGLPointParameterf;
        PFNVKGLPOINTPARAMETERFVPROC  pGLPointParameterfv;
        PFNVKGLPOINTPARAMETERIPROC   pGLPointParameteri;
        PFNVKGLPOINTPARAMETERIVPROC  pGLPointParameteriv;

        /* GL 1.5 */
        PFNVKGLBEGINQUERYPROC           pGLBeginQuery;
        PFNVKGLBINDBUFFERPROC           pGLBindBuffer;
        PFNVKGLBUFFERDATAPROC           pGLBufferData;
        PFNVKGLBUFFERSUBDATAPROC        pGLBufferSubData;
        PFNVKGLDELETEBUFFERSPROC        pGLDeleteBuffers;
        PFNVKGLDELETEQUERIESPROC        pGLDeleteQueries;
        PFNVKGLENDQUERYPROC             pGLEndQuery;
        PFNVKGLGENBUFFERSPROC           pGLGenBuffers;
        PFNVKGLGENQUERIESPROC           pGLGenQueries;
        PFNVKGLGETBUFFERPARAMETERIVPROC pGLGetBufferParameteriv;
        PFNVKGLGETBUFFERPOINTERVPROC    pGLGetBufferPointerv;
        PFNVKGLGETBUFFERSUBDATAPROC     pGLGetBufferSubData;
        PFNVKGLGETQUERYOBJECTIVPROC     pGLGetQueryObjectiv;
        PFNVKGLGETQUERYOBJECTUIVPROC    pGLGetQueryObjectuiv;
        PFNVKGLGETQUERYIVPROC           pGLGetQueryiv;
        PFNVKGLISBUFFERPROC             pGLIsBuffer;
        PFNVKGLISQUERYPROC              pGLIsQuery;
        PFNVKGLMAPBUFFERPROC            pGLMapBuffer;
        PFNVKGLUNMAPBUFFERPROC          pGLUnmapBuffer;

        DispatchTable();
    };

    typedef struct FramebufferAttachmentPointState
    {
        FramebufferAttachmentComponentType component_type;
        bool                               layered;
        GLuint                             name;
        uint32_t                           size_alpha;
        uint32_t                           size_blue;
        uint32_t                           size_depth;
        uint32_t                           size_green;
        uint32_t                           size_red;
        uint32_t                           size_stencil;
        TextureCubeMapFace                 texture_cube_map_face;
        uint32_t                           texture_layer;
        uint32_t                           texture_level;
        FramebufferAttachmentObjectType    type;
        bool                               uses_srgb_color_encoding;


        FramebufferAttachmentPointState();
    } FramebufferAttachmentPointState;

    typedef struct FramebufferState
    {
        std::vector<uint32_t> draw_buffer_per_color_output;
        uint32_t              read_buffer;

        std::vector<FramebufferAttachmentPointState> color_attachments;
        FramebufferAttachmentPointState              depth_attachment;
        FramebufferAttachmentPointState              stencil_attachment;

        bool                        is_doublebuffer;
        bool                        is_stereo;
        uint32_t                    n_sample_buffers;
        uint32_t                    n_samples;
        std::vector<SamplePosition> sample_position;

        explicit FramebufferState(const uint32_t& in_n_color_attachments);
    } FramebufferState;

    typedef struct ProgramState
    {
        uint32_t                          active_attribute_max_length;
        uint32_t                          active_uniform_block_max_length;
        uint32_t                          active_uniform_max_length;
        std::vector<ActiveUniformBlock>   active_uniform_blocks;
        std::vector<ActiveUniformState>   active_uniforms;
        std::vector<GLuint>               attached_shaders;
        bool                              delete_status;
        std::string                       info_log;
        bool                              link_status;
        uint32_t                          n_geometry_vertices_out;
        uint32_t                          n_transform_feedback_varyings;
        VKGL::GeometryInputType           geometry_input_type;
        VKGL::GeometryOutputType          geometry_output_type;
        VKGL::TransformFeedbackBufferMode transform_feedback_buffer_mode;
        uint32_t                          transform_feedback_varying_max_length;
        RangedBufferBinding               uniform_buffer_binding_generic;
        std::vector<RangedBufferBinding>  uniform_buffer_binding_indexed;
        bool                              validate_status;

        ProgramState(const uint32_t& in_n_max_indexed_uniform_buffer_bindings);
    } ProgramState;

    typedef struct RenderbufferState
    {
        uint32_t             height;
        VKGL::InternalFormat internal_format;
        uint32_t             samples;
        uint32_t             size_alpha;
        uint32_t             size_blue;
        uint32_t             size_depth;
        uint32_t             size_green;
        uint32_t             size_red;
        uint32_t             size_stencil;
        uint32_t             width;

        RenderbufferState();
    } RenderbufferState;

    typedef struct ShaderState
    {
        bool             compile_status;
        bool             delete_status;
        std::string      info_log;
        std::string      source_code;
        VKGL::ShaderType type;

        ShaderState();
    } ShaderState;

    typedef struct TextureImageState
    {
        uint32_t             binding_texture_buffer_data_store;
        uint32_t             compressed_image_size;
        bool                 fixed_sample_locations;
        uint32_t             depth;
        uint32_t             height;
        VKGL::InternalFormat internal_format;
        uint32_t             samples;
        uint32_t             width;

        explicit TextureImageState(const VKGL::InternalFormat& in_internal_format);
    } TextureImageState;

    typedef std::unique_ptr<TextureImageState> TextureImageStateUniquePtr;

    typedef struct TextureState
    {
        int32_t                      base_level;
        uint32_t                     border_color[4];
        VKGL::TextureCompareFunction compare_function;
        VKGL::TextureCompareMode     compare_mode;
        float                        lod_bias;
        VKGL::TextureMagFilter       mag_filter;
        int32_t                      max_level;
        float                        max_lod;
        VKGL::TextureMinFilter       min_filter;
        float                        min_lod;
        VKGL::TextureWrapMode        wrap_r;
        VKGL::TextureWrapMode        wrap_s;
        VKGL::TextureWrapMode        wrap_t;

        explicit TextureState(const VKGL::TextureMinFilter& in_min_filter,
                              const VKGL::TextureWrapMode&  in_wrap_s,
                              const VKGL::TextureWrapMode&  in_wrap_t,
                              const VKGL::TextureWrapMode&  in_wrap_r);
    } TextureState;

    typedef std::unique_ptr<TextureState> TextureStateUniquePtr;

    typedef struct TextureUnitState
    {
        GLuint binding_1d;
        GLuint binding_1d_array;
        GLuint binding_2d;
        GLuint binding_2d_array;
        GLuint binding_2d_multisample;
        GLuint binding_2d_multisample_array;
        GLuint binding_3d;
        GLuint binding_cube_map;
        GLuint binding_rectangle;
        GLuint binding_texture_buffer;

        TextureUnitState();
    } TextureUnitState;

    typedef std::unique_ptr<TextureUnitState> TextureUnitStateUniquePtr;

    typedef struct VertexArrayObjectState
    {
        uint32_t                               element_array_buffer_binding;
        std::vector<VertexAttributeArrayState> vertex_attribute_arrays;

        explicit VertexArrayObjectState(const uint32_t& in_n_vertex_attribute_arrays);
    } VertexArrayObjectState;

    typedef struct VertexAttributeArrayState
    {
        uint32_t                 buffer_binding;
        bool                     enabled;
        bool                     integer;
        bool                     normalized;
        void*                    pointer;
        uint64_t                 size;
        uint64_t                 stride;
        VertexAttributeArrayType type;

        VertexAttributeArrayState();
    } VertexAttributeArrayState;


    /* Rendering context state */
    typedef struct ContextState
    {
        bool    is_primitive_restart_enabled;
        int32_t primitive_restart_index;

        bool              is_depth_clamp_enabled;
        double            depth_range[2];
        std::vector<bool> user_clip_planes_enabled;
        int32_t           viewport   [4];

        VKGL::ClampReadColorMode        clamp_read_color;
        VKGL::ProvokingVertexConvention provoking_vertex;

        bool                         is_line_smooth_enabled;
        float                        line_width;
        float                        point_fade_threshold_size;
        float                        point_size;
        VKGL::PointSpriteCoordOrigin point_sprite_coord_origin;

        VKGL::CullMode             cull_face_mode;
        VKGL::FrontFaceOrientation front_face;
        bool                       is_cull_face_enabled;
        bool                       is_polygon_offset_fill_enabled;
        bool                       is_polygon_offset_line_enabled;
        bool                       is_polygon_offset_point_enabled;
        bool                       is_polygon_smooth_enabled;
        float                      polygon_offset_factor;
        float                      polygon_offset_units;

        bool     is_multisample_enabled;
        bool     is_sample_alpha_to_coverage_enabled;
        bool     is_sample_alpha_to_one_enabled;
        bool     is_sample_coverage_enabled;
        bool     is_sample_coverage_invert_enabled;
        bool     is_sample_mask_enabled;
        float    sample_coverage_value;
        uint32_t sample_mask;

        uint32_t                      active_texture_unit;
        std::vector<TextureUnitState> texture_image_units;

        bool                   is_scissor_test_enabled;
        bool                   is_stencil_test_enabled;
        int32_t                scissor_box[4];
        VKGL::StencilFunction  stencil_function_back;
        VKGL::StencilFunction  stencil_function_front;
        VKGL::StencilOperation stencil_op_fail_back;
        VKGL::StencilOperation stencil_op_fail_front;
        VKGL::StencilOperation stencil_op_pass_depth_fail_back;
        VKGL::StencilOperation stencil_op_pass_depth_fail_front;
        VKGL::StencilOperation stencil_op_pass_depth_pass_back;
        VKGL::StencilOperation stencil_op_pass_depth_pass_front;
        int32_t                stencil_reference_value_back;
        int32_t                stencil_reference_value_front;
        int32_t                stencil_value_mask_back;
        int32_t                stencil_value_mask_front;

        float               blend_color[4];
        VKGL::BlendEquation blend_equation_alpha;
        VKGL::BlendEquation blend_equation_rgb;
        VKGL::BlendFunction blend_func_dst_alpha;
        VKGL::BlendFunction blend_func_dst_rgb;
        VKGL::BlendFunction blend_func_src_alpha;
        VKGL::BlendFunction blend_func_src_rgb;
        VKGL::DepthFunction depth_function;
        uint32_t            is_blend_enabled_for_draw_buffers; /* n-th bit corresponds to n-th draw buffer */
        bool                is_color_logic_op_enabled;
        bool                is_depth_test_enabled;
        bool                is_dither_enabled;
        bool                is_framebuffer_srgb_enabled;
        VKGL::LogicOpMode   logic_op_mode;

        float    color_clear_value[4];
        uint32_t color_writemask_for_draw_buffers; /* 4-bits per each draw buffer. */
        double   depth_clear_value;
        bool     depth_writemask;
        uint32_t stencil_clear_value;
        uint32_t stencil_writemask_back;
        uint32_t stencil_writemask_front;

        uint32_t binding_draw_framebuffer;
        uint32_t binding_read_framebuffer;
        uint32_t binding_renderbuffer;

        uint32_t pack_alignment;
        uint32_t pack_image_height;
        bool     pack_lsb_first;
        uint32_t pack_row_length;
        uint32_t pack_skip_images;
        uint32_t pack_skip_pixels;
        uint32_t pack_skip_rows;
        bool     pack_swap_bytes;
        uint32_t unpack_alignment;
        uint32_t unpack_image_height;
        bool     unpack_lsb_first;
        uint32_t unpack_row_length;
        uint32_t unpack_skip_images;
        uint32_t unpack_skip_pixels;
        uint32_t unpack_skip_rows;
        bool     unpack_swap_bytes;

        GLuint current_program_id;

        VKGL::HintMode hint_fragment_shader_derivative;
        VKGL::HintMode hint_line_smooth;
        VKGL::HintMode hint_polygon_smooth;
        VKGL::HintMode hint_texture_compression;

        bool     is_texture_cube_map_seamless_enabled;

        GLuint active_any_samples_passed_query_id;
        GLuint active_primitives_generated_query_id;
        GLuint active_samples_passed_query_id;
        GLuint active_time_elapsed_query_id;
        GLuint active_timestamp_query_id;
        GLuint active_transform_feedback_primitives_written_query_id;

        bool        is_program_point_size_enabled;
        PolygonMode polygon_mode;

        explicit ContextState(const IGLLimits* in_limits_ptr,
                              const int32_t*   in_viewport_ivec4_ptr,
                              const int32_t*   in_scissor_box_ivec4_ptr);

    } ContextState;

    typedef std::unique_ptr<ContextState> ContextStateUniquePtr;
};

#endif /* VKGL_TYPES_STRUCTS_H */