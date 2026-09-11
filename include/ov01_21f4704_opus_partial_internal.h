#ifndef GUARD_OV01_021F4704_PRIVATE_H
#define GUARD_OV01_021F4704_PRIVATE_H

#include "global.h"

#include "field/map_load_manager.h"

#include "field_metatile_query_internal.h"
#include "filesystem.h"
#include "heap.h"
#include "sys_task.h"

typedef struct MapLoadSoundplate {
    int unk00;               // 0x86C
    u8 unk04[0xA70 - 0x870]; // 0x870
} MapLoadSoundplate;

typedef struct MapLoadedChunk {
    u8 pad_000[0x854];        // 0x000
    void *unk854;             // 0x854
    void *unk858;             // 0x858
    void *unk85C;             // 0x85C
    int unk860;               // 0x860
    u32 unk864;               // 0x864
    MapPropManager *unk868;   // 0x868
    MapLoadSoundplate unk86C; // 0x86C  soundplate block
    u8 *unkA70;               // 0xA70
} MapLoadedChunk;

typedef struct MapLoadSlot {
    void *unk00;            // 0x00
    u8 pad_04[0x0C - 0x04]; // 0x04
    SysTask *unk0C;         // 0x0C
    void *unk10;            // 0x10
    int unk14;              // 0x14
    int unk18;              // 0x18
    u8 pad_1C[0x28 - 0x1C]; // 0x1C
    int unk28;              // 0x28
    int unk2C;              // 0x2C
} MapLoadSlot;              // sizeof == 0x30

typedef struct MapLoadTask {
    u8 pad_00[8]; // 0x00
    void *unk08;  // 0x08
    void *unk0C;  // 0x0C
    int unk10;    // 0x10
    int unk14;    // 0x14
    int unk18;    // 0x18
    int unk1C;    // 0x1C
    int unk20;    // 0x20
} MapLoadTask;

typedef struct MapLoadRequest {
    void *unk00;            // 0x00
    void *unk04;            // 0x04
    void *unk08;            // 0x08
    void *unk0C;            // 0x0C
    void *unk10;            // 0x10
    void *unk14;            // 0x14
    u8 unk18;               // 0x18
    u8 pad_19[0x1C - 0x19]; // 0x19
    int *unk1C;             // 0x1C
    int unk20;              // 0x20
    void *unk24;            // 0x24
    void *unk28;            // 0x28
    u8 pad_2C[0x30 - 0x2C]; // 0x2C
} MapLoadRequest;           // sizeof == 0x30

typedef struct MapLoadPending {
    MapLoadedChunk *unk00;  // 0x64
    MapLoadedChunk *unk04;  // 0x68
    u8 pad_08[0x10 - 0x08]; // 0x6C
    int unk10;              // 0x74
    int unk14;              // 0x78
} MapLoadPending;           // sizeof == 0x18

typedef struct MapLoadVTable {
    void (*func0)(struct MapLoadManager *mapLoadManager, int x, int z, u32 unkCC);
} MapLoadVTable;

struct MapLoadManager {
    MapLoadSlot slots[2];        // 0x00
    u8 pad_60[0x64 - 0x60];      // 0x60
    MapLoadPending unk64;        // 0x64
    u8 pad_7C[0x80 - 0x7C];      // 0x7C
    u32 unk80[4];                // 0x80
    MapLoadedChunk *maps[4];     // 0x90
    u8 unkA0;                    // 0xA0
    u8 unkA1;                    // 0xA1
    u8 unkA2;                    // 0xA2
    u8 pad_A3[0xA4 - 0xA3];      // 0xA3
    u32 unkA4;                   // 0xA4
    u32 unkA8;                   // 0xA8
    u8 unkAC;                    // 0xAC
    u8 unkAD;                    // 0xAD
    u8 pad_AE[0xB0 - 0xAE];      // 0xAE
    int unkB0;                   // 0xB0
    u8 pad_B4[0xB8 - 0xB4];      // 0xB4
    void *unkB8;                 // 0xB8
    UnkStruct_FieldSysC0 *unkBC; // 0xBC
    void *unkC0;                 // 0xC0
    u32 unkC4;                   // 0xC4
    u32 unkC8;                   // 0xC8
    u32 unkCC;                   // 0xCC
    VecFx32 unkD0;               // 0xD0
    VecFx32 *unkDC;              // 0xDC
    u8 pad_E0[0xF4 - 0xE0];      // 0xE0
    int unkF4;                   // 0xF4
    u8 pad_F8[0xFC - 0xF8];      // 0xF8
    MapLoadVTable *unkFC;        // 0xFC
    NARC *narc;                  // 0x100
};

typedef struct MapLoadPair {
    int unk00;
    int unk04;
} MapLoadPair;

void ov01_021FB354(void *a0);
void ov01_021FACB4(void *a0);
int ov01_021F5BF0(MapLoadManager *mapLoadManager);
void ov01_021F5568(int idx, MapLoadManager *mapLoadManager);

void MapLoadManager_RenderLoadedMap(int idx, MapLoadManager *mapLoadManager, ModelAttributes *modelAttributes);
void ov01_021F6614(SysTask *task);

typedef void (*MapLoadFunc)(void);

void ov01_021F6620(SysTask *task, void *data);

void *ov01_021FB254(void);
void ov01_021FB360(void *bufs);
int ov01_021FBA00(void *areaDataManager);

void ov01_021FACE4(u32 index, void *buffers, void **out);
void ov01_021FACEC(u32 index, void *buffers, void **out);

typedef struct MapLoadIds {
    int unk00;
    int unk04;
    u32 unk08;
    u32 unk0C;
} MapLoadIds;

int ov01_021F4A50(MapLoadIds *ids, MapLoadManager *mapLoadManager, void *a2, MapLoadedChunk *chunk, void *a4, u32 a5, int a6);
void ov01_021F4B1C(MapLoadManager *mapLoadManager, MapLoadedChunk *chunk, MapLoadIds *ids, void *a3);
void ov01_021F4C6C(MapLoadManager *mapLoadManager, MapLoadedChunk *chunk, MapLoadIds *ids, void *a3, int a4, void *a5, int a6, int a7);
void ov01_021F488C(MapLoadManager *mapLoadManager, int a1);
void ov01_021F497C(MapLoadManager *mapLoadManager);
void ov01_021F47A0(int a0, int a1, u32 a2, u32 a3, int a4, void **a5);
void ov01_021F4E88(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5, int a6, MapLoadManager *a7);
void ov01_021F4F0C(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5, int a6, MapLoadManager *a7);
void ov01_021F4FB0(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5, int a6, MapLoadManager *a7);

void ov01_021F5D8C(MapLoadManager *mapLoadManager, int a1, int a2, int a3);
void ov01_021F4D10(void);
void ov01_021F5EA0(MapLoadManager *mapLoadManager, int a1, int a2, int a3);
void ov01_021F4E1C(void);
void ov01_021F5E20(MapLoadManager *mapLoadManager, int a1, int a2, int a3);
void ov01_021F4D88(void);

#endif // GUARD_OV01_021F4704_PRIVATE_H
