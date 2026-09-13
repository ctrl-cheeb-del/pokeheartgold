#ifndef TO45_OV02_EFFECT_SLOTS_R50_PRIVATE_H
#define TO45_OV02_EFFECT_SLOTS_R50_PRIVATE_H

#include "global.h"

#include "field/overlay_01_021FB878.h"

#include "sys_task.h"

typedef struct Ov02EffectSlot {
    Field3dObject object;
    Field3DModelAnimation animations[4];
    BOOL active;
} Ov02EffectSlot;

typedef struct Ov02EffectTask {
    void *object;
    u16 *result;
    u32 state;
    u32 kind;
} Ov02EffectTask;

typedef void *(*Ov02EffectCreateFunc)(void *);
typedef BOOL (*Ov02EffectUpdateFunc)(void *);

extern Ov02EffectCreateFunc ov02_02253A1C[];
extern Ov02EffectUpdateFunc ov02_02253A34[];
extern void (*ov02_02253A04[])(void *);

void GF_AssertFail(void);
void PlaySE(u16 seqNo);
void ov01_021FBE70(Field3DModelAnimation *anim, Field3dModel *model, void *animRaw, NNSFndAllocator *alloc);
void Field3dModelAnimation_Unload(Field3DModelAnimation *anim, NNSFndAllocator *alloc);
void *Heap_Alloc(enum HeapID heapID, u32 size);
void Heap_Free(void *ptr);
SysTask *SysTask_CreateOnMainQueue(SysTaskFunc func, void *data, u32 priority);
void SysTask_Destroy(SysTask *task);

void ov02_0224DE10(Ov02EffectSlot *slot, const VecFx32 *position, fx32 dx, fx32 dz);
void ov02_0224DE6C(Ov02EffectSlot *slot);
void ov02_0224DEA8(Ov02EffectSlot *slot, Field3dModel *model, NNSFndAllocator *allocator, void **animationData);
void ov02_0224DEF4(Ov02EffectSlot *slot, NNSFndAllocator *allocator);
void ov02_0224E008(u8 *work);
void ov02_0224E020(SysTask *task, void *arg);
void ov02_0224E074(void *fieldSystem, u16 *result, int kind, enum HeapID heapID);

#endif
