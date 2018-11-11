/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/thread_pool.h"
#include "OpenGL/backend/vk_spirv_manager.h"

OpenGL::VKSPIRVManager::GLSLData::GLSLData(const SPIRVBlobID&        in_id,
                                           const Anvil::ShaderStage& in_shader_stage,
                                           const std::string&        in_glsl)
    :compilation_status(false),
     glsl              (in_glsl),
     id                (in_id),
     shader_stage      (in_shader_stage)
{
    vkgl_assert(in_shader_stage != Anvil::ShaderStage::UNKNOWN);

    compile_task_fence_ptr.reset(new VKGL::Fence() );
    vkgl_assert(compile_task_fence_ptr != nullptr);
}

OpenGL::VKSPIRVManager::VKSPIRVManager(IBackend* in_backend_ptr)
    :m_backend_ptr         (in_backend_ptr),
     m_n_shaders_registered(0)
{
    vkgl_assert(in_backend_ptr != nullptr);
}

OpenGL::VKSPIRVManager::~VKSPIRVManager()
{
    /* Stub for now */
}

void OpenGL::VKSPIRVManager::compile_shader(GLSLData* in_glsl_data_ptr)
{
    /* NOTE: This function is called back from one of the backend thread pool's threads */
    vkgl_not_implemented();

    in_glsl_data_ptr->compile_task_fence_ptr->signal();
}

OpenGL::VKSPIRVManagerUniquePtr OpenGL::VKSPIRVManager::create(IBackend* in_backend_ptr)
{
    OpenGL::VKSPIRVManagerUniquePtr result_ptr;

    result_ptr.reset(new VKSPIRVManager(in_backend_ptr) );
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

OpenGL::SPIRVBlobID OpenGL::VKSPIRVManager::register_shader(const Anvil::ShaderStage& in_shader_stage,
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
                                             in_shader_stage,
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

