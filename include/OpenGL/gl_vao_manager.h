/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VAO_MANAGER_H
#define VKGL_GL_VAO_MANAGER_H

#include "OpenGL/gl_object_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLVAOManager> GLVAOManagerUniquePtr;

    class GLVAOManager : public GLObjectManager
    {
    public:
        /* Public functions */

        static GLVAOManagerUniquePtr create(const IGLLimits* in_limits_ptr);

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

        bool set_element_array_buffer_binding(const GLuint&                    in_vao_id,
                                              const GLuint&                    in_new_buffer_binding);
        bool set_vaa_state                   (const GLuint&                    in_vao_id,
                                              const uint32_t&                  in_n_vao_vaa,
                                              const VertexAttributeArrayState& in_state);

        ~GLVAOManager();

    protected:
        /* Protected functions */
        bool     add_binding      (const GLuint&    in_id,
                                   const GLBinding* in_binding_ptr) final;
        bool     delete_binding   (const GLuint&    in_id,
                                   const GLBinding* in_binding_ptr) final;
        bool     delete_object    (const GLuint&    in_id)          final;
        uint32_t get_n_bindings   (const GLuint&    in_id) const    final;
        Status   get_object_status(const GLuint&    in_id) const    final;
        bool     insert_object    (const GLuint&    in_id)          final;
        bool     is_id_valid      (const GLuint&    in_id) const    final;
        bool     set_object_status(const GLuint&    in_id,
                                   const Status&    in_new_status)  final;

    private:
        /* Private type definitions */

        typedef struct VAO
        {
            std::vector<const OpenGL::GLBinding*>           bindings;
            GLuint                                          id;
            Status                                          status;
            std::unique_ptr<OpenGL::VertexArrayObjectState> vao_ptr;

            VAO()
            {
                id     = UINT32_MAX;
                status = Status::Unknown;
            }

            VAO(const GLuint&    in_id,
                const IGLLimits* in_limits_ptr);
        } VAO;

        /* Private functions */

        GLVAOManager(const IGLLimits* in_limits_ptr);

        bool insert_new_vao(const GLuint& in_id);

        /* Private variables */
        std::unordered_map<GLuint, std::unique_ptr<VAO> > m_vao_ptrs;
    };
}
#endif /* VKGL_GL_VAO_MANAGER_H */