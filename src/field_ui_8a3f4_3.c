#include "field_ui_8a3f4_internal.h"

void sub_0208A8F4(u8 *work) {
    ScheduleSetBgPosText(*(void **)work, 2, 0, 0);
    sub_0208DB1C(work);
    sub_0208A79C(work);
    thunk_Sprite_SetDrawFlag(*(void **)(work + 0x430), 1);
    sub_0208C068(work);
    if (work[0x240] != work[0x241]) {
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x434), 1);
    }
    Sprite_SetDrawFlag(*(void **)(work + 0x428), 1);
}

void sub_0208A950(u8 *work) {
    sub_0208DB1C(work);
    sub_0208A79C(work);
    sub_0208C068(work);
    if (*(s8 *)(work + 0x7BC) == 1) {
        sub_0208C208(work);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x430), 1);
        if (work[0x240] != work[0x241]) {
            thunk_Sprite_SetDrawFlag(*(void **)(work + 0x434), 1);
        }
        ScheduleSetBgPosText(*(void **)work, 2, 3, 0);
    } else {
        sub_0208C0E8(work);
        ScheduleSetBgPosText(*(void **)work, 2, 3, 0x100);
    }
}

BOOL sub_0208A9C4(u8 *work) {
    switch (work[0x7BE]) {
    case 0:
        ScheduleSetBgPosText(*(void **)work, 5, 0, 0);
        ScheduleSetBgPosText(*(void **)work, 5, 3, 0);
        Sprite_SetPriority(*(void **)(work + 0x428), 3);
        thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x428), 0);
        ClearWindowTilemapAndScheduleTransfer(work + 0x1D4);
        ClearWindowTilemapAndScheduleTransfer(work + 0x174);
        ClearWindowTilemapAndScheduleTransfer(*(void **)(work + 0x224));
        work[0x7C5] = 0;
        work[0x7BE] = 1;
        break;
    case 1:
        if (Bg_GetYpos(*(void **)work, 5) >= 0x48) {
            ScheduleSetBgPosText(*(void **)work, 5, 3, 0x48);
            work[0x7BE] = 2;
        } else {
            ScheduleSetBgPosText(*(void **)work, 5, 4, 0x24);
        }
        break;
    case 2:
        Sprite_SetDrawFlag(*(void **)(work + 0x500), 1);
        Sprite_SetDrawFlag(*(void **)(work + 0x50C), 1);
        sub_0208AB58(work, 0);
        work[0x7BE] = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL sub_0208AA9C(u8 *work) {
    switch (work[0x7BE]) {
    case 0:
        work[0x7C4] = 0;
        work[0x7C5] = 0;
        ClearWindowTilemapAndScheduleTransfer(*(u8 **)(work + 0x224) + 0x10);
        ClearWindowTilemapAndScheduleTransfer(*(u8 **)(work + 0x224) + 0x20);
        sub_0208C2A0(work);
        work[0x7BE] = 1;
        break;
    case 1:
        if (Bg_GetYpos(*(void **)work, 5) <= 0) {
            ScheduleSetBgPosText(*(void **)work, 5, 3, 0);
            work[0x7BE] = 2;
        } else {
            ScheduleSetBgPosText(*(void **)work, 5, 5, 0x24);
        }
        break;
    case 2:
        ScheduleWindowCopyToVram(work + 0x1D4);
        ScheduleWindowCopyToVram(work + 0x174);
        ScheduleWindowCopyToVram(*(void **)(work + 0x224));
        Sprite_SetPriority(*(void **)(work + 0x428), 0);
        thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x428), 2);
        work[0x7BE] = 0;
        return TRUE;
    }
    return FALSE;
}
