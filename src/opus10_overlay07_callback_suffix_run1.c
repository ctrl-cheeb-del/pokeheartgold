#include "opus10_overlay07_callback_suffix_private.h"

s16 ov07_02234B5C(u32 a0, u32 a1);

Ov07CallbackWork *ov07_02233DB8(Ov07Params *params) {
    Ov07CallbackWork *work = Heap_Alloc(params->heapId, sizeof(Ov07CallbackWork));
    MI_CpuFill8(work, 0, sizeof(Ov07CallbackWork));
    GF_ASSERT(work != NULL);
    work->params = *params;
    work->state = 0;
    work->unk10 = 0;
    work->unk0C = 0;
    work->unk14 = 0;
    work->unk18 = 0;
    work->unk00 = 0;
    work->unk04 = 0;
    work->spriteManager = SpriteManager_New(work->params.spriteSystem);
    work->delay = 0;
    work->tickSprite = ov07_022325BC(work->params.kind);
    work->unkC4 = 0;
    work->unk20 = 0x10;
    work->unk21 = 0;
    ov07_0221C69C();
    if (LCRandom() % 2) {
        work->unk22 = 1;
    } else {
        work->unk22 = -1;
    }
    ov07_022342E4(work);
    ov07_0223441C(work);
    ov07_02233F30(work);
    work->active = TRUE;
    work->unk28 = 0;
    work->task = SysTask_CreateOnMainQueue(ov07_02233D60, work, 1000);
    return work;
}

BOOL ov07_02233E88(Ov07CallbackWork *work) {
    GF_ASSERT(work != NULL);
    if (work->active) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov07_02233EA0(Ov07CallbackWork *work) {
    GF_ASSERT(work != NULL);
    if (work->unk28) {
        return TRUE;
    }
    return FALSE;
}

void ov07_02233EB8(Ov07CallbackWork *work, u32 a1) {
    work->unk14 = a1;
}

BOOL ov07_02233EBC(Ov07CallbackWork *work, u32 a1) {
    if (work->unk14 == a1) {
        return TRUE;
    }
    return FALSE;
}

void ov07_02233ECC(Ov07CallbackWork *work) {
    GF_ASSERT(work != NULL);
    SpriteSystem_FreeResourcesAndManager(work->params.spriteSystem, work->spriteManager);
    Sprite_DeleteAndFreeResources(work->sprite);
    SysTask_Destroy(work->task);
    Heap_Free(work);
}

void ov07_02233EFC(Ov07CallbackWork *work, u32 callbackId) {
    work->params.callbackId = callbackId;
    work->state = 0;
    work->unk0C = 0;
    work->unk10 = 0;
    work->active = TRUE;
    ManagedSprite_GetPositionXY(work->sprite, &work->spriteX, &work->spriteY);
}

u32 ov07_02233F20(Ov07CallbackWork *work) {
    GF_ASSERT(work != NULL);
    return work->params.callbackId;
}

void ov07_02233F30(Ov07CallbackWork *work) {
    ManagedSprite_GetPositionXY(work->sprite, &work->spriteX, &work->spriteY);
    switch (work->params.kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        ManagedSprite_GetPositionXY(work->sprite, &work->unkBC, &work->unkBE);
        work->unkC8 = 0;
        work->unkC0 = 0xC;
        return;
    case 6:
        ov07_02221F04(0, 0, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x30;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 7:
        ManagedSprite_GetPositionXY(work->sprite, &work->spriteX, &work->spriteY);
        ov07_02221F04(1, 4, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x30;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 8:
        ov07_02221F04(1, 2, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x30;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 9:
        ov07_02221F04(0, 1, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x30;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 10:
        ov07_02221F04(1, 3, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x30;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 11:
        ov07_02221F04(1, 5, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x30;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 12:
        ov07_02221F04(0, 1, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x10;
        work->unkBE = work->unkBE + 0x10;
        work->unkC0 = 0xC;
        return;
    case 13:
        ov07_02221F04(0, 1, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x20;
        work->unkBC = work->unkBC - 0x14;
        work->unkBE = work->unkBE + 0x26;
        work->unkC0 = 0x10;
        return;
    case 14:
        work->unkBC = 0x80;
        work->unkBE = 0x40;
        work->unkC8 = 0x20;
        work->unkBE = work->unkBE + 0x20;
        break;
    case 15:
        ov07_02221F04(0, 1, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x40;
        work->unkBE = work->unkBE + 8;
        work->unkC0 = 0x10;
        return;
    case 16:
        ov07_02221F04(1, 3, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x40;
        work->unkBE = work->unkBE + 8;
        work->unkC0 = 0x10;
        return;
    case 17:
        ov07_02221F04(1, 5, &work->unkBC, &work->unkBE);
        work->unkC8 = 0x40;
        work->unkBE = work->unkBE + 8;
        work->unkC0 = 0x10;
        return;
    }
    work->unkC0 = 0x14;
}

void ov07_022341A4(Ov07CallbackWork *work, s16 *x, s16 *y) {
    switch (work->params.kind) {
    case 0:
        ov07_02221F04(0, 0, x, y);
        *y = *y + 0x28;
        break;
    case 1:
        ov07_02221F04(0, 1, x, y);
        *y = *y + 0x26;
        break;
    case 2:
        ov07_02221F04(1, 2, x, y);
        *y = *y + 0x28;
        break;
    case 4:
        ov07_02221F04(1, 4, x, y);
        *y = *y + 0x28;
        break;
    case 3:
        ov07_02221F04(1, 3, x, y);
        *y = *y + 0x26;
        break;
    case 5:
        ov07_02221F04(1, 5, x, y);
        *y = *y + 0x26;
        break;
    case 6:
        *x = 0xA;
        *y = 0x64;
        break;
    case 7:
        *x = 0xA;
        *y = 0x64;
        break;
    case 8:
        *x = 0xA;
        *y = 0x64;
        break;
    case 9:
        ov07_02221F04(0, 0, x, y);
        break;
    case 10:
        ov07_02221F04(0, 0, x, y);
        break;
    case 11:
        ov07_02221F04(0, 0, x, y);
        break;
    case 12:
        ov07_02221F04(0, 0, x, y);
        break;
    case 13:
        ov07_02221F04(0, 0, x, y);
        break;
    case 14:
        *x = 0xE6;
        *y = 0x20;
        break;
    case 15:
    case 16:
    case 17:
        *x = -30;
        *y = 0xA0;
        break;
    }
}

void ov07_022342E4(Ov07CallbackWork *work) {
    SpriteResourceCountsListUnion counts;
    NARC *narc;
    int charRes;
    int plttRes;
    int cellRes;
    int animRes;
    int i;

    SpriteSystem_InitSprites(work->params.spriteSystem, work->spriteManager, 10);
    if (work->params.unk18 == 0) {
        G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(work->params.spriteSystem), 0, 0x11 << 16);
    }
    for (i = 0; i < 6; i++) {
        counts.asArray[i] = 10;
    }
    counts.numMcel = 0;
    counts.numManm = 0;
    SpriteSystem_InitManagerWithCapacities(work->params.spriteSystem, work->spriteManager, &counts);
    charRes = ov07_02232658((void *)work->params.unk10, 0);
    plttRes = ov07_02232658((void *)work->params.unk10, 1);
    cellRes = ov07_02232658((void *)work->params.unk10, 2);
    animRes = ov07_02232658((void *)work->params.unk10, 3);
    narc = NARC_New((NarcId)8, work->params.heapId);
    SpriteSystem_LoadCharResObjFromOpenNarc(work->params.spriteSystem, work->spriteManager, narc, charRes, TRUE, 1, work->params.unk0C + 0x1770);
    SpriteSystem_LoadPaletteBufferFromOpenNarc((PaletteData *)work->params.unk20, (PaletteBufferId)2, work->params.spriteSystem, work->spriteManager, narc, plttRes, FALSE, 1, 1, work->params.unk0C + 0x1770);
    SpriteSystem_LoadCellResObjFromOpenNarc(work->params.spriteSystem, work->spriteManager, narc, cellRes, TRUE, work->params.unk0C + 0x1770);
    SpriteSystem_LoadAnimResObjFromOpenNarc(work->params.spriteSystem, work->spriteManager, narc, animRes, TRUE, work->params.unk0C + 0x1770);
    NARC_Delete(narc);
}

void ov07_0223441C(Ov07CallbackWork *work) {
    ManagedSpriteTemplate template;
    int i;

    ov07_022341A4(work, &template.x, &template.y);
    template.z = 0;
    template.animation = 0;
    template.drawPriority = 0;
    template.pal = 0;
    template.vram = (NNS_G2D_VRAM_TYPE)1;
    template.bgPriority = work->params.unk14;
    template.vramTransfer = 0;
    for (i = 0; i < 6; i++) {
        template.resIdList[i] = work->params.unk0C + 0x1770;
    }
    work->sprite = SpriteSystem_NewSprite(work->params.spriteSystem, work->spriteManager, &template);
    ManagedSprite_SetDrawFlag(work->sprite, TRUE);
    ManagedSprite_SetAffineOverwriteMode(work->sprite, 2);
    ManagedSprite_SetAnimationFrame(work->sprite, 0);
    ManagedSprite_SetAnim(work->sprite, 0);
    ManagedSprite_TickFrame(work->sprite);
    ov07_0221C69C();
}

void ov07_0223449C(Ov07CallbackWork *work, int flag) {
    ManagedSprite_SetDrawFlag(work->sprite, flag);
}

void ov07_022344A8(Ov07CallbackWork *work, s16 x, s16 y) {
    ManagedSprite_SetPositionXY(work->sprite, x, y);
}

void ov07_022344B4(Ov07CallbackWork *work, u16 a1) {
    ManagedSprite_SetAffineZRotation(work->sprite, a1);
}

void ov07_022344C0(Ov07CallbackWork *work, u32 a1) {
    work->tickSprite = a1;
}

void ov07_022344C4(Ov07CallbackWork *work, u16 a1) {
    ManagedSprite_SetDrawPriority(work->sprite, a1);
}

void ov07_022344D0(Ov07CallbackWork *work, int a1) {
    ManagedSprite_SetPriority(work->sprite, a1);
}

void ov07_022344DC(Ov07CallbackWork *work, s32 a1) {
    work->delay = a1;
}

s32 ov07_022344E4(s16 x0, s16 y0, s16 x1, s16 y1) {
    s16 dx = x0 - x1;
    s16 dy = -(y0 - y1);
    return FX_Sqrt((dy * dy + dx * dx) * FX32_ONE) / FX32_ONE;
}

s32 ov07_02234510(const SEAL *seal) {
    s16 x = SealOnCapsuleGetX(seal);
    return ov07_022344E4(x, SealOnCapsuleGetY(seal), 190, 70);
}

u8 ov07_02234530(const SEAL *seal) {
    Ov07Table7 tbl = ov07_0223777C;
    int idx;

    if (!sub_0209109C((u8)SealOnCapsuleGetID(seal))) {
        idx = ov07_02234510(seal);
        if (idx >= 0x38) {
            idx = 3;
        } else {
            idx = (idx + 1) / 20;
            if (idx >= 3) {
                idx = 3;
            }
        }
        return tbl.vals[idx];
    }
    return tbl.vals[1];
}

Ov07EmitterManager *ov07_0223458C(enum HeapID heapId, s32 *a1) {
    int i;
    Ov07EmitterManager *mgr = Heap_Alloc(heapId, sizeof(Ov07EmitterManager));
    if (mgr == NULL) {
        GF_AssertFail();
        return NULL;
    }
    ov07_0221C69C();
    mgr->heapId = heapId;
    if (a1 != NULL) {
        mgr->unk04 = a1[0];
    }
    for (i = 0; i < 16; i++) {
        mgr->emitters[i] = NULL;
    }
    return mgr;
}

Ov07Emitter *ov07_022345C8(Ov07EmitterManager *mgr, Ov07EmitterInit *init) {
    Ov07Emitter *ret = NULL;
    int i;

    for (i = 0; i < 16; i++) {
        if (mgr->emitters[i] == NULL) {
            mgr->emitters[i] = ov07_02234658(mgr->heapId, init);
            mgr->emitters[i]->task = NULL;
            ret = mgr->emitters[i];
            ret->index = i;
            break;
        }
    }
    GF_ASSERT(ret != NULL);
    return ret;
}

void ov07_02234604(Ov07EmitterManager *mgr) {
    int i;
    for (i = 0; i < 16; i++) {
        if (mgr->emitters[i] != NULL) {
            Heap_Free(mgr->emitters[i]);
        }
    }
    Heap_Free(mgr);
}

void ov07_02234628(Ov07EmitterManager *mgr) {
    int i;
    for (i = 0; i < 16; i++) {
        if (mgr->emitters[i] != NULL) {
            ov07_0221FF2C(mgr->emitters[i]->emitter);
            if (mgr->emitters[i]->unk20 != 0 && mgr->emitters[i]->task != NULL) {
                SysTask_Destroy(mgr->emitters[i]->task);
            }
        }
    }
}

Ov07Emitter *ov07_02234658(enum HeapID heapId, Ov07EmitterInit *init) {
    Ov07Emitter *ptr = Heap_Alloc(heapId, sizeof(Ov07Emitter));
    if (ptr == NULL) {
        GF_AssertFail();
        return NULL;
    }
    ptr->heapId = heapId;
    ptr->init = *init;
    ptr->unk1C = ov07_02234718(ptr->init.unk00);
    ptr->emitter = ov07_0221FE88(ptr->heapId, ptr->init.unk00, 1);
    return ptr;
}

void ov07_02234694(Ov07Emitter *emitter) {
    emitter->unk20 = 1;
    ov07_022346E4(emitter, (void (*)(SPLEmitter *))ov07_02234710);
    emitter->task = SysTask_CreateOnMainQueue(ov07_022346C0, emitter, 1000);
}

u32 ov07_022346BC(Ov07Emitter *emitter) {
    return emitter->unk20;
}

void ov07_022346C0(SysTask *task, void *data) {
    Ov07Emitter *emitter = data;
    if (!sub_020154B0(emitter->emitter)) {
        emitter->unk20 = 0;
        ov07_0221FF2C(emitter->emitter);
        SysTask_Destroy(task);
    }
}

void ov07_022346E4(Ov07Emitter *emitter, void (*cb)(SPLEmitter *)) {
    int i;
    for (i = 0; i < emitter->unk1C; i++) {
        sub_02015494(emitter->emitter, i, cb, emitter);
    }
    sub_02015528(emitter->emitter, emitter->init.unk04);
}

void *ov07_02234710(void) {
    return sub_02015504();
}

s32 ov07_02234718(u32 id) {
    Ov07Table22 tbl = ov07_02237784;
    u32 idx = id - 5;
    if (idx >= 22) {
        GF_AssertFail();
        return 0;
    }
    return tbl.vals[idx];
}

void ov07_0223474C(Ov07PicWork *w, u32 a1) {
    ov07_0223476C(w, w->unk00, 0, a1);
}

void ov07_0223475C(Ov07PicWork *w, u32 a1) {
    ov07_0223476C(w, w->unk04, 1, a1);
}
