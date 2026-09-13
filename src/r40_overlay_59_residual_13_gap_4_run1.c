#include "r40_overlay_59_residual_13_gap_4_private.h"

void ov59_0223C304(void *work) {
    vu32 *a = (vu32 *)0x04000440;
    vu32 *b = (vu32 *)0x04000454;
    Thunk_G3X_Reset();
    sub_0201543C();
    Thunk_G3X_Reset();
    NNS_G2dSetupSoftwareSpriteCamera();
    Camera_PushLookAtToNNSGlb();
    *a = 0;
    *b = 0;
    *a = 2;
    *b = 0;
    NNS_G3dGlbFlushP();
    NNS_G2dSetupSoftwareSpriteCamera();
    PokepicManager_DrawAll(*(void **)((u8 *)work + 0xc));
    sub_02015460();
    *(vu32 *)0x04000540 = 1;
}
