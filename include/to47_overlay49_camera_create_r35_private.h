#ifndef POKEHEARTGOLD_OVERLAY49_CAMERA_CREATE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY49_CAMERA_CREATE_PRIVATE_H
#include "global.h"
#include "camera.h"
typedef struct Ov49CameraState {
    Camera *camera;
    u32 unk4;
    VecFx32 target;
} Ov49CameraState;
extern const CameraAngle ov49_02269A6C;
Ov49CameraState *ov49_0225CB78(enum HeapID heapId);

#endif
