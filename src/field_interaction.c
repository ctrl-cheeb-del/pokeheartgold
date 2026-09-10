#include "field_interaction_internal.h"

void sub_0203DB6C(void) {
}

void sub_0203DB70(void) {
}

BOOL sub_0203DB74(void) {
    return TRUE;
}

u32 _GetCoordsOfFacingTile(FieldSystem *fieldSystem, int *x, int *z) {
    u32 dir = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
    *x = (int)PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    *z = (int)PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    switch (dir) {
    case 0:
        (*z)--;
        break;
    case 1:
        (*z)++;
        break;
    case 2:
        (*x)--;
        break;
    case 3:
        (*x)++;
        break;
    }
    return dir;
}

u8 sub_0203DBD4(PlayerAvatar *avatar, LocalMapObject *object) {
    u32 y = MapObject_GetPositionVectorYCoordUInt(PlayerAvatar_GetMapObject(avatar));
    if (y == MapObject_GetPositionVectorYCoordUInt(object)) {
        return TRUE;
    }
    return FALSE;
}

void FieldSystem_GetFacingObject(FieldSystem *fieldSystem, LocalMapObject **ret_p) {
    int x;
    int z;
    u32 dir = _GetCoordsOfFacingTile(fieldSystem, &x, &z);
    if (sub_0205B700(GetMetatileBehavior(fieldSystem, x, z)) == TRUE) {
        switch (dir) {
        case 0:
            z--;
            break;
        case 1:
            z++;
            break;
        case 2:
            x--;
            break;
        case 3:
            x++;
            break;
        }
    }
    *ret_p = MapObjectManager_GetFirstObjectWithXAndZ(fieldSystem->mapObjectManager, (u32)x, (u32)z, FALSE);
}

BOOL sub_0203DC64(FieldSystem *fieldSystem, LocalMapObject **localMapObject) {
    FieldSystem_GetFacingObject(fieldSystem, localMapObject);
    if (*localMapObject != NULL && MapObject_CheckFlag19Disabled(*localMapObject) == TRUE && sub_0203DBD4(fieldSystem->playerAvatar, *localMapObject) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

u16 GetInteractedBackgroundEventScript(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents) {
    int x;
    int z;
    int i;
    BgEvent *bgEvent;
    _GetCoordsOfFacingTile(fieldSystem, &x, &z);
    i = 0;
    if (numEvents > 0) {
        bgEvent = bgEvents;
        do {
            if (x == bgEvent->x && z == bgEvent->z) {
                if (bgEvent->type == 2) {
                    if (BgEventIsUncollectedHiddenItem(fieldSystem, &bgEvents[i]) == TRUE) {
                        return bgEvents[i].scriptId;
                    }
                } else if (BgEventDirectionIsCompatibleWithPlayerFacing(fieldSystem, &bgEvents[i]) == TRUE) {
                    return bgEvents[i].scriptId;
                }
            }
            bgEvent++;
            i++;
        } while (i < numEvents);
    }
    return 0xFFFF;
}

u8 BgEventIsUncollectedHiddenItem(FieldSystem *fieldSystem, BgEvent *bgEvent) {
    if (bgEvent->type != 2) {
        return FALSE;
    }
    if (FieldSystem_FlagCheck(fieldSystem, HiddenItemScriptNoToFlagId(bgEvent->scriptId)) == TRUE) {
        return FALSE;
    }
    return TRUE;
}

BOOL BgEventDirectionIsCompatibleWithPlayerFacing(FieldSystem *fieldSystem, BgEvent *bgEvent) {
    if (bgEvent->dir == 4) {
        return TRUE;
    }
    switch (PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar)) {
    case 0:
        if (bgEvent->dir == 0 || bgEvent->dir == 6) {
            return TRUE;
        }
        break;
    case 1:
        if (bgEvent->dir == 3 || bgEvent->dir == 6) {
            return TRUE;
        }
        break;
    case 2:
        if (bgEvent->dir == 2 || bgEvent->dir == 5) {
            return TRUE;
        }
        break;
    case 3:
        if (bgEvent->dir == 1 || bgEvent->dir == 5) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

u32 sub_0203DDA4(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents) {
    int x;
    int z;
    int i;
    if (PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar) != 0) {
        return 0xFFFF;
    }
    _GetCoordsOfFacingTile(fieldSystem, &x, &z);
    for (i = 0; i < numEvents; i++) {
        if (x == bgEvents[i].x && z == bgEvents[i].z && bgEvents[i].type == 1) {
            return bgEvents[i].scriptId;
        }
    }
    return 0xFFFF;
}

u16 sub_0203DE04(FieldSystem *fieldSystem, const CoordEvent *coordEvents, int numEvents) {
    int i;
    int x = (int)PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    int z = (int)PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    for (i = 0; i < numEvents; i++) {
        if (x >= coordEvents[i].x && x < coordEvents[i].x + coordEvents[i].w && z >= coordEvents[i].z && z < coordEvents[i].z + coordEvents[i].h && FieldSystem_VarGet(fieldSystem, coordEvents[i].var) == coordEvents[i].val) {
            return coordEvents[i].scriptId;
        }
    }
    return 0xFFFF;
}
