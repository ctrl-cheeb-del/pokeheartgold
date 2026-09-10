#ifndef OV01_021FB368_PRIVATE_H
#define OV01_021FB368_PRIVATE_H

#include "global.h"

typedef struct DynamicTerrainHeightEntry {
    s32 x;
    s32 z;
    s32 width;
    s32 depth;
    s32 height;
    BOOL active;
} DynamicTerrainHeightEntry;

typedef struct DynamicTerrainHeightManager {
    s32 count;
    DynamicTerrainHeightEntry *entries;
} DynamicTerrainHeightManager;

extern void *Heap_Alloc(u32 heapId, u32 size);
extern void Heap_Free(void *);
extern void GF_AssertFail(void);

BOOL ov01_021FB368(s32 x, s32 z, const DynamicTerrainHeightEntry *);
DynamicTerrainHeightManager *DynamicTerrainHeightManager_New(u32 count, u32 heapId);
void ov01_021FB3E4(u32 index, s32 x, s32 z, s32 width, s32 depth, s32 height, DynamicTerrainHeightManager *);
void DynamicTerrainHeightManager_Free(DynamicTerrainHeightManager *);
BOOL ov01_021FB42C(s32 x, s32 z, DynamicTerrainHeightManager *, u8 *index);
s32 ov01_021FB474(s32 index, DynamicTerrainHeightManager *);
void ov01_021FB4A0(s32 index, s32 height, DynamicTerrainHeightManager *);

#endif
