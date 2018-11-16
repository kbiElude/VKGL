/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_FRAMEBUFFER_MANAGER_H
#define VKGL_VK_FRAMEBUFFER_MANAGER_H

#include "Common/shared_mutex.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    class VKFramebufferManager
    {
    public:
        /* Public functions */
        static VKFramebufferManagerUniquePtr create(IBackend* in_backend_ptr);

        ~VKFramebufferManager();

    private:
        /* Private functions */
        VKFramebufferManager(IBackend* in_backend_ptr);

        /* Private variables */
        IBackend* const m_backend_ptr;
    };
}
#endif /* VKGL_VK_FRAMEBUFFER_MANAGER_H */
