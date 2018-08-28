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

std::unordered_map<std::string, void*> OpenGL::get_func_name_to_func_ptr_map()
{
    /* >= GL 1.2 */
    std::unordered_map<std::string, void*> result;

    result["glCopyTexSubImage3D"] = OpenGL::vkglCopyTexSubImage3D_with_validation;
    result["glDrawRangeElements"] = OpenGL::vkglDrawRangeElements_with_validation;
    result["glTexImage3D"]        = OpenGL::vkglTexImage3D;
    result["glTexSubImage3D"]     = OpenGL::vkglTexSubImage3D;

    result["glActiveTexture"]           = OpenGL::vkglActiveTexture_with_validation;
    result["glCompressedTexImage1D"]    = OpenGL::vkglCompressedTexImage1D_with_validation;
    result["glCompressedTexImage2D"]    = OpenGL::vkglCompressedTexImage2D_with_validation;
    result["glCompressedTexImage3D"]    = OpenGL::vkglCompressedTexImage3D_with_validation;
    result["glCompressedTexSubImage1D"] = OpenGL::vkglCompressedTexSubImage1D_with_validation;
    result["glCompressedTexSubImage2D"] = OpenGL::vkglCompressedTexSubImage2D_with_validation;
    result["glCompressedTexSubImage3D"] = OpenGL::vkglCompressedTexSubImage3D_with_validation;
    result["glGetCompressedTexImage"]   = OpenGL::vkglGetCompressedTexImage_with_validation;
    result["glSampleCoverage"]          = OpenGL::vkglSampleCoverage_with_validation;

    result["glBlendColor"]        = OpenGL::vkglBlendColor_with_validation;
    result["glBlendEquation"]     = OpenGL::vkglBlendEquation_with_validation;
    result["glBlendFuncSeparate"] = OpenGL::vkglBlendFuncSeparate_with_validation;
    result["glMultiDrawArrays"]   = OpenGL::vkglMultiDrawArrays_with_validation;
    result["glMultiDrawElements"] = OpenGL::vkglMultiDrawElements_with_validation;
    result["glPointParameterf"]   = OpenGL::vkglPointParameterf_with_validation;
    result["glPointParameterfv"]  = OpenGL::vkglPointParameterfv_with_validation;
    result["glPointParameteri"]   = OpenGL::vkglPointParameteri_with_validation;
    result["glPointParameteriv"]  = OpenGL::vkglPointParameteriv_with_validation;

    result["glBeginQuery"]           = OpenGL::vkglBeginQuery_with_validation;
    result["glBindBuffer"]           = OpenGL::vkglBindBuffer_with_validation;
    result["glBufferData"]           = OpenGL::vkglBufferData_with_validation;
    result["glBufferSubData"]        = OpenGL::vkglBufferSubData_with_validation;
    result["glDeleteBuffers"]        = OpenGL::vkglDeleteBuffers_with_validation;
    result["glDeleteQueries"]        = OpenGL::vkglDeleteQueries_with_validation;
    result["glEndQuery"]             = OpenGL::vkglEndQuery_with_validation;
    result["glGenBuffers"]           = OpenGL::vkglGenBuffers_with_validation;
    result["glGenQueries"]           = OpenGL::vkglGenQueries_with_validation;
    result["glGetBufferParameteriv"] = OpenGL::vkglGetBufferParameteriv_with_validation;
    result["glGetBufferPointerv"]    = OpenGL::vkglGetBufferPointerv_with_validation;
    result["glGetBufferSubData"]     = OpenGL::vkglGetBufferSubData_with_validation;
    result["glGetQueryiv"]           = OpenGL::vkglGetQueryiv_with_validation;
    result["glGetQueryObjectiv"]     = OpenGL::vkglGetQueryObjectiv_with_validation;
    result["glGetQueryObjectuiv"]    = OpenGL::vkglGetQueryObjectuiv_with_validation;
    result["glIsBuffer"]             = OpenGL::vkglIsBuffer_with_validation;
    result["glIsQuery"]              = OpenGL::vkglIsQuery_with_validation;
    result["glMapBuffer"]            = OpenGL::vkglMapBuffer_with_validation;
    result["glUnmapBuffer"]          = OpenGL::vkglUnmapBuffer_with_validation;

    result["glAttachShader"]             = OpenGL::vkglAttachShader_with_validation;
    result["glBindAttribLocation"]       = OpenGL::vkglBindAttribLocation_with_validation;
    result["glBlendEquationSeparate"]    = OpenGL::vkglBlendEquationSeparate_with_validation;
    result["glCompileShader"]            = OpenGL::vkglCompileShader_with_validation;
    result["glCreateProgram"]            = OpenGL::vkglCreateProgram_with_validation;
    result["glCreateShader"]             = OpenGL::vkglCreateShader_with_validation;
    result["glDeleteProgram"]            = OpenGL::vkglDeleteProgram_with_validation;
    result["glDeleteShader"]             = OpenGL::vkglDeleteShader_with_validation;
    result["glDetachShader"]             = OpenGL::vkglDetachShader_with_validation;
    result["glDisableVertexAttribArray"] = OpenGL::vkglDisableVertexAttribArray_with_validation;
    result["glDrawBuffers"]              = OpenGL::vkglDrawBuffers_with_validation;
    result["glEnableVertexAttribArray"]  = OpenGL::vkglEnableVertexAttribArray_with_validation;
    result["glGetActiveAttrib"]          = OpenGL::vkglGetActiveAttrib_with_validation;
    result["glGetActiveUniform"]         = OpenGL::vkglGetActiveUniform_with_validation;
    result["glGetAttachedShaders"]       = OpenGL::vkglGetAttachedShaders_with_validation;
    result["glGetAttribLocation"]        = OpenGL::vkglGetAttribLocation_with_validation;
    result["glGetProgramiv"]             = OpenGL::vkglGetProgramiv_with_validation;
    result["glGetProgramInfoLog"]        = OpenGL::vkglGetProgramInfoLog_with_validation;
    result["glGetShaderiv"]              = OpenGL::vkglGetShaderiv_with_validation;
    result["glGetShaderInfoLog"]         = OpenGL::vkglGetShaderInfoLog_with_validation;
    result["glGetShaderSource"]          = OpenGL::vkglGetShaderSource_with_validation;
    result["glGetUniformfv"]             = OpenGL::vkglGetUniformfv_with_validation;
    result["glGetUniformiv"]             = OpenGL::vkglGetUniformiv_with_validation;
    result["glGetUniformLocation"]       = OpenGL::vkglGetUniformLocation_with_validation;
    result["glGetVertexAttribdv"]        = OpenGL::vkglGetVertexAttribdv_with_validation;
    result["glGetVertexAttribfv"]        = OpenGL::vkglGetVertexAttribfv_with_validation;
    result["glGetVertexAttribiv"]        = OpenGL::vkglGetVertexAttribiv_with_validation;
    result["glGetVertexAttribPointerv"]  = OpenGL::vkglGetVertexAttribPointerv_with_validation;
    result["glIsProgram"]                = OpenGL::vkglIsProgram_with_validation;
    result["glIsShader"]                 = OpenGL::vkglIsShader_with_validation;
    result["glLinkProgram"]              = OpenGL::vkglLinkProgram_with_validation;
    result["glShaderSource"]             = OpenGL::vkglShaderSource_with_validation;
    result["glStencilFuncSeparate"]      = OpenGL::vkglStencilFuncSeparate_with_validation;
    result["glStencilMaskSeparate"]      = OpenGL::vkglStencilMaskSeparate_with_validation;
    result["glStencilOpSeparate"]        = OpenGL::vkglStencilOpSeparate_with_validation;
    result["glUniform1f"]                = OpenGL::vkglUniform1f_with_validation;
    result["glUniform1fv"]               = OpenGL::vkglUniform1fv_with_validation;
    result["glUniform1i"]                = OpenGL::vkglUniform1i_with_validation;
    result["glUniform1iv"]               = OpenGL::vkglUniform1iv_with_validation;
    result["glUniform2f"]                = OpenGL::vkglUniform2f_with_validation;
    result["glUniform2fv"]               = OpenGL::vkglUniform2fv_with_validation;
    result["glUniform2i"]                = OpenGL::vkglUniform2i_with_validation;
    result["glUniform2iv"]               = OpenGL::vkglUniform2iv_with_validation;
    result["glUniform3f"]                = OpenGL::vkglUniform3f_with_validation;
    result["glUniform3fv"]               = OpenGL::vkglUniform3fv_with_validation;
    result["glUniform3i"]                = OpenGL::vkglUniform3i_with_validation;
    result["glUniform3iv"]               = OpenGL::vkglUniform3iv_with_validation;
    result["glUniform4f"]                = OpenGL::vkglUniform4f_with_validation;
    result["glUniform4fv"]               = OpenGL::vkglUniform4fv_with_validation;
    result["glUniform4i"]                = OpenGL::vkglUniform4i_with_validation;
    result["glUniform4iv"]               = OpenGL::vkglUniform4iv_with_validation;
    result["glUniformMatrix2fv"]         = OpenGL::vkglUniformMatrix2fv_with_validation;
    result["glUniformMatrix3fv"]         = OpenGL::vkglUniformMatrix3fv_with_validation;
    result["glUniformMatrix4fv"]         = OpenGL::vkglUniformMatrix4fv_with_validation;
    result["glUseProgram"]               = OpenGL::vkglUseProgram_with_validation;
    result["glValidateProgram"]          = OpenGL::vkglValidateProgram_with_validation;
    result["glVertexAttrib1d"]           = OpenGL::vkglVertexAttrib1d_with_validation;
    result["glVertexAttrib1dv"]          = OpenGL::vkglVertexAttrib1dv_with_validation;
    result["glVertexAttrib1f"]           = OpenGL::vkglVertexAttrib1f_with_validation;
    result["glVertexAttrib1fv"]          = OpenGL::vkglVertexAttrib1fv_with_validation;
    result["glVertexAttrib1s"]           = OpenGL::vkglVertexAttrib1s_with_validation;
    result["glVertexAttrib1sv"]          = OpenGL::vkglVertexAttrib1sv_with_validation;
    result["glVertexAttrib2d"]           = OpenGL::vkglVertexAttrib2d_with_validation;
    result["glVertexAttrib2dv"]          = OpenGL::vkglVertexAttrib2dv_with_validation;
    result["glVertexAttrib2f"]           = OpenGL::vkglVertexAttrib2f_with_validation;
    result["glVertexAttrib2fv"]          = OpenGL::vkglVertexAttrib2fv_with_validation;
    result["glVertexAttrib2s"]           = OpenGL::vkglVertexAttrib2s_with_validation;
    result["glVertexAttrib2sv"]          = OpenGL::vkglVertexAttrib2sv_with_validation;
    result["glVertexAttrib3d"]           = OpenGL::vkglVertexAttrib3d_with_validation;
    result["glVertexAttrib3dv"]          = OpenGL::vkglVertexAttrib3dv_with_validation;
    result["glVertexAttrib3f"]           = OpenGL::vkglVertexAttrib3f_with_validation;
    result["glVertexAttrib3fv"]          = OpenGL::vkglVertexAttrib3fv_with_validation;
    result["glVertexAttrib3s"]           = OpenGL::vkglVertexAttrib3s_with_validation;
    result["glVertexAttrib3sv"]          = OpenGL::vkglVertexAttrib3sv_with_validation;
    result["glVertexAttrib4bv"]          = OpenGL::vkglVertexAttrib4bv_with_validation;
    result["glVertexAttrib4d"]           = OpenGL::vkglVertexAttrib4d_with_validation;
    result["glVertexAttrib4dv"]          = OpenGL::vkglVertexAttrib4dv_with_validation;
    result["glVertexAttrib4f"]           = OpenGL::vkglVertexAttrib4f_with_validation;
    result["glVertexAttrib4fv"]          = OpenGL::vkglVertexAttrib4fv_with_validation;
    result["glVertexAttrib4iv"]          = OpenGL::vkglVertexAttrib4iv_with_validation;
    result["glVertexAttrib4Nbv"]         = OpenGL::vkglVertexAttrib4Nbv_with_validation;
    result["glVertexAttrib4Niv"]         = OpenGL::vkglVertexAttrib4Niv_with_validation;
    result["glVertexAttrib4Nsv"]         = OpenGL::vkglVertexAttrib4Nsv_with_validation;
    result["glVertexAttrib4Nub"]         = OpenGL::vkglVertexAttrib4Nub_with_validation;
    result["glVertexAttrib4Nubv"]        = OpenGL::vkglVertexAttrib4Nubv_with_validation;
    result["glVertexAttrib4Nuiv"]        = OpenGL::vkglVertexAttrib4Nuiv_with_validation;
    result["glVertexAttrib4Nusv"]        = OpenGL::vkglVertexAttrib4Nusv_with_validation;
    result["glVertexAttrib4s"]           = OpenGL::vkglVertexAttrib4s_with_validation;
    result["glVertexAttrib4sv"]          = OpenGL::vkglVertexAttrib4sv_with_validation;
    result["glVertexAttrib4ubv"]         = OpenGL::vkglVertexAttrib4ubv_with_validation;
    result["glVertexAttrib4uiv"]         = OpenGL::vkglVertexAttrib4uiv_with_validation;
    result["glVertexAttrib4usv"]         = OpenGL::vkglVertexAttrib4usv_with_validation;
    result["glVertexAttribPointer"]      = OpenGL::vkglVertexAttribPointer_with_validation;

    result["glUniformMatrix2x3fv"] = OpenGL::vkglUniformMatrix2x3fv_with_validation;
    result["glUniformMatrix2x4fv"] = OpenGL::vkglUniformMatrix2x4fv_with_validation;
    result["glUniformMatrix3x2fv"] = OpenGL::vkglUniformMatrix3x2fv_with_validation;
    result["glUniformMatrix3x4fv"] = OpenGL::vkglUniformMatrix3x4fv_with_validation;
    result["glUniformMatrix4x2fv"] = OpenGL::vkglUniformMatrix4x2fv_with_validation;
    result["glUniformMatrix4x3fv"] = OpenGL::vkglUniformMatrix4x3fv_with_validation;

    result["glBeginConditionalRender"]              = OpenGL::vkglBeginConditionalRender_with_validation;
    result["glBeginTransformFeedback"]              = OpenGL::vkglBeginTransformFeedback_with_validation;
    result["glBindBufferBase"]                      = OpenGL::vkglBindBufferBase_with_validation;
    result["glBindBufferRange"]                     = OpenGL::vkglBindBufferRange_with_validation;
    result["glBindFragDataLocation"]                = OpenGL::vkglBindFragDataLocation_with_validation;
    result["glBindFramebuffer"]                     = OpenGL::vkglBindFramebuffer_with_validation;
    result["glBindRenderbuffer"]                    = OpenGL::vkglBindRenderbuffer_with_validation;
    result["glBindVertexArray"]                     = OpenGL::vkglBindVertexArray_with_validation;
    result["glBlitFramebuffer"]                     = OpenGL::vkglBlitFramebuffer_with_validation;
    result["glCheckFramebufferStatus"]              = OpenGL::vkglCheckFramebufferStatus_with_validation;
    result["glClampColor"]                          = OpenGL::vkglClampColor_with_validation;
    result["glClearBufferfi"]                       = OpenGL::vkglClearBufferfi_with_validation;
    result["glClearBufferfv"]                       = OpenGL::vkglClearBufferfv_with_validation;
    result["glClearBufferiv"]                       = OpenGL::vkglClearBufferiv_with_validation;
    result["glClearBufferuiv"]                      = OpenGL::vkglClearBufferuiv_with_validation;
    result["glColorMaski"]                          = OpenGL::vkglColorMaski_with_validation;
    result["glDeleteFramebuffers"]                  = OpenGL::vkglDeleteFramebuffers_with_validation;
    result["glDeleteRenderbuffers"]                 = OpenGL::vkglDeleteRenderbuffers_with_validation;
    result["glDeleteVertexArrays"]                  = OpenGL::vkglDeleteVertexArrays_with_validation;
    result["glDisablei"]                            = OpenGL::vkglDisablei_with_validation;
    result["glEnablei"]                             = OpenGL::vkglEnablei_with_validation;
    result["glEndConditionalRender"]                = OpenGL::vkglEndConditionalRender_with_validation;
    result["glEndTransformFeedback"]                = OpenGL::vkglEndTransformFeedback_with_validation;
    result["glFlushMappedBufferRange"]              = OpenGL::vkglFlushMappedBufferRange_with_validation;
    result["glFramebufferRenderbuffer"]             = OpenGL::vkglFramebufferRenderbuffer_with_validation;
    result["glFramebufferTexture1D"]                = OpenGL::vkglFramebufferTexture1D_with_validation;
    result["glFramebufferTexture2D"]                = OpenGL::vkglFramebufferTexture2D_with_validation;
    result["glFramebufferTexture3D"]                = OpenGL::vkglFramebufferTexture3D_with_validation;
    result["glFramebufferTextureLayer"]             = OpenGL::vkglFramebufferTextureLayer_with_validation;
    result["glGenerateMipmap"]                      = OpenGL::vkglGenerateMipmap_with_validation;
    result["glGenFramebuffers"]                     = OpenGL::vkglGenFramebuffers_with_validation;
    result["glGenRenderbuffers"]                    = OpenGL::vkglGenRenderbuffers_with_validation;
    result["glGenVertexArrays"]                     = OpenGL::vkglGenVertexArrays_with_validation;
    result["glGetBooleani_v"]                       = OpenGL::vkglGetBooleani_v_with_validation;
    result["glGetFragDataLocation"]                 = OpenGL::vkglGetFragDataLocation_with_validation;
    result["glGetFramebufferAttachmentParameteriv"] = OpenGL::vkglGetFramebufferAttachmentParameteriv_with_validation;
    result["glGetIntegeri_v"]                       = OpenGL::vkglGetIntegeri_v_with_validation;
    result["glGetRenderbufferParameteriv"]          = OpenGL::vkglGetRenderbufferParameteriv_with_validation;
    result["glGetStringi"]                          = OpenGL::vkglGetStringi_with_validation;
    result["glGetTexParameterIiv"]                  = OpenGL::vkglGetTexParameterIiv_with_validation;
    result["glGetTexParameterIuiv"]                 = OpenGL::vkglGetTexParameterIuiv_with_validation;
    result["glGetTransformFeedbackVarying"]         = OpenGL::vkglGetTransformFeedbackVarying_with_validation;
    result["glGetUniformuiv"]                       = OpenGL::vkglGetUniformuiv_with_validation;
    result["glGetVertexAttribIiv"]                  = OpenGL::vkglGetVertexAttribIiv_with_validation;
    result["glGetVertexAttribIuiv"]                 = OpenGL::vkglGetVertexAttribIuiv_with_validation;
    result["glIsEnabledi"]                          = OpenGL::vkglIsEnabledi_with_validation;
    result["glIsFramebuffer"]                       = OpenGL::vkglIsFramebuffer_with_validation;
    result["glIsRenderbuffer"]                      = OpenGL::vkglIsRenderbuffer_with_validation;
    result["glIsVertexArray"]                       = OpenGL::vkglIsVertexArray_with_validation;
    result["glMapBufferRange"]                      = OpenGL::vkglMapBufferRange_with_validation;
    result["glRenderbufferStorage"]                 = OpenGL::vkglRenderbufferStorage_with_validation;
    result["glRenderbufferStorageMultisample"]      = OpenGL::vkglRenderbufferStorageMultisample_with_validation;
    result["glTexParameterIiv"]                     = OpenGL::vkglTexParameterIiv_with_validation;
    result["glTexParameterIuiv"]                    = OpenGL::vkglTexParameterIuiv_with_validation;
    result["glTransformFeedbackVaryings"]           = OpenGL::vkglTransformFeedbackVaryings_with_validation;
    result["glUniform1ui"]                          = OpenGL::vkglUniform1ui_with_validation;
    result["glUniform1uiv"]                         = OpenGL::vkglUniform1uiv_with_validation;
    result["glUniform2ui"]                          = OpenGL::vkglUniform2ui_with_validation;
    result["glUniform2uiv"]                         = OpenGL::vkglUniform2uiv_with_validation;
    result["glUniform3ui"]                          = OpenGL::vkglUniform3ui_with_validation;
    result["glUniform3uiv"]                         = OpenGL::vkglUniform3uiv_with_validation;
    result["glUniform4ui"]                          = OpenGL::vkglUniform4ui_with_validation;
    result["glUniform4uiv"]                         = OpenGL::vkglUniform4uiv_with_validation;
    result["glVertexAttribI1i"]                     = OpenGL::vkglVertexAttribI1i_with_validation;
    result["glVertexAttribI1iv"]                    = OpenGL::vkglVertexAttribI1iv_with_validation;
    result["glVertexAttribI1ui"]                    = OpenGL::vkglVertexAttribI1ui_with_validation;
    result["glVertexAttribI1uiv"]                   = OpenGL::vkglVertexAttribI1uiv_with_validation;
    result["glVertexAttribI2i"]                     = OpenGL::vkglVertexAttribI2i_with_validation;
    result["glVertexAttribI2iv"]                    = OpenGL::vkglVertexAttribI2iv_with_validation;
    result["glVertexAttribI2ui"]                    = OpenGL::vkglVertexAttribI2ui_with_validation;
    result["glVertexAttribI2uiv"]                   = OpenGL::vkglVertexAttribI2uiv_with_validation;
    result["glVertexAttribI3i"]                     = OpenGL::vkglVertexAttribI3i_with_validation;
    result["glVertexAttribI3iv"]                    = OpenGL::vkglVertexAttribI3iv_with_validation;
    result["glVertexAttribI3ui"]                    = OpenGL::vkglVertexAttribI3ui_with_validation;
    result["glVertexAttribI3uiv"]                   = OpenGL::vkglVertexAttribI3uiv_with_validation;
    result["glVertexAttribI4bv"]                    = OpenGL::vkglVertexAttribI4bv_with_validation;
    result["glVertexAttribI4i"]                     = OpenGL::vkglVertexAttribI4i_with_validation;
    result["glVertexAttribI4iv"]                    = OpenGL::vkglVertexAttribI4iv_with_validation;
    result["glVertexAttribI4sv"]                    = OpenGL::vkglVertexAttribI4sv_with_validation;
    result["glVertexAttribI4ubv"]                   = OpenGL::vkglVertexAttribI4ubv_with_validation;
    result["glVertexAttribI4ui"]                    = OpenGL::vkglVertexAttribI4ui_with_validation;
    result["glVertexAttribI4uiv"]                   = OpenGL::vkglVertexAttribI4uiv_with_validation;
    result["glVertexAttribI4usv"]                   = OpenGL::vkglVertexAttribI4usv_with_validation;
    result["glVertexAttribIPointer"]                = OpenGL::vkglVertexAttribIPointer_with_validation;

    result["glCopyBufferSubData"]         = OpenGL::vkglCopyBufferSubData_with_validation;
    result["glDrawArraysInstanced"]       = OpenGL::vkglDrawArraysInstanced_with_validation;
    result["glDrawElementsInstanced"]     = OpenGL::vkglDrawElementsInstanced_with_validation;
    result["glGetActiveUniformsiv"]       = OpenGL::vkglGetActiveUniformsiv_with_validation;
    result["glGetActiveUniformBlockiv"]   = OpenGL::vkglGetActiveUniformBlockiv_with_validation;
    result["glGetActiveUniformBlockName"] = OpenGL::vkglGetActiveUniformBlockName_with_validation;
    result["glGetActiveUniformName"]      = OpenGL::vkglGetActiveUniformName_with_validation;
    result["glGetUniformBlockIndex"]      = OpenGL::vkglGetUniformBlockIndex_with_validation;
    result["glGetUniformIndices"]         = OpenGL::vkglGetUniformIndices_with_validation;
    result["glPrimitiveRestartIndex"]     = OpenGL::vkglPrimitiveRestartIndex_with_validation;
    result["glTexBuffer"]                 = OpenGL::vkglTexBuffer_with_validation;
    result["glUniformBlockBinding"]       = OpenGL::vkglUniformBlockBinding_with_validation;

    result["glClientWaitSync"]                  = OpenGL::vkglClientWaitSync_with_validation;
    result["glDeleteSync"]                      = OpenGL::vkglDeleteSync_with_validation;
    result["glDrawElementsBaseVertex"]          = OpenGL::vkglDrawElementsBaseVertex_with_validation;
    result["glDrawElementsInstancedBaseVertex"] = OpenGL::vkglDrawElementsInstancedBaseVertex_with_validation;
    result["glDrawRangeElementsBaseVertex"]     = OpenGL::vkglDrawRangeElementsBaseVertex_with_validation;
    result["glFenceSync"]                       = OpenGL::vkglFenceSync_with_validation;
    result["glFramebufferTexture"]              = OpenGL::vkglFramebufferTexture_with_validation;
    result["glGetBufferParameteri64v"]          = OpenGL::vkglGetBufferParameteri64v_with_validation;
    result["glGetInteger64i_v"]                 = OpenGL::vkglGetInteger64i_v_with_validation;
    result["glGetInteger64v"]                   = OpenGL::vkglGetInteger64v_with_validation;
    result["glGetMultisamplefv"]                = OpenGL::vkglGetMultisamplefv_with_validation;
    result["glGetSynciv"]                       = OpenGL::vkglGetSynciv_with_validation;
    result["glIsSync"]                          = OpenGL::vkglIsSync_with_validation;
    result["glMultiDrawElementsBaseVertex"]     = OpenGL::vkglMultiDrawElementsBaseVertex_with_validation;
    result["glProvokingVertex"]                 = OpenGL::vkglProvokingVertex_with_validation;
    result["glSampleMaski"]                     = OpenGL::vkglSampleMaski_with_validation;
    result["glTexImage2DMultisample"]           = OpenGL::vkglTexImage2DMultisample_with_validation;
    result["glTexImage3DMultisample"]           = OpenGL::vkglTexImage3DMultisample_with_validation;
    result["glWaitSync"]                        = OpenGL::vkglWaitSync_with_validation;

    result["glClampColorARB"] = OpenGL::vkglClampColorARB_with_validation;

    result["glDrawBuffersARB"] = OpenGL::vkglDrawBuffersARB_with_validation;

    result["glDrawArraysInstancedARB"]   = OpenGL::vkglDrawArraysInstancedARB_with_validation;
    result["glDrawElementsInstancedARB"] = OpenGL::vkglDrawElementsInstancedARB_with_validation;

    result["glSampleCoverageARB"] = OpenGL::vkglSampleCoverageARB_with_validation;

    result["glActiveTextureARB"] = OpenGL::vkglActiveTextureARB_with_validation;

    result["glBeginQueryARB"]        = OpenGL::vkglBeginQueryARB_with_validation;
    result["glDeleteQueriesARB"]     = OpenGL::vkglDeleteQueriesARB_with_validation;
    result["glEndQueryARB"]          = OpenGL::vkglEndQueryARB_with_validation;
    result["glGenQueriesARB"]        = OpenGL::vkglGenQueriesARB_with_validation;
    result["glGetQueryivARB"]        = OpenGL::vkglGetQueryivARB_with_validation;
    result["glGetQueryObjectivARB"]  = OpenGL::vkglGetQueryObjectivARB_with_validation;
    result["glGetQueryObjectuivARB"] = OpenGL::vkglGetQueryObjectuivARB_with_validation;
    result["glIsQueryARB"]           = OpenGL::vkglIsQueryARB_with_validation;

    result["glPointParameterfARB"]  = OpenGL::vkglPointParameterfARB_with_validation;
    result["glPointParameterfvARB"] = OpenGL::vkglPointParameterfvARB_with_validation;

    result["glTexBufferARB"] = OpenGL::vkglTexBufferARB_with_validation;

    result["glCompressedTexImage1DARB"]    = OpenGL::vkglCompressedTexImage1DARB_with_validation;
    result["glCompressedTexImage2DARB"]    = OpenGL::vkglCompressedTexImage2DARB_with_validation;
    result["glCompressedTexImage3DARB"]    = OpenGL::vkglCompressedTexImage3DARB_with_validation;
    result["glCompressedTexSubImage1DARB"] = OpenGL::vkglCompressedTexSubImage1DARB_with_validation;
    result["glCompressedTexSubImage2DARB"] = OpenGL::vkglCompressedTexSubImage2DARB_with_validation;
    result["glCompressedTexSubImage3DARB"] = OpenGL::vkglCompressedTexSubImage3DARB_with_validation;
    result["glGetCompressedTexImageARB"]   = OpenGL::vkglGetCompressedTexImageARB_with_validation;

    result["glBindBufferARB"]           = OpenGL::vkglBindBufferARB_with_validation;
    result["glBufferDataARB"]           = OpenGL::vkglBufferDataARB_with_validation;
    result["glBufferSubDataARB"]        = OpenGL::vkglBufferSubDataARB_with_validation;
    result["glDeleteBuffersARB"]        = OpenGL::vkglDeleteBuffersARB_with_validation;
    result["glGenBuffersARB"]           = OpenGL::vkglGenBuffersARB_with_validation;
    result["glGetBufferParameterivARB"] = OpenGL::vkglGetBufferParameterivARB_with_validation;
    result["glGetBufferPointervARB"]    = OpenGL::vkglGetBufferPointervARB_with_validation;
    result["glGetBufferSubDataARB"]     = OpenGL::vkglGetBufferSubDataARB_with_validation;
    result["glIsBufferARB"]             = OpenGL::vkglIsBufferARB_with_validation;
    result["glMapBufferARB"]            = OpenGL::vkglMapBufferARB_with_validation;
    result["glUnmapBufferARB"]          = OpenGL::vkglUnmapBufferARB_with_validation;

    result["glDisableVertexAttribArrayARB"] = OpenGL::vkglDisableVertexAttribArrayARB_with_validation;
    result["glEnableVertexAttribArrayARB"]  = OpenGL::vkglEnableVertexAttribArrayARB_with_validation;
    result["glGetVertexAttribdvARB"]        = OpenGL::vkglGetVertexAttribdvARB_with_validation;
    result["glGetVertexAttribfvARB"]        = OpenGL::vkglGetVertexAttribfvARB_with_validation;
    result["glGetVertexAttribivARB"]        = OpenGL::vkglGetVertexAttribivARB_with_validation;
    result["glGetVertexAttribPointervARB"]  = OpenGL::vkglGetVertexAttribPointervARB_with_validation;
    result["glVertexAttrib1dvARB"]          = OpenGL::vkglVertexAttrib1dvARB_with_validation;
    result["glVertexAttrib1dARB"]           = OpenGL::vkglVertexAttrib1dARB_with_validation;
    result["glVertexAttrib1fvARB"]          = OpenGL::vkglVertexAttrib1fvARB_with_validation;
    result["glVertexAttrib1fARB"]           = OpenGL::vkglVertexAttrib1fARB_with_validation;
    result["glVertexAttrib1svARB"]          = OpenGL::vkglVertexAttrib1svARB_with_validation;
    result["glVertexAttrib1sARB"]           = OpenGL::vkglVertexAttrib1sARB_with_validation;
    result["glVertexAttrib2dvARB"]          = OpenGL::vkglVertexAttrib2dvARB_with_validation;
    result["glVertexAttrib2dARB"]           = OpenGL::vkglVertexAttrib2dARB_with_validation;
    result["glVertexAttrib2fvARB"]          = OpenGL::vkglVertexAttrib2fvARB_with_validation;
    result["glVertexAttrib2fARB"]           = OpenGL::vkglVertexAttrib2fARB_with_validation;
    result["glVertexAttrib2svARB"]          = OpenGL::vkglVertexAttrib2svARB_with_validation;
    result["glVertexAttrib2sARB"]           = OpenGL::vkglVertexAttrib2sARB_with_validation;
    result["glVertexAttrib3dvARB"]          = OpenGL::vkglVertexAttrib3dvARB_with_validation;
    result["glVertexAttrib3dARB"]           = OpenGL::vkglVertexAttrib3dARB_with_validation;
    result["glVertexAttrib3fvARB"]          = OpenGL::vkglVertexAttrib3fvARB_with_validation;
    result["glVertexAttrib3fARB"]           = OpenGL::vkglVertexAttrib3fARB_with_validation;
    result["glVertexAttrib3svARB"]          = OpenGL::vkglVertexAttrib3svARB_with_validation;
    result["glVertexAttrib3sARB"]           = OpenGL::vkglVertexAttrib3sARB_with_validation;
    result["glVertexAttrib4bvARB"]          = OpenGL::vkglVertexAttrib4bvARB_with_validation;
    result["glVertexAttrib4dvARB"]          = OpenGL::vkglVertexAttrib4dvARB_with_validation;
    result["glVertexAttrib4dARB"]           = OpenGL::vkglVertexAttrib4dARB_with_validation;
    result["glVertexAttrib4fvARB"]          = OpenGL::vkglVertexAttrib4fvARB_with_validation;
    result["glVertexAttrib4fARB"]           = OpenGL::vkglVertexAttrib4fARB_with_validation;
    result["glVertexAttrib4ivARB"]          = OpenGL::vkglVertexAttrib4ivARB_with_validation;
    result["glVertexAttrib4NbvARB"]         = OpenGL::vkglVertexAttrib4NbvARB_with_validation;
    result["glVertexAttrib4NivARB"]         = OpenGL::vkglVertexAttrib4NivARB_with_validation;
    result["glVertexAttrib4NsvARB"]         = OpenGL::vkglVertexAttrib4NsvARB_with_validation;
    result["glVertexAttrib4NubvARB"]        = OpenGL::vkglVertexAttrib4NubvARB_with_validation;
    result["glVertexAttrib4NubARB"]         = OpenGL::vkglVertexAttrib4NubARB_with_validation;
    result["glVertexAttrib4NuivARB"]        = OpenGL::vkglVertexAttrib4NuivARB_with_validation;
    result["glVertexAttrib4svARB"]          = OpenGL::vkglVertexAttrib4svARB_with_validation;
    result["glVertexAttrib4sARB"]           = OpenGL::vkglVertexAttrib4sARB_with_validation;
    result["glVertexAttrib4ubvARB"]         = OpenGL::vkglVertexAttrib4ubvARB_with_validation;
    result["glVertexAttrib4uivARB"]         = OpenGL::vkglVertexAttrib4uivARB_with_validation;
    result["glVertexAttrib4usvARB"]         = OpenGL::vkglVertexAttrib4usvARB_with_validation;
    result["glVertexAttribPointerARB"]      = OpenGL::vkglVertexAttribPointerARB_with_validation;

    result["glBindAttribLocationARB"] = OpenGL::vkglBindAttribLocationARB_with_validation;
    result["glGetActiveAttribARB"]    = OpenGL::vkglGetActiveAttribARB_with_validation;
    result["glGetAttribLocationARB"]  = OpenGL::vkglGetAttribLocationARB_with_validation;

    return result;
}

std::vector<VKGL::FunctionInterceptor> OpenGL::get_function_interceptors()
{
    /* <= GL 1.1 */
    return std::vector<VKGL::FunctionInterceptor>
    {
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_bind_texture,              vkglBindTexture),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_clear,                     vkglClear),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_clear_color,               vkglClearColor),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_clear_depth,               vkglClearDepth),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_clear_stencil,             vkglClearStencil),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_color_mask,                vkglColorMask),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_image_1d,         vkglCopyTexImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_image_2d,         vkglCopyTexImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_sub_image_1d,     vkglCopyTexSubImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_copy_tex_sub_image_2d,     vkglCopyTexSubImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_cull_face,                 vkglCullFace),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_delete_textures,           vkglDeleteTextures),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_depth_func,                vkglDepthFunc),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_depth_mask,                vkglDepthMask),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_depth_range,               vkglDepthRange),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_disable,                   vkglDisable),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_draw_arrays,               vkglDrawArrays),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_draw_buffer,               vkglDrawBuffer),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_draw_elements,             vkglDrawElements),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_enable,                    vkglEnable),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_finish,                    vkglFinish),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_flush,                     vkglFlush),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_front_face,                vkglFrontFace),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_gen_textures,              vkglGenTextures),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_booleanv,              vkglGetBooleanv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_doublev,               vkglGetDoublev),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_error,                 vkglGetError),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_floatv,                vkglGetFloatv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_integerv,              vkglGetIntegerv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_string,                vkglGetString),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_image,             vkglGetTexImage),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_level_parameterfv, vkglGetTexLevelParameterfv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_level_parameteriv, vkglGetTexLevelParameteriv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_parameterfv,       vkglGetTexParameterfv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_get_tex_parameteriv,       vkglGetTexParameteriv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_hint,                      vkglHint),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_is_enabled,                vkglIsEnabled),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_is_texture,                vkglIsTexture),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_line_width,                vkglLineWidth),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_logic_op,                  vkglLogicOp),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_pixel_storef,              vkglPixelStoref),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_pixel_storei,              vkglPixelStorei),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_point_size,                vkglPointSize),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_polygon_mode,              vkglPolygonMode),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_polygon_offset,            vkglPolygonOffset),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_read_buffer,               vkglReadBuffer),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_read_pixels,               vkglReadPixels),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_scissor,                   vkglScissor),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_stencil_func,              vkglStencilFunc),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_stencil_mask,              vkglStencilMask),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_stencil_op,                vkglStencilOp),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_image_1d,              vkglTexImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_image_2d,              vkglTexImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameterf,            vkglTexParameterf),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameterfv,           vkglTexParameterfv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameteri,            vkglTexParameteri),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_parameteriv,           vkglTexParameteriv),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_sub_image_1d,          vkglTexSubImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_tex_sub_image_2d,          vkglTexSubImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) g_cached_gl_viewport_func_ptr,         vkglViewport),
    };
}