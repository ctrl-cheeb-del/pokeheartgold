#include "r40_unk_0208DF2C_private.h"

void sub_0208DF2C(void *p) {
    VecFx32 pos = _02104EA4;
    CameraAngle angle = { 0, 0, 0, 0 };
    PTR(p, 0x29C) = Camera_New((enum HeapID)0x13);
    Camera_Init_FromPosDistanceAndAngle(&pos, 0x10000, &angle, 0x5C1, 1, PTR(p, 0x29C));
    Camera_SetPerspectiveClippingPlane(0, 0x64000, PTR(p, 0x29C));
    Camera_ClearFixedTarget(PTR(p, 0x29C));
    Camera_SetStaticPtr(PTR(p, 0x29C));
}
