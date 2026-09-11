#include "overlay96_pokeathlon_course_ui_private.h"

void ov96_02203754(Ov96CourseUiWork *w) {
    u8 flags[12];
    VecFx32 diff;
    int i;
    int j;

    for (i = 0; i < 12; i++) {
        flags[i] = 0;
    }
    for (i = 0; i < 12; i++) {
        switch (w->slots[i].unk0C) {
        case 1:
        case 2:
            for (j = 0; j < 12; j++) {
                if (i == j) {
                    continue;
                }
                switch (w->slots[j].unk0C) {
                case 1:
                case 2:
                    VEC_Subtract(&w->slots[i].pos, &w->slots[j].pos, &diff);
                    if (VEC_Mag(&diff) < (1 << 14)) {
                        flags[i] = 1;
                        flags[j] = 1;
                    }
                    break;
                }
            }
            break;
        }
    }
    for (i = 0; i < 12; i++) {
        if (flags[i]) {
            w->slots[i].unk0C = 3;
            w->slots[i].unk46 = 0;
            w->slots[i].unk44 = 0;
        }
    }
}

void ov96_0220382C(Ov96CourseUiWork *w, PokeathlonCourseData *data) {
    int i;
    int idx;
    Window *window;
    String *name;
    u8 base;

    base = (u8)ov96_021E5F24(data);
    i = 0;
    idx = base + 1;
    window = w->windows;
    for (; i < 3; i++) {
        name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(data, (u8)(idx % 4)), w->heapId);
        AddTextPrinterParameterizedWithColor(window, 0, name, 0, 0, 0xFF, 0x000F0E00, NULL);
        String_Delete(name);
        CopyWindowToVram(window);
        idx++;
        window++;
    }
}

void ov96_022038A0(Ov96CourseUiWork *w, u32 v) {
    u8 x = (u8)v;

    Sprite_SetAnimCtrlSeq(w->unk050, (u8)(x / 10) + 1);
    Sprite_SetAnimCtrlSeq(w->unk054, (u8)(x % 10) + 1);
}

void ov96_022038D4(PokeathlonCourseData *course) {
    u16 *table;
    void *heapPtr;
    u16 v;

    table = (u16 *)ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course) + 0xF0);
    heapPtr = PokeathlonCourse_GetHeapAllocPtr4(course);
    v = (u16)(table[(u8)ov96_021E5F24(course)] & 0x3FF);
    if (v > 999) {
        v = 999;
    }
    ov96_021E8318(course, v);
    ov96_0220337C(heapPtr, v);
}

s32 ov96_02203924(const void *aa, const void *bb) {
    const Ov96SortEntry *a = aa;
    const Ov96SortEntry *b = bb;
    u8 row = (u8)a->group;
    s32 res;

    if (a->score > b->score) {
        res = -1;
    } else if (a->score < b->score) {
        res = 1;
    } else if (ov96_0221C95C[row][a->index] < ov96_0221C95C[row][b->index]) {
        res = -1;
    } else if (ov96_0221C95C[row][a->index] > ov96_0221C95C[row][b->index]) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}

void ov96_02203970(Ov96CourseUiWork *w, u16 group) {
    Ov96SortEntry entries[12];
    u8 i;
    u8 k;
    Ov96AnimRec *rec;

    for (i = 0; i < 12; i++) {
        rec = ov96_021EB594(w->slots[i].unk04);
        entries[i].index = w->slots[i].unk41;
        entries[i].score = rec->unk04;
        entries[i].group = group;
    }
    MATH_QSort(entries, 12, sizeof(Ov96SortEntry), ov96_02203924, w->unk598);
    for (i = 0; i < 12; i++) {
        k = (u8)entries[i].index;
        ov96_021EB630(w->slots[k].unk00, i + 0x14);
        ov96_021EB630(w->slots[k].unk08, i + 5);
    }
}

Ov96CourseUiGfx *ov96_02203A00(enum HeapID heapId, BgConfig *bgConfig, void *unk04) {
    Ov96CourseUiGfx *gfx;

    gfx = Heap_Alloc(heapId, sizeof(Ov96CourseUiGfx));
    MI_CpuFill8(gfx, 0, sizeof(Ov96CourseUiGfx));
    gfx->heapId = heapId;
    gfx->bgConfig = bgConfig;
    gfx->unk04 = unk04;
    ov96_02203FBC(gfx);
    ov96_02203FFC(gfx);
    return gfx;
}

void ov96_02203A30(Ov96CourseUiGfx *gfx) {
    int i;

    for (i = 0; i < 3; i++) {
        Heap_Free(gfx->subs[i].unk00);
        Heap_Free(gfx->subs[i].unk04);
    }
    Heap_Free(gfx->scrnRaw);
    RemoveWindow(&gfx->window);
    Heap_Free(gfx);
}

void ov96_02203A64(Ov96CourseUiGfx *gfx, u32 index) {
    GfGfxLoader_LoadCharData(NARC_a_2_1_7, 4, gfx->bgConfig, GF_BG_LYR_SUB_3, 0, 0x2000, FALSE, gfx->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_1_7, 5, gfx->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, gfx->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_1_7, 6, gfx->bgConfig, GF_BG_LYR_SUB_3, 0, 0, FALSE, gfx->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_1_7, 7, gfx->bgConfig, GF_BG_LYR_SUB_2, 0, 0, FALSE, gfx->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_1_7, 8, gfx->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, gfx->heapId);
    gfx->scrnRaw = GfGfxLoader_GetScrnData(NARC_a_2_1_7, 9, FALSE, &gfx->scrn, gfx->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_1_7, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x80, gfx->heapId);
    CopyRectToBgTilemapRect(gfx->bgConfig, GF_BG_LYR_SUB_1, 0, 0x12, 4, 4, gfx->scrn->rawData, index * 4, 0x10, 0x14, 0x14);
    ScheduleBgTilemapBufferTransfer(gfx->bgConfig, GF_BG_LYR_SUB_1);
}

void ov96_02203B44(Ov96CourseUiGfx *gfx, Ov96R31Work *sprites) {
#pragma unused(gfx)
    ov96_021EB2BC(sprites, NARC_a_2_1_7, 0xD, 0x65, 2);
    ov96_021EB2F4(sprites, NARC_a_2_1_7, 0xA, 0x65, 2, 4);
    ov96_021EB334(sprites, NARC_a_2_1_7, 0xC, 0x65);
    ov96_021EB36C(sprites, NARC_a_2_1_7, 0xB, 0x65);
}

void ov96_02203B8C(void *a, Ov96R31Work *sprites, void *b) {
    int i;

    for (i = 0; i < 3; i++) {
        ov96_021EB408(sprites, 3, 2, 0x65, 5);
    }
    ov96_02203E30(sprites, a, b);
}
