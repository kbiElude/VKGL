/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/logger.h"
#include "Common/macros.h"
#include "GDI32/globals.h"
#include "Khronos/GL/glcorearb.h"
#include "Khronos/GL/wglext.h"
#include "OpenGL/backend/vk_backend.h"
#include "WGL/context.h"
#include "WGL/globals.h"

WGL::Context::Context()
    :m_current_hdc                  (nullptr),
     m_is_debug_context             (false),
     m_is_forward_compatible_context(false),
     m_n_layer_plane                (0),
     m_major_version                (1),
     m_minor_version                (0),
     m_swap_interval                (1)
{
    memset(&m_pixel_format_descriptor,
           0,
           sizeof(m_pixel_format_descriptor) );
}

WGL::Context::~Context()
{
    /* Stub */
}

WGL::Context* WGL::Context::create(const HDC&     in_hdc,
                                   const Context* in_opt_share_context_ptr,
                                   const int*     in_attribute_list_ptr)
{
    WGL::Context* result_ptr;

    result_ptr = new WGL::Context();

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init(in_hdc,
                              in_opt_share_context_ptr,
                              in_attribute_list_ptr) )
        {
            /* TODO: An error code corresponding to the reason behind the failure should be exposed via Kernel32.dll::GetLastError() */
            vkgl_assert_fail();

            delete result_ptr;
            result_ptr = nullptr;
        }
    }

    return result_ptr;
}

bool WGL::Context::init(const HDC&     in_hdc,
                        const Context* in_share_context_ptr,
                        const int*     in_attribute_list_ptr)
{
    const int* attribute_list_traveller_ptr = in_attribute_list_ptr;
    uint32_t   pixel_format_index           = UINT32_MAX;
    bool       result                       = true;

    pixel_format_index = reinterpret_cast<GDI32::PFNGETPIXELFORMATPROC>(GDI32::g_cached_get_pixel_format_func_ptr)(in_hdc);
    if (pixel_format_index == 0)
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "Could not retrieve pixel format index for the specified HDC.");

        vkgl_assert_fail();

        result = false;
        goto end;
    }

    if (reinterpret_cast<GDI32::PFNDESCRIBEPIXELFORMATPROC>(GDI32::g_cached_describe_pixel_format_func_ptr)(in_hdc,
                                                                                                            pixel_format_index,
                                                                                                            sizeof(PIXELFORMATDESCRIPTOR),
                                                                                                           &m_pixel_format_descriptor) == 0)
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "Failed to retrieve pixel format properties for the specified HDC.");

        vkgl_assert_fail();

        result = false;
        goto end;
    }

    if (attribute_list_traveller_ptr == nullptr)
    {
        /* Most likely a trampoline context. Assume success. */
        goto end;
    }

    while ( attribute_list_traveller_ptr != nullptr &&
           *attribute_list_traveller_ptr != 0)
    {
        const auto attribute_name  = * attribute_list_traveller_ptr;
        const auto attribute_value = *(attribute_list_traveller_ptr + 1);

        switch (attribute_name)
        {
            case WGL_CONTEXT_LAYER_PLANE_ARB:
            {
                m_n_layer_plane = attribute_value;

                break;
            }

            case WGL_CONTEXT_MAJOR_VERSION_ARB:
            {
                m_major_version = attribute_value;

                break;
            }

            case WGL_CONTEXT_MINOR_VERSION_ARB:
            {
                m_minor_version = attribute_value;

                break;
            }

            case WGL_CONTEXT_FLAGS_ARB:
            {
                m_is_debug_context              |= (attribute_value & WGL_CONTEXT_DEBUG_BIT_ARB)              != 0;
                m_is_forward_compatible_context |= (attribute_value & WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB) != 0;

                break;
            }

            case WGL_CONTEXT_PROFILE_MASK_ARB:
            {
                if (attribute_value != WGL_CONTEXT_CORE_PROFILE_BIT_ARB)
                {
                    VKGL_LOG(VKGL::LogLevel::Error,
                             "VKGL does not support OpenGL profiles other than core.");

                    vkgl_assert_fail();

                    result = false;
                    goto end;
                }

                break;
            }

            default:
            {
                VKGL_LOG(VKGL::LogLevel::Error,
                         "Unrecognized attribute name [%d] was specific at WGL context creation time!",
                          attribute_name);

                vkgl_assert_fail();

                result = false;
                goto end;
            }
        }

        /* Move on */
        attribute_list_traveller_ptr += 2 /* name, value */;
    }

    /* Sanity checks */
    if ((m_major_version != 3) ||
        (m_minor_version != 0  &&
         m_minor_version != 1  &&
         m_minor_version != 2) )
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "The application requested an unsupported OpenGL context version (%d.%d)",
                 m_major_version,
                 m_minor_version);

        result = false;
        goto end;
    }

    if (m_n_layer_plane != 0)
    {
        VKGL_LOG(VKGL::LogLevel::Error,
                 "Non-zero layer planes are not supported by VKGL");

        result = false;
        goto end;
    }

    if (m_is_forward_compatible_context)
    {
        m_major_version = 3;
        m_minor_version = 2;
    }
    else
    {
        VKGL_LOG(VKGL::LogLevel::Warning,
                 "Non-forward-compatible GL context was requested: VKGL does not prevent apps from using deprecated functionality.");
    }

end:
    vkgl_assert(result);

    result = init_gl_context();
    vkgl_assert(result);

    return result;
}

bool WGL::Context::init_gl_context()
{
    bool result = false;

    /* First, spawn a Vulkan backend instance we're going to use to translate all the GL calls to */
    m_vk_backend_ptr = OpenGL::VKBackend::create();

    if (m_vk_backend_ptr == nullptr)
    {
        vkgl_assert(m_vk_backend_ptr != nullptr);

        goto end;
    }

    /* Good to create the GL context instance, now that we have a functional backend instance. */
    m_gl_context_ptr = OpenGL::Context::create(reinterpret_cast<VKGL::IWSIContext*>      (this),
                                               dynamic_cast<OpenGL::IBackendGLCallbacks*>(m_vk_backend_ptr.get() ));

    if (m_gl_context_ptr == nullptr)
    {
        vkgl_assert(m_gl_context_ptr != nullptr);

        goto end;
    }

    result = true;
end:
    return result;
}