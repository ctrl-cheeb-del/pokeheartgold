#include "global.h"

#include "camera.h"
#include "heap.h"
#include "unk_02014DA0.h"

// The existing public API uses SPLEmitter pointers for this owning context.
typedef struct ParticleContext {
    void *manager;
    void *unk_04;
    void *unk_08;
    void *heapStart;
    void *heapCurrent;
    void *heapEnd;
    texAllocFun texAlloc;
    plttAllocFun plttAlloc;
    Camera *camera;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u16 perspective;
    u8 pad_32[2];
    VecFx32 pos;
    VecFx32 up;
    VecFx32 target;
    u32 texKeys[16];
    u32 plttKeys[16];
    u8 flags;
    u8 unk_D9;
    u8 slot;
    u8 unk_DB;
} ParticleContext;

extern ParticleContext *_021D10A8[16];
extern const VecFx32 _020F6078;
extern const VecFx32 _020F6084;
extern const VecFx32 _020F6090;
typedef void *(*ParticleAllocFunc)(u32 size);
extern const ParticleAllocFunc _020F609C[16];
extern void *SPL_Init(ParticleAllocFunc callback, int, int, int, int, int);
extern void sub_020154E4(ParticleContext *, const VecFx32 *);
extern void sub_020154B8(ParticleContext *);
extern void NNS_GfdSetFrmTexVramState(void *);
extern int NNS_GfdFreeLnkTexVram(u32);
extern void NNS_GfdSetFrmPlttVramState(void *);
extern int NNS_GfdFreeLnkPlttVram(u32);
void sub_02014F84(void);

void sub_02014DA0(void) {
    int i;
    for (i = 0; i < 16; i++) {
        _021D10A8[i] = NULL;
    }
}

SPLEmitter *sub_02014DB4(texAllocFun texAlloc, plttAllocFun plttAlloc, void *particleHeap, u32 workSize, BOOL makeCamera, enum HeapID heapID) {
    ParticleContext *ctx;
    int slot;

    for (slot = 0; slot < 16; slot++) {
        if (_021D10A8[slot] == NULL) {
            break;
        }
    }
    if (slot >= 16) {
        return NULL;
    }
    ctx = Heap_Alloc(heapID, sizeof(ParticleContext));
    GF_ASSERT(ctx != NULL);
    memset(ctx, 0, sizeof(ParticleContext));
    ctx->texAlloc = texAlloc;
    ctx->plttAlloc = plttAlloc;
    ctx->pos = _020F6090;
    ctx->up = _020F6078;
    ctx->target = _020F6084;
    memset(particleHeap, 0, workSize);
    ctx->heapStart = particleHeap;
    ctx->heapCurrent = particleHeap;
    ctx->heapEnd = (u8 *)particleHeap + workSize;
    ctx->slot = slot;
    _021D10A8[slot] = ctx;
    if (makeCamera == TRUE) {
        ctx->camera = Camera_New(heapID);
        ctx->unk_24 = 0;
        ctx->unk_28 = 0;
        ctx->unk_2C = 0;
        ctx->perspective = 2 * FX32_ONE;
        Camera_Init_FromTargetAndPos(&_020F6084, &_020F6090, ctx->perspective, 0, FALSE, ctx->camera);
        ctx->unk_DB = FALSE;
        Camera_SetStaticPtr(ctx->camera);
    }
    ctx->manager = SPL_Init(_020F609C[slot], 20, 200, 5, 6, 63);
    sub_020154E4(ctx, &_020F6078);
    return (SPLEmitter *)ctx;
}

void sub_02014EBC(SPLEmitter *emitter) {
    ParticleContext *ctx = (ParticleContext *)emitter;
    int i;
    int j;

    sub_020154B8(ctx);
    if (ctx->flags & 1) {
        NNS_GfdSetFrmTexVramState(ctx->texKeys);
    } else if (ctx->flags & 2) {
        for (i = 0; i < 16; i++) {
            if (ctx->texKeys[i] != 0) {
                NNS_GfdFreeLnkTexVram(ctx->texKeys[i]);
                ctx->texKeys[i] = 0;
            }
        }
    }
    if (ctx->flags & 4) {
        NNS_GfdSetFrmPlttVramState(ctx->plttKeys);
    } else if (ctx->flags & 8) {
        for (i = 0; i < 16; i++) {
            if (ctx->plttKeys[i] != 0) {
                NNS_GfdFreeLnkPlttVram(ctx->plttKeys[i]);
                ctx->plttKeys[i] = 0;
            }
        }
    }
    ctx->flags = 0;
    ctx->unk_08 = NULL;
    if (ctx->unk_04 != NULL) {
        Heap_Free(ctx->unk_04);
        ctx->unk_04 = NULL;
    }
    for (j = 0; j < 16; j++) {
        if (_021D10A8[j] == ctx) {
            _021D10A8[j] = NULL;
            break;
        }
    }
    if (ctx->camera != NULL) {
        Camera_Delete(ctx->camera);
    }
    Heap_Free(ctx);
}

void sub_02014F84(void) {
    int i;
    for (i = 0; i < 16; i++) {
        if (_021D10A8[i] != NULL) {
            sub_02014EBC((SPLEmitter *)_021D10A8[i]);
        }
    }
}
