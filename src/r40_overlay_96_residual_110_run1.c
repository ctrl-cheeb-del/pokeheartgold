#include "r40_overlay_96_residual_110_private.h"

void ov96_0221490C(void *work, s32 value) {
    u8 digit;

    if (value <= 900) {
        Sprite_SetDrawFlag(PTR(work, 8), FALSE);
        Sprite_SetDrawFlag(PTR(work, 0xc), FALSE);
        ov96_021EB52C(PTR(work, 0x4c), TRUE, FALSE);
        if (U32_AT(work, 0x48) == 0) {
            ov96_02214854(work);
            U32_AT(work, 0x48) = 1;
        }
    } else {
        digit = (u8)(value / 30);
        Sprite_SetAnimCtrlSeq(PTR(work, 8), (u8)(digit / 10) + 1);
        Sprite_SetAnimCtrlSeq(PTR(work, 0xc), (u8)(digit % 10) + 1);
    }
}

void ov96_0221497C(void *work, s32 value) {
    u8 offsets[2];
    u8 tiles[2];
    u8 digit;
    u8 i;

    digit = (u8)(value / 10);
    offsets[0] = (digit % 5) * 4;
    tiles[0] = (digit / 5) * 8;
    digit = (u8)(value % 10);
    offsets[1] = (digit % 5) * 4;
    tiles[1] = (digit / 5) * 8;

    for (i = 0; i < 2; i++) {
        CopyRectToBgTilemapRect(PTR(work, 0x10), 6, (u8)(i * 4 + 6), 10, 4, 8, (u8 *)PTR(work, 0x3c) + 0xc, offsets[i], tiles[i], 20, 16);
    }
    ScheduleBgTilemapBufferTransfer(PTR(work, 0x10), 6);
}

void *ov96_02214A24(u32 heapId, u8 count) {
    u8 *work = Heap_Alloc(heapId, 0xa0);

    MI_CpuFill8(work, 0, 0xa0);
    U8_AT(work, 0x98) = count;
    U8_AT(work, 0x9e) = 4 - count;
    U8_AT(work, 0x9d) = U8_AT(work, 0x9e);
    U8_AT(work, 0x9b) = 3;
    U8_AT(work, 0x9a) = U8_AT(work, 0x9b);
    return work;
}

void ov96_02214A6C(Ov96R110Group *groups, s32 index, void *value) {
    groups[(u8)(index / 3)].entries[(u8)(index % 3)] = value;
}

void ov96_02214A9C(Ov96R110Group *groups) {
    u8 i;

    for (i = 0; i < 4; i++) {
        ov96_02214ABC(&groups[i]);
    }
}

void ov96_02214ABC(Ov96R110Group *group) {
    u8 second[3];
    u8 first[3];
    u8 selected;
    u8 i;
    u8 a;
    u8 b;

    for (i = 0; i < 3; i++) {
        second[i] = U8_AT(group->entries[i], 0x73) + U8_AT(group->entries[i], 0x70);
        first[i] = U8_AT(group->entries[i], 0x73) + U8_AT(group->entries[i], 0x75);
    }

    selected = 0;
    for (i = 1; i < 3; i++) {
        if (second[i - 1] < second[i]) {
            selected = i;
        }
    }

    if (selected == 0) {
        if (first[1] >= first[2]) {
            a = 1;
            b = 2;
        } else {
            a = 2;
            b = 1;
        }
    } else if (selected == 1) {
        if (first[0] >= first[2]) {
            a = 0;
            b = 2;
        } else {
            a = 2;
            b = 0;
        }
    } else {
        if (first[0] >= first[1]) {
            a = 0;
            b = 1;
        } else {
            a = 1;
            b = 0;
        }
    }

    group->order0 = group->entries[selected];
    group->order1 = group->entries[a];
    group->order2 = group->entries[b];
}
