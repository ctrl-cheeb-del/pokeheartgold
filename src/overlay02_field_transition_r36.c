#include "overlay02_field_transition_r36_private.h"

int ov02_0224C698(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    void *effect = ov01_021FCD2C(fieldSystem, 4);
    work->effect = effect;
    ov01_021FCD8C(effect, 1, 0xFFF6A000, 15);
    work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_02253770);
    work->state++;
    PlaySE(SEQ_SE_DP_TELE);
    return 0;
}

int ov02_0224C6DC(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    if (!EventObjectMovementMan_IsFinish(work->followerMovement)) {
        return 0;
    }
    EventObjectMovementMan_Delete(work->followerMovement);
    work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_02253820);
    work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_02253820);
    work->state++;
    return 0;
}

int ov02_0224C71C(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    void *effect = ov01_021FCD2C(fieldSystem, 4);
    work->effect = effect;
    ov01_021FCD8C(effect, 1, 0xFFF6A000, 15);
    work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_02253820);
    work->state++;
    PlaySE(SEQ_SE_DP_TELE);
    return 0;
}

int ov02_0224C75C(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    if (!EventObjectMovementMan_IsFinish(work->playerMovement)) {
        return 0;
    }
    EventObjectMovementMan_Delete(work->playerMovement);
    work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_02253794);
    if (work->hasFollower != 0) {
        EventObjectMovementMan_Delete(work->followerMovement);
        work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_02253794);
    }
    work->counter++;
    if (work->counter < 8) {
        return 0;
    }
    BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 4);
    work->state++;
    return 0;
}

int ov02_0224C7D4(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    if (EventObjectMovementMan_IsFinish(work->playerMovement) == 1) {
        EventObjectMovementMan_Delete(work->playerMovement);
        work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_02253794);
        if (work->hasFollower != 0) {
            EventObjectMovementMan_Delete(work->followerMovement);
            work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_02253794);
        }
    }
    if (!IsPaletteFadeFinished()) {
        return 0;
    }
    EventObjectMovementMan_Delete(work->playerMovement);
    if (work->hasFollower != 0) {
        EventObjectMovementMan_Delete(work->followerMovement);
    }
    ov01_021FCD78(work->effect);
    work->state++;
    return 1;
}

int ov02_0224C840(void *taskManager, R36FieldSystem *fieldSystem, R36Work *work) {
    R36WarpData warp;
    void *localFieldData = Save_LocalFieldData_Get(fieldSystem->saveData);
    void *blackoutSpawn = LocalFieldData_GetBlackoutSpawn(localFieldData);
    GetFlyWarpData(blackoutSpawn, &warp);
    GetSpecialSpawnWarpData(blackoutSpawn, LocalFieldData_GetSpecialSpawnWarpPtr(localFieldData));
    sub_02053B04(taskManager, &warp, work->warpId);
    return 2;
}

int ov02_0224C87C(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    void *effect = ov01_021FCD2C(fieldSystem, 4);
    work->effect = effect;
    ov01_021FCD8C(effect, 1, 0xFFF6A000, 15);
    work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_022537DC);
    if (work->hasFollower != 0) {
        work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_022537DC);
    }
    work->state++;
    PlaySE(SEQ_SE_DP_KAIDAN2);
    return 0;
}

int ov02_0224C8D0(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    if (!EventObjectMovementMan_IsFinish(work->playerMovement)) {
        return 0;
    }
    EventObjectMovementMan_Delete(work->playerMovement);
    work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_022537B8);
    if (work->hasFollower != 0) {
        EventObjectMovementMan_Delete(work->followerMovement);
        work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_022537B8);
    }
    if (PlayerAvatar_GetState(fieldSystem->playerAvatar) != 2) {
        if (work->hasFollower != 0) {
            work->unk2C = ov02_0224DDF4(work->unk24);
        } else {
            work->unk2C = ov02_0224DDE0(work->unk24);
        }
    }
    work->state++;
    return 0;
}

int ov02_0224C93C(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    if (!EventObjectMovementMan_IsFinish(work->playerMovement)) {
        return 0;
    }
    EventObjectMovementMan_Delete(work->playerMovement);
    work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_02253794);
    if (work->hasFollower != 0) {
        EventObjectMovementMan_Delete(work->followerMovement);
        work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_02253794);
    }
    work->counter++;
    if (work->counter < 8) {
        return 0;
    }
    BeginNormalPaletteFade(0, 0, 0, 0x7FFF, 6, 1, 4);
    work->state++;
    return 0;
}

int ov02_0224C9B8(void *unused, R36FieldSystem *fieldSystem, R36Work *work) {
    if (EventObjectMovementMan_IsFinish(work->playerMovement) == 1) {
        EventObjectMovementMan_Delete(work->playerMovement);
        work->playerMovement = EventObjectMovementMan_Create(work->playerObject, ov02_02253794);
        if (work->hasFollower != 0) {
            EventObjectMovementMan_Delete(work->followerMovement);
            work->followerMovement = EventObjectMovementMan_Create(fieldSystem->mapObjectManager, ov02_02253794);
        }
    }
    if (!IsPaletteFadeFinished()) {
        return 0;
    }
    EventObjectMovementMan_Delete(work->playerMovement);
    if (PlayerAvatar_GetState(fieldSystem->playerAvatar) != 2) {
        ov02_0224DE08(work->unk2C);
        work->unk2C = NULL;
    }
    if (work->hasFollower != 0) {
        EventObjectMovementMan_Delete(work->followerMovement);
    }
    ov01_021FCD78(work->effect);
    work->state++;
    return 1;
}
