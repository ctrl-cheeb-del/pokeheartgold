#ifndef OVERLAY02_EFFECT_RESOURCES_R17_PRIVATE_H
#define OVERLAY02_EFFECT_RESOURCES_R17_PRIVATE_H

#include "global.h"

#include "sprite_transfer.h"
#include "unk_0200A090.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct Ov02R17Entry {
    s32 x;
    s32 y;
    s32 parameter;
    u32 value;
    u32 priority;
} Ov02R17Entry;

typedef struct Ov02R17EffectArgs {
    u32 value;
    void *owner;
    void *context;
    VecFx32 offset;
} Ov02R17EffectArgs;

typedef struct Ov02R17TaskArgs {
    VecFx32 position;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
} Ov02R17TaskArgs;

typedef struct Ov02R17TaskWork {
    u32 unk00;
    u32 effectParam;
    void *sprite;
    Ov02R17TaskArgs args;
} Ov02R17TaskWork;

extern const Ov02R17Entry ov02_022535E4[];
extern const void *ov02_02253468;

void DC_FlushRange(const void *, u32);
void GX_LoadOBJ(const void *, u32, u32);
void GX_LoadOBJPltt(const void *, u32, u32);
void *ov02_0224A33C(void *, void *, u32, u32, u32, s32, u32, u32);
void *sub_02068B0C(void *, const void *, const VecFx32 *, int, void *, u32);
void *sub_02068D98(void *);
u32 sub_02068D90(void *);
void sub_02068DB8(void *, VecFx32 *);
void *ov02_0224A3F0(u32, const VecFx32 *, u32, u32);
void Sprite_SetDrawFlag(void *, BOOL);

void ov02_0224A810(void *, void *);
void ov02_0224A834(void *, void *);
void ov02_0224A868(void *, void *);
void ov02_0224A88C(void *, void *);
void *ov02_0224A9B8(void *, void *);
void ov02_0224A9D8(void *, void *);
void ov02_0224AA44(void *, const VecFx32 *, const VecFx32 *, u32, u32, void *);
int ov02_0224AA80(void *, Ov02R17TaskWork *);

#endif
