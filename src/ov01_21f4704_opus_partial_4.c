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

void ov01_021F4E88(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5, int a6, MapLoadManager *a7) {
    MapLoadIds ids;
    int r;

    r = ov01_021F4A50(&ids, a7, a3, a7->maps[a1], a0, a4 * a5, 1);
    if (r != 0xFFFF) {
        ov01_021F4AAC(a7, a7->maps[a1]);
        ov01_021F4AE4(a7, a7->maps[a1], ids.unk00);
        MapPropManager_LoadFromNARC(a7->narc, ids.unk0C, a7->maps[a1]->unk868, a7->unkF4);
        ov01_021F4C6C(a7, a7->maps[a1], &ids, a2, r, a0, a6, 1);
    }
}

void ov01_021F4F0C(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5, int a6, MapLoadManager *a7) {
    u8 buf[0x800];
    MapLoadIds ids;
    int r;

    r = ov01_021F4A50(&ids, a7, a3, a7->maps[a1], a0, a4 * a5, 0);
    if (r != 0xFFFF) {
        ov01_021F4AAC(a7, a7->maps[a1]);
        NARC_ReadFile(a7->narc, 0x800, buf);
        MapPropManager_LoadFromNARC(a7->narc, ids.unk0C, a7->maps[a1]->unk868, a7->unkF4);
        ov01_021F4C6C(a7, a7->maps[a1], &ids, a2, r, a0, a6, 0);
    }
}

void ov01_021F4FB0(void *a0, u8 a1, void *a2, void *a3, u32 a4, u32 a5, int a6, MapLoadManager *a7) {
    MapLoadIds ids;
    int r;

    r = ov01_021F4A50(&ids, a7, a3, a7->maps[a1], a0, a4 * a5, 1);
    if (r != 0xFFFF) {
        ov01_021F4AAC(a7, a7->maps[a1]);
        ov01_021F4AE4(a7, a7->maps[a1], ids.unk00);
        ov01_021F4B1C(a7, a7->maps[a1], &ids, a0);
        ov01_021F4C6C(a7, a7->maps[a1], &ids, a2, r, a0, a6, 1);
    }
}

BOOL ov01_021F5024(MapLoadPair *pair) {
    if (pair->unk00 == 0 && pair->unk04 == 0) {
        return TRUE;
    }
    return FALSE;
}
