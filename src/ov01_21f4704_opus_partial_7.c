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

u32 ov01_021F5AE8(u32 dir, u8 val) {
    switch (dir) {
    case 4:
        return (u8)(val - 2);
    case 2:
        return (u8)(val + 2);
    case 3:
        return (u8)(val - 1);
    case 1:
        return (u8)(val + 1);
    }
    return dir;
}
