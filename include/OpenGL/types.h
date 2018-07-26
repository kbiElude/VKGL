#ifndef VKGL_TYPES_H
#define VKGL_TYPES_H

#include "Khronos/GL/glcorearb.h"


#if defined(_WIN32)
    #define VKGL_API __declspec(dllexport)
#else
    #define VKGL_API
#endif

#define VKGL_APIENTRY KHRONOS_APIENTRY


namespace VKGL
{

};

#endif /* VKGL_TYPES_H */