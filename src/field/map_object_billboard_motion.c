#include "field/map_object_billboard_motion.h"

#include "global.h"

#include "constants/scrcmd.h"
#include "constants/sprites.h"

#include "field/field_effect_helpers.h"
#include "field/field_effect_manager.h"
#include "field/field_follow_mon.h"
#include "field/map_object_model_list.h"
#include "field/map_object_models.h"
#include "field/map_object_render.h"

#include "billboard_lists.h"
#include "field_system.h"
#include "follow_mon.h"
#include "map_object.h"
#include "map_object_behavior_internal.h"
#include "map_object_movement_commands.h"
#include "map_object_movement_commands_internal.h"
#include "party.h"
#include "pokemon.h"
#include "script_pokemon_util.h"

// PlayerBillboardMotion_FishingBite: the rod bobs while a Pokemon bites
enum FishingBiteBillboardPhase {
    FISHING_BITE_PHASE_DIP,
    FISHING_BITE_PHASE_RISE,
    FISHING_BITE_PHASE_PAUSE,
};

typedef struct BillboardFrameSteps4 {
    fx32 values[4];
} BillboardFrameSteps4;

typedef struct BillboardFacingSequences {
    u32 values[4];
} BillboardFacingSequences;

typedef struct BillboardFrameSteps7 {
    fx32 values[7];
} BillboardFrameSteps7;

typedef struct BillboardFrameSteps8 {
    fx32 values[8];
} BillboardFrameSteps8;

// One sprite ID -> effect model offset entry of the table ending in MAP_OBJECT_GFX_ID_INVALID
typedef struct EffectModelOffset {
    u32 spriteId;
    VecFx32 offset;
} EffectModelOffset;

// The draw data of a billboard map object: the frame step of the stepped walk motions, the facing and animation
// drawn last, the billboard and its state while the object is paused
typedef struct BillboardDrawWork {
    s16 step;
    s8 facing;
    s8 movement;
    BillboardObject *billboard;
    BillboardState savedState;
} BillboardDrawWork;

// The draw data of the player's map object: the facing and animation drawn last, the frame step of the stepped
// walk motions (the tick counter while a Pokemon bites), whether the last frame was held, the fishing bite phase,
// the billboard and its state while the object is paused
typedef struct PlayerDrawWork {
    s8 facing;
    s8 step;
    s8 movement;
    u8 held : 1;
    u8 phase : 7;
    BillboardObject *billboard;
    BillboardState savedState;
} PlayerDrawWork;

// Billboard sequence callbacks: called with the map object, its billboard, the object's draw work and the facing
// direction.
typedef void (*BillboardMotionFunc)(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
typedef void (*PlayerBillboardMotionFunc)(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);

typedef struct LadderBillboardMotions {
    PlayerBillboardMotionFunc stand[1];
    PlayerBillboardMotionFunc walk[2];
} LadderBillboardMotions;

extern const EffectModelOffset gEffectModelOffsets[];

static void BillboardMotion_Stand(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_AnimateHalfSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_AnimateNormalSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_AnimateDoubleSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_AnimateQuadSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_WalkSlightlyFast(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_WalkSlightlyFaster(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_WalkEverSoSlightlyFast(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_PcWomanStand(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void BillboardMotion_PcWomanBow(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing);
static void PlayerBillboardMotion_Stand(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_AnimateHalfSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_AnimateNormalSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_AnimateDoubleSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_AnimateQuadSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_WalkSlightlyFast(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_WalkSlightlyFaster(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_WalkEverSoSlightlyFast(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_Run(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_CyclingStand(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_CyclingAnimateHalfSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_CyclingAnimateNormalSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_FishingIdle(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_FishingCast(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_FishingBite(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_FishingReel(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerDraw_SetFishingOffset(LocalMapObject *object, BillboardObject *billboard, u32 facing);
static void PlayerBillboardMotion_Ladder0(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerBillboardMotion_Ladder1(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerDraw_SetLadderOffset(LocalMapObject *object, BillboardObject *billboard, u32 facing);
static void PlayerBillboardMotion_ApricornShake(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing);
static void PlayerDraw_SetApricornShakeOffset(LocalMapObject *object, BillboardObject *billboard, u32 facing);
static void BillboardObject_AlignSequenceFrame(BillboardObject *billboard, int divisor);
static void BillboardObject_AlignSequenceFrameTo8(BillboardObject *billboard);
static void BillboardObject_SetSequenceKeepAlignedFrame(BillboardObject *billboard, u32 sequence, int divisor);
static void BillboardObject_SetSequenceKeepAlignedFrameTo8(BillboardObject *billboard, u32 sequence);
static void MapObject_UpdateBillboardVisibility(LocalMapObject *object, BillboardObject *billboard);
static void MapObject_GetEffectModelOffset(u32 spriteId, VecFx32 *offset);

static const LadderBillboardMotions sPlayerApricornLadderBillboardMotions = {
    .stand = {
              PlayerBillboardMotion_ApricornShake,
              },
    .walk = {
              PlayerBillboardMotion_Ladder0,
              PlayerBillboardMotion_Ladder1,
              },
};

static const BillboardFrameSteps4 sWalkSlightlyFasterFrameSteps = {
    .values = { FX32_CONST(3), FX32_CONST(2), FX32_CONST(3), 0 },
};

static const u32 sPlayerFishingSequences[4] = { 0, 1, 2, 3 };

static const PlayerBillboardMotionFunc sPlayerFishingBillboardMotions[4] = {
    PlayerBillboardMotion_FishingIdle,
    PlayerBillboardMotion_FishingCast,
    PlayerBillboardMotion_FishingBite,
    PlayerBillboardMotion_FishingReel,
};

static const u32 sPlayerLadderSequences[4] = { 0, 1, 2, 3 };

static const u32 sPlayerApricornShakeSequences[4] = { 0, 1, 2, 3 };

static const BillboardFrameSteps4 sPlayerWalkSlightlyFasterFrameSteps = {
    .values = { FX32_CONST(3), FX32_CONST(2), FX32_CONST(3), 0 },
};

static const BillboardFacingSequences sPlayerCyclingStandSequences = {
    .values = { 6, 7, 8, 9 },
};

static const BillboardFrameSteps7 sWalkSlightlyFastFrameSteps = {
    .values = { FX32_ONE, FX32_ONE, FX32_CONST(2), FX32_ONE, FX32_ONE, FX32_CONST(2), 0 },
};

static const BillboardFrameSteps7 sPlayerWalkSlightlyFastFrameSteps = {
    .values = { FX32_ONE, FX32_ONE, FX32_CONST(2), FX32_ONE, FX32_ONE, FX32_CONST(2), 0 },
};

static const BillboardFrameSteps8 sWalkEverSoSlightlyFastFrameSteps = {
    .values = { FX32_CONST(2), FX32_ONE, FX32_ONE, FX32_ONE, FX32_ONE, FX32_ONE, FX32_ONE, 0 },
};

static const BillboardFrameSteps8 sPlayerWalkEverSoSlightlyFastFrameSteps = {
    .values = { FX32_CONST(2), FX32_ONE, FX32_ONE, FX32_ONE, FX32_ONE, FX32_ONE, FX32_ONE, 0 },
};

static const BillboardMotionFunc sNpcBillboardMotions[9] = {
    BillboardMotion_Stand,
    BillboardMotion_AnimateHalfSpeed,
    BillboardMotion_AnimateHalfSpeed,
    BillboardMotion_AnimateNormalSpeed,
    BillboardMotion_AnimateDoubleSpeed,
    BillboardMotion_AnimateQuadSpeed,
    BillboardMotion_WalkSlightlyFast,
    BillboardMotion_WalkSlightlyFaster,
    BillboardMotion_WalkEverSoSlightlyFast,
};

static const PlayerBillboardMotionFunc sPlayerCyclingBillboardMotions[10] = {
    PlayerBillboardMotion_CyclingStand,
    PlayerBillboardMotion_AnimateHalfSpeed,
    PlayerBillboardMotion_AnimateHalfSpeed,
    PlayerBillboardMotion_AnimateNormalSpeed,
    PlayerBillboardMotion_AnimateDoubleSpeed,
    PlayerBillboardMotion_WalkSlightlyFast,
    PlayerBillboardMotion_WalkSlightlyFast,
    PlayerBillboardMotion_WalkSlightlyFast,
    PlayerBillboardMotion_CyclingAnimateHalfSpeed,
    PlayerBillboardMotion_CyclingAnimateNormalSpeed,
};

static const BillboardMotionFunc sPcWomanBillboardMotions[10] = {
    BillboardMotion_PcWomanStand,
    BillboardMotion_AnimateHalfSpeed,
    BillboardMotion_AnimateHalfSpeed,
    BillboardMotion_AnimateNormalSpeed,
    BillboardMotion_AnimateDoubleSpeed,
    BillboardMotion_AnimateQuadSpeed,
    BillboardMotion_WalkSlightlyFast,
    BillboardMotion_WalkSlightlyFaster,
    BillboardMotion_WalkEverSoSlightlyFast,
    BillboardMotion_PcWomanBow,
};

static const PlayerBillboardMotionFunc sPlayerWalkingBillboardMotions[10] = {
    PlayerBillboardMotion_Stand,
    PlayerBillboardMotion_AnimateHalfSpeed,
    PlayerBillboardMotion_AnimateHalfSpeed,
    PlayerBillboardMotion_AnimateNormalSpeed,
    PlayerBillboardMotion_AnimateDoubleSpeed,
    PlayerBillboardMotion_AnimateQuadSpeed,
    PlayerBillboardMotion_WalkSlightlyFast,
    PlayerBillboardMotion_WalkSlightlyFaster,
    PlayerBillboardMotion_WalkEverSoSlightlyFast,
    PlayerBillboardMotion_Run,
};

static inline void BillboardMotion_Loop(BillboardObject *billboard, const PlayerDrawWork *work, int facing, int movement, const u32 *sequences) {
    if (facing != work->facing || work->movement != movement) {
        BillboardObject_SetSequence(billboard, sequences[facing]);
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    BillboardObject_AdvanceFrame(billboard, FX32_ONE);
}

static inline void BillboardMotion_Fall(BillboardObject *billboard, const PlayerDrawWork *work, int facing, int movement) {
    fx32 frame;
    if (facing != work->facing || work->movement != movement) {
        BillboardObject_SetSequence(billboard, sPlayerFishingSequences[facing]);
        BillboardObject_SetSequenceFrame(billboard, 15 * FX32_ONE);
    }
    frame = BillboardObject_GetSequenceFrame(billboard) - FX32_ONE;
    if (frame < 0) {
        frame = 0;
    }
    BillboardObject_SetSequenceFrame(billboard, frame);
    BillboardObject_AdvanceFrame(billboard, 0);
}

static inline void BillboardMotion_Walk(LocalMapObject *object, BillboardObject *billboard, const PlayerDrawWork *work, int facing, fx32 speed) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (work->movement == MAP_OBJECT_ANIM_RUN) {
        BillboardObject_SetSequenceKeepAlignedFrameTo8(billboard, Facing_GetBillboardStandSequence(facing));
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, speed);
    }
}

BillboardObject *MapObject_GetBillboard(LocalMapObject *object) {
    int spriteId = MapObject_GetSpriteID(object);

    switch (spriteId) {
    case SPRITE_HERO:
    case SPRITE_CYCLEHERO:
    case SPRITE_HEROINE:
    case SPRITE_CYCLEHEROINE:
    case SPRITE_SPHERO:
    case SPRITE_SPHEROINE:
    case SPRITE_SWIMHERO:
    case SPRITE_SWIMHEROINE:
    case SPRITE_WATERHERO:
    case SPRITE_WATERHEROINE:
    case SPRITE_FISHINGHERO:
    case SPRITE_FISH_HEROINE:
    case SPRITE_POKEHERO:
    case SPRITE_POKEHEROINE:
    case SPRITE_SAVEHERO:
    case SPRITE_SAVEHEROINE:
    case SPRITE_BANZAIHERO:
    case SPRITE_BANZAIHEROINE:
    case SPRITE_LADDERHERO:
    case SPRITE_LADDERHEROINE:
    case SPRITE_RHERO:
    case SPRITE_RHEROINE:
    case SPRITE_RBANZAIHERO:
    case SPRITE_RBANZAIINE:
        return ((PlayerDrawWork *)MapObject_GetDrawData(object))->billboard;
    }

    if (spriteId >= SPRITE_FOLLOWER_MON_BULBASAUR && spriteId <= SPRITE_FOLLOWER_MON_ARCEUS_DARK) {
        return ((FollowMonBillboardWork *)MapObject_GetDrawData(object))->billboard;
    }
    if (spriteId >= SPRITE_BONGURI && spriteId <= SPRITE_BONGURI_BK) {
        return ApricornTreeObject_GetBillboard(object);
    }
    return ((BillboardDrawWork *)MapObject_GetDrawData(object))->billboard;
}

void BillboardDraw_Init(LocalMapObject *object) {
    BillboardDrawWork *work = MapObject_InitDrawData(object, sizeof(BillboardDrawWork));
    work->facing = -1;
    MapObject_CreateBillboard(object, &work->billboard);
    if (work->billboard != NULL) {
        MapObject_CallDrawUpdate(object);
    }
}

void BillboardDraw_Delete(LocalMapObject *object) {
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    MapObject_DeleteBillboard(object, &work->billboard);
}

void BillboardDraw_Pause(LocalMapObject *object) {
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    if (billboard != NULL) {
        BillboardObject_SaveState(billboard, &work->savedState);
    }
    MapObject_DeleteBillboard(object, &work->billboard);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK21);
}

void BillboardDraw_Resume(LocalMapObject *object) {
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    if (MapObject_IsBillboardPending(object) != TRUE) {
        if (work->billboard == NULL) {
            MapObject_CreateBillboard(object, &work->billboard);
        }
        if (work->billboard != NULL) {
            BillboardObject_RestoreState(work->billboard, &work->savedState);
            MapObject_UpdateBillboardPosition(object, work->billboard);
            MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK21);
        }
    }
}

void FollowMonDraw_Init(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_InitDrawData(object, sizeof(FollowMonBillboardWork));
    work->direction = -1;
    MapObject_CreateBillboard(object, &work->billboard);
    work->bobbing = 0;
    work->spriteLoaded = FALSE;
    work->paletteApplied = FALSE;
    if (work->billboard != NULL) {
        MapObject_CallDrawUpdate(object);
    }
}

void FollowMonDraw_Delete(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    MapObject_DeleteBillboard(object, &work->billboard);
}

void FollowMonDraw_Pause(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    if (billboard != NULL) {
        BillboardObject_SaveState(billboard, &work->savedState);
    }
    work->spriteLoaded = FALSE;
    work->paletteApplied = FALSE;
    MapObject_DeleteBillboard(object, &work->billboard);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK21);
}

// Draw callback of the following Pokemon: (re)loads the party leader's overworld sprite on first use.
void FollowMonDraw_Resume(LocalMapObject *object) {
    VecFx32 pos;
    VecFx32 facing;
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    if (!work->spriteLoaded && MapObject_GetID(object) == obj_partner_poke) {
        FieldSystem *fieldSystem = MapObjectManager_GetFieldSystem(MapObject_GetManager(object));
        Pokemon *mon = GetFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(fieldSystem->saveData));
        u32 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        u32 form = GetMonData(mon, MON_DATA_FORM, NULL);
        u8 gender = GetMonGender(mon);
        u32 spriteId = FollowMon_GetSpriteID(species, form, gender);
        u8 shiny = MonIsShiny(mon);
        int x, y, z;
        work->spriteLoaded = TRUE;
        FollowMon_SetObjectParams(object, species, form, (u32)shiny);
        MapObject_SetSpriteID(object, spriteId);
        MapObject_RestoreDrawUpdateCallback(object);
        MapObject_SetFlagsBits(object, MAPOBJECTFLAG_START_MOVEMENT);
        MapObject_CopyPositionVector(object, &pos);
        x = MapObject_GetXCoord(object);
        pos.x = FX32_CONST(16) * x + FX32_CONST(8);
        MapObject_SetPreviousX(object, x);
        y = MapObject_GetYCoord(object);
        MapObject_SetPreviousY(object, y);
        z = MapObject_GetZCoord(object);
        pos.z = FX32_CONST(16) * z + FX32_CONST(8);
        MapObject_SetPreviousZ(object, z);
        MapObject_SetPositionVector(object, &pos);
        MapObject_ClearHeldMovement(object);
        if (fieldSystem->followMon.species != species || fieldSystem->followMon.form != form || fieldSystem->followMon.shiny != shiny || fieldSystem->followMon.gender != gender) {
            FieldSystem_SetFollowerPokeParam(fieldSystem, species, form, shiny, gender);
            MapObject_SetFacingDirectionDirect(object, DIR_SOUTH);
        }
        FollowMonMood_SetMon(fieldSystem->followMonMood, mon, species, GetMonData(mon, MON_DATA_PERSONALITY, NULL));
    }
    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    if (work->billboard == NULL) {
        MapObject_CreateBillboard(object, &work->billboard);
    }
    if (work->billboard != NULL) {
        work->paletteApplied = TRUE;
        {
            VecFx32 offset = { 0, 0, 0 };
            MapObject_CopyFacingVector(object, &facing);
            MapObject_GetSpriteID(object);
            FollowMonBillboard_AddFacingOffset(object, MapObject_GetFacingDirection(object), &offset);
            facing.x = offset.x;
            facing.z = offset.z;
            MapObject_SetFacingVector(object, &facing);
            if (MapObject_HasFollowMonSprite(object)) {
                MapObject_SetBillboardSepia(TRUE, object, work->billboard);
            } else if (MapObject_IsShinyPokemon(object)) {
                FollowMonBillboard_SetResource(TRUE, object, work->billboard);
            }
            BillboardObject_RestoreState(work->billboard, &work->savedState);
            MapObject_UpdateBillboardPosition(object, work->billboard);
            MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK21);
            MapObject_CallDrawUpdate(object);
        }
    }
}

void FollowMonDraw_ClearBob(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    work->bobbing = 0;
    MapObject_GetFacingVector(object)->y = 0;
}

BillboardObject *MapObjectManager_GetFollowMonBillboard(MapObjectManager *manager) {
    return ((FollowMonBillboardWork *)MapObject_GetDrawData(MapObjectManager_GetFirstActiveObjectByID(manager, obj_partner_poke)))->billboard;
}

void BillboardDraw_UpdateNpc(LocalMapObject *object) {
    u32 facing;
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    int movement;
    if (MapObject_IsBillboardPending(object) == TRUE || billboard == NULL) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    movement = MapObject_GetAnimation(object);
    GF_ASSERT(movement < 9);
    sNpcBillboardMotions[movement](object, billboard, work, facing);
    MapObject_GetFacingVector(object)->z = FX32_CONST(0.5);
    work->facing = facing;
    work->movement = MapObject_GetAnimation(object);
    MapObject_UpdateBillboardPosition(object, billboard);
    MapObject_UpdateBillboardVisibility(object, billboard);
}

void BillboardDraw_UpdatePositionOnly(LocalMapObject *object) {
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    if (MapObject_IsBillboardPending(object) != TRUE) {
        BillboardObject *billboard = work->billboard;
        if (billboard != NULL) {
            MapObject_UpdateBillboardPosition(object, billboard);
            MapObject_UpdateBillboardVisibility(object, billboard);
        }
    }
}

void BillboardDraw_UpdateLooping(LocalMapObject *object) {
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    if (MapObject_IsBillboardPending(object) != TRUE) {
        BillboardObject *billboard = work->billboard;
        if (billboard != NULL) {
            if (!MapObject_IsBillboardAnimPaused(object)) {
                BillboardObject_AdvanceFrame(billboard, FX32_ONE);
            }
            MapObject_UpdateBillboardPosition(object, billboard);
            MapObject_UpdateBillboardVisibility(object, billboard);
        }
    }
}

void FollowMonDraw_UpdateLarge(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    BillboardObject *sprite = work->billboard;
    u32 direction;

    if (MapObject_IsBillboardPending(object) == TRUE || sprite == NULL) {
        return;
    }
    if (!work->paletteApplied) {
        work->paletteApplied = TRUE;
        if (MapObject_HasFollowMonSprite(object)) {
            MapObject_SetBillboardSepia(TRUE, object, work->billboard);
        } else if (MapObject_IsShinyPokemon(object)) {
            FollowMonBillboard_SetResource(TRUE, object, sprite);
        }
    }
    direction = MapObject_GetFacingDirection(object);
    FollowMonBillboard_Update(object, sprite, work, direction, TRUE);
    work->direction = direction;
    MapObject_UpdateBillboardPosition(object, sprite);
    MapObject_UpdateBillboardVisibility(object, sprite);
}

void FollowMonDraw_Update(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    BillboardObject *sprite = work->billboard;
    u32 direction;

    if (MapObject_IsBillboardPending(object) == TRUE || sprite == NULL) {
        return;
    }
    if (!work->paletteApplied) {
        work->paletteApplied = TRUE;
        if (MapObject_HasFollowMonSprite(object)) {
            MapObject_SetBillboardSepia(TRUE, object, work->billboard);
        } else if (MapObject_IsShinyPokemon(object)) {
            FollowMonBillboard_SetResource(TRUE, object, sprite);
        }
    }
    direction = MapObject_GetFacingDirection(object);
    FollowMonBillboard_Update(object, sprite, work, direction, TRUE);
    work->direction = direction;
    MapObject_UpdateBillboardPosition(object, sprite);
    MapObject_UpdateBillboardVisibility(object, sprite);
}

void FollowMonDraw_UpdatePositionOnly(LocalMapObject *object) {
    FollowMonBillboardWork *work = MapObject_GetDrawData(object);
    BillboardObject *sprite;

    if (MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    sprite = work->billboard;
    if (sprite == NULL) {
        return;
    }
    if (!work->paletteApplied) {
        work->paletteApplied = TRUE;
        if (MapObject_IsShinyPokemon(object)) {
            FollowMonBillboard_SetResource(TRUE, object, sprite);
        }
    }
    MapObject_UpdateBillboardPosition(object, sprite);
    MapObject_UpdateBillboardVisibility(object, sprite);
}

static void BillboardMotion_Stand(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else {
        BillboardObject_AlignSequenceFrameTo8(billboard);
    }
    BillboardObject_AdvanceFrame(billboard, 0);
}

static void BillboardMotion_AnimateHalfSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, FX32_CONST(0.5));
    }
}

static void BillboardMotion_AnimateNormalSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    }
}

static void BillboardMotion_AnimateDoubleSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, 2 * FX32_ONE);
    }
}

static void BillboardMotion_AnimateQuadSpeed(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, 4 * FX32_ONE);
    }
}

static void BillboardMotion_WalkSlightlyFast(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->step = 0;
    }
    if (work->movement != MAP_OBJECT_ANIM_WALK_SLIGHTLY_FAST) {
        work->step = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardFrameSteps7 steps = sWalkSlightlyFastFrameSteps;
        BillboardObject_AdvanceFrame(billboard, steps.values[work->step]);
        work->step++;
        if (steps.values[work->step] == 0) {
            work->step = 0;
        }
    }
}

static void BillboardMotion_WalkSlightlyFaster(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->step = 0;
    }
    if (work->movement != MAP_OBJECT_ANIM_WALK_SLIGHTLY_FASTER) {
        work->step = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardFrameSteps4 steps = sWalkSlightlyFasterFrameSteps;
        BillboardObject_AdvanceFrame(billboard, steps.values[work->step]);
        work->step++;
        if (steps.values[work->step] == 0) {
            work->step = 0;
        }
    }
}

static void BillboardMotion_WalkEverSoSlightlyFast(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->step = 0;
    }
    if (work->movement != MAP_OBJECT_ANIM_WALK_EVER_SO_SLIGHTLY_FAST) {
        work->step = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardFrameSteps8 steps = sWalkEverSoSlightlyFastFrameSteps;
        BillboardObject_AdvanceFrame(billboard, steps.values[work->step]);
        work->step++;
        if (steps.values[work->step] == 0) {
            work->step = 0;
        }
    }
}

void BillboardDraw_UpdatePcWoman(LocalMapObject *object) {
    u32 facing;
    BillboardDrawWork *work;
    int movement;
    BillboardObject *billboard;
    work = MapObject_GetDrawData(object);
    billboard = work->billboard;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        facing = MapObject_GetFacingDirection(object);
        movement = MapObject_GetAnimation(object);
        GF_ASSERT(movement < 10);
        sPcWomanBillboardMotions[movement](object, billboard, work, facing);
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

static void BillboardMotion_PcWomanStand(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (facing != work->facing || work->movement == MAP_OBJECT_ANIM_NURSE_BOW) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else {
        BillboardObject_AlignSequenceFrameTo8(billboard);
    }
    BillboardObject_AdvanceFrame(billboard, 0);
}

static void BillboardMotion_PcWomanBow(LocalMapObject *object, BillboardObject *billboard, BillboardDrawWork *work, u32 facing) {
    if (work->movement != MAP_OBJECT_ANIM_NURSE_BOW) {
        BillboardObject_SetSequence(billboard, 4);
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    BillboardObject_AdvanceFrame(billboard, FX32_ONE);
}

void BillboardDraw_UpdateTwoSequences(LocalMapObject *object) {
    u32 facing;
    BillboardDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    int sequence;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        facing = MapObject_GetFacingDirection(object);
        if (MapObject_GetAnimation(object) == 0) {
            sequence = facing > 1 ? 1 : 0;
            if (sequence != BillboardObject_GetSequence(billboard) || work->movement == 0) {
                BillboardObject_SetSequence(billboard, sequence);
                BillboardObject_SetSequenceFrame(billboard, 0);
                BillboardObject_AdvanceFrame(billboard, 0);
            }
            BillboardObject_AdvanceFrame(billboard, 0);
        } else {
            int other = facing > 1 ? 1 : 0;
            if (other != BillboardObject_GetSequence(billboard)) {
                BillboardObject_SetSequence(billboard, other);
                BillboardObject_SetSequenceFrame(billboard, 0);
            }
            BillboardObject_AdvanceFrame(billboard, FX32_ONE);
        }
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

void PlayerDraw_Init(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_InitDrawData(object, sizeof(PlayerDrawWork));
    work->facing = -1;
    MapObject_CreateBillboard(object, &work->billboard);
    if (work->billboard != NULL) {
        MapObject_CallDrawUpdate(object);
    }
}

void PlayerDraw_Delete(LocalMapObject *object) {
    VecFx32 offset = { 0, 0, 0 };
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    MapObject_DeleteBillboard(object, &work->billboard);
    MapObject_SetFacingVector(object, &offset);
}

void PlayerDraw_Pause(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    if (billboard != NULL) {
        BillboardObject_SaveState(billboard, &work->savedState);
    }
    MapObject_DeleteBillboard(object, &work->billboard);
    MapObject_SetFlagsBits(object, MAPOBJECTFLAG_UNK21);
}

void PlayerDraw_Resume(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    if (MapObject_IsBillboardPending(object) != TRUE) {
        if (work->billboard == NULL) {
            MapObject_CreateBillboard(object, &work->billboard);
        }
        if (work->billboard != NULL) {
            BillboardObject_RestoreState(work->billboard, &work->savedState);
            MapObject_UpdateBillboardPosition(object, work->billboard);
            MapObject_ClearFlagsBits(object, MAPOBJECTFLAG_UNK21);
        }
    }
}

void PlayerDraw_UpdateWalking(LocalMapObject *object) {
    u32 facing;
    int movement;
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;

    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        facing = MapObject_GetFacingDirection(object);
        movement = MapObject_GetAnimation(object);
        GF_ASSERT(movement < 10);
        sPlayerWalkingBillboardMotions[movement](object, billboard, work, facing);
        MapObject_GetFacingVector(object)->z = FX32_CONST(0.5);
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

static void PlayerBillboardMotion_Stand(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
#pragma unused(object)
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->held = 0;
        return;
    }
    if (work->movement == MAP_OBJECT_ANIM_RUN) {
        work->held = 1;
        return;
    }
    if (work->held == 1) {
        BillboardObject_SetSequenceKeepAlignedFrameTo8(billboard, Facing_GetBillboardStandSequence(facing));
        work->held = 0;
        return;
    }
    BillboardObject_AlignSequenceFrameTo8(billboard);
}

static void PlayerBillboardMotion_AnimateHalfSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (work->movement == MAP_OBJECT_ANIM_RUN) {
        work->held = 1;
        return;
    } else if (work->held == 1) {
        BillboardObject_SetSequenceKeepAlignedFrameTo8(billboard, Facing_GetBillboardStandSequence(facing));
        work->held = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, FX32_CONST(0.5));
    }
}

static void PlayerBillboardMotion_AnimateNormalSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Walk(object, billboard, work, facing, FX32_ONE);
}

static void PlayerBillboardMotion_AnimateDoubleSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Walk(object, billboard, work, facing, 2 * FX32_ONE);
}

static void PlayerBillboardMotion_AnimateQuadSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Walk(object, billboard, work, facing, 4 * FX32_ONE);
}

static void PlayerBillboardMotion_WalkSlightlyFast(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->step = 0;
    } else if (work->movement == MAP_OBJECT_ANIM_RUN) {
        BillboardObject_SetSequenceKeepAlignedFrameTo8(billboard, Facing_GetBillboardStandSequence(facing));
    }
    if (work->movement != MAP_OBJECT_ANIM_WALK_SLIGHTLY_FAST) {
        work->step = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardFrameSteps7 steps = sPlayerWalkSlightlyFastFrameSteps;
        BillboardObject_AdvanceFrame(billboard, steps.values[work->step]);
        work->step++;
        if (steps.values[work->step] == 0) {
            work->step = 0;
        }
    }
}

static void PlayerBillboardMotion_WalkSlightlyFaster(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->step = 0;
    } else if (work->movement == MAP_OBJECT_ANIM_RUN) {
        BillboardObject_SetSequenceKeepAlignedFrameTo8(billboard, Facing_GetBillboardStandSequence(facing));
    }
    if (work->movement != MAP_OBJECT_ANIM_WALK_SLIGHTLY_FASTER) {
        work->step = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardFrameSteps4 steps = sPlayerWalkSlightlyFasterFrameSteps;
        BillboardObject_AdvanceFrame(billboard, steps.values[work->step]);
        work->step++;
        if (steps.values[work->step] == 0) {
            work->step = 0;
        }
    }
}

static void PlayerBillboardMotion_WalkEverSoSlightlyFast(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->step = 0;
    } else if (work->movement == MAP_OBJECT_ANIM_RUN) {
        BillboardObject_SetSequenceKeepAlignedFrameTo8(billboard, Facing_GetBillboardStandSequence(facing));
    }
    if (work->movement != MAP_OBJECT_ANIM_WALK_EVER_SO_SLIGHTLY_FAST) {
        work->step = 0;
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardFrameSteps8 steps = sPlayerWalkEverSoSlightlyFastFrameSteps;
        BillboardObject_AdvanceFrame(billboard, steps.values[work->step]);
        work->step++;
        if (steps.values[work->step] == 0) {
            work->step = 0;
        }
    }
}

static void PlayerBillboardMotion_Run(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, Facing_GetBillboardWalkSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (work->movement != MAP_OBJECT_ANIM_RUN) {
        BillboardObject_SetSequenceKeepAlignedFrame(billboard, Facing_GetBillboardWalkSequence(facing), 4);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    }
}

void PlayerDraw_UpdateCycling(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    int facing, movement;
    BillboardObject *billboard = work->billboard;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        facing = MapObject_GetFacingDirection(object);
        movement = MapObject_GetAnimation(object);
        GF_ASSERT(movement < 12);
        if (work->movement == MAP_OBJECT_ANIM_STAND && movement != work->movement && work->held == 0) {
            work->facing = -1;
        }
        sPlayerCyclingBillboardMotions[movement](object, billboard, work, facing);
        work->facing = facing;
        work->movement = movement;
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

static void PlayerBillboardMotion_CyclingStand(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardFacingSequences sequences = sPlayerCyclingStandSequences;
    int sequence;
    sequence = sequences.values[facing];
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->held = 0;
    } else if (work->movement) {
        work->held = 1;
    } else if (work->held == 1) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
        work->held = 0;
    } else {
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    }
}

static void PlayerBillboardMotion_CyclingAnimateHalfSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    u32 sequence = MapObjectRender_GetFacingSequence(facing);
    if (facing != work->facing || work->movement != MAP_OBJECT_ANIM_STAND) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (work->movement != MAP_OBJECT_ANIM_JUMP_NEAR_SLOW) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (BillboardObject_GetSequence(billboard) != sequence) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, FX32_CONST(0.5));
    }
}

static void PlayerBillboardMotion_CyclingAnimateNormalSpeed(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    u32 sequence = MapObjectRender_GetFacingSequence(facing);
    if (facing != work->facing) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (work->movement != MAP_OBJECT_ANIM_JUMP_FARTHER) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
    } else if (BillboardObject_GetSequence(billboard) != sequence) {
        BillboardObject_SetSequence(billboard, sequence);
        BillboardObject_SetSequenceFrame(billboard, 0);
    }
    if (!MapObject_IsBillboardAnimPaused(object)) {
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    }
}

void PlayerDraw_UpdateFishing(LocalMapObject *object) {
    u32 facing;
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    int movement;
    if (billboard == NULL || MapObject_IsBillboardPending(object) == TRUE) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    movement = MapObject_GetAnimation(object);
    GF_ASSERT(movement < 4);
    sPlayerFishingBillboardMotions[movement](object, billboard, work, facing);
    PlayerDraw_SetFishingOffset(object, billboard, facing);
    work->facing = facing;
    work->movement = MapObject_GetAnimation(object);
    MapObject_UpdateBillboardPosition(object, billboard);
    MapObject_UpdateBillboardVisibility(object, billboard);
}

static void PlayerBillboardMotion_FishingIdle(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Fall(billboard, work, facing, 0);
}

static void PlayerBillboardMotion_FishingCast(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Loop(billboard, work, facing, 1, sPlayerFishingSequences);
}

static void PlayerBillboardMotion_FishingBite(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    int frame;
    if (facing != work->facing || work->movement != 2) {
        BillboardObject_SetSequence(billboard, sPlayerFishingSequences[facing]);
        BillboardObject_SetSequenceFrame(billboard, 15 * FX32_ONE);
        work->phase = FISHING_BITE_PHASE_DIP;
    }
    frame = BillboardObject_GetSequenceFrame(billboard);
    switch (work->phase) {
    case FISHING_BITE_PHASE_DIP:
        frame -= FX32_ONE;
        if (frame <= 10 * FX32_ONE) {
            work->phase = (u8)(work->phase + 1);
        }
        break;
    case FISHING_BITE_PHASE_RISE:
        frame += FX32_ONE;
        if (frame >= 15 * FX32_ONE) {
            work->phase = (u8)(work->phase + 1);
            work->step = 0;
        }
        break;
    case FISHING_BITE_PHASE_PAUSE:
        work->step++;
        if (work->step >= 30) {
            work->step = 0;
            work->phase = FISHING_BITE_PHASE_DIP;
        }
        break;
    }
    BillboardObject_SetSequenceFrame(billboard, frame);
    BillboardObject_AdvanceFrame(billboard, 0);
}

static void PlayerBillboardMotion_FishingReel(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Fall(billboard, work, facing, 3);
}

static void PlayerDraw_SetFishingOffset(LocalMapObject *object, BillboardObject *billboard, u32 facing) {
    VecFx32 offset = { 0, 0, 0 };
    int frame = BillboardObject_GetFrame(billboard) / FX32_ONE;
    switch (facing) {
    case DIR_NORTH:
        break;
    case DIR_SOUTH:
        if (frame >= 24) {
            offset.z = 6 * FX32_ONE;
        }
        break;
    case DIR_WEST:
        if (frame < 40) {
            offset.x = FX32_ONE;
        } else {
            offset.x = -5 * FX32_ONE;
        }
        break;
    case DIR_EAST:
        if (frame < 56) {
            offset.x = -FX32_ONE;
        } else {
            offset.x = 5 * FX32_ONE;
        }
        break;
    }
    offset.z += FX32_CONST(0.5);
    MapObject_SetFacingVector(object, &offset);
}

void PlayerDraw_UpdateLadder(LocalMapObject *object) {
    u32 facing;
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    int movement;
    PlayerBillboardMotionFunc func;
    if (billboard != NULL && MapObject_IsBillboardPending(object) != TRUE) {
        facing = MapObject_GetFacingDirection(object);
        movement = MapObject_GetAnimation(object);
        GF_ASSERT(movement < 2);
        func = sPlayerApricornLadderBillboardMotions.walk[movement];
        func(object, billboard, work, facing);
        PlayerDraw_SetLadderOffset(object, billboard, facing);
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

static void PlayerBillboardMotion_Ladder0(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Loop(billboard, work, facing, 0, sPlayerLadderSequences);
}

static void PlayerBillboardMotion_Ladder1(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Loop(billboard, work, facing, 1, sPlayerLadderSequences);
}

static void PlayerDraw_SetLadderOffset(LocalMapObject *object, BillboardObject *billboard, u32 facing) {
    VecFx32 offset = { 0, 0, 0 };
    int frame = BillboardObject_GetFrame(billboard) / FX32_ONE;
    switch (facing) {
    case DIR_NORTH:
        break;
    case DIR_SOUTH:
        if (frame >= 24) {
            offset.z = 6 * FX32_ONE;
        }
        break;
    case DIR_WEST:
        if (frame < 40) {
            offset.x = FX32_ONE;
        } else {
            offset.x = -5 * FX32_ONE;
        }
        break;
    case DIR_EAST:
        if (frame < 56) {
            offset.x = -FX32_ONE;
        } else {
            offset.x = 5 * FX32_ONE;
        }
        break;
    }
    MapObject_SetFacingVector(object, &offset);
}

void PlayerDraw_UpdateSurfing(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    u32 facing;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        facing = MapObject_GetFacingDirection(object);
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
        BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
        BillboardObject_SetSequenceFrame(billboard, 0);
        BillboardObject_AdvanceFrame(billboard, 0);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

void PlayerDraw_UpdateUseHmOrSaving(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        work->facing = MapObject_GetFacingDirection(object);
        work->movement = MapObject_GetAnimation(object);
        if (BillboardObject_GetSequence(billboard)) {
            BillboardObject_SetSequence(billboard, 0);
            BillboardObject_SetSequenceFrame(billboard, 0);
        }
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
        MapObject_GetFacingVector(object)->z = FX32_CONST(0.5);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

void PlayerDraw_UpdateWatering(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    u32 facing;
    if (MapObject_IsBillboardPending(object) == TRUE || billboard == NULL) {
        return;
    }
    facing = MapObject_GetFacingDirection(object);
    if (MapObject_GetAnimation(object) == 0) {
        if (BillboardObject_GetSequence(billboard) != 1) {
            BillboardObject_SetSequence(billboard, 1);
            BillboardObject_SetSequenceFrame(billboard, 0);
        }
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    } else {
        if (BillboardObject_GetSequence(billboard) != 0) {
            BillboardObject_SetSequence(billboard, 0);
            BillboardObject_SetSequenceFrame(billboard, 0);
        }
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
    }
    work->facing = facing;
    work->movement = MapObject_GetAnimation(object);
    MapObject_UpdateBillboardPosition(object, billboard);
    MapObject_UpdateBillboardVisibility(object, billboard);
}

void PlayerDraw_UpdatePoketch(LocalMapObject *object) {
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    u32 facing;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard != NULL) {
        facing = MapObject_GetFacingDirection(object);
        if (facing != work->facing) {
            BillboardObject_SetSequence(billboard, Facing_GetBillboardStandSequence(facing));
            BillboardObject_SetSequenceFrame(billboard, 0);
        }
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
    }
}

void PlayerDraw_UpdateHeal(LocalMapObject *object) {
    int movement;
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    if (MapObject_IsBillboardPending(object) != TRUE && billboard) {
        u32 facing = MapObject_GetFacingDirection(object);
        movement = MapObject_GetAnimation(object);
        if (movement != work->movement) {
            if (movement == 0) {
                BillboardObject_SetSequence(billboard, 0);
            } else {
                BillboardObject_SetSequence(billboard, 1);
            }
            BillboardObject_SetSequenceFrame(billboard, 0);
        }
        BillboardObject_AdvanceFrame(billboard, FX32_ONE);
        MapObject_GetFacingVector(object)->z = FX32_CONST(0.5);
        work->facing = facing;
        work->movement = movement;
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

void PlayerDraw_UpdateApricornShake(LocalMapObject *object) {
    u32 facing;
    PlayerDrawWork *work = MapObject_GetDrawData(object);
    BillboardObject *billboard = work->billboard;
    if (billboard && MapObject_IsBillboardPending(object) != TRUE) {
        facing = MapObject_GetFacingDirection(object);
        int movement = MapObject_GetAnimation(object);
        GF_ASSERT(movement < 1);
        sPlayerApricornLadderBillboardMotions.stand[movement](object, billboard, work, facing);
        PlayerDraw_SetApricornShakeOffset(object, billboard, facing);
        work->facing = facing;
        work->movement = MapObject_GetAnimation(object);
        MapObject_UpdateBillboardPosition(object, billboard);
        MapObject_UpdateBillboardVisibility(object, billboard);
    }
}

static void PlayerBillboardMotion_ApricornShake(LocalMapObject *object, BillboardObject *billboard, PlayerDrawWork *work, u32 facing) {
    BillboardMotion_Loop(billboard, work, facing, 0, sPlayerApricornShakeSequences);
}

static void PlayerDraw_SetApricornShakeOffset(LocalMapObject *object, BillboardObject *billboard, u32 facing) {
#pragma unused(billboard, facing)
    VecFx32 offset = { 0, 0, 0 };
    offset.z += FX32_CONST(0.5);
    MapObject_SetFacingVector(object, &offset);
}

// Rounds the sequence frame down to a multiple of divisor frames
static void BillboardObject_AlignSequenceFrame(BillboardObject *billboard, int divisor) {
    s32 frame = BillboardObject_GetSequenceFrame(billboard) / FX32_ONE;
    BillboardObject_SetSequenceFrame(billboard, (frame - frame % divisor) * FX32_ONE);
    BillboardObject_AdvanceFrame(billboard, 0);
}

static void BillboardObject_AlignSequenceFrameTo8(BillboardObject *billboard) {
    BillboardObject_AlignSequenceFrame(billboard, 8);
}

static void BillboardObject_SetSequenceKeepAlignedFrame(BillboardObject *billboard, u32 sequence, int divisor) {
    fx32 frame;
    BillboardObject_AlignSequenceFrame(billboard, divisor);
    frame = BillboardObject_GetSequenceFrame(billboard);
    BillboardObject_SetSequence(billboard, sequence);
    BillboardObject_SetSequenceFrame(billboard, frame);
}

static void BillboardObject_SetSequenceKeepAlignedFrameTo8(BillboardObject *billboard, u32 sequence) {
    fx32 frame;
    BillboardObject_AlignSequenceFrameTo8(billboard);
    frame = BillboardObject_GetSequenceFrame(billboard);
    BillboardObject_SetSequence(billboard, sequence);
    BillboardObject_SetSequenceFrame(billboard, frame);
}

static void MapObject_UpdateBillboardVisibility(LocalMapObject *object, BillboardObject *billboard) {
    int visible = TRUE;
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_INVISIBLE) == TRUE) {
        visible = FALSE;
    }
    if (MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK12) == TRUE && !MapObject_TestFlagsBits(object, MAPOBJECTFLAG_UNK13)) {
        visible = FALSE;
    }
    BillboardObject_SetVisible(billboard, visible);
}

static void MapObject_GetEffectModelOffset(u32 spriteId, VecFx32 *offset) {
    const EffectModelOffset *entry = gEffectModelOffsets;
    while (entry->spriteId != MAP_OBJECT_GFX_ID_INVALID) {
        if (entry->spriteId == spriteId) {
            *offset = entry->offset;
            return;
        }
        entry++;
    }
    GF_ASSERT(FALSE);
}

void ModelObjectDraw_Init(LocalMapObject *object) {
    FieldEffect **effect = (FieldEffect **)MapObject_InitDrawData(object, sizeof(FieldEffect *));
    VecFx32 offset;
    MapObject_GetEffectModelOffset(MapObject_GetSpriteID(object), &offset);
    *effect = MapObjectModel_CreateEffect(object, &offset);
}

void ModelObjectDraw_Update(void) {
}

void ModelObjectDraw_Delete(LocalMapObject *object) {
    FieldEffect **effect = (FieldEffect **)MapObject_GetDrawData(object);
    if (*effect != NULL) {
        FieldEffectManager_DestroyEffect(*effect);
        *effect = NULL;
    }
}

void ModelObjectDraw_Pause(LocalMapObject *object) {
    FieldEffect **effect = (FieldEffect **)MapObject_GetDrawData(object);
    if (*effect != NULL) {
        FieldEffectManager_DestroyEffect(*effect);
        *effect = NULL;
    }
}

void ModelObjectDraw_Resume(LocalMapObject *object) {
    FieldEffect **effect = (FieldEffect **)MapObject_GetDrawData(object);
    VecFx32 offset;
    MapObject_GetEffectModelOffset(MapObject_GetSpriteID(object), &offset);
    *effect = MapObjectModel_CreateEffect(object, &offset);
}
