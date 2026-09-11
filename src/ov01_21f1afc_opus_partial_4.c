#include "ov01_21f1afc_opus_partial_internal.h"

extern const StepFunc ov01_02206994[5];

extern const StepFunc ov01_022069A8[5];

extern const StepFunc ov01_022069BC[5];

extern const StepFunc ov01_022069D0[8];

extern const StepFunc ov01_022069F0[9];

extern const u16 __attribute__((aligned(4))) ov01_02206A14[4][5];

extern void (*const sPlayerAvatarBitUpdateFuncs[15])(PlayerAvatar *);

void CallFieldTask_Surf(TaskManager *taskManager, int direction, int partySlot) {
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
    ov01_021F202C(fieldSystem, direction, &work);
}

BOOL Field_PlayerCanSurfOnTile(PlayerAvatar *playerAvatar, int a1, int a2) {
    LocalMapObject *obj = PlayerAvatar_GetMapObject(playerAvatar);
    if (MetatileBehavior_IsSurfableWater(a2) == TRUE) {
        if (sub_0205BA30(a1) == TRUE || sub_0205BA24(a1) == TRUE) {
            if (MapObject_CheckFlag28(obj) == TRUE) {
                return FALSE;
            }
        }
        if (sub_0205B78C(a1) == TRUE) {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}
