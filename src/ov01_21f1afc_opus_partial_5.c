#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

BOOL ov01_021F2538(FieldSystem *fieldSystem, PlayerAvatar *playerAvatar, int a2) {
    MapObject_AreBitsSetForMovementScriptInit(PlayerAvatar_GetMapObject(playerAvatar));
    return FALSE;
}

void ov01_021F2548(FieldSystem *fieldSystem, int a1, struct SurfWork *a2) {
    PlayerAvatar *playerAvatar;
    struct RockClimbWork *work = ov01_021F30D0(sizeof(struct RockClimbWork));
    work->direction = a1;
    work->fieldSystem = fieldSystem;
    playerAvatar = fieldSystem->playerAvatar;
    work->playerAvatar = playerAvatar;
    work->obj = PlayerAvatar_GetMapObject(playerAvatar);
    work->surf = *a2;
    if (work->surf.unk0 == 1) {
        work->unk2 = 5;
    } else {
        work->unk2 = 6;
    }
    TaskManager_Call(fieldSystem->taskman, ov01_021F2628, work);
}

void CallFieldTask_RockClimb(TaskManager *taskManager, int direction, int partySlot) {
    u32 state;
    struct SurfWork work;
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    ov01_021F3040(fieldSystem, (u32)ov01_021F3100(fieldSystem, partySlot), &work);
    state = PlayerAvatar_GetState(fieldSystem->playerAvatar);
    if (state - 1 <= 1) {
        work.unk0 = 1;
    } else if (ov01_02206268(fieldSystem) != 0 && partySlot == ov01_022062CC(fieldSystem)) {
        work.unk0 = 0;
    }
    ov01_021F2548(fieldSystem, direction, &work);
}

BOOL MetatileBehavior_IsRockClimbInDirection(int facingTile, int facingDirection) {
    switch (facingDirection) {
    case 0:
    case 1:
        if (MetatileBehavior_IsRockClimbNorthSouth((u8)facingTile) == TRUE) {
            return TRUE;
        }
        break;
    case 2:
    case 3:
        if (MetatileBehavior_IsRockClimbEastWest((u8)facingTile) == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}
