/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_H
#define VKGL_TYPES_H

#include "Khronos/GL/glcorearb.h"
#include <stdint.h>
#include <memory>
#include <unordered_map>
#include <vector>

#define VKGL_APIENTRY KHRONOS_APIENTRY

namespace OpenGL
{
    /* Forward declarations */
    class Context;
    class GLLimits;
    class GLStateManager;
    class GLTextureManager;
    class IGLLimits;
    class Scheduler;
}

#include "OpenGL/types_enums.h"
#include "OpenGL/types_typedefs.h"
#include "OpenGL/types_structs.h"
#include "OpenGL/types_interfaces.h"

#endif /* VKGL_TYPES_H */