#include "ov80_2fd08_partial_internal.h"

void ov80_022309F8(void *work) {
    u8 *p = work;
    if (*(u16 *)(p + 0x4DC) != 0xFF) {
        void *mon = Party_GetMonByIndex(*(void **)(p + 0x4D8), *(u16 *)(p + 0x4DE));
        Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(*(void **)(p + 0x4D4), *(u16 *)(p + 0x4DC), mon);
        *(u16 *)(p + 0x4E8 + *(u16 *)(p + 0x4DC) * 2) = *(u16 *)(p + 0x254 + *(u16 *)(p + 0x4DE) * 2);
        ov80_02230AE4(work);
        GameStats_Inc(Save_GameStats_Get(*(void **)(p + 0x4F8)), 0x41);
    }
}

void ov80_02230A60(void *work) {
    u8 *p = work;
    u8 *cursor;
    int count;
    int i;
    void *mon;
    ov80_02236DD4(p[4]);
    count = ov80_02236DF8(p[4], 1);
    SaveArray_Party_Init(*(void **)(p + 0x4D8));
    mon = AllocMonZeroed(11);
    i = 0;
    if (count > 0) {
        cursor = p + 0x3F0;
        do {
            ov80_0222A140(cursor, mon, ov80_02237120(work));
            ov80_0222A3BC(*(void **)(p + 0x4F8), *(void **)(p + 0x4D8), mon);
            cursor += 0x38;
            i++;
        } while (i < count);
    }
    Heap_Free(mon);
    for (i = 0; i < count; i++) {
        Party_GetMonByIndex(*(void **)(p + 0x4D8), i);
    }
}

void ov80_02230AE4(void *work) {
    u8 *p = work;
    u16 value = *(u16 *)(p + 8);
    if (value < 9999) {
        *(u16 *)(p + 8) = value + 1;
    }
}

void ov80_02230AF8(void *work, u32 command, int value) {
    switch (command) {
    case 0:
        ov80_0222B108(work);
        break;
    case 1:
        ov80_0222B174(work);
        break;
    case 2:
        ov80_0222B1DC(work);
        break;
    case 3:
        ov80_0222B2C4(work);
        break;
    case 4:
        ov80_0222B3B0(work, (u8)value);
        break;
    case 5:
        ov80_0222B3FC(work, (u8)value);
        break;
    case 6:
        ov80_0222B448(work);
        break;
    }
}

int ov80_02230B4C(void *work) {
    u8 *p = work;
    u8 mode = p[4];
    u16 round = *(u16 *)(p + 0xE);
    int result;
    if (mode <= 1) {
        result = round >= 8 ? 9 : ov80_0223BDD4[round];
    } else {
        result = round >= 8 ? 21 : ov80_0223BDE0[round];
    }
    if (mode == 0) {
        u16 stat = *(u16 *)(p + 0xC);
        if (stat == 0x15 || stat == 0x31) {
            result = 20;
        }
    }
    return result;
}
