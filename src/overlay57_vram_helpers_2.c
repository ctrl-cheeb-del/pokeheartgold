#include "overlay57_vram_helpers_private.h"

void ov57_02238BCC(void) {
    u32 tex = NNS_GfdDefaultFuncAllocTexVram(0x8000, 0, 0);
    u32 pltt = NNS_GfdDefaultFuncAllocPlttVram(0x80, 0, 0);
    if (tex == 0) GF_AssertFail();
    if (pltt == 0) GF_AssertFail();
    sub_02014DA0();
}

void ov57_02238C0C(void) {
    Thunk_G3X_Reset();
    if (sub_0201543C() > 0) {
        Thunk_G3X_Reset();
        NNS_G2dSetupSoftwareSpriteCamera();
    }
    sub_02015460();
    RequestSwap3DBuffers(1, 0);
}
