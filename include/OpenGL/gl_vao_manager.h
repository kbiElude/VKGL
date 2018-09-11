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
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object(const GLuint& in_id) final;

    private:
        /* Private type definitions */

        typedef struct VAO
        {
            std::unique_ptr<OpenGL::VertexArrayObjectState> vao_ptr;

            VAO();

            VAO(const IGLLimits* in_limits_ptr);
        } VAO;

        /* Private functions */

        GLVAOManager(const IGLLimits* in_limits_ptr);

        const VAO* get_vao_ptr(const GLuint& in_id) const;
        VAO*       get_vao_ptr(const GLuint& in_id);

        /* Private variables */
        const IGLLimits* const m_limits_ptr;
    };
}
#endif /* VKGL_GL_VAO_MANAGER_H */