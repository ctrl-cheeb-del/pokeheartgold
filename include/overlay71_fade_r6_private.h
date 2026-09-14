#ifndef TO45_OVERLAY71_RESIDUAL5_PRIVATE_H
#define TO45_OVERLAY71_RESIDUAL5_PRIVATE_H

#include "global.h"

typedef struct Ov71FadeTask {
    void *bgConfig;
    int *finished;
    s32 current;
    s32 target;
    s32 delta;
    s32 step;
    s32 direction;
    s32 bgId;
    void *task;
} Ov71FadeTask;

typedef struct Ov71PlaneTask {
    void *system;
    s32 index;
    s32 current;
    s32 counter;
    s32 delay;
    s32 direction;
} Ov71PlaneTask;

typedef struct Ov71ScaleMatrix {
    s32 x;
    s32 z0;
    s32 z1;
    s32 y;
} Ov71ScaleMatrix;

void ov71_02246E84(void *, int, int, u16);
void ov71_02246F60(void *, int);
void *Heap_Alloc(int, u32);
void Heap_Free(void *);
void *SysTask_CreateOnVBlankQueue(void (*)(void *, void *), void *, u32);
void SysTask_Destroy(void *);
void ov71_02247424(void *);
void SetBgAffine(void *, u8, const void *, int, int);
extern const s32 _0224BBD4[];
void *GfGfxLoader_GetCellBank(int, int, int, void **, int);
void *GfGfxLoader_GetAnimBank(int, int, int, void **, int);
void *GfGfxLoader_GetScrnData(int, int, int, void **, int);
void CopyToBgTilemapRect(void *, u8, u8, u8, u8, u8, const void *, u8, u8, u8, u8);
void BgTilemapRectChangePalette(void *, u8, u8, u8, u8, u8, u8);

void ov71_02246F90(void *, Ov71PlaneTask *);
Ov71FadeTask *ov71_02247000(void *, s32, s32, s32, s32, s32, int *);
void ov71_02247068(void *, Ov71FadeTask *);
void ov71_022470DC(Ov71FadeTask *);
void ov71_02247230(void *, int, int, int, int, int);
void ov71_022472C4(void *, s32, s32, s32);

#endif
