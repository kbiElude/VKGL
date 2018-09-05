/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/gl_texture_manager.h"

OpenGL::GLTextureManager::GLTextureManager(const IGLLimits* in_limits_ptr)
    :m_limits_ptr(in_limits_ptr)
{
    vkgl_assert(in_limits_ptr != nullptr);
}

OpenGL::GLTextureManager::~GLTextureManager()
{
    /* Stub */
}

OpenGL::GLTextureManagerUniquePtr OpenGL::GLTextureManager::create(const OpenGL::IGLLimits* in_limits_ptr)
{
    OpenGL::GLTextureManagerUniquePtr result_ptr;

    result_ptr.reset(
        new GLTextureManager(in_limits_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return std::move(result_ptr);
}

bool OpenGL::GLTextureManager::delete_ids(const uint32_t& in_n_ids,
                                          const GLuint*   in_ids_ptr)
{
    vkgl_assert(m_id_manager_ptr != nullptr);

    m_id_manager_ptr->release(in_n_ids,
                              in_ids_ptr);

    return true;
}

bool OpenGL::GLTextureManager::generate_ids(const uint32_t& in_n_ids,
                                            GLuint*         out_ids_ptr)
{
    vkgl_assert(m_id_manager_ptr != nullptr);

    m_id_manager_ptr->allocate(in_n_ids,
                               out_ids_ptr);

    return true;
}

void OpenGL::GLTextureManager::get_texture_level_parameter(const int32_t&                      in_level,
                                                           const OpenGL::TextureLevelProperty& in_pname,
                                                           const OpenGL::GetSetArgumentType&   in_arg_type,
                                                           void*                               out_params_ptr) const
{
    todo;
}

void OpenGL::GLTextureManager::get_texture_parameter(const OpenGL::TextureProperty&    in_property,
                                                     const OpenGL::GetSetArgumentType& in_arg_type,
                                                     void*                             out_arg_value_ptr) const
{
    todo;
}

bool OpenGL::GLTextureManager::is_alive_id(const GLuint& in_id) const
{
    vkgl_assert(m_id_manager_ptr != nullptr);

    return m_id_manager_ptr->is_alive_id(in_id);
}

bool OpenGL::GLTextureManager::init()
{
    m_id_manager_ptr.reset(
        new OpenGL::Namespace()
    );

    vkgl_assert(m_id_manager_ptr != nullptr);
    return (m_id_manager_ptr != nullptr);
}

void OpenGL::GLTextureManager::set_texture_parameter(const OpenGL::TextureProperty&    in_property,
                                                     const OpenGL::GetSetArgumentType& in_arg_type,
                                                     const void*                       in_arg_value_ptr)
{
    todo;
}
