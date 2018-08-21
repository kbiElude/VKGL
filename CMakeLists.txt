cmake_minimum_required (VERSION 2.8)
project (VK_GL)

option(VKGL_INCLUDE_GDI32  "Intercept GDI32 entrypoints"  ON)
option(VKGL_INCLUDE_OPENGL "Intercept OpenGL entrypoints" OFF) # TODO: Does not compile for now.
option(VKGL_INCLUDE_WGL    "Intercept WGL entrypoints"    ON)

# DO NOT MODIFY BELOW THIS LINE
configure_file("${VK_GL_SOURCE_DIR}/include/config.h.in" "${VK_GL_BINARY_DIR}/vkgl_config.h")

add_subdirectory(deps/Detours_VKGL)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif (MSVC)

set(CMAKE_INCLUDE_PATH             "${VK_GL_SOURCE_DIR}/include")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${VK_GL_BINARY_DIR}/bin")

include_directories("${VK_GL_BINARY_DIR}"
                    "${VK_GL_SOURCE_DIR}/deps"
                    "${VK_GL_SOURCE_DIR}/include"
                    "${VK_GL_SOURCE_DIR}/include/Khronos")

file(GLOB LauncherIncludes "${VK_GL_SOURCE_DIR}/include/Launcher/*.h")
file(GLOB LauncherSources  "${VK_GL_SOURCE_DIR}/src/Launcher/*.cpp")

file(GLOB CommonIncludes "${VK_GL_SOURCE_DIR}/include/Common/*.h")

file(GLOB VKGLIncludes "${VK_GL_SOURCE_DIR}/include/VKGL/*.h")
file(GLOB VKGLSources  "${VK_GL_SOURCE_DIR}/src/VKGL/*.cpp"
                       "${VK_GL_SOURCE_DIR}/src/VKGL/*.def")

add_executable(Launcher ${LauncherIncludes}
                        ${LauncherSources})


if (VKGL_INCLUDE_GDI32)
    file(GLOB GDI32Includes "${VK_GL_SOURCE_DIR}/include/GDI32/*.h"
                            "${VK_GL_SOURCE_DIR}/include/GDI32/entrypoints/*.h")
    file(GLOB GDI32Sources  "${VK_GL_SOURCE_DIR}/src/GDI32/*.cpp"
                            "${VK_GL_SOURCE_DIR}/src/GDI32/entrypoints/*.cpp")

    add_library(GDI32 STATIC ${CommonIncludes}
                             ${GDI32Sources}
                             ${GDI32Includes})
endif ()

if (VKGL_INCLUDE_OPENGL)
    FILE(GLOB KhronosInclude "${VK_GL_SOURCE_DIR}/include/Khronos/GL/*.h"
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
                                                                                                  
    FILE(GLOB OpenGL32Includes "${VK_GL_SOURCE_DIR}/include/OpenGL/*.h")
    FILE(GLOB OpenGL32Sources  "${VK_GL_SOURCE_DIR}/src/OpenGL/*.cpp")

    add_library(OPENGL32 STATIC ${CommonIncludes}
                                ${KhronosIncludes}
                                ${OpenGL32EntrypointsSources}
                                ${OpenGL32EntrypointsIncludes}
                                ${OpenGL32Sources}
                                ${OpenGL32Includes})

endif ()

if (VKGL_INCLUDE_WGL)
    file(GLOB WGLIncludes "${VK_GL_SOURCE_DIR}/include/WGL/*.h"
                          "${VK_GL_SOURCE_DIR}/include/WGL/entrypoints/*.h"
                          "${VK_GL_SOURCE_DIR}/include/WGL/entrypoints/WGL_ARB_create_context/*.h"
                          "${VK_GL_SOURCE_DIR}/include/WGL/entrypoints/WGL_ARB_framebuffer_sRGB/*.h")
    file(GLOB WGLSources  "${VK_GL_SOURCE_DIR}/src/WGL/*.cpp"
                          "${VK_GL_SOURCE_DIR}/src/WGL/entrypoints/*.cpp")

    add_library(WGL STATIC ${CommonIncludes}
                           ${WGLSources}
                           ${WGLIncludes})
endif ()

add_library(VKGL SHARED ${VKGLSources})

target_link_libraries(Launcher Detours)
target_link_libraries(VKGL     Detours)

if (VKGL_INCLUDE_GDI32)
    target_link_libraries(VKGL GDI32)
endif ()

if (VKGL_INCLUDE_OPENGL)
    target_link_libraries(VKGL OPENGL32)
endif ()

if (VKGL_INCLUDE_WGL)
    target_link_libraries(VKGL WGL)
endif ()

set(LIBRARY_OUTPUT_PATH ${VK_GL_BINARY_DIR}/bin)

source_group ("Common include files"     FILES ${CommonIncludes})
source_group ("GDI32 include files"      FILES ${GDI32Includes})
source_group ("GDI32 source files"       FILES ${GDI32Sources})
source_group ("Khronos include files"    FILES ${KhronosIncludes})
source_group ("Launcher include files"   FILES ${LauncherIncludes})
source_group ("Launcher source files"    FILES ${LauncherSources})
source_group ("Entrypoint include files" FILES ${OpenGL32EntrypointsIncludes})
source_group ("Entrypoint source files"  FILES ${OpenGL32EntrypointsSources})
source_group ("OpenGL32 include files"   FILES ${OpenGL32Includes})
source_group ("OpenGL32 source files"    FILES ${OpenGL32Sources})
source_group ("WGL include files"        FILES ${WGLIncludes})
source_group ("WGL source files"         FILES ${WGLSources})
