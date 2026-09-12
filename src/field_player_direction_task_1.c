#include "field_player_direction_task_internal.h"
BOOL ov01_021F3114(void *fieldSystem, void *avatar) {
    u8 behavior = sub_0205F504(PlayerAvatar_GetMapObject(avatar));
    int direction;
    if (MetatileBehavior_IsSlideEast(behavior) == TRUE) {
        direction = 3;
    } else if (MetatileBehavior_IsSlideWest(behavior) == TRUE) {
        direction = 2;
    } else if (MetatileBehavior_IsSlideNorth(behavior) == TRUE) {
        direction = 0;
    } else if (MetatileBehavior_IsSlideSouth(behavior) == TRUE) {
        direction = 1;
    } else {
        return FALSE;
    }
    ov01_021F3170(fieldSystem, avatar, direction);
    return TRUE;
}

void ov01_021F3170(void *fieldSystem, void *avatar, int direction) {
    LocalSlideState *s = ov01_021F3348(sizeof(LocalSlideState));
    s->fieldSystem = fieldSystem;
    s->avatar = avatar;
    s->direction = direction;
    PlaySE(1623);
    FieldSystem_CreateTask(fieldSystem, ov01_021F31CC, s);
}

int ov01_021F31A0(int direction) {
    switch (direction) {
    case 0:
        return 2;
    case 2:
        return 1;
    case 1:
        return 3;
    case 3:
        return 0;
    default:
        return 0;
    }
}

BOOL ov01_021F31CC(void *taskManager) {
    LocalSlideState *s = TaskManager_GetEnvironment(taskManager);
    void *mapObject = PlayerAvatar_GetMapObject(s->avatar);
    u8 behavior = sub_0205F504(mapObject);
    switch (s->state) {
    case 0:
        MapObject_SetFlagsBits(mapObject, 1 << 8);
        s->state++;
        break;
    case 1:
        if (sub_0205DFC8(s->avatar) == 0) {
            break;
        }
        sub_0205DFD4(s->avatar, sub_0206234C(s->direction, 12));
        PlayerAvatar_SetFacingDirection(s->avatar, s->direction);
        s->state++;
        s->countdown = 7;
        break;
    case 2:
        if (s->countdown == 2 || s->countdown == 4 || s->countdown == 6) {
            s->direction = ov01_021F31A0(s->direction);
            PlayerAvatar_SetFacingDirection(s->avatar, s->direction);
        }
        s->countdown--;
        if (s->countdown != 0) {
            break;
        }
        if (MetatileBehavior_IsSlideEast(behavior) == TRUE) {
            s->direction = 3;
            ViridianGymmick_HandleTileAction(s->fieldSystem, behavior);
        } else if (MetatileBehavior_IsSlideWest(behavior) == TRUE) {
            s->direction = 2;
            ViridianGymmick_HandleTileAction(s->fieldSystem, behavior);
        } else if (MetatileBehavior_IsSlideNorth(behavior) == TRUE) {
            s->direction = 0;
            ViridianGymmick_HandleTileAction(s->fieldSystem, behavior);
        } else if (MetatileBehavior_IsSlideSouth(behavior) == TRUE) {
            s->direction = 1;
            ViridianGymmick_HandleTileAction(s->fieldSystem, behavior);
        } else if (MetatileBehavior_StopSliding(behavior) == TRUE) {
            s->direction = ov01_021F31A0(s->direction);
            MapObject_ClearFlagsBits(mapObject, 0x80);
            MapObject_ClearFlagsBits(mapObject, 1 << 8);
            PlayerAvatar_SetFacingDirection(s->avatar, s->direction);
            ov01_021F336C(s);
            StopSE(1623, 0);
            return TRUE;
        } else {
            s->direction = ov01_021F31A0(s->direction);
        }
        if (sub_0205DA34(s->avatar, mapObject, s->direction) == 0) {
            s->state = 1;
            break;
        }
        MapObject_ClearFlagsBits(mapObject, 0x80);
        MapObject_ClearFlagsBits(mapObject, 1 << 8);
        PlayerAvatar_SetFacingDirection(s->avatar, s->direction);
        ov01_021F336C(s);
        StopSE(1623, 0);
        return TRUE;
    }
    return FALSE;
}

void *ov01_021F3348(u32 size) {
    void *p = Heap_AllocAtEnd(4, size);
    if (p == NULL) {
        GF_AssertFail();
    }
    memset(p, 0, size);
    return p;
}

void ov01_021F336C(void *p) {
    Heap_FreeExplicit(4, p);
}
