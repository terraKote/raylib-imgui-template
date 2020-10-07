cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(ralib-imgui-template VERSION 0.1.0)

SET(BUILD_EXAMPLES OFF CACHE BOOL "Disable building examples")

add_library(
    imgui
    dependencies/imgui/imgui.h
    dependencies/imgui/imgui.cpp
    dependencies/imgui/imgui_draw.cpp
    dependencies/imgui/imconfig.h
    dependencies/imgui/imgui_demo.cpp
    dependencies/imgui/imgui_internal.h
    dependencies/imgui/imgui_widgets.cpp
    dependencies/imgui/imstb_rectpack.h
    dependencies/imgui/imstb_textedit.h
    dependencies/imgui/imstb_truetype.h
    dependencies/imgui/examples/imgui_impl_opengl3.h
    dependencies/imgui/examples/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/imgui)
target_include_directories(imgui PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/raylib/src/external/glfw/deps)
target_compile_definitions(imgui PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD2)

add_subdirectory(dependencies/raylib)
add_subdirectory(template)
add_subdirectory(example)