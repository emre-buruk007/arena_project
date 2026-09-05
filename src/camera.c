#include "raylib.h"
#include "camera.h"

int scrollSpeed = 1;
float cameraSpeed = 4.0;

void UpdateMyCamera(Camera3D *cameraPtr) {
    //camera movement, the Z axis manipulation is to counteract the isometric view maths.
    // move camera left, increase z to counteract 45 degree angle
    if (GetMouseX() <= 30 && GetMouseX() > 5) {
        cameraPtr->position.x -= GetFrameTime() * cameraSpeed;
        cameraPtr->target.x -= GetFrameTime() * cameraSpeed;
        cameraPtr->position.z += GetFrameTime() * cameraSpeed;
        cameraPtr->target.z += GetFrameTime() * cameraSpeed;
    }
    // move camera right
    else if(GetMouseX() >= GetScreenWidth() - 30) {
        cameraPtr->position.x += GetFrameTime() * cameraSpeed;
        cameraPtr->target.x += GetFrameTime() * cameraSpeed;
        cameraPtr->position.z -= GetFrameTime() * cameraSpeed;
        cameraPtr->target.z -= GetFrameTime() * cameraSpeed;
    }
    // move camera up
    else if(GetMouseY() <= 30 && GetMouseX() > 5) {
        cameraPtr->position.z -= GetFrameTime() * cameraSpeed;
        cameraPtr->target.z -= GetFrameTime() * cameraSpeed;
        cameraPtr->position.x -= GetFrameTime() * cameraSpeed;
        cameraPtr->target.x -= GetFrameTime() * cameraSpeed;
    }
    // move camera down
    else if(GetMouseY() >= GetScreenHeight() - 30) {
        cameraPtr->position.z += GetFrameTime() * cameraSpeed;
        cameraPtr->target.z += GetFrameTime() * cameraSpeed;
        cameraPtr->position.x += GetFrameTime() * cameraSpeed;
        cameraPtr->target.x += GetFrameTime() * cameraSpeed;
    };
    //camera zoom
    // nested if is a clamp so can't zoom out too much or zoom in too much
    if(GetMouseWheelMove() != 0) { 
        cameraPtr->fovy -= scrollSpeed * GetMouseWheelMove();
        if (cameraPtr->fovy < 5) {
            cameraPtr->fovy = 5;
        }
        if (cameraPtr->fovy > 30) {
            cameraPtr->fovy = 30;
        }
    }    
    
}