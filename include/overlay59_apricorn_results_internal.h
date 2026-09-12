#ifndef POKEHEARTGOLD_OVERLAY59_APRICORN_RESULTS_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY59_APRICORN_RESULTS_INTERNAL_H

#include "global.h"

#pragma require_prototypes off

#define OV59_RESULT_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define OV59_RESULT_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define OV59_RESULT_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov59ResultScaleTask {
    void *parent;
    u8 hide;
    u8 padding_05;
    u8 timer;
    u8 padding_07;
    s32 velocity;
    u16 angle;
    s16 angleStep;
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    void *sprite;
} Ov59ResultScaleTask;

typedef struct Ov59ResultShakeTask {
    void *parent;
    u8 counter;
    u8 phase;
    u8 delta;
    u8 padding_07;
} Ov59ResultShakeTask;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void MI_CpuFill8(void *dest, u8 value, u32 size);
void *SysTask_CreateOnMainQueue(void *function, void *data, u32 priority);
void SysTask_Destroy(void *task);
void ov59_0223BD4C(void *work, void *entry, u8 index);
void ov59_0223C09C(void *task, Ov59ResultShakeTask *data);
void ov59_0223C16C(void *task, Ov59ResultShakeTask *data);
void ov59_0223C3F0(void);
void *PokepicManager_Create(u32 heapId);
void *GF_3DVramMan_Create(u32 heapId, u32 a1, u32 a2, u32 a3, u32 a4, void *callback);

#endif
