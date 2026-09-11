#include "ov01_21f4704_opus_partial_internal.h"

extern const MapLoadFunc ov01_02206BC0[2];
extern const MapLoadFunc ov01_02206BD0[2];
extern const MapLoadFunc ov01_02206BC8[2];
extern const VecFx32 ov01_02206BD8;
extern const fx32 ov01_02206BE4[9];

BOOL ov01_021F4704(int a0, int a1, int a2);
BOOL ov01_021F4728(int a0, int a1, int a2);
void ov01_021F474C(MapLoadManager *mapLoadManager, int idx);
void ov01_021F477C(MapLoadTask *task);
void ov01_021F4AAC(MapLoadManager *mapLoadManager, MapLoadedChunk *chunk);
void ov01_021F4AE4(MapLoadManager *mapLoadManager, MapLoadedChunk *chunk, int fileId);
BOOL ov01_021F5024(MapLoadPair *pair);
void ov01_021F55F4(int i0, int i1, int i2, int i3, MapLoadManager *mapLoadManager);
u32 ov01_021F5A04(u32 a0, u32 a1, u32 a2);
u32 ov01_021F5A28(u32 a0, u32 a1, u32 a2);
u32 ov01_021F5A30(u32 a0, u32 a1, u32 a2);
int ov01_021F5A54(int a0);
u32 ov01_021F5AE8(u32 dir, u8 val);
int ov01_021F5B88(u32 a0);
void ov01_021F5CB4(MapLoadManager *mapLoadManager);
int ov01_021F5D10(MapLoadManager *mapLoadManager);
void ov01_021F5D20(MapLoadManager *mapLoadManager);
void ov01_021F5D38(u32 dir, MapLoadManager *mapLoadManager);
void ov01_021F5F34(MapLoadManager *mapLoadManager);
void ov01_021F5F64(int x, int z, MapLoadManager *mapLoadManager);
void ov01_021F61DC(fx32 x, fx32 z, int *outX, int *outZ);
void ov01_021F676C(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, int *a7, void *a8);

void ov01_021F5CB4(MapLoadManager *mapLoadManager) {
    MapLoadPending *pending = &mapLoadManager->unk64;

    if (mapLoadManager->unkA0 >= 2) {
        GF_AssertFail();
    }
    if (ov01_021F5BF0(mapLoadManager) != 1) {
        GF_AssertFail();
    }
    pending->unk00->unk860 = pending->unk10;
    pending->unk04->unk860 = pending->unk14;
    mapLoadManager->unkA0++;
    mapLoadManager->unkA1 = (mapLoadManager->unkA1 + 1) % 2;
}

int ov01_021F5D10(MapLoadManager *mapLoadManager) {
    return mapLoadManager->slots[mapLoadManager->unkA2].unk28;
}

void ov01_021F5D20(MapLoadManager *mapLoadManager) {
    u8 i;

    for (i = 0; i < 4; i++) {
        mapLoadManager->unk80[i] = 0;
    }
}

void ov01_021F5D38(u32 dir, MapLoadManager *mapLoadManager) {
    switch (dir) {
    case 4:
        mapLoadManager->unk80[2] = 1;
        mapLoadManager->unk80[3] = 1;
        break;
    case 1:
        mapLoadManager->unk80[0] = 1;
        mapLoadManager->unk80[2] = 1;
        break;
    case 2:
        mapLoadManager->unk80[0] = 1;
        mapLoadManager->unk80[1] = 1;
        break;
    case 3:
        mapLoadManager->unk80[1] = 1;
        mapLoadManager->unk80[3] = 1;
        break;
    }
}

void ov01_021F5D8C(MapLoadManager *mapLoadManager, int a1, int a2, int a3) {
    u8 i;
    void *sp10[4];

    ov01_021F488C(mapLoadManager, 0);
    ov01_021F47A0(a1, a2, mapLoadManager->unkC4, mapLoadManager->unkC8, a3, sp10);
    for (i = 0; i < 4; i++) {
        mapLoadManager->maps[i]->unk85C = ov01_021FB254();
        ov01_021FB360(mapLoadManager->maps[i]->unk85C);
        ov01_021F4E88(sp10[i], i, mapLoadManager->unkB8, mapLoadManager->unkC0, mapLoadManager->unkC4, mapLoadManager->unkC8, ov01_021FBA00(mapLoadManager->unkB8), mapLoadManager);
    }
}

void ov01_021F5E20(MapLoadManager *mapLoadManager, int a1, int a2, int a3) {
    u8 i;
    void *sp10[4];

    ov01_021F497C(mapLoadManager);
    ov01_021F47A0(a1, a2, mapLoadManager->unkC4, mapLoadManager->unkC8, a3, sp10);
    for (i = 0; i < 4; i++) {
        mapLoadManager->maps[i]->unk85C = NULL;
        ov01_021F4F0C(sp10[i], i, mapLoadManager->unkB8, mapLoadManager->unkC0, mapLoadManager->unkC4, mapLoadManager->unkC8, ov01_021FBA00(mapLoadManager->unkB8), mapLoadManager);
    }
}

void ov01_021F5EA0(MapLoadManager *mapLoadManager, int a1, int a2, int a3) {
    u8 i;
    void *sp10[4];

    ov01_021F488C(mapLoadManager, 1);
    ov01_021F47A0(a1, a2, mapLoadManager->unkC4, mapLoadManager->unkC8, a3, sp10);
    for (i = 0; i < 4; i++) {
        mapLoadManager->maps[i]->unk85C = ov01_021FB254();
        ov01_021FB360(mapLoadManager->maps[i]->unk85C);
        ov01_021F4FB0(sp10[i], i, mapLoadManager->unkB8, mapLoadManager->unkC0, mapLoadManager->unkC4, mapLoadManager->unkC8, ov01_021FBA00(mapLoadManager->unkB8), mapLoadManager);
    }
}

void ov01_021F5F34(MapLoadManager *mapLoadManager) {
    int i;

    mapLoadManager->unkA2 = 0;
    mapLoadManager->unkA1 = 0;
    mapLoadManager->unkA0 = 0;
    for (i = 0; i < 2; i++) {
        mapLoadManager->slots[i].unk2C = 0;
        mapLoadManager->slots[i].unk28 = 1;
    }
    ov01_021F5D20(mapLoadManager);
}

void ov01_021F5F64(int x, int z, MapLoadManager *mapLoadManager) {
    mapLoadManager->unkA8 = ov01_021F5A28(x, z, mapLoadManager->unkCC);
    mapLoadManager->unkAD = ov01_021F6328(mapLoadManager->unkA8, mapLoadManager->unkCC);
    mapLoadManager->unkAC = ov01_021F5A54(mapLoadManager->unkAD);
    mapLoadManager->unkA4 = ov01_021F5A30(mapLoadManager->unkA8, mapLoadManager->unkC4, mapLoadManager->unkCC);
}
