#include "touch_sprite_motion_internal.h"

void sub_0208763C(UnkStruct02087284 *p, int a1) {
    SpriteSystem *ss = p->spriteSys;
    NARC *narc;
    SpriteManager *sm = p->spriteMan;
    PaletteData *pd = p->plttData;
    narc = p->narc;

    SpriteManager_UnloadPlttObjById(sm, 0x56CF);
    SpriteManager_UnloadPlttObjById(sm, 0x56D0);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pd, PLTTBUF_MAIN_OBJ, ss, sm, narc, _02102814[a1], FALSE, 1, 1, 0x56CF);
    SpriteSystem_LoadPaletteBufferFromOpenNarc(pd, PLTTBUF_SUB_OBJ, ss, sm, narc, _02102814[a1], FALSE, 1, 2, 0x56D0);
}

void sub_020876B0(UnkStruct02087284 *p, int a1) {
    int resBase = p->resBase;
    NARC *narc;
    SpriteSystem *ss = p->spriteSys;
    int resId = resBase + 0x56CE;
    SpriteManager *sm = p->spriteMan;
    PaletteData *pd = p->plttData;
    narc = p->narc;

    if (resBase == 1) {
        if (p->unk_1C == 0) {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(pd, PLTTBUF_MAIN_OBJ, ss, sm, narc, _02102814[a1], FALSE, 1, 1, resId);
        } else {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(pd, PLTTBUF_MAIN_OBJ, ss, sm, narc, 0x60, FALSE, 1, 1, resId);
        }
        SpriteSystem_LoadCharResObjFromOpenNarc(ss, sm, narc, 0x5F, FALSE, 1, resId);
    } else {
        if (p->unk_1C == 0) {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(pd, PLTTBUF_SUB_OBJ, ss, sm, narc, _02102814[a1], FALSE, 1, 2, resId);
        } else {
            SpriteSystem_LoadPaletteBufferFromOpenNarc(pd, PLTTBUF_SUB_OBJ, ss, sm, narc, 0x60, FALSE, 1, 2, resId);
        }
        SpriteSystem_LoadCharResObjFromOpenNarc(ss, sm, narc, 0x5F, FALSE, 2, resId);
    }
    SpriteSystem_LoadCellResObjFromOpenNarc(ss, sm, narc, 0x5D, FALSE, resId);
    SpriteSystem_LoadAnimResObjFromOpenNarc(ss, sm, narc, 0x5E, FALSE, resId);
}

void sub_020877B4(UnkStruct02087284 *p) {
    ManagedSpriteTemplate tmpl;
    SpriteSystem *ss = p->spriteSys;
    SpriteManager *sm = p->spriteMan;
    int i = 0;

    tmpl.x = 0x80;
    tmpl.y = 0x60;
    tmpl.z = 0;
    tmpl.animation = 0;
    tmpl.drawPriority = 0;
    tmpl.vram = (NNS_G2D_VRAM_TYPE)p->resBase;
    tmpl.bgPriority = 0;
    tmpl.vramTransfer = 0;
    tmpl.pal = 0;
    tmpl.resIdList[0] = p->resBase + 0x56CE;
    tmpl.resIdList[1] = p->resBase + 0x56CE;
    tmpl.resIdList[2] = p->resBase + 0x56CE;
    tmpl.resIdList[3] = p->resBase + 0x56CE;
    tmpl.resIdList[4] = -1;
    tmpl.resIdList[5] = -1;

    for (i = 0; i < p->count; i++) {
        p->sprites[i].sprite = SpriteSystem_NewSprite(ss, sm, &tmpl);
        ManagedSprite_TickFrame(p->sprites[i].sprite);
        ManagedSprite_SetPositionXY(p->sprites[i].sprite, 0x80, 0x60);
    }
}

void sub_02087830(UnkStruct02087284 *p) {
    int i;
    for (i = 0; i < p->count; i++) {
        SpriteManager_UnloadCharObjById(p->spriteMan, p->resBase + 0x56CE);
        SpriteManager_UnloadCellObjById(p->spriteMan, p->resBase + 0x56CE);
        SpriteManager_UnloadAnimObjById(p->spriteMan, p->resBase + 0x56CE);
        Sprite_DeleteAndFreeResources(p->sprites[i].sprite);
    }
}

BOOL sub_02087878(UnkStruct02087284 *p, int a1) {
    p->narc = NARC_New((NarcId)0xBF, p->heapId);
    sub_020876B0(p, a1);
    sub_020877B4(p);
    p->task = SysTask_CreateOnVBlankQueue(sub_020873D4, p, 0x1000);
    return TRUE;
}

BOOL sub_020878B0(UnkStruct02087284 *p, int a1) {
    p->unk_F0 = a1;
    return TRUE;
}

BOOL sub_020878B8(UnkStruct02087284 *p, int x, int y) {
    int i;
    p->sprites[0].x = x;
    p->sprites[0].y = y;
    p->unk_E8 = 0xFF;
    p->unk_EC = 0;
    for (i = 0; i < p->count; i++) {
        p->sprites[i].unk_08 = 0;
    }
    return TRUE;
}

BOOL sub_020878EC(UnkStruct02087284 *p, int x, int y) {
    int i;
    if (!sub_02087930(p, x, y)) {
        return FALSE;
    }
    p->sprites[0].x = x;
    p->sprites[0].y = y;
    p->unk_E8 = 0xFF;
    p->unk_EC = 0;
    for (i = 0; i < p->count; i++) {
        p->sprites[i].unk_08 = 0;
    }
    return TRUE;
}

BOOL sub_02087930(UnkStruct02087284 *p, int x, int y) {
    if (p->sprites[0].x == x && p->sprites[0].y == y) {
        return FALSE;
    }
    return TRUE;
}

BOOL sub_02087948(UnkStruct02087284 *p, s16 x, s16 y) {
    int i;
    p->unk_E8 = 0xFF;
    p->unk_EC = 0;
    for (i = 0; i < p->count; i++) {
        p->sprites[i].x = x;
        p->sprites[i].y = y;
        ManagedSprite_SetPositionXYWithSubscreenOffset(p->sprites[i].sprite, x, y, p->yOffset);
    }
    return TRUE;
}

BOOL sub_02087988(UnkStruct02087284 *p) {
    switch (p->state) {
    case 0:
        sub_020878B0(p, FALSE);
        p->state++;
        break;
    case 1:
        SysTask_Destroy(p->task);
        p->state++;
        break;
    default:
        sub_02087830(p);
        NARC_Delete(p->narc);
        Heap_Free(p);
        return FALSE;
    }
    return TRUE;
}

BOOL sub_020879E0(UnkStruct02087284 *p, int flag) {
    int i;
    for (i = 0; i < p->count; i++) {
        ManagedSprite_SetDrawFlag(p->sprites[i].sprite, flag);
    }
    return TRUE;
}

void sub_02087A08(UnkStruct02087284 *p, int a1, int a2) {
    if (a1 != 0 && a2 != 0) {
        p->unk_FC = a1;
        p->unk_100 = a2;
    } else {
        p->unk_FC = 15;
        p->unk_100 = 15;
    }
}

void sub_02087A30(UnkStruct02087284 *p) {
    int i;
    for (i = 0; i < p->count; i++) {
        ManagedSprite_SetAnim(p->sprites[i].sprite, 1);
    }
}

void sub_02087A54(UnkStruct02087284 *p) {
    int i;
    for (i = 0; i < p->count; i++) {
        ManagedSprite_SetAnim(p->sprites[i].sprite, 0);
    }
}
