#ifndef POKEHEARTGOLD_OVERLAY02_FIELD_EFFECT_SLOTS_R45_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY02_FIELD_EFFECT_SLOTS_R45_PRIVATE_H

#include "global.h"

#include "field/overlay_01_021FB878.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov02EffectSlotR45 {
    Field3dObject object;
    Field3DModelAnimation animations[4];
    BOOL active;
} Ov02EffectSlotR45;

typedef struct Ov02EffectManagerR45 {
    Field3dModel model;
    Ov02EffectSlotR45 slots[16];
    void *animationData[4];
    void *fieldSystem;
    u32 unk_CE4;
    fx32 dx;
    fx32 dz;
    VecFx32 lastPosition;
    NNSFndAllocator allocator;
} Ov02EffectManagerR45;

void GF_AssertFail(void);
void PlaySE(u16 seqNo);
void PlayerAvatar_CopyPositionVector(void *avatar, VecFx32 *vector);
void ov01_021FBE70(Field3DModelAnimation *anim, Field3dModel *model, void *animRaw, NNSFndAllocator *alloc);

void ov02_0224D698(Ov02EffectSlotR45 *slot, void *avatar, fx32 dx, fx32 dz);
void ov02_0224D700(Ov02EffectSlotR45 *slot);
void ov02_0224D73C(Ov02EffectSlotR45 *slot, Field3dModel *model, NNSFndAllocator *allocator, void **animationData);
void ov02_0224D788(Ov02EffectSlotR45 *slot, NNSFndAllocator *allocator);
void ov02_0224D7B0(Ov02EffectManagerR45 *manager);
void ov02_0224D820(Ov02EffectManagerR45 *manager);

#endif // POKEHEARTGOLD_OVERLAY02_FIELD_EFFECT_SLOTS_R45_PRIVATE_H
