#include "ov80_2237a70_partial_internal.h"

int ov80_02237D5C(int mode) {
    switch (mode) {
    case 0:
        return 0x81;
    case 1:
        return 0x83;
    case 2:
        return 0x8F;
    case 3:
        return 0x8F;
    default:
        return 0x81;
    }
}

int ov80_02237D88(void *unused) {
    return 50;
}

BOOL ov80_02237D8C(int mode) {
    switch (mode) {
    case 2:
    case 3:
        return TRUE;
    default:
        return FALSE;
    }
}

void ov80_02237D9C(void *party) {
    int count = Party_GetCount(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(party, i);
        int value;
        if (GetMonData(mon, 0xAC, NULL) != 0) {
            if (GetMonData(mon, 0xA3, NULL) == 0) {
                value = 1;
                SetMonData(mon, 0xA3, &value);
            }
            value = 0;
            SetMonData(mon, 0xA0, &value);
        }
    }
}

void ov80_02237DF4(void *context, void *mon) {
    void *profile = Save_PlayerData_GetProfile(*(void **)((u8 *)context + 4));
    sub_0207217C(mon, profile, 4, 0, 0, 11);
}

void ov80_02237E18(void *context, void *party, void *mon) {
    ov80_02237DF4(context, mon);
    Party_AddMon(party, mon);
}

void ov80_02237E30(void *context) {
    u8 *work = context;
    int count;
    void *mon;
    int i;
    u8 *record;

    SaveArray_Party_Init(*(void **)(work + 0x2C));
    count = ov80_02237B58(work[0x10], 1);
    mon = AllocMonZeroed(11);
    i = 0;
    if (count > 0) {
        record = work + 0x288;
        do {
            ov80_0222A140(record, mon, ov80_02237D88(context));
            ov80_02237E18(context, *(void **)(work + 0x2C), mon);
            i++;
            record += 0x38;
        } while (i < count);
    }
    Heap_Free(mon);
}

int ov80_02237E88(void *context) {
    u8 *work = context;
    int value;
    int result;

    if (work[0x10] == 0 && (u16)(*(u16 *)(work + 0x30 + work[0x11] * 2) + 0xFEC7) <= 1) {
        return 7;
    }
    value = ov80_02237ED8(context);
    value++;
    result = 7;
    switch (value) {
    case 1:
    case 2:
        result = 0;
        break;
    case 3:
    case 4:
        result = 1;
        break;
    }
    return result;
}

u16 ov80_02237ED8(void *context) {
    u8 *work = context;
    u16 value = *(u16 *)(work + 0x16);
    if (ov80_02237D8C(work[0x10]) == TRUE) {
        u16 other = *(u16 *)(work + 0xA12);
        if (other > *(u16 *)(work + 0x16)) {
            value = other;
        }
    }
    return value;
}

void ov80_02237EFC(void *bgConfig, void *context, int bgId) {
    u16 buffer[30];
    ov80_02237F3C(buffer, ov80_02237ED8(context));
    LoadRectToBgTilemapRect(bgConfig, bgId, buffer, 11, 6, 10, 3);
    ScheduleBgTilemapBufferTransfer(bgConfig, bgId);
}
