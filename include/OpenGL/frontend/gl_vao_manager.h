/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VAO_MANAGER_H
#define VKGL_GL_VAO_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLVAOManager> GLVAOManagerUniquePtr;

    class GLVAOManager : public GLObjectManager<GLVAOReference, GLVAOReferenceUniquePtr>
    {
    public:
        /* Public functions */

        static GLVAOManagerUniquePtr create(const IGLLimits*              in_limits_ptr,
                                            const IContextObjectManagers* in_frontend_object_managers_ptr);

        bool get_element_array_buffer_binding(const uint32_t&           in_vao_id,
                                              const OpenGL::TimeMarker* in_opt_time_marker_ptr,
                                              GLuint*                   out_result_ptr) const;

        bool get_vaa_state_copy(const GLuint&              in_vao_id,
                                const OpenGL::TimeMarker*  in_opt_time_marker_ptr,
                                const uint32_t&            in_n_vao_vaa,
                                VertexAttributeArrayState* out_result_ptr) const;

        bool get_vaa_property(const GLuint&                         in_vao_id,
                              const OpenGL::TimeMarker*             in_opt_time_marker_ptr,
                              const uint32_t&                       in_n_vao_vaa,
                              const OpenGL::VertexAttributeProperty in_pname,
                              const OpenGL::GetSetArgumentType&     in_dst_type,
                              void*                                 out_result_ptr) const;

        bool get_vao_state_ptr(const GLuint&                          in_vao_id,
                               const OpenGL::TimeMarker*              in_opt_time_marker_ptr,
                               const OpenGL::VertexArrayObjectState** out_vao_state_ptr_ptr) const;

        bool set_element_array_buffer_binding(const GLuint&                    in_vao_id,
                                              const GLuint&                    in_new_buffer_binding);
        bool set_vaa_state                   (const GLuint&                    in_vao_id,
                                              const uint32_t&                  in_n_vao_vaa,
                                              const VertexAttributeArrayState& in_state);

        ~GLVAOManager();

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr,
                                                                                       const bool& in_convert_from_proxy_to_nonproxy) final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr)                        final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                                              final;

    private:
        /* Private type definitions */

        typedef struct VAO
        {
            std::unique_ptr<OpenGL::VertexArrayObjectState> vao_ptr;

            VAO() = delete;
            VAO(const VAO&                    in_vao,
                const bool&                   in_convert_from_proxy_to_nonproxy,
                const IContextObjectManagers* in_frontend_object_managers_ptr);
            VAO(const IGLLimits*              in_limits_ptr);

            VAO& operator=(const VAO& in_vao);
        } VAO;

        /* Private functions */

        GLVAOManager(const IGLLimits*              in_limits_ptr,
                     const IContextObjectManagers* in_frontend_object_managers_ptr);

        const VAO* get_vao_ptr(const GLuint&             in_id,
                               const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        VAO*       get_vao_ptr(const GLuint&             in_id,
                               const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */

        const IContextObjectManagers* const m_frontend_object_managers_ptr;
        const IGLLimits* const              m_limits_ptr;
    };
}
#endif /* VKGL_GL_VAO_MANAGER_H */