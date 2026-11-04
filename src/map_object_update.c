#include "global.h"

#include "constants/scrcmd.h"

#include "field/field_follow_mon.h"
#include "field/map_object_models.h"

#include "comm_state.h"
#include "communication_command.h"
#include "field_footprints.h"
#include "field_ground_dust.h"
#include "field_mud_splash.h"
#include "field_puddle_splash.h"
#include "field_reflection.h"
#include "field_shadow.h"
#include "field_shallow_water_ripple.h"
#include "field_system.h"
#include "field_tall_grass.h"
#include "field_terrain.h"
#include "field_very_tall_grass.h"
#include "map_object.h"
#include "map_object_behavior_internal.h"
#include "map_object_follow_internal.h"
#include "map_object_movement_commands_internal.h"
#include "map_object_movement_utilities_internal.h"
#include "metatile_behavior.h"
#include "overlay_01.h"

static BOOL MapObject_CanUpdateMovement(LocalMapObject *object);
static void MapObject_UpdateHeightIfFlagged(LocalMapObject *object);
static void MapObject_RestartIfBehaviorsLoaded(LocalMapObject *object);
static void MapObject_UpdateEffectsBeforeMovement(LocalMapObject *object);
static void MapObject_UpdateEffectsAfterMovement(LocalMapObject *object);
static void MapObject_UpdateEffectsAtStepEnd(LocalMapObject *object);
static void MapObject_SpawnStartEffects(LocalMapObject *object);
static void MapObject_SpawnStepStartEffects(LocalMapObject *object);
static void MapObject_SpawnJumpStartEffects(LocalMapObject *object);
static void MapObject_SpawnStepEndEffects(LocalMapObject *object);
static void MapObject_SpawnJumpLandEffects(LocalMapObject *object);
static void MapObject_ResetTileDrawOffset(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnTallGrassStanding(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnTallGrassOnStep(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnFootprints(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_UpdateShallowWaterRipple(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_ResetShallowWaterRipple(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_CreateShadowWithSavedBehavior(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_CreateShadow(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_UpdateShadowVisibility(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnGroundDust(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnVeryTallGrassStanding(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnVeryTallGrassOnStep(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_TileEffectDummy(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_TileEffectDummy2(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnPuddleSplashAtPrevious(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnPuddleSplash(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnMudSplashAtPrevious(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_SpawnMudSplash(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_CreateReflection(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_UpdateReflection(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_UpdateOnBridgeFlag(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static void MapObject_TileEffectDummy3(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags);
static u32 MapObject_CheckCollision(LocalMapObject *object, VecFx32 *position, int x, int y, int z, u32 direction);

void MapObject_CallMovementAndBehaviorInit(LocalMapObject *object) {
    MapObject_CallMovementInit(object);
    MapObject_InitTypeBehavior(object);
}

void MapObject_UpdateMovement(LocalMapObject *object) {
    if (MapObject_GetManagerFlagsBitsMask(object, MAPOBJECTFLAG_SINGLE_MOVEMENT) == 0) {
        MapObject_UpdateHeightIfFlagged(object);
        MapObject_RestartIfBehaviorsLoaded(object);
        MapObject_UpdateEffectsBeforeMovement(object);
        if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK4)) {
            MapObject_ExecuteMovementCommand(object);
        } else if (!MapObject_CheckMovementPaused(object) && MapObject_CanUpdateMovement(object) == TRUE && !MapObject_UpdateTypeBehavior(object)) {
            MapObject_CallMovementUpdate(object);
        }
        MapObject_UpdateEffectsAfterMovement(object);
        MapObject_UpdateEffectsAtStepEnd(object);
    }
}

static BOOL MapObject_CanUpdateMovement(LocalMapObject *object) {
    u32 flags;
    if (MapObject_CheckSingleMovement(object) == TRUE) {
        return TRUE;
    }
    if (!MapObject_GetFlagsBitsMask(object, (MapObjectFlagBits)(MAPOBJECTFLAG_UNK11 | MAPOBJECTFLAG_UNK12))) {
        return TRUE;
    }
    if (MapObject_GetMovement(object) == 0x32) {
        return TRUE;
    }
    if (MapObject_GetMovement(object) == 0x30) {
        return TRUE;
    }
    flags = MapObject_GetFlags(object);
    if ((flags & MAPOBJECTFLAG_UNK12) && !(flags & MAPOBJECTFLAG_IGNORE_HEIGHTS)) {
        return FALSE;
    }
    if ((flags & MAPOBJECTFLAG_UNK11) && !MapObject_CheckIgnoreMetatileBehaviors(object)) {
        return FALSE;
    }
    return TRUE;
}

static void MapObject_UpdateHeightIfFlagged(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK12)) {
        MapObject_UpdateHeight(object);
    }
}

static void MapObject_RestartIfBehaviorsLoaded(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK11) && MapObject_UpdateMetatileBehaviors(object) == TRUE) {
        MapObject_SetStartMovement(object);
    }
}

static void MapObject_UpdateEffectsBeforeMovement(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_START_MOVEMENT)) {
        MapObject_SpawnStartEffects(object);
    }
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_START_MOVEMENT | MAPOBJECTFLAG_UNK16));
}

static void MapObject_UpdateEffectsAfterMovement(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK16)) {
        MapObject_SpawnJumpStartEffects(object);
    } else if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_START_MOVEMENT)) {
        MapObject_SpawnStepStartEffects(object);
    }
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_START_MOVEMENT | MAPOBJECTFLAG_UNK16));
}

static void MapObject_UpdateEffectsAtStepEnd(LocalMapObject *object) {
    if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK17)) {
        MapObject_SpawnJumpLandEffects(object);
    } else if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_END_MOVEMENT)) {
        MapObject_SpawnStepEndEffects(object);
    }
    MapObject_ClearFlagsBits(object, (MapObjectFlagBits)(MAPOBJECTFLAG_END_MOVEMENT | MAPOBJECTFLAG_UNK17));
}

const TileTestFunc gMetatileBlocksExitTests[4] = { MetatileBehavior_IsBlockedNorth, MetatileBehavior_IsBlockedSouth, MetatileBehavior_IsBlockedWest, MetatileBehavior_IsBlockedEast };
const TileTestFunc gMetatileBlocksEntryTests[4] = { MetatileBehavior_IsBlockedSouth, MetatileBehavior_IsBlockedNorth, MetatileBehavior_IsBlockedEast, MetatileBehavior_IsBlockedWest };
const s32 gDirectionDeltaX[4] = { 0, 0, -1, 1 };
const s32 gDirectionDeltaY[4] = { -1, 1, 0, 0 };
const s32 gOppositeDirections[4] = { 1, 0, 3, 2 };

static void MapObject_SpawnStartEffects(LocalMapObject *object) {
    u8 previous;
    u8 current;
    const MapObjectEffectFlags *effect;
    MapObject_UpdateMetatileBehaviors(object);
    if (MapObject_IsDrawInitialized(object) == TRUE) {
        previous = MapObject_GetCurrentMetatileBehavior(object);
        current = MapObject_GetPreviousMetatileBehavior(object);
        effect = MapObject_GetEffectFlags(object);
        MapObject_UpdateOnBridgeFlag(object, previous, current, effect);
        MapObject_SpawnTallGrassStanding(object, previous, current, effect);
        MapObject_UpdateShallowWaterRipple(object, previous, current, effect);
        MapObject_CreateShadowWithSavedBehavior(object, previous, current, effect);
        MapObject_ResetTileDrawOffset(object, previous, current, effect);
        MapObject_SpawnVeryTallGrassStanding(object, previous, current, effect);
        MapObject_TileEffectDummy(object, previous, current, effect);
        MapObject_CreateReflection(object, previous, current, effect);
    }
}

static void MapObject_SpawnStepStartEffects(LocalMapObject *object) {
    u8 previous;
    u8 current;
    const MapObjectEffectFlags *effect;
    MapObject_UpdateMetatileBehaviors(object);
    if (MapObject_IsDrawInitialized(object) == TRUE) {
        previous = MapObject_GetCurrentMetatileBehavior(object);
        current = MapObject_GetPreviousMetatileBehavior(object);
        effect = MapObject_GetEffectFlags(object);
        MapObject_UpdateOnBridgeFlag(object, previous, current, effect);
        MapObject_SpawnTallGrassOnStep(object, previous, current, effect);
        MapObject_SpawnFootprints(object, previous, current, effect);
        MapObject_UpdateShallowWaterRipple(object, previous, current, effect);
        MapObject_CreateShadow(object, previous, current, effect);
        MapObject_SpawnVeryTallGrassOnStep(object, previous, current, effect);
        MapObject_TileEffectDummy2(object, previous, current, effect);
        MapObject_SpawnPuddleSplashAtPrevious(object, previous, current, effect);
        MapObject_SpawnMudSplashAtPrevious(object, previous, current, effect);
        MapObject_CreateReflection(object, previous, current, effect);
        MapObject_TileEffectDummy3(object, previous, current, effect);
    }
}

static void MapObject_SpawnJumpStartEffects(LocalMapObject *object) {
    MapObject_UpdateMetatileBehaviors(object);
    if (MapObject_IsDrawInitialized(object) == TRUE) {
        u8 previous = MapObject_GetCurrentMetatileBehavior(object);
        u8 current = MapObject_GetPreviousMetatileBehavior(object);
        const MapObjectEffectFlags *effect = MapObject_GetEffectFlags(object);
        MapObject_UpdateOnBridgeFlag(object, previous, current, effect);
        MapObject_CreateShadow(object, previous, current, effect);
        MapObject_CreateReflection(object, previous, current, effect);
        MapObject_ResetShallowWaterRipple(object, previous, current, effect);
        MapObject_TileEffectDummy3(object, previous, current, effect);
    }
}

static void MapObject_SpawnStepEndEffects(LocalMapObject *object) {
    u8 value = MapObject_GetPreviousMetatileBehavior(object);
    MapObject_SetSavedPreviousBehavior(object, value);
    MapObject_UpdateMetatileBehaviors(object);
    if (MapObject_IsDrawInitialized(object) == TRUE) {
        u8 behavior = MapObject_GetCurrentMetatileBehavior(object);
        u8 prevBehavior = MapObject_GetPreviousMetatileBehavior(object);
        const MapObjectEffectFlags *effect = MapObject_GetEffectFlags(object);
        MapObject_ResetTileDrawOffset(object, behavior, prevBehavior, effect);
        MapObject_SpawnPuddleSplash(object, behavior, prevBehavior, effect);
        MapObject_SpawnMudSplash(object, behavior, prevBehavior, effect);
        MapObject_UpdateShallowWaterRipple(object, behavior, prevBehavior, effect);
        MapObject_UpdateReflection(object, behavior, prevBehavior, effect);
        MapObject_UpdateShadowVisibility(object, behavior, prevBehavior, effect);
    }
}

static void MapObject_SpawnJumpLandEffects(LocalMapObject *object) {
    MapObject_UpdateMetatileBehaviors(object);
    if (MapObject_IsDrawInitialized(object) == TRUE) {
        u8 behavior = MapObject_GetCurrentMetatileBehavior(object);
        u8 prevBehavior = MapObject_GetPreviousMetatileBehavior(object);
        const MapObjectEffectFlags *effect = MapObject_GetEffectFlags(object);
        MapObject_ResetTileDrawOffset(object, behavior, prevBehavior, effect);
        MapObject_SpawnPuddleSplash(object, behavior, prevBehavior, effect);
        MapObject_SpawnMudSplash(object, behavior, prevBehavior, effect);
        MapObject_UpdateShallowWaterRipple(object, behavior, prevBehavior, effect);
        MapObject_UpdateReflection(object, behavior, prevBehavior, effect);
        MapObject_UpdateShadowVisibility(object, behavior, prevBehavior, effect);
        MapObject_SpawnTallGrassOnStep(object, behavior, prevBehavior, effect);
        MapObject_SpawnGroundDust(object, behavior, prevBehavior, effect);
    }
}

static void MapObject_ResetTileDrawOffset(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    VecFx32 position = { 0, 0, 0 };
    MapObject_SetTileDrawOffset(object, &position);
}

static void MapObject_SpawnTallGrassStanding(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u32 id = MapObject_GetID(object);
    int x;
    int z;
    u8 facing;
    FieldSystem *fieldSystem;
    u32 nextBehavior;

    if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
        if (id != obj_partner_poke || MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE) != TRUE) {
            TallGrass_Spawn(object, FALSE);
        } else {
            return;
        }
    }
    if (MapObject_GetID(object) != obj_partner_poke || !FollowMonObject_IsLarge(object)) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    fieldSystem = MapObject_GetFieldSystem(object);
    if ((u8)(facing + 0xFE) > 1) {
        return;
    }
    MapObject_GetCoordsBehind(object, &x, &z);
    nextBehavior = GetMetatileBehavior(fieldSystem, x, z);
    if (MetatileBehavior_IsTallGrass(nextBehavior) == TRUE) {
        TallGrass_SpawnAt(object, FALSE, x, z, TRUE);
        return;
    }
    if (MetatileBehavior_IsVeryTallGrass(nextBehavior) == TRUE) {
        VeryTallGrass_SpawnAt(object, FALSE, x, z, TRUE);
    }
}

static void MapObject_SpawnTallGrassOnStep(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u32 id = MapObject_GetID(object);
    int x;
    int z;
    u8 facing;
    FieldSystem *fieldSystem;
    u32 nextBehavior;

    if (MetatileBehavior_IsTallGrass(behavior) == TRUE) {
        if (id != obj_partner_poke || MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE) != TRUE) {
            TallGrass_Spawn(object, TRUE);
        } else {
            return;
        }
    }
    if (MapObject_GetID(object) != obj_partner_poke || !FollowMonObject_IsLarge(object)) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    fieldSystem = MapObject_GetFieldSystem(object);
    if ((u8)(facing + 0xFE) > 1) {
        return;
    }
    MapObject_GetCoordsBehind(object, &x, &z);
    nextBehavior = GetMetatileBehavior(fieldSystem, x, z);
    if (MetatileBehavior_IsTallGrass(nextBehavior) == TRUE) {
        TallGrass_SpawnAt(object, TRUE, x, z, TRUE);
        return;
    }
    if (MetatileBehavior_IsVeryTallGrass(nextBehavior) == TRUE) {
        VeryTallGrass_SpawnAt(object, TRUE, x, z, TRUE);
    }
}

static void MapObject_SpawnFootprints(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u32 kind = flags->footprints;

    if (kind == 0) {
        return;
    }
    if (MetatileBehavior_Is169(prevBehavior) == TRUE) {
        kind = flags->footprints;
        if (kind == 1) {
            Footprints_SpawnOnBehavior169(object);
        } else if (kind == 2) {
            Footprints_SpawnTracksOnBehavior169(object);
        }
    }
    if (MapObject_CheckSandBehavior(object, prevBehavior) == TRUE) {
        kind = flags->footprints;
        if (kind == 1) {
            Footprints_SpawnInSand(object);
            return;
        } else if (kind == 2) {
            Footprints_SpawnTracksInSand(object);
            return;
        }
    } else if (MapObject_CheckSnowFootprintBehavior(object, prevBehavior) == TRUE) {
        Footprints_SpawnInSnow(object);
    }
}

static void MapObject_UpdateShallowWaterRipple(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MetatileBehavior_IsShallowWater(behavior) == TRUE) {
        if (!MapObject_CheckFlag26(object)) {
            ShallowWaterRipple_Spawn(object, TRUE);
            MapObject_SetFlag26(object, TRUE);
        }
    } else {
        MapObject_SetFlag26(object, FALSE);
    }
}

static void MapObject_ResetShallowWaterRipple(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    MapObject_SetFlag26(object, FALSE);
}

static void MapObject_CreateShadowWithSavedBehavior(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u8 value = MapObject_GetSavedPreviousBehavior(object);
    MapObject_CreateShadow(object, behavior, value, flags);
}

#define IS_GROUND_EFFECT_TILE(object, behavior)                                                                       \
    (MetatileBehavior_IsTallGrass(behavior) == TRUE || MetatileBehavior_IsVeryTallGrass(behavior) == TRUE             \
        || MapObject_CheckWaterBehavior(object, behavior) == TRUE || MetatileBehavior_IsPuddle(behavior) == TRUE      \
        || MetatileBehavior_IsShallowWater(behavior) == TRUE || MapObject_CheckSnowBehavior(object, behavior) == TRUE \
        || MetatileBehavior_IsMud(behavior) == TRUE || MetatileBehavior_IsReflective(behavior))

static void MapObject_CreateShadow(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u32 state;

    if (!MapObjectManager_NotEndMovement(MapObject_GetManager(object))) {
        return;
    }
    state = flags->shadow;
    if (state == 0) {
        return;
    }
    if (state == 2) {
        if (MetatileBehavior_IsTallGrass(behavior) == TRUE
            || MetatileBehavior_IsVeryTallGrass(behavior) == TRUE
            || MetatileBehavior_IsTallGrass(prevBehavior) == TRUE
            || MetatileBehavior_IsVeryTallGrass(prevBehavior) == TRUE
            || MapObject_CheckWaterBehavior(object, behavior) == TRUE
            || MetatileBehavior_IsPuddle(behavior) == TRUE
            || MetatileBehavior_IsShallowWater(behavior) == TRUE
            || MapObject_CheckSnowBehavior(object, behavior) == TRUE
            || MetatileBehavior_IsMud(behavior) == TRUE
            || MetatileBehavior_IsReflective(behavior)) {
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
            return;
        }
        if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK15) == 0) {
            FieldShadow_CreateFollowMonShadow(object);
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK15);
        }
    } else {
        if (IS_GROUND_EFFECT_TILE(object, behavior)) {
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
            return;
        }
        if (MapObject_GetFlagsBitsMask(object, MAPOBJECTFLAG_UNK15) == 0) {
            FieldShadow_CreateMapObjectShadow(object);
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK15);
        }
    }
}

static void MapObject_UpdateShadowVisibility(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u16 previous;
    if (!MapObjectManager_NotEndMovement(MapObject_GetManager(object))) {
        return;
    }
    if (flags->shadow == 0) {
        return;
    }
    if (flags->shadow == 2) {
        previous = (u16)((u32(*)(LocalMapObject *))MapObject_GetSavedPreviousBehavior)(object);
        if (MetatileBehavior_IsTallGrass(behavior) == TRUE || MetatileBehavior_IsVeryTallGrass(behavior) == TRUE || MetatileBehavior_IsTallGrass(previous) == TRUE || MetatileBehavior_IsVeryTallGrass(previous) == TRUE || MapObject_CheckWaterBehavior(object, behavior) == TRUE || MetatileBehavior_IsPuddle(behavior) == TRUE || MetatileBehavior_IsShallowWater(behavior) == TRUE || MapObject_CheckSnowBehavior(object, behavior) == TRUE || MetatileBehavior_IsMud(behavior) == TRUE || MetatileBehavior_IsReflective(behavior)) {
            MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
        } else {
            MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK20);
        }
        return;
    }
    if (MetatileBehavior_IsTallGrass(behavior) == TRUE || MetatileBehavior_IsVeryTallGrass(behavior) == TRUE || MapObject_CheckWaterBehavior(object, behavior) == TRUE || MetatileBehavior_IsPuddle(behavior) == TRUE || MetatileBehavior_IsShallowWater(behavior) == TRUE || MapObject_CheckSnowBehavior(object, behavior) == TRUE || MetatileBehavior_IsMud(behavior) == TRUE || MetatileBehavior_IsReflective(behavior)) {
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK20);
    } else {
        MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK20);
    }
}

static void MapObject_SpawnGroundDust(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MapObject_CheckWaterBehavior(object, behavior) == TRUE
        || MetatileBehavior_IsShallowWater(behavior) == TRUE
        || MetatileBehavior_IsIce(behavior) == TRUE
        || MetatileBehavior_IsMud(behavior) == TRUE
        || MapObject_CheckSnowBehavior(object, behavior) == TRUE
        || MapObject_CheckInvisible(object)) {
        return;
    }
    GroundDust_Spawn(object);
}

static void MapObject_SpawnVeryTallGrassStanding(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u32 id = MapObject_GetID(object);
    if (MetatileBehavior_IsVeryTallGrass(behavior) == TRUE && (id != obj_partner_poke || MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE) != TRUE)) {
        VeryTallGrass_Spawn(object, FALSE);
    }
}

static void MapObject_SpawnVeryTallGrassOnStep(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u32 id = MapObject_GetID(object);
    if (MetatileBehavior_IsVeryTallGrass(behavior) == TRUE && (id != obj_partner_poke || MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE) != TRUE)) {
        VeryTallGrass_Spawn(object, TRUE);
    }
}

static void MapObject_TileEffectDummy(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
}

static void MapObject_TileEffectDummy2(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
}

static void MapObject_SpawnPuddleSplashAtPrevious(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MetatileBehavior_IsPuddle(prevBehavior) == TRUE) {
        int x = MapObject_GetPreviousXCoord(object);
        int y = MapObject_GetPreviousYCoord(object);
        int z = MapObject_GetPreviousZCoord(object);
        PuddleSplash_Spawn(object, x, y, z);
    }
}

static void MapObject_SpawnPuddleSplash(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MetatileBehavior_IsPuddle(behavior) == TRUE) {
        int x = MapObject_GetXCoord(object);
        int y = MapObject_GetYCoord(object);
        int z = MapObject_GetZCoord(object);
        PuddleSplash_Spawn(object, x, y, z);
    }
}

static void MapObject_SpawnMudSplashAtPrevious(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MetatileBehavior_IsMud(prevBehavior) == TRUE) {
        int x = MapObject_GetPreviousXCoord(object);
        int y = MapObject_GetPreviousYCoord(object);
        int z = MapObject_GetPreviousZCoord(object);
        MudSplash_Spawn(object, x, y, z);
    }
}

static void MapObject_SpawnMudSplash(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MetatileBehavior_IsMud(behavior) == TRUE) {
        int x = MapObject_GetXCoord(object);
        int y = MapObject_GetYCoord(object);
        int z = MapObject_GetZCoord(object);
        MudSplash_Spawn(object, x, y, z);
    }
}

static void MapObject_CreateReflection(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    u8 selected;

    if (flags->reflection != 0) {
        if (MapObject_CheckFlag24(object) != TRUE) {
            selected = GetMetatileBehavior_None();

            if (MapObject_GetID(object) == obj_partner_poke) {
                if (FollowMonObject_IsLarge(object) != 0) {
                    u8 foundBehavior;
                    u8 first;
                    u8 second;
                    u8 third;
                    u8 fourth;
                    u8 fifth;
                    BOOL found;
                    enum ReflectionKind kind;

                    if (MapObject_CheckFlag24(object)) {
                        return;
                    }
                    if (MetatileBehavior_HasReflectiveSurface(behavior) == TRUE) {
                        selected = behavior;
                    } else {
                        first = MapObject_GetMetatileBehaviorInDirection(object, DIR_SOUTH);
                        second = MapObject_GetMetatileBehaviorInDirection(object, DIR_EAST);
                        third = MapObject_GetMetatileBehaviorInDirection(object, DIR_WEST);
                        fourth = MapObject_GetAdjacentTileBehavior(object, 4);
                        fifth = MapObject_GetAdjacentTileBehavior(object, 5);
                        found = FALSE;
                        if (MetatileBehavior_HasReflectiveSurface(first) == TRUE) {
                            foundBehavior = first;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(second) == TRUE) {
                            foundBehavior = second;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(third) == TRUE) {
                            foundBehavior = third;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(fourth) == TRUE) {
                            foundBehavior = fourth;
                            found = TRUE;
                        } else if (MetatileBehavior_HasReflectiveSurface(fifth) == TRUE) {
                            foundBehavior = fifth;
                            found = TRUE;
                        }
                        if (found == TRUE) {
                            selected = foundBehavior;
                        }
                    }
                    if (selected == GetMetatileBehavior_None()) {
                        return;
                    }
                    MapObject_SetFlag24(object, TRUE);
                    if (MetatileBehavior_IsReflective(selected) == TRUE) {
                        kind = REFLECTION_KIND_LARGE_FLOOR;
                    } else if (MetatileBehavior_IsPuddle(selected) == TRUE) {
                        kind = REFLECTION_KIND_LARGE_PUDDLE;
                    } else {
                        kind = REFLECTION_KIND_LARGE_WATER;
                    }
                    Reflection_SpawnForFollower(object, kind);
                } else {
                    enum ReflectionKind kind;
                    if (MapObject_CheckFlag24(object)) {
                        return;
                    }
                    if (MetatileBehavior_HasReflectiveSurface(behavior) == TRUE) {
                        selected = behavior;
                    } else {
                        u8 adjacent = MapObject_GetMetatileBehaviorInDirection(object, DIR_SOUTH);
                        if (MetatileBehavior_HasReflectiveSurface(adjacent) == TRUE) {
                            selected = adjacent;
                        }
                    }
                    if (selected == GetMetatileBehavior_None()) {
                        return;
                    }
                    MapObject_SetFlag24(object, TRUE);
                    if (MetatileBehavior_IsReflective(selected) == TRUE) {
                        kind = REFLECTION_KIND_FLOOR;
                    } else if (MetatileBehavior_IsPuddle(selected) == TRUE) {
                        kind = REFLECTION_KIND_PUDDLE;
                    } else {
                        kind = REFLECTION_KIND_WATER;
                    }
                    Reflection_SpawnForFollower(object, kind);
                }
            } else {
                enum ReflectionKind kind;
                if (MapObject_CheckFlag24(object)) {
                    return;
                }
                if (MetatileBehavior_HasReflectiveSurface(behavior) == TRUE) {
                    selected = behavior;
                } else {
                    u8 adjacent = MapObject_GetMetatileBehaviorInDirection(object, DIR_SOUTH);
                    if (MetatileBehavior_HasReflectiveSurface(adjacent) == TRUE) {
                        selected = adjacent;
                    }
                }
                if (selected == GetMetatileBehavior_None()) {
                    return;
                }
                MapObject_SetFlag24(object, TRUE);
                if (MetatileBehavior_IsReflective(selected) == TRUE) {
                    kind = REFLECTION_KIND_FLOOR;
                } else if (MetatileBehavior_IsPuddle(selected) == TRUE) {
                    kind = REFLECTION_KIND_PUDDLE;
                } else {
                    kind = REFLECTION_KIND_WATER;
                }
                Reflection_Spawn(object, kind);
            }
        }
    }
}

static void MapObject_UpdateReflection(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (flags->reflection == 0 || !MapObject_CheckFlag24(object)) {
        return;
    }
    if (MapObject_GetID(object) == obj_partner_poke && FollowMonObject_IsLarge(object) != 0) {
        u8 first = MapObject_GetMetatileBehaviorInDirection(object, DIR_SOUTH);
        u8 second = MapObject_GetMetatileBehaviorInDirection(object, DIR_EAST);
        u8 third = MapObject_GetMetatileBehaviorInDirection(object, DIR_WEST);
        u8 fourth = MapObject_GetAdjacentTileBehavior(object, 4);
        u8 fifth = MapObject_GetAdjacentTileBehavior(object, 5);
        BOOL found = FALSE;

        if (MetatileBehavior_HasReflectiveSurface(first) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(second) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(third) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(fourth) == TRUE) {
            found = TRUE;
        } else if (MetatileBehavior_HasReflectiveSurface(fifth) == TRUE) {
            found = TRUE;
        }
        if (!found) {
            MapObject_SetFlag24(object, FALSE);
        }
    } else {
        u8 adjacent = MapObject_GetMetatileBehaviorInDirection(object, DIR_SOUTH);
        if (!MetatileBehavior_HasReflectiveSurface(adjacent)) {
            MapObject_SetFlag24(object, FALSE);
        }
    }
}

static void MapObject_UpdateOnBridgeFlag(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
    if (MetatileBehavior_IsBridgeStart(behavior) == TRUE) {
        MapObject_SetFlag28(object, TRUE);
    } else if (MapObject_CheckFlag28(object) == TRUE && !MetatileBehavior_IsBridge(behavior)) {
        MapObject_SetFlag28(object, FALSE);
    }
}

static void MapObject_TileEffectDummy3(LocalMapObject *object, u8 behavior, u8 prevBehavior, const MapObjectEffectFlags *flags) {
}

static u32 MapObject_CheckCollision(LocalMapObject *object, VecFx32 *position, int x, int y, int z, u32 direction) {
    u32 result = 0;
    s8 slope;

    if (MapObject_IsOutsideMovementRange(object, x, y, z) == TRUE) {
        result |= 1;
    }
    if (FieldSystem_CheckCollisionAndHeight(MapObject_GetFieldSystem(object), position, x, z, &slope) == TRUE) {
        result |= 2;
        if (slope != 0) {
            result |= 8;
        }
    }
    if (MapObject_IsMoveBlockedByBehavior(object, x, z, direction) == TRUE) {
        result |= 2;
    }
    if (Comm_IsUnionRoomLinkMode(CommState_GetLinkMode())) {
        if (MapObject_IsTileOccupiedInLink(object, x, y, z) == TRUE) {
            result |= 4;
        }
    } else {
        if (MapObject_IsTileOccupied(object, x, y, z) == TRUE) {
            result |= 4;
        }
    }
    return result;
}

u32 MapObject_CheckCollisionAt(LocalMapObject *object, int x, int y, int z, u32 direction) {
    VecFx32 position;
    MapObject_CopyPositionVector(object, &position);
    return MapObject_CheckCollision(object, &position, x, y, z, direction);
}

u32 MapObject_CheckCollisionInDirection(LocalMapObject *object, u32 direction) {
    int x = MapObject_GetXCoord(object) + GetDeltaXByFacingDirection(direction);
    int y = MapObject_GetYCoord(object);
    int z = MapObject_GetZCoord(object) + GetDeltaYByFacingDirection(direction);
    return MapObject_CheckCollisionAt(object, x, y, z, direction);
}
