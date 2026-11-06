#ifndef POKEHEARTGOLD_FOLLOW_MON_H
#define POKEHEARTGOLD_FOLLOW_MON_H

#include "heap.h"
#include "map_object.h"
#include "map_object_manager.h"

#define FOLLOW_MON_PARAM_SPECIES 0

LocalMapObject *FollowMon_InitMapObject(MapObjectManager *mapObjectManager, int x, int y, int direction, u32 mapNo);
void FollowMon_ChangeMon(MapObjectManager *mapObjectManager, u32 mapNo);
LocalMapObject *FollowMon_GetMapObject(FieldSystem *fieldSystem);
u32 FollowMon_GetSpriteID(int species, u16 form, u32 gender);
void FollowMon_HideUntilStep(LocalMapObject *mapObject, BOOL enableBit);
void FollowMon_SetHideUntilStepBit(LocalMapObject *mapObject, BOOL enableBit);
u8 FollowMon_IsHiddenUntilStep(LocalMapObject *mapObject);
void FollowMon_SetPendingHop(LocalMapObject *mapObject, u32 a1);
void FollowMon_SetHopMovement(LocalMapObject *mapObject, u8 hopMovement);
void FollowMon_SetReleaseBallPending(LocalMapObject *mapObject, u8 pending);
u8 FollowMon_IsReleaseBallPending(LocalMapObject *mapObject);
u8 FollowMon_GetPendingHop(LocalMapObject *mapObject);
u8 FollowMon_GetHopMovement(LocalMapObject *mapObject);
void FollowMon_SetObjectParams(LocalMapObject *mapObject, int species, u8 form, BOOL shiny);
void FollowMon_SetObjectMon(LocalMapObject *mapObject, int species, u8 form, BOOL shiny, int a4);
void FieldSystem_SetFollowerPokeParam(FieldSystem *fieldSystem, int species, u8 form, BOOL shiny, u8 gender);
u8 FollowMon_GetSizeParamBySpecies(int species);
int FollowMon_GetSpecies(LocalMapObject *mapObject);
BOOL FollowMon_IsActive(FieldSystem *fieldSystem);
BOOL FollowMon_IsVisible(FieldSystem *fieldSystem);
BOOL FollowMon_GetPermission(FieldSystem *fieldSystem);
BOOL FollowMon_GetPermissionBySpeciesAndMap(int species, u32 mapNo);
void FollowMon_SetInvisibleFlag(LocalMapObject *mapObject, BOOL enableBit);
void FollowMon_Hide(FieldSystem *fieldSystem);
FollowMonMood *FollowMonMood_New(enum HeapID heapID);
void FollowMonMood_Add(FollowMonMood *followMood, s8 by);
void FollowMonMood_Set(FollowMonMood *followMood, s8 mood);
s8 FollowMonMood_Get(FollowMonMood *followMood);
void FollowMonMood_SetMon(FollowMonMood *followMonMood, Pokemon *mon, u16 species, u32 personality);
void FollowMonMood_MoveTowardsNeutral(FollowMonMood *followMonMood);
int SpeciesToOverworldModelIndexOffset(int species);
int OverworldModelLookupFormCount(int species);
BOOL OverworldModelLookupHasFemaleForm(int species);

#endif // POKEHEARTGOLD_FOLLOW_MON_H
