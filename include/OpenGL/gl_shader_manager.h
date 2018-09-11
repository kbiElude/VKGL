/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SHADER_MANAGER_H
#define VKGL_GL_SHADER_MANAGER_H

#include "OpenGL/gl_object_manager.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLShaderManager> GLShaderManagerUniquePtr;

    class GLShaderManager : public GLObjectManager
    {
    public:
        /* Public functions */

        static GLShaderManagerUniquePtr create();

        ~GLShaderManager();

        bool get_shader_glsl   (const GLuint&             in_id,
                                const char**              out_result_ptr_ptr) const;
        bool get_shader_infolog(const GLuint&             in_id,
                                const char**              out_result_ptr_ptr) const;
        bool set_shader_glsl   (const GLuint&             in_id,
                                const std::string&        in_glsl);
        bool set_shader_infolog(const GLuint&             in_id,
                                const std::string&        in_glsl);
        bool set_shader_type   (const GLuint&             in_id,
                                const OpenGL::ShaderType& in_type);

        bool get_shader_property(const GLuint&                     in_shader,
                                 const OpenGL::ShaderProperty&     in_pname,
                                 const OpenGL::GetSetArgumentType& in_params_type,
                                 const uint32_t&                   in_n_params_components,
                                 GLint*                            out_params_ptr) const;

    protected:
        /* Protected functions */
        bool     add_reference    (const GLuint&      in_id,
                                   const GLReference* in_reference_ptr) final;
        bool     delete_reference (const GLuint&      in_id,
                                   const GLReference* in_reference_ptr) final;
        bool     delete_object    (const GLuint&      in_id)            final;
        uint32_t get_n_references (const GLuint&      in_id) const      final;
        Status   get_object_status(const GLuint&      in_id) const      final;
        bool     insert_object    (const GLuint&      in_id)            final;
        bool     is_id_valid      (const GLuint&      in_id) const      final;
        bool     set_object_status(const GLuint&      in_id,
                                   const Status&      in_new_status)    final;

    private:
        /* Private type definitions */

        typedef struct Shader
        {
            std::string                     glsl;
            GLuint                          id;
            std::string                     infolog;
            std::vector<const GLReference*> references;
            Status                          status;
            bool                            successful_last_compile;
            OpenGL::ShaderType              type;

            Shader()
            {
                id                      = UINT32_MAX;
                status                  = Status::Unknown;
                successful_last_compile = false;
                type                    = OpenGL::ShaderType::Unknown;
            }

            Shader(const GLuint& in_id)
            {
                id                      = in_id;
                status                  = Status::Alive;
                successful_last_compile = false;
                type                    = OpenGL::ShaderType::Unknown;
            }
        } Shader;

        /* Private functions */

        GLShaderManager();

        const Shader* get_shader_ptr(const GLuint& in_id) const;
        Shader*       get_shader_ptr(const GLuint& in_id);

        /* Private variables */
        std::unordered_map<GLuint, std::unique_ptr<Shader> > m_shader_ptrs;
    };
}
#endif /* VKGL_GL_SHADER_MANAGER_H */