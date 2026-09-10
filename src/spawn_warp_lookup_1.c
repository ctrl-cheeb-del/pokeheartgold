#include "spawn_warp_lookup_internal.h"

s32 SpawnIdToTableIndex(s32 spawnId) {
    if (spawnId <= 0 || (u32)spawnId > 30) {
        GF_AssertFail();
        spawnId = 1;
    }
    return spawnId - 1;
}

u32 GetMomSpawnId(void) {
    return 1;
}

void GetFlyWarpData(s32 spawnId, WarpDataPrivate *warp) {
    s32 index = SpawnIdToTableIndex(spawnId);
    warp->map = sSpawnMaps[index][3];
    warp->warpId = -1;
    warp->x = sSpawnMaps[index][4];
    warp->y = sSpawnMaps[index][5];
    warp->direction = 1;
}

void GetDeathWarpData(s32 spawnId, WarpDataPrivate *warp) {
    s32 index = SpawnIdToTableIndex(spawnId);
    warp->map = sSpawnMaps[index][1];
    warp->warpId = -1;
    warp->x = ((const SpawnEntryPrivate *)sSpawnMaps)[index].deathX;
    warp->y = ((const SpawnEntryPrivate *)sSpawnMaps)[index].deathY;
    warp->direction = 0;
}

void GetSpecialSpawnWarpData(s32 spawnId, WarpDataPrivate *warp) {
    s32 index = SpawnIdToTableIndex(spawnId);
    warp->map = sSpawnMaps[index][6];
    warp->warpId = -1;
    warp->x = sSpawnMaps[index][7];
    warp->y = sSpawnMaps[index][8];
    warp->direction = 1;
}

u32 MapHeader_GetSpawnIdForDeathWarp(u32 mapId) {
    const SpawnEntryPrivate *entries = (const SpawnEntryPrivate *)sSpawnMaps;
    u32 i;
    for (i = 0; i < 30; i++) {
        if (entries[i].deathMap == mapId && entries[i].isBlackoutSpawn) {
            return i + 1;
        }
    }
    return 0;
}

u32 sub_0203BB50(u32 mapId) {
    u32 i;
    for (i = 0; i < 30; i++) {
        if (sSpawnMaps[i][3] == mapId) {
            return i + 1;
        }
    }
    return 0;
}

void FlypointFlagAction(void *fieldSystem, u32 mapId) {
    u8 *p = fieldSystem;
    u32 i;
    for (i = 0; i < 30; i++) {
        if (sSpawnMaps[i][3] == mapId && ((const SpawnEntryPrivate *)sSpawnMaps)[i].isFlyPoint) {
            void *varsFlags = Save_VarsFlags_Get(*(void **)(p + 0xc));
            Save_VarsFlags_FlypointFlagAction(varsFlags, 1, (u8)sSpawnMaps[i][0]);
            return;
        }
    }
}
