/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_spirv_manager.h"

OpenGL::VKSPIRVManager::VKSPIRVManager()
    :m_n_shaders_registered(0)
{
    /* Stub for now */
}

OpenGL::VKSPIRVManager::~VKSPIRVManager()
{
    /* Stub for now */
}

OpenGL::VKSPIRVManagerUniquePtr OpenGL::VKSPIRVManager::create()
{
    OpenGL::VKSPIRVManagerUniquePtr result_ptr;

    result_ptr.reset(new VKSPIRVManager() );
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

        vkgl_assert(iterator != m_glsl_to_glsl_data_map.end() );
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

OpenGL::SPIRVBlobID OpenGL::VKSPIRVManager::register_shader(const Anvil::ShaderStage& in_shader_stage,
                                                            const char*               in_glsl)
{
    OpenGL::SPIRVBlobID result = UINT32_MAX;

    vkgl_not_implemented();

    return result;
}

