/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/globals.h"
#include <GL/gl.h>

VKGL_THREADLOCAL OpenGL::DispatchTable* g_dispatch_table_ptr = nullptr;

void* g_cached_gl_bind_texture              = glBindTexture;
void* g_cached_gl_clear                     = glClear;
void* g_cached_gl_clear_color               = glClearColor;
void* g_cached_gl_clear_depth               = glClearDepth;
void* g_cached_gl_clear_stencil             = glClearStencil;
void* g_cached_gl_color_mask                = glColorMask;
void* g_cached_gl_copy_tex_image_1d         = glCopyTexImage1D;
void* g_cached_gl_copy_tex_image_2d         = glCopyTexImage2D;
void* g_cached_gl_copy_tex_sub_image_1d     = glCopyTexSubImage1D;
void* g_cached_gl_copy_tex_sub_image_2d     = glCopyTexSubImage2D;
void* g_cached_gl_cull_face                 = glCullFace;
void* g_cached_gl_delete_textures           = glDeleteTextures;
void* g_cached_gl_depth_func                = glDepthFunc;
void* g_cached_gl_depth_mask                = glDepthMask;
void* g_cached_gl_depth_range               = glDepthRange;
void* g_cached_gl_disable                   = glDisable;
void* g_cached_gl_draw_arrays               = glDrawArrays;
void* g_cached_gl_draw_buffer               = glDrawBuffer;
void* g_cached_gl_draw_elements             = glDrawElements;
void* g_cached_gl_enable                    = glEnable;
void* g_cached_gl_finish                    = glFinish;
void* g_cached_gl_flush                     = glFlush;
void* g_cached_gl_front_face                = glFrontFace;
void* g_cached_gl_gen_textures              = glGenTextures;
void* g_cached_gl_get_booleanv              = glGetBooleanv;
void* g_cached_gl_get_doublev               = glGetDoublev;
void* g_cached_gl_get_error                 = glGetError;
void* g_cached_gl_get_floatv                = glGetFloatv;
void* g_cached_gl_get_integerv              = glGetIntegerv;
void* g_cached_gl_get_string                = glGetString;
void* g_cached_gl_get_tex_image             = glGetTexImage;
void* g_cached_gl_get_tex_level_parameterfv = glGetTexLevelParameterfv;
void* g_cached_gl_get_tex_level_parameteriv = glGetTexLevelParameteriv;
void* g_cached_gl_get_tex_parameterfv       = glGetTexParameterfv;
void* g_cached_gl_get_tex_parameteriv       = glGetTexParameteriv;
void* g_cached_gl_hint                      = glHint;
void* g_cached_gl_is_enabled                = glIsEnabled;
void* g_cached_gl_is_texture                = glIsTexture;
void* g_cached_gl_line_width                = glLineWidth;
void* g_cached_gl_logic_op                  = glLogicOp;
void* g_cached_gl_pixel_storef              = glPixelStoref;
void* g_cached_gl_pixel_storei              = glPixelStorei;
void* g_cached_gl_point_size                = glPointSize;
void* g_cached_gl_polygon_mode              = glPolygonMode;
void* g_cached_gl_polygon_offset            = glPolygonOffset;
void* g_cached_gl_read_buffer               = glReadBuffer;
void* g_cached_gl_read_pixels               = glReadPixels;
void* g_cached_gl_scissor                   = glScissor;
void* g_cached_gl_stencil_func              = glStencilFunc;
void* g_cached_gl_stencil_mask              = glStencilMask;
void* g_cached_gl_stencil_op                = glStencilOp;
void* g_cached_gl_tex_image_1d              = glTexImage1D;
void* g_cached_gl_tex_image_2d              = glTexImage2D;
void* g_cached_gl_tex_parameterf            = glTexParameterf;
void* g_cached_gl_tex_parameterfv           = glTexParameterfv;
void* g_cached_gl_tex_parameteri            = glTexParameteri;
void* g_cached_gl_tex_parameteriv           = glTexParameteriv;
void* g_cached_gl_tex_sub_image_1d          = glTexSubImage1D;
void* g_cached_gl_tex_sub_image_2d          = glTexSubImage2D;
void* g_cached_gl_viewport_func_ptr         = glViewport;