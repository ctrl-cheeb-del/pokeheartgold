#ifndef PRIVATE_OV01_021FB878_H
#define PRIVATE_OV01_021FB878_H

#include "global.h"

#include "field/area_data.h"
#include "field/map_prop_animation.h"
#include "field/overlay_01_02204004.h"

#include "filesystem.h"
#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "sys_task.h"

#define AREA_DATA_MAX_MAP_PROPS 0x226

// The 8-byte header read from NARC_AREA_DATA member 0x2a.
typedef struct AreaDataHeader {
    u16 mapPropNarcMemberId; // 0x8B0
    u16 mapTexNarcMemberId;  // 0x8B2
    u16 unk4;                // 0x8B4
    u8 buildModelKind;       // 0x8B6
    u8 lightKind;            // 0x8B7
} AreaDataHeader;

// 16-byte scratch context, freed at the end of AreaDataManager_Load.
typedef struct AreaDataLoadContext {
    u32 areaDataBank;
    u32 unk4;
    NARC *narc;
    u16 count;
    u16 unkE;
} AreaDataLoadContext;

struct AreaDataManager {
    u32 unk0;
    NNSG3dResFileHeader *mapPropModels[AREA_DATA_MAX_MAP_PROPS]; // 0x004
    void *mapPropTexFile;                                        // 0x89C
    void *mapTexFile;                                            // 0x8A0
    NNSG3dResTex *mapPropTex;                                    // 0x8A4
    NNSG3dResTex *mapTex;                                        // 0x8A8
    AreaDataManager_Sub8AC *unk8AC;                              // 0x8AC
    AreaDataHeader header;                                       // 0x8B0
    AreaDataLoadContext *loadCtx;                                // 0x8B8
    u16 *mapPropIdList;                                          // 0x8BC
    NARC *mapPropNarc;                                           // 0x8C0
};

// Only the size field at +0x14 is used by this module.
typedef struct AreaDataTexBlockHeader {
    u8 padding_00[0x14];
    u32 endOffset;
} AreaDataTexBlockHeader;

typedef struct AreaDataMapPropEntry {
    u16 unk0;
    u16 fileId;
} AreaDataMapPropEntry;

int sprintf(char *buf, const char *fmt, ...);
SysTask *SysTask_CreateOnVWaitQueue(SysTaskFunc func, void *data, u32 priority);
void SysTask_Destroy(SysTask *task);

AreaDataManager_Sub8AC *ov01_021EA724(void);
void ov01_021EA73C(const char *path, AreaDataManager_Sub8AC *a1);
void ov01_021EA7E0(AreaDataManager_Sub8AC *a0);

#endif // PRIVATE_OV01_021FB878_H
