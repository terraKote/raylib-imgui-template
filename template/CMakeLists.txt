add_library(
    template
    src/imgui_impl_raylib.hpp
    src/imgui_impl_raylib.cpp
)

target_link_libraries(template PUBLIC raylib)
target_link_libraries(template PUBLIC imgui)

target_include_directories(template PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(template PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/imgui)