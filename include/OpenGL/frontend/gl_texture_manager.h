/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEXTURE_MANAGER_H
#define VKGL_GL_TEXTURE_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLTextureManager> GLTextureManagerUniquePtr;

    class GLTextureManager : public GLObjectManager<GLTextureReference, GLTextureReferenceUniquePtr>
    {
    public:
        /* Public functions */

        static GLTextureManagerUniquePtr create(const IGLLimits* in_limits_ptr);

        void get_texture_level_parameter(const GLuint&                       in_id,
                                         const int32_t&                      in_level,
                                         const OpenGL::TextureLevelProperty& in_pname,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         void*                               out_params_ptr) const;
        void get_texture_parameter      (const GLuint&                       in_id,
                                         const OpenGL::TextureProperty&      in_property,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         void*                               out_arg_value_ptr) const;
        void set_texture_parameter      (const GLuint&                       in_id,
                                         const OpenGL::TextureProperty&      in_property,
                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                         const void*                         in_arg_value_ptr);
        void set_texture_mip_properties (const GLuint&                       in_id,
                                         const int32_t&                      in_level,
                                         const OpenGL::InternalFormat&       in_internalformat,
                                         const uint32_t&                     in_width,
                                         const uint32_t&                     in_height,
                                         const uint32_t&                     in_depth,
                                         const int32_t&                      in_border,
                                         const uint32_t&                     in_n_samples,
                                         const bool&                         in_fixed_sample_locations);

        void on_texture_bound_to_target(const GLuint&                in_id,
                                        const OpenGL::TextureTarget& in_target);

        ~GLTextureManager();

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr)     final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr) final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                       final;

    private:
        /* Private type definitions */

        typedef uint32_t                              LayerIndex;
        typedef std::vector<TextureMipStateUniquePtr> Mips;
        typedef std::unique_ptr<Mips>                 MipsUniquePtr;

        typedef struct Texture
        {
            std::map<LayerIndex, MipsUniquePtr> layer_data;
            TextureStateUniquePtr               state_ptr;
            OpenGL::TextureTarget               texture_target;

            void set_from_texture_ptr(const Texture* in_texture_ptr);

            Texture           ()                          = default;
            Texture           (const Texture& in_texture);
            Texture& operator=(const Texture& in_texture);
        } Texture;

        /* Private functions */

        GLTextureManager(const IGLLimits* in_limits_ptr);

        const Texture* get_texture_ptr(const GLuint&             in_id,
                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        Texture*       get_texture_ptr(const GLuint&             in_id,
                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */
        const IGLLimits* const                                                  m_limits_ptr;
        std::unordered_map<OpenGL::TextureProperty, OpenGL::GetSetArgumentType> m_property_to_base_type;
    };
}
#endif /* VKGL_GL_TEXTURE_MANAGER_H */