/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SAMPLE_MASKI_H
#define VKGL_GL_SAMPLE_MASKI_H

#include "OpenGL/types.h"

namespace OpenGL
{
    void VKGL_APIENTRY vkglSampleMaski(GLuint     maskNumber,
                                       GLbitfield mask);

    void vkglSampleMaski_with_validation(OpenGL::Context*  in_context_ptr,
                                         const GLuint&     in_mask_number,
                                         const GLbitfield& in_mask);
}

#endif /* VKGL_GL_SAMPLE_MASKI_H */