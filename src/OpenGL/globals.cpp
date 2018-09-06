/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/globals.h"
#include <GL/gl.h>

VKGL_THREADLOCAL OpenGL::DispatchTable* OpenGL::g_dispatch_table_ptr = nullptr;

void* OpenGL::g_cached_gl_bind_texture              = glBindTexture;
void* OpenGL::g_cached_gl_clear                     = glClear;
void* OpenGL::g_cached_gl_clear_color               = glClearColor;
void* OpenGL::g_cached_gl_clear_depth               = glClearDepth;
void* OpenGL::g_cached_gl_clear_stencil             = glClearStencil;
void* OpenGL::g_cached_gl_color_mask                = glColorMask;
void* OpenGL::g_cached_gl_copy_tex_image_1d         = glCopyTexImage1D;
void* OpenGL::g_cached_gl_copy_tex_image_2d         = glCopyTexImage2D;
void* OpenGL::g_cached_gl_copy_tex_sub_image_1d     = glCopyTexSubImage1D;
void* OpenGL::g_cached_gl_copy_tex_sub_image_2d     = glCopyTexSubImage2D;
void* OpenGL::g_cached_gl_cull_face                 = glCullFace;
void* OpenGL::g_cached_gl_delete_textures           = glDeleteTextures;
void* OpenGL::g_cached_gl_depth_func                = glDepthFunc;
void* OpenGL::g_cached_gl_depth_mask                = glDepthMask;
void* OpenGL::g_cached_gl_depth_range               = glDepthRange;
void* OpenGL::g_cached_gl_disable                   = glDisable;
void* OpenGL::g_cached_gl_draw_arrays               = glDrawArrays;
void* OpenGL::g_cached_gl_draw_buffer               = glDrawBuffer;
void* OpenGL::g_cached_gl_draw_elements             = glDrawElements;
void* OpenGL::g_cached_gl_enable                    = glEnable;
void* OpenGL::g_cached_gl_finish                    = glFinish;
void* OpenGL::g_cached_gl_flush                     = glFlush;
void* OpenGL::g_cached_gl_front_face                = glFrontFace;
void* OpenGL::g_cached_gl_gen_textures              = glGenTextures;
void* OpenGL::g_cached_gl_get_booleanv              = glGetBooleanv;
void* OpenGL::g_cached_gl_get_doublev               = glGetDoublev;
void* OpenGL::g_cached_gl_get_error                 = glGetError;
void* OpenGL::g_cached_gl_get_floatv                = glGetFloatv;
void* OpenGL::g_cached_gl_get_integerv              = glGetIntegerv;
void* OpenGL::g_cached_gl_get_string                = glGetString;
void* OpenGL::g_cached_gl_get_tex_image             = glGetTexImage;
void* OpenGL::g_cached_gl_get_tex_level_parameterfv = glGetTexLevelParameterfv;
void* OpenGL::g_cached_gl_get_tex_level_parameteriv = glGetTexLevelParameteriv;
void* OpenGL::g_cached_gl_get_tex_parameterfv       = glGetTexParameterfv;
void* OpenGL::g_cached_gl_get_tex_parameteriv       = glGetTexParameteriv;
void* OpenGL::g_cached_gl_hint                      = glHint;
void* OpenGL::g_cached_gl_is_enabled                = glIsEnabled;
void* OpenGL::g_cached_gl_is_texture                = glIsTexture;
void* OpenGL::g_cached_gl_line_width                = glLineWidth;
void* OpenGL::g_cached_gl_logic_op                  = glLogicOp;
void* OpenGL::g_cached_gl_pixel_storef              = glPixelStoref;
void* OpenGL::g_cached_gl_pixel_storei              = glPixelStorei;
void* OpenGL::g_cached_gl_point_size                = glPointSize;
void* OpenGL::g_cached_gl_polygon_mode              = glPolygonMode;
void* OpenGL::g_cached_gl_polygon_offset            = glPolygonOffset;
void* OpenGL::g_cached_gl_read_buffer               = glReadBuffer;
void* OpenGL::g_cached_gl_read_pixels               = glReadPixels;
void* OpenGL::g_cached_gl_scissor                   = glScissor;
void* OpenGL::g_cached_gl_stencil_func              = glStencilFunc;
void* OpenGL::g_cached_gl_stencil_mask              = glStencilMask;
void* OpenGL::g_cached_gl_stencil_op                = glStencilOp;
void* OpenGL::g_cached_gl_tex_image_1d              = glTexImage1D;
void* OpenGL::g_cached_gl_tex_image_2d              = glTexImage2D;
void* OpenGL::g_cached_gl_tex_parameterf            = glTexParameterf;
void* OpenGL::g_cached_gl_tex_parameterfv           = glTexParameterfv;
void* OpenGL::g_cached_gl_tex_parameteri            = glTexParameteri;
void* OpenGL::g_cached_gl_tex_parameteriv           = glTexParameteriv;
void* OpenGL::g_cached_gl_tex_sub_image_1d          = glTexSubImage1D;
void* OpenGL::g_cached_gl_tex_sub_image_2d          = glTexSubImage2D;
void* OpenGL::g_cached_gl_viewport_func_ptr         = glViewport;