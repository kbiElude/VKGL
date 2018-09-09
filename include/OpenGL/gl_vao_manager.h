/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VAO_MANAGER_H
#define VKGL_GL_VAO_MANAGER_H

#include "OpenGL/namespace.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLVAOManager> GLVAOManagerUniquePtr;

    class GLVAOManager : public IGLVAOManager,
                         public IGLVAOManagerRelease
    {
    public:
        /* Public functions */

        static GLVAOManagerUniquePtr create(const IGLLimits* in_limits_ptr);

        bool delete_ids      (const uint32_t& in_n_ids,
                              const GLuint*   in_ids_ptr);
        bool generate_ids    (const uint32_t& in_n_ids,
                              GLuint*         out_ids_ptr);
        bool is_alive_id     (const GLuint&   in_id)       const;
        bool mark_id_as_bound(const GLuint&   in_vao_id);

        bool get_element_array_buffer_binding(const uint32_t& in_vao_id,
                                              GLuint*         out_result_ptr) const;

        /* NOTE: We return a copy here due to anticipated MT support requirements. */
        bool get_vaa_state_copy(const GLuint&              in_vao_id,
                                const uint32_t&            in_n_vao_vaa,
                                VertexAttributeArrayState* out_result_ptr) const;

        bool get_vaa_property(const GLuint&                         in_vao_id,
                              const uint32_t&                       in_n_vao_vaa,
                              const OpenGL::VertexAttributeProperty in_pname,
                              const OpenGL::GetSetArgumentType&     in_dst_type,
                              void*                                 out_result_ptr) const;

        GLVAOBindingUniquePtr acquire_vao            (const GLuint& in_vao_id);
        GLVAOBindingUniquePtr get_default_vao_binding()                        const final;

        bool set_element_array_buffer_binding(const GLuint&                    in_vao_id,
                                              const GLuint&                    in_new_buffer_binding);
        bool set_vaa_state                   (const GLuint&                    in_vao_id,
                                              const uint32_t&                  in_n_vao_vaa,
                                              const VertexAttributeArrayState& in_state);

        ~GLVAOManager();

    private:
        /* Private type definitions */

        enum class Status
        {
            Created_Not_Bound,
            Alive,
            Deleted_Bindings_Pending,

            Unknown
        };

        typedef struct VAO
        {
            std::vector<OpenGL::GLVAOBinding*>              bindings;
            GLuint                                          id;
            Status                                          status;
            std::unique_ptr<OpenGL::VertexArrayObjectState> vao_ptr;

            VAO()
            {
                id     = UINT32_MAX;
                status = Status::Unknown;
            }
        } VAO;

        /* IGLVaoManagerRelease interface */
        void release_vao(const OpenGL::GLVAOBinding* in_vao_binding_ptr) final;

        /* Private functions */

        GLVAOManager(const IGLLimits* in_limits_ptr);

        bool init          ();
        bool insert_new_vao(const GLuint& in_id);

        /* Private variables */
        OpenGL::NamespaceUniquePtr m_id_manager_ptr;
        const IGLLimits* const     m_limits_ptr;

        bool                                              m_releasing;
        std::unordered_map<GLuint, std::unique_ptr<VAO> > m_vao_ptrs;
        mutable std::mutex                                m_vao_ptrs_lock;
        GLVAOBindingUniquePtr                             m_zero_vao_binding_ptr;

        friend class GLVAOBinding;
    };
}
#endif /* VKGL_GL_VAO_MANAGER_H */