#include "map_object_behavior_internal.h"

BOOL sub_0206464C(TrainerApproachWork *work) {
    LocalMapObject *object = work->trainer;
    if (MapObject_CheckSingleMovement(object) == TRUE) {
        MapObject_UnpauseMovement(object);
    }
    work->state = 1;
    return TRUE;
}

BOOL sub_02064668(TrainerApproachWork *work) {
    LocalMapObject *object = work->trainer;
    if (MapObject_CheckSingleMovement(object) == TRUE) {
        return FALSE;
    }
    ov01_021F9408(work->trainer, work->movement);
    MapObject_SetFlagsBits(object, (MapObjectFlagBits)0x40);
    work->state = 2;
    return TRUE;
}

BOOL sub_02064694(TrainerApproachWork *work) {
    LocalMapObject *player = PlayerAvatar_GetMapObject(work->player);
    if (!MapObject_IsMovementPaused(player)) {
        return FALSE;
    }
    switch (MapObject_GetMovement(work->trainer)) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
        work->state = 7;
        return TRUE;
    default:
        work->state = 3;
        return TRUE;
    }
}

BOOL sub_020646DC(TrainerApproachWork *work) {
    if (!MapObject_AreBitsSetForMovementScriptInit(work->trainer)) {
        return FALSE;
    }
    if (work->movement == -1) {
        GF_AssertFail();
    }
    MapObject_SetHeldMovement(work->trainer, sub_0206234C(work->movement, 0));
    work->state = 4;
    return FALSE;
}

BOOL sub_02064714(TrainerApproachWork *work) {
    if (!MapObject_IsMovementPaused(work->trainer)) {
        return FALSE;
    }
    work->state = 5;
    return TRUE;
}

BOOL sub_02064730(TrainerApproachWork *work) {
    work->effect = ov01_02200540(work->trainer, 0, 0);
    work->state = 6;
    return FALSE;
}

BOOL sub_02064748(TrainerApproachWork *work) {
    if (ov01_022003F4(work->effect) == TRUE) {
        sub_02068B48(work->effect);
        work->state = 9;
    }
    return FALSE;
}

BOOL sub_02064764(TrainerApproachWork *work) {
    MapObject_SetHeldMovement(work->trainer, 0x65);
    work->state = 8;
    return FALSE;
}

BOOL sub_02064778(TrainerApproachWork *work) {
    if (MapObject_IsMovementPaused(work->trainer) == TRUE) {
        work->state = 9;
    }
    return FALSE;
}

BOOL sub_02064790(TrainerApproachWork *work) {
    if (++work->timer >= 30) {
        work->timer = 0;
        work->state = 10;
    }
    return FALSE;
}

BOOL sub_020647A8(TrainerApproachWork *work) {
    if (work->remaining <= 1) {
        work->state = 13;
        return TRUE;
    }
    work->state = 11;
    return TRUE;
}

BOOL sub_020647C0(TrainerApproachWork *work) {
    if (MapObject_AreBitsSetForMovementScriptInit(work->trainer) == TRUE) {
        MapObject_SetHeldMovement(work->trainer, sub_0206234C(work->movement, 12));
        work->state = 12;
    }
    return FALSE;
}

BOOL sub_020647E8(TrainerApproachWork *work) {
    if (!MapObject_IsMovementPaused(work->trainer)) {
        return FALSE;
    }
    work->remaining--;
    work->state = 10;
    return TRUE;
}

BOOL sub_02064808(TrainerApproachWork *work) {
    if (++work->timer < 8) {
        return FALSE;
    }
    work->timer = 0;
    work->state = 14;
    return TRUE;
}
