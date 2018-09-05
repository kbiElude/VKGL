/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef OPENGL_GLOBALS_H
#define OPENGL_GLOBALS_H

#include "Common/globals.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    extern VKGL_THREADLOCAL OpenGL::DispatchTable* g_dispatch_table_ptr;

    /* NOTE: opengl32.dll only exposes <=GL1.1 entrypoints. We discard the compatibility
     *       entrypoints and only reroute funcs implemented by the library
     */
    extern void* g_cached_gl_bind_texture;
    extern void* g_cached_gl_clear;
    extern void* g_cached_gl_clear_color;
    extern void* g_cached_gl_clear_depth;
    extern void* g_cached_gl_clear_stencil;
    extern void* g_cached_gl_color_mask;
    extern void* g_cached_gl_copy_tex_image_1d;
    extern void* g_cached_gl_copy_tex_image_2d;
    extern void* g_cached_gl_copy_tex_sub_image_1d;
    extern void* g_cached_gl_copy_tex_sub_image_2d;
    extern void* g_cached_gl_cull_face;
    extern void* g_cached_gl_delete_textures;
    extern void* g_cached_gl_depth_func;
    extern void* g_cached_gl_depth_mask;
    extern void* g_cached_gl_depth_range;
    extern void* g_cached_gl_disable;
    extern void* g_cached_gl_draw_arrays;
    extern void* g_cached_gl_draw_buffer;
    extern void* g_cached_gl_draw_elements;
    extern void* g_cached_gl_enable;
    extern void* g_cached_gl_finish;
    extern void* g_cached_gl_flush;
    extern void* g_cached_gl_front_face;
    extern void* g_cached_gl_gen_textures;
    extern void* g_cached_gl_get_booleanv;
    extern void* g_cached_gl_get_doublev;
    extern void* g_cached_gl_get_error;
    extern void* g_cached_gl_get_floatv;
    extern void* g_cached_gl_get_integerv;
    extern void* g_cached_gl_get_string;
    extern void* g_cached_gl_get_tex_image;
    extern void* g_cached_gl_get_tex_level_parameterfv;
    extern void* g_cached_gl_get_tex_level_parameteriv;
    extern void* g_cached_gl_get_tex_parameterfv;
    extern void* g_cached_gl_get_tex_parameteriv;
    extern void* g_cached_gl_hint;
    extern void* g_cached_gl_is_enabled;
    extern void* g_cached_gl_is_texture;
    extern void* g_cached_gl_line_width;
    extern void* g_cached_gl_logic_op;
    extern void* g_cached_gl_pixel_storef;
    extern void* g_cached_gl_pixel_storei;
    extern void* g_cached_gl_point_size;
    extern void* g_cached_gl_polygon_mode;
    extern void* g_cached_gl_polygon_offset;
    extern void* g_cached_gl_read_buffer;
    extern void* g_cached_gl_read_pixels;
    extern void* g_cached_gl_scissor;
    extern void* g_cached_gl_stencil_func;
    extern void* g_cached_gl_stencil_mask;
    extern void* g_cached_gl_stencil_op;
    extern void* g_cached_gl_tex_image_1d;
    extern void* g_cached_gl_tex_image_2d;
    extern void* g_cached_gl_tex_parameterf;
    extern void* g_cached_gl_tex_parameterfv;
    extern void* g_cached_gl_tex_parameteri;
    extern void* g_cached_gl_tex_parameteriv;
    extern void* g_cached_gl_tex_sub_image_1d;
    extern void* g_cached_gl_tex_sub_image_2d;
    extern void* g_cached_gl_viewport_func_ptr;
}

#endif /* OPENGL_GLOBALS_H */