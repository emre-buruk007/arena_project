#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"
/**
 * The game's main camera control function, this is to isolate camera logic.
 * @param cameraPtr this is a pointer to the main camera struct.
 */
void UpdateMyCamera(Camera3D *cameraPtr);

#endif