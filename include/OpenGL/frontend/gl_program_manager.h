/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_PROGRAM_MANAGER_H
#define VKGL_GL_PROGRAM_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLProgramManager> GLProgramManagerUniquePtr;

    class GLProgramManager : public GLObjectManager<GLProgramReference, GLProgramReferenceUniquePtr>
    {
    public:
        /* Public constants */
        static const uint32_t DEFAULT_UNIFORM_BLOCK_INDEX = UINT32_MAX;

        /* Public functions */

        static GLProgramManagerUniquePtr create(IBackendGLCallbacks* in_backend_ptr);

        ~GLProgramManager();

        bool attach_shader                    (const GLuint&                       in_program,
                                               GLShaderReferenceUniquePtr          in_shader_reference_ptr);
        bool cache_attribute_location_binding (const GLuint&                       in_program,
                                               const char*                         in_name,
                                               const uint32_t&                     in_index);
        bool cache_frag_data_location         (const GLuint&                       in_program,
                                               const char*                         in_name,
                                               const uint32_t&                     in_fragment_color_output);
        bool detach_shader                    (const GLuint&                       in_program,
                                               const GLuint&                       in_shader_id);
        bool get_active_attribute             (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const GLuint&                       in_index,
                                               const char**                        out_opt_name_ptr_ptr,
                                               uint32_t*                           out_opt_size_ptr,
                                               VariableType*                       out_opt_variable_ptr) const;
        bool get_active_attribute_location    (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const char*                         in_name,
                                               GLint*                              out_result_ptr) const;
        bool get_active_uniform               (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const GLuint&                       in_index,
                                               const uint32_t                      in_uniform_block_index = DEFAULT_UNIFORM_BLOCK_INDEX,
                                               const char**                        out_opt_name_ptr_ptr   = nullptr,
                                               uint32_t*                           out_opt_size_ptr       = nullptr,
                                               VariableType*                       out_opt_variable_ptr   = nullptr) const;
        bool get_active_uniform_block_name    (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const GLuint&                       in_index,
                                               const char**                        out_opt_name_ptr_ptr) const;
        bool get_active_uniform_block_property(const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const GLuint&                       in_uniform_block_index,
                                               const OpenGL::UniformBlockProperty& in_pname,
                                               const OpenGL::GetSetArgumentType&   in_params_type,
                                               void*                               out_params_ptr) const;
        bool get_active_uniform_by_name       (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const char*                         in_name_ptr,
                                               GLint*                              out_opt_location_ptr = nullptr) const;
        bool get_active_uniform_indices       (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const uint32_t&                     in_uniform_count,
                                               const char* const*                  in_uniform_names_ptr_ptr,
                                               GLuint*                             out_uniform_indices_ptr) const; /* NOTE: For unrecognized names, set corresponding result array items to GL_INVALID_INDEX */
        bool get_active_uniforms_property     (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const GLsizei&                      in_uniform_count,
                                               const GLuint*                       in_uniform_indices_ptr,
                                               const OpenGL::UniformProperty&      in_pname,
                                               GLint*                              out_params_ptr) const;
        bool get_frag_data_location           (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const char*                         in_name_ptr,
                                               GLint*                              out_result_ptr) const;
        bool get_program_info_log             (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const char**                        out_result_ptr) const;
        bool get_program_property             (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const OpenGL::ProgramProperty&      in_pname,
                                               const OpenGL::GetSetArgumentType&   in_params_type,
                                               const uint32_t&                     in_n_params_components,
                                               void*                               out_params_ptr) const;
        bool get_uniform_block_index          (const GLuint&                       in_program,
                                               const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                               const char*                         in_uniform_block_name,
                                               uint32_t*                           out_result_ptr) const;

        const std::vector<GLShaderReferenceUniquePtr>* get_attached_shaders(const GLuint&             in_program,
                                                                            const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;

        bool map_global_uniform_index_to_uniform_and_ub_indices(const GLuint&             in_program,
                                                                const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                                                const GLuint&             in_global_uniform_index,
                                                                GLuint*                   out_uniform_block_index_ptr,
                                                                GLuint*                   out_uniform_index_ptr) const;

        void set_uniform_block_binding(const GLuint& in_program,
                                       const GLuint& in_uniform_block_index,
                                       const GLuint& in_uniform_block_binding);

        void set_program_backend_spirv_blob_id(const GLuint&              in_program,
                                               const OpenGL::TimeMarker*  in_opt_time_marker_ptr,
                                               const OpenGL::SPIRVBlobID& in_spirv_blob_id);
        void set_program_post_link_data_ptr   (const GLuint&              in_program,
                                               const OpenGL::TimeMarker*  in_opt_time_marker_ptr,
                                               PostLinkDataUniquePtr      in_post_link_data_ptr);

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr)     final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr) final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                       final;

    private:
        /* Private type definitions */

        typedef std::unordered_map<std::string, uint32_t> AttributeLocationBindingMap;

        typedef struct Program
        {
            std::vector<GLShaderReferenceUniquePtr> attached_shaders;
            AttributeLocationBindingMap             cached_attribute_location_bindings; //< Locations to force for specific generic vertex attributes.
            FragDataLocationMap                     cached_frag_data_locations;         //< Bindings to force for specific fragment color outputs.

            OpenGL::GeometryInputType  gs_input_type;               //< GL_GEOMETRY_INPUT_TYPE
            OpenGL::GeometryOutputType gs_output_type;              //< GL_GEOMETRY_OUTPUT_TYPE
            uint32_t                   n_max_gs_vertices_generated; //< GL_GEOMETRY_VERTICES_OUT

            OpenGL::TransformFeedbackBufferMode   tf_buffer_mode;              //< GL_TRANSFORM_FEEDBACK_BUFFER_MODE
            std::vector<std::string>              tf_varyings;
            uint32_t                              tf_varying_max_length;

            std::unordered_map<uint32_t, uint32_t> ub_index_to_ub_binding;

            bool delete_status;
            bool validate_status;

            OpenGL::SPIRVBlobID spirv_blob_id;

            const PostLinkData* get_post_link_data(IBackendGLCallbacks* in_backend_ptr) const;

            void set_post_link_data(PostLinkDataUniquePtr in_post_link_data_ptr)
            {
                vkgl_assert(in_post_link_data_ptr != nullptr);

                post_link_data_ptr = std::move(in_post_link_data_ptr);
            }

            Program()
                :delete_status              (false),
                 gs_input_type              (OpenGL::GeometryInputType::Triangles),
                 gs_output_type             (OpenGL::GeometryOutputType::Triangle_Strip),
                 n_max_gs_vertices_generated(0),
                 spirv_blob_id              (UINT32_MAX),
                 tf_buffer_mode             (OpenGL::TransformFeedbackBufferMode::Interleaved_Attribs),
                 tf_varying_max_length      (0),
                 validate_status            (true) /* TODO */
            {
                /* Stub */
            }

            Program           (const Program& in_program);
            Program& operator=(const Program& in_program);

        private:
            PostLinkDataUniquePtr post_link_data_ptr;

        } Program;

        /* Private functions */

        GLProgramManager(IBackendGLCallbacks* in_backend_ptr);

        const Program* get_program_ptr(const GLuint&             in_id,
                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        Program*       get_program_ptr(const GLuint&             in_id,
                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */
        IBackendGLCallbacks* m_backend_ptr;
    };
}
#endif /* VKGL_GL_PROGRAM_MANAGER_H */