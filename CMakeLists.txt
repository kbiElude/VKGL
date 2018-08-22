cmake_minimum_required (VERSION 2.8)
project (VK_GL)

# DO NOT MODIFY BELOW THIS LINE
include (GenerateExportHeader)

IF(MSVC)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)

    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
ENDIF(MSVC)

SET(CMAKE_INCLUDE_PATH             "${VK_GL_SOURCE_DIR}/include")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${VK_GL_BINARY_DIR}/bin")

INCLUDE_DIRECTORIES("${VK_GL_SOURCE_DIR}/include"
                    "${VK_GL_SOURCE_DIR}/include/Khronos"
                   )

FILE(GLOB GDI32Includes               "${VK_GL_SOURCE_DIR}/include/GDI32/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/GDI32/entrypoints/*.h")
FILE(GLOB GDI32Sources                "${VK_GL_SOURCE_DIR}/src/GDI32/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/GDI32/entrypoints/*.cpp")
FILE(GLOB KhronosInclude              "${VK_GL_SOURCE_DIR}/include/Khronos/GL/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/Khronos/KHR/*.h")
FILE(GLOB OpenGL32EntrypointsIncludes "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_color_buffer_float/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_copy_buffer/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_depth_buffer_float/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_depth_clamp/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_depth_texture/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_draw_buffers/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_draw_elements_base_vertex/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_draw_instanced/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_fragment_coord_conventions/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_fragment_program_shadow/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_framebuffer_object/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_framebuffer_sRGB/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_half_float_pixel/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_half_float_vertex/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_instanced_arrays/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_map_buffer_range/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_multisample/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_multitexture/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_occlusion_query/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_point_parameters/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_point_sprite/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_provoking_vertex/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_seamless_cube_map/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_shader_texture_lod/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_shading_language_100/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_shadow/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_sync/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_border_clamp/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_buffer_object/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_compression/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_compression_rgtc/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_cube_map/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_cube_map_array/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_float/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_gather/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_mirrored_repeat/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_multisample/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_non_power_of_two/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_query_lod/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_rectangle/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_texture_rg/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_uniform_buffer_object/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_vertex_array_bgra/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_vertex_array_object/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_vertex_buffer_object/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_vertex_program/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL_ARB_vertex_shader/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL1.0/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL1.1/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL1.2/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL1.3/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL1.4/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL1.5/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL2.0/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL2.1/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL3.0/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL3.1/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/OpenGL/entrypoints/GL3.2/*.h"
                                                                                                )
FILE(GLOB OpenGL32EntrypointsSources  "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL1.0/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL1.1/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL1.2/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL1.3/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL1.4/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL1.5/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL2.0/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL2.1/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL3.0/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL3.1/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/OpenGL/entrypoints/GL3.2/*.cpp"
                                                                                              )
FILE(GLOB OpenGL32Includes            "${VK_GL_SOURCE_DIR}/include/OpenGL/*.h")
FILE(GLOB OpenGL32Sources             "${VK_GL_SOURCE_DIR}/src/OpenGL/*.cpp")
FILE(GLOB WGLIncludes                 "${VK_GL_SOURCE_DIR}/include/WGL/*.h"
                                      "${VK_GL_SOURCE_DIR}/include/WGL/entrypoints/*.h")
FILE(GLOB WGLSources                  "${VK_GL_SOURCE_DIR}/src/WGL/*.cpp"
                                      "${VK_GL_SOURCE_DIR}/src/WGL/entrypoints/*.cpp")

ADD_LIBRARY(GDI32 STATIC    ${GDI32Sources}
                            ${GDI32Includes})
ADD_LIBRARY(OpenGL32 STATIC ${KhronosIncludes}
                            ${OpenGL32EntrypointsSources}
                            ${OpenGL32EntrypointsIncludes}
                            ${OpenGL32Sources}
                            ${OpenGL32Includes})
ADD_LIBRARY(WGL  STATIC     ${WGLSources}
                            ${WGLIncludes})

SET(LIBRARY_OUTPUT_PATH ${VK_GL_BINARY_DIR}/bin)

SOURCE_GROUP ("GDI32 includes"       FILES ${GDI32Includes})
SOURCE_GROUP ("GDI32 sources"        FILES ${GDI32Sources})
SOURCE_GROUP ("Khronos includes"     FILES ${KhronosIncludes})
SOURCE_GROUP ("Entrypoint includes"  FILES ${OpenGL32EntrypointsIncludes})
SOURCE_GROUP ("Entrypoint sources"   FILES ${OpenGL32EntrypointsSources})
SOURCE_GROUP ("OpenGL32 includes"    FILES ${OpenGL32Includes})
SOURCE_GROUP ("OpenGL32 sources"     FILES ${OpenGL32Sources})
SOURCE_GROUP ("WGL includes"         FILES ${WGLIncludes})
SOURCE_GROUP ("WGL sources"          FILES ${WGLSources})