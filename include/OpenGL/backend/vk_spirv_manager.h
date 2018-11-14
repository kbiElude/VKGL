/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_SPIRV_MANAGER_H
#define VKGL_VK_SPIRV_MANAGER_H

#include "Anvil/deps/glslang/SPIRV/GlslangToSpv.h"
#include "Common/fence.h"
#include "Common/shared_mutex.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    class VKSPIRVManager
    {
    public:
        /* Public functions */

        static VKSPIRVManagerUniquePtr create(IBackend*                             in_backend_ptr,
                                              const OpenGL::IContextObjectManagers* in_frontend_ptr);

        ~VKSPIRVManager();

        bool get_program_link_status                (const SPIRVBlobID&        in_spirv_blob_id,
                                                     bool*                     out_status_ptr,
                                                     const char**              out_link_log_ptr) const;
        bool get_shader_compilation_status          (const SPIRVBlobID&        in_spirv_blob_id,
                                                     bool*                     out_status_ptr,
                                                     const char**              out_compilation_log_ptr) const;
        bool get_spirv_blob                         (const SPIRVBlobID&        in_spirv_blob_id,
                                                     const uint8_t**           out_spirv_blob_ptr,
                                                     uint32_t*                 out_spirv_blob_size_bytes_ptr) const;
        bool get_spirv_blob_id_for_glsl             (const char*               in_glsl_ptr,
                                                     OpenGL::SPIRVBlobID*      out_result_ptr) const;
        bool get_spirv_blob_id_for_program_reference(const GLuint&             in_program_id,
                                                     const OpenGL::TimeMarker& in_time_marker,
                                                     OpenGL::SPIRVBlobID*      out_result_ptr) const;

        SPIRVBlobID register_program(OpenGL::GLProgramReferenceUniquePtr in_program_reference_ptr);
        SPIRVBlobID register_shader (const OpenGL::ShaderType&           in_shader_type,
                                     const char*                         in_glsl);

    private:
        /* Private type definitions */
        typedef struct ShaderData
        {
            std::string                       compilation_log;
            bool                              compilation_status;
            VKGL::FenceUniquePtr              compile_task_fence_ptr;
            std::string                       glsl;
            std::unique_ptr<glslang::TShader> glslang_shader_ptr;
            SPIRVBlobID                       id;
            std::vector<uint8_t>              spirv_blob;
            OpenGL::ShaderType                type;

            ShaderData(const SPIRVBlobID&        in_id,
                       const OpenGL::ShaderType& in_shader_type,
                       const std::string&        in_glsl);

        private:
            ANVIL_DISABLE_ASSIGNMENT_OPERATOR(ShaderData);
            ANVIL_DISABLE_COPY_CONSTRUCTOR   (ShaderData);
        } ShaderData;

        typedef std::unique_ptr<ShaderData> ShaderDataUniquePtr;

        typedef struct ProgramData
        {
            SPIRVBlobID              id;
            std::string              link_log;
            bool                     link_status;
            VKGL::FenceUniquePtr     link_task_fence_ptr;
            std::vector<ShaderData*> shader_ptrs;
            std::vector<uint8_t>     spirv_blobs[static_cast<uint32_t>(OpenGL::ShaderType::Count)];

            /* Temporary object stored until linking finishes and then released. It is used in order to ensure
             * frontend does not release corresponding descriptor until we're done doing things on the backend's end.
             */
            OpenGL::GLProgramReferenceUniquePtr program_reference_ptr;

            ProgramData(const SPIRVBlobID&                  in_id,
                        const std::vector<ShaderData*>&     in_shader_ptrs,
                        OpenGL::GLProgramReferenceUniquePtr in_program_reference_ptr);

        private:
            ANVIL_DISABLE_ASSIGNMENT_OPERATOR(ProgramData);
            ANVIL_DISABLE_COPY_CONSTRUCTOR   (ProgramData);
        } ProgramData;

        typedef std::unique_ptr<ProgramData> ProgramDataUniquePtr;

        /* Private functions */
        VKSPIRVManager(IBackend*                             in_backend_ptr,
                       const OpenGL::IContextObjectManagers* in_frontend_ptr);

        void compile_shader(ShaderData*  in_shader_data_ptr);
        void link_program  (ProgramData* in_program_data_ptr);

        PostLinkDataUniquePtr      create_post_link_data                       (const glslang::TProgram*        in_program_data_ptr) const;
        OpenGL::GeometryInputType  get_geometry_input_type_for_layout_geometry (const glslang::TLayoutGeometry& in_layout_geometry)  const;
        OpenGL::GeometryOutputType get_geometry_output_type_for_layout_geometry(const glslang::TLayoutGeometry& in_layout_geometry)  const;
        OpenGL::VariableType       get_variable_type_for_glslang_type          (const glslang::TType&           in_type)             const;

        bool init                  ();
        bool init_glslang_resources();

        IBackend*                                                     m_backend_ptr;
        const OpenGL::IContextObjectManagers*                         m_frontend_ptr;
        std::unordered_map<std::string, ShaderDataUniquePtr>          m_glsl_to_shader_data_map;
        mutable VKGL::SharedMutex                                     m_mutex;
        uint32_t                                                      m_n_entities_registered;
        std::map<std::pair<GLuint, OpenGL::TimeMarker>, ProgramData*> m_program_reference_to_program_data_map;
        std::unordered_map<SPIRVBlobID, ProgramDataUniquePtr>         m_spirv_blob_id_to_program_data_map;
        std::unordered_map<SPIRVBlobID, ShaderData*>                  m_spirv_blob_id_to_shader_data_map;

        std::unique_ptr<struct TBuiltInResource> m_glslang_resources_ptr;
    };
}

#endif /* VKGL_VK_SPIRV_MANAGER_H */
