/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "Common/types.h"
#include "OpenGL/types.h"
#include "OpenGL/context.h"
#include "OpenGL/utils_enum.h"

#include "OpenGL/entrypoints/GL1.0/gl_blend_func.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear_color.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear_depth.h"
#include "OpenGL/entrypoints/GL1.0/gl_clear_stencil.h"
#include "OpenGL/entrypoints/GL1.0/gl_color_mask.h"
#include "OpenGL/entrypoints/GL1.0/gl_cull_face.h"
#include "OpenGL/entrypoints/GL1.0/gl_depth_func.h"
#include "OpenGL/entrypoints/GL1.0/gl_depth_mask.h"
#include "OpenGL/entrypoints/GL1.0/gl_depth_range.h"
#include "OpenGL/entrypoints/GL1.0/gl_disable.h"
#include "OpenGL/entrypoints/GL1.0/gl_draw_buffer.h"
#include "OpenGL/entrypoints/GL1.0/gl_enable.h"
#include "OpenGL/entrypoints/GL1.0/gl_finish.h"
#include "OpenGL/entrypoints/GL1.0/gl_flush.h"
#include "OpenGL/entrypoints/GL1.0/gl_front_face.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_booleanv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_doublev.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_error.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_floatv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_integerv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_string.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_image.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameterfv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_level_parameteriv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_parameterfv.h"
#include "OpenGL/entrypoints/GL1.0/gl_get_tex_parameteriv.h"
#include "OpenGL/entrypoints/GL1.0/gl_hint.h"
#include "OpenGL/entrypoints/GL1.0/gl_is_enabled.h"
#include "OpenGL/entrypoints/GL1.0/gl_line_width.h"
#include "OpenGL/entrypoints/GL1.0/gl_logic_op.h"
#include "OpenGL/entrypoints/GL1.0/gl_pixel_storef.h"
#include "OpenGL/entrypoints/GL1.0/gl_pixel_storei.h"
#include "OpenGL/entrypoints/GL1.0/gl_point_size.h"
#include "OpenGL/entrypoints/GL1.0/gl_polygon_mode.h"
#include "OpenGL/entrypoints/GL1.0/gl_read_buffer.h"
#include "OpenGL/entrypoints/GL1.0/gl_read_pixels.h"
#include "OpenGL/entrypoints/GL1.0/gl_scissor.h"
#include "OpenGL/entrypoints/GL1.0/gl_stencil_func.h"
#include "OpenGL/entrypoints/GL1.0/gl_stencil_mask.h"
#include "OpenGL/entrypoints/GL1.0/gl_stencil_op.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_image_1d.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_image_2d.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterf.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameterfv.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteri.h"
#include "OpenGL/entrypoints/GL1.0/gl_tex_parameteriv.h"
#include "OpenGL/entrypoints/GL1.0/gl_viewport.h"

#include "OpenGL/entrypoints/GL1.1/gl_bind_texture.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_1d.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_image_2d.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_1d.h"
#include "OpenGL/entrypoints/GL1.1/gl_copy_tex_sub_image_2d.h"
#include "OpenGL/entrypoints/GL1.1/gl_delete_textures.h"
#include "OpenGL/entrypoints/GL1.1/gl_draw_arrays.h"
#include "OpenGL/entrypoints/GL1.1/gl_draw_elements.h"
#include "OpenGL/entrypoints/GL1.1/gl_gen_textures.h"
#include "OpenGL/entrypoints/GL1.1/gl_is_texture.h"
#include "OpenGL/entrypoints/GL1.1/gl_polygon_offset.h"
#include "OpenGL/entrypoints/GL1.1/gl_tex_sub_image_1d.h"
#include "OpenGL/entrypoints/GL1.1/gl_tex_sub_image_2d.h"

#include "OpenGL/entrypoints/GL1.2/gl_copy_tex_sub_image_3d.h"
#include "OpenGL/entrypoints/GL1.2/gl_draw_range_elements.h"
#include "OpenGL/entrypoints/GL1.2/gl_tex_image_3d.h"
#include "OpenGL/entrypoints/GL1.2/gl_tex_sub_image_3d.h"

#include "OpenGL/entrypoints/GL1.3/gl_active_texture.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_1d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_2d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_image_3d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_1d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_2d.h"
#include "OpenGL/entrypoints/GL1.3/gl_compressed_tex_sub_image_3d.h"
#include "OpenGL/entrypoints/GL1.3/gl_get_compressed_tex_image.h"
#include "OpenGL/entrypoints/GL1.3/gl_sample_coverage.h"

#include "OpenGL/entrypoints/GL1.4/gl_blend_color.h"
#include "OpenGL/entrypoints/GL1.4/gl_blend_equation.h"
#include "OpenGL/entrypoints/GL1.4/gl_blend_func_separate.h"
#include "OpenGL/entrypoints/GL1.4/gl_multi_draw_arrays.h"
#include "OpenGL/entrypoints/GL1.4/gl_multi_draw_elements.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterf.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameterfv.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameteri.h"
#include "OpenGL/entrypoints/GL1.4/gl_point_parameteriv.h"

#include "OpenGL/entrypoints/GL1.5/gl_begin_query.h"
#include "OpenGL/entrypoints/GL1.5/gl_bind_buffer.h"
#include "OpenGL/entrypoints/GL1.5/gl_buffer_data.h"
#include "OpenGL/entrypoints/GL1.5/gl_buffer_sub_data.h"
#include "OpenGL/entrypoints/GL1.5/gl_delete_buffers.h"
#include "OpenGL/entrypoints/GL1.5/gl_delete_queries.h"
#include "OpenGL/entrypoints/GL1.5/gl_end_query.h"
#include "OpenGL/entrypoints/GL1.5/gl_gen_buffers.h"
#include "OpenGL/entrypoints/GL1.5/gl_gen_queries.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_parameteriv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_pointerv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_buffer_sub_data.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_queryiv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_query_objectiv.h"
#include "OpenGL/entrypoints/GL1.5/gl_get_query_objectuiv.h"
#include "OpenGL/entrypoints/GL1.5/gl_is_buffer.h"
#include "OpenGL/entrypoints/GL1.5/gl_is_query.h"
#include "OpenGL/entrypoints/GL1.5/gl_map_buffer.h"
#include "OpenGL/entrypoints/GL1.5/gl_unmap_buffer.h"

#include "OpenGL/entrypoints/GL2.0/gl_attach_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_bind_attrib_location.h"
#include "OpenGL/entrypoints/GL2.0/gl_blend_equation_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_compile_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_create_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_create_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_delete_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_delete_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_detach_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_disable_vertex_attrib_array.h"
#include "OpenGL/entrypoints/GL2.0/gl_draw_buffers.h"
#include "OpenGL/entrypoints/GL2.0/gl_enable_vertex_attrib_array.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_active_attrib.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_active_uniform.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_attached_shaders.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_attrib_location.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_programiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_program_info_log.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_shaderiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_shader_info_log.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_shader_source.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_uniformfv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_uniformiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_uniform_location.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribdv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribfv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attribiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_get_vertex_attrib_pointerv.h"
#include "OpenGL/entrypoints/GL2.0/gl_is_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_is_shader.h"
#include "OpenGL/entrypoints/GL2.0/gl_link_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_shader_source.h"
#include "OpenGL/entrypoints/GL2.0/gl_stencil_func_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_stencil_mask_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_stencil_op_separate.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_1iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_2iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_3iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4f.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4i.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_4iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_2fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_3fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_uniform_matrix_4fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_use_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_validate_program.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_1sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_2sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_3sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4bv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4d.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4dv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4f.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4fv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4iv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nbv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Niv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nsv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nub.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nubv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nuiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4Nusv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4s.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4sv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4ubv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4uiv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4usv.h"
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_pointer.h"

#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_2x3_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_2x4_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_3x2_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_3x4_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_4x2_fv.h"
#include "OpenGL/entrypoints/GL2.1/gl_uniform_matrix_4x3_fv.h"

#include "OpenGL/entrypoints/GL3.0/gl_begin_conditional_render.h"
#include "OpenGL/entrypoints/GL3.0/gl_begin_transform_feedback.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_buffer_base.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_buffer_range.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_frag_data_location.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_framebuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_renderbuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_bind_vertex_array.h"
#include "OpenGL/entrypoints/GL3.0/gl_blit_framebuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_check_framebuffer_status.h"
#include "OpenGL/entrypoints/GL3.0/gl_clamp_color.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fi.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_fv.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_clear_buffer_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_color_maski.h"
#include "OpenGL/entrypoints/GL3.0/gl_delete_framebuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_delete_renderbuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_delete_vertex_arrays.h"
#include "OpenGL/entrypoints/GL3.0/gl_disablei.h"
#include "OpenGL/entrypoints/GL3.0/gl_enablei.h"
#include "OpenGL/entrypoints/GL3.0/gl_end_conditional_render.h"
#include "OpenGL/entrypoints/GL3.0/gl_end_transform_feedback.h"
#include "OpenGL/entrypoints/GL3.0/gl_flush_mapped_buffer_range.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_renderbuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_1d.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_2d.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_3d.h"
#include "OpenGL/entrypoints/GL3.0/gl_framebuffer_texture_layer.h"
#include "OpenGL/entrypoints/GL3.0/gl_generate_mipmap.h"
#include "OpenGL/entrypoints/GL3.0/gl_gen_framebuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_gen_renderbuffers.h"
#include "OpenGL/entrypoints/GL3.0/gl_gen_vertex_arrays.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_booleani_v.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_frag_data_location.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_framebuffer_attachment_parameteriv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_integeri_v.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_renderbuffer_parameteriv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_stringi.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_tex_parameter_i_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_tex_parameter_i_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_transform_feedback_varying.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_uniformuiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_vertex_attrib_i_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_get_vertex_attrib_i_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_enabledi.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_framebuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_renderbuffer.h"
#include "OpenGL/entrypoints/GL3.0/gl_is_vertex_array.h"
#include "OpenGL/entrypoints/GL3.0/gl_map_buffer_range.h"
#include "OpenGL/entrypoints/GL3.0/gl_renderbuffer_storage.h"
#include "OpenGL/entrypoints/GL3.0/gl_renderbuffer_storage_multisample.h"
#include "OpenGL/entrypoints/GL3.0/gl_tex_parameter_i_iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_tex_parameter_i_uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_transform_feedback_varyings.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_1ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_1uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_2ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_2uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_3ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_3uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_4ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_uniform_4uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_1uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_2uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_3uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4bv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4i.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4iv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4sv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4ubv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4ui.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4uiv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_4usv.h"
#include "OpenGL/entrypoints/GL3.0/gl_vertex_attrib_i_pointer.h"

#include "OpenGL/entrypoints/GL3.1/gl_copy_buffer_sub_data.h"
#include "OpenGL/entrypoints/GL3.1/gl_draw_arrays_instanced.h"
#include "OpenGL/entrypoints/GL3.1/gl_draw_elements_instanced.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniformsiv.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_blockiv.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_block_name.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_active_uniform_name.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_block_index.h"
#include "OpenGL/entrypoints/GL3.1/gl_get_uniform_indices.h"
#include "OpenGL/entrypoints/GL3.1/gl_primitive_restart_index.h"
#include "OpenGL/entrypoints/GL3.1/gl_tex_buffer.h"
#include "OpenGL/entrypoints/GL3.1/gl_uniform_block_binding.h"

#include "OpenGL/entrypoints/GL3.2/gl_client_wait_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_delete_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_draw_elements_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_draw_elements_instanced_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_draw_range_elements_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_fence_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_framebuffer_texture.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_buffer_parameteri64v.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_integer64i_v.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_integer64v.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_multisamplefv.h"
#include "OpenGL/entrypoints/GL3.2/gl_get_synciv.h"
#include "OpenGL/entrypoints/GL3.2/gl_is_sync.h"
#include "OpenGL/entrypoints/GL3.2/gl_multi_draw_elements_base_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_provoking_vertex.h"
#include "OpenGL/entrypoints/GL3.2/gl_sample_maski.h"
#include "OpenGL/entrypoints/GL3.2/gl_tex_image_2d_multisample.h"
#include "OpenGL/entrypoints/GL3.2/gl_tex_image_3d_multisample.h"
#include "OpenGL/entrypoints/GL3.2/gl_wait_sync.h"

#include "OpenGL/entrypoints/GL_ARB_color_buffer_float/gl_clamp_color_arb.h"

#include "OpenGL/entrypoints/GL_ARB_draw_buffers/gl_draw_buffers_arb.h"

#include "OpenGL/entrypoints/GL_ARB_draw_instanced/gl_draw_arrays_instanced_arb.h"
#include "OpenGL/entrypoints/GL_ARB_draw_instanced/gl_draw_elements_instanced_arb.h"

#include "OpenGL/entrypoints/GL_ARB_multisample/gl_sample_coverage_arb.h"

#include "OpenGL/entrypoints/GL_ARB_multitexture/gl_active_texture_arb.h"

#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_begin_query_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_delete_queries_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_end_query_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_gen_queries_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_get_queryiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_get_query_objectiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_get_query_objectuiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_occlusion_query/gl_is_query_arb.h"

#include "OpenGL/entrypoints/GL_ARB_point_parameters/gl_point_parameterf_arb.h"
#include "OpenGL/entrypoints/GL_ARB_point_parameters/gl_point_parameterfv_arb.h"

#include "OpenGL/entrypoints/GL_ARB_texture_buffer_object/gl_tex_buffer_arb.h"

#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_image_1d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_image_2d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_image_3d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_sub_image_1d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_sub_image_2d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_compressed_tex_sub_image_3d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_texture_compression/gl_get_compressed_tex_image_arb.h"

#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_bind_buffer_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_buffer_data_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_buffer_sub_data_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_delete_buffers_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_gen_buffers_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_get_buffer_parameteriv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_get_buffer_pointerv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_get_buffer_sub_data_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_is_buffer_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_map_buffer_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_buffer_object/gl_unmap_buffer_arb.h"

#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_disable_vertex_attrib_array_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_enable_vertex_attrib_array_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attribdv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attribfv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attribiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_get_vertex_attrib_pointerv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_1s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_2s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_3s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4bv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4dv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4d_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4fv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4f_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4iv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nbv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Niv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nsv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nubv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nub_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4Nuiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4sv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4s_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4ubv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4uiv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_4usv_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_program/gl_vertex_attrib_pointer_arb.h"

#include "OpenGL/entrypoints/GL_ARB_vertex_shader/gl_bind_attrib_location_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_shader/gl_get_active_attrib_arb.h"
#include "OpenGL/entrypoints/GL_ARB_vertex_shader/gl_get_attrib_location_arb.h"


OpenGL::Context::Context(const VKGL::IWSIContext* in_wsi_context_ptr)
    :m_wsi_context_ptr(in_wsi_context_ptr)
{
    /* Stub */
}

OpenGL::Context::~Context()
{
    /* Stub */
}

void OpenGL::Context::attach_shader(const GLuint& in_program,
                                    const GLuint& in_shader)
{
    vkgl_not_implemented();
}

void OpenGL::Context::begin_conditional_render(const GLuint&                        in_occlusion_query_id,
                                               const OpenGL::ConditionalRenderMode& in_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::begin_query(const OpenGL::QueryTarget& in_target,
                                  const uint32_t&            in_id)
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->begin_query(in_target,
                                        in_id);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::begin_transform_feedback(const OpenGL::TransformFeedbackPrimitiveMode& in_primitive_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_attrib_location(const GLuint& in_program,
                                           const GLuint& in_index,
                                           const GLchar* in_name)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_buffer(const OpenGL::BufferTarget& in_target,
                                  const uint32_t&             in_id)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_buffer_binding(in_target,
                                               in_id);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::bind_buffer_base(const OpenGL::BufferTarget& in_target,
                                       const GLuint&               in_index,
                                       const GLuint&               in_buffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLuint&               in_index,
                                        const GLuint&               in_buffer,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_size)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_frag_data_location(const GLuint& in_program,
                                              const GLuint& in_color,
                                              const GLchar* in_name)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_framebuffer(const OpenGL::FramebufferTarget& in_target,
                                       const GLuint&                    in_framebuffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_renderbuffer(const OpenGL::RenderbufferTarget& in_target,
                                        const GLuint&                     in_renderbuffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::bind_texture(const OpenGL::TextureTarget& in_target,
                                   const uint32_t&              in_texture)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_texture_binding(m_gl_state_manager_ptr->get_state()->active_texture_unit,
                                                in_target,
                                                in_texture);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::bind_vertex_array(const GLuint& in_array)
{
    vkgl_not_implemented();
}

void OpenGL::Context::blit_framebuffer(const GLint&                in_src_x0,
                                       const GLint&                in_src_y0,
                                       const GLint&                in_src_x1,
                                       const GLint&                in_src_y1,
                                       const GLint&                in_dst_x0,
                                       const GLint&                in_dst_y0,
                                       const GLint&                in_dst_x1,
                                       const GLint&                in_dst_y1,
                                       const OpenGL::BlitMaskBits& in_mask,
                                       const OpenGL::BlitFilter&   in_filter)
{
    vkgl_not_implemented();
}

void OpenGL::Context::buffer_data(const OpenGL::BufferTarget& in_target,
                                  const GLsizeiptr&           in_size,
                                  const void*                 in_data_ptr,
                                  const OpenGL::BufferUsage&  in_usage)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    m_gl_buffer_manager_ptr->buffer_data(buffer_id,
                                         in_size,
                                         in_data_ptr,
                                         in_usage);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                      const GLintptr&             in_offset,
                                      const GLsizeiptr&           in_size,
                                      const void*                 in_data_ptr)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    m_gl_buffer_manager_ptr->buffer_sub_data(buffer_id,
                                             in_offset,
                                             in_size,
                                             in_data_ptr);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::FramebufferStatus OpenGL::Context::check_framebuffer_status(const OpenGL::FramebufferTarget& in_target) const
{
    vkgl_not_implemented();

    return OpenGL::FramebufferStatus::Unknown;
}

void OpenGL::Context::clear(const OpenGL::ClearBufferBits& in_buffers_to_clear)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->clear(in_buffers_to_clear);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::clear_buffer(const OpenGL::ClearBuffer&        in_buffer,
                                   const GLint&                      in_drawbuffer,
                                   const OpenGL::GetSetArgumentType& in_color_arg_type,
                                   const uint32_t&                   in_color_n_components,
                                   const void*                       in_color_data_ptr,
                                   const GLfloat&                    in_depth,
                                   const GLint&                      in_stencil)
{
    vkgl_not_implemented();
}

OpenGL::WaitResult OpenGL::Context::client_wait_sync(const GLsync&               in_sync,
                                                     const OpenGL::WaitSyncBits& in_flags,
                                                     const GLuint64&             in_timeout)
{
    vkgl_not_implemented();

    return OpenGL::WaitResult::Unknown;
}

void OpenGL::Context::compile_shader(const GLuint& in_shader)
{
    vkgl_not_implemented();
}

void OpenGL::Context::compressed_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei                 in_width,
                                              const GLint                   in_border,
                                              const GLsizei                 in_image_size,
                                              const void*                   in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_image_1d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_border,
                                             in_image_size,
                                             in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei&                in_width,
                                              const GLsizei&                in_height,
                                              const GLint&                  in_border,
                                              const GLsizei&                in_image_size,
                                              const void*                   in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_image_2d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_height,
                                             in_border,
                                             in_image_size,
                                             in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_image_3d(const OpenGL::TextureTarget&  in_target,
                                              const GLint&                  in_level,
                                              const OpenGL::InternalFormat& in_internalformat,
                                              const GLsizei&                in_width,
                                              const GLsizei&                in_height,
                                              const GLsizei&                in_depth,
                                              const GLint&                  in_border,
                                              const GLsizei&                in_image_size,
                                              const void*                   in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_image_3d(texture_id,
                                             in_level,
                                             in_internalformat,
                                             in_width,
                                             in_height,
                                             in_depth,
                                             in_border,
                                             in_image_size,
                                             in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLsizei&               in_width,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_sub_image_1d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_width,
                                                 in_format,
                                                 in_image_size,
                                                 in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLint&                 in_yoffset,
                                                  const GLsizei&               in_width,
                                                  const GLsizei&               in_height,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_sub_image_2d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_yoffset,
                                                 in_width,
                                                 in_height,
                                                 in_format,
                                                 in_image_size,
                                                 in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::compressed_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                                  const GLint&                 in_level,
                                                  const GLint&                 in_xoffset,
                                                  const GLint&                 in_yoffset,
                                                  const GLint&                 in_zoffset,
                                                  const GLsizei&               in_width,
                                                  const GLsizei&               in_height,
                                                  const GLsizei&               in_depth,
                                                  const OpenGL::PixelFormat&   in_format,
                                                  const GLsizei&               in_image_size,
                                                  const void*                  in_data)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->compressed_tex_sub_image_3d(texture_id,
                                                 in_level,
                                                 in_xoffset,
                                                 in_yoffset,
                                                 in_zoffset,
                                                 in_width,
                                                 in_height,
                                                 in_depth,
                                                 in_format,
                                                 in_image_size,
                                                 in_data);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_buffer_sub_data(const OpenGL::BufferTarget& in_read_target,
                                           const OpenGL::BufferTarget& in_write_target,
                                           const GLintptr&             in_read_offset,
                                           const GLintptr&             in_write_offset,
                                           const GLsizeiptr&           in_size)
{
    vkgl_not_implemented();
}

void OpenGL::Context::copy_tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                        const GLint                   in_level,
                                        const OpenGL::InternalFormat& in_internalformat,
                                        const GLint&                  in_x,
                                        const GLint&                  in_y,
                                        const GLsizei&                in_width,
                                        const GLint&                  in_border)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_image_1d(texture_id,
                                       in_level,
                                       in_internalformat,
                                       in_x,
                                       in_y,
                                       in_width,
                                       in_border);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                        const GLint&                  in_level,
                                        const OpenGL::InternalFormat& in_internalformat,
                                        const GLint&                  in_x,
                                        const GLint&                  in_y,
                                        const GLsizei&                in_width,
                                        const GLsizei&                in_height,
                                        const GLint&                  in_border)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_image_2d(texture_id,
                                       in_level,
                                       in_internalformat,
                                       in_x,
                                       in_y,
                                       in_width,
                                       in_height,
                                       in_border);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_sub_image_1d(texture_id,
                                           in_level,
                                           in_xoffset,
                                           in_x,
                                           in_y,
                                           in_width);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_yoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width,
                                            const GLsizei&               in_height)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_sub_image_2d(texture_id,
                                           in_level,
                                           in_xoffset,
                                           in_yoffset,
                                           in_x,
                                           in_y,
                                           in_width,
                                           in_height);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::copy_tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                            const GLint&                 in_level,
                                            const GLint&                 in_xoffset,
                                            const GLint&                 in_yoffset,
                                            const GLint&                 in_zoffset,
                                            const GLint&                 in_x,
                                            const GLint&                 in_y,
                                            const GLsizei&               in_width,
                                            const GLsizei&               in_height)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->copy_tex_sub_image_3d(texture_id,
                                           in_level,
                                           in_xoffset,
                                           in_yoffset,
                                           in_zoffset,
                                           in_x,
                                           in_y,
                                           in_width,
                                           in_height);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::ContextUniquePtr OpenGL::Context::create(const VKGL::IWSIContext* in_wsi_context_ptr)
{
    OpenGL::ContextUniquePtr result_ptr;

    result_ptr.reset(
        new OpenGL::Context(in_wsi_context_ptr)
    );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

GLuint OpenGL::Context::create_program()
{
    vkgl_not_implemented();

    return 0;
}

GLuint OpenGL::Context::create_shader(const OpenGL::ShaderType& in_type)
{
    vkgl_not_implemented();

    return 0;
}

void OpenGL::Context::delete_buffers(const GLsizei&  in_n,
                                     const uint32_t* in_ids_ptr)
{
#if 0
    bool result;

    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    result = m_gl_buffer_manager_ptr->delete_ids(in_n,
                                                 in_ids_ptr);

    if (!result)
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_framebuffers(const GLsizei&  in_n,
                                          const uint32_t* in_framebuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_program (const GLuint& in_id)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_queries(const GLsizei&  in_n,
                                     const uint32_t* in_ids_ptr)
{
#if 0
    bool result;

    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    result = m_gl_query_manager_ptr->delete_ids(in_n,
                                                in_ids_ptr);

    if (!result)
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_renderbuffers(const GLsizei& in_n,
                                           const GLuint*  in_renderbuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_shader(const GLuint& in_id)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_sync(const GLsync& in_sync)
{
    vkgl_not_implemented();
}

void OpenGL::Context::delete_textures(const GLsizei& in_n,
                                      const GLuint*  in_ids_ptr)
{
#if 0
    bool result;

    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    result = m_gl_texture_manager_ptr->delete_ids(in_n,
                                                  in_ids_ptr);

    if (!result)
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::delete_vertex_arrays(const GLsizei& in_n,
                                           const GLuint*  in_arrays_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::detach_shader(const GLuint& in_program,
                                    const GLuint& in_shader)
{
    vkgl_not_implemented();
}

void OpenGL::Context::disable(const OpenGL::Capability& in_capability)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->disable(in_capability);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::disable_indexed(const OpenGL::Capability& in_capability,
                                      const GLuint&             in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::disable_vertex_attrib_array(const GLuint& in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                  const GLint&                in_first,
                                  const GLsizei&              in_count)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_arrays(in_mode,
                                 in_first,
                                 in_count);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_arrays_instanced(const OpenGL::DrawCallMode& in_mode,
                                            const GLint&                in_first,
                                            const GLsizei&              in_count,
                                            const GLsizei&              in_instancecount)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                    const GLsizei&                   in_count,
                                    const OpenGL::DrawCallIndexType& in_type,
                                    const void*                      in_indices)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_elements(in_mode,
                                   in_count,
                                   in_type,
                                   in_indices);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                const GLsizei&                   in_count,
                                                const OpenGL::DrawCallIndexType& in_type,
                                                const void*                      in_indices,
                                                const GLint&                     in_basevertex)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements_instanced(const OpenGL::DrawCallMode&      in_mode,
                                              const GLsizei&                   in_count,
                                              const OpenGL::DrawCallIndexType& in_type,
                                              const void*                      in_indices_ptr,
                                              const GLsizei&                   in_instancecount)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_elements_instanced_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                          const GLsizei&                   in_count,
                                                          const OpenGL::DrawCallIndexType& in_type,
                                                          const void*                      in_indices_ptr,
                                                          const GLsizei&                   in_instancecount,
                                                          const GLint&                     in_basevertex)
{
    vkgl_not_implemented();
}

void OpenGL::Context::draw_range_elements(const OpenGL::DrawCallMode&      in_mode,
                                          const GLuint&                    in_start,
                                          const GLuint&                    in_end,
                                          const GLsizei&                   in_count,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void*                      in_indices)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->draw_range_elements(in_mode,
                                         in_start,
                                         in_end,
                                         in_count,
                                         in_type,
                                         in_indices);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::draw_range_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                      const GLuint&                    in_start,
                                                      const GLuint&                    in_end,
                                                      const GLsizei&                   in_count,
                                                      const OpenGL::DrawCallIndexType& in_type,
                                                      const void*                      in_indices,
                                                      const GLint&                     in_basevertex)
{
    vkgl_not_implemented();
}

void OpenGL::Context::enable(const OpenGL::Capability& in_capability)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->enable(in_capability);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::enable_indexed(const OpenGL::Capability& in_capability,
                                     const GLuint&             in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::enable_vertex_attrib_array(const GLuint& in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::end_conditional_render()
{
    vkgl_not_implemented();
}

void OpenGL::Context::end_transform_feedback()
{
    vkgl_not_implemented();
}

void OpenGL::Context::end_query(const OpenGL::QueryTarget& in_target)
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    const auto query_id = m_gl_state_manager_ptr->get_query_binding(in_target);
    vkgl_assert(query_id != 0);

    m_gl_query_manager_ptr->end_query(query_id);
#else
    vkgl_not_implemented();
#endif
}

GLsync OpenGL::Context::fence_sync(const OpenGL::SyncCondition& in_condition)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::Context::finish()
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->finish();
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::flush()
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->flush();
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::flush_mapped_buffer_range(const OpenGL::BufferTarget& in_target,
                                                const GLintptr&             in_offset,
                                                const GLsizeiptr&           in_length)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_renderbuffer(const OpenGL::FramebufferTarget&          in_target,
                                               const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                               const OpenGL::RenderbufferTarget&         in_renderbuffertarget,
                                               const GLuint&                             in_renderbuffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture(const OpenGL::FramebufferTarget&          in_target,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          const GLuint&                             in_texture,
                                          const GLint&                              in_level)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_1D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_2D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_3D(const OpenGL::FramebufferTarget&          in_target,
                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                             const OpenGL::TextureTarget&              in_textarget,
                                             const GLuint&                             in_texture,
                                             const GLint&                              in_level,
                                             const GLint&                              in_zoffset)
{
    vkgl_not_implemented();
}

void OpenGL::Context::framebuffer_texture_layer(const OpenGL::FramebufferTarget&          in_target,
                                                const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                const GLuint&                             in_texture,
                                                const GLint&                              in_level,
                                                const GLint&                              in_layer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::generate_mipmap(const OpenGL::MipmapGenerationTextureTarget& in_target)
{
    vkgl_not_implemented();
}

void OpenGL::Context::gen_buffers(const uint32_t& in_n,
                                  uint32_t*       out_ids_ptr)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    if (!m_gl_buffer_manager_ptr->generate_ids(in_n,
                                               out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_framebuffers(const GLsizei& in_n,
                                       GLuint*        out_framebuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::gen_queries(const uint32_t& in_n,
                                  uint32_t*       out_ids_ptr)
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    if (!m_gl_query_manager_ptr->generate_ids(in_n,
                                              out_ids_ptr) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_renderbuffers(const GLsizei& in_n,
                                        GLuint*        out_renderbuffers_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::gen_textures(const GLsizei& in_n,
                                   GLuint*        out_ids_ptr)
{
#if 0
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    if (!m_gl_texture_manager_ptr->generate_ids(in_n,
                                                in_textures) )
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::gen_vertex_arrays(const GLsizei& in_n,
                                        GLuint*        out_arrays_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_attrib(const GLuint&         in_program,
                                        const GLuint&         in_index,
                                        const GLsizei&        in_buf_size,
                                        GLsizei*              out_length_ptr,
                                        GLint*                out_size_ptr,
                                        OpenGL::VariableType* out_type_ptr,
                                        GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform(const GLuint&         in_program,
                                         const GLuint&         in_index,
                                         const GLsizei&        in_buf_size,
                                         GLsizei*              out_length_ptr,
                                         GLint*                out_size_ptr,
                                         OpenGL::VariableType* out_type_ptr,
                                         GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform_block_name(const GLuint&  in_program,
                                                    const GLuint&  in_uniform_block_index,
                                                    const GLsizei& in_buf_size_ptr,
                                                    GLsizei*       inout_length_ptr,
                                                    GLchar*        out_uniform_block_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform_block_property(const GLuint&                       in_program,
                                                        const GLuint&                       in_uniform_block_index,
                                                        const OpenGL::UniformBlockProperty& in_pname,
                                                        const OpenGL::GetSetArgumentType&   in_params_type,
                                                        void*                               out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniform_name(const GLuint&  in_program,
                                              const GLuint&  in_uniform_index,
                                              const GLsizei& in_buf_size,
                                              GLsizei*       inout_length_ptr,
                                              GLchar*        out_uniform_name_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_active_uniforms(const GLuint&                  in_program,
                                          const GLsizei&                 in_uniform_count,
                                          const GLuint*                  in_uniform_indices_ptr,
                                          const OpenGL::UniformProperty& in_pname,
                                          GLint*                         out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_attached_shaders(const GLuint&  in_program,
                                           const GLsizei& in_max_count,
                                           GLsizei*       out_count_ptr,
                                           GLuint*        out_shaders_ptr) const
{
    vkgl_not_implemented();
}

GLint OpenGL::Context::get_attrib_location(const GLuint& in_program,
                                           const GLchar* in_name) const
{
    vkgl_not_implemented();

    return -1;
}

void OpenGL::Context::get_buffer_pointerv(const OpenGL::BufferTarget&          in_target,
                                          const OpenGL::BufferPointerProperty& in_pname,
                                          void**                               out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);

    m_gl_buffer_manager_ptr->get_buffer_pointerv(buffer_id,
                                                 in_pname,
                                                 out_params_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_buffer_property(const OpenGL::BufferTarget&       in_target,
                                          const OpenGL::BufferProperty&     in_pname,
                                          const OpenGL::GetSetArgumentType& in_arg_type,
                                          const uint32_t&                   in_n_args,
                                          void*                             out_result_ptr) const
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);

    m_gl_buffer_manager_ptr->get_buffer_property(buffer_id,
                                                 in_pname,
                                                 in_arg_type,
                                                 in_n_args,
                                                 out_result_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_buffer_sub_data(const OpenGL::BufferTarget& in_target,
                                          const GLintptr&             in_offset,
                                          const GLsizeiptr&           in_size,
                                          void*                       out_data_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    m_scheduler_ptr->get_buffer_sub_data(buffer_id,
                                         in_offset,
                                         in_size,
                                         out_data_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_compressed_tex_image(const OpenGL::TextureTarget& in_target,
                                               const GLint&                 in_level,
                                               void*                        in_img)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    m_scheduler_ptr->get_compressed_tex_image(texture_id,
                                              in_level,
                                              in_img);
#else
    vkgl_not_implemented();
#endif
}

OpenGL::ErrorCode OpenGL::Context::get_error()
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->get_error();
}

GLint OpenGL::Context::get_frag_data_location(const GLuint& in_program,
                                              const GLchar* in_name_ptr) const
{
    vkgl_not_implemented();

    return -1;
}

void OpenGL::Context::get_framebuffer_attachment_property(const OpenGL::FramebufferTarget&             in_target,
                                                          const OpenGL::FramebufferAttachmentPoint&    in_attachment,
                                                          const OpenGL::FramebufferAttachmentProperty& in_pname,
                                                          const OpenGL::GetSetArgumentType&            in_params_type,
                                                          void*                                        out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_parameter(const OpenGL::ContextProperty&    in_pname,
                                    const OpenGL::GetSetArgumentType& in_arg_type,
                                    void*                             out_arg_value_ptr) const
{
    if (OpenGL::Utils::is_context_property_gl_constant(in_pname) )
    {
        vkgl_assert(m_gl_constants_ptr != nullptr);

        m_gl_constants_ptr->get_parameter(in_pname,
                                          in_arg_type,
                                          out_arg_value_ptr);
    }
    else
    if (OpenGL::Utils::is_context_property_gl_limit(in_pname) )
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        m_gl_limits_ptr->get_parameter(in_pname,
                                       in_arg_type,
                                       out_arg_value_ptr);
    }
    else
#if 0
    if (OpenGL::Utils::is_framebuffer_pname(in_pname) ) // todo: gl_doublebuffer, _drawbuffer, _drawbufferN, _readbuffer, samples, sample_buffers, stereo
    {
        vkgl_not_implemented();

    }
    else
#endif
    if (in_pname == OpenGL::ContextProperty::Renderbuffer_Binding) // todo
    {
        vkgl_not_implemented()
    }
    else
#if 0
    if (OpenGL::Utils::is_buffer_binding_pname(in_pname) ) // todo: buffer bindings
    {
        vkgl_not_implemented();
    }
    else
#endif
    if (OpenGL::Utils::is_texture_binding_pname(in_pname) ) // todo
    {
        vkgl_not_implemented();
    }
    else
    {
        vkgl_assert_fail();
    }
}

void OpenGL::Context::get_parameter_indexed(const OpenGL::ContextProperty&    in_pname,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            const GLuint&                     in_index,
                                            void*                             out_data_ptr) const
{
    if (OpenGL::Utils::is_context_property_gl_constant(in_pname) )
    {
        vkgl_assert(m_gl_constants_ptr != nullptr);

        m_gl_constants_ptr->get_parameter_indexed(in_pname,
                                                  in_arg_type,
                                                  in_index,
                                                  out_data_ptr);
    }
    else
    {
        /* TODO: See get_parameter() for the remaining bits. */
        vkgl_not_implemented();
    }
}

void OpenGL::Context::get_program_info_log(const GLuint&  in_program,
                                           const GLsizei& in_buf_size,
                                           GLsizei*       inout_length_ptr,
                                           GLchar*        out_info_log_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_program_property(const GLuint&                     in_program,
                                           const OpenGL::ProgramProperty&    in_pname,
                                           const OpenGL::GetSetArgumentType& in_params_type,
                                           const uint32_t&                   in_n_params_components,
                                           void*                             out_params_ptr) const
{
    vkgl_not_implemented();
}
void OpenGL::Context::get_query_property(const uint32_t&                   in_id,
                                         const OpenGL::QueryProperty&      in_pname,
                                         const OpenGL::GetSetArgumentType& in_arg_type,
                                         const uint32_t&                   in_n_args,
                                         void*                             out_result_ptr) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->get_query_property(in_id,
                                               in_pname,
                                               in_arg_type,
                                               in_n_args,
                                               out_result_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_query_target_property(const OpenGL::QueryTarget&         in_target,
                                                const OpenGL::QueryTargetProperty& in_pname,
                                                int32_t*                           out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    m_gl_query_manager_ptr->get_query_target_property(in_target,
                                                      in_pname,
                                                      out_params_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_renderbuffer_property(const OpenGL::RenderbufferTarget&   in_target,
                                                const OpenGL::RenderbufferProperty& in_pname,
                                                const OpenGL::GetSetArgumentType&   in_params_type,
                                                void*                               out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_sample_position(const GLuint& in_index,
                                          GLfloat*      out_val_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_info_log(const GLuint&  in_shader,
                                          const GLsizei& in_buf_size,
                                          GLsizei*       inout_length_ptr,
                                          GLchar*        out_info_log_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_property(const GLuint&                     in_shader,
                                          const OpenGL::ShaderProperty&     in_pname,
                                          const OpenGL::GetSetArgumentType& in_params_type,
                                          const uint32_t&                   in_n_params_components,
                                          GLint*                            out_params_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_shader_source(const GLuint&  in_shader,
                                        const GLsizei& in_buf_size,
                                        GLsizei*       inout_length_ptr,
                                        GLchar*        out_source_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_sync_property(const GLsync&                     in_sync,
                                        const GLenum&                     in_pname,
                                        const OpenGL::GetSetArgumentType& in_values_type,
                                        const GLsizei&                    in_buf_size,
                                        GLsizei*                          inout_length_ptr,
                                        void*                             out_values_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_texture_image(const OpenGL::TextureTarget& in_target,
                                        const uint32_t&              in_level,
                                        const OpenGL::PixelFormat&   in_format,
                                        const OpenGL::PixelType&     in_type,
                                        void*                        out_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    m_scheduler_ptr->get_texture_image(texture_id,
                                       in_level,
                                       in_format,
                                       in_type,
                                       out_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_texture_level_parameter(const OpenGL::TextureTarget&        in_target,
                                                  const int32_t&                      in_level,
                                                  const OpenGL::TextureLevelProperty& in_pname,
                                                  const OpenGL::GetSetArgumentType&   in_arg_type,
                                                  void*                               out_params_ptr) const
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->get_texture_level_parameter(in_level,
                                                              in_pname,
                                                              in_arg_type,
                                                              out_params_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_texture_parameter(const OpenGL::TextureTarget&      in_target,
                                            const OpenGL::TextureProperty&    in_property,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            void*                             out_arg_value_ptr) const
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->get_texture_parameter(in_property,
                                                        in_arg_type,
                                                        out_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::get_transform_feedback_varying(const GLuint&         in_program,
                                                     const GLuint&         in_index,
                                                     const GLsizei&        in_buf_size,
                                                     GLsizei*              out_length_ptr,
                                                     GLsizei*              out_size_ptr,
                                                     OpenGL::VariableType* out_type_ptr,
                                                     GLchar*               out_name_ptr) const
{
    vkgl_not_implemented();
}

GLuint OpenGL::Context::get_uniform_block_index(const GLuint& in_program,
                                                const GLchar* in_uniform_block_name) const
{
    vkgl_not_implemented();

    return UINT32_MAX;
}

void OpenGL::Context::get_uniform_indices(const GLuint&        in_program,
                                          const GLsizei&       in_uniform_count,
                                          const GLchar* const* in_uniform_names_ptr_ptr,
                                          GLuint*              out_uniform_indices_ptr) const
{
    vkgl_not_implemented();
}

GLint OpenGL::Context::get_uniform_location(const GLuint& in_program,
                                            const GLchar* in_name) const
{
    vkgl_not_implemented();

    return -1;
}

void OpenGL::Context::get_uniform_value(const GLuint&                     in_program,
                                        const GLint&                      in_location,
                                        const OpenGL::GetSetArgumentType& in_params_type,
                                        void*                             out_params_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_vertex_attrib_pointer_property(const GLuint&                                 in_index,
                                                         const OpenGL::VertexAttributePointerProperty& in_pname,
                                                         void**                                        out_pointer_ptr) const
{
    vkgl_not_implemented();
}

void OpenGL::Context::get_vertex_attribute_property(const GLuint&                          in_index,
                                                    const OpenGL::VertexAttributeProperty& in_pname,
                                                    const OpenGL::GetSetArgumentType&      in_src_type,
                                                    const OpenGL::GetSetArgumentType&      in_dst_type,
                                                    void*                                  out_params_ptr) const
{
    vkgl_not_implemented();
}

bool OpenGL::Context::init()
{
    bool result = false;

    /* Init dispatch table */
    result = init_dispatch_table();

    if (!result)
    {
        vkgl_assert(result);

        goto end;
    }

    /* Cache supported extensions */
    result = init_supported_extensions();

    if (!result)
    {
        vkgl_assert(result);

        goto end;
    }

    /* Set up GL constants container */
    m_gl_constants_ptr.reset(
        new OpenGL::GLConstants(dynamic_cast<IContext*>(this) )
    );

    if (m_gl_constants_ptr == nullptr)
    {
        vkgl_assert(m_gl_constants_ptr != nullptr);

        goto end;
    }

    /* Set up GL limits container */
    m_gl_limits_ptr.reset(
        new OpenGL::GLLimits()
    );

    if (m_gl_limits_ptr == nullptr)
    {
        vkgl_assert(m_gl_limits_ptr != nullptr);

        goto end;
    }

    /* Set up GL state manager */
    m_gl_state_manager_ptr.reset(
        new OpenGL::GLStateManager(dynamic_cast<IGLLimits*>(m_gl_limits_ptr.get() ))
    );

    if (m_gl_state_manager_ptr == nullptr)
    {
        vkgl_assert(m_gl_state_manager_ptr != nullptr);

        goto end;
    }

    /* Set up task scheduler */
    m_scheduler_ptr = Scheduler::create();

    if (m_scheduler_ptr == nullptr)
    {
        vkgl_assert(m_scheduler_ptr != nullptr);

        goto end;
    }

    /* All done */
    result = true;
end:
    return result;
}

bool OpenGL::Context::init_dispatch_table()
{
    bool result = false;

    m_dispatch_table.bound_context_ptr         = this;
    m_dispatch_table.pGLBindTexture            = OpenGL::vkglBindTexture_with_validation;
    m_dispatch_table.pGLBlendFunc              = OpenGL::vkglBlendFunc_with_validation;
    m_dispatch_table.pGLClear                  = OpenGL::vkglClear_with_validation;
    m_dispatch_table.pGLClearColor             = OpenGL::vkglClearColor_with_validation;
    m_dispatch_table.pGLClearDepth             = OpenGL::vkglClearDepth_with_validation;
    m_dispatch_table.pGLClearStencil           = OpenGL::vkglClearStencil_with_validation;
    m_dispatch_table.pGLColorMask              = OpenGL::vkglColorMask_with_validation;
    m_dispatch_table.pGLCopyTexImage1D         = OpenGL::vkglCopyTexImage1D_with_validation;
    m_dispatch_table.pGLCopyTexImage2D         = OpenGL::vkglCopyTexImage2D_with_validation;
    m_dispatch_table.pGLCopyTexSubImage1D      = OpenGL::vkglCopyTexSubImage1D_with_validation;
    m_dispatch_table.pGLCopyTexSubImage2D      = OpenGL::vkglCopyTexSubImage2D_with_validation;
    m_dispatch_table.pGLCullFace               = OpenGL::vkglCullFace_with_validation;
    m_dispatch_table.pGLDeleteTextures         = OpenGL::vkglDeleteTextures_with_validation;
    m_dispatch_table.pGLDepthFunc              = OpenGL::vkglDepthFunc_with_validation;
    m_dispatch_table.pGLDepthMask              = OpenGL::vkglDepthMask_with_validation;
    m_dispatch_table.pGLDepthRange             = OpenGL::vkglDepthRange_with_validation;
    m_dispatch_table.pGLDisable                = OpenGL::vkglDisable_with_validation;
    m_dispatch_table.pGLDrawArrays             = OpenGL::vkglDrawArrays_with_validation;
    m_dispatch_table.pGLDrawBuffer             = OpenGL::vkglDrawBuffer_with_validation;
    m_dispatch_table.pGLDrawElements           = OpenGL::vkglDrawElements_with_validation;
    m_dispatch_table.pGLEnable                 = OpenGL::vkglEnable_with_validation;
    m_dispatch_table.pGLFinish                 = OpenGL::vkglFinish_with_validation;
    m_dispatch_table.pGLFlush                  = OpenGL::vkglFlush_with_validation;
    m_dispatch_table.pGLFrontFace              = OpenGL::vkglFrontFace_with_validation;
    m_dispatch_table.pGLGenTextures            = OpenGL::vkglGenTextures_with_validation;
    m_dispatch_table.pGLGetBooleanv            = OpenGL::vkglGetBooleanv_with_validation;
    m_dispatch_table.pGLGetDoublev             = OpenGL::vkglGetDoublev_with_validation;
    m_dispatch_table.pGLGetError               = OpenGL::vkglGetError_with_validation;
    m_dispatch_table.pGLGetFloatv              = OpenGL::vkglGetFloatv_with_validation;
    m_dispatch_table.pGLGetIntegerv            = OpenGL::vkglGetIntegerv_with_validation;
    m_dispatch_table.pGLGetString              = OpenGL::vkglGetString_with_validation;
    m_dispatch_table.pGLGetTexImage            = OpenGL::vkglGetTexImage_with_validation;
    m_dispatch_table.pGLGetTexLevelParameterfv = OpenGL::vkglGetTexLevelParameterfv_with_validation;
    m_dispatch_table.pGLGetTexLevelParameteriv = OpenGL::vkglGetTexLevelParameteriv_with_validation;
    m_dispatch_table.pGLGetTexParameterfv      = OpenGL::vkglGetTexParameterfv_with_validation;
    m_dispatch_table.pGLGetTexParameteriv      = OpenGL::vkglGetTexParameteriv_with_validation;
    m_dispatch_table.pGLHint                   = OpenGL::vkglHint_with_validation;
    m_dispatch_table.pGLIsEnabled              = OpenGL::vkglIsEnabled_with_validation;
    m_dispatch_table.pGLIsTexture              = OpenGL::vkglIsTexture_with_validation;
    m_dispatch_table.pGLLineWidth              = OpenGL::vkglLineWidth_with_validation;
    m_dispatch_table.pGLLogicOp                = OpenGL::vkglLogicOp_with_validation;
    m_dispatch_table.pGLPixelStoref            = OpenGL::vkglPixelStoref_with_validation;
    m_dispatch_table.pGLPixelStorei            = OpenGL::vkglPixelStorei_with_validation;
    m_dispatch_table.pGLPointSize              = OpenGL::vkglPointSize_with_validation;
    m_dispatch_table.pGLPolygonMode            = OpenGL::vkglPolygonMode_with_validation;
    m_dispatch_table.pGLPolygonOffset          = OpenGL::vkglPolygonOffset_with_validation;
    m_dispatch_table.pGLReadBuffer             = OpenGL::vkglReadBuffer_with_validation;
    m_dispatch_table.pGLReadPixels             = OpenGL::vkglReadPixels_with_validation;
    m_dispatch_table.pGLScissor                = OpenGL::vkglScissor_with_validation;
    m_dispatch_table.pGLStencilFunc            = OpenGL::vkglStencilFunc_with_validation;
    m_dispatch_table.pGLStencilMask            = OpenGL::vkglStencilMask_with_validation;
    m_dispatch_table.pGLStencilOp              = OpenGL::vkglStencilOp_with_validation;
    m_dispatch_table.pGLTexImage1D             = OpenGL::vkglTexImage1D_with_validation;
    m_dispatch_table.pGLTexImage2D             = OpenGL::vkglTexImage2D_with_validation;
    m_dispatch_table.pGLTexParameterf          = OpenGL::vkglTexParameterf_with_validation;
    m_dispatch_table.pGLTexParameterfv         = OpenGL::vkglTexParameterfv_with_validation;
    m_dispatch_table.pGLTexParameteri          = OpenGL::vkglTexParameteri_with_validation;
    m_dispatch_table.pGLTexParameteriv         = OpenGL::vkglTexParameteriv_with_validation;
    m_dispatch_table.pGLTexSubImage1D          = OpenGL::vkglTexSubImage1D_with_validation;
    m_dispatch_table.pGLTexSubImage2D          = OpenGL::vkglTexSubImage2D_with_validation;
    m_dispatch_table.pGLViewport               = OpenGL::vkglViewport_with_validation;

    m_dispatch_table.pGLCopyTexSubImage3D = OpenGL::vkglCopyTexSubImage3D_with_validation;
    m_dispatch_table.pGLDrawRangeElements = OpenGL::vkglDrawRangeElements_with_validation;
    m_dispatch_table.pGLTexImage3D        = OpenGL::vkglTexImage3D_with_validation;
    m_dispatch_table.pGLTexSubImage3D     = OpenGL::vkglTexSubImage3D_with_validation;

    m_dispatch_table.pGLActiveTexture           = OpenGL::vkglActiveTexture_with_validation;
    m_dispatch_table.pGLCompressedTexImage1D    = OpenGL::vkglCompressedTexImage1D_with_validation;
    m_dispatch_table.pGLCompressedTexImage2D    = OpenGL::vkglCompressedTexImage2D_with_validation;
    m_dispatch_table.pGLCompressedTexImage3D    = OpenGL::vkglCompressedTexImage3D_with_validation;
    m_dispatch_table.pGLCompressedTexSubImage1D = OpenGL::vkglCompressedTexSubImage1D_with_validation;
    m_dispatch_table.pGLCompressedTexSubImage2D = OpenGL::vkglCompressedTexSubImage2D_with_validation;
    m_dispatch_table.pGLCompressedTexSubImage3D = OpenGL::vkglCompressedTexSubImage3D_with_validation;
    m_dispatch_table.pGLGetCompressedTexImage   = OpenGL::vkglGetCompressedTexImage_with_validation;
    m_dispatch_table.pGLSampleCoverage          = OpenGL::vkglSampleCoverage_with_validation;

    m_dispatch_table.pGLBlendColor        = OpenGL::vkglBlendColor_with_validation;
    m_dispatch_table.pGLBlendEquation     = OpenGL::vkglBlendEquation_with_validation;
    m_dispatch_table.pGLBlendFuncSeparate = OpenGL::vkglBlendFuncSeparate_with_validation;
    m_dispatch_table.pGLMultiDrawArrays   = OpenGL::vkglMultiDrawArrays_with_validation;
    m_dispatch_table.pGLMultiDrawElements = OpenGL::vkglMultiDrawElements_with_validation;
    m_dispatch_table.pGLPointParameterf   = OpenGL::vkglPointParameterf_with_validation;
    m_dispatch_table.pGLPointParameterfv  = OpenGL::vkglPointParameterfv_with_validation;
    m_dispatch_table.pGLPointParameteri   = OpenGL::vkglPointParameteri_with_validation;
    m_dispatch_table.pGLPointParameteriv  = OpenGL::vkglPointParameteriv_with_validation;

    m_dispatch_table.pGLBeginQuery           = OpenGL::vkglBeginQuery_with_validation;
    m_dispatch_table.pGLBindBuffer           = OpenGL::vkglBindBuffer_with_validation;
    m_dispatch_table.pGLBufferData           = OpenGL::vkglBufferData_with_validation;
    m_dispatch_table.pGLBufferSubData        = OpenGL::vkglBufferSubData_with_validation;
    m_dispatch_table.pGLDeleteBuffers        = OpenGL::vkglDeleteBuffers_with_validation;
    m_dispatch_table.pGLDeleteQueries        = OpenGL::vkglDeleteQueries_with_validation;
    m_dispatch_table.pGLEndQuery             = OpenGL::vkglEndQuery_with_validation;
    m_dispatch_table.pGLGenBuffers           = OpenGL::vkglGenBuffers_with_validation;
    m_dispatch_table.pGLGenQueries           = OpenGL::vkglGenQueries_with_validation;
    m_dispatch_table.pGLGetBufferParameteriv = OpenGL::vkglGetBufferParameteriv_with_validation;
    m_dispatch_table.pGLGetBufferPointerv    = OpenGL::vkglGetBufferPointerv_with_validation;
    m_dispatch_table.pGLGetBufferSubData     = OpenGL::vkglGetBufferSubData_with_validation;
    m_dispatch_table.pGLGetQueryiv           = OpenGL::vkglGetQueryiv_with_validation;
    m_dispatch_table.pGLGetQueryObjectiv     = OpenGL::vkglGetQueryObjectiv_with_validation;
    m_dispatch_table.pGLGetQueryObjectuiv    = OpenGL::vkglGetQueryObjectuiv_with_validation;
    m_dispatch_table.pGLIsBuffer             = OpenGL::vkglIsBuffer_with_validation;
    m_dispatch_table.pGLIsQuery              = OpenGL::vkglIsQuery_with_validation;
    m_dispatch_table.pGLMapBuffer            = OpenGL::vkglMapBuffer_with_validation;
    m_dispatch_table.pGLUnmapBuffer          = OpenGL::vkglUnmapBuffer_with_validation;

    m_dispatch_table.pGLAttachShader             = OpenGL::vkglAttachShader_with_validation;
    m_dispatch_table.pGLBindAttribLocation       = OpenGL::vkglBindAttribLocation_with_validation;
    m_dispatch_table.pGLBlendEquationSeparate    = OpenGL::vkglBlendEquationSeparate_with_validation;
    m_dispatch_table.pGLCompileShader            = OpenGL::vkglCompileShader_with_validation;
    m_dispatch_table.pGLCreateProgram            = OpenGL::vkglCreateProgram_with_validation;
    m_dispatch_table.pGLCreateShader             = OpenGL::vkglCreateShader_with_validation;
    m_dispatch_table.pGLDeleteProgram            = OpenGL::vkglDeleteProgram_with_validation;
    m_dispatch_table.pGLDeleteShader             = OpenGL::vkglDeleteShader_with_validation;
    m_dispatch_table.pGLDetachShader             = OpenGL::vkglDetachShader_with_validation;
    m_dispatch_table.pGLDisableVertexAttribArray = OpenGL::vkglDisableVertexAttribArray_with_validation;
    m_dispatch_table.pGLDrawBuffers              = OpenGL::vkglDrawBuffers_with_validation;
    m_dispatch_table.pGLEnableVertexAttribArray  = OpenGL::vkglEnableVertexAttribArray_with_validation;
    m_dispatch_table.pGLGetActiveAttrib          = OpenGL::vkglGetActiveAttrib_with_validation;
    m_dispatch_table.pGLGetActiveUniform         = OpenGL::vkglGetActiveUniform_with_validation;
    m_dispatch_table.pGLGetAttachedShaders       = OpenGL::vkglGetAttachedShaders_with_validation;
    m_dispatch_table.pGLGetAttribLocation        = OpenGL::vkglGetAttribLocation_with_validation;
    m_dispatch_table.pGLGetProgramiv             = OpenGL::vkglGetProgramiv_with_validation;
    m_dispatch_table.pGLGetProgramInfoLog        = OpenGL::vkglGetProgramInfoLog_with_validation;
    m_dispatch_table.pGLGetShaderiv              = OpenGL::vkglGetShaderiv_with_validation;
    m_dispatch_table.pGLGetShaderInfoLog         = OpenGL::vkglGetShaderInfoLog_with_validation;
    m_dispatch_table.pGLGetShaderSource          = OpenGL::vkglGetShaderSource_with_validation;
    m_dispatch_table.pGLGetUniformfv             = OpenGL::vkglGetUniformfv_with_validation;
    m_dispatch_table.pGLGetUniformiv             = OpenGL::vkglGetUniformiv_with_validation;
    m_dispatch_table.pGLGetUniformLocation       = OpenGL::vkglGetUniformLocation_with_validation;
    m_dispatch_table.pGLGetVertexAttribdv        = OpenGL::vkglGetVertexAttribdv_with_validation;
    m_dispatch_table.pGLGetVertexAttribfv        = OpenGL::vkglGetVertexAttribfv_with_validation;
    m_dispatch_table.pGLGetVertexAttribiv        = OpenGL::vkglGetVertexAttribiv_with_validation;
    m_dispatch_table.pGLGetVertexAttribPointerv  = OpenGL::vkglGetVertexAttribPointerv_with_validation;
    m_dispatch_table.pGLIsProgram                = OpenGL::vkglIsProgram_with_validation;
    m_dispatch_table.pGLIsShader                 = OpenGL::vkglIsShader_with_validation;
    m_dispatch_table.pGLLinkProgram              = OpenGL::vkglLinkProgram_with_validation;
    m_dispatch_table.pGLShaderSource             = OpenGL::vkglShaderSource_with_validation;
    m_dispatch_table.pGLStencilFuncSeparate      = OpenGL::vkglStencilFuncSeparate_with_validation;
    m_dispatch_table.pGLStencilMaskSeparate      = OpenGL::vkglStencilMaskSeparate_with_validation;
    m_dispatch_table.pGLStencilOpSeparate        = OpenGL::vkglStencilOpSeparate_with_validation;
    m_dispatch_table.pGLUniform1f                = OpenGL::vkglUniform1f_with_validation;
    m_dispatch_table.pGLUniform1fv               = OpenGL::vkglUniform1fv_with_validation;
    m_dispatch_table.pGLUniform1i                = OpenGL::vkglUniform1i_with_validation;
    m_dispatch_table.pGLUniform1iv               = OpenGL::vkglUniform1iv_with_validation;
    m_dispatch_table.pGLUniform2f                = OpenGL::vkglUniform2f_with_validation;
    m_dispatch_table.pGLUniform2fv               = OpenGL::vkglUniform2fv_with_validation;
    m_dispatch_table.pGLUniform2i                = OpenGL::vkglUniform2i_with_validation;
    m_dispatch_table.pGLUniform2iv               = OpenGL::vkglUniform2iv_with_validation;
    m_dispatch_table.pGLUniform3f                = OpenGL::vkglUniform3f_with_validation;
    m_dispatch_table.pGLUniform3fv               = OpenGL::vkglUniform3fv_with_validation;
    m_dispatch_table.pGLUniform3i                = OpenGL::vkglUniform3i_with_validation;
    m_dispatch_table.pGLUniform3iv               = OpenGL::vkglUniform3iv_with_validation;
    m_dispatch_table.pGLUniform4f                = OpenGL::vkglUniform4f_with_validation;
    m_dispatch_table.pGLUniform4fv               = OpenGL::vkglUniform4fv_with_validation;
    m_dispatch_table.pGLUniform4i                = OpenGL::vkglUniform4i_with_validation;
    m_dispatch_table.pGLUniform4iv               = OpenGL::vkglUniform4iv_with_validation;
    m_dispatch_table.pGLUniformMatrix2fv         = OpenGL::vkglUniformMatrix2fv_with_validation;
    m_dispatch_table.pGLUniformMatrix3fv         = OpenGL::vkglUniformMatrix3fv_with_validation;
    m_dispatch_table.pGLUniformMatrix4fv         = OpenGL::vkglUniformMatrix4fv_with_validation;
    m_dispatch_table.pGLUseProgram               = OpenGL::vkglUseProgram_with_validation;
    m_dispatch_table.pGLValidateProgram          = OpenGL::vkglValidateProgram_with_validation;
    m_dispatch_table.pGLVertexAttrib1d           = OpenGL::vkglVertexAttrib1d_with_validation;
    m_dispatch_table.pGLVertexAttrib1dv          = OpenGL::vkglVertexAttrib1dv_with_validation;
    m_dispatch_table.pGLVertexAttrib1f           = OpenGL::vkglVertexAttrib1f_with_validation;
    m_dispatch_table.pGLVertexAttrib1fv          = OpenGL::vkglVertexAttrib1fv_with_validation;
    m_dispatch_table.pGLVertexAttrib1s           = OpenGL::vkglVertexAttrib1s_with_validation;
    m_dispatch_table.pGLVertexAttrib1sv          = OpenGL::vkglVertexAttrib1sv_with_validation;
    m_dispatch_table.pGLVertexAttrib2d           = OpenGL::vkglVertexAttrib2d_with_validation;
    m_dispatch_table.pGLVertexAttrib2dv          = OpenGL::vkglVertexAttrib2dv_with_validation;
    m_dispatch_table.pGLVertexAttrib2f           = OpenGL::vkglVertexAttrib2f_with_validation;
    m_dispatch_table.pGLVertexAttrib2fv          = OpenGL::vkglVertexAttrib2fv_with_validation;
    m_dispatch_table.pGLVertexAttrib2s           = OpenGL::vkglVertexAttrib2s_with_validation;
    m_dispatch_table.pGLVertexAttrib2sv          = OpenGL::vkglVertexAttrib2sv_with_validation;
    m_dispatch_table.pGLVertexAttrib3d           = OpenGL::vkglVertexAttrib3d_with_validation;
    m_dispatch_table.pGLVertexAttrib3dv          = OpenGL::vkglVertexAttrib3dv_with_validation;
    m_dispatch_table.pGLVertexAttrib3f           = OpenGL::vkglVertexAttrib3f_with_validation;
    m_dispatch_table.pGLVertexAttrib3fv          = OpenGL::vkglVertexAttrib3fv_with_validation;
    m_dispatch_table.pGLVertexAttrib3s           = OpenGL::vkglVertexAttrib3s_with_validation;
    m_dispatch_table.pGLVertexAttrib3sv          = OpenGL::vkglVertexAttrib3sv_with_validation;
    m_dispatch_table.pGLVertexAttrib4bv          = OpenGL::vkglVertexAttrib4bv_with_validation;
    m_dispatch_table.pGLVertexAttrib4d           = OpenGL::vkglVertexAttrib4d_with_validation;
    m_dispatch_table.pGLVertexAttrib4dv          = OpenGL::vkglVertexAttrib4dv_with_validation;
    m_dispatch_table.pGLVertexAttrib4f           = OpenGL::vkglVertexAttrib4f_with_validation;
    m_dispatch_table.pGLVertexAttrib4fv          = OpenGL::vkglVertexAttrib4fv_with_validation;
    m_dispatch_table.pGLVertexAttrib4iv          = OpenGL::vkglVertexAttrib4iv_with_validation;
    m_dispatch_table.pGLVertexAttrib4Nbv         = OpenGL::vkglVertexAttrib4Nbv_with_validation;
    m_dispatch_table.pGLVertexAttrib4Niv         = OpenGL::vkglVertexAttrib4Niv_with_validation;
    m_dispatch_table.pGLVertexAttrib4Nsv         = OpenGL::vkglVertexAttrib4Nsv_with_validation;
    m_dispatch_table.pGLVertexAttrib4Nub         = OpenGL::vkglVertexAttrib4Nub_with_validation;
    m_dispatch_table.pGLVertexAttrib4Nubv        = OpenGL::vkglVertexAttrib4Nubv_with_validation;
    m_dispatch_table.pGLVertexAttrib4Nuiv        = OpenGL::vkglVertexAttrib4Nuiv_with_validation;
    m_dispatch_table.pGLVertexAttrib4Nusv        = OpenGL::vkglVertexAttrib4Nusv_with_validation;
    m_dispatch_table.pGLVertexAttrib4s           = OpenGL::vkglVertexAttrib4s_with_validation;
    m_dispatch_table.pGLVertexAttrib4sv          = OpenGL::vkglVertexAttrib4sv_with_validation;
    m_dispatch_table.pGLVertexAttrib4ubv         = OpenGL::vkglVertexAttrib4ubv_with_validation;
    m_dispatch_table.pGLVertexAttrib4uiv         = OpenGL::vkglVertexAttrib4uiv_with_validation;
    m_dispatch_table.pGLVertexAttrib4usv         = OpenGL::vkglVertexAttrib4usv_with_validation;
    m_dispatch_table.pGLVertexAttribPointer      = OpenGL::vkglVertexAttribPointer_with_validation;

    m_dispatch_table.pGLUniformMatrix2x3fv = OpenGL::vkglUniformMatrix2x3fv_with_validation;
    m_dispatch_table.pGLUniformMatrix2x4fv = OpenGL::vkglUniformMatrix2x4fv_with_validation;
    m_dispatch_table.pGLUniformMatrix3x2fv = OpenGL::vkglUniformMatrix3x2fv_with_validation;
    m_dispatch_table.pGLUniformMatrix3x4fv = OpenGL::vkglUniformMatrix3x4fv_with_validation;
    m_dispatch_table.pGLUniformMatrix4x2fv = OpenGL::vkglUniformMatrix4x2fv_with_validation;
    m_dispatch_table.pGLUniformMatrix4x3fv = OpenGL::vkglUniformMatrix4x3fv_with_validation;

    m_dispatch_table.pGLBeginConditionalRender              = OpenGL::vkglBeginConditionalRender_with_validation;
    m_dispatch_table.pGLBeginTransformFeedback              = OpenGL::vkglBeginTransformFeedback_with_validation;
    m_dispatch_table.pGLBindBufferBase                      = OpenGL::vkglBindBufferBase_with_validation;
    m_dispatch_table.pGLBindBufferRange                     = OpenGL::vkglBindBufferRange_with_validation;
    m_dispatch_table.pGLBindFragDataLocation                = OpenGL::vkglBindFragDataLocation_with_validation;
    m_dispatch_table.pGLBindFramebuffer                     = OpenGL::vkglBindFramebuffer_with_validation;
    m_dispatch_table.pGLBindRenderbuffer                    = OpenGL::vkglBindRenderbuffer_with_validation;
    m_dispatch_table.pGLBindVertexArray                     = OpenGL::vkglBindVertexArray_with_validation;
    m_dispatch_table.pGLBlitFramebuffer                     = OpenGL::vkglBlitFramebuffer_with_validation;
    m_dispatch_table.pGLCheckFramebufferStatus              = OpenGL::vkglCheckFramebufferStatus_with_validation;
    m_dispatch_table.pGLClampColor                          = OpenGL::vkglClampColor_with_validation;
    m_dispatch_table.pGLClearBufferfi                       = OpenGL::vkglClearBufferfi_with_validation;
    m_dispatch_table.pGLClearBufferfv                       = OpenGL::vkglClearBufferfv_with_validation;
    m_dispatch_table.pGLClearBufferiv                       = OpenGL::vkglClearBufferiv_with_validation;
    m_dispatch_table.pGLClearBufferuiv                      = OpenGL::vkglClearBufferuiv_with_validation;
    m_dispatch_table.pGLColorMaski                          = OpenGL::vkglColorMaski_with_validation;
    m_dispatch_table.pGLDeleteFramebuffers                  = OpenGL::vkglDeleteFramebuffers_with_validation;
    m_dispatch_table.pGLDeleteRenderbuffers                 = OpenGL::vkglDeleteRenderbuffers_with_validation;
    m_dispatch_table.pGLDeleteVertexArrays                  = OpenGL::vkglDeleteVertexArrays_with_validation;
    m_dispatch_table.pGLDisablei                            = OpenGL::vkglDisablei_with_validation;
    m_dispatch_table.pGLEnablei                             = OpenGL::vkglEnablei_with_validation;
    m_dispatch_table.pGLEndConditionalRender                = OpenGL::vkglEndConditionalRender_with_validation;
    m_dispatch_table.pGLEndTransformFeedback                = OpenGL::vkglEndTransformFeedback_with_validation;
    m_dispatch_table.pGLFlushMappedBufferRange              = OpenGL::vkglFlushMappedBufferRange_with_validation;
    m_dispatch_table.pGLFramebufferRenderbuffer             = OpenGL::vkglFramebufferRenderbuffer_with_validation;
    m_dispatch_table.pGLFramebufferTexture1D                = OpenGL::vkglFramebufferTexture1D_with_validation;
    m_dispatch_table.pGLFramebufferTexture2D                = OpenGL::vkglFramebufferTexture2D_with_validation;
    m_dispatch_table.pGLFramebufferTexture3D                = OpenGL::vkglFramebufferTexture3D_with_validation;
    m_dispatch_table.pGLFramebufferTextureLayer             = OpenGL::vkglFramebufferTextureLayer_with_validation;
    m_dispatch_table.pGLGenerateMipmap                      = OpenGL::vkglGenerateMipmap_with_validation;
    m_dispatch_table.pGLGenFramebuffers                     = OpenGL::vkglGenFramebuffers_with_validation;
    m_dispatch_table.pGLGenRenderbuffers                    = OpenGL::vkglGenRenderbuffers_with_validation;
    m_dispatch_table.pGLGenVertexArrays                     = OpenGL::vkglGenVertexArrays_with_validation;
    m_dispatch_table.pGLGetBooleani_v                       = OpenGL::vkglGetBooleani_v_with_validation;
    m_dispatch_table.pGLGetFragDataLocation                 = OpenGL::vkglGetFragDataLocation_with_validation;
    m_dispatch_table.pGLGetFramebufferAttachmentParameteriv = OpenGL::vkglGetFramebufferAttachmentParameteriv_with_validation;
    m_dispatch_table.pGLGetIntegeri_v                       = OpenGL::vkglGetIntegeri_v_with_validation;
    m_dispatch_table.pGLGetRenderbufferParameteriv          = OpenGL::vkglGetRenderbufferParameteriv_with_validation;
    m_dispatch_table.pGLGetStringi                          = OpenGL::vkglGetStringi_with_validation;
    m_dispatch_table.pGLGetTexParameterIiv                  = OpenGL::vkglGetTexParameterIiv_with_validation;
    m_dispatch_table.pGLGetTexParameterIuiv                 = OpenGL::vkglGetTexParameterIuiv_with_validation;
    m_dispatch_table.pGLGetTransformFeedbackVarying         = OpenGL::vkglGetTransformFeedbackVarying_with_validation;
    m_dispatch_table.pGLGetUniformuiv                       = OpenGL::vkglGetUniformuiv_with_validation;
    m_dispatch_table.pGLGetVertexAttribIiv                  = OpenGL::vkglGetVertexAttribIiv_with_validation;
    m_dispatch_table.pGLGetVertexAttribIuiv                 = OpenGL::vkglGetVertexAttribIuiv_with_validation;
    m_dispatch_table.pGLIsEnabledi                          = OpenGL::vkglIsEnabledi_with_validation;
    m_dispatch_table.pGLIsFramebuffer                       = OpenGL::vkglIsFramebuffer_with_validation;
    m_dispatch_table.pGLIsRenderbuffer                      = OpenGL::vkglIsRenderbuffer_with_validation;
    m_dispatch_table.pGLIsVertexArray                       = OpenGL::vkglIsVertexArray_with_validation;
    m_dispatch_table.pGLMapBufferRange                      = OpenGL::vkglMapBufferRange_with_validation;
    m_dispatch_table.pGLRenderbufferStorage                 = OpenGL::vkglRenderbufferStorage_with_validation;
    m_dispatch_table.pGLRenderbufferStorageMultisample      = OpenGL::vkglRenderbufferStorageMultisample_with_validation;
    m_dispatch_table.pGLTexParameterIiv                     = OpenGL::vkglTexParameterIiv_with_validation;
    m_dispatch_table.pGLTexParameterIuiv                    = OpenGL::vkglTexParameterIuiv_with_validation;
    m_dispatch_table.pGLTransformFeedbackVaryings           = OpenGL::vkglTransformFeedbackVaryings_with_validation;
    m_dispatch_table.pGLUniform1ui                          = OpenGL::vkglUniform1ui_with_validation;
    m_dispatch_table.pGLUniform1uiv                         = OpenGL::vkglUniform1uiv_with_validation;
    m_dispatch_table.pGLUniform2ui                          = OpenGL::vkglUniform2ui_with_validation;
    m_dispatch_table.pGLUniform2uiv                         = OpenGL::vkglUniform2uiv_with_validation;
    m_dispatch_table.pGLUniform3ui                          = OpenGL::vkglUniform3ui_with_validation;
    m_dispatch_table.pGLUniform3uiv                         = OpenGL::vkglUniform3uiv_with_validation;
    m_dispatch_table.pGLUniform4ui                          = OpenGL::vkglUniform4ui_with_validation;
    m_dispatch_table.pGLUniform4uiv                         = OpenGL::vkglUniform4uiv_with_validation;
    m_dispatch_table.pGLVertexAttribI1i                     = OpenGL::vkglVertexAttribI1i_with_validation;
    m_dispatch_table.pGLVertexAttribI1iv                    = OpenGL::vkglVertexAttribI1iv_with_validation;
    m_dispatch_table.pGLVertexAttribI1ui                    = OpenGL::vkglVertexAttribI1ui_with_validation;
    m_dispatch_table.pGLVertexAttribI1uiv                   = OpenGL::vkglVertexAttribI1uiv_with_validation;
    m_dispatch_table.pGLVertexAttribI2i                     = OpenGL::vkglVertexAttribI2i_with_validation;
    m_dispatch_table.pGLVertexAttribI2iv                    = OpenGL::vkglVertexAttribI2iv_with_validation;
    m_dispatch_table.pGLVertexAttribI2ui                    = OpenGL::vkglVertexAttribI2ui_with_validation;
    m_dispatch_table.pGLVertexAttribI2uiv                   = OpenGL::vkglVertexAttribI2uiv_with_validation;
    m_dispatch_table.pGLVertexAttribI3i                     = OpenGL::vkglVertexAttribI3i_with_validation;
    m_dispatch_table.pGLVertexAttribI3iv                    = OpenGL::vkglVertexAttribI3iv_with_validation;
    m_dispatch_table.pGLVertexAttribI3ui                    = OpenGL::vkglVertexAttribI3ui_with_validation;
    m_dispatch_table.pGLVertexAttribI3uiv                   = OpenGL::vkglVertexAttribI3uiv_with_validation;
    m_dispatch_table.pGLVertexAttribI4bv                    = OpenGL::vkglVertexAttribI4bv_with_validation;
    m_dispatch_table.pGLVertexAttribI4i                     = OpenGL::vkglVertexAttribI4i_with_validation;
    m_dispatch_table.pGLVertexAttribI4iv                    = OpenGL::vkglVertexAttribI4iv_with_validation;
    m_dispatch_table.pGLVertexAttribI4sv                    = OpenGL::vkglVertexAttribI4sv_with_validation;
    m_dispatch_table.pGLVertexAttribI4ubv                   = OpenGL::vkglVertexAttribI4ubv_with_validation;
    m_dispatch_table.pGLVertexAttribI4ui                    = OpenGL::vkglVertexAttribI4ui_with_validation;
    m_dispatch_table.pGLVertexAttribI4uiv                   = OpenGL::vkglVertexAttribI4uiv_with_validation;
    m_dispatch_table.pGLVertexAttribI4usv                   = OpenGL::vkglVertexAttribI4usv_with_validation;
    m_dispatch_table.pGLVertexAttribIPointer                = OpenGL::vkglVertexAttribIPointer_with_validation;

    m_dispatch_table.pGLCopyBufferSubData         = OpenGL::vkglCopyBufferSubData_with_validation;
    m_dispatch_table.pGLDrawArraysInstanced       = OpenGL::vkglDrawArraysInstanced_with_validation;
    m_dispatch_table.pGLDrawElementsInstanced     = OpenGL::vkglDrawElementsInstanced_with_validation;
    m_dispatch_table.pGLGetActiveUniformsiv       = OpenGL::vkglGetActiveUniformsiv_with_validation;
    m_dispatch_table.pGLGetActiveUniformBlockiv   = OpenGL::vkglGetActiveUniformBlockiv_with_validation;
    m_dispatch_table.pGLGetActiveUniformBlockName = OpenGL::vkglGetActiveUniformBlockName_with_validation;
    m_dispatch_table.pGLGetActiveUniformName      = OpenGL::vkglGetActiveUniformName_with_validation;
    m_dispatch_table.pGLGetUniformBlockIndex      = OpenGL::vkglGetUniformBlockIndex_with_validation;
    m_dispatch_table.pGLGetUniformIndices         = OpenGL::vkglGetUniformIndices_with_validation;
    m_dispatch_table.pGLPrimitiveRestartIndex     = OpenGL::vkglPrimitiveRestartIndex_with_validation;
    m_dispatch_table.pGLTexBuffer                 = OpenGL::vkglTexBuffer_with_validation;
    m_dispatch_table.pGLUniformBlockBinding       = OpenGL::vkglUniformBlockBinding_with_validation;

    m_dispatch_table.pGLClientWaitSync                  = OpenGL::vkglClientWaitSync_with_validation;
    m_dispatch_table.pGLDeleteSync                      = OpenGL::vkglDeleteSync_with_validation;
    m_dispatch_table.pGLDrawElementsBaseVertex          = OpenGL::vkglDrawElementsBaseVertex_with_validation;
    m_dispatch_table.pGLDrawElementsInstancedBaseVertex = OpenGL::vkglDrawElementsInstancedBaseVertex_with_validation;
    m_dispatch_table.pGLDrawRangeElementsBaseVertex     = OpenGL::vkglDrawRangeElementsBaseVertex_with_validation;
    m_dispatch_table.pGLFenceSync                       = OpenGL::vkglFenceSync_with_validation;
    m_dispatch_table.pGLFramebufferTexture              = OpenGL::vkglFramebufferTexture_with_validation;
    m_dispatch_table.pGLGetBufferParameteri64v          = OpenGL::vkglGetBufferParameteri64v_with_validation;
    m_dispatch_table.pGLGetInteger64i_v                 = OpenGL::vkglGetInteger64i_v_with_validation;
    m_dispatch_table.pGLGetInteger64v                   = OpenGL::vkglGetInteger64v_with_validation;
    m_dispatch_table.pGLGetMultisamplefv                = OpenGL::vkglGetMultisamplefv_with_validation;
    m_dispatch_table.pGLGetSynciv                       = OpenGL::vkglGetSynciv_with_validation;
    m_dispatch_table.pGLIsSync                          = OpenGL::vkglIsSync_with_validation;
    m_dispatch_table.pGLMultiDrawElementsBaseVertex     = OpenGL::vkglMultiDrawElementsBaseVertex_with_validation;
    m_dispatch_table.pGLProvokingVertex                 = OpenGL::vkglProvokingVertex_with_validation;
    m_dispatch_table.pGLSampleMaski                     = OpenGL::vkglSampleMaski_with_validation;
    m_dispatch_table.pGLTexImage2DMultisample           = OpenGL::vkglTexImage2DMultisample_with_validation;
    m_dispatch_table.pGLTexImage3DMultisample           = OpenGL::vkglTexImage3DMultisample_with_validation;
    m_dispatch_table.pGLWaitSync                        = OpenGL::vkglWaitSync_with_validation;

    result = true;
    return result;
}

bool OpenGL::Context::init_supported_extensions()
{
    bool result = false;

    vkgl_assert(m_supported_extensions.size() == 0);

    /* TODO: This array should probably be generated by an external Python script executed at cmake build time
     *       by looking up directory names under OpenGL/entrypoints and excluding everything that starts with GL{number}* ..
     */
    m_supported_extensions =
    {
        "GL_ARB_color_buffer_float",
        "GL_ARB_copy_buffer",
        "GL_ARB_depth_buffer_float",
        "GL_ARB_depth_clamp",
        "GL_ARB_depth_texture",
        "GL_ARB_draw_buffers",
        "GL_ARB_draw_elements_base_vertex",
        "GL_ARB_draw_instanced",
        "GL_ARB_fragment_coord_conventions",
        "GL_ARB_fragment_program_shadow",
        "GL_ARB_fragment_shader",
        "GL_ARB_framebuffer_object",
        "GL_ARB_framebuffer_sRGB",
        "GL_ARB_half_float_pixel",
        "GL_ARB_half_float_vertex",
        "GL_ARB_map_buffer_range",
        "GL_ARB_multisample",
        "GL_ARB_multitexture",
        "GL_ARB_occlusion_query",
        "GL_ARB_pixel_buffer_object",
        "GL_ARB_point_parameters",
        "GL_ARB_point_sprite",
        "GL_ARB_provoking_vertex",
        "GL_ARB_seamless_cube_map",
        "GL_ARB_shader_texture_lod",
        "GL_ARB_shading_language_100",
        "GL_ARB_shadow",
        "GL_ARB_sync",
        "GL_ARB_texture_border_clamp",
        "GL_ARB_texture_buffer_object",
        "GL_ARB_texture_compression",
        "GL_ARB_texture_compression_rgtc",
        "GL_ARB_texture_cube_map",
        "GL_ARB_texture_cube_map_array",
        "GL_ARB_texture_float",
        "GL_ARB_texture_gather",
        "GL_ARB_texture_mirrored_repeat",
        "GL_ARB_texture_multisample",
        "GL_ARB_texture_non_power_of_two",
        "GL_ARB_texture_query_lod",
        "GL_ARB_texture_rectangle",
        "GL_ARB_texture_rg",
        "GL_ARB_uniform_buffer_object",
        "GL_ARB_vertex_array_bgra",
        "GL_ARB_vertex_array_object",
        "GL_ARB_vertex_buffer_object",
        "GL_ARB_vertex_program",
        "GL_ARB_vertex_shader"
    };

    result = true;
end:
    return result;
}

bool OpenGL::Context::is_buffer(const GLuint& in_id) const
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);

    return m_gl_buffer_manager_ptr->is_alive_id(in_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_enabled(const OpenGL::Capability& in_capability) const
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    return m_gl_state_manager_ptr->is_enabled(in_capability);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_enabled_indexed(const OpenGL::Capability& in_capability,
                                         const GLuint&             in_index) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_framebuffer(const GLuint& in_framebuffer) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_program(const GLuint& in_program) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_query(const GLuint& in_id) const
{
#if 0
    vkgl_assert(m_gl_query_manager_ptr != nullptr);

    return m_gl_query_manager_ptr->is_alive_id(in_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_renderbuffer(const GLuint& in_renderbuffer) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_shader(const GLuint& in_shader) const
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_sync(const GLsync& in_sync)
{
    vkgl_not_implemented();

    return false;
}

bool OpenGL::Context::is_texture(const GLuint& in_texture) const
{
#if 0
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    return m_gl_texture_manager_ptr->is_alive_id(in_texture);
#else
    vkgl_not_implemented();

    return false;
#endif
}

bool OpenGL::Context::is_vertex_array(const GLuint& in_array) const
{
    vkgl_not_implemented();

    return false;
}

void OpenGL::Context::link_program(const GLuint& in_program)
{
    vkgl_not_implemented();
}

void* OpenGL::Context::map_buffer(const OpenGL::BufferTarget& in_target,
                                  const OpenGL::BufferAccess& in_access)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    return m_scheduler_ptr->map_buffer(in_target,
                                       in_access);
#else
    vkgl_not_implemented();

    return nullptr;
#endif
}

void* OpenGL::Context::map_buffer_range(const OpenGL::BufferTarget& in_target,
                                        const GLintptr&             in_offset,
                                        const GLsizeiptr&           in_length,
                                        const OpenGL::BufferAccess& in_access)
{
    vkgl_not_implemented();

    return nullptr;
}

void OpenGL::Context::multi_draw_arrays(const OpenGL::DrawCallMode& in_mode,
                                        const GLint*                in_first_ptr,
                                        const GLsizei*              in_count_ptr,
                                        const GLsizei&              in_drawcount)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->multi_draw_arrays(in_mode,
                                       in_first_ptr,
                                       in_count_ptr,
                                       in_drawcount);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::multi_draw_elements(const OpenGL::DrawCallMode&      in_mode,
                                          const GLsizei*                   in_count_ptr,
                                          const OpenGL::DrawCallIndexType& in_type,
                                          const void* const*               in_indices_ptr,
                                          const GLsizei&                   in_drawcount)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->multi_draw_elements(in_mode,
                                         in_count_ptr,
                                         in_type,
                                         in_indices_ptr,
                                         in_drawcount);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::multi_draw_elements_base_vertex(const OpenGL::DrawCallMode&      in_mode,
                                                      const GLsizei*                   in_count_ptr,
                                                      const OpenGL::DrawCallIndexType& in_type,
                                                      const void* const*               in_indices_ptr,
                                                      const GLsizei&                   in_drawcount,
                                                      const GLint*                     in_basevertex_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::read_pixels(const int32_t&             in_x,
                                  const int32_t&             in_y,
                                  const size_t&              in_width,
                                  const size_t&              in_height,
                                  const OpenGL::PixelFormat& in_format,
                                  const OpenGL::PixelType&   in_type,
                                  void*                      out_pixels_ptr)
{
#if 0
    vkgl_assert(m_scheduler_ptr != nullptr);

    m_scheduler_ptr->read_pixels(in_x,
                                 in_y,
                                 in_width,
                                 in_height,
                                 in_format,
                                 in_type,
                                 out_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::set_active_texture(const uint32_t& in_n_texture_unit)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_active_texture(in_n_texture_unit);
}

void OpenGL::Context::set_blend_color(const float& in_red,
                                      const float& in_green,
                                      const float& in_blue,
                                      const float& in_alpha)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_color(in_red,
                                            in_green,
                                            in_blue,
                                            in_alpha);
}

void OpenGL::Context::set_blend_equation(const OpenGL::BlendEquation& in_blend_equation)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_equation(in_blend_equation);
}

void OpenGL::Context::set_blend_equation_separate(const OpenGL::BlendEquation& in_modeRGB,
                                                  const OpenGL::BlendEquation& in_modeAlpha)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_blend_functions(const OpenGL::BlendFunction& in_src_rgba_function,
                                          const OpenGL::BlendFunction& in_dst_rgba_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions(in_src_rgba_function,
                                                in_dst_rgba_function);
}

void OpenGL::Context::set_blend_functions_separate(const OpenGL::BlendFunction& in_src_rgb_function,
                                                   const OpenGL::BlendFunction& in_dst_rgb_function,
                                                   const OpenGL::BlendFunction& in_src_alpha_function,
                                                   const OpenGL::BlendFunction& in_dst_alpha_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_blend_functions_separate(in_src_rgb_function,
                                                         in_dst_rgb_function,
                                                         in_src_alpha_function,
                                                         in_dst_alpha_function);
}

void OpenGL::Context::set_clamp_color(const bool& in_enable)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_clear_color_value(const float& in_red,
                                            const float& in_green,
                                            const float& in_blue,
                                            const float& in_alpha)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_color_value(in_red,
                                                  in_green,
                                                  in_blue,
                                                  in_alpha);
}

void OpenGL::Context::set_clear_depth_value(const double& in_value)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_depth_value(in_value);
}

void OpenGL::Context::set_clear_stencil_value(const int& in_value)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_clear_stencil_value(in_value);
}

void OpenGL::Context::set_color_mask(const bool& in_red,
                                     const bool& in_green,
                                     const bool& in_blue,
                                     const bool& in_alpha)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_color_mask(in_red,
                                           in_green,
                                           in_blue,
                                           in_alpha);
}

void OpenGL::Context::set_color_mask_indexed(const GLuint& in_index,
                                             const bool&   in_r,
                                             const bool&   in_g,
                                             const bool&   in_b,
                                             const bool&   in_a)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_cull_mode(const OpenGL::CullMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_cull_mode(in_mode);
}

void OpenGL::Context::set_depth_function(const OpenGL::DepthFunction& in_function)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_function(in_function);
}

void OpenGL::Context::set_depth_mask(const bool& in_flag)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_mask(in_flag);
}

void OpenGL::Context::set_depth_range(const double& in_near,
                                      const double& in_far)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_depth_range(in_near,
                                            in_far);
}

void OpenGL::Context::set_draw_buffer(const OpenGL::DrawBuffer& in_draw_buffer)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_draw_buffer(in_draw_buffer);
}

void OpenGL::Context::set_draw_buffers(const GLsizei&            in_n,
                                       const OpenGL::DrawBuffer* in_bufs_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_front_face_orientation(const OpenGL::FrontFaceOrientation& in_orientation)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_front_face_orientation(in_orientation);
}

void OpenGL::Context::set_hint(const OpenGL::HintTarget& in_target,
                               const OpenGL::HintMode&   in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_hint(in_target,
                                     in_mode);
}

void OpenGL::Context::set_line_width(const float& in_width)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_line_width(in_width);
}

void OpenGL::Context::set_logic_op(const OpenGL::LogicOpMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_logic_op(in_mode);
}

void OpenGL::Context::set_matrix_uniform(const GLint&    in_location,
                                         const uint32_t& in_n_columns,
                                         const uint32_t& in_n_rows,
                                         const uint32_t& in_n_array_items,
                                         const bool&     in_transpose,
                                         const GLfloat*  in_value_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_pixel_store_property(const OpenGL::PixelStoreProperty& in_property,
                                               const OpenGL::GetSetArgumentType& in_arg_type,
                                               const void*                     in_arg_value_ptr)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_pixel_store_property(in_property,
                                                     in_arg_type,
                                                     in_arg_value_ptr);
}

void OpenGL::Context::set_point_property(const OpenGL::PointProperty&      in_property,
                                         const OpenGL::GetSetArgumentType& in_arg_type,
                                         const void*                       in_arg_value_ptr)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_property(in_property,
                                               in_arg_type,
                                               in_arg_value_ptr);
}

void OpenGL::Context::set_point_size(const float& in_size)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_point_size(in_size);
}

void OpenGL::Context::set_polygon_mode(const OpenGL::PolygonMode& in_mode)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_mode(in_mode);
}

void OpenGL::Context::set_polygon_offset(const GLfloat& in_factor,
                                         const GLfloat& in_units)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_polygon_offset(in_factor,
                                               in_units);
}

void OpenGL::Context::set_primitive_restart_index(const GLuint& in_index)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_provoking_vertex(const OpenGL::ProvokingVertexConvention& in_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_read_buffer(const OpenGL::ReadBuffer& in_read_buffer)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_read_buffer(in_read_buffer);
}

void OpenGL::Context::set_renderbuffer_storage(const OpenGL::RenderbufferTarget& in_target,
                                               const OpenGL::InternalFormat&     in_internalformat,
                                               const GLsizei&                    in_width,
                                               const GLsizei&                    in_height)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_renderbuffer_storage_multisample(const OpenGL::RenderbufferTarget& in_target,
                                                           const GLsizei&                    in_samples,
                                                           const OpenGL::InternalFormat&     in_internalformat,
                                                           const GLsizei&                    in_width,
                                                           const GLsizei&                    in_height)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_sample_coverage(const GLfloat&   in_value,
                                          const GLboolean& in_invert)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_sample_coverage(in_value,
                                                (in_invert == GL_TRUE) );
}

void OpenGL::Context::set_sample_mask_indexed(const GLuint&     in_mask_number,
                                              const GLbitfield& in_mask)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_scissor(const int32_t& in_x,
                                  const int32_t& in_y,
                                  const size_t&  in_width,
                                  const size_t&  in_height)
{            
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_scissor(in_x,
                                        in_y,
                                        in_width,
                                        in_height);
}

void OpenGL::Context::set_shader_source(const GLuint&        in_shader,
                                        const GLsizei&       in_count,
                                        const GLchar* const* in_string_ptr_ptr,
                                        const GLint*         in_length_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_function(const OpenGL::StencilFunction& in_func,
                                           const int32_t&                 in_ref,
                                           const uint32_t&                in_mask)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_function(in_func,
                                                 in_ref,
                                                 in_mask);
}

void OpenGL::Context::set_stencil_function_separate(const OpenGL::StencilStateFace& in_face,
                                                    const OpenGL::StencilFunction&  in_func,
                                                    const GLint&                    in_ref,
                                                    const GLuint&                   in_mask)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_mask(const uint32_t& in_mask)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_mask(in_mask);
}

void OpenGL::Context::set_stencil_mask_separate(const OpenGL::StencilStateFace& in_face,
                                                const GLuint&                   in_mask)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_stencil_operations(const OpenGL::StencilOperation& in_fail,
                                             const OpenGL::StencilOperation& in_zfail,
                                             const OpenGL::StencilOperation& in_zpass)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_stencil_operations(in_fail,
                                                   in_zfail,
                                                   in_zpass);
}

void OpenGL::Context::set_stencil_operations_separate(const OpenGL::StencilStateFace& in_face,
                                                      const OpenGL::StencilOperation& in_sfail,
                                                      const OpenGL::StencilOperation& in_dpfail,
                                                      const OpenGL::StencilOperation& in_dppass)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_texture_parameter(const OpenGL::TextureTarget&      in_target,
                                            const OpenGL::TextureProperty&    in_property,
                                            const OpenGL::GetSetArgumentType& in_arg_type,
                                            const void*                       in_arg_value_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr   != nullptr);
    vkgl_assert(m_gl_texture_manager_ptr != nullptr);

    const auto& context_state_ptr   = m_gl_state_manager_ptr->get_state();
    const auto  active_texture_unit = context_state_ptr->active_texture_unit;
    const auto  texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                  in_target);

    if (texture_id != 0)
    {
        m_gl_texture_manager_ptr->set_texture_parameter(in_property,
                                                        in_arg_type,
                                                        in_arg_value_ptr);
    }
    else
    {
        vkgl_assert_fail();
    }
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::set_transform_feedback_varyings(const GLuint&                              in_program,
                                                      const GLsizei&                             in_count,
                                                      const GLchar* const*                       in_varyings_ptr_ptr,
                                                      const OpenGL::TransformFeedbackBufferMode& in_buffer_mode)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_uniform(const GLint&                      in_location,
                                  const OpenGL::GetSetArgumentType& in_data_type,
                                  const uint32_t&                   in_n_components,
                                  const uint32_t&                   in_n_array_items,
                                  const void*                       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_uniform_block_binding(const GLuint& in_program,
                                                const GLuint& in_uniform_block_index,
                                                const GLuint& in_uniform_block_binding)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_vertex_attribute(const GLuint&                     in_index,
                                           const OpenGL::GetSetArgumentType& in_src_type,
                                           const OpenGL::GetSetArgumentType& in_dst_type,
                                           const uint32_t&                   in_n_components,
                                           const bool&                       in_normalized,
                                           const void*                       in_data_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_vertex_attrib_pointer(const GLuint&                     in_index,
                                                const GLint&                      in_size,
                                                const OpenGL::VariableType&       in_type,
                                                const OpenGL::GetSetArgumentType& in_data_type,
                                                const bool&                       in_normalized,
                                                const GLsizei&                    in_stride,
                                                const void*                       in_pointer_ptr)
{
    vkgl_not_implemented();
}

void OpenGL::Context::set_viewport(const int32_t& in_x,
                                   const int32_t& in_y,
                                   const size_t&  in_width,
                                   const size_t&  in_height)
{
    vkgl_assert(m_gl_state_manager_ptr != nullptr);

    m_gl_state_manager_ptr->set_viewport(in_x,
                                         in_y,
                                         in_width,
                                         in_height);
}

void OpenGL::Context::tex_buffer(const OpenGL::InternalFormat& in_internalformat,
                                 const GLuint&                 in_buffer)
{
    vkgl_not_implemented();
}

void OpenGL::Context::tex_image_1d(const OpenGL::TextureTarget&  in_target,
                                   const int32_t&                in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const int32_t&                in_width,
                                   const int32_t&                in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_image_1d(texture_id,
                                  in_level,
                                  in_internalformat,
                                  in_width,
                                  in_border,
                                  in_format,
                                  in_type,
                                  in_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_image_2d(const OpenGL::TextureTarget&  in_target,
                                   const GLint&                  in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const GLsizei&                in_width,
                                   const GLsizei&                in_height,
                                   const GLint&                  in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_image_2d(texture_id,
                                  in_level,
                                  in_internalformat,
                                  in_width,
                                  in_height,
                                  in_border,
                                  in_format,
                                  in_type,
                                  in_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_image_2d_multisample(const OpenGL::TextureTarget&  in_target,
                                               const GLsizei&                in_samples,
                                               const OpenGL::InternalFormat& in_internalformat,
                                               const GLsizei&                in_width,
                                               const GLsizei&                in_height,
                                               const bool&                   in_fixedsamplelocations)
{
    vkgl_not_implemented();
}

void OpenGL::Context::tex_image_3d(const OpenGL::TextureTarget&  in_target,
                                   const GLint&                  in_level,
                                   const OpenGL::InternalFormat& in_internalformat,
                                   const GLsizei&                in_width,
                                   const GLsizei&                in_height,
                                   const GLsizei&                in_depth,
                                   const GLint&                  in_border,
                                   const OpenGL::PixelFormat&    in_format,
                                   const OpenGL::PixelType&      in_type,
                                   const void*                   in_pixels_ptr)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_image_3d(texture_id,
                                  in_level,
                                  in_internalformat,
                                  in_width,
                                  in_height,
                                  in_depth,
                                  in_border,
                                  in_format,
                                  in_type,
                                  in_pixels_ptr);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_image_3d_multisample(const OpenGL::TextureTarget&  in_target,
                                               const GLsizei&                in_samples,
                                               const OpenGL::InternalFormat& in_internalformat,
                                               const GLsizei&                in_width,
                                               const GLsizei&                in_height,
                                               const GLsizei&                in_depth,
                                               const bool&                   in_fixedsamplelocations)
{
    vkgl_not_implemented();
}

void OpenGL::Context::tex_sub_image_1d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLsizei&               in_width,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_sub_image_1d(texture_id,
                                      in_level,
                                      in_xoffset,
                                      in_width,
                                      in_format,
                                      in_type,
                                      in_pixels);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_sub_image_2d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLsizei&               in_width,
                                       const GLsizei&               in_height,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_sub_image_2d(texture_id,
                                      in_level,
                                      in_xoffset,
                                      in_yoffset,
                                      in_width,
                                      in_height,
                                      in_format,
                                      in_type,
                                      in_pixels);
#else
    vkgl_not_implemented();
#endif
}

void OpenGL::Context::tex_sub_image_3d(const OpenGL::TextureTarget& in_target,
                                       const GLint&                 in_level,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLint&                 in_zoffset,
                                       const GLsizei&               in_width,
                                       const GLsizei&               in_height,
                                       const GLsizei&               in_depth,
                                       const OpenGL::PixelFormat&   in_format,
                                       const OpenGL::PixelType&     in_type,
                                       const void*                  in_pixels)
{
#if 0
    vkgl_assert(m_gl_state_manager_ptr != nullptr);
    vkgl_assert(m_scheduler_ptr        != nullptr);

    const auto active_texture_unit = m_gl_state_manager_ptr->get_state()->active_texture_unit;
    const auto texture_id          = m_gl_state_manager_ptr->get_texture_binding(active_texture_unit,
                                                                                 in_target);

    m_scheduler_ptr->tex_sub_image_3d(texture_id,
                                      in_level,
                                      in_xoffset,
                                      in_yoffset,
                                      in_zoffset,
                                      in_width,
                                      in_height,
                                      in_depth,
                                      in_format,
                                      in_type,
                                      in_pixels);
#else
    vkgl_not_implemented();
#endif
}

bool OpenGL::Context::unmap_buffer(const OpenGL::BufferTarget& in_target)
{
#if 0
    vkgl_assert(m_gl_buffer_manager_ptr != nullptr);
    vkgl_assert(m_gl_state_manager_ptr  != nullptr);

    const auto buffer_id = m_gl_state_manager_ptr->get_buffer_binding(in_target);
    vkgl_assert(buffer_id != 0);

    return m_scheduler_ptr->unmap_buffer(buffer_id);
#else
    vkgl_not_implemented();

    return false;
#endif
}

void OpenGL::Context::use_program(const GLuint& in_program)
{
    vkgl_not_implemented();
}

void OpenGL::Context::validate_program(const GLuint& in_program)
{
    vkgl_not_implemented();
}

void OpenGL::Context::wait_sync(const GLsync&   in_sync,
                                const GLuint64& in_timeout)
{
    vkgl_not_implemented();
}
