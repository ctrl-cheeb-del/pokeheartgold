#include "r40_overlay_27_residual_3_private.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
typedef struct {
    u8 pad[0xD2];
    u8 flags : 6;
} FsFake;

BOOL ov27_0225A4D0(void *p) {
    BOOL draw = ov27_0225BDC8(p);
    if (PlayerAvatar_GetState(PTR(PTR(p, 0x10), 0x40)) == 1 || ((FsFake *)PTR(p, 0x10))->flags != 0) {
        draw = FALSE;
    }
    if (draw) {
        Sprite_SetDrawFlag(PTR(p, 0x3BC), TRUE);
        Sprite_SetDrawFlag(PTR(p, 0x3C4), TRUE);
    } else {
        Sprite_SetDrawFlag(PTR(p, 0x3BC), FALSE);
        Sprite_SetDrawFlag(PTR(p, 0x3C4), FALSE);
    }
    return draw;
}

void ov27_0225A530(void *p, int active) {
    int anim = Sprite_GetAnimationNumber(PTR(p, 0x3C0));
    if (Sprite_GetDrawFlag(PTR(p, 0x3C0))) {
        if (active == 1 && System_GetTouchNew()) {
            *(u32 *)(gSystem + 0x5C) = 1;
            Sprite_SetAnimCtrlSeq(PTR(p, 0x3C0), 6);
            return;
        }
        if (active == 1 && anim == 6) {
            *(u32 *)(gSystem + 0x5C) = 1;
            return;
        }
        Sprite_SetAnimCtrlSeq(PTR(p, 0x3C0), 5);
    }
}

s32 ov27_0225A594(void *p) {
    void *fs = PTR(p, 0x10);
    void *playerObj;
    void *facingObj;
    s32 result;
    if (ov27_0225BD44(fs)) {
        return 4;
    }
    if (!FieldSystem_IsPlayerMovementAllowed(fs)) {
        playerObj = PlayerAvatar_GetMapObject(FieldSystem_GetPlayerAvatar(fs));
        int dir = sub_0205F330(playerObj);
        u32 id = MapObject_GetSpriteID(playerObj);
        if ((u32)(id - 0xBC) <= 1) {
            return dir == 1 ? 3 : 4;
        }
        if (U32(p, 0x510) != 4) {
            return U32(p, 0x510);
        }
    }
    result = ov01_021E7F54(fs);
    if (result == 1) {
        FieldSystem_GetFacingObject(fs, &facingObj);
        if (ov01_021F6BD0(MapObject_GetScriptID(facingObj)) || ov01_021F6BB0(MapObject_GetSpriteID(facingObj))) {
            result = 0;
        }
    }
    return result;
}

void ov27_0225A61C(void *p, s32 index) {
    FillWindowPixelBuffer((u8 *)p + 0x3D0, 0);
    u8 *entry = (u8 *)p + ov27_0225D108[index] * 4;
    AddTextPrinterParameterizedWithColor((u8 *)p + 0x3D0, 4, PTR(entry, 0x4B0), 0, 0, 0, 0xF0100, 0);
    Sprite_SetDrawFlag(PTR(p, 0x3C0), TRUE);
}
