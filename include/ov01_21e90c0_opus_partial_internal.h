#ifndef PRIVATE_OVERLAY_01_021E90C0_H
#define PRIVATE_OVERLAY_01_021E90C0_H

#include "global.h"

#include "constants/sndseq.h"

#include "field/area_light.h"
#include "nnsys/g3d/binres/res_struct.h"

#include "ascii_util.h"
#include "field_system.h"
#include "filesystem.h"
#include "gf_rtc.h"
#include "heap.h"
#include "map_header.h"
#include "screen_fade.h"
#include "unk_02055BF0.h"

typedef struct Struct021E90C0 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8 filler0C[0x10];
    u16 unk1C;
    u16 unk1E;
} Struct021E90C0;

typedef struct AreaLightTemplate {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
} AreaLightTemplate;

/* 0x30-byte runtime light entry parsed out of the .txt by ov01_021EA3E0. */
typedef struct DoorSEData {
    u32 unk00;
    u8 doorType; // 0x04
    u8 filler05[0x13];
} DoorSEData;

typedef struct Struct021E9F78 {
    u8 state; // 0x00
    u8 step;  // 0x01
    u16 pad02;
    u32 active; // 0x04
} Struct021E9F78;

typedef struct AreaLightEntry {
    u32 endTime; // 0x00
    u8 mask;     // 0x04
    u8 pad05;
    u16 color[4];  // 0x06
    s16 dir[4][3]; // 0x0e
    u16 unk26;     // 0x26
    u16 unk28;     // 0x28
    u16 unk2A;     // 0x2a
    u16 unk2C;     // 0x2c
    u16 pad2E;
} AreaLightEntry;

void ov01_021EAAB8(ModelAttributes *ma, int idx, s16 x, s16 y, s16 z);
void ov01_021EAAE0(ModelAttributes *ma, int idx, u16 color);
void ov01_021EAAF4(ModelAttributes *ma, u16 v, int a, int b);
void ov01_021EAB08(ModelAttributes *ma, u16 v, int a);
void ov01_021EAB1C(ModelAttributes *ma, u16 v, int a, int b);
void ov01_021EAB30(ModelAttributes *ma, u16 v, int a);

struct AreaLightManager {
    u32 count;                        // 0x00
    AreaLightEntry *entries;          // 0x04
    u32 activeIndex;                  // 0x08
    ModelAttributes *modelAttributes; // 0x0C
    u32 unk10;                        // 0x10
};

/* No tracked prototypes exist for these. */
int GetDoorSE(FieldSystem *fieldSystem, int modelId, BOOL opening);
NARC *ov01_021FB904(AreaDataManager *areaDataManager);
void PlaySE(u16 seq);
void ov01_021EA300(AreaLightEntry *entry, ModelAttributes *modelAttributes);
int ov01_021EA3E0(const char *path, AreaLightEntry **entriesOut);
void ov01_021EA398(AreaLightManager *areaLightManager);
void ov01_021EA564(AreaLightEntry **p);

#endif
