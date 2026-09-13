#ifndef OVERLAY07_CALLBACK_SUFFIX_PRIVATE_H
#define OVERLAY07_CALLBACK_SUFFIX_PRIVATE_H

#include "global.h"

#include "filesystem.h"
#include "heap.h"
#include "math_util.h"
#include "pokepic.h"
#include "seal_case.h"
#include "sprite_system.h"
#include "sys_task.h"
#include "sys_task_api.h"
#include "unk_02009D48.h"
#include "unk_02014DA0.h"
#include "unk_02091054.h"

typedef struct Ov07Params {
    u32 kind;
    enum HeapID heapId;
    u32 callbackId;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    SpriteSystem *spriteSystem;
    u32 unk20;
    u32 unk24;
} Ov07Params;

typedef struct Ov07CallbackWork {
    u32 unk00;
    u32 unk04;
    u32 state;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 active;
    u8 unk20;
    u8 unk21;
    s8 unk22;
    u8 unk23;
    u32 tickSprite;
    u32 unk28;
    SpriteManager *spriteManager;
    ManagedSprite *sprite;
    u8 pad34[0x90 - 0x34];
    Ov07Params params;
    s16 spriteX;
    s16 spriteY;
    s16 unkBC;
    s16 unkBE;
    u32 unkC0;
    u32 unkC4;
    u32 unkC8;
    SysTask *task;
    u8 padD0[0xDC - 0xD0];
    s32 delay;
} Ov07CallbackWork;

typedef struct Ov07EmitterInit {
    u32 unk00;
    s32 unk04;
} Ov07EmitterInit;

typedef struct Ov07Emitter {
    u32 index;
    enum HeapID heapId;
    Ov07EmitterInit init;
    SPLEmitter *emitter;
    u32 unk14;
    SysTask *task;
    s32 unk1C;
    u32 unk20;
} Ov07Emitter;

typedef struct Ov07EmitterManager {
    enum HeapID heapId;
    s32 unk04;
    Ov07Emitter *emitters[16];
} Ov07EmitterManager;

typedef struct Ov07Table22 {
    u32 vals[22];
} Ov07Table22;

typedef struct Ov07Table7 {
    u8 vals[7];
} Ov07Table7;

extern const Ov07Table7 ov07_0223777C;
extern const Ov07Table22 ov07_02237784;
extern const s16 ov07_022377DC[][2];
extern const s16 ov07_022377F4[][3];

void ov07_0221C69C(void);
SPLEmitter *ov07_0221FE88(enum HeapID heapId, u32 a1, int a2);
void ov07_0221FF2C(SPLEmitter *emitter);
void ov07_02221F04(int a0, int a1, s16 *x, s16 *y);
int ov07_02232658(void *a0, int a1);
fx32 FX_Sqrt(fx32 x);
u32 ov07_022325BC(u32 kind);
void ov07_02233D60(SysTask *task, void *data);

Ov07CallbackWork *ov07_02233DB8(Ov07Params *params);
BOOL ov07_02233E88(Ov07CallbackWork *work);
BOOL ov07_02233EA0(Ov07CallbackWork *work);
void ov07_02233EB8(Ov07CallbackWork *work, u32 a1);
BOOL ov07_02233EBC(Ov07CallbackWork *work, u32 a1);
void ov07_02233ECC(Ov07CallbackWork *work);
void ov07_02233EFC(Ov07CallbackWork *work, u32 callbackId);
u32 ov07_02233F20(Ov07CallbackWork *work);
void ov07_02233F30(Ov07CallbackWork *work);
void ov07_022341A4(Ov07CallbackWork *work, s16 *x, s16 *y);
void ov07_022342E4(Ov07CallbackWork *work);
void ov07_0223441C(Ov07CallbackWork *work);
void ov07_0223449C(Ov07CallbackWork *work, int flag);
void ov07_022344A8(Ov07CallbackWork *work, s16 x, s16 y);
void ov07_022344B4(Ov07CallbackWork *work, u16 a1);
void ov07_022344C0(Ov07CallbackWork *work, u32 a1);
void ov07_022344C4(Ov07CallbackWork *work, u16 a1);
void ov07_022344D0(Ov07CallbackWork *work, int a1);
void ov07_022344DC(Ov07CallbackWork *work, s32 a1);
s32 ov07_022344E4(s16 x0, s16 y0, s16 x1, s16 y1);
s32 ov07_02234510(const SEAL *seal);
u8 ov07_02234530(const SEAL *seal);
Ov07EmitterManager *ov07_0223458C(enum HeapID heapId, s32 *a1);
Ov07Emitter *ov07_022345C8(Ov07EmitterManager *mgr, Ov07EmitterInit *init);
void ov07_02234604(Ov07EmitterManager *mgr);
void ov07_02234628(Ov07EmitterManager *mgr);
Ov07Emitter *ov07_02234658(enum HeapID heapId, Ov07EmitterInit *init);
void ov07_02234694(Ov07Emitter *emitter);
u32 ov07_022346BC(Ov07Emitter *emitter);
void ov07_022346C0(SysTask *task, void *data);
void ov07_022346E4(Ov07Emitter *emitter, void (*cb)(SPLEmitter *));
void *ov07_02234710(void);
s32 ov07_02234718(u32 id);
s16 ov07_02234B5C(u32 a0, u32 a1);

typedef struct Ov07PicWork {
    u32 unk00;
    u32 unk04;
} Ov07PicWork;

void ov07_0223476C(Ov07PicWork *w, u32 a1, int a2, u32 a3);
void ov07_0223474C(Ov07PicWork *w, u32 a1);
void ov07_0223475C(Ov07PicWork *w, u32 a1);

#endif // OVERLAY07_CALLBACK_SUFFIX_PRIVATE_H
