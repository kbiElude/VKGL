cmake_minimum_required (VERSION 2.8)
project (DetoursVKGL)

INCLUDE_DIRECTORIES("${DetoursVKGL_SOURCE_DIR}/../Detours/src")

FILE(GLOB DetoursIncludes "${DetoursVKGL_SOURCE_DIR}/../Detours/src/*.h")
FILE(GLOB DetoursSources  "${DetoursVKGL_SOURCE_DIR}/../Detours/src/detours.cpp"
                          "${DetoursVKGL_SOURCE_DIR}/../Detours/src/modules.cpp"
                          "${DetoursVKGL_SOURCE_DIR}/../Detours/src/disasm.cpp"
                          "${DetoursVKGL_SOURCE_DIR}/../Detours/src/image.cpp"
                          "${DetoursVKGL_SOURCE_DIR}/../Detours/src/creatwth.cpp"
                          "${DetoursVKGL_SOURCE_DIR}/../Detours/src/disolx86.cpp"
                          "${DetoursVKGL_SOURCE_DIR}/../Detours/src/disolx64.cpp")

if (WIN32)
    if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
        add_definitions(-DDETOURS_64BIT=1)
        add_definitions(-DDETOURS_BITS=64)
        add_definitions(-DDETOURS_TARGET_PROCESSOR=X64)
    else()
        add_definitions(-DDETOURS_64BIT=0)
        add_definitions(-DDETOURS_BITS=32)
        add_definitions(-DDETOURS_TARGET_PROCESSOR=X86)
    endif()
else()
    message(FATAL_ERROR "Only Windows platform is currently supported.")
endif()

ADD_LIBRARY(Detours STATIC  ${DetoursIncludes}
                            ${DetoursSources})

SET(LIBRARY_OUTPUT_PATH ${DetoursVKGL_BINARY_DIR}/bin)

SOURCE_GROUP ("Detours includes" FILES ${DetoursIncludes})
SOURCE_GROUP ("Detours sources"  FILES ${DetoursSources})
