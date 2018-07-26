#ifndef VKGL_GL_TEX_IMAGE_2D_MULTISAMPLE_H
#define VKGL_GL_TEX_IMAGE_2D_MULTISAMPLE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glTexImage2DMultisample(GLenum    target,
                                                    GLsizei   samples,
                                                    GLenum    internalformat,
                                                    GLsizei   width,
                                                    GLsizei   height,
                                                    GLboolean fixedsamplelocations);

#endif /* VKGL_GL_TEX_IMAGE_2D_MULTISAMPLE_H */