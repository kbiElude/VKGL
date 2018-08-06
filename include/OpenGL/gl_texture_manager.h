/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEXTURE_MANAGER_H
#define VKGL_GL_TEXTURE_MANAGER_H

#include "OpenGL/namespace.h"
#include "OpenGL/types.h"

namespace VKGL
{
    typedef std::unique_ptr<GLTextureManager> GLTextureManagerUniquePtr;

    class GLTextureManager
    {
    public:
        /* Public functions */

        static GLTextureManagerUniquePtr create(const IGLLimits* in_limits_ptr);

        void get_texture_level_parameter(const int32_t&                    in_level,
                                         const VKGL::TextureLevelProperty& in_pname,
                                         const VKGL::GetSetArgumentType&   in_arg_type,
                                         void*                             out_params_ptr) const;
        void get_texture_parameter      (const VKGL::TextureProperty&      in_property,
                                         const VKGL::GetSetArgumentType&   in_arg_type,
                                         void*                             out_arg_value_ptr) const;
        void set_texture_parameter      (const VKGL::TextureProperty&      in_property,
                                         const VKGL::GetSetArgumentType&   in_arg_type,
                                         const void*                       in_arg_value_ptr);

        bool delete_ids  (const uint32_t& in_n_ids,
                          const GLuint*   in_ids_ptr);
        bool generate_ids(const uint32_t& in_n_ids,
                          GLuint*         out_ids_ptr);
        bool is_alive_id (const GLuint&   in_id)       const;

        ~GLTextureManager();

    private:
        /* Private type definitions */

        typedef uint32_t                                LayerIndex;
        typedef std::vector<TextureImageStateUniquePtr> Mips;

        typedef struct TextureData
        {
            std::unordered_map<LayerIndex, Mips> layer_data;
            TextureStateUniquePtr                state_ptr;
        } TextureData;

        /* Private functions */

        GLTextureManager(const IGLLimits* in_limits_ptr);

        bool init();

        /* Private variables */
        VKGL::NamespaceUniquePtr m_id_manager_ptr;
        const IGLLimits* const   m_limits_ptr;
    };
}
#endif /* VKGL_GL_TEXTURE_MANAGER_H */