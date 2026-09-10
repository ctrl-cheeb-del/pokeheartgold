#include "overlay_27_helpers_internal.h"

BOOL ov27_0225BDAC(Ov27Work *work) {
    u32 v = (work->unk51C.raw << 27) >> 28;
    if (v - 2 > 4) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov27_0225BDC8(Ov27Work *work) {
    return PlayerSaveData_CheckRunningShoes(LocalFieldData_GetPlayer(Save_LocalFieldData_Get(work->unk10->saveData)));
}

void ov27_0225BDDC(Ov27Sub *sub, Ov27Work *work) {
    sub->unk04 = FieldSystem_GetGearPhoneRingManager(work->unk10);
    sub->unk08 = work->unk39C;
    sub->unk00 = work->unk04;
    sub->unk1C = 0;
}
