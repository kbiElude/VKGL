/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/device.h"
#include "OpenGL/backend/thread_pool.h"
#include "OpenGL/backend/vk_spirv_manager.h"
#include "OpenGL/frontend/gl_limits.h"

OpenGL::VKSPIRVManager::GLSLData::GLSLData(const SPIRVBlobID&        in_id,
                                           const OpenGL::ShaderType& in_shader_type,
                                           const std::string&        in_glsl)
    :compilation_status(false),
     glsl              (in_glsl),
     id                (in_id),
     type              (in_shader_type)
{
    vkgl_assert(in_shader_type != OpenGL::ShaderType::Unknown);

    compile_task_fence_ptr.reset(new VKGL::Fence() );
    vkgl_assert(compile_task_fence_ptr != nullptr);
}

OpenGL::VKSPIRVManager::VKSPIRVManager(IBackend*                             in_backend_ptr,
                                       const OpenGL::IContextObjectManagers* in_frontend_ptr)
    :m_backend_ptr         (in_backend_ptr),
     m_frontend_ptr        (in_frontend_ptr),
     m_n_shaders_registered(0)
{
    vkgl_assert(in_backend_ptr != nullptr);

    glslang::InitializeProcess();
}

OpenGL::VKSPIRVManager::~VKSPIRVManager()
{
    glslang::FinalizeProcess();
}

void OpenGL::VKSPIRVManager::compile_shader(GLSLData* in_glsl_data_ptr)
{
    /* NOTE: This function is called back from one of the backend thread pool's threads */
    std::unique_ptr<glslang::TShader> glslang_shader_ptr;
    const char*                       glsl_code_ptr        = in_glsl_data_ptr->glsl.c_str();
    const auto                        glslang_shader_stage = (in_glsl_data_ptr->type == OpenGL::ShaderType::Fragment) ? EShLanguage::EShLangFragment
                                                           : (in_glsl_data_ptr->type == OpenGL::ShaderType::Geometry) ? EShLanguage::EShLangGeometry
                                                           : (in_glsl_data_ptr->type == OpenGL::ShaderType::Vertex)   ? EShLanguage::EShLangVertex
                                                                                                                      : EShLanguage::EShLangCount;

    vkgl_assert(glslang_shader_stage != EShLanguage::EShLangCount);

    glslang_shader_ptr.reset(new glslang::TShader(glslang_shader_stage) );
    vkgl_assert(glslang_shader_ptr != nullptr);

    glslang_shader_ptr->setStrings(&glsl_code_ptr,
                                   1); /* in_n */

    glslang_shader_ptr->setAutoMapBindings (true); /* NOTE: We're going to modify these later on by ourselves anyway */
    glslang_shader_ptr->setAutoMapLocations(true); /* NOTE: We're going to modify these later on by ourselves anyway */

    in_glsl_data_ptr->compilation_status = glslang_shader_ptr->parse(m_glslang_resources_ptr.get(),
                                                                     110,   /* defaultVersion    */
                                                                     false, /* forwardCompatible */
                                                                     static_cast<EShMessages>(EShMsgDefault | EShMsgSpvRules | EShMsgVulkanRules) );
    in_glsl_data_ptr->compilation_log    = glslang_shader_ptr->getInfoLog();

    if (in_glsl_data_ptr->compilation_status)
    {
        const auto            intermediate_ptr = glslang_shader_ptr->getIntermediate();
        std::vector<uint32_t> result_spirv_blob;

        glslang::GlslangToSpv(*intermediate_ptr,
                              result_spirv_blob);

        if (result_spirv_blob.size() == 0)
        {
            vkgl_assert_fail();
        }
        else
        {
            in_glsl_data_ptr->spirv_blob.resize(result_spirv_blob.size() * sizeof(uint32_t) );

            memcpy(&in_glsl_data_ptr->spirv_blob.at(0),
                   &result_spirv_blob.at(0),
                   in_glsl_data_ptr->spirv_blob.size() );
        }
    }

    in_glsl_data_ptr->glslang_shader_ptr = std::move(glslang_shader_ptr);

    in_glsl_data_ptr->compile_task_fence_ptr->signal();
}

OpenGL::VKSPIRVManagerUniquePtr OpenGL::VKSPIRVManager::create(IBackend*                             in_backend_ptr,
                                                               const OpenGL::IContextObjectManagers* in_frontend_ptr)
{
    OpenGL::VKSPIRVManagerUniquePtr result_ptr;

    result_ptr.reset(new VKSPIRVManager(in_backend_ptr,
                                        in_frontend_ptr) );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

bool OpenGL::VKSPIRVManager::get_spirv_blob_id_for_glsl(const char*          in_glsl_ptr,
                                                        OpenGL::SPIRVBlobID* out_result_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_glsl_to_glsl_data_map.find(std::string(in_glsl_ptr) );

        if (iterator != m_glsl_to_glsl_data_map.end() )
        {
            *out_result_ptr = iterator->second->id;
            result          = true;
        }
    }
    m_mutex.unlock_shared();

    return result;
}

bool OpenGL::VKSPIRVManager::get_shader_compilation_status(const SPIRVBlobID& in_spirv_blob_id,
                                                           bool*              out_status_ptr,
                                                           const char**       out_compilation_log_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_spirv_blob_id_to_glsl_data_map.find(in_spirv_blob_id);

        if (iterator != m_spirv_blob_id_to_glsl_data_map.end() )
        {
            vkgl_assert(iterator->second->compile_task_fence_ptr != nullptr);

            iterator->second->compile_task_fence_ptr->wait();

            result                   = true;
            *out_status_ptr          = iterator->second->compilation_status;
            *out_compilation_log_ptr = iterator->second->compilation_log.c_str();
        }
    }
    m_mutex.unlock_shared();

    return result;
}

bool OpenGL::VKSPIRVManager::get_spirv_blob(const SPIRVBlobID& in_spirv_blob_id,
                                            const uint8_t**    out_spirv_blob_ptr,
                                            uint32_t*          out_spirv_blob_size_bytes_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_spirv_blob_id_to_glsl_data_map.find(in_spirv_blob_id);

        if (iterator != m_spirv_blob_id_to_glsl_data_map.end() )
        {
            vkgl_assert(iterator->second->compile_task_fence_ptr != nullptr);

            iterator->second->compile_task_fence_ptr->wait();

            vkgl_assert(iterator->second->spirv_blob.size() > 0);
            if (iterator->second->spirv_blob.size() > 0)
            {
                result                         = true;
                *out_spirv_blob_ptr            = &iterator->second->spirv_blob.at(0);
                *out_spirv_blob_size_bytes_ptr = static_cast<uint32_t>(iterator->second->spirv_blob.size() );
            }
        }
    }
    m_mutex.unlock_shared();

    return result;
}

bool OpenGL::VKSPIRVManager::init()
{
    bool result = false;

    result = init_glslang_resources();
    if (!result)
    {
        vkgl_assert(result);

        goto end;
    }

end:
    return result;
}

bool OpenGL::VKSPIRVManager::init_glslang_resources()
{
    auto device_ptr          = m_backend_ptr->get_device_ptr ();
    auto frontend_limits_ptr = m_frontend_ptr->get_limits_ptr();
    bool result              = false;

    m_glslang_resources_ptr.reset(new TBuiltInResource() );

    vkgl_assert(m_glslang_resources_ptr != nullptr);
    if (m_glslang_resources_ptr == nullptr)
    {
        goto end;
    }

    m_glslang_resources_ptr->maxLights                                   = 0; /* pre-core profile stuff */
    m_glslang_resources_ptr->maxClipPlanes                               = frontend_limits_ptr->get_max_clip_distances();
    m_glslang_resources_ptr->maxTextureUnits                             = 0; /* pre-core profile stuff */
    m_glslang_resources_ptr->maxTextureCoords                            = 0; /* pre-core profile stuff */
    m_glslang_resources_ptr->maxVertexAttribs                            = frontend_limits_ptr->get_max_vertex_attribs                ();
    m_glslang_resources_ptr->maxVertexUniformComponents                  = frontend_limits_ptr->get_max_vertex_uniform_components     ();
    m_glslang_resources_ptr->maxVaryingFloats                            = frontend_limits_ptr->get_max_varying_components            ();
    m_glslang_resources_ptr->maxVertexTextureImageUnits                  = frontend_limits_ptr->get_max_vertex_texture_image_units    ();
    m_glslang_resources_ptr->maxCombinedTextureImageUnits                = frontend_limits_ptr->get_max_combined_texture_image_units  ();
    m_glslang_resources_ptr->maxTextureImageUnits                        = frontend_limits_ptr->get_max_texture_image_units           ();
    m_glslang_resources_ptr->maxFragmentUniformComponents                = frontend_limits_ptr->get_max_fragment_uniform_components   ();
    m_glslang_resources_ptr->maxDrawBuffers                              = frontend_limits_ptr->get_max_draw_buffers                  ();
    m_glslang_resources_ptr->maxVertexUniformVectors                     = frontend_limits_ptr->get_max_vertex_uniform_components     () / 4; /* magic number as per spec */
    m_glslang_resources_ptr->maxVaryingVectors                           = frontend_limits_ptr->get_max_varying_components            () / 4; /* magic number as per spec */
    m_glslang_resources_ptr->maxFragmentUniformVectors                   = frontend_limits_ptr->get_max_fragment_uniform_components   () / 4; /* magic number as per spec */
    m_glslang_resources_ptr->maxVertexOutputVectors                      = frontend_limits_ptr->get_max_vertex_output_components      () / 4; /* magic number as per spec */
    m_glslang_resources_ptr->maxFragmentInputVectors                     = frontend_limits_ptr->get_max_fragment_input_components     () / 4; /* magic number as per spec */
    m_glslang_resources_ptr->minProgramTexelOffset                       = frontend_limits_ptr->get_min_program_texel_offset          ();
    m_glslang_resources_ptr->maxProgramTexelOffset                       = frontend_limits_ptr->get_max_program_texel_offset          ();
    m_glslang_resources_ptr->maxClipDistances                            = frontend_limits_ptr->get_max_clip_distances                ();
    m_glslang_resources_ptr->maxComputeWorkGroupCountX                   = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_work_group_count      ()[0]; */
    m_glslang_resources_ptr->maxComputeWorkGroupCountY                   = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_work_group_count      ()[1]; */
    m_glslang_resources_ptr->maxComputeWorkGroupCountZ                   = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_work_group_count      ()[2]; */
    m_glslang_resources_ptr->maxComputeWorkGroupSizeX                    = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_work_group_size       ()[0]; */
    m_glslang_resources_ptr->maxComputeWorkGroupSizeY                    = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_work_group_size       ()[1]; */
    m_glslang_resources_ptr->maxComputeWorkGroupSizeZ                    = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_work_group_size       ()[2]; */
    m_glslang_resources_ptr->maxComputeUniformComponents                 = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_uniform_components    ();    */
    m_glslang_resources_ptr->maxComputeTextureImageUnits                 = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_texture_image_units   ();    */
    m_glslang_resources_ptr->maxComputeImageUniforms                     = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_image_uniforms        ();    */
    m_glslang_resources_ptr->maxComputeAtomicCounters                    = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_atomic_counters       ();    */
    m_glslang_resources_ptr->maxComputeAtomicCounterBuffers              = 0; /* No support for compute shaders in GL 3.2: frontend_limits_ptr->get_max_compute_atomic_counter_buffers();    */
    m_glslang_resources_ptr->maxVaryingComponents                        = frontend_limits_ptr->get_max_varying_components            ();
    m_glslang_resources_ptr->maxVertexOutputComponents                   = frontend_limits_ptr->get_max_vertex_output_components      ();
    m_glslang_resources_ptr->maxGeometryInputComponents                  = frontend_limits_ptr->get_max_geometry_input_components     ();
    m_glslang_resources_ptr->maxGeometryOutputComponents                 = frontend_limits_ptr->get_max_geometry_output_components    ();
    m_glslang_resources_ptr->maxFragmentInputComponents                  = frontend_limits_ptr->get_max_fragment_input_components     ();
    m_glslang_resources_ptr->maxImageUnits                               = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_image_units                              (); */
    m_glslang_resources_ptr->maxCombinedImageUnitsAndFragmentOutputs     = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_combined_image_units_and_fragment_outputs(); */
    m_glslang_resources_ptr->maxCombinedShaderOutputResources            = /* No support for SSBOs in GL 3.2:  frontend_limits_ptr->get_max_combined_shader_storage_blocks() + */
                                                                           /* No support for images in GL 3.2: frontend_limits_ptr->get_max_combined_image_uniforms       () + */
                                                                           frontend_limits_ptr->get_max_draw_buffers();
    m_glslang_resources_ptr->maxImageSamples                             = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_image_samples                 (); */
    m_glslang_resources_ptr->maxVertexImageUniforms                      = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_vertex_image_uniforms         (); */
    m_glslang_resources_ptr->maxTessControlImageUniforms                 = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_tess_control_image_uniforms   (); */
    m_glslang_resources_ptr->maxTessEvaluationImageUniforms              = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_image_uniforms(); */
    m_glslang_resources_ptr->maxGeometryImageUniforms                    = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_geometry_image_uniforms       (); */
    m_glslang_resources_ptr->maxFragmentImageUniforms                    = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_fragment_image_uniforms       (); */
    m_glslang_resources_ptr->maxCombinedImageUniforms                    = 0; /* No support for images in GL 3.2: frontend_limits_ptr->get_max_combined_image_uniforms       (); */
    m_glslang_resources_ptr->maxGeometryTextureImageUnits                = frontend_limits_ptr->get_max_geometry_texture_image_units    ();
    m_glslang_resources_ptr->maxGeometryOutputVertices                   = frontend_limits_ptr->get_max_geometry_output_vertices        ();
    m_glslang_resources_ptr->maxGeometryTotalOutputComponents            = frontend_limits_ptr->get_max_geometry_total_output_components();
    m_glslang_resources_ptr->maxGeometryUniformComponents                = frontend_limits_ptr->get_max_geometry_uniform_components     ();
    m_glslang_resources_ptr->maxGeometryVaryingComponents                = 0; /* ES stuff? */
    m_glslang_resources_ptr->maxTessControlInputComponents               = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_control_input_components       (); */
    m_glslang_resources_ptr->maxTessControlOutputComponents              = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_control_output_components      (); */
    m_glslang_resources_ptr->maxTessControlTextureImageUnits             = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_control_texture_image_units    (); */
    m_glslang_resources_ptr->maxTessControlUniformComponents             = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_control_uniform_components     (); */
    m_glslang_resources_ptr->maxTessControlTotalOutputComponents         = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_control_total_output_components(); */
    m_glslang_resources_ptr->maxTessEvaluationInputComponents            = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_input_components    (); */
    m_glslang_resources_ptr->maxTessEvaluationOutputComponents           = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_output_components   (); */
    m_glslang_resources_ptr->maxTessEvaluationTextureImageUnits          = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_texture_image_units (); */
    m_glslang_resources_ptr->maxTessEvaluationUniformComponents          = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_uniform_components  (); */
    m_glslang_resources_ptr->maxTessPatchComponents                      = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_patch_components               (); */
    m_glslang_resources_ptr->maxPatchVertices                            = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_patch_vertices                      (); */
    m_glslang_resources_ptr->maxTessGenLevel                             = 0; /* No support for tess shaders in GL 3.2: frontend_limits_ptr->get_max_tess_gen_level                      (); */
    m_glslang_resources_ptr->maxViewports                                = 1; /* No support for multiple viewports in GL 3.2 */
    m_glslang_resources_ptr->maxVertexAtomicCounters                     = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_vertex_atomic_counters                (); */
    m_glslang_resources_ptr->maxTessControlAtomicCounters                = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_tess_control_atomic_counters          (); */
    m_glslang_resources_ptr->maxTessEvaluationAtomicCounters             = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_atomic_counters       (); */
    m_glslang_resources_ptr->maxGeometryAtomicCounters                   = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_geometry_atomic_counters              (); */
    m_glslang_resources_ptr->maxFragmentAtomicCounters                   = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_fragment_atomic_counters              (); */
    m_glslang_resources_ptr->maxCombinedAtomicCounters                   = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_combined_atomic_counters              (); */
    m_glslang_resources_ptr->maxAtomicCounterBindings                    = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_atomic_counter_bindings               (); */
    m_glslang_resources_ptr->maxVertexAtomicCounterBuffers               = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_vertex_atomic_counter_buffers         (); */
    m_glslang_resources_ptr->maxTessControlAtomicCounterBuffers          = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_tess_control_atomic_counter_buffers   (); */
    m_glslang_resources_ptr->maxTessEvaluationAtomicCounterBuffers       = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_tess_evaluation_atomic_counter_buffers(); */
    m_glslang_resources_ptr->maxGeometryAtomicCounterBuffers             = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_geometry_atomic_counter_buffers       (); */
    m_glslang_resources_ptr->maxFragmentAtomicCounterBuffers             = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_fragment_atomic_counter_buffers       (); */
    m_glslang_resources_ptr->maxCombinedAtomicCounterBuffers             = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_combined_atomic_counter_buffers       (); */
    m_glslang_resources_ptr->maxAtomicCounterBufferSize                  = 0; /* No support for atomic counters in GL 3.2: frontend_limits_ptr->get_max_atomic_counter_buffer_size            (); */
    m_glslang_resources_ptr->maxTransformFeedbackBuffers                 = frontend_limits_ptr->get_max_transform_feedback_buffers               ();
    m_glslang_resources_ptr->maxTransformFeedbackInterleavedComponents   = frontend_limits_ptr->get_max_transform_feedback_interleaved_components();
    m_glslang_resources_ptr->maxCullDistances                            = 0; /* No support for ARB_cull_distance in GL3.2: frontend_limits_ptr->get_max_cull_distances                  (); */
    m_glslang_resources_ptr->maxCombinedClipAndCullDistances             = 0; /* No support for ARB_cull_distance in GL3.2: frontend_limits_ptr->get_max_combined_clip_and_cull_distances(); */
    m_glslang_resources_ptr->maxSamples                                  = frontend_limits_ptr->get_max_samples();
    m_glslang_resources_ptr->limits.nonInductiveForLoops                 = true;
    m_glslang_resources_ptr->limits.whileLoops                           = true;
    m_glslang_resources_ptr->limits.doWhileLoops                         = true;
    m_glslang_resources_ptr->limits.generalUniformIndexing               = true;
    m_glslang_resources_ptr->limits.generalAttributeMatrixVectorIndexing = true;
    m_glslang_resources_ptr->limits.generalVaryingIndexing               = true;
    m_glslang_resources_ptr->limits.generalSamplerIndexing               = (device_ptr->get_extension_info()->ext_descriptor_indexing() );
    m_glslang_resources_ptr->limits.generalVariableIndexing              = true;
    m_glslang_resources_ptr->limits.generalConstantMatrixVectorIndexing  = true;

    result = true;
end:
    return result;
}

OpenGL::SPIRVBlobID OpenGL::VKSPIRVManager::register_shader(const OpenGL::ShaderType& in_shader_type,
                                                            const char*               in_glsl)
{
    OpenGL::SPIRVBlobID result          = UINT32_MAX;
    auto                thread_pool_ptr = m_backend_ptr->get_thread_pool_ptr();

    m_mutex.lock_unique();
    {
        GLSLData* glsl_data_raw_ptr = nullptr;

        vkgl_assert(m_glsl_to_glsl_data_map.find(in_glsl) == m_glsl_to_glsl_data_map.end() );

        /* 1. Spawn a new entity to hold shader data */
        {
            GLSLDataUniquePtr glsl_data_ptr;
            SPIRVBlobID       new_blob_id    = static_cast<SPIRVBlobID>(++m_n_shaders_registered);

            vkgl_assert(m_spirv_blob_id_to_glsl_data_map.find(new_blob_id) == m_spirv_blob_id_to_glsl_data_map.end() );

            glsl_data_ptr.reset(new GLSLData(new_blob_id,
                                             in_shader_type,
                                             in_glsl)
            );
            vkgl_assert(glsl_data_ptr != nullptr);

            glsl_data_raw_ptr                             = glsl_data_ptr.get();
            m_spirv_blob_id_to_glsl_data_map[new_blob_id] = glsl_data_raw_ptr;
            m_glsl_to_glsl_data_map         [in_glsl]     = std::move(glsl_data_ptr);
        }

        /* 2. Submit a new task to the thread pool, which we're going to use to actually perform the GLSL->SPIRV "conversion". */
        thread_pool_ptr->submit_task(std::bind(&OpenGL::VKSPIRVManager::compile_shader,
                                               this,
                                               glsl_data_raw_ptr)
        );
    }
    m_mutex.unlock_unique();

    return result;
}

