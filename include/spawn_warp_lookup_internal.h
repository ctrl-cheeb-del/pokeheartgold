#include "global.h"

typedef struct SpawnEntryPrivate {
    u16 flagIndex : 8;
    u16 isBlackoutSpawn : 1;
    u16 isFlyPoint : 1;
    u16 unused : 6;
    u16 deathMap;
    u16 deathX : 8;
    u16 deathY : 8;
    u16 flyMap;
    u16 flyX;
    u16 flyY;
    u16 specialMap;
    u16 specialX;
    u16 specialY;
} SpawnEntryPrivate;

typedef struct WarpDataPrivate {
    u32 map;
    s32 warpId;
    u32 x;
    u32 y;
    u32 direction;
} WarpDataPrivate;

extern const u16 sSpawnMaps[][9];
extern void GF_AssertFail(void);
extern void *Save_VarsFlags_Get(void *);
extern void Save_VarsFlags_FlypointFlagAction(void *, u32, u32);

s32 SpawnIdToTableIndex(s32);
u32 GetMomSpawnId(void);
void GetFlyWarpData(s32, WarpDataPrivate *);
void GetDeathWarpData(s32, WarpDataPrivate *);
void GetSpecialSpawnWarpData(s32, WarpDataPrivate *);
u32 MapHeader_GetSpawnIdForDeathWarp(u32);
u32 sub_0203BB50(u32);
void FlypointFlagAction(void *, u32);
