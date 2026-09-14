#include "overlay01_field_movement_r4_private.h"

BOOL ov01_021F232C(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int direction, int collision) {
    u32 result;

    if (collision != 1 || PlayerAvatar_GetState(playerAvatar) != 2) {
        return FALSE;
    }
    result = sub_0205DA34(playerAvatar, PlayerAvatar_GetMapObject(playerAvatar), direction);
    if (result == 0x20) {
        return FALSE;
    }
    if ((result & ~0x20) != 0) {
        return FALSE;
    }
    ov01_021F2378(direction, fieldSystem, playerAvatar);
    return TRUE;
}

void ov01_021F2378(int direction, FieldSystem *fieldSystem, PlayerAvatar *playerAvatar) {
    struct SoundplateWork *work;

    work = ov01_021F30D0(sizeof(struct SoundplateWork));
    work->direction = direction;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = playerAvatar;
    work->mapObject = PlayerAvatar_GetMapObject(playerAvatar);
    work->avatarEffect = PlayerAvatar_GetUnk34(playerAvatar);
    if (work->avatarEffect == 0) {
        GF_AssertFail();
    }
    FieldSystem_CreateTask(fieldSystem, ov01_021F23B8, work);
}

BOOL ov01_021F23B8(TaskManager *taskManager) {
    struct SoundplateWork *work = TaskManager_GetEnvironment(taskManager);

    switch (work->state) {
    case 0:
        if (MapObject_AreBitsSetForMovementScriptInit(work->mapObject) == TRUE) {
            ov01_021F3084(work->playerAvatar, PlayerAvatar_GetSpriteByStateAndGender(0, PlayerAvatar_GetGender(work->playerAvatar)));
            MapObject_SetHeldMovement(work->mapObject, sub_0206234C(work->direction, 0x34));
            ov01_021FE9F4(work->avatarEffect, 0);
            work->state++;
        }
        break;
    case 1:
        if (MapObject_IsMovementPaused(work->mapObject)) {
            MapObject_ClearHeldMovementIfActive(work->mapObject);
            ov01_021F1640(work->avatarEffect);
            PlayerAvatar_SetUnk34(work->playerAvatar, 0);
            PlayerAvatar_SetState(work->playerAvatar, 0);
            FieldSystem_ProcessSoundplate(work->fieldSystem, 0);
            if (FollowMon_IsActive(work->fieldSystem)) {
                ov01_02205790(work->fieldSystem, (u8)work->direction);
                sub_02069DC8(FollowMon_GetMapObject(work->fieldSystem), 1);
                ov01_0220609C(work->fieldSystem, 1);
                sub_0205FC94(FollowMon_GetMapObject(work->fieldSystem), 0x30);
            }
            if (!CheckFlag99A(Save_VarsFlags_Get(work->fieldSystem->saveData))) {
                FieldBGM_TryFadeOut(work->fieldSystem, FieldBGM_GetForMapHeader(work->fieldSystem, work->fieldSystem->location->mapId), 4);
            }
            if (SndRadio_GetSeqNo() != 0) {
                work->timer = 0x28;
                work->state++;
            } else {
                ov01_021F30F4(work);
                return TRUE;
            }
        }
        break;
    case 2:
        if (SndRadio_GetSeqNo() == 0) {
            FieldSystem_ProcessSoundplate(work->fieldSystem, 1);
            ov01_021F30F4(work);
            return TRUE;
        }
        work->timer--;
        if (work->timer == 0) {
            FieldSystem_ProcessSoundplate(work->fieldSystem, 1);
            ov01_021F30F4(work);
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov01_021F24F4(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int direction, int collision) {
    if (direction != 1 || collision != 1 || PlayerAvatar_GetState(playerAvatar) != 2) {
        return FALSE;
    }
    if (!MetatileBehavior_IsWaterfall((u8)sub_0205DFEC(playerAvatar, direction))) {
        return FALSE;
    }
    ov01_021F28EC(fieldSystem, direction);
    return TRUE;
}
