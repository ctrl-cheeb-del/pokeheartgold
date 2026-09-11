#include "map_object_state_update_internal.h"

#define IS_GROUND_EFFECT_TILE(object, behavior)                                                           \
    (MetatileBehavior_IsTallGrass(behavior) == TRUE || MetatileBehavior_IsVeryTallGrass(behavior) == TRUE \
        || sub_02060E54(object, behavior) == TRUE || MetatileBehavior_IsPuddle(behavior) == TRUE          \
        || MetatileBehavior_IsShallowWater(behavior) == TRUE || sub_02060EBC(object, behavior) == TRUE    \
        || MetatileBehavior_IsMud(behavior) == TRUE || MetatileBehavior_IsReflective(behavior) != FALSE)

void sub_020603F8(LocalMapObject *object, int previous, u8 current, int effect) {
    u32 state;

    if (MapObjectManager_NotEndMovement(MapObject_GetManager(object)) == FALSE) {
        return;
    }
    state = ((u32) * (u16 *)effect << 25) >> 29;
    if (state == 0) {
        return;
    }
    if (state == 2) {
        if (MetatileBehavior_IsTallGrass(previous) == TRUE
            || MetatileBehavior_IsVeryTallGrass(previous) == TRUE
            || MetatileBehavior_IsTallGrass(current) == TRUE
            || MetatileBehavior_IsVeryTallGrass(current) == TRUE
            || sub_02060E54(object, previous) == TRUE
            || MetatileBehavior_IsPuddle(previous) == TRUE
            || MetatileBehavior_IsShallowWater(previous) == TRUE
            || sub_02060EBC(object, previous) == TRUE
            || MetatileBehavior_IsMud(previous) == TRUE
            || MetatileBehavior_IsReflective(previous) != FALSE) {
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
            return;
        }
        if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK15) == 0) {
            ov01_021FD684(object);
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK15);
        }
    } else {
        if (IS_GROUND_EFFECT_TILE(object, previous)) {
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
            return;
        }
        if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK15) == 0) {
            ov01_021FD640(object);
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK15);
        }
    }
}
