#include "field_interaction.h"

#include "global.h"

#include "constants/global_fieldmap.h"

#include "field_system.h"
#include "field_terrain.h"
#include "map_events_internal.h"
#include "map_object.h"
#include "metatile_behavior.h"
#include "player_avatar.h"
#include "script_manager.h"

static u32 GetCoordsOfFacingTile(FieldSystem *fieldSystem, int *x, int *z);
static u8 PlayerAvatar_IsAtSameHeightAs(PlayerAvatar *avatar, LocalMapObject *object);
static u8 BgEventIsUncollectedHiddenItem(FieldSystem *fieldSystem, BgEvent *bgEvent);
static BOOL BgEvent_MatchesPlayerFacing(FieldSystem *fieldSystem, BgEvent *bgEvent);

void BottomScreen_None_Init(FieldSystem *fieldSystem) {
}

void BottomScreen_None_End(FieldSystem *fieldSystem) {
}

BOOL BottomScreen_None_IsDone(FieldSystem *fieldSystem) {
    return TRUE;
}

static u32 GetCoordsOfFacingTile(FieldSystem *fieldSystem, int *x, int *z) {
    u32 dir = PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar);
    *x = (int)PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    *z = (int)PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    switch (dir) {
    case DIR_NORTH:
        (*z)--;
        break;
    case DIR_SOUTH:
        (*z)++;
        break;
    case DIR_WEST:
        (*x)--;
        break;
    case DIR_EAST:
        (*x)++;
        break;
    }
    return dir;
}

static u8 PlayerAvatar_IsAtSameHeightAs(PlayerAvatar *avatar, LocalMapObject *object) {
    u32 y = MapObject_GetPositionVectorYCoordUInt(PlayerAvatar_GetMapObject(avatar));
    if (y == MapObject_GetPositionVectorYCoordUInt(object)) {
        return TRUE;
    }
    return FALSE;
}

void FieldSystem_GetFacingObject(FieldSystem *fieldSystem, LocalMapObject **ret_p) {
    int x;
    int z;
    u32 dir = GetCoordsOfFacingTile(fieldSystem, &x, &z);
    if (MetatileBehavior_IsCounter(GetMetatileBehavior(fieldSystem, x, z)) == TRUE) {
        switch (dir) {
        case DIR_NORTH:
            z--;
            break;
        case DIR_SOUTH:
            z++;
            break;
        case DIR_WEST:
            x--;
            break;
        case DIR_EAST:
            x++;
            break;
        }
    }
    *ret_p = MapObjectManager_GetFirstObjectWithXAndZ(fieldSystem->mapObjectManager, x, z, FALSE);
}

// The object on the facing tile, if it can be talked to (flag 19 clear) and stands at the player's height.
BOOL FieldSystem_GetInteractableFacingObject(FieldSystem *fieldSystem, LocalMapObject **localMapObject) {
    FieldSystem_GetFacingObject(fieldSystem, localMapObject);
    if (*localMapObject != NULL && MapObject_CheckFlag19Disabled(*localMapObject) == TRUE && PlayerAvatar_IsAtSameHeightAs(fieldSystem->playerAvatar, *localMapObject) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

u16 GetInteractedBackgroundEventScript(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents) {
    int x;
    int z;
    int i;
    BgEvent *bgEvent;
    GetCoordsOfFacingTile(fieldSystem, &x, &z);
    i = 0;
    if (numEvents > 0) {
        bgEvent = bgEvents;
        do {
            if (x == bgEvent->x && z == bgEvent->z) {
                if (bgEvent->type == BG_TYPE_HIDDEN_ITEM) {
                    if (BgEventIsUncollectedHiddenItem(fieldSystem, &bgEvents[i]) == TRUE) {
                        return bgEvents[i].scriptId;
                    }
                } else if (BgEvent_MatchesPlayerFacing(fieldSystem, &bgEvents[i]) == TRUE) {
                    return bgEvents[i].scriptId;
                }
            }
            bgEvent++;
            i++;
        } while (i < numEvents);
    }
    return 0xFFFF;
}

static u8 BgEventIsUncollectedHiddenItem(FieldSystem *fieldSystem, BgEvent *bgEvent) {
    if (bgEvent->type != BG_TYPE_HIDDEN_ITEM) {
        return FALSE;
    }
    if (FieldSystem_FlagCheck(fieldSystem, HiddenItemScriptNoToFlagId(bgEvent->scriptId)) == TRUE) {
        return FALSE;
    }
    return TRUE;
}

static BOOL BgEvent_MatchesPlayerFacing(FieldSystem *fieldSystem, BgEvent *bgEvent) {
    if (bgEvent->dir == BG_DIR_ALL) {
        return TRUE;
    }
    switch (PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar)) {
    case DIR_NORTH:
        if (bgEvent->dir == BG_DIR_SOUTH || bgEvent->dir == BG_DIR_NORTHSOUTH) {
            return TRUE;
        }
        break;
    case DIR_SOUTH:
        if (bgEvent->dir == BG_DIR_NORTH || bgEvent->dir == BG_DIR_NORTHSOUTH) {
            return TRUE;
        }
        break;
    case DIR_WEST:
        if (bgEvent->dir == BG_DIR_EAST || bgEvent->dir == BG_DIR_EASTWEST) {
            return TRUE;
        }
        break;
    case DIR_EAST:
        if (bgEvent->dir == BG_DIR_WEST || bgEvent->dir == BG_DIR_EASTWEST) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

// Script of a sign (BG event type 1) on the facing tile; signs are only read while facing north.
u32 GetFacingSignScript(FieldSystem *fieldSystem, BgEvent *bgEvents, int numEvents) {
    int x;
    int z;
    int i;
    if (PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar) != DIR_NORTH) {
        return 0xFFFF;
    }
    GetCoordsOfFacingTile(fieldSystem, &x, &z);
    for (i = 0; i < numEvents; i++) {
        if (x == bgEvents[i].x && z == bgEvents[i].z && bgEvents[i].type == BG_TYPE_SIGNPOST) {
            return bgEvents[i].scriptId;
        }
    }
    return 0xFFFF;
}

// Script of the coord event whose rectangle contains the player and whose variable holds its trigger value.
u16 GetTriggeredCoordEventScript(FieldSystem *fieldSystem, const CoordEvent *coordEvents, int numEvents) {
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
