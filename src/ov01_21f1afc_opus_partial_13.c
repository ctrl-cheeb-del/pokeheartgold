#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

int ov01_021F2E08(struct WaterfallWork *work, TaskManager *taskManager) {
    ov01_021F3054(work->fieldSystem, &work->surf);
    work->state++;
    return 0;
}

int ov01_021F2E20(struct WaterfallWork *work, TaskManager *taskManager) {
    if (ov01_021F3068(&work->surf) == TRUE) {
        work->state++;
    }
    return 0;
}

int ov01_021F2E38(struct WaterfallWork *work, TaskManager *taskManager) {
    if (FollowMon_IsActive(work->fieldSystem)) {
        MapObject_UnpauseMovement(FollowMon_GetMapObject(work->fieldSystem));
    }
    work->unk50 = ov02_0224D67C(work->fieldSystem);
    PlaySE(SEQ_SE_DP_FW463);
    work->state++;
    return 0;
}

int ov01_021F2E6C(struct WaterfallWork *work, TaskManager *taskManager) {
    if (MapObject_AreBitsSetForMovementScriptInit(work->obj) == TRUE) {
        MapObject_SetHeldMovement(work->obj, sub_0206234C(work->direction, 4));
        work->state++;
    }
    return 0;
}

int ov01_021F2E94(struct WaterfallWork *work) {
    if (MapObject_IsMovementPaused(work->obj) == 0) {
        return 0;
    }
    MapObject_GetNextFacingDirection(work->obj);
    if (MetatileBehavior_IsWhirlpool(sub_0205F504(work->obj)) == TRUE) {
        work->state = 3;
        return 2;
    }
    ov02_0224D690(work->unk50);
    work->unk50 = NULL;
    MapObject_ClearHeldMovementIfActive(work->obj);
    return 1;
}

void ov01_021F2EDC(PlayerAvatar *playerAvatar) {
    u32 flags;
    LocalMapObject *obj = PlayerAvatar_GetMapObject(playerAvatar);
    if (sub_0205F73C(obj) != 0 && PlayerAvatar_GetState(playerAvatar) == 0 && MapObject_GetSpriteID(obj) - 0xC4 > 1) {
        flags = PlayerAvatar_GetTransitionFlags(playerAvatar);
        Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, 0x40);
        Field_PlayerAvatar_ApplyTransitionFlags(playerAvatar);
        Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, flags);
    }
}

void ov01_021F2F24(PlayerAvatar *playerAvatar) {
    u32 flags;
    LocalMapObject *obj = PlayerAvatar_GetMapObject(playerAvatar);
    if (sub_0205F73C(obj) != 0 && PlayerAvatar_GetState(playerAvatar) == 0) {
        switch (MapObject_GetSpriteID(obj)) {
        case 0xC4:
        case 0xC5:
            flags = PlayerAvatar_GetTransitionFlags(playerAvatar);
            Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, 1);
            Field_PlayerAvatar_ApplyTransitionFlags(playerAvatar);
            Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, flags);
            break;
        }
    }
}

SysTask *Field_PlayerMovementSavingSet(FieldSystem *fieldSystem) {
    PlayerAvatar *playerAvatar = fieldSystem->playerAvatar;
    u32 state = PlayerAvatar_GetState(playerAvatar);
    struct SavingWork *work;
    LocalMapObject *obj;
    SysTask *task;
    u32 flags;
    if (state != 0 && state != 3) {
        return NULL;
    }
    obj = PlayerAvatar_GetMapObject(playerAvatar);
    work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(struct SavingWork));
    work->unk0 = 0;
    work->fieldSystem = fieldSystem;
    work->playerAvatar = playerAvatar;
    work->state = state;
    if (state == 0) {
        flags = 0x80;
    } else if (state == 3) {
        flags = 1 << 14;
    } else {
        GF_AssertFail();
        flags = 0x80;
    }
    MapObject_UnpauseMovement(obj);
    Field_PlayerAvatar_OrrTransitionFlags(playerAvatar, flags);
    Field_PlayerAvatar_ApplyTransitionFlags(playerAvatar);
    task = SysTask_CreateOnMainQueue(ov01_021F3030, work, 0xFFFF);
    if (task == NULL) {
        GF_AssertFail();
    }
    return task;
}

void Field_PlayerMovementSavingClear(SysTask *task) {
    struct SavingWork *work;
    int state;
    PlayerAvatar *playerAvatar;
    if (task == NULL) {
        return;
    }
    work = SysTask_GetData(task);
    state = work->state;
    playerAvatar = work->playerAvatar;
    if (state == 0) {
        ov01_021F1B38(playerAvatar);
    } else if (state == 3) {
        ov01_021F1C30(playerAvatar);
    } else {
        GF_AssertFail();
        ov01_021F1B38(playerAvatar);
    }
    Heap_Free(work);
    SysTask_Destroy(task);
}

void ov01_021F3030(SysTask *task, void *data) {
    sub_0205F484(PlayerAvatar_GetMapObject(((struct SavingWork *)data)->playerAvatar));
}

void ov01_021F3040(FieldSystem *fieldSystem, u32 a1, struct SurfWork *work) {
    work->unk0 = 1;
    work->unk8 = a1;
    work->gender = PlayerAvatar_GetGender(fieldSystem->playerAvatar);
}

void ov01_021F3054(FieldSystem *fieldSystem, struct SurfWork *work) {
    work->unkC = ov02_02249458(fieldSystem, 0, work->unk8, work->gender);
}

BOOL ov01_021F3068(struct SurfWork *work) {
    if (ov02_0224953C(work->unkC) == TRUE) {
        ov02_02249548(work->unkC);
        return TRUE;
    }
    return FALSE;
}

void ov01_021F3084(PlayerAvatar *playerAvatar, u32 sprite) {
    ov01_021FA930(PlayerAvatar_GetMapObject(playerAvatar), sprite);
}

LocalMapObject *ov01_021F3094(PlayerAvatar *playerAvatar, int direction) {
    int x = PlayerAvatar_GetXCoord(playerAvatar);
    int dx = GetDeltaXByFacingDirection(direction);
    int z = PlayerAvatar_GetZCoord(playerAvatar);
    int dz = GetDeltaYByFacingDirection(direction);
    return MapObjectManager_GetFirstObjectWithXAndZ(MapObject_GetManager(PlayerAvatar_GetMapObject(playerAvatar)), x + dx, z + dz, 0);
}

void *ov01_021F30D0(u32 size) {
    void *p = Heap_AllocAtEnd(HEAP_ID_FIELD1, size);
    if (p == NULL) {
        GF_AssertFail();
    }
    memset(p, 0, size);
    return p;
}

void ov01_021F30F4(void *env) {
    Heap_FreeExplicit(HEAP_ID_FIELD1, env);
}

void *ov01_021F3100(FieldSystem *fieldSystem, int partySlot) {
    return Party_GetMonByIndex(SaveArray_Party_Get(fieldSystem->saveData), partySlot);
}
