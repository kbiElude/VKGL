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

    class GLProgramManager : public GLObjectManager
    {
    public:
        /* Public constants */
        static const uint32_t DEFAULT_UNIFORM_BLOCK_INDEX = UINT32_MAX;

        /* Public functions */

        static GLProgramManagerUniquePtr create();

        ~GLProgramManager();

        bool attach_shader                    (const GLuint&                       in_program,
                                               GLReferenceUniquePtr                in_shader_reference_ptr);
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

        const std::vector<GLReferenceUniquePtr>* get_attached_shaders(const GLuint&             in_program,
                                                                      const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;

        bool map_global_uniform_index_to_uniform_and_ub_indices(const GLuint&             in_program,
                                                                const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                                                const GLuint&             in_global_uniform_index,
                                                                GLuint*                   out_uniform_block_index_ptr,
                                                                GLuint*                   out_uniform_index_ptr) const;

        void set_uniform_block_binding(const GLuint& in_program,
                                       const GLuint& in_uniform_block_index,
                                       const GLuint& in_uniform_block_binding);

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object() final;

    private:
        /* Private type definitions */

        typedef std::unordered_map<std::string, uint32_t> AttributeLocationBindingMap;
        typedef std::unordered_map<std::string, uint32_t> FragDataLocationMap;

        typedef struct ActiveAttributeProperties
        {
            int32_t      location;
            std::string  name;
            uint32_t     size; /* in units of attribute's type */
            VariableType type;

            ActiveAttributeProperties()
               :location(-1),
                size    (0),
                type    (VariableType::Unknown)
            {
                /* Stub */
            }

            ActiveAttributeProperties(const std::string&  in_name,
                                      const int32_t&      in_location,
                                      const uint32_t&     in_size,
                                      const VariableType& in_type)
                :location(in_location),
                 name    (in_name),
                 size    (in_size),
                 type    (in_type)
            {
                /* Stub */
            }
        } ActiveAttributeProperties;

        typedef struct ActiveUniformProperties
        {
            int32_t      array_stride;  /* 0 for non array uniforms,                     -1 for default UB uniforms */
            int32_t      index;
            uint32_t     is_row_major;  /* 1 = true,                                      0 otherwise */
            int32_t      location;
            int32_t      matrix_stride; /* 0 for non matrix uniforms in non-default UBs, -1 for default UB uniforms */
            std::string  name;
            int32_t      offset;
            uint32_t     size; /* in units of attribute's type OR n of array items for arrayed uniforms */
            VariableType type;
            int32_t      uniform_block_index;

            ActiveUniformProperties()
               :array_stride       (-1),
                index              (GL_INVALID_INDEX),
                is_row_major       (UINT32_MAX),
                location           (-1),
                matrix_stride      (-1),
                offset             (-1),
                size               (0),
                type               (VariableType::Unknown),
                uniform_block_index(-1)
            {
                /* Stub */
            }

            ActiveUniformProperties(const std::string&  in_name,
                                    const uint32_t&     in_size,
                                    const VariableType& in_type,
                                    const int32_t&      in_uniform_block_index,
                                    const int32_t&      in_offset, /* -1 for default UBs */
                                    const int32_t&      in_array_stride,
                                    const int32_t&      in_matrix_stride,
                                    const bool&         in_is_row_major,
                                    const int32_t&      in_location,
                                    const int32_t&      in_index)
                :array_stride       (in_array_stride),
                 index              (in_index),
                 is_row_major       ( (in_is_row_major) ? 1 : 0),
                 location           (in_location),
                 matrix_stride      (in_matrix_stride),
                 name               (in_name),
                 offset             (in_offset),
                 size               (in_size),
                 type               (in_type),
                 uniform_block_index(in_uniform_block_index)
            {
                /* Stub */
            }
        } ActiveUniformProperties;

        typedef struct ActiveUniformBlock
        {
            std::vector<ActiveUniformProperties> active_uniforms;
            uint32_t                             binding_point;
            uint32_t                             data_size;
            int32_t                              index;
            std::string                          name;
            bool                                 referenced_by_fs;
            bool                                 referenced_by_gs;
            bool                                 referenced_by_vs;

            ActiveUniformBlock()
                :binding_point   (0),
                 data_size       (0),
                 index           (GL_INVALID_INDEX),
                 referenced_by_fs(false),
                 referenced_by_gs(false),
                 referenced_by_vs(false)
            {
                /* Stub */
            }

            ActiveUniformBlock(const int32_t&     in_index,
                               const std::string& in_name)
                :binding_point   (0),
                 data_size       (0),
                 index           (in_index),
                 name            (in_name),
                 referenced_by_fs(false),
                 referenced_by_gs(false),
                 referenced_by_vs(false)
            {
                /* Stub */
            }
        } ActiveUniformBlock;

        typedef std::pair<int32_t, uint32_t> UniformBlockAndUniformIndexPair;

        typedef struct PostLinkData
        {
            std::unordered_map<std::string, uint32_t>                       active_attribute_name_to_location_map;
            std::vector<ActiveAttributeProperties>                          active_attributes;
            std::unordered_map<std::string, const ActiveUniformBlock*>      active_uniform_block_by_name_map;
            std::vector<ActiveUniformBlock>                                 active_uniform_blocks;
            std::unordered_map<std::string, const ActiveUniformProperties*> active_uniform_by_name_map;
            std::vector<ActiveUniformProperties>                            active_uniforms;
            FragDataLocationMap                                             frag_data_locations;
            std::unordered_map<uint32_t, UniformBlockAndUniformIndexPair>   index_to_ub_and_uniform_index_pair;
            std::string                                                     link_info_log;

            uint32_t active_attribute_max_length;
            uint32_t active_uniform_block_max_name_length;
            uint32_t active_uniform_max_length;

            PostLinkData();
        } PostLinkData;

        typedef struct Program
        {
            std::vector<GLReferenceUniquePtr>     attached_shaders;
            AttributeLocationBindingMap           cached_attribute_location_bindings; //< Locations to force for specific generic vertex attributes.
            FragDataLocationMap                   cached_frag_data_locations;         //< Bindings to force for specific fragment color outputs.
            std::string                           infolog;
            std::unique_ptr<PostLinkData>         post_link_data_ptr;

            OpenGL::GeometryInputType             gs_input_type;               //< GL_GEOMETRY_INPUT_TYPE
            OpenGL::GeometryOutputType            gs_output_type;              //< GL_GEOMETRY_OUTPUT_TYPE
            uint32_t                              n_max_gs_vertices_generated; //< GL_GEOMETRY_VERTICES_OUT

            OpenGL::TransformFeedbackBufferMode   tf_buffer_mode;              //< GL_TRANSFORM_FEEDBACK_BUFFER_MODE
            std::vector<std::string>              tf_varyings;
            uint32_t                              tf_varying_max_length;

            std::unordered_map<uint32_t, uint32_t> ub_index_to_ub_binding;

            bool delete_status;
            bool link_status;
            bool validate_status;

            Program()
                :delete_status              (false),
                 gs_input_type              (OpenGL::GeometryInputType::Triangles),
                 gs_output_type             (OpenGL::GeometryOutputType::Triangle_Strip),
                 link_status                (false),
                 n_max_gs_vertices_generated(0),
                 tf_buffer_mode             (OpenGL::TransformFeedbackBufferMode::Interleaved_Attribs),
                 tf_varying_max_length      (0),
                 validate_status            (false)
            {
                /* Stub */
            }
        } Program;

        /* Private functions */

        GLProgramManager();

        const Program* get_program_ptr(const GLuint&             in_id,
                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        Program*       get_program_ptr(const GLuint&             in_id,
                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */
    };
}
#endif /* VKGL_GL_PROGRAM_MANAGER_H */