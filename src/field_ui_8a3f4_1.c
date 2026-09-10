#include "field_ui_8a3f4_internal.h"

int sub_0208A3F4(u8 *work, int direction) {
    s8 index = (*(u8 **)(work + 0x22C))[0x14];
    int size;
    u8 *base;
    do {
        index = (s8)(index + direction);
        if (index < 0 || index >= (*(u8 **)(work + 0x22C))[0x13]) {
            return -1;
        }
        size = sub_02070D90();
        base = **(u8 ***)(work + 0x22C);
        if (GetMonData(base + index * size, 5, 0) != 0) {
            if (GetMonData(base + index * size, 0x4C, 0) == 0 || sub_0208A3CC(work) == 1) {
                return index;
            }
        }
    } while (1);
}

int sub_0208A45C(u8 *work, int direction) {
    s8 index = (*(u8 **)(work + 0x22C))[0x14];
    void *mon;
    do {
        index = (s8)(index + direction);
        if (index < 0 || index >= (*(u8 **)(work + 0x22C))[0x13]) {
            return -1;
        }
        mon = Party_GetMonByIndex(**(void ***)(work + 0x22C), index);
        if (GetMonData(mon, 5, 0) != 0) {
            if (GetMonData(mon, 0x4C, 0) == 0 || sub_0208A3CC(work) == 1) {
                return index;
            }
        }
    } while (1);
}

int sub_0208A4B8(u8 *work, int direction) {
    s8 index = (*(u8 **)(work + 0x22C))[0x14];
    int size;
    u8 *base;
    do {
        index = (s8)(index + direction);
        if (index < 0 || index >= (*(u8 **)(work + 0x22C))[0x13]) {
            return -1;
        }
        size = sub_02070D94();
        base = **(u8 ***)(work + 0x22C);
        if (GetBoxMonData(base + index * size, 5, 0) != 0) {
            if (GetBoxMonData(base + index * size, 0x4C, 0) == 0 || sub_0208A3CC(work) == 1) {
                return index;
            }
        }
    } while (1);
}

void *sub_0208A520(u8 *work) {
    u8 *data = *(u8 **)(work + 0x22C);
    switch (data[0x11]) {
    case 0:
        return *(u8 **)data + data[0x14] * sub_02070D90();
    case 1:
        return Party_GetMonByIndex(*(void **)data, data[0x14]);
    case 2:
        return *(u8 **)data + data[0x14] * sub_02070D94();
    default:
        return NULL;
    }
}

BOOL sub_0208A564(u8 *work) {
    switch (work[0x7BE]) {
    case 0:
        Sprite_SetDrawFlag(*(void **)(work + 0x428), 0);
        Sprite_SetAnimCtrlSeq(*(void **)(work + 0x428), 0);
        ScheduleSetBgPosText(*(void **)work, 5, 0, 0);
        ScheduleSetBgPosText(*(void **)work, 5, 3, 0);
        ClearWindowTilemapAndScheduleTransfer(work + 0x44);
        work[0x7BE] = 1;
        break;
    case 1:
        if (Bg_GetXpos(*(void **)work, 5) >= 0x80) {
            ScheduleSetBgPosText(*(void **)work, 5, 0, 0x80);
            work[0x7BE] = 2;
        } else {
            ScheduleSetBgPosText(*(void **)work, 5, 1, 0x40);
        }
        break;
    case 2:
        sub_0208DB1C(work);
        sub_0208A79C(work);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x430), 1);
        sub_0208C068(work);
        if (work[0x240] != work[0x241]) {
            thunk_Sprite_SetDrawFlag(*(void **)(work + 0x434), 1);
        }
        Sprite_SetDrawFlag(*(void **)(work + 0x428), 1);
        work[0x7BE] = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL sub_0208A63C(u8 *work) {
    switch (work[0x7BE]) {
    case 0:
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x430), 0);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x434), 0);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x44C), 0);
        thunk_Sprite_SetDrawFlag(*(void **)(work + 0x450), 0);
        Sprite_SetDrawFlag(*(void **)(work + 0x428), 0);
        sub_0208DB58(work);
        sub_0208DAD4(work);
        work[0x7BE] = 1;
        break;
    case 1:
        if (Bg_GetXpos(*(void **)work, 5) <= 0x80) {
            ScheduleSetBgPosText(*(void **)work, 5, 0, 0);
            work[0x7BE] = 2;
        } else {
            ScheduleSetBgPosText(*(void **)work, 5, 2, 0x40);
        }
        break;
    case 2:
        ScheduleWindowCopyToVram(work + 0x204);
        ScheduleWindowCopyToVram(work + 0x64);
        ScheduleWindowCopyToVram(work + 0x1F4);
        ScheduleWindowCopyToVram(work + 0x44);
        Sprite_SetDrawFlag(*(void **)(work + 0x428), 1);
        sub_0208B400(work);
        work[0x7BE] = 0;
        return TRUE;
    }
    return FALSE;
}
