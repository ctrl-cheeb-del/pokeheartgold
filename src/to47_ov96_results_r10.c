#include "to47_ov96_results_r10_private.h"

struct R10Work {
    void *owner;
    u8 pad004[8];
    void *sprite;
    u8 pad010[0x3a0];
    u16 ranks[4];
    u8 participant;
};

typedef struct R10Entry {
    u8 pad000[3];
    u8 rank;
    u8 pad004;
    u8 kind : 3;
    u8 pad005 : 5;
} R10Entry;

typedef struct R10Data {
    R10Entry entries[4];
    u8 pad018[8];
    u32 unk020;
} R10Data;

typedef struct R10Heap {
    u8 pad000[0x180];
    void *rankUi;
} R10Heap;

void ov96_02217544(void *dst, void *a1, void *a2, void *a3, void *a4, void *a5) {
    volatile s32 control[3];
    s32 next;
    int j;
    int index;
    u8 *group;
    u16 *palette;
    u16 *gray;

    PTR_AT(dst, 0) = a3;
    PTR_AT(dst, 4) = a1;
    PTR_AT(dst, 8) = a2;
    PTR_AT(dst, 0xc) = ov96_022164EC(a1, a2, 0x80, 0x10, 3, 1);
    control[2] = 0;
    group = (u8 *)dst + 0x10;
    control[1] = control[2];
    control[0] = (u32)a5;
    do {
        index = (u8)control[1];
        PTR_AT(group, 0) = ov96_021EAA04(a4, index);
        palette = (u16 *)(group + 0x1c);
        gray = (u16 *)(group + 0x3c);
        for (j = 0; j < 3; index++, j++, palette += 0x20, gray += 0x20) {
            ov96_021E8BB4(ov96_021E8BB0(ov96_021EAA20(ov96_021EAA04(a4, (u8)index))), (void *)control[0], palette);
            MI_CpuCopy8(palette, gray, 0x20);
            TintPalette_GrayScale(gray, 0x10);
        }
        PTR_AT(group, 0x14) = ov96_022164EC(a1, a2, 0, 0, 7, 3);
        ManagedSprite_SetDrawFlag(PTR_AT(group, 0x14), FALSE);
        PTR_AT(group, 8) = ov96_022164EC(a1, a2, 0, 0, 1, 5);
        ManagedSprite_SetDrawFlag(PTR_AT(group, 8), FALSE);
        PTR_AT(group, 4) = ov96_022164EC(a1, a2, 0, 0, 11, 4);
        ManagedSprite_SetDrawFlag(PTR_AT(group, 4), FALSE);
        PTR_AT(group, 0xc) = ov96_022164EC(a1, a2, 0, 0, 21, 6);
        ManagedSprite_SetDrawFlag(PTR_AT(group, 0xc), FALSE);
        PTR_AT(group, 0x10) = ov96_022164EC(a1, a2, 0, 0, 8, 2);
        ManagedSprite_SetDrawFlag(PTR_AT(group, 0x10), FALSE);
        group += 0xe8;
        control[1] += 3;
        next = control[2] + 1;
        control[2] = next;
    } while (next < 4);
}

void ov96_0221768C(R10Work *work, R10Course *course) {
    u8 sorted[4][2];
    R10Data *data;
    R10Heap *heap;
    u8 participant;
    u32 anim;
    int i;

    data = (R10Data *)ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0xf0);
    heap = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_02216C38(work, data, course);
    ov96_021E6454(course, (data->unk020 << 13) >> 16);
    if (((data->unk020 << 13) >> 16) == 0x1c2) {
        PlaySE(0x6d7);
    }
    participant = data->entries[ov96_021E5F24(course)].kind;
    switch (participant) {
    case 0:
        anim = 2;
        break;
    case 3:
        anim = 3;
        break;
    case 2:
        anim = 4;
        break;
    case 4:
        anim = 5;
        break;
    case 1:
        anim = 6;
        break;
    default:
        GF_AssertFail();
        break;
    }
    ManagedSprite_SetAnimNoRestart(work->sprite, anim);
    if (participant != work->participant) {
        if (participant == 2) {
            PlaySE(0x89b);
        } else if (participant == 4) {
            PlaySE(0x89c);
        }
    }
    work->participant = participant;
    for (i = 0; i < 4; i++) {
        sorted[i][1] = (u8)i;
        sorted[i][0] = data->entries[i].rank;
    }
    MATH_QSort(sorted, 4, 2, ov96_02216C1C, NULL);
    for (i = 0; i < 4; i++) {
        if (data->entries[i].rank != work->ranks[i]) {
            ov96_0221966C(work->owner, (u8)i, data->entries[i].rank, sorted);
        }
        work->ranks[i] = data->entries[i].rank;
    }
    ov96_022196E4(heap->rankUi, ((data->unk020 << 13) >> 16) / 30);
}
