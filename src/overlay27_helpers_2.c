#include "overlay_27_helpers_internal.h"

void ov27_0225A468(Ov27Work *work, s32 a1) {
    Sprite_SetAnimCtrlSeq(work->unk3C4, 11 - a1 * 4);
    Sprite_SetAnimCtrlSeq(work->unk3BC, a1 + 3);
}

void ov27_0225A48C(Ov27Work *work, s32 a1) {
    PlayerAvatar *avatar;
    s32 v;
    if (a1 == 0) {
        avatar = FieldSystem_GetPlayerAvatar(work->unk10);
        v = PlayerAvatar_CheckRunningShoesLock(avatar) ^ 1;
        ov27_0225A468(work, v);
        PlayerAvatar_SetRunningShoesLock(avatar, v);
    }
}

void ov27_0225A4B8(Ov27Work *work) {
    ov27_0225A468(work, PlayerAvatar_CheckRunningShoesLock(FieldSystem_GetPlayerAvatar(work->unk10)));
}
