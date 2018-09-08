/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_CONSTANTS_H
#define VKGL_GL_CONSTANTS_H

#include "OpenGL/types.h"

namespace OpenGL
{
    class GLConstants : public OpenGL::IGLConstants
    {
    public:
         GLConstants(const IContext* in_context_ptr);
        ~GLConstants();

        void get_parameter        (const OpenGL::ContextProperty&    in_pname,
                                   const OpenGL::GetSetArgumentType& in_arg_type,
                                   void*                             out_arg_value_ptr) const;
        void get_parameter_indexed(const OpenGL::ContextProperty&    in_pname,
                                   const OpenGL::GetSetArgumentType& in_arg_type,
                                   const uint32_t&                   in_index,
                                   void*                             out_arg_value_ptr) const;

        /* IGLConstants interface impl */
        const uint32_t& get_context_flags() const final
        {
            return m_context_flags;
        }

        const uint32_t& get_context_profile_mask() const final
        {
            return m_context_profile_mask;
        }

        const char* get_extensions() const final
        {
            return m_extensions.c_str();
        }

        const uint32_t& get_major_version() const final
        {
            return m_major_version;
        }

        const uint32_t& get_minor_version() const final
        {
            return m_minor_version;
        }

        const char* get_renderer() const final
        {
            return m_renderer.c_str();
        }

        const char* get_shading_language_version() const final
        {
            return m_shading_language_version.c_str();
        }

        const char* get_vendor() const final
        {
            return m_vendor.c_str();
        }

    private:
        /* Private type definitions */

        /* Private functions */

        void init_extension_constants();

        /* Private variables */
        uint32_t    m_context_flags;
        uint32_t    m_context_profile_mask;
        std::string m_extensions;
        uint32_t    m_major_version;
        uint32_t    m_minor_version;
        uint32_t    m_n_extensions;
        std::string m_renderer;
        std::string m_shading_language_version;
        std::string m_vendor;
        std::string m_version;

        const IContext*                  m_context_ptr;
        IndexedPropertyToArgumentTypeMap m_indexed_prop_map;
        PropertyToArgumentTypeMap        m_prop_map;
    };

    typedef std::unique_ptr<GLConstants> GLConstantsUniquePtr;
}

#endif /* VKGL_GL_CONSTANTS_H */