/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SHADER_MANAGER_H
#define VKGL_GL_SHADER_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"
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

        bool get_shader_glsl              (const GLuint&             in_id,
                                           const char**              out_result_ptr_ptr) const;
        bool get_shader_infolog           (const GLuint&             in_id,
                                           const char**              out_result_ptr_ptr) const;
        bool get_shader_last_modified_time(const GLuint&             in_id,
                                           OpenGL::TimeMarker*       out_result_ptr) const;
        bool set_shader_glsl              (const GLuint&             in_id,
                                           const std::string&        in_glsl);
        bool set_shader_infolog           (const GLuint&             in_id,
                                           const std::string&        in_glsl);
        bool set_shader_type              (const GLuint&             in_id,
                                           const OpenGL::ShaderType& in_type);

        bool get_shader_property(const GLuint&                     in_shader,
                                 const OpenGL::ShaderProperty&     in_pname,
                                 const OpenGL::GetSetArgumentType& in_params_type,
                                 const uint32_t&                   in_n_params_components,
                                 GLint*                            out_params_ptr) const;

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object(const GLuint& in_id) final;

    private:
        /* Private type definitions */

        typedef struct Shader
        {
            std::string        glsl;
            std::string        infolog;
            OpenGL::TimeMarker last_modified_time;
            bool               successful_last_compile;
            OpenGL::ShaderType type;

            Shader()
            {
                last_modified_time      = std::chrono::high_resolution_clock::now();
                successful_last_compile = false;
                type                    = OpenGL::ShaderType::Unknown;
            }
        } Shader;

        /* Private functions */

        GLShaderManager();

        const Shader* get_shader_ptr(const GLuint& in_id) const;
        Shader*       get_shader_ptr(const GLuint& in_id);

        /* Private variables */
    };
}
#endif /* VKGL_GL_SHADER_MANAGER_H */