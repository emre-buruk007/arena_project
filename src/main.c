#include "raylib.h"
#include "stdio.h"
#include "camera.h"

int main(void) {

    // window boilerplate
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Arena Prototype");
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // x, y, z for cam position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 20.0f;
    camera.projection = CAMERA_ORTHOGRAPHIC;

    float cameraSpeed = 4.0;

    SetTargetFPS(60);

    int scrollSpeed = 1;

    while(!WindowShouldClose()) {

        UpdateMyCamera(&camera);
        

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawGrid(10.f, 1.0f);
        DrawCube((Vector3){0.0f, 0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, RED);
        DrawCubeWires((Vector3){0.0f, 0.5f, 0.0f}, 1.0f, 1.0f, 1.0f, MAROON);
        EndMode3D();

        DrawText("We successfully printed on the screen", 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Cam Z: %0.2f | Mouse X: %d | Mouse Y: %d | Screen Width: %d", camera.position.z, GetMouseX(), GetMouseY(), GetScreenWidth()), 10, 40, 20, DARKGRAY);
        DrawText(TextFormat("Cam fovy: %0.2f", camera.fovy), 10, 70, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}