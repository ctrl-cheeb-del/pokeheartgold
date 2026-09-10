#include "map_object_behavior_internal.h"

BOOL sub_020648A0(TrainerApproachWork *work) {
    LocalMapObject *player = PlayerAvatar_GetMapObject(work->player);
    if (!MapObject_IsMovementPaused(player)) {
        return FALSE;
    }
    MapObject_ClearHeldMovementIfActive(player);
    work->state = 16;
    return TRUE;
}

BOOL sub_020648C8(TrainerApproachWork *work) {
    MapObject_ClearHeldMovementIfActive(work->trainer);
    sub_0205FC94(work->trainer, 0);
    work->state = 17;
    return TRUE;
}

BOOL sub_020648E4(TrainerApproachWork *work) {
    work->done = TRUE;
    return FALSE;
}
