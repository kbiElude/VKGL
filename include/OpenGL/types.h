/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_H
#define VKGL_TYPES_H

#include "Khronos/GL/glcorearb.h"
#include <stdint.h>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#define VKGL_APIENTRY KHRONOS_APIENTRY

#include "OpenGL/types_enums.h"

namespace OpenGL
{
    /* Forward declarations */
    class Context;
    class GLLimits;
    class GLReference;
    class GLShaderManager;
    class GLStateManager;
    class GLTextureManager;
    class GLVAOManager;
    class IGLLimits;
    class IGLObjectManager;
    class Scheduler;

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