#ifndef VKGL_GL_GET_TEX_IMAGE_H
#define VKGL_GL_GET_TEX_IMAGE_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glGetTexImage(GLenum target,
                                          GLint  level,
                                          GLenum format,
                                          GLenum type,
                                          void*  pixels);

void vkglGetTexImage_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_target,
                                     const GLint&   in_level,
                                     const GLenum&  in_format,
                                     const GLenum&  in_type,
                                     void*          out_pixels_ptr);

#endif /* VKGL_GL_GET_TEX_IMAGE_H */