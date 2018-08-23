/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
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

#include "OpenGL/globals.h"
#include "OpenGL/interceptors.h"

std::unordered_map<std::string, void*> opengl32_get_func_name_to_func_ptr_map()
{
    /* >= GL 1.2 */
    std::unordered_map<std::string, void*> result;

    result["glCopyTexSubImage3D"] = vkglCopyTexSubImage3D;
    result["glDrawRangeElements"] = vkglDrawRangeElements;
    result["glTexImage3D"]        = vkglTexImage3D;
    result["glTexSubImage3D"]     = vkglTexSubImage3D;

    result["glActiveTexture"]           = vkglActiveTexture;
    result["glCompressedTexImage1D"]    = vkglCompressedTexImage1D;
    result["glCompressedTexImage2D"]    = vkglCompressedTexImage2D;
    result["glCompressedTexImage3D"]    = vkglCompressedTexImage3D;
    result["glCompressedTexSubImage1D"] = vkglCompressedTexSubImage1D;
    result["glCompressedTexSubImage2D"] = vkglCompressedTexSubImage2D;
    result["glCompressedTexSubImage3D"] = vkglCompressedTexSubImage3D;
    result["glGetCompressedTexImage"]   = vkglGetCompressedTexImage;
    result["glSampleCoverage"]          = vkglSampleCoverage;

    result["glBlendColor"]        = vkglBlendColor;
    result["glBlendEquation"]     = vkglBlendEquation;
    result["glBlendFuncSeparate"] = vkglBlendFuncSeparate;
    result["glMultiDrawArrays"]   = vkglMultiDrawArrays;
    result["glMultiDrawElements"] = vkglMultiDrawElements;
    result["glPointParameterf"]   = vkglPointParameterf;
    result["glPointParameterfv"]  = vkglPointParameterfv;
    result["glPointParameteri"]   = vkglPointParameteri;
    result["glPointParameteriv"]  = vkglPointParameteriv;

    result["glBeginQuery"]           = vkglBeginQuery;
    result["glBindBuffer"]           = vkglBindBuffer;
    result["glBufferData"]           = vkglBufferData;
    result["glBufferSubData"]        = vkglBufferSubData;
    result["glDeleteBuffers"]        = vkglDeleteBuffers;
    result["glDeleteQueries"]        = vkglDeleteQueries;
    result["glEndQuery"]             = vkglEndQuery;
    result["glGenBuffers"]           = vkglGenBuffers;
    result["glGenQueries"]           = vkglGenQueries;
    result["glGetBufferParameteriv"] = vkglGetBufferParameteriv;
    result["glGetBufferPointerv"]    = vkglGetBufferPointerv;
    result["glGetBufferSubData"]     = vkglGetBufferSubData;
    result["glGetQueryiv"]           = vkglGetQueryiv;
    result["glGetQueryObjectiv"]     = vkglGetQueryObjectiv;
    result["glGetQueryObjectuiv"]    = vkglGetQueryObjectuiv;
    result["glIsBuffer"]             = vkglIsBuffer;
    result["glIsQuery"]              = vkglIsQuery;
    result["glMapBuffer"]            = vkglMapBuffer;
    result["glUnmapBuffer"]          = vkglUnmapBuffer;

    result["glAttachShader"]             = vkglAttachShader;
    result["glBindAttribLocation"]       = vkglBindAttribLocation;
    result["glBlendEquationSeparate"]    = vkglBlendEquationSeparate;
    result["glCompileShader"]            = vkglCompileShader;
    result["glCreateProgram"]            = vkglCreateProgram;
    result["glCreateShader"]             = vkglCreateShader;
    result["glDeleteProgram"]            = vkglDeleteProgram;
    result["glDeleteShader"]             = vkglDeleteShader;
    result["glDetachShader"]             = vkglDetachShader;
    result["glDisableVertexAttribArray"] = vkglDisableVertexAttribArray;
    result["glDrawBuffers"]              = vkglDrawBuffers;
    result["glEnableVertexAttribArray"]  = vkglEnableVertexAttribArray;
    result["glGetActiveAttrib"]          = vkglGetActiveAttrib;
    result["glGetActiveUniform"]         = vkglGetActiveUniform;
    result["glGetAttachedShaders"]       = vkglGetAttachedShaders;
    result["glGetAttribLocation"]        = vkglGetAttribLocation;
    result["glGetProgramiv"]             = vkglGetProgramiv;
    result["glGetProgramInfoLog"]        = vkglGetProgramInfoLog;
    result["glGetShaderiv"]              = vkglGetShaderiv;
    result["glGetShaderInfoLog"]         = vkglGetShaderInfoLog;
    result["glGetShaderSource"]          = vkglGetShaderSource;
    result["glGetUniformfv"]             = vkglGetUniformfv;
    result["glGetUniformiv"]             = vkglGetUniformiv;
    result["glGetUniformLocation"]       = vkglGetUniformLocation;
    result["glGetVertexAttribdv"]        = vkglGetVertexAttribdv;
    result["glGetVertexAttribfv"]        = vkglGetVertexAttribfv;
    result["glGetVertexAttribiv"]        = vkglGetVertexAttribiv;
    result["glGetVertexAttribPointerv"]  = vkglGetVertexAttribPointerv;
    result["glIsProgram"]                = vkglIsProgram;
    result["glIsShader"]                 = vkglIsShader;
    result["glLinkProgram"]              = vkglLinkProgram;
    result["glShaderSource"]             = vkglShaderSource;
    result["glStencilFuncSeparate"]      = vkglStencilFuncSeparate;
    result["glStencilMaskSeparate"]      = vkglStencilMaskSeparate;
    result["glStencilOpSeparate"]        = vkglStencilOpSeparate;
    result["glUniform1f"]                = vkglUniform1f;
    result["glUniform1fv"]               = vkglUniform1fv;
    result["glUniform1i"]                = vkglUniform1i;
    result["glUniform1iv"]               = vkglUniform1iv;
    result["glUniform2f"]                = vkglUniform2f;
    result["glUniform2fv"]               = vkglUniform2fv;
    result["glUniform2i"]                = vkglUniform2i;
    result["glUniform2iv"]               = vkglUniform2iv;
    result["glUniform3f"]                = vkglUniform3f;
    result["glUniform3fv"]               = vkglUniform3fv;
    result["glUniform3i"]                = vkglUniform3i;
    result["glUniform3iv"]               = vkglUniform3iv;
    result["glUniform4f"]                = vkglUniform4f;
    result["glUniform4fv"]               = vkglUniform4fv;
    result["glUniform4i"]                = vkglUniform4i;
    result["glUniform4iv"]               = vkglUniform4iv;
    result["glUniformMatrix2fv"]         = vkglUniformMatrix2fv;
    result["glUniformMatrix3fv"]         = vkglUniformMatrix3fv;
    result["glUniformMatrix4fv"]         = vkglUniformMatrix4fv;
    result["glUseProgram"]               = vkglUseProgram;
    result["glValidateProgram"]          = vkglValidateProgram;
    result["glVertexAttrib1d"]           = vkglVertexAttrib1d;
    result["glVertexAttrib1dv"]          = vkglVertexAttrib1dv;
    result["glVertexAttrib1f"]           = vkglVertexAttrib1f;
    result["glVertexAttrib1fv"]          = vkglVertexAttrib1fv;
    result["glVertexAttrib1s"]           = vkglVertexAttrib1s;
    result["glVertexAttrib1sv"]          = vkglVertexAttrib1sv;
    result["glVertexAttrib2d"]           = vkglVertexAttrib2d;
    result["glVertexAttrib2dv"]          = vkglVertexAttrib2dv;
    result["glVertexAttrib2f"]           = vkglVertexAttrib2f;
    result["glVertexAttrib2fv"]          = vkglVertexAttrib2fv;
    result["glVertexAttrib2s"]           = vkglVertexAttrib2s;
    result["glVertexAttrib2sv"]          = vkglVertexAttrib2sv;
    result["glVertexAttrib3d"]           = vkglVertexAttrib3d;
    result["glVertexAttrib3dv"]          = vkglVertexAttrib3dv;
    result["glVertexAttrib3f"]           = vkglVertexAttrib3f;
    result["glVertexAttrib3fv"]          = vkglVertexAttrib3fv;
    result["glVertexAttrib3s"]           = vkglVertexAttrib3s;
    result["glVertexAttrib3sv"]          = vkglVertexAttrib3sv;
    result["glVertexAttrib4bv"]          = vkglVertexAttrib4bv;
    result["glVertexAttrib4d"]           = vkglVertexAttrib4d;
    result["glVertexAttrib4dv"]          = vkglVertexAttrib4dv;
    result["glVertexAttrib4f"]           = vkglVertexAttrib4f;
    result["glVertexAttrib4fv"]          = vkglVertexAttrib4fv;
    result["glVertexAttrib4iv"]          = vkglVertexAttrib4iv;
    result["glVertexAttrib4Nbv"]         = vkglVertexAttrib4Nbv;
    result["glVertexAttrib4Niv"]         = vkglVertexAttrib4Niv;
    result["glVertexAttrib4Nsv"]         = vkglVertexAttrib4Nsv;
    result["glVertexAttrib4Nub"]         = vkglVertexAttrib4Nub;
    result["glVertexAttrib4Nubv"]        = vkglVertexAttrib4Nubv;
    result["glVertexAttrib4Nuiv"]        = vkglVertexAttrib4Nuiv;
    result["glVertexAttrib4Nusv"]        = vkglVertexAttrib4Nusv;
    result["glVertexAttrib4s"]           = vkglVertexAttrib4s;
    result["glVertexAttrib4sv"]          = vkglVertexAttrib4sv;
    result["glVertexAttrib4ubv"]         = vkglVertexAttrib4ubv;
    result["glVertexAttrib4uiv"]         = vkglVertexAttrib4uiv;
    result["glVertexAttrib4usv"]         = vkglVertexAttrib4usv;
    result["glVertexAttribPointer"]      = vkglVertexAttribPointer;

    result["glUniformMatrix2x3fv"] = vkglUniformMatrix2x3fv;
    result["glUniformMatrix2x4fv"] = vkglUniformMatrix2x4fv;
    result["glUniformMatrix3x2fv"] = vkglUniformMatrix3x2fv;
    result["glUniformMatrix3x4fv"] = vkglUniformMatrix3x4fv;
    result["glUniformMatrix4x2fv"] = vkglUniformMatrix4x2fv;
    result["glUniformMatrix4x3fv"] = vkglUniformMatrix4x3fv;

    result["glBeginConditionalRender"]                              = vkglBeginConditionalRender;
    result["glBeginTransformFeedback"]                              = vkglBeginTransformFeedback;
    result["glBindBufferBase"]                                      = vkglBindBufferBase;
    result["glBindBufferRange"]                                     = vkglBindBufferRange;
    result["glBindFragDataLocation"]                                = vkglBindFragDataLocation;
    result["glBindFramebuffer"]                                     = vkglBindFramebuffer;
    result["glBindRenderbuffer"]                                    = vkglBindRenderbuffer;
    result["glBindVertexArray"]                                     = vkglBindVertexArray;
    result["glBlitFramebuffer"]                                     = vkglBlitFramebuffer;
    result["glCheckFramebufferStatus"]                              = vkglCheckFramebufferStatus;
    result["glClampColor"]                                          = vkglClampColor;
    result["glClearBufferfi"]                                       = vkglClearBufferfi;
    result["glClearBufferfv"]                                       = vkglClearBufferfv;
    result["glClearBufferiv"]                                       = vkglClearBufferiv;
    result["glClearBufferuiv"]                                      = vkglClearBufferuiv;
    result["glColorMaski"]                                          = vkglColorMaski;
    result["glDeleteFramebuffers"]                                  = vkglDeleteFramebuffers;
    result["glDeleteRenderbuffers"]                                 = vkglDeleteRenderbuffers;
    result["glDeleteVertexArrays"]                                  = vkglDeleteVertexArrays;
    result["glDisablei"]                                            = vkglDisablei;
    result["glEnablei"]                                             = vkglEnablei;
    result["glEndConditionalRender"]                                = vkglEndConditionalRender;
    result["glEndTransformFeedback"]                                = vkglEndTransformFeedback;
    result["glFlushMappedBufferRange"]                              = vkglFlushMappedBufferRange;
    result["glFramebufferRenderbuffer"]                             = vkglFramebufferRenderbuffer;
    result["glFramebufferTexture1D"]                                = vkglFramebufferTexture1D;
    result["glFramebufferTexture2D"]                                = vkglFramebufferTexture2D;
    result["glFramebufferTexture3D"]                                = vkglFramebufferTexture3D;
    result["glFramebufferTextureLayer"]                             = vkglFramebufferTextureLayer;
    result["glGenerateMipmap"]                                      = vkglGenerateMipmap;
    result["glGenFramebuffers"]                                     = vkglGenFramebuffers;
    result["glGenRenderbuffers"]                                    = vkglGenRenderbuffers;
    result["glGenVertexArrays"]                                     = vkglGenVertexArrays;
    result["glGetBooleani_v"]                                       = vkglGetBooleani_v;
    result["glGetFragDataLocation"]                                 = vkglGetFragDataLocation;
    result["glGetFramebufferAttachmentParameteriv"] = vkglGetFramebufferAttachmentParameteriv;
    result["glGetIntegeri_v"]                                       = vkglGetIntegeri_v;
    result["glGetRenderbufferParameteriv"]                          = vkglGetRenderbufferParameteriv;
    result["glGetStringi"]                                          = vkglGetStringi;
    result["glGetTexParameterIiv"]                                  = vkglGetTexParameterIiv;
    result["glGetTexParameterIuiv"]                                 = vkglGetTexParameterIuiv;
    result["glGetTransformFeedbackVarying"]                         = vkglGetTransformFeedbackVarying;
    result["glGetUniformuiv"]                                       = vkglGetUniformuiv;
    result["glGetVertexAttribIiv"]                                  = vkglGetVertexAttribIiv;
    result["glGetVertexAttribIuiv"]                                 = vkglGetVertexAttribIuiv;
    result["glIsEnabledi"]                                          = vkglIsEnabledi;
    result["glIsFramebuffer"]                                       = vkglIsFramebuffer;
    result["glIsRenderbuffer"]                                      = vkglIsRenderbuffer;
    result["glIsVertexArray"]                                       = vkglIsVertexArray;
    result["glMapBufferRange"]                                      = vkglMapBufferRange;
    result["glRenderbufferStorage"]                                 = vkglRenderbufferStorage;
    result["glRenderbufferStorageMultisample"]                      = vkglRenderbufferStorageMultisample;
    result["glTexParameterIiv"]                                     = vkglTexParameterIiv;
    result["glTexParameterIuiv"]                                    = vkglTexParameterIuiv;
    result["glTransformFeedbackVaryings"]                           = vkglTransformFeedbackVaryings;
    result["glUniform1ui"]                                          = vkglUniform1ui;
    result["glUniform1uiv"]                                         = vkglUniform1uiv;
    result["glUniform2ui"]                                          = vkglUniform2ui;
    result["glUniform2uiv"]                                         = vkglUniform2uiv;
    result["glUniform3ui"]                                          = vkglUniform3ui;
    result["glUniform3uiv"]                                         = vkglUniform3uiv;
    result["glUniform4ui"]                                          = vkglUniform4ui;
    result["glUniform4uiv"]                                         = vkglUniform4uiv;
    result["glVertexAttribI1i"]                                     = vkglVertexAttribI1i;
    result["glVertexAttribI1iv"]                                    = vkglVertexAttribI1iv;
    result["glVertexAttribI1ui"]                                    = vkglVertexAttribI1ui;
    result["glVertexAttribI1uiv"]                                   = vkglVertexAttribI1uiv;
    result["glVertexAttribI2i"]                                     = vkglVertexAttribI2i;
    result["glVertexAttribI2iv"]                                    = vkglVertexAttribI2iv;
    result["glVertexAttribI2ui"]                                    = vkglVertexAttribI2ui;
    result["glVertexAttribI2uiv"]                                   = vkglVertexAttribI2uiv;
    result["glVertexAttribI3i"]                                     = vkglVertexAttribI3i;
    result["glVertexAttribI3iv"]                                    = vkglVertexAttribI3iv;
    result["glVertexAttribI3ui"]                                    = vkglVertexAttribI3ui;
    result["glVertexAttribI3uiv"]                                   = vkglVertexAttribI3uiv;
    result["glVertexAttribI4bv"]                                    = vkglVertexAttribI4bv;
    result["glVertexAttribI4i"]                                     = vkglVertexAttribI4i;
    result["glVertexAttribI4iv"]                                    = vkglVertexAttribI4iv;
    result["glVertexAttribI4sv"]                                    = vkglVertexAttribI4sv;
    result["glVertexAttribI4ubv"]                                   = vkglVertexAttribI4ubv;
    result["glVertexAttribI4ui"]                                    = vkglVertexAttribI4ui;
    result["glVertexAttribI4uiv"]                                   = vkglVertexAttribI4uiv;
    result["glVertexAttribI4usv"]                                   = vkglVertexAttribI4usv;
    result["glVertexAttribIPointer"]                                = vkglVertexAttribIPointer;

    result["glCopyBufferSubData"]         = vkglCopyBufferSubData;
    result["glDrawArraysInstanced"]       = vkglDrawArraysInstanced;
    result["glDrawElementsInstanced"]     = vkglDrawElementsInstanced;
    result["glGetActiveUniformsiv"]       = vkglGetActiveUniformsiv;
    result["glGetActiveUniformBlockiv"]   = vkglGetActiveUniformBlockiv;
    result["glGetActiveUniformBlockName"] = vkglGetActiveUniformBlockName;
    result["glGetActiveUniformName"]      = vkglGetActiveUniformName;
    result["glGetUniformBlockIndex"]      = vkglGetUniformBlockIndex;
    result["glGetUniformIndices"]         = vkglGetUniformIndices;
    result["glPrimitiveRestartIndex"]     = vkglPrimitiveRestartIndex;
    result["glTexBuffer"]                 = vkglTexBuffer;
    result["glUniformBlockBinding"]       = vkglUniformBlockBinding;

    result["glClientWaitSync"]                  = vkglClientWaitSync;
    result["glDeleteSync"]                      = vkglDeleteSync;
    result["glDrawElementsBaseVertex"]          = vkglDrawElementsBaseVertex;
    result["glDrawElementsInstancedBaseVertex"] = vkglDrawElementsInstancedBaseVertex;
    result["glDrawRangeElementsBaseVertex"]     = vkglDrawRangeElementsBaseVertex;
    result["glFenceSync"]                       = vkglFenceSync;
    result["glFramebufferTexture"]              = vkglFramebufferTexture;
    result["glGetBufferParameteri64v"]          = vkglGetBufferParameteri64v;
    result["glGetInteger64i_v"]                 = vkglGetInteger64i_v;
    result["glGetInteger64v"]                   = vkglGetInteger64v;
    result["glGetMultisamplefv"]                = vkglGetMultisamplefv;
    result["glGetSynciv"]                       = vkglGetSynciv;
    result["glIsSync"]                          = vkglIsSync;
    result["glMultiDrawElementsBaseVertex"]     = vkglMultiDrawElementsBaseVertex;
    result["glProvokingVertex"]                 = vkglProvokingVertex;
    result["glSampleMaski"]                     = vkglSampleMaski;
    result["glTexImage2DMultisample"]           = vkglTexImage2DMultisample;
    result["glTexImage3DMultisample"]           = vkglTexImage3DMultisample;
    result["glWaitSync"]                        = vkglWaitSync;

    result["glClampColorARB"] = vkglClampColorARB;

    result["glDrawBuffersARB"] = vkglDrawBuffersARB;

    result["glDrawArraysInstancedARB"]   = vkglDrawArraysInstancedARB;
    result["glDrawElementsInstancedARB"] = vkglDrawElementsInstancedARB;

    result["glSampleCoverageARB"] = vkglSampleCoverageARB;

    result["glActiveTextureARB"] = vkglActiveTextureARB;

    result["glBeginQueryARB"]        = vkglBeginQueryARB;
    result["glDeleteQueriesARB"]     = vkglDeleteQueriesARB;
    result["glEndQueryARB"]          = vkglEndQueryARB;
    result["glGenQueriesARB"]        = vkglGenQueriesARB;
    result["glGetQueryivARB"]        = vkglGetQueryivARB;
    result["glGetQueryObjectivARB"]  = vkglGetQueryObjectivARB;
    result["glGetQueryObjectuivARB"] = vkglGetQueryObjectuivARB;
    result["glIsQueryARB"]           = vkglIsQueryARB;

    result["glPointParameterfARB"]  = vkglPointParameterfARB;
    result["glPointParameterfvARB"] = vkglPointParameterfvARB;

    result["glTexBufferARB"] = vkglTexBufferARB;

    result["glCompressedTexImage1DARB"]    = vkglCompressedTexImage1DARB;
    result["glCompressedTexImage2DARB"]    = vkglCompressedTexImage2DARB;
    result["glCompressedTexImage3DARB"]    = vkglCompressedTexImage3DARB;
    result["glCompressedTexSubImage1DARB"] = vkglCompressedTexSubImage1DARB;
    result["glCompressedTexSubImage2DARB"] = vkglCompressedTexSubImage2DARB;
    result["glCompressedTexSubImage3DARB"] = vkglCompressedTexSubImage3DARB;
    result["glGetCompressedTexImageARB"]   = vkglGetCompressedTexImageARB;

    result["glBindBufferARB"]           = vkglBindBufferARB;
    result["glBufferDataARB"]           = vkglBufferDataARB;
    result["glBufferSubDataARB"]        = vkglBufferSubDataARB;
    result["glDeleteBuffersARB"]        = vkglDeleteBuffersARB;
    result["glGenBuffersARB"]           = vkglGenBuffersARB;
    result["glGetBufferParameterivARB"] = vkglGetBufferParameterivARB;
    result["glGetBufferPointervARB"]    = vkglGetBufferPointervARB;
    result["glGetBufferSubDataARB"]     = vkglGetBufferSubDataARB;
    result["glIsBufferARB"]             = vkglIsBufferARB;
    result["glMapBufferARB"]            = vkglMapBufferARB;
    result["glUnmapBufferARB"]          = vkglUnmapBufferARB;

    result["glDisableVertexAttribArrayARB"] = vkglDisableVertexAttribArrayARB;
    result["glEnableVertexAttribArrayARB"]  = vkglEnableVertexAttribArrayARB;
    result["glGetVertexAttribdvARB"]        = vkglGetVertexAttribdvARB;
    result["glGetVertexAttribfvARB"]        = vkglGetVertexAttribfvARB;
    result["glGetVertexAttribivARB"]        = vkglGetVertexAttribivARB;
    result["glGetVertexAttribPointervARB"]  = vkglGetVertexAttribPointervARB;
    result["glVertexAttrib1dvARB"]          = vkglVertexAttrib1dvARB;
    result["glVertexAttrib1dARB"]           = vkglVertexAttrib1dARB;
    result["glVertexAttrib1fvARB"]          = vkglVertexAttrib1fvARB;
    result["glVertexAttrib1fARB"]           = vkglVertexAttrib1fARB;
    result["glVertexAttrib1svARB"]          = vkglVertexAttrib1svARB;
    result["glVertexAttrib1sARB"]           = vkglVertexAttrib1sARB;
    result["glVertexAttrib2dvARB"]          = vkglVertexAttrib2dvARB;
    result["glVertexAttrib2dARB"]           = vkglVertexAttrib2dARB;
    result["glVertexAttrib2fvARB"]          = vkglVertexAttrib2fvARB;
    result["glVertexAttrib2fARB"]           = vkglVertexAttrib2fARB;
    result["glVertexAttrib2svARB"]          = vkglVertexAttrib2svARB;
    result["glVertexAttrib2sARB"]           = vkglVertexAttrib2sARB;
    result["glVertexAttrib3dvARB"]          = vkglVertexAttrib3dvARB;
    result["glVertexAttrib3dARB"]           = vkglVertexAttrib3dARB;
    result["glVertexAttrib3fvARB"]          = vkglVertexAttrib3fvARB;
    result["glVertexAttrib3fARB"]           = vkglVertexAttrib3fARB;
    result["glVertexAttrib3svARB"]          = vkglVertexAttrib3svARB;
    result["glVertexAttrib3sARB"]           = vkglVertexAttrib3sARB;
    result["glVertexAttrib4bvARB"]          = vkglVertexAttrib4bvARB;
    result["glVertexAttrib4dvARB"]          = vkglVertexAttrib4dvARB;
    result["glVertexAttrib4dARB"]           = vkglVertexAttrib4dARB;
    result["glVertexAttrib4fvARB"]          = vkglVertexAttrib4fvARB;
    result["glVertexAttrib4fARB"]           = vkglVertexAttrib4fARB;
    result["glVertexAttrib4ivARB"]          = vkglVertexAttrib4ivARB;
    result["glVertexAttrib4NbvARB"]         = vkglVertexAttrib4NbvARB;
    result["glVertexAttrib4NivARB"]         = vkglVertexAttrib4NivARB;
    result["glVertexAttrib4NsvARB"]         = vkglVertexAttrib4NsvARB;
    result["glVertexAttrib4NubvARB"]        = vkglVertexAttrib4NubvARB;
    result["glVertexAttrib4NubARB"]         = vkglVertexAttrib4NubARB;
    result["glVertexAttrib4NuivARB"]        = vkglVertexAttrib4NuivARB;
    result["glVertexAttrib4svARB"]          = vkglVertexAttrib4svARB;
    result["glVertexAttrib4sARB"]           = vkglVertexAttrib4sARB;
    result["glVertexAttrib4ubvARB"]         = vkglVertexAttrib4ubvARB;
    result["glVertexAttrib4uivARB"]         = vkglVertexAttrib4uivARB;
    result["glVertexAttrib4usvARB"]         = vkglVertexAttrib4usvARB;
    result["glVertexAttribPointerARB"]      = vkglVertexAttribPointerARB;

    result["glBindAttribLocationARB"] = vkglBindAttribLocationARB;
    result["glGetActiveAttribARB"]    = vkglGetActiveAttribARB;
    result["glGetAttribLocationARB"]  = vkglGetAttribLocationARB;

    return result;
}

std::vector<FunctionInterceptor> opengl32_get_function_interceptors()
{
    /* <= GL 1.1 */
    return std::vector<FunctionInterceptor>
    {
        FunctionInterceptor(&(PVOID&) g_cached_gl_bind_texture,              vkglBindTexture),
        FunctionInterceptor(&(PVOID&) g_cached_gl_clear,                     vkglClear),
        FunctionInterceptor(&(PVOID&) g_cached_gl_clear_color,               vkglClearColor),
        FunctionInterceptor(&(PVOID&) g_cached_gl_clear_depth,               vkglClearDepth),
        FunctionInterceptor(&(PVOID&) g_cached_gl_clear_stencil,             vkglClearStencil),
        FunctionInterceptor(&(PVOID&) g_cached_gl_color_mask,                vkglColorMask),
        FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_image_1d,         vkglCopyTexImage1D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_image_2d,         vkglCopyTexImage2D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_sub_image_1d,     vkglCopyTexSubImage1D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_sub_image_2d,     vkglCopyTexSubImage2D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_cull_face,                 vkglCullFace),
        FunctionInterceptor(&(PVOID&) g_cached_gl_delete_textures,           vkglDeleteTextures),
        FunctionInterceptor(&(PVOID&) g_cached_gl_depth_func,                vkglDepthFunc),
        FunctionInterceptor(&(PVOID&) g_cached_gl_depth_mask,                vkglDepthMask),
        FunctionInterceptor(&(PVOID&) g_cached_gl_depth_range,               vkglDepthRange),
        FunctionInterceptor(&(PVOID&) g_cached_gl_disable,                   vkglDisable),
        FunctionInterceptor(&(PVOID&) g_cached_gl_draw_arrays,               vkglDrawArrays),
        FunctionInterceptor(&(PVOID&) g_cached_gl_draw_buffer,               vkglDrawBuffer),
        FunctionInterceptor(&(PVOID&) g_cached_gl_draw_elements,             vkglDrawElements),
        FunctionInterceptor(&(PVOID&) g_cached_gl_enable,                    vkglEnable),
        FunctionInterceptor(&(PVOID&) g_cached_gl_finish,                    vkglFinish),
        FunctionInterceptor(&(PVOID&) g_cached_gl_flush,                     vkglFlush),
        FunctionInterceptor(&(PVOID&) g_cached_gl_front_face,                vkglFrontFace),
        FunctionInterceptor(&(PVOID&) g_cached_gl_gen_textures,              vkglGenTextures),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_booleanv,              vkglGetBooleanv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_doublev,               vkglGetDoublev),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_error,                 vkglGetError),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_floatv,                vkglGetFloatv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_integerv,              vkglGetIntegerv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_string,                vkglGetString),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_image,             vkglGetTexImage),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_level_parameterfv, vkglGetTexLevelParameterfv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_level_parameteriv, vkglGetTexLevelParameteriv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_parameterfv,       vkglGetTexParameterfv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_parameteriv,       vkglGetTexParameteriv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_hint,                      vkglHint),
        FunctionInterceptor(&(PVOID&) g_cached_gl_is_enabled,                vkglIsEnabled),
        FunctionInterceptor(&(PVOID&) g_cached_gl_is_texture,                vkglIsTexture),
        FunctionInterceptor(&(PVOID&) g_cached_gl_line_width,                vkglLineWidth),
        FunctionInterceptor(&(PVOID&) g_cached_gl_logic_op,                  vkglLogicOp),
        FunctionInterceptor(&(PVOID&) g_cached_gl_pixel_storef,              vkglPixelStoref),
        FunctionInterceptor(&(PVOID&) g_cached_gl_pixel_storei,              vkglPixelStorei),
        FunctionInterceptor(&(PVOID&) g_cached_gl_point_size,                vkglPointSize),
        FunctionInterceptor(&(PVOID&) g_cached_gl_polygon_mode,              vkglPolygonMode),
        FunctionInterceptor(&(PVOID&) g_cached_gl_polygon_offset,            vkglPolygonOffset),
        FunctionInterceptor(&(PVOID&) g_cached_gl_read_buffer,               vkglReadBuffer),
        FunctionInterceptor(&(PVOID&) g_cached_gl_read_pixels,               vkglReadPixels),
        FunctionInterceptor(&(PVOID&) g_cached_gl_scissor,                   vkglScissor),
        FunctionInterceptor(&(PVOID&) g_cached_gl_stencil_func,              vkglStencilFunc),
        FunctionInterceptor(&(PVOID&) g_cached_gl_stencil_mask,              vkglStencilMask),
        FunctionInterceptor(&(PVOID&) g_cached_gl_stencil_op,                vkglStencilOp),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_image_1d,              vkglTexImage1D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_image_2d,              vkglTexImage2D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameterf,            vkglTexParameterf),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameterfv,           vkglTexParameterfv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameteri,            vkglTexParameteri),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameteriv,           vkglTexParameteriv),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_sub_image_1d,          vkglTexSubImage1D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_tex_sub_image_2d,          vkglTexSubImage2D),
        FunctionInterceptor(&(PVOID&) g_cached_gl_viewport_func_ptr,         vkglViewport),
    };
}