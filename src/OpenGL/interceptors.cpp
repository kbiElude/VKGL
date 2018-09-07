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
    /* NOTE: If you add any new entrypoints to this function, make sure to also update OpenGL::Context::init_dispatch_table() */

    /* >= GL 1.2 */
    std::unordered_map<std::string, void*> result;

    result["glCopyTexSubImage3D"] = OpenGL::vkglCopyTexSubImage3D;
    result["glDrawRangeElements"] = OpenGL::vkglDrawRangeElements;
    result["glTexImage3D"]        = OpenGL::vkglTexImage3D;
    result["glTexSubImage3D"]     = OpenGL::vkglTexSubImage3D;

    result["glActiveTexture"]           = OpenGL::vkglActiveTexture;
    result["glCompressedTexImage1D"]    = OpenGL::vkglCompressedTexImage1D;
    result["glCompressedTexImage2D"]    = OpenGL::vkglCompressedTexImage2D;
    result["glCompressedTexImage3D"]    = OpenGL::vkglCompressedTexImage3D;
    result["glCompressedTexSubImage1D"] = OpenGL::vkglCompressedTexSubImage1D;
    result["glCompressedTexSubImage2D"] = OpenGL::vkglCompressedTexSubImage2D;
    result["glCompressedTexSubImage3D"] = OpenGL::vkglCompressedTexSubImage3D;
    result["glGetCompressedTexImage"]   = OpenGL::vkglGetCompressedTexImage;
    result["glSampleCoverage"]          = OpenGL::vkglSampleCoverage;

    result["glBlendColor"]        = OpenGL::vkglBlendColor;
    result["glBlendEquation"]     = OpenGL::vkglBlendEquation;
    result["glBlendFuncSeparate"] = OpenGL::vkglBlendFuncSeparate;
    result["glMultiDrawArrays"]   = OpenGL::vkglMultiDrawArrays;
    result["glMultiDrawElements"] = OpenGL::vkglMultiDrawElements;
    result["glPointParameterf"]   = OpenGL::vkglPointParameterf;
    result["glPointParameterfv"]  = OpenGL::vkglPointParameterfv;
    result["glPointParameteri"]   = OpenGL::vkglPointParameteri;
    result["glPointParameteriv"]  = OpenGL::vkglPointParameteriv;

    result["glBeginQuery"]           = OpenGL::vkglBeginQuery;
    result["glBindBuffer"]           = OpenGL::vkglBindBuffer;
    result["glBufferData"]           = OpenGL::vkglBufferData;
    result["glBufferSubData"]        = OpenGL::vkglBufferSubData;
    result["glDeleteBuffers"]        = OpenGL::vkglDeleteBuffers;
    result["glDeleteQueries"]        = OpenGL::vkglDeleteQueries;
    result["glEndQuery"]             = OpenGL::vkglEndQuery;
    result["glGenBuffers"]           = OpenGL::vkglGenBuffers;
    result["glGenQueries"]           = OpenGL::vkglGenQueries;
    result["glGetBufferParameteriv"] = OpenGL::vkglGetBufferParameteriv;
    result["glGetBufferPointerv"]    = OpenGL::vkglGetBufferPointerv;
    result["glGetBufferSubData"]     = OpenGL::vkglGetBufferSubData;
    result["glGetQueryiv"]           = OpenGL::vkglGetQueryiv;
    result["glGetQueryObjectiv"]     = OpenGL::vkglGetQueryObjectiv;
    result["glGetQueryObjectuiv"]    = OpenGL::vkglGetQueryObjectuiv;
    result["glIsBuffer"]             = OpenGL::vkglIsBuffer;
    result["glIsQuery"]              = OpenGL::vkglIsQuery;
    result["glMapBuffer"]            = OpenGL::vkglMapBuffer;
    result["glUnmapBuffer"]          = OpenGL::vkglUnmapBuffer;

    result["glAttachShader"]             = OpenGL::vkglAttachShader;
    result["glBindAttribLocation"]       = OpenGL::vkglBindAttribLocation;
    result["glBlendEquationSeparate"]    = OpenGL::vkglBlendEquationSeparate;
    result["glCompileShader"]            = OpenGL::vkglCompileShader;
    result["glCreateProgram"]            = OpenGL::vkglCreateProgram;
    result["glCreateShader"]             = OpenGL::vkglCreateShader;
    result["glDeleteProgram"]            = OpenGL::vkglDeleteProgram;
    result["glDeleteShader"]             = OpenGL::vkglDeleteShader;
    result["glDetachShader"]             = OpenGL::vkglDetachShader;
    result["glDisableVertexAttribArray"] = OpenGL::vkglDisableVertexAttribArray;
    result["glDrawBuffers"]              = OpenGL::vkglDrawBuffers;
    result["glEnableVertexAttribArray"]  = OpenGL::vkglEnableVertexAttribArray;
    result["glGetActiveAttrib"]          = OpenGL::vkglGetActiveAttrib;
    result["glGetActiveUniform"]         = OpenGL::vkglGetActiveUniform;
    result["glGetAttachedShaders"]       = OpenGL::vkglGetAttachedShaders;
    result["glGetAttribLocation"]        = OpenGL::vkglGetAttribLocation;
    result["glGetProgramiv"]             = OpenGL::vkglGetProgramiv;
    result["glGetProgramInfoLog"]        = OpenGL::vkglGetProgramInfoLog;
    result["glGetShaderiv"]              = OpenGL::vkglGetShaderiv;
    result["glGetShaderInfoLog"]         = OpenGL::vkglGetShaderInfoLog;
    result["glGetShaderSource"]          = OpenGL::vkglGetShaderSource;
    result["glGetUniformfv"]             = OpenGL::vkglGetUniformfv;
    result["glGetUniformiv"]             = OpenGL::vkglGetUniformiv;
    result["glGetUniformLocation"]       = OpenGL::vkglGetUniformLocation;
    result["glGetVertexAttribdv"]        = OpenGL::vkglGetVertexAttribdv;
    result["glGetVertexAttribfv"]        = OpenGL::vkglGetVertexAttribfv;
    result["glGetVertexAttribiv"]        = OpenGL::vkglGetVertexAttribiv;
    result["glGetVertexAttribPointerv"]  = OpenGL::vkglGetVertexAttribPointerv;
    result["glIsProgram"]                = OpenGL::vkglIsProgram;
    result["glIsShader"]                 = OpenGL::vkglIsShader;
    result["glLinkProgram"]              = OpenGL::vkglLinkProgram;
    result["glShaderSource"]             = OpenGL::vkglShaderSource;
    result["glStencilFuncSeparate"]      = OpenGL::vkglStencilFuncSeparate;
    result["glStencilMaskSeparate"]      = OpenGL::vkglStencilMaskSeparate;
    result["glStencilOpSeparate"]        = OpenGL::vkglStencilOpSeparate;
    result["glUniform1f"]                = OpenGL::vkglUniform1f;
    result["glUniform1fv"]               = OpenGL::vkglUniform1fv;
    result["glUniform1i"]                = OpenGL::vkglUniform1i;
    result["glUniform1iv"]               = OpenGL::vkglUniform1iv;
    result["glUniform2f"]                = OpenGL::vkglUniform2f;
    result["glUniform2fv"]               = OpenGL::vkglUniform2fv;
    result["glUniform2i"]                = OpenGL::vkglUniform2i;
    result["glUniform2iv"]               = OpenGL::vkglUniform2iv;
    result["glUniform3f"]                = OpenGL::vkglUniform3f;
    result["glUniform3fv"]               = OpenGL::vkglUniform3fv;
    result["glUniform3i"]                = OpenGL::vkglUniform3i;
    result["glUniform3iv"]               = OpenGL::vkglUniform3iv;
    result["glUniform4f"]                = OpenGL::vkglUniform4f;
    result["glUniform4fv"]               = OpenGL::vkglUniform4fv;
    result["glUniform4i"]                = OpenGL::vkglUniform4i;
    result["glUniform4iv"]               = OpenGL::vkglUniform4iv;
    result["glUniformMatrix2fv"]         = OpenGL::vkglUniformMatrix2fv;
    result["glUniformMatrix3fv"]         = OpenGL::vkglUniformMatrix3fv;
    result["glUniformMatrix4fv"]         = OpenGL::vkglUniformMatrix4fv;
    result["glUseProgram"]               = OpenGL::vkglUseProgram;
    result["glValidateProgram"]          = OpenGL::vkglValidateProgram;
    result["glVertexAttrib1d"]           = OpenGL::vkglVertexAttrib1d;
    result["glVertexAttrib1dv"]          = OpenGL::vkglVertexAttrib1dv;
    result["glVertexAttrib1f"]           = OpenGL::vkglVertexAttrib1f;
    result["glVertexAttrib1fv"]          = OpenGL::vkglVertexAttrib1fv;
    result["glVertexAttrib1s"]           = OpenGL::vkglVertexAttrib1s;
    result["glVertexAttrib1sv"]          = OpenGL::vkglVertexAttrib1sv;
    result["glVertexAttrib2d"]           = OpenGL::vkglVertexAttrib2d;
    result["glVertexAttrib2dv"]          = OpenGL::vkglVertexAttrib2dv;
    result["glVertexAttrib2f"]           = OpenGL::vkglVertexAttrib2f;
    result["glVertexAttrib2fv"]          = OpenGL::vkglVertexAttrib2fv;
    result["glVertexAttrib2s"]           = OpenGL::vkglVertexAttrib2s;
    result["glVertexAttrib2sv"]          = OpenGL::vkglVertexAttrib2sv;
    result["glVertexAttrib3d"]           = OpenGL::vkglVertexAttrib3d;
    result["glVertexAttrib3dv"]          = OpenGL::vkglVertexAttrib3dv;
    result["glVertexAttrib3f"]           = OpenGL::vkglVertexAttrib3f;
    result["glVertexAttrib3fv"]          = OpenGL::vkglVertexAttrib3fv;
    result["glVertexAttrib3s"]           = OpenGL::vkglVertexAttrib3s;
    result["glVertexAttrib3sv"]          = OpenGL::vkglVertexAttrib3sv;
    result["glVertexAttrib4bv"]          = OpenGL::vkglVertexAttrib4bv;
    result["glVertexAttrib4d"]           = OpenGL::vkglVertexAttrib4d;
    result["glVertexAttrib4dv"]          = OpenGL::vkglVertexAttrib4dv;
    result["glVertexAttrib4f"]           = OpenGL::vkglVertexAttrib4f;
    result["glVertexAttrib4fv"]          = OpenGL::vkglVertexAttrib4fv;
    result["glVertexAttrib4iv"]          = OpenGL::vkglVertexAttrib4iv;
    result["glVertexAttrib4Nbv"]         = OpenGL::vkglVertexAttrib4Nbv;
    result["glVertexAttrib4Niv"]         = OpenGL::vkglVertexAttrib4Niv;
    result["glVertexAttrib4Nsv"]         = OpenGL::vkglVertexAttrib4Nsv;
    result["glVertexAttrib4Nub"]         = OpenGL::vkglVertexAttrib4Nub;
    result["glVertexAttrib4Nubv"]        = OpenGL::vkglVertexAttrib4Nubv;
    result["glVertexAttrib4Nuiv"]        = OpenGL::vkglVertexAttrib4Nuiv;
    result["glVertexAttrib4Nusv"]        = OpenGL::vkglVertexAttrib4Nusv;
    result["glVertexAttrib4s"]           = OpenGL::vkglVertexAttrib4s;
    result["glVertexAttrib4sv"]          = OpenGL::vkglVertexAttrib4sv;
    result["glVertexAttrib4ubv"]         = OpenGL::vkglVertexAttrib4ubv;
    result["glVertexAttrib4uiv"]         = OpenGL::vkglVertexAttrib4uiv;
    result["glVertexAttrib4usv"]         = OpenGL::vkglVertexAttrib4usv;
    result["glVertexAttribPointer"]      = OpenGL::vkglVertexAttribPointer;

    result["glUniformMatrix2x3fv"] = OpenGL::vkglUniformMatrix2x3fv;
    result["glUniformMatrix2x4fv"] = OpenGL::vkglUniformMatrix2x4fv;
    result["glUniformMatrix3x2fv"] = OpenGL::vkglUniformMatrix3x2fv;
    result["glUniformMatrix3x4fv"] = OpenGL::vkglUniformMatrix3x4fv;
    result["glUniformMatrix4x2fv"] = OpenGL::vkglUniformMatrix4x2fv;
    result["glUniformMatrix4x3fv"] = OpenGL::vkglUniformMatrix4x3fv;

    result["glBeginConditionalRender"]              = OpenGL::vkglBeginConditionalRender;
    result["glBeginTransformFeedback"]              = OpenGL::vkglBeginTransformFeedback;
    result["glBindBufferBase"]                      = OpenGL::vkglBindBufferBase;
    result["glBindBufferRange"]                     = OpenGL::vkglBindBufferRange;
    result["glBindFragDataLocation"]                = OpenGL::vkglBindFragDataLocation;
    result["glBindFramebuffer"]                     = OpenGL::vkglBindFramebuffer;
    result["glBindRenderbuffer"]                    = OpenGL::vkglBindRenderbuffer;
    result["glBindVertexArray"]                     = OpenGL::vkglBindVertexArray;
    result["glBlitFramebuffer"]                     = OpenGL::vkglBlitFramebuffer;
    result["glCheckFramebufferStatus"]              = OpenGL::vkglCheckFramebufferStatus;
    result["glClampColor"]                          = OpenGL::vkglClampColor;
    result["glClearBufferfi"]                       = OpenGL::vkglClearBufferfi;
    result["glClearBufferfv"]                       = OpenGL::vkglClearBufferfv;
    result["glClearBufferiv"]                       = OpenGL::vkglClearBufferiv;
    result["glClearBufferuiv"]                      = OpenGL::vkglClearBufferuiv;
    result["glColorMaski"]                          = OpenGL::vkglColorMaski;
    result["glDeleteFramebuffers"]                  = OpenGL::vkglDeleteFramebuffers;
    result["glDeleteRenderbuffers"]                 = OpenGL::vkglDeleteRenderbuffers;
    result["glDeleteVertexArrays"]                  = OpenGL::vkglDeleteVertexArrays;
    result["glDisablei"]                            = OpenGL::vkglDisablei;
    result["glEnablei"]                             = OpenGL::vkglEnablei;
    result["glEndConditionalRender"]                = OpenGL::vkglEndConditionalRender;
    result["glEndTransformFeedback"]                = OpenGL::vkglEndTransformFeedback;
    result["glFlushMappedBufferRange"]              = OpenGL::vkglFlushMappedBufferRange;
    result["glFramebufferRenderbuffer"]             = OpenGL::vkglFramebufferRenderbuffer;
    result["glFramebufferTexture1D"]                = OpenGL::vkglFramebufferTexture1D;
    result["glFramebufferTexture2D"]                = OpenGL::vkglFramebufferTexture2D;
    result["glFramebufferTexture3D"]                = OpenGL::vkglFramebufferTexture3D;
    result["glFramebufferTextureLayer"]             = OpenGL::vkglFramebufferTextureLayer;
    result["glGenerateMipmap"]                      = OpenGL::vkglGenerateMipmap;
    result["glGenFramebuffers"]                     = OpenGL::vkglGenFramebuffers;
    result["glGenRenderbuffers"]                    = OpenGL::vkglGenRenderbuffers;
    result["glGenVertexArrays"]                     = OpenGL::vkglGenVertexArrays;
    result["glGetBooleani_v"]                       = OpenGL::vkglGetBooleani_v;
    result["glGetFragDataLocation"]                 = OpenGL::vkglGetFragDataLocation;
    result["glGetFramebufferAttachmentParameteriv"] = OpenGL::vkglGetFramebufferAttachmentParameteriv;
    result["glGetIntegeri_v"]                       = OpenGL::vkglGetIntegeri_v;
    result["glGetRenderbufferParameteriv"]          = OpenGL::vkglGetRenderbufferParameteriv;
    result["glGetStringi"]                          = OpenGL::vkglGetStringi;
    result["glGetTexParameterIiv"]                  = OpenGL::vkglGetTexParameterIiv;
    result["glGetTexParameterIuiv"]                 = OpenGL::vkglGetTexParameterIuiv;
    result["glGetTransformFeedbackVarying"]         = OpenGL::vkglGetTransformFeedbackVarying;
    result["glGetUniformuiv"]                       = OpenGL::vkglGetUniformuiv;
    result["glGetVertexAttribIiv"]                  = OpenGL::vkglGetVertexAttribIiv;
    result["glGetVertexAttribIuiv"]                 = OpenGL::vkglGetVertexAttribIuiv;
    result["glIsEnabledi"]                          = OpenGL::vkglIsEnabledi;
    result["glIsFramebuffer"]                       = OpenGL::vkglIsFramebuffer;
    result["glIsRenderbuffer"]                      = OpenGL::vkglIsRenderbuffer;
    result["glIsVertexArray"]                       = OpenGL::vkglIsVertexArray;
    result["glMapBufferRange"]                      = OpenGL::vkglMapBufferRange;
    result["glRenderbufferStorage"]                 = OpenGL::vkglRenderbufferStorage;
    result["glRenderbufferStorageMultisample"]      = OpenGL::vkglRenderbufferStorageMultisample;
    result["glTexParameterIiv"]                     = OpenGL::vkglTexParameterIiv;
    result["glTexParameterIuiv"]                    = OpenGL::vkglTexParameterIuiv;
    result["glTransformFeedbackVaryings"]           = OpenGL::vkglTransformFeedbackVaryings;
    result["glUniform1ui"]                          = OpenGL::vkglUniform1ui;
    result["glUniform1uiv"]                         = OpenGL::vkglUniform1uiv;
    result["glUniform2ui"]                          = OpenGL::vkglUniform2ui;
    result["glUniform2uiv"]                         = OpenGL::vkglUniform2uiv;
    result["glUniform3ui"]                          = OpenGL::vkglUniform3ui;
    result["glUniform3uiv"]                         = OpenGL::vkglUniform3uiv;
    result["glUniform4ui"]                          = OpenGL::vkglUniform4ui;
    result["glUniform4uiv"]                         = OpenGL::vkglUniform4uiv;
    result["glVertexAttribI1i"]                     = OpenGL::vkglVertexAttribI1i;
    result["glVertexAttribI1iv"]                    = OpenGL::vkglVertexAttribI1iv;
    result["glVertexAttribI1ui"]                    = OpenGL::vkglVertexAttribI1ui;
    result["glVertexAttribI1uiv"]                   = OpenGL::vkglVertexAttribI1uiv;
    result["glVertexAttribI2i"]                     = OpenGL::vkglVertexAttribI2i;
    result["glVertexAttribI2iv"]                    = OpenGL::vkglVertexAttribI2iv;
    result["glVertexAttribI2ui"]                    = OpenGL::vkglVertexAttribI2ui;
    result["glVertexAttribI2uiv"]                   = OpenGL::vkglVertexAttribI2uiv;
    result["glVertexAttribI3i"]                     = OpenGL::vkglVertexAttribI3i;
    result["glVertexAttribI3iv"]                    = OpenGL::vkglVertexAttribI3iv;
    result["glVertexAttribI3ui"]                    = OpenGL::vkglVertexAttribI3ui;
    result["glVertexAttribI3uiv"]                   = OpenGL::vkglVertexAttribI3uiv;
    result["glVertexAttribI4bv"]                    = OpenGL::vkglVertexAttribI4bv;
    result["glVertexAttribI4i"]                     = OpenGL::vkglVertexAttribI4i;
    result["glVertexAttribI4iv"]                    = OpenGL::vkglVertexAttribI4iv;
    result["glVertexAttribI4sv"]                    = OpenGL::vkglVertexAttribI4sv;
    result["glVertexAttribI4ubv"]                   = OpenGL::vkglVertexAttribI4ubv;
    result["glVertexAttribI4ui"]                    = OpenGL::vkglVertexAttribI4ui;
    result["glVertexAttribI4uiv"]                   = OpenGL::vkglVertexAttribI4uiv;
    result["glVertexAttribI4usv"]                   = OpenGL::vkglVertexAttribI4usv;
    result["glVertexAttribIPointer"]                = OpenGL::vkglVertexAttribIPointer;

    result["glCopyBufferSubData"]         = OpenGL::vkglCopyBufferSubData;
    result["glDrawArraysInstanced"]       = OpenGL::vkglDrawArraysInstanced;
    result["glDrawElementsInstanced"]     = OpenGL::vkglDrawElementsInstanced;
    result["glGetActiveUniformsiv"]       = OpenGL::vkglGetActiveUniformsiv;
    result["glGetActiveUniformBlockiv"]   = OpenGL::vkglGetActiveUniformBlockiv;
    result["glGetActiveUniformBlockName"] = OpenGL::vkglGetActiveUniformBlockName;
    result["glGetActiveUniformName"]      = OpenGL::vkglGetActiveUniformName;
    result["glGetUniformBlockIndex"]      = OpenGL::vkglGetUniformBlockIndex;
    result["glGetUniformIndices"]         = OpenGL::vkglGetUniformIndices;
    result["glPrimitiveRestartIndex"]     = OpenGL::vkglPrimitiveRestartIndex;
    result["glTexBuffer"]                 = OpenGL::vkglTexBuffer;
    result["glUniformBlockBinding"]       = OpenGL::vkglUniformBlockBinding;

    result["glClientWaitSync"]                  = OpenGL::vkglClientWaitSync;
    result["glDeleteSync"]                      = OpenGL::vkglDeleteSync;
    result["glDrawElementsBaseVertex"]          = OpenGL::vkglDrawElementsBaseVertex;
    result["glDrawElementsInstancedBaseVertex"] = OpenGL::vkglDrawElementsInstancedBaseVertex;
    result["glDrawRangeElementsBaseVertex"]     = OpenGL::vkglDrawRangeElementsBaseVertex;
    result["glFenceSync"]                       = OpenGL::vkglFenceSync;
    result["glFramebufferTexture"]              = OpenGL::vkglFramebufferTexture;
    result["glGetBufferParameteri64v"]          = OpenGL::vkglGetBufferParameteri64v;
    result["glGetInteger64i_v"]                 = OpenGL::vkglGetInteger64i_v;
    result["glGetInteger64v"]                   = OpenGL::vkglGetInteger64v;
    result["glGetMultisamplefv"]                = OpenGL::vkglGetMultisamplefv;
    result["glGetSynciv"]                       = OpenGL::vkglGetSynciv;
    result["glIsSync"]                          = OpenGL::vkglIsSync;
    result["glMultiDrawElementsBaseVertex"]     = OpenGL::vkglMultiDrawElementsBaseVertex;
    result["glProvokingVertex"]                 = OpenGL::vkglProvokingVertex;
    result["glSampleMaski"]                     = OpenGL::vkglSampleMaski;
    result["glTexImage2DMultisample"]           = OpenGL::vkglTexImage2DMultisample;
    result["glTexImage3DMultisample"]           = OpenGL::vkglTexImage3DMultisample;
    result["glWaitSync"]                        = OpenGL::vkglWaitSync;

    result["glClampColorARB"] = OpenGL::vkglClampColorARB;

    result["glDrawBuffersARB"] = OpenGL::vkglDrawBuffersARB;

    result["glDrawArraysInstancedARB"]   = OpenGL::vkglDrawArraysInstancedARB;
    result["glDrawElementsInstancedARB"] = OpenGL::vkglDrawElementsInstancedARB;

    result["glSampleCoverageARB"] = OpenGL::vkglSampleCoverageARB;

    result["glActiveTextureARB"] = OpenGL::vkglActiveTextureARB;

    result["glBeginQueryARB"]        = OpenGL::vkglBeginQueryARB;
    result["glDeleteQueriesARB"]     = OpenGL::vkglDeleteQueriesARB;
    result["glEndQueryARB"]          = OpenGL::vkglEndQueryARB;
    result["glGenQueriesARB"]        = OpenGL::vkglGenQueriesARB;
    result["glGetQueryivARB"]        = OpenGL::vkglGetQueryivARB;
    result["glGetQueryObjectivARB"]  = OpenGL::vkglGetQueryObjectivARB;
    result["glGetQueryObjectuivARB"] = OpenGL::vkglGetQueryObjectuivARB;
    result["glIsQueryARB"]           = OpenGL::vkglIsQueryARB;

    result["glPointParameterfARB"]  = OpenGL::vkglPointParameterfARB;
    result["glPointParameterfvARB"] = OpenGL::vkglPointParameterfvARB;

    result["glTexBufferARB"] = OpenGL::vkglTexBufferARB;

    result["glCompressedTexImage1DARB"]    = OpenGL::vkglCompressedTexImage1DARB;
    result["glCompressedTexImage2DARB"]    = OpenGL::vkglCompressedTexImage2DARB;
    result["glCompressedTexImage3DARB"]    = OpenGL::vkglCompressedTexImage3DARB;
    result["glCompressedTexSubImage1DARB"] = OpenGL::vkglCompressedTexSubImage1DARB;
    result["glCompressedTexSubImage2DARB"] = OpenGL::vkglCompressedTexSubImage2DARB;
    result["glCompressedTexSubImage3DARB"] = OpenGL::vkglCompressedTexSubImage3DARB;
    result["glGetCompressedTexImageARB"]   = OpenGL::vkglGetCompressedTexImageARB;

    result["glBindBufferARB"]           = OpenGL::vkglBindBufferARB;
    result["glBufferDataARB"]           = OpenGL::vkglBufferDataARB;
    result["glBufferSubDataARB"]        = OpenGL::vkglBufferSubDataARB;
    result["glDeleteBuffersARB"]        = OpenGL::vkglDeleteBuffersARB;
    result["glGenBuffersARB"]           = OpenGL::vkglGenBuffersARB;
    result["glGetBufferParameterivARB"] = OpenGL::vkglGetBufferParameterivARB;
    result["glGetBufferPointervARB"]    = OpenGL::vkglGetBufferPointervARB;
    result["glGetBufferSubDataARB"]     = OpenGL::vkglGetBufferSubDataARB;
    result["glIsBufferARB"]             = OpenGL::vkglIsBufferARB;
    result["glMapBufferARB"]            = OpenGL::vkglMapBufferARB;
    result["glUnmapBufferARB"]          = OpenGL::vkglUnmapBufferARB;

    result["glDisableVertexAttribArrayARB"] = OpenGL::vkglDisableVertexAttribArrayARB;
    result["glEnableVertexAttribArrayARB"]  = OpenGL::vkglEnableVertexAttribArrayARB;
    result["glGetVertexAttribdvARB"]        = OpenGL::vkglGetVertexAttribdvARB;
    result["glGetVertexAttribfvARB"]        = OpenGL::vkglGetVertexAttribfvARB;
    result["glGetVertexAttribivARB"]        = OpenGL::vkglGetVertexAttribivARB;
    result["glGetVertexAttribPointervARB"]  = OpenGL::vkglGetVertexAttribPointervARB;
    result["glVertexAttrib1dvARB"]          = OpenGL::vkglVertexAttrib1dvARB;
    result["glVertexAttrib1dARB"]           = OpenGL::vkglVertexAttrib1dARB;
    result["glVertexAttrib1fvARB"]          = OpenGL::vkglVertexAttrib1fvARB;
    result["glVertexAttrib1fARB"]           = OpenGL::vkglVertexAttrib1fARB;
    result["glVertexAttrib1svARB"]          = OpenGL::vkglVertexAttrib1svARB;
    result["glVertexAttrib1sARB"]           = OpenGL::vkglVertexAttrib1sARB;
    result["glVertexAttrib2dvARB"]          = OpenGL::vkglVertexAttrib2dvARB;
    result["glVertexAttrib2dARB"]           = OpenGL::vkglVertexAttrib2dARB;
    result["glVertexAttrib2fvARB"]          = OpenGL::vkglVertexAttrib2fvARB;
    result["glVertexAttrib2fARB"]           = OpenGL::vkglVertexAttrib2fARB;
    result["glVertexAttrib2svARB"]          = OpenGL::vkglVertexAttrib2svARB;
    result["glVertexAttrib2sARB"]           = OpenGL::vkglVertexAttrib2sARB;
    result["glVertexAttrib3dvARB"]          = OpenGL::vkglVertexAttrib3dvARB;
    result["glVertexAttrib3dARB"]           = OpenGL::vkglVertexAttrib3dARB;
    result["glVertexAttrib3fvARB"]          = OpenGL::vkglVertexAttrib3fvARB;
    result["glVertexAttrib3fARB"]           = OpenGL::vkglVertexAttrib3fARB;
    result["glVertexAttrib3svARB"]          = OpenGL::vkglVertexAttrib3svARB;
    result["glVertexAttrib3sARB"]           = OpenGL::vkglVertexAttrib3sARB;
    result["glVertexAttrib4bvARB"]          = OpenGL::vkglVertexAttrib4bvARB;
    result["glVertexAttrib4dvARB"]          = OpenGL::vkglVertexAttrib4dvARB;
    result["glVertexAttrib4dARB"]           = OpenGL::vkglVertexAttrib4dARB;
    result["glVertexAttrib4fvARB"]          = OpenGL::vkglVertexAttrib4fvARB;
    result["glVertexAttrib4fARB"]           = OpenGL::vkglVertexAttrib4fARB;
    result["glVertexAttrib4ivARB"]          = OpenGL::vkglVertexAttrib4ivARB;
    result["glVertexAttrib4NbvARB"]         = OpenGL::vkglVertexAttrib4NbvARB;
    result["glVertexAttrib4NivARB"]         = OpenGL::vkglVertexAttrib4NivARB;
    result["glVertexAttrib4NsvARB"]         = OpenGL::vkglVertexAttrib4NsvARB;
    result["glVertexAttrib4NubvARB"]        = OpenGL::vkglVertexAttrib4NubvARB;
    result["glVertexAttrib4NubARB"]         = OpenGL::vkglVertexAttrib4NubARB;
    result["glVertexAttrib4NuivARB"]        = OpenGL::vkglVertexAttrib4NuivARB;
    result["glVertexAttrib4svARB"]          = OpenGL::vkglVertexAttrib4svARB;
    result["glVertexAttrib4sARB"]           = OpenGL::vkglVertexAttrib4sARB;
    result["glVertexAttrib4ubvARB"]         = OpenGL::vkglVertexAttrib4ubvARB;
    result["glVertexAttrib4uivARB"]         = OpenGL::vkglVertexAttrib4uivARB;
    result["glVertexAttrib4usvARB"]         = OpenGL::vkglVertexAttrib4usvARB;
    result["glVertexAttribPointerARB"]      = OpenGL::vkglVertexAttribPointerARB;

    result["glBindAttribLocationARB"] = OpenGL::vkglBindAttribLocationARB;
    result["glGetActiveAttribARB"]    = OpenGL::vkglGetActiveAttribARB;
    result["glGetAttribLocationARB"]  = OpenGL::vkglGetAttribLocationARB;

    return result;
}

std::vector<VKGL::FunctionInterceptor> OpenGL::get_function_interceptors()
{
    /* NOTE: If you add any new entrypoints to this function, make sure to also update OpenGL::Context::init_dispatch_table() */

    /* <= GL 1.1 */
    return std::vector<VKGL::FunctionInterceptor>
    {
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_bind_texture,              OpenGL::vkglBindTexture),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_clear,                     OpenGL::vkglClear),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_clear_color,               OpenGL::vkglClearColor),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_clear_depth,               OpenGL::vkglClearDepth),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_clear_stencil,             OpenGL::vkglClearStencil),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_color_mask,                OpenGL::vkglColorMask),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_copy_tex_image_1d,         OpenGL::vkglCopyTexImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_copy_tex_image_2d,         OpenGL::vkglCopyTexImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_copy_tex_sub_image_1d,     OpenGL::vkglCopyTexSubImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_copy_tex_sub_image_2d,     OpenGL::vkglCopyTexSubImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_cull_face,                 OpenGL::vkglCullFace),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_delete_textures,           OpenGL::vkglDeleteTextures),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_depth_func,                OpenGL::vkglDepthFunc),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_depth_mask,                OpenGL::vkglDepthMask),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_depth_range,               OpenGL::vkglDepthRange),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_disable,                   OpenGL::vkglDisable),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_draw_arrays,               OpenGL::vkglDrawArrays),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_draw_buffer,               OpenGL::vkglDrawBuffer),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_draw_elements,             OpenGL::vkglDrawElements),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_enable,                    OpenGL::vkglEnable),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_finish,                    OpenGL::vkglFinish),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_flush,                     OpenGL::vkglFlush),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_front_face,                OpenGL::vkglFrontFace),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_gen_textures,              OpenGL::vkglGenTextures),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_booleanv,              OpenGL::vkglGetBooleanv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_doublev,               OpenGL::vkglGetDoublev),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_error,                 OpenGL::vkglGetError),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_floatv,                OpenGL::vkglGetFloatv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_integerv,              OpenGL::vkglGetIntegerv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_string,                OpenGL::vkglGetString),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_tex_image,             OpenGL::vkglGetTexImage),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_tex_level_parameterfv, OpenGL::vkglGetTexLevelParameterfv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_tex_level_parameteriv, OpenGL::vkglGetTexLevelParameteriv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_tex_parameterfv,       OpenGL::vkglGetTexParameterfv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_get_tex_parameteriv,       OpenGL::vkglGetTexParameteriv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_hint,                      OpenGL::vkglHint),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_is_enabled,                OpenGL::vkglIsEnabled),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_is_texture,                OpenGL::vkglIsTexture),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_line_width,                OpenGL::vkglLineWidth),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_logic_op,                  OpenGL::vkglLogicOp),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_pixel_storef,              OpenGL::vkglPixelStoref),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_pixel_storei,              OpenGL::vkglPixelStorei),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_point_size,                OpenGL::vkglPointSize),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_polygon_mode,              OpenGL::vkglPolygonMode),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_polygon_offset,            OpenGL::vkglPolygonOffset),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_read_buffer,               OpenGL::vkglReadBuffer),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_read_pixels,               OpenGL::vkglReadPixels),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_scissor,                   OpenGL::vkglScissor),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_stencil_func,              OpenGL::vkglStencilFunc),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_stencil_mask,              OpenGL::vkglStencilMask),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_stencil_op,                OpenGL::vkglStencilOp),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_image_1d,              OpenGL::vkglTexImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_image_2d,              OpenGL::vkglTexImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_parameterf,            OpenGL::vkglTexParameterf),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_parameterfv,           OpenGL::vkglTexParameterfv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_parameteri,            OpenGL::vkglTexParameteri),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_parameteriv,           OpenGL::vkglTexParameteriv),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_sub_image_1d,          OpenGL::vkglTexSubImage1D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_tex_sub_image_2d,          OpenGL::vkglTexSubImage2D),
        VKGL::FunctionInterceptor(&(PVOID&) OpenGL::g_cached_gl_viewport_func_ptr,         OpenGL::vkglViewport),
    };
}