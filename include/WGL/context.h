/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef WGL_CONTEXT_H
#define WGL_CONTEXT_H

#include "vkgl_config.h"
#include "Common/types.h"

#if !defined(VKGL_INCLUDE_OPENGL)
    #error WGL requires OpenGL component for successful compilation
#else
    #include "OpenGL/backend/vk_backend.h"
    #include "OpenGL/context.h"
    #include "OpenGL/types.h"
#endif

#include <stdint.h>
#include <windows.h>

namespace WGL
{
    class Context : public VKGL::IWSIContext
    {
    public:
        /* Public functions */

        static Context* create(const HDC&     in_hdc,
                               const Context* in_opt_share_context_ptr,
                               const int*     in_attribute_list_ptr);

        ~Context();

        const OpenGL::Context* get_gl_context_ptr() const
        {
            return m_gl_context_ptr.get();
        }

        OpenGL::Context* get_gl_context_ptr()
        {
            return m_gl_context_ptr.get();
        }

        const VKGL::PixelFormatRequirements& get_pixel_format_requirements() const
        {
            return m_pixel_format_reqs;
        }

        const int& get_swap_interval() const
        {
            return m_swap_interval;
        }

        OpenGL::IBackend* get_vk_backend_ptr()
        {
            return m_vk_backend_ptr.get();
        }

        const bool& is_debug_context() const
        {
            return m_is_debug_context;
        }

        const bool& is_forward_compatible_context() const
        {
            return m_is_forward_compatible_context;
        }

        const HDC& get_current_hdc() const
        {
            return m_current_hdc;
        }

        const uint32_t& get_major_version() const
        {
            return m_major_version;
        }

        const uint32_t& get_minor_version() const
        {
            return m_minor_version;
        }

        const uint32_t& get_n_layer_plane() const
        {
            return m_n_layer_plane;
        }

        void set_current_hdc(const HDC& in_hdc);

        void set_swap_interval(const int& in_swap_interval)
        {
            m_swap_interval = in_swap_interval;
        }

    private:
        /* Private functions */
        Context();

        bool init           (const HDC&     in_hdc,
                             const Context* in_share_context_ptr,
                             const int*     in_attribute_list_ptr);
        bool init_gl_context();

        /* Private variables */

        OpenGL::ContextUniquePtr   m_gl_context_ptr;
        OpenGL::VKBackendUniquePtr m_vk_backend_ptr;

        HDC                           m_current_hdc;
        bool                          m_is_debug_context;
        bool                          m_is_forward_compatible_context;
        uint32_t                      m_major_version;
        uint32_t                      m_minor_version;
        uint32_t                      m_n_layer_plane;
        VKGL::PixelFormatRequirements m_pixel_format_reqs;
        int                           m_swap_interval;
    };

    /* Globally available funcs */
    extern Context* get_wgl_context_for_hdc(HDC);
}

#endif /* WGL_CONTEXT_H */