/*******************************************************************************************
*
*   raylib cimgui example
*
*   Migrated to raylib cimgui by Alfred Reinold Baudisch
*   from the official samples from dear imgui.
*
*   Heavily inspired by the original "rlImGui" C++
*   implementation Copyright (c) 2024 Jeffery Myers (LICENSE: ZLIB).
*
********************************************************************************************/

#include "raylib.h"
#include "../imgui_impl_raylib.h"
#include "../rlcimgui.h"
#include <stdlib.h>
#include <math.h>

static void setupImGui()
{
    // Setup Dear ImGui context
    igCreateContext(NULL);
    ImGuiIO *ioptr = igGetIO_Nil();
    ioptr->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
    ioptr->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    
    // set docking
#ifdef IMGUI_HAS_DOCK
    ioptr->ConfigFlags |= ImGuiConfigFlags_DockingEnable;       // Enable Docking
    ioptr->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;     // Enable Multi-Viewport / Platform Windows
#endif
    
    // Setup Dear ImGui style
    igStyleColorsDark(NULL);

    // Setup Platform/Renderer backends
    ImGui_ImplRaylib_Init();

    ImFontAtlas_AddFontDefault(ioptr->Fonts, NULL);
    //rligSetupFontAwesome();

    // required to be called to cache the font texture with raylib
    ImGui_ImplRaylib_BuildFontAtlas();
}

static void beginImGui()
{
    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
    // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
    ImGui_ImplRaylib_ProcessEvents();

    // Start the Dear ImGui frame
    ImGui_ImplRaylib_NewFrame();
    igNewFrame();
}

// Main code
int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    // Our state
    bool showDemoWindow = true;
    ImVec4 clearColor = {0.9f, 0.0f, 0.0f, 1.00f};

    // Setup raylib window
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);
    InitWindow(1280, 720, "raylib CIMGUI PURE C");
    SetTargetFPS(144);
 
    setupImGui();

    // Main loop
    bool done = false;
    while (!done)
    {
        beginImGui();

        if (showDemoWindow)
            igShowDemoWindow(&showDemoWindow);

        // Rendering
        igRender();
        BeginDrawing();
        ClearBackground((Color){ (unsigned char)(clearColor.x * 255), (unsigned char)(clearColor.y * 255),(unsigned char)(clearColor.z * 0),(unsigned char)(clearColor.w * 255) });
        ImGui_ImplRaylib_RenderDrawData(igGetDrawData());
        EndDrawing();

        done = WindowShouldClose();
    }

    // Cleanup
    ImGui_ImplRaylib_Shutdown();
    igDestroyContext(NULL);

    CloseWindow();

    return 0;
}
