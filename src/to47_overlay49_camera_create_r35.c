#include "to47_overlay49_camera_create_r35_private.h"


Ov49CameraState *ov49_0225CB78(enum HeapID heapId) {
    Ov49CameraState *state = Heap_Alloc(heapId, sizeof(Ov49CameraState));
    u32 i;
    u8 *p = (u8 *)state;

    i = sizeof(Ov49CameraState);
    do {
        *p = 0;
        p++;
        i--;
    } while (i != 0);
    state->camera = Camera_New(heapId);
    Camera_Init_FromTargetDistanceAndAngle(&state->target, 0x29AEC1, &ov49_02269A6C, 0x5C1, 0, TRUE, state->camera);
    Camera_SetStaticPtr(state->camera);
    Camera_SetPerspectiveClippingPlane(0x96000, 0x384000, state->camera);
    return state;
}
