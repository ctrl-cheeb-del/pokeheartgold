#define PlayerAvatar_SetRunningShoesLock PlayerAvatar_SetRunningShoesLock_u16
#include "r45_overlay28_private.h"
#undef PlayerAvatar_SetRunningShoesLock

void PlayerAvatar_SetRunningShoesLock(PlayerAvatar *avatar, u32 lock);

void ov28_0225DA74(DowsingMchn *ptr);
void ov28_0225DB8C(DowsingMchn *ptr, NARC *narc);

SysTask *ov28_0225D520(BgConfig *bgConfig, void *a1, FieldSystem *fieldSystem, void *a3);
void ov28_0225D650(BgConfig *bgConfig);
void ov28_0225D7E0(DowsingMchn *ptr);
void ov28_0225DC2C(SysTask *task, void *data);
int ov01_021E7F54(FieldSystem *fieldSystem);
int ov01_021F6BD0(int a);
int ov01_021F6BB0(int a);
void ov28_0225D5EC(void *unused, SysTask *task);
BOOL ov28_0225D624(void);
void ov28_0225D628(void);
void ov28_0225D6E0(BgConfig *bgConfig);
void ov28_0225D6FC(DowsingMchn *ptr, NARC *narc);
void ov28_0225D764(DowsingMchn *ptr);
void ov28_0225D7C4(DowsingMchn *ptr);
void ov28_0225D878(DowsingMchn *ptr);
void ov28_0225D898(DowsingMchn *ptr, NARC *narc);
void ov28_0225D8D0(DowsingMchn *ptr);
void ov28_0225D8EC(DowsingMchn *ptr);
void ov28_0225D910(DowsingMchn *ptr);
void ov28_0225DB54(DowsingMchn *ptr);
void ov28_0225DB8C(DowsingMchn *ptr, NARC *narc);
void ov28_0225DBFC(DowsingMchn *ptr);
void DowsingMchn_GetHiddenItemLocs(DowsingMchn *ptr);
void DowsingMchn_FreeHiddenItemLocs(DowsingMchn *ptr);
void ov28_0225DE04(fx32 *ptr, int deg);
u16 ov28_0225DE64(int x, int y);
u16 ov28_0225DE78(int x, int y);
u16 ov28_0225DE88(int a);
void ov28_0225DE98(DowsingMchnAngle *ptr);
void ov28_0225DEB0(DowsingMchn *ptr);
void ov28_0225DF14(DowsingMchn *ptr);
void ov28_0225DFBC(DowsingMchn *ptr);
void ov28_0225E060(DowsingMchn *ptr);
void ov28_0225E0DC(DowsingMchnAngle *ptr);
void ov28_0225E424(Sprite *sprite, int deg);
BOOL ov28_0225E7D4(DowsingMchn *ptr);
BOOL ov28_0225E8B8(const TouchscreenHitbox *hitbox, Sprite *sprite, int idleAnim, int pressedAnim);
BOOL ov28_0225EA58(DowsingMchn *ptr);
BOOL FieldSystem_TaskIsRunning(FieldSystem *fieldSystem);
u8 ov28_0225E51C(DowsingMchn *ptr, int x, int y);
void ov28_0225E810(DowsingMchn *ptr);
void ov28_0225E900(DowsingMchn *ptr);
void ov28_0225E938(DowsingMchn *ptr);
void ov28_0225E9E0(DowsingMchn *ptr);

extern const u8 ov28_0225EA91[];
extern const u8 ov28_0225EB7C[];
extern const TouchscreenHitbox _0225EA7C;
extern const TouchscreenHitbox ov28_0225EA80;
extern const TouchscreenHitbox ov28_0225EA84;

void ov28_0225DF04(DowsingMchnAngle *ptr);
void ov28_0225DFA4(DowsingMchnAngle *ptr);
void ov28_0225E054(DowsingMchnAngle *ptr);

/* callees not written here */
void ov28_0225D8EC(DowsingMchn *ptr);
void ov28_0225DA74(DowsingMchn *ptr);

BOOL ov28_0225E7D4(DowsingMchn *ptr) {
    u32 x;
    u32 y;

    System_GetTouchHeldCoords(&x, &y);
    if (ptr->unk214 != x || ptr->unk218 != y) {
        ptr->unk214 = x;
        ptr->unk218 = y;
        return FALSE;
    }
    return TRUE;
}

void ov28_0225E810(DowsingMchn *ptr) {
    int state;

    if (ptr->fieldSystem->textbox_open == TRUE) {
        state = 4;
    } else if (!FieldSystem_IsPlayerMovementAllowed(ptr->fieldSystem)) {
        LocalMapObject *obj = PlayerAvatar_GetMapObject(FieldSystem_GetPlayerAvatar(ptr->fieldSystem));
        u32 spriteId = MapObject_GetSpriteID(obj);
        if ((u32)(spriteId - 0xBC) <= 1) {
            state = sub_0205F330(obj) == 1 ? 3 : 4;
        } else {
            state = ptr->unk334;
        }
    } else {
        state = ov01_021E7F54(ptr->fieldSystem);
        if (state == 1) {
            LocalMapObject *obj;
            FieldSystem_GetFacingObject(ptr->fieldSystem, &obj);
            if (ov01_021F6BD0(MapObject_GetScriptID(obj)) == 1 || ov01_021F6BB0(MapObject_GetSpriteID(obj)) == 1) {
                state = 0;
            }
        }
    }
    if (state != ptr->unk334) {
        ptr->unk334 = state;
        ScheduleWindowCopyToVram(&ptr->windows[ov28_0225EB7C[ptr->unk334]]);
    }
}

BOOL ov28_0225E8B8(const TouchscreenHitbox *hitbox, Sprite *sprite, int idleAnim, int pressedAnim) {
    BOOL held = TouchscreenHitbox_TouchHeldIsIn(hitbox);
    u16 animation = Sprite_GetAnimationNumber(sprite);

    if (held == TRUE && System_GetTouchNew()) {
        Sprite_SetAnimCtrlSeq(sprite, pressedAnim);
        return TRUE;
    }
    if (held == TRUE && animation == pressedAnim) {
        return TRUE;
    }
    Sprite_SetAnimCtrlSeq(sprite, idleAnim);
    return FALSE;
}

void ov28_0225E900(DowsingMchn *ptr) {
    if (sub_0203DF8C(ptr->fieldSystem) == TRUE) {
        ov28_0225E810(ptr);
    }
    if (ov28_0225E8B8(&_0225EA7C, ptr->sprites[0], 5, 6)) {
        gSystem.simulatedInputs = TRUE;
    }
}

void ov28_0225E938(DowsingMchn *ptr) {
    PlayerAvatar *avatar;
    u16 lock;

    if (PlayerAvatar_GetState(ptr->fieldSystem->playerAvatar) == 1 || ov28_0225EA58(ptr) == TRUE) {
        Sprite_SetDrawFlag(ptr->sprites[1], FALSE);
        Sprite_SetDrawFlag(ptr->sprites[2], FALSE);
        return;
    }
    Sprite_SetDrawFlag(ptr->sprites[1], TRUE);
    Sprite_SetDrawFlag(ptr->sprites[2], TRUE);
    if (TouchscreenHitbox_TouchNewIsIn(&ov28_0225EA84) == TRUE) {
        avatar = FieldSystem_GetPlayerAvatar(ptr->fieldSystem);
        lock = PlayerAvatar_CheckRunningShoesLock(avatar);
        if (lock == 0) {
            Sprite_SetAnimCtrlSeq(ptr->sprites[1], 4);
            Sprite_SetAnimCtrlSeq(ptr->sprites[2], 7);
        } else {
            Sprite_SetAnimCtrlSeq(ptr->sprites[1], 3);
            Sprite_SetAnimCtrlSeq(ptr->sprites[2], 11);
        }
        PlayerAvatar_SetRunningShoesLock(avatar, lock ^ 1);
    }
}

void ov28_0225E9E0(DowsingMchn *ptr) {
    if (ov28_0225EA58(ptr) == TRUE) {
        ClearWindowTilemapAndScheduleTransfer(&ptr->windows[4]);
        Sprite_SetAnimCtrlSeq(ptr->sprites[3], 8);
        Sprite_SetDrawFlag(ptr->sprites[3], FALSE);
        return;
    }
    ScheduleWindowCopyToVram(&ptr->windows[4]);
    Sprite_SetDrawFlag(ptr->sprites[3], TRUE);
    if (ov28_0225E8B8(&ov28_0225EA80, ptr->sprites[3], 8, 9)) {
        ptr->fieldSystem->lastTouchMenuInput = 11;
        MenuInputStateMgr_SetState((MenuInputStateMgr *)((u8 *)ptr->fieldSystem + 0x10C), MENU_INPUT_STATE_TOUCH);
    }
}

BOOL ov28_0225EA58(DowsingMchn *ptr) {
    if (FieldSystem_TaskIsRunning(ptr->fieldSystem) == TRUE && ((Ov28FieldSystemFlags *)ptr->fieldSystem)->taskFlag == 0) {
        return TRUE;
    }
    return FALSE;
}
