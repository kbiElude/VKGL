/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/backend/vk_gfx_pipeline_manager.h"


OpenGL::VKGFXPipelineManager::VKGFXPipelineManager(IBackend* in_backend_ptr)
    :m_backend_ptr(in_backend_ptr)
{
    /* Stub */
}

OpenGL::VKGFXPipelineManager::~VKGFXPipelineManager()
{
    /* Stub */
}

OpenGL::VKGFXPipelineManagerUniquePtr OpenGL::VKGFXPipelineManager::create(IBackend* in_backend_ptr)
{
    OpenGL::VKGFXPipelineManagerUniquePtr result_ptr;

    result_ptr.reset(new VKGFXPipelineManager(in_backend_ptr) );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}
