cmake_minimum_required(VERSION 3.5)
project(track_recognizer VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH /usr/local/lib/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw3)
#set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_CXX_COMPILER "g++")

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

find_package (OpenGL REQUIRED)
find_package (glfw3 REQUIRED)

include_directories(/usr/local/include glad)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

find_library(COCOA_LIBRARY Cocoa REQUIRED)
find_library(IOKIT_LIBRARY IOKit REQUIRED)
find_library(COREVID_LIBRARY CoreVideo REQUIRED)
find_library(GLEW_LIBRARY GLEW REQUIRED)

include_directories(engine/)
include_directories(engine/shader/)

add_executable(track_recognizer
        main.cpp
        engine/
        engine/shader/
        engine/shader/shader.cpp engine/shader/shader.h
        engine/shader/loader.cpp engine/shader/loader.h
        engine/shader/compiler.cpp engine/shader/compiler.h
        engine/error.cpp engine/error.h
        engine/shader/basic_shader.h engine/primitive/mesh.h engine/primitive/mesh_loader.cpp engine/primitive/mesh_loader.h engine/vendor/obj_loader_bly7.h engine/primitive/texture.h engine/mesh/vertex.h engine/mesh/texture.h engine/primitive/entity.h engine/primitive/camera.h engine/primitive/model.cpp engine/primitive/model.h engine/primitive/camera.cpp engine/primitive/entity.cpp)
target_link_libraries (track_recognizer
        ${OPENGL_LIBRARIES}
        ${COCOA_LIBRARY}
        ${COREVID_LIBRARY}
        ${IOKIT_LIBRARY}
        ${GLEW_LIBRARY}
        ${GLFW3_LIBRARY} glfw)

#/usr/local/lib/libSOIL.a
#/usr/local/include/SOIL.h