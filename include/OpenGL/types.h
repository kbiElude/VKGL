/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_H
#define VKGL_TYPES_H

#include "Khronos/GL/glcorearb.h"
#include <cstdint>
#include <chrono>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#define VKGL_APIENTRY KHRONOS_APIENTRY

#include "Common/types.h"
#include "OpenGL/types_enums.h"
#include "OpenGL/backend/vk_reference.h"
#include "OpenGL/frontend/gl_reference.h"

namespace OpenGL
{
    /* Forward declarations */
    class  Context;
    struct DispatchTable;
    class  GLBufferManager;
    class  GLFramebufferManager;
    class  GLLimits;
    class  GLProgramManager;
    class  GLRenderbufferManager;
    class  GLShaderManager;
    class  GLStateManager;
    class  GLTextureManager;
    class  GLVAOManager;
    class  IGLLimits;
    class  VKBackend;
    class  VKBufferManager;
    class  VKFormatManager;
    class  VKFrameGraph;
    class  VKScheduler;
    class  VKSPIRVManager;
    class  VKSwapchainManager;

    typedef std::unique_ptr<GLBufferReference,       std::function<void(GLBufferReference*)> >       GLBufferReferenceUniquePtr;
    typedef std::unique_ptr<GLContextStateReference, std::function<void(GLContextStateReference*)> > GLContextStateReferenceUniquePtr;
    typedef std::unique_ptr<GLFramebufferReference,  std::function<void(GLFramebufferReference*)> >  GLFramebufferReferenceUniquePtr;
    typedef std::unique_ptr<GLProgramReference,      std::function<void(GLProgramReference*)> >      GLProgramReferenceUniquePtr;
    typedef std::unique_ptr<GLRenderbufferReference, std::function<void(GLRenderbufferReference*)> > GLRenderbufferReferenceUniquePtr;
    typedef std::unique_ptr<GLShaderReference,       std::function<void(GLShaderReference*)> >       GLShaderReferenceUniquePtr;
    typedef std::unique_ptr<GLTextureReference,      std::function<void(GLTextureReference*)> >      GLTextureReferenceUniquePtr;
    typedef std::unique_ptr<GLVAOReference,          std::function<void(GLVAOReference*)> >          GLVAOReferenceUniquePtr;
    typedef std::unique_ptr<VKBackend>                                                               VKBackendUniquePtr;
    typedef std::unique_ptr<VKBufferReference,       std::function<void(VKBufferReference*)> >       VKBufferReferenceUniquePtr;
    typedef std::unique_ptr<VKFrameGraph,            std::function<void(VKFrameGraph*)> >            VKFrameGraphUniquePtr;
    typedef std::unique_ptr<VKScheduler>                                                             VKSchedulerUniquePtr;
    typedef std::unique_ptr<VKSPIRVManager>                                                          VKSPIRVManagerUniquePtr;
    typedef std::unique_ptr<VKSwapchainReference,    std::function<void(VKSwapchainReference*)> >    VKSwapchainReferenceUniquePtr;

    typedef struct PropertyData
    {
        const void*                data_ptr;
        uint32_t                   n_components;
        OpenGL::GetSetArgumentType type;

        PropertyData(const OpenGL::GetSetArgumentType& in_type,
                     const uint32_t&                   in_n_components,
                     const void*                       in_data_ptr)
            :data_ptr    (in_data_ptr),
             n_components(in_n_components),
             type        (in_type)
        {
            /* Stub */
        }
    } PropertyData;

    typedef struct IndexedPropertyData
    {
        std::vector<const void*>   data_ptrs;
        uint32_t                   n_components;
        OpenGL::GetSetArgumentType type;

        IndexedPropertyData()
            :n_components(UINT32_MAX),
             type        (OpenGL::GetSetArgumentType::Unknown)
        {
            /* Stub */
        }

        IndexedPropertyData(const OpenGL::GetSetArgumentType& in_type,
                            const uint32_t&                   in_n_components,
                            const std::vector<const void*>&   in_data_ptrs)
            :data_ptrs   (in_data_ptrs),
             n_components(in_n_components),
             type        (in_type)
        {
            /* Stub */
        }
    } IndexedPropertyData;

    typedef std::unordered_map<OpenGL::ContextProperty, IndexedPropertyData> IndexedPropertyToArgumentTypeMap;
    typedef std::unordered_map<OpenGL::ContextProperty, PropertyData>        PropertyToArgumentTypeMap;
}

#include "OpenGL/types_typedefs.h"
#include "OpenGL/types_structs.h"
#include "OpenGL/types_interfaces.h"

#endif /* VKGL_TYPES_H */