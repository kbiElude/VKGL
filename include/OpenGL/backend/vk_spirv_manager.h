/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_SPIRV_MANAGER_H
#define VKGL_VK_SPIRV_MANAGER_H

#include "Common/fence.h"
#include "Common/shared_mutex.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef uint32_t SPIRVBlobID;

    class VKSPIRVManager
    {
    public:
        /* Public functions */

        static VKSPIRVManagerUniquePtr create();

        ~VKSPIRVManager();

        bool get_shader_compilation_status(const SPIRVBlobID&   in_spirv_blob_id,
                                            bool*               out_status_ptr,
                                            const char**        out_compilation_log_ptr) const;
        bool get_spirv_blob               (const SPIRVBlobID&   in_spirv_blob_id,
                                           const uint8_t**      out_spirv_blob_ptr,
                                           uint32_t*            out_spirv_blob_size_bytes_ptr) const;
        bool get_spirv_blob_id_for_glsl   (const char*          in_glsl_ptr,
                                           OpenGL::SPIRVBlobID* out_result_ptr)                const;

        SPIRVBlobID register_shader(const Anvil::ShaderStage& in_shader_stage,
                                    const char*               in_glsl);

    private:
        /* Private type definitions */
        typedef struct GLSLData
        {
            std::string          compilation_log;
            bool                 compilation_status;
            VKGL::FenceUniquePtr compile_task_fence_ptr;
            SPIRVBlobID          id;
            Anvil::ShaderStage   shader_stage;
            std::vector<uint8_t> spirv_blob;

            GLSLData()
                :compilation_status(false),
                 id                (UINT32_MAX),
                 shader_stage      (Anvil::ShaderStage::UNKNOWN)
            {
                /* Stub */
            }
        } GLSLData;

        typedef std::unique_ptr<GLSLData> GLSLDataUniquePtr;

        /* Private functions */
        VKSPIRVManager();

        std::unordered_map<std::string, GLSLDataUniquePtr> m_glsl_to_glsl_data_map;
        mutable VKGL::SharedMutex                          m_mutex;
        uint32_t                                           m_n_shaders_registered;
        std::unordered_map<SPIRVBlobID, GLSLData*>         m_spirv_blob_id_to_glsl_data_map;
    };
}

#endif /* VKGL_VK_SPIRV_MANAGER_H */
