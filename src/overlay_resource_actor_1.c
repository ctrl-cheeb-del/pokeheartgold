#include "overlay_resource_actor_internal.h"

void *sub_020755E8(void *system, void *manager, u16 x, u16 y, u8 kind) {
    SpriteCreate create = _020FFF5C;
    void *sprite;
    create.x = x;
    create.y = y;
    create.unk6 = kind;
    sprite = SpriteSystem_NewSprite(system, manager, &create);
    ManagedSprite_SetAnimateFlag(sprite, 1);
    return sprite;
}

void sub_02075630(Work *work) {
    Config32 cfg32;
    Config20 cfg20;
    Config24 cfg24;
    void *narc;
    void *system;
    void *manager;
    work->spriteSystem = SpriteSystem_Alloc(work->heapId);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    cfg32 = _020FFF14;
    cfg20 = _020FFEE8;
    cfg20.value[0] = 0x10;
    SpriteSystem_Init(work->spriteSystem, &cfg32, &cfg20, 0x20);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 0x10);
    cfg24 = _020FFEFC;
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &cfg24);
    system = work->spriteSystem;
    manager = work->spriteManager;
    narc = NARC_New(0xef, work->heapId);
    SpriteSystem_LoadPlttResObjFromOpenNarc(system, manager, narc, 0xb, 0, 1, 2, 0);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, narc, 0xc, 0, 2, 0);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, narc, 0xd, 0, 0);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, narc, 0xe, 0, 0);
    NARC_Delete(narc);
    work->sprite = sub_020755E8(work->spriteSystem, work->spriteManager, 0x80, 0x48, 1);
    ManagedSprite_SetDrawFlag(work->sprite, 0);
    work->spritesReady = (void *)1;
}

void sub_02075770(Work *work) {
    void *system = work->spriteSystem;
    void *manager = work->spriteManager;
    if (work->sprite == 0) {
        GF_AssertFail();
    }
    Sprite_DeleteAndFreeResources(work->sprite);
    SpriteSystem_FreeResourcesAndManager(system, manager);
    SpriteSystem_Free(system);
    work->spritesReady = 0;
}

void sub_020757AC(Work *work) {
    int which;
    if (work->spritesReady == 0) {
        GF_AssertFail();
    }
    if (work->sprite == 0) {
        GF_AssertFail();
    }
    switch (work->result) {
    case 1:
        which = 0;
        break;
    case 2:
        which = 1;
        break;
    default:
        GF_AssertFail();
        break;
    }
    ManagedSprite_SetPositionXY(work->sprite, _020FFEC4[which * 2], _020FFEC6[which * 2]);
}

void sub_02075804(Work *work, void *window, void *msgData, int msgNo) {
    void *str = ReadMsgData_ExpandPlaceholders(work->msgFmt, work->msgData, msgNo, work->heapId);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 4, str, 0, 0, 0, 0x10200, 0);
    CopyWindowToVram(window);
    String_Delete(str);
}

void sub_0207584C(Work *work, int mode) {
    int first = 0x49d;
    int second = 0x49e;
    if (work->spritesReady == 0) {
        GF_AssertFail();
    }
    if (mode == 0) {
        BufferMoveName(work->msgFmt, 0, work->move);
        first = 0x4a2;
        second = 0x4a3;
    }
    sub_02075804(work, work->window1, work->msgData, first);
    sub_02075804(work, work->window2, work->msgData, second);
    work->state = 0;
    work->result = 1;
    sub_020757AC(work);
    ToggleBgLayer(5, 1);
    ToggleBgLayer(6, 1);
    ManagedSprite_SetDrawFlag(work->sprite, 1);
}

int sub_020758D0(Work *work) {
    int selected = 0;
    int hit = TouchscreenHitbox_FindRectAtTouchNew(_020FFECC);
    u32 keys;
    if (work->spritesReady == 0) {
        GF_AssertFail();
    }
    if (hit != -1) {
        PlaySE(0x5dc);
        switch (hit) {
        case 0:
            work->result = 1;
            selected = 1;
            break;
        case 1:
            work->result = 2;
            selected = 1;
            break;
        default:
            GF_AssertFail();
            break;
        }
    } else {
        keys = *(u32 *)(gSystem + 0x48);
        if (keys & 0x40) {
            if (work->result != 1) {
                work->result = 1;
                sub_020757AC(work);
                PlaySE(0x5dc);
            }
        } else if (keys & 0x80) {
            if (work->result != 2) {
                work->result = 2;
                sub_020757AC(work);
                PlaySE(0x5dc);
            }
        } else if (keys & 1) {
            if (work->result == 0) {
                GF_AssertFail();
                work->result = 2;
            }
            selected = 1;
        } else if (keys & 2) {
            work->result = 2;
            selected = 1;
        }
    }
    if (selected) {
        sub_020757AC(work);
        ManagedSprite_SetAnim(work->sprite, 3);
        PlaySE(0x5dc);
    }
    return selected;
}

int sub_020759CC(Work *work) {
    if (work->spritesReady == 0) {
        GF_AssertFail();
    }
    if (ManagedSprite_GetActiveAnim(work->sprite) != 3) {
        GF_AssertFail();
    }
    if (!ManagedSprite_IsAnimated(work->sprite)) {
        return 1;
    }
    return 0;
}

int sub_02075A04(Work *work) {
    switch (work->state) {
    case 0:
        if (sub_020758D0(work)) {
            work->state++;
        }
        break;
    case 1:
        if (sub_020759CC(work)) {
            if (work->spritesReady == 0) {
                GF_AssertFail();
            }
            if (work->result == 0) {
                GF_AssertFail();
            }
            ToggleBgLayer(5, 0);
            ToggleBgLayer(6, 0);
            ManagedSprite_SetDrawFlag(work->sprite, 0);
            return work->result;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}
