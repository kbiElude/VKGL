/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_framebuffer_manager.h"

OpenGL::VKFramebufferManager::VKFramebufferManager(IBackend* in_backend_ptr)
    :m_backend_ptr(in_backend_ptr)
{
    vkgl_assert(in_backend_ptr != nullptr);
}

OpenGL::VKFramebufferManager::~VKFramebufferManager()
{
    /* Stub for now */
}

OpenGL::VKFramebufferManagerUniquePtr OpenGL::VKFramebufferManager::create(IBackend* in_backend_ptr)
{
    OpenGL::VKFramebufferManagerUniquePtr result_ptr;

    result_ptr.reset(new VKFramebufferManager(in_backend_ptr) );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}
