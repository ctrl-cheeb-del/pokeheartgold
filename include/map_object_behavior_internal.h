#ifndef POKEHEARTGOLD_MAP_OBJECT_BEHAVIOR_INTERNAL_H
#define POKEHEARTGOLD_MAP_OBJECT_BEHAVIOR_INTERNAL_H

#include "field/map_object_render.h"

#include "field_system.h"
#include "map_object.h"
#include "player_avatar.h"

typedef struct TrainerBehaviorState {
    u8 state;
    u8 turnState;
    s8 count;
    s8 limit;
    s8 direction;
    s8 sequence;
    s8 index;
    s8 turns;
    s8 timer;
} TrainerBehaviorState;

typedef struct ApricornTreeState {
    u32 spriteId;
    u32 apricorns;
    BillboardObject *billboard;
    BillboardState savedState;
} ApricornTreeState;

typedef struct MapObjectSpriteState {
    u16 unk0;
    u16 unk2;
} MapObjectSpriteState;

typedef struct EngageParams {
    int x;
    int z;
    int scriptId;
    int trainerNum;
    BOOL isDouble;
    LocalMapObject *object;
} EngageParams;

typedef struct TrainerApproachWork {
    int state;
    BOOL done;
    int direction;
    int distance;
    int unk10;
    int encounterType;
    int trainerIndex;
    int timer;
    FieldEffect *effect;
    LocalMapObject *trainer;
    PlayerAvatar *player;
    FieldSystem *fieldSystem;
} TrainerApproachWork;

typedef struct FourValues {
    u32 values[4];
} FourValues;

typedef struct TwoByTwoValues {
    u32 values[2][2];
} TwoByTwoValues;

typedef struct DirectionMovementTable {
    u32 values[2][DIR_MAX];
} DirectionMovementTable;

typedef void (*MapObjectAction)(LocalMapObject *object);
typedef BOOL (*MapObjectPredicate)(LocalMapObject *object);
typedef int (*TrainerSightFunc)(LocalMapObject *object, int range, int targetX, int targetZ, int unused);
typedef BOOL (*TrainerApproachStateFunc)(TrainerApproachWork *work);

extern const FourValues gLookSidewaysAxisByFacing;
extern const TwoByTwoValues gLookSidewaysDirections;
extern const DirectionMovementTable gTypeBehaviorSpinOrders;
extern const MapObjectAction gMapObjectTypeBehaviorInits[];
extern const MapObjectPredicate gMapObjectTypeBehaviorChecks[];
extern const MapObjectPredicate gMapObjectTypeBehaviorUpdates[];

extern const u32 gApricornTreeSpriteIds[];

void MapObject_InitTypeBehavior(LocalMapObject *object);
BOOL MapObject_UpdateTypeBehavior(LocalMapObject *object);
void TypeBehavior_NoOpInit(LocalMapObject *object);
int TypeBehavior_NoOpCheck(LocalMapObject *object);
int TypeBehavior_NoOpUpdate(LocalMapObject *object);
void TypeBehavior_LookSidewaysInit(LocalMapObject *object);
BOOL TypeBehavior_LookSidewaysCheck(LocalMapObject *object);
BOOL TypeBehavior_LookSidewaysUpdate(LocalMapObject *object);
void TypeBehavior_SpinInit(LocalMapObject *object);
BOOL TypeBehavior_SpinCheck(LocalMapObject *object);
BOOL TypeBehavior_SpinUpdate(LocalMapObject *object);
void ApricornTreeObject_Init(LocalMapObject *object);
void ApricornTreeObject_Update(LocalMapObject *object);
void ApricornTreeObject_Delete(LocalMapObject *object);
void ApricornTreeObject_Pause(LocalMapObject *object);
void ApricornTreeObject_Resume(LocalMapObject *object);
BillboardObject *ApricornTreeObject_GetBillboard(LocalMapObject *object);
BOOL TryGetSeenByNpcTrainers(FieldSystem *fieldSystem, BOOL doublesEligible);
u32 MapObjectBehavior_GetTrainerNum(LocalMapObject *object);

#endif // POKEHEARTGOLD_MAP_OBJECT_BEHAVIOR_INTERNAL_H
