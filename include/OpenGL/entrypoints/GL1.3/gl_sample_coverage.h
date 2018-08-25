/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_SAMPLE_COVERAGE_H
#define VKGL_GL_SAMPLE_COVERAGE_H

#include "OpenGL/types.h"

void VKGL_APIENTRY vkglSampleCoverage(GLfloat   value,
                                      GLboolean invert);

void vkglSampleCoverage_with_validation(VKGL::Context*   in_context_ptr,
                                        const GLfloat&   in_value,
                                        const GLboolean& in_invert);

#endif /* VKGL_GL_ACTIVE_TEXTURE_H */