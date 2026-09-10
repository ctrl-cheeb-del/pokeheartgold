#include "field_effect_dispatch_internal.h"

BOOL ScrCmd_808(void *ctx) {
    u16 var = FieldSystem_VarGet(*(void **)((u8 *)ctx + 0x80), ScriptReadHalfword(ctx));
    u32 overlay = FS_OVERLAY_ID(OVY_25);
    HandleLoadOverlay(overlay, 2);
    TrainerHouse_StartBattle(*(void **)((u8 *)ctx + 0x80), var);
    UnloadOverlayByID(overlay);
    return TRUE;
}

void ov01_02205424(void *p) {
    *((u8 *)p + 0xf9) = 1;
}

u32 ov01_0220542C(u32 index, u32 value) {
    Overlay01FourValues first = ov01_02209720;
    Overlay01FourValues second = ov01_02209730;
    Overlay01FourValues third = ov01_02209740;
    Overlay01FourValues fourth = ov01_02209710;
    u8 i;
    for (i = 0; i < 4; i++) {
        if (value == first.values[i]) {
            return second.values[index];
        }
    }
    for (i = 0; i < 4; i++) {
        if (value == second.values[i]) {
            return third.values[index];
        }
    }
    for (i = 0; i < 4; i++) {
        if (value == third.values[i]) {
            return fourth.values[index];
        }
    }
    GF_AssertFail();
    return 0;
}
