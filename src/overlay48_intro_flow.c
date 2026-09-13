#include "overlay48_intro_flow_private.h"

BOOL ov48_02258800(OverlayManager *man, u32 *state) {
    void *args;
    void *work;

#pragma unused(state)
    args = OverlayManager_GetArgs(man);
    Heap_Create((enum HeapID)3, (enum HeapID)0x70, 5 << 16);
    work = OverlayManager_CreateAndGetData(man, 0xC724, (enum HeapID)0x70);
    memset(work, 0, 0xC724);
    U32AT(work, 0xC) = (u32)Save_WiFiHistory_Get(PTRAT(args, 4));
    U32AT(work, 0x10) = (u32)Save_PlayerData_GetOptionsAddr(PTRAT(args, 4));
    U32AT(work, 0x14) = WifiHistory_GetPlayerCountry(PTRAT(work, 0xC));
    U32AT(work, 0x18) = WiFiHistory_GetPlayerRegion(PTRAT(work, 0xC));
    U32AT(work, 0x1C) = U32AT(args, 8);
    ov48_022593F4(work, args);
    ov48_02259464(ADD(work, 0x20), PTRAT(work, 0x10), 0x70);
    ov48_02259824(ADD(work, 0x178), ADD(work, 0x20), 0x70);
    ov48_0225B068(ADD(work, 0x168), (enum HeapID)0x70);
    ov48_022598EC(ADD(work, 0x224), U32AT(args, 0), ADD(work, 0x20), *(Ov48Pair *)ADD(work, 4), 0x70);
    ov48_02259BC0(ADD(work, 0xC3CC), *(Ov48Pair *)ADD(work, 4), 0x70);
    ov48_02259D00(ADD(work, 0xC3E0), ADD(work, 0x20), ADD(work, 0x168), 0x70);
    ov48_02259EAC(ADD(work, 0xC700), ADD(work, 0x20), ADD(work, 0x168), PTRAT(args, 4), 0x70);
    ov48_0225A00C(ADD(work, 0xC40C), ADD(work, 0x20), ADD(work, 0x168), 0x70);
    ov48_02259130(work, args);
    Main_SetVBlankIntrCB(ov48_02259090, work);
    HBlankInterruptDisable();
    return TRUE;
}

BOOL ov48_02258920(OverlayManager *man, u32 *state) {
    void *work;
    void *args;
    u32 done;

    work = OverlayManager_GetData(man);
    args = OverlayManager_GetArgs(man);
    switch (*state) {
    case 0:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)1, (enum FadeType)1, 0, 6, 1, (enum HeapID)0x70);
        ov45_0222A520(PTRAT(args, 0xC), 1);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == TRUE) {
            (*state)++;
        }
        break;
    case 2:
        done = ov48_02258F64(work);
        ov48_02259030(work);
        if (ov45_0222A330(PTRAT(args, 0xC)) == 1) {
            ov45_0222A4A8(PTRAT(args, 0xC));
            done = 1;
        }
        if (ov45_0222D844() == 1) {
            done = 1;
        }
        if (done == 1) {
            *state = 5;
        }
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)0, (enum FadeType)0, 0, 6, 1, (enum HeapID)0x70);
        (*state)++;
        break;
    case 6:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    ov48_02259050(work);
    return FALSE;
}

BOOL ov48_022589FC(OverlayManager *man, u32 *state) {
    void *work;

#pragma unused(state)
    work = OverlayManager_GetData(man);
    OverlayManager_GetArgs(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    ov48_0225A108(ADD(work, 0xC40C), ADD(work, 0x20));
    ov48_02259F14(ADD(work, 0xC700));
    ov48_02259D94(ADD(work, 0xC3E0));
    ov48_02259C38(ADD(work, 0xC3CC));
    ov48_02259868(ADD(work, 0x178));
    ov48_02259984(ADD(work, 0x224));
    ov48_0225B0A4(ADD(work, 0x168));
    ov48_022594A8(ADD(work, 0x20));
    OverlayManager_FreeData(man);
    Heap_Destroy((enum HeapID)0x70);
    return TRUE;
}

void ov48_02258A80(void *p, void *q, u32 heapId) {
    u32 size1;
    u32 size2;
    NARC *narc;
    void *buf1;
    void *buf2;
    s32 nCountry;
    s32 nCity;
    s32 i;
    s32 j;
    const Ov48Rec6 *rec6;
    const Ov48Rec4 *rec4;
    Ov48EntryList *list;

    list = p;
    narc = NARC_New((NarcId)0x62, (enum HeapID)heapId);
    list->count = 0;
    buf1 = GfGfxLoader_LoadFromOpenNarc_GetSizeOut(narc, 0x12, FALSE, (enum HeapID)heapId, FALSE, &size1);
    nCity = size1 / 6;
    i = 1;
    rec6 = ADD(buf1, 6);
    for (; i < nCity; i++) {
        if (rec6->kind != 2) {
            ov48_02258B7C(list, list->count, rec6->x, rec6->y, (u16)i, 0, q);
            list->count++;
        }
        rec6++;
    }
    Heap_Free(buf1);
    i = 1;
    nCountry = LocationGmmDatCountGet();
    for (; i < nCountry; i++) {
        buf2 = GfGfxLoader_LoadFromOpenNarc_GetSizeOut(narc, LocationGmmDatGetEarthPlaceDatId(i), FALSE, (enum HeapID)heapId, FALSE, &size2);
        nCity = size2 / 4;
        j = 1;
        rec4 = ADD(buf2, 4);
        for (; j < nCity; j++) {
            ov48_02258B7C(list, list->count, rec4->x, rec4->y, (u16)LocationGmmDatGetCountryMsgNo(i), (u16)j, q);
            list->count++;
            rec4++;
        }
        Heap_Free(buf2);
    }
    NARC_Delete(narc);
}

void ov48_02258B7C(void *p, u32 idx, s32 x, s32 y, u16 e, u16 f, void *q) {
    Ov48EntryList *list;
    MtxFx33 mtx;
    VecFx32 rot;

    list = p;
    mtx = ov48_0225B1EC;
    list->entries[idx].x = (s16)x;
    list->entries[idx].y = (s16)y;
    rot.x = x;
    rot.y = y;
    rot.z = 0;
    ov48_02258C6C(&mtx, &rot);
    list->entries[idx].mtx = mtx;
    if (q != NULL) {
        list->entries[idx].a = (s16)ov48_02259A68(q, e, f);
    }
    list->entries[idx].b = (s16)e;
    list->entries[idx].c = (s16)f;
}

void ov48_02258BF4(MtxFx33 *m, VecFx32 *rot) {
    MtxFx33 tmp;

    MTX_RotY33_(m, FX_SinIdx((u16)rot->y), FX_CosIdx((u16)rot->y));
    MTX_RotX33_(&tmp, FX_SinIdx((u16)rot->x), FX_CosIdx((u16)rot->x));
    MTX_Concat33(m, &tmp, m);
    MTX_RotZ33_(&tmp, FX_SinIdx((u16)rot->z), FX_CosIdx((u16)rot->z));
    MTX_Concat33(m, &tmp, m);
}

void ov48_02258C6C(MtxFx33 *m, VecFx32 *rot) {
    MtxFx33 tmp;

    MTX_RotY33_(m, FX_SinIdx((u16)rot->x), FX_CosIdx((u16)rot->x));
    MTX_RotX33_(&tmp, FX_SinIdx((u16)(-rot->y)), FX_CosIdx((u16)(-rot->y)));
    MTX_Concat33(m, &tmp, m);
    MTX_RotZ33_(&tmp, FX_CosIdx((u16)rot->z), FX_SinIdx((u16)rot->z));
    MTX_Concat33(m, &tmp, m);
}

void ov48_02258CE4(s32 a, s32 b, u32 *o1, u32 *o2, u32 *o3, u32 *o4) {
    u32 dir1;
    u32 dir2;
    s32 d1;
    s32 d2;

    dir1 = 0;
    dir2 = 0;
    d1 = 0;
    d2 = 0;
    if (gSystem.touchX != 0xFFFF) {
        d1 = gSystem.touchX - a;
        if (d1 < 0) {
            d1 = d1 ^ -1;
            dir1 = 0x10;
        } else if (d1 > 0) {
            dir1 = 0x20;
        }
    }
    *o1 = dir1;
    *o2 = d1 & 0x3F;
    if (gSystem.touchY != 0xFFFF) {
        d2 = gSystem.touchY - b;
        if (d2 < 0) {
            d2 = d2 ^ -1;
            dir2 = 0x80;
        } else if (d2 > 0) {
            dir2 = 0x40;
        }
    }
    *o3 = dir2;
    *o4 = d2 & 0x3F;
}
