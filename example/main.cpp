#include "raylib.h"

#ifndef IMGUI_IMPL_OPENGL_LOADER_GLAD2
#define IMGUI_IMPL_OPENGL_LOADER_GLAD2
#endif // !IMGUI_IMPL_OPENGL_LOADER_GLAD2

#include "imgui.h"
#include "examples/imgui_impl_opengl3.h"
#include "imgui_impl_raylib.hpp"

int main(int argc, char* argv[])
{
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib ImGui Implementation");

    SetTargetFPS(60);

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplOpenGL3_Init();
    ImGui_ImplRaylib_Init();

    while (!WindowShouldClose())
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplRaylib_NewFrame();
        ImGui::NewFrame();
        ImGui_ImplRaylib_ProcessEvent();

        BeginDrawing();

        {
            ClearBackground(RAYWHITE);

            ImGui::ShowDemoWindow();

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        EndDrawing();
    }

    ImGui_ImplRaylib_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();

    CloseWindow();

    return 0;
}