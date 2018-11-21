/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Anvil/include/wrappers/device.h"
#include "Anvil/include/wrappers/shader_module.h"
#include "Anvil/deps/glslang/glslang/MachineIndependent/localintermediate.h"
#include "OpenGL/backend/thread_pool.h"
#include "OpenGL/backend/vk_spirv_manager.h"
#include "OpenGL/frontend/gl_limits.h"
#include "OpenGL/frontend/gl_program_manager.h"
#include "OpenGL/frontend/gl_shader_manager.h"
#include "OpenGL/utils_enum.h"

OpenGL::VKSPIRVManager::ProgramData::ProgramData(const SPIRVBlobID&                  in_id,
                                                 const std::vector<ShaderData*>&     in_shader_ptrs,
                                                 OpenGL::GLProgramReferenceUniquePtr in_program_reference_ptr)
    :id                   (in_id),
     link_status          (false),
     program_reference_ptr(std::move(in_program_reference_ptr) ),
     shader_ptrs          (in_shader_ptrs)
{
    link_task_fence_ptr.reset(new VKGL::Fence() );
    vkgl_assert(link_task_fence_ptr != nullptr);

    program_id = program_reference_ptr->get_payload().id;
}

OpenGL::VKSPIRVManager::ShaderData::ShaderData(const SPIRVBlobID&        in_id,
                                               const OpenGL::ShaderType& in_shader_type,
                                               const std::string&        in_glsl)
    :compilation_status(false),
     glsl              (in_glsl),
     id                (in_id),
     sm_entrypoint_name(nullptr),
     type              (in_shader_type)
{
    vkgl_assert(in_shader_type != OpenGL::ShaderType::Unknown);

    compile_task_fence_ptr.reset(new VKGL::Fence() );
    vkgl_assert(compile_task_fence_ptr != nullptr);
}

OpenGL::VKSPIRVManager::VKSPIRVManager(IBackend*                             in_backend_ptr,
                                       const OpenGL::IContextObjectManagers* in_frontend_ptr)
    :m_backend_ptr          (in_backend_ptr),
     m_frontend_ptr         (in_frontend_ptr),
     m_n_entities_registered(0)
{
    vkgl_assert(in_backend_ptr != nullptr);

    glslang::InitializeProcess();
}

OpenGL::VKSPIRVManager::~VKSPIRVManager()
{
    glslang::FinalizeProcess();
}

void OpenGL::VKSPIRVManager::compile_shader(ShaderData* in_shader_data_ptr)
{
    /* NOTE: This function is called back from one of the backend thread pool's threads */
    const char*                       glsl_code_ptr        = in_shader_data_ptr->glsl.c_str();
    std::unique_ptr<glslang::TShader> glslang_shader_ptr;
    const auto                        glslang_shader_stage = OpenGL::Utils::get_sh_language_for_opengl_shader_type(in_shader_data_ptr->type);
    const char*                       sm_entrypoint_name   = (in_shader_data_ptr->type == OpenGL::ShaderType::Fragment) ? "main_fs"
                                                           : (in_shader_data_ptr->type == OpenGL::ShaderType::Geometry) ? "main_gs"
                                                                                                                        : "main_vs";

    vkgl_assert(in_shader_data_ptr->type == OpenGL::ShaderType::Fragment ||
                in_shader_data_ptr->type == OpenGL::ShaderType::Geometry ||
                in_shader_data_ptr->type == OpenGL::ShaderType::Vertex);
    vkgl_assert(glslang_shader_stage     != EShLanguage::EShLangCount);

    glslang_shader_ptr.reset(new glslang::TShader(glslang_shader_stage) );
    vkgl_assert(glslang_shader_ptr != nullptr);

    glslang_shader_ptr->setStrings(&glsl_code_ptr,
                                   1); /* in_n */

    glslang_shader_ptr->setAutoMapBindings (true); /* TODO: Need to use app-specified data here */
    glslang_shader_ptr->setAutoMapLocations(true); /* TODO: Need to use app-specified data here */
    glslang_shader_ptr->setEntryPoint      (sm_entrypoint_name);

    in_shader_data_ptr->compilation_status = glslang_shader_ptr->parse(m_glslang_resources_ptr.get(),
                                                                       110,   /* defaultVersion    */
                                                                       false, /* forwardCompatible */
                                                                       static_cast<EShMessages>(EShMsgDefault | EShMsgSpvRules | EShMsgVulkanRules) );
    in_shader_data_ptr->compilation_log    = glslang_shader_ptr->getInfoLog();

    if (in_shader_data_ptr->compilation_status)
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
            in_shader_data_ptr->spirv_blob.resize(result_spirv_blob.size() * sizeof(uint32_t) );

            memcpy(&in_shader_data_ptr->spirv_blob.at(0),
                   &result_spirv_blob.at(0),
                    in_shader_data_ptr->spirv_blob.size() );
        }
    }

    in_shader_data_ptr->glslang_shader_ptr = std::move(glslang_shader_ptr);
    in_shader_data_ptr->sm_entrypoint_name = sm_entrypoint_name;

    in_shader_data_ptr->compile_task_fence_ptr->signal();
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

OpenGL::PostLinkDataUniquePtr OpenGL::VKSPIRVManager::create_post_link_data(const glslang::TProgram* in_program_data_ptr) const
{
    const auto                    n_live_attributes = in_program_data_ptr->getNumLiveAttributes      ();
    const auto                    n_live_ubs        = in_program_data_ptr->getNumLiveUniformBlocks   ();
    const auto                    n_live_uniforms   = in_program_data_ptr->getNumLiveUniformVariables();
    OpenGL::PostLinkDataUniquePtr result_ptr;

    result_ptr.reset(new OpenGL::PostLinkData() );
    vkgl_assert(result_ptr != nullptr);

    /* Miscellaneous stuff */
    {
        auto gs_intermediate_ptr = in_program_data_ptr->getIntermediate(EShLanguage::EShLangGeometry);

        if (gs_intermediate_ptr != nullptr)
        {
            result_ptr->gs_input_type               = get_geometry_input_type_for_layout_geometry (gs_intermediate_ptr->getInputPrimitive () );
            result_ptr->gs_output_type              = get_geometry_output_type_for_layout_geometry(gs_intermediate_ptr->getOutputPrimitive() );
            result_ptr->n_max_gs_vertices_generated = gs_intermediate_ptr->getVertices            ();
        }
    }

    /* Active attribs */
    result_ptr->active_attributes.reserve(n_live_attributes);
    result_ptr->active_attributes.clear  ();

    result_ptr->active_attribute_max_length = 0;
    result_ptr->active_attribute_name_to_location_map.clear();

    for (auto  n_live_attribute = 0;
               n_live_attribute < n_live_attributes;
             ++n_live_attribute)
    {
        const auto                        live_attribute_name_ptr = in_program_data_ptr->getAttributeName (n_live_attribute);
        const auto                        live_attribute_type_ptr = in_program_data_ptr->getAttributeTType(n_live_attribute);
        OpenGL::ActiveAttributeProperties live_attribute_props;

        live_attribute_props.location = live_attribute_type_ptr->getQualifier().layoutLocation;
        live_attribute_props.name     = live_attribute_name_ptr;
        live_attribute_props.size     = (live_attribute_type_ptr->getArraySizes() != nullptr) ? live_attribute_type_ptr->getOuterArraySize()
                                                                                              : 1;
        live_attribute_props.type     = get_variable_type_for_glslang_type(*live_attribute_type_ptr);

        result_ptr->active_attribute_max_length = std::max(result_ptr->active_attribute_max_length,
                                                           live_attribute_props.name.length() + 1);

        vkgl_assert(result_ptr->active_attribute_name_to_location_map.find(live_attribute_props.name) == result_ptr->active_attribute_name_to_location_map.end() );
        result_ptr->active_attribute_name_to_location_map[live_attribute_props.name] = live_attribute_props.location;

        result_ptr->active_attributes.push_back(live_attribute_props);
    }

    /* Unsupported stuff: */
    vkgl_assert(n_live_ubs      == 0); /* TODO */
    vkgl_assert(n_live_uniforms == 0); /* TODO */

    return result_ptr;
}

OpenGL::GeometryInputType OpenGL::VKSPIRVManager::get_geometry_input_type_for_layout_geometry(const glslang::TLayoutGeometry& in_layout_geometry) const
{
    OpenGL::GeometryInputType result = OpenGL::GeometryInputType::Unknown;

    switch (in_layout_geometry)
    {
        case glslang::TLayoutGeometry::ElgNone:                                                                        break;
        case glslang::TLayoutGeometry::ElgLines:              result = OpenGL::GeometryInputType::Lines;               break;
        case glslang::TLayoutGeometry::ElgLinesAdjacency:     result = OpenGL::GeometryInputType::Lines_Adjacency;     break;
        case glslang::TLayoutGeometry::ElgPoints:             result = OpenGL::GeometryInputType::Points;              break;
        case glslang::TLayoutGeometry::ElgTriangles:          result = OpenGL::GeometryInputType::Triangles;           break;
        case glslang::TLayoutGeometry::ElgTrianglesAdjacency: result = OpenGL::GeometryInputType::Triangles_Adjacency; break;

        case glslang::TLayoutGeometry::ElgIsolines:
        case glslang::TLayoutGeometry::ElgLineStrip:
        case glslang::TLayoutGeometry::ElgQuads:
        case glslang::TLayoutGeometry::ElgTriangleStrip:
        {
            /* ?! */
            vkgl_assert_fail();

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

OpenGL::GeometryOutputType OpenGL::VKSPIRVManager::get_geometry_output_type_for_layout_geometry(const glslang::TLayoutGeometry& in_layout_geometry) const
{
    OpenGL::GeometryOutputType result = OpenGL::GeometryOutputType::Unknown;

    switch (in_layout_geometry)
    {
        case glslang::TLayoutGeometry::ElgNone:                                                               break;
        case glslang::TLayoutGeometry::ElgLineStrip:     result = OpenGL::GeometryOutputType::Line_Strip;     break;
        case glslang::TLayoutGeometry::ElgPoints:        result = OpenGL::GeometryOutputType::Points;         break;
        case glslang::TLayoutGeometry::ElgTriangleStrip: result = OpenGL::GeometryOutputType::Triangle_Strip; break;

        case glslang::TLayoutGeometry::ElgIsolines:
        case glslang::TLayoutGeometry::ElgLines:
        case glslang::TLayoutGeometry::ElgLinesAdjacency:
        case glslang::TLayoutGeometry::ElgQuads:
        case glslang::TLayoutGeometry::ElgTriangles:
        case glslang::TLayoutGeometry::ElgTrianglesAdjacency:
        {
            /* ?! */
            vkgl_assert_fail();

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

    return result;
}

bool OpenGL::VKSPIRVManager::get_program_link_status(const SPIRVBlobID& in_spirv_blob_id,
                                                     bool*              out_status_ptr,
                                                     const char**       out_link_log_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_spirv_blob_id_to_program_data_map.find(in_spirv_blob_id);

        if (iterator != m_spirv_blob_id_to_program_data_map.end() )
        {
            vkgl_assert(iterator->second->link_task_fence_ptr != nullptr);

            iterator->second->link_task_fence_ptr->wait();

            result            = true;
            *out_status_ptr   = iterator->second->link_status;
            *out_link_log_ptr = iterator->second->link_log.c_str();
        }
    }
    m_mutex.unlock_shared();

    return result;
}

bool OpenGL::VKSPIRVManager::get_spirv_blob_id_for_glsl(const char*          in_glsl_ptr,
                                                        OpenGL::SPIRVBlobID* out_result_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_glsl_to_shader_data_map.find(std::string(in_glsl_ptr) );

        if (iterator != m_glsl_to_shader_data_map.end() )
        {
            *out_result_ptr = iterator->second->id;
            result          = true;
        }
    }
    m_mutex.unlock_shared();

    return result;
}

bool OpenGL::VKSPIRVManager::get_spirv_blob_id_for_program_reference(const GLuint&             in_program_id,
                                                                     const OpenGL::TimeMarker& in_time_marker,
                                                                     OpenGL::SPIRVBlobID*      out_result_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_program_reference_to_program_data_map.find(std::pair<GLuint, OpenGL::TimeMarker>(in_program_id, in_time_marker) );

        if (iterator != m_program_reference_to_program_data_map.end() )
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
        auto iterator = m_spirv_blob_id_to_shader_data_map.find(in_spirv_blob_id);

        if (iterator != m_spirv_blob_id_to_shader_data_map.end() )
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

bool OpenGL::VKSPIRVManager::get_shader_module_ptr(const SPIRVBlobID&        in_spirv_blob_id,
                                                   const OpenGL::ShaderType& in_shader_type,
                                                   Anvil::ShaderModule**     out_result_ptr_ptr) const
{
    bool result = false;

    m_mutex.lock_shared();
    {
        auto iterator = m_spirv_blob_id_to_program_data_map.find(in_spirv_blob_id);

        if (iterator != m_spirv_blob_id_to_program_data_map.end() )
        {
            vkgl_assert(iterator->second->link_task_fence_ptr != nullptr);

            iterator->second->link_task_fence_ptr->wait();

            result              = true;
            *out_result_ptr_ptr = iterator->second->shader_module_ptrs[static_cast<uint32_t>(in_shader_type)].get();

            vkgl_assert(*out_result_ptr_ptr != nullptr);
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
        auto iterator = m_spirv_blob_id_to_shader_data_map.find(in_spirv_blob_id);

        if (iterator != m_spirv_blob_id_to_shader_data_map.end() )
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

OpenGL::VariableType OpenGL::VKSPIRVManager::get_variable_type_for_glslang_type(const glslang::TType& in_type) const
{
    OpenGL::VariableType result = OpenGL::VariableType::Unknown;

    switch (in_type.getBasicType() )
    {
        case glslang::TBasicType::EbtAtomicUint:
        case glslang::TBasicType::EbtDouble:
        case glslang::TBasicType::EbtFloat16:
        case glslang::TBasicType::EbtInt8:
        case glslang::TBasicType::EbtInt16:
        case glslang::TBasicType::EbtInt64:
        case glslang::TBasicType::EbtUint8:
        case glslang::TBasicType::EbtUint16:
        case glslang::TBasicType::EbtUint64:
        case glslang::TBasicType::EbtVoid:
        {
            /* Computer says no */
            vkgl_assert_fail();

            break;
        }

        case glslang::TBasicType::EbtBool:
        {
            switch (in_type.getVectorSize() )
            {
                case 1: result = OpenGL::VariableType::Bool;  break;
                case 2: result = OpenGL::VariableType::Bvec2; break;
                case 3: result = OpenGL::VariableType::Bvec3; break;
                case 4: result = OpenGL::VariableType::Bvec4; break;

                default:
                {
                    vkgl_assert_fail();
                }
            }

            break;
        }

        case glslang::TBasicType::EbtFloat:
        {
            switch (in_type.getVectorSize() )
            {
                case 1: result = OpenGL::VariableType::Float; break;
                case 2: result = OpenGL::VariableType::Vec2;  break;
                case 3: result = OpenGL::VariableType::Vec3;  break;
                case 4: result = OpenGL::VariableType::Vec4;  break;

                default:
                {
                    vkgl_assert_fail();
                }
            }

            break;
        }

        case glslang::TBasicType::EbtInt:
        {
            switch (in_type.getVectorSize() )
            {
                case 1: result = OpenGL::VariableType::Int;  break;
                case 2: result = OpenGL::VariableType::Ivec2; break;
                case 3: result = OpenGL::VariableType::Ivec3; break;
                case 4: result = OpenGL::VariableType::Ivec4; break;

                default:
                {
                    vkgl_assert_fail();
                }
            }

            break;
        }

        case glslang::TBasicType::EbtSampler:
        {
            /* TODO */
            vkgl_not_implemented();

            break;
        }

        case glslang::TBasicType::EbtUint:
        {
            switch (in_type.getVectorSize() )
            {
                case 1: result = OpenGL::VariableType::Uint;  break;
                case 2: result = OpenGL::VariableType::Uvec2; break;
                case 3: result = OpenGL::VariableType::Uvec3; break;
                case 4: result = OpenGL::VariableType::Uvec4; break;

                default:
                {
                    vkgl_assert_fail();
                }
            }

            break;
        }

        case glslang::TBasicType::EbtBlock:
        case glslang::TBasicType::EbtStruct:
        {
            /* todo */
            vkgl_not_implemented();

            break;
        }

        default:
        {
            vkgl_assert_fail();
        }
    }

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

void OpenGL::VKSPIRVManager::link_program(ProgramData* in_program_data_ptr)
{
    /* NOTE: This function is called back from one of the backend thread pool's threads */
    auto                               frontend_program_manager_ptr = m_frontend_ptr->get_program_manager_ptr();
    std::unique_ptr<glslang::TProgram> glslang_program_ptr;
    const auto                         program_id                   = in_program_data_ptr->program_reference_ptr->get_payload().id;
    const auto                         program_time_marker          = in_program_data_ptr->program_reference_ptr->get_payload().time_marker;

    glslang_program_ptr.reset(new glslang::TProgram() );
    vkgl_assert(glslang_program_ptr!= nullptr);

    for (const auto& current_shader_data_ptr : in_program_data_ptr->shader_ptrs)
    {
        glslang_program_ptr->addShader(current_shader_data_ptr->glslang_shader_ptr.get() );
    }

    /* NOTE: We do not support predefined bindings & locations specified via GL API calls just yet. */
    {
        const OpenGL::AttributeLocationBindingMap*    attribute_location_bindings_ptr  = nullptr;
        const OpenGL::FragDataLocationMap*            frag_data_location_mappings_ptr  = nullptr;
        const std::unordered_map<uint32_t, uint32_t>* ub_index_to_binding_mappings_ptr = nullptr;

        if (!frontend_program_manager_ptr->get_program_link_time_properties(program_id,
                                                                           &program_time_marker,
                                                                           &attribute_location_bindings_ptr,
                                                                           &frag_data_location_mappings_ptr,
                                                                           &ub_index_to_binding_mappings_ptr) )
        {
            vkgl_assert_fail();
        }

        vkgl_assert(attribute_location_bindings_ptr->size () == 0); /* TODO */
        vkgl_assert(frag_data_location_mappings_ptr->size () == 0); /* TODO */
        vkgl_assert(ub_index_to_binding_mappings_ptr->size() == 0); /* TODO */
    }

    /* Link the program and cache result SPIR-V blobs.. */
    in_program_data_ptr->link_status = glslang_program_ptr->link      (EShMsgDefault);
    in_program_data_ptr->link_log    = glslang_program_ptr->getInfoLog();

    if (!glslang_program_ptr->buildReflection() )
    {
        vkgl_assert_fail();
    }

    if (in_program_data_ptr->link_status)
    {
        for (const auto& current_shader_data_ptr : in_program_data_ptr->shader_ptrs)
        {
            const auto            shader_type           = current_shader_data_ptr->type;
            const auto            intermediate_ptr      = glslang_program_ptr->getIntermediate(OpenGL::Utils::get_sh_language_for_opengl_shader_type(shader_type) );
            std::vector<uint8_t>& result_spirv_blob_u8  = in_program_data_ptr->spirv_blobs[static_cast<uint32_t>(shader_type)];
            std::vector<uint32_t> result_spirv_blob_u32;

            glslang::GlslangToSpv(*intermediate_ptr,
                                  result_spirv_blob_u32);

            if (result_spirv_blob_u32.size() == 0)
            {
                vkgl_assert_fail();
            }
            else
            {
                result_spirv_blob_u8.resize(result_spirv_blob_u32.size() * sizeof(uint32_t) );

                memcpy(&result_spirv_blob_u8.at(0),
                       &result_spirv_blob_u32.at(0),
                        result_spirv_blob_u8.size() );
            }

            vkgl_assert(shader_type == ShaderType::Fragment ||
                        shader_type == ShaderType::Geometry ||
                        shader_type == ShaderType::Vertex);

            in_program_data_ptr->shader_module_ptrs[static_cast<uint32_t>(current_shader_data_ptr->type)] = Anvil::ShaderModule::create_from_spirv_blob(m_backend_ptr->get_device_ptr(),
                                                                                                                                                       &result_spirv_blob_u32.at(0),
                                                                                                                                                        static_cast<uint32_t>(result_spirv_blob_u32.size() ),
                                                                                                                                                        "",  /* in_opt_cs_entrypoint_name */
                                                                                                                                                        (shader_type == ShaderType::Fragment) ? current_shader_data_ptr->sm_entrypoint_name : "",
                                                                                                                                                        (shader_type == ShaderType::Geometry) ? current_shader_data_ptr->sm_entrypoint_name : "",
                                                                                                                                                        "",  /* in_opt_tc_entrypoint_name */
                                                                                                                                                        "",  /* in_opt_te_entrypoint_name */
                                                                                                                                                        (shader_type == ShaderType::Vertex) ? current_shader_data_ptr->sm_entrypoint_name : "");
            vkgl_assert(in_program_data_ptr->shader_module_ptrs[static_cast<uint32_t>(current_shader_data_ptr->type)] != nullptr);
        }
    }

    /* Create, fill and associate post-link data struct with the GL program */
    {
        auto post_link_data_ptr = create_post_link_data(glslang_program_ptr.get() );
        vkgl_assert(post_link_data_ptr != nullptr);

        frontend_program_manager_ptr->set_program_post_link_data_ptr(program_id,
                                                                    &program_time_marker,
                                                                     std::move(post_link_data_ptr) );
    }

    /* All done, signal the fence we're done */
    in_program_data_ptr->link_task_fence_ptr->signal();

    /* NOTE: We do NOT cache the TProgram instance. It's not going to be needed afterwards */
    in_program_data_ptr->program_reference_ptr.reset();
}

OpenGL::SPIRVBlobID OpenGL::VKSPIRVManager::register_program(OpenGL::GLProgramReferenceUniquePtr in_program_reference_ptr)
{
    OpenGL::SPIRVBlobID result                       = UINT32_MAX;
    auto                program_frontend_manager_ptr = m_frontend_ptr->get_program_manager_ptr();
    auto                shader_frontend_manager_ptr  = m_frontend_ptr->get_shader_manager_ptr ();
    auto                thread_pool_ptr              = m_backend_ptr->get_thread_pool_ptr     ();

    const auto          program_id                   = in_program_reference_ptr->get_payload().id;
    const auto          program_timestamp            = in_program_reference_ptr->get_payload().time_marker;

    m_mutex.lock_unique();
    {
        ProgramDataUniquePtr     program_data_ptr;
        ProgramData*             program_data_raw_ptr = nullptr;
        std::vector<ShaderData*> shader_data_vec;

        /* 1. Obtain ptrs to ShaderData structures for all shaders attached to the program */
        {
            const auto attached_shader_reference_vec_ptr = program_frontend_manager_ptr->get_attached_shaders(program_id,
                                                                                                             &program_timestamp);

            vkgl_assert(attached_shader_reference_vec_ptr         != nullptr);
            vkgl_assert(attached_shader_reference_vec_ptr->size() >  0);

            for (const auto& current_shader_reference_ptr : *attached_shader_reference_vec_ptr)
            {
                const char* shader_glsl      = nullptr;
                const auto  shader_id        = current_shader_reference_ptr->get_payload().id;
                const auto  shader_timestamp = current_shader_reference_ptr->get_payload().time_marker;

                decltype(m_glsl_to_shader_data_map)::const_iterator shader_data_iterator;

                if (!shader_frontend_manager_ptr->get_shader_glsl(shader_id,
                                                                 &shader_timestamp,
                                                                 &shader_glsl) )
                {
                    vkgl_assert_fail();
                }
                else
                {
                    vkgl_assert(shader_glsl != nullptr);
                }

                shader_data_iterator = m_glsl_to_shader_data_map.find(std::string(shader_glsl) );
                vkgl_assert(shader_data_iterator != m_glsl_to_shader_data_map.end() );

                shader_data_vec.push_back(shader_data_iterator->second.get() );
            }
        }

        /* 2. Spawn a new entity to hold shader data */
        {
            SPIRVBlobID new_blob_id = static_cast<SPIRVBlobID>(++m_n_entities_registered);

            vkgl_assert(m_spirv_blob_id_to_program_data_map.find(new_blob_id) == m_spirv_blob_id_to_program_data_map.end() );

            program_data_ptr.reset(new ProgramData(new_blob_id,
                                                   shader_data_vec,
                                                   std::move(in_program_reference_ptr) )
            );
            vkgl_assert(program_data_ptr != nullptr);

            program_data_raw_ptr                                                                                          = program_data_ptr.get();
            m_program_reference_to_program_data_map[std::pair<GLuint, OpenGL::TimeMarker>(program_id, program_timestamp)] = program_data_raw_ptr;
            m_spirv_blob_id_to_program_data_map    [new_blob_id]                                                          = std::move(program_data_ptr);

            program_frontend_manager_ptr->set_program_backend_spirv_blob_id(program_id,
                                                                           &program_timestamp,
                                                                            new_blob_id);
        }

        /* 3. Wait until all shaders are compiled before submitting a link task to the thread pool.
         *
         * NOTE: This works because this function is always called from app's thread.
         * TODO: Do we need to implicitly submit compile shader tasks for shaders, for which glCompileShader() has not been invoked?
         */
        for (auto& current_shader_data_ptr : shader_data_vec)
        {
            current_shader_data_ptr->compile_task_fence_ptr->wait();
        }

        /* 4. Submit a new task to the thread pool, which we're going to use to actually perform the linking. */
        thread_pool_ptr->submit_task(std::bind(&OpenGL::VKSPIRVManager::link_program,
                                               this,
                                               program_data_raw_ptr)
        );
    }
    m_mutex.unlock_unique();

    return result;
}

OpenGL::SPIRVBlobID OpenGL::VKSPIRVManager::register_shader(const OpenGL::ShaderType& in_shader_type,
                                                            const char*               in_glsl)
{
    OpenGL::SPIRVBlobID result          = UINT32_MAX;
    auto                thread_pool_ptr = m_backend_ptr->get_thread_pool_ptr();

    m_mutex.lock_unique();
    {
        ShaderData* shader_data_raw_ptr = nullptr;

        vkgl_assert(m_glsl_to_shader_data_map.find(in_glsl) == m_glsl_to_shader_data_map.end() );

        /* 1. Spawn a new entity to hold shader data */
        {
            SPIRVBlobID         new_blob_id    = static_cast<SPIRVBlobID>(++m_n_entities_registered);
            ShaderDataUniquePtr shader_data_ptr;

            vkgl_assert(m_spirv_blob_id_to_shader_data_map.find(new_blob_id) == m_spirv_blob_id_to_shader_data_map.end() );

            shader_data_ptr.reset(new ShaderData(new_blob_id,
                                                 in_shader_type,
                                                 in_glsl)
            );
            vkgl_assert(shader_data_ptr != nullptr);

            shader_data_raw_ptr                             = shader_data_ptr.get();
            m_spirv_blob_id_to_shader_data_map[new_blob_id] = shader_data_raw_ptr;
            m_glsl_to_shader_data_map         [in_glsl]     = std::move(shader_data_ptr);
        }

        /* 2. Submit a new task to the thread pool, which we're going to use to actually perform the GLSL->SPIRV "conversion". */
        thread_pool_ptr->submit_task(std::bind(&OpenGL::VKSPIRVManager::compile_shader,
                                               this,
                                               shader_data_raw_ptr)
        );
    }
    m_mutex.unlock_unique();

    return result;
}

void OpenGL::VKSPIRVManager::unregister_program(const GLuint& in_id)
{
    m_mutex.lock_unique();
    {
        std::vector<std::pair<GLuint, OpenGL::TimeMarker> > relevant_program_reference_map_keys;
        std::vector<SPIRVBlobID>                            relevant_spirv_blob_ids;

        for (const auto& current_program_reference_map_item : m_program_reference_to_program_data_map)
        {
            if (current_program_reference_map_item.first.first == in_id)
            {
                relevant_program_reference_map_keys.push_back(current_program_reference_map_item.first);
            }
        }

        for (const auto& current_spirv_blob_map_item : m_spirv_blob_id_to_program_data_map)
        {
            if (current_spirv_blob_map_item.second->program_id == in_id)
            {
                relevant_spirv_blob_ids.push_back(current_spirv_blob_map_item.first);
            }
        }

        for (const auto& current_program_reference_map_key : relevant_program_reference_map_keys)
        {
            m_program_reference_to_program_data_map.erase(current_program_reference_map_key);
        }

        for (const auto& current_spirv_blob_id : relevant_spirv_blob_ids)
        {
            m_spirv_blob_id_to_program_data_map.erase(current_spirv_blob_id);
        }
    }
    m_mutex.unlock_unique();
}