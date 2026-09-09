#include "global.h"

#include "camera.h"
#include "heap.h"
#include "sys_task.h"
#include "sys_task_api.h"
#include "unk_02014DA0.h"

typedef struct ParticleArena {
    u8 pad_00[0x10];
    u8 *current;
    u8 *end;
} ParticleArena;

extern void *_021D10A0[18];
extern const VecFx32 _020F6078;

#include "particle_internal.h"

extern ParticleContext *_021D10A8[16];

typedef struct ParticleManagerLite {
    u8 pad[8];
    BOOL active;
} ParticleManagerLite;

extern void *AllocAndReadWholeNarcMemberByIdPair(NarcId, int, enum HeapID);
extern void NNS_GfdGetFrmTexVramState(void *);
extern void NNS_GfdGetFrmPlttVramState(void *);
extern void SPL_Load(void *, void *);
extern void SPL_LoadTexByVRAMManager(void *);
extern void SPL_LoadTexByCallbackFunction(void *);
extern void SPL_LoadTexPlttByVRAMManager(void *);
extern void SPL_LoadTexPlttByCallbackFunction(void *);
extern void NNS_G3dGlbFlushP(void);
extern void SPL_Draw(void *, void *);
extern void SPL_Calc(void *);
extern SPLEmitter *SPL_Create(SPLManager *, int, void (*)(SPLEmitter *));
extern void SPL_DeleteAll(void *);
extern void SPL_Delete(void *, SPLEmitter *);

void sub_02015300(ParticleContext *ctx);
void sub_02015340(SysTask *task, ParticleContext *ctx);
void sub_020153D8(ParticleContext *ctx);
void sub_02015414(ParticleContext *ctx);
void sub_02015484(ParticleContext *ctx, int resNo, void (*callback)(SPLEmitter *));
void sub_020154B8(ParticleContext *ctx);
void sub_020154C4(ParticleContext *ctx, SPLEmitter *emitter);
void sub_020154D4(ParticleContext *ctx, VecFx32 *out);
void sub_020154E4(ParticleContext *ctx, const VecFx32 *up);
int sub_02015530(ParticleContext *ctx);
void sub_02015510(VecFx32 *out);
int sub_02015460(void);
void *sub_02015550(SPLEmitter *emitter, int type);
extern void spl_calc_gravity(const void *, SPLParticle *, VecFx32 *, SPLEmitter *);
extern void spl_calc_random(const void *, SPLParticle *, VecFx32 *, SPLEmitter *);
extern void spl_calc_magnet(const void *, SPLParticle *, VecFx32 *, SPLEmitter *);
extern void spl_calc_spin(const void *, SPLParticle *, VecFx32 *, SPLEmitter *);
extern void spl_calc_scfield(const void *, SPLParticle *, VecFx32 *, SPLEmitter *);
extern void spl_calc_convergence(const void *, SPLParticle *, VecFx32 *, SPLEmitter *);
void sub_0201560C(SPLEmitter *, VecFx16 *);
void sub_02015628(SPLEmitter *, VecFx32 *);

#define DECL_ALLOC(name) void *name(u32 size)
DECL_ALLOC(sub_02014FA4);
DECL_ALLOC(sub_02014FD0);
DECL_ALLOC(sub_02014FFC);
DECL_ALLOC(sub_02015028);
DECL_ALLOC(sub_02015054);
DECL_ALLOC(sub_02015080);
DECL_ALLOC(sub_020150AC);
DECL_ALLOC(sub_020150D8);
DECL_ALLOC(sub_02015104);
DECL_ALLOC(sub_02015130);
DECL_ALLOC(sub_0201515C);
DECL_ALLOC(sub_02015188);
DECL_ALLOC(sub_020151B4);
DECL_ALLOC(sub_020151E0);
DECL_ALLOC(sub_0201520C);
DECL_ALLOC(sub_02015238);

#define DEF_ALLOC(name, n)                                    \
    DECL_ALLOC(name) {                                        \
        ParticleArena *arena = (ParticleArena *)_021D10A0[n]; \
        u8 *ret = arena->current;                             \
        u8 *next = ret + size;                                \
        if ((u32)next & 3) {                                  \
            next += 4 - ((u32)next & 3);                      \
        }                                                     \
        arena->current = next;                                \
        GF_ASSERT(next < arena->end);                         \
        return ret;                                           \
    }

DEF_ALLOC(sub_02014FA4, 2)
DEF_ALLOC(sub_02014FD0, 3)
DEF_ALLOC(sub_02014FFC, 4)
DEF_ALLOC(sub_02015028, 5)
DEF_ALLOC(sub_02015054, 6)
DEF_ALLOC(sub_02015080, 7)
DEF_ALLOC(sub_020150AC, 8)
DEF_ALLOC(sub_020150D8, 9)
DEF_ALLOC(sub_02015104, 10)
DEF_ALLOC(sub_02015130, 11)
DEF_ALLOC(sub_0201515C, 12)
DEF_ALLOC(sub_02015188, 13)
DEF_ALLOC(sub_020151B4, 14)
DEF_ALLOC(sub_020151E0, 15)
DEF_ALLOC(sub_0201520C, 16)
DEF_ALLOC(sub_02015238, 17)

void *sub_02015264(NarcId narcId, int fileId, enum HeapID heapID) {
    return AllocAndReadWholeNarcMemberByIdPair(narcId, fileId, heapID);
}

void sub_0201526C(SPLEmitter *emitter, void *data, u32 flag, BOOL loadNow) {
    ParticleContext *ctx = (ParticleContext *)emitter;
    int i;
    int j;
    GF_ASSERT(ctx->manager != NULL);
    GF_ASSERT(ctx->resource == NULL);
    ctx->flags = flag;
    if (flag & 1) {
        NNS_GfdGetFrmTexVramState(ctx->texKeys);
    } else if (flag & 2) {
        for (i = 0; i < 16; i++) {
            ctx->texKeys[i] = 0;
        }
    }
    if (flag & 4) {
        NNS_GfdGetFrmPlttVramState(ctx->plttKeys);
    } else if (flag & 8) {
        for (j = 0; j < 16; j++) {
            ctx->plttKeys[j] = 0;
        }
    }
    ctx->resource = data;
    if (loadNow == TRUE) {
        sub_02015300(ctx);
        return;
    }
    SysTask_CreateOnVWaitQueue((SysTaskFunc)sub_02015340, ctx, 5);
}

void sub_02015300(ParticleContext *ctx) {
    texAllocFun texAlloc;
    plttAllocFun plttAlloc;
    SPLManager *manager;
    SPL_Load(ctx->manager, ctx->resource);
    _021D10A0[0] = ctx;
    texAlloc = ctx->texAlloc;
    manager = ctx->manager;
    if (texAlloc == NULL) {
        SPL_LoadTexByVRAMManager(manager);
    } else {
        SPL_LoadTexByCallbackFunction(manager);
    }
    plttAlloc = ctx->plttAlloc;
    manager = ctx->manager;
    if (plttAlloc == NULL) {
        SPL_LoadTexPlttByVRAMManager(manager);
    } else {
        SPL_LoadTexPlttByCallbackFunction(manager);
    }
    _021D10A0[0] = NULL;
}

void sub_02015340(SysTask *task, ParticleContext *ctx) {
    sub_02015300(ctx);
    SysTask_Destroy(task);
}

void sub_02015354(NNSGfdTexKey texKey) {
    int i;
    u8 *cursor;
    ParticleContext *ctx;
    GF_ASSERT(texKey != 0);
    GF_ASSERT(_021D10A0[0] != NULL);
    ctx = _021D10A0[0];
    cursor = (u8 *)ctx;
    for (i = 0; i < 16; i++) {
        if (*(u32 *)(cursor + 0x58) == 0) {
            ctx->texKeys[i] = texKey;
            return;
        }
        cursor += 4;
    }
    GF_ASSERT(FALSE);
}

void sub_02015394(NNSGfdPlttKey plttKey) {
    int i;
    u8 *cursor;
    ParticleContext *ctx;
    GF_ASSERT(plttKey != 0);
    GF_ASSERT(_021D10A0[0] != NULL);
    ctx = _021D10A0[0];
    cursor = (u8 *)ctx;
    for (i = 0; i < 16; i++) {
        if (*(u32 *)(cursor + 0x98) == 0) {
            ctx->plttKeys[i] = plttKey;
            return;
        }
        cursor += 4;
    }
    GF_ASSERT(FALSE);
}

void sub_020153D8(ParticleContext *ctx) {
    if (ctx->camera != NULL) {
        Camera_ApplyPerspectiveType(ctx->perspectiveType, ctx->camera);
        Camera_SetStaticPtr(ctx->camera);
        Camera_PushLookAtToNNSGlb();
    }
    NNS_G3dGlbFlushP();
    SPL_Draw(ctx->manager, &NNS_G3dGlb.cameraMtx);
    if (ctx->camera != NULL) {
        Camera_UnsetStaticPtr();
    }
    NNS_G3dGlbFlushP();
}

void sub_02015414(ParticleContext *ctx) {
    SPL_Calc(ctx->manager);
}

int sub_02015420(void) {
    int count = 0, i;
    for (i = 0; i < 16; i++) {
        if (_021D10A8[i] != NULL) {
            count++;
        }
    }
    return count;
}

int sub_0201543C(void) {
    int count = 0, i;
    for (i = 0; i < 16; i++) {
        if (_021D10A8[i] != NULL) {
            sub_020153D8(_021D10A8[i]);
            count++;
        }
    }
    return count;
}

int sub_02015460(void) {
    int count = 0, i;
    for (i = 0; i < 16; i++) {
        if (_021D10A8[i] != NULL) {
            sub_02015414(_021D10A8[i]);
            count++;
        }
    }
    return count;
}

void sub_02015484(ParticleContext *ctx, int resNo, void (*callback)(SPLEmitter *)) {
    ctx->emitter = SPL_Create(ctx->manager, resNo, callback);
}

void sub_02015494(SPLEmitter *emitter, int resNo, void (*callback)(SPLEmitter *), void *arg) {
    ParticleContext *ctx = (ParticleContext *)emitter;
    SPLEmitter *result;
    // Preserve the original callback-argument and emitter store order.
    *(void *volatile *)&_021D10A0[1] = arg;
    result = SPL_CreateWithInitialize(ctx->manager, resNo, callback);
    *(void *volatile *)&_021D10A0[1] = NULL;
    *(void *volatile *)&ctx->emitter = result;
}

BOOL sub_020154B0(SPLEmitter *emitter) {
    return ((ParticleManagerLite *)((ParticleContext *)emitter)->manager)->active;
}
void sub_020154B8(ParticleContext *ctx) {
    SPL_DeleteAll(ctx->manager);
}
void sub_020154C4(ParticleContext *ctx, SPLEmitter *emitter) {
    SPL_Delete(ctx->manager, emitter);
}
void *sub_020154D0(SPLEmitter *emitter) {
    return ((ParticleContext *)emitter)->heapStart;
}
void sub_020154D4(ParticleContext *ctx, VecFx32 *out) {
    *out = ctx->up;
}
void sub_020154E4(ParticleContext *ctx, const VecFx32 *up) {
    ctx->up = *up;
    Camera_SetLookAtCamUp((VecFx32 *)up, ctx->camera);
}
void *sub_02015504(void) {
    return _021D10A0[1];
}
void sub_02015510(VecFx32 *out) {
    *out = _020F6078;
}
Camera *sub_02015524(SPLEmitter *emitter) {
    return ((ParticleContext *)emitter)->camera;
}
void sub_02015528(SPLEmitter *emitter, int type) {
    ((ParticleContext *)emitter)->perspectiveType = type;
}
int sub_02015530(ParticleContext *ctx) {
    return ctx->perspectiveType;
}
void sub_02015538(SPLEmitter *emitter, VecFx16 *axis) {
    axis->x = *(const u16 *)&emitter->axis.x;
    axis->y = *(const u16 *)&emitter->axis.y;
    axis->z = *(const u16 *)&emitter->axis.z;
}

void *sub_02015550(SPLEmitter *emitter, int type) {
    SPLResource *resource = emitter->p_res;
    register int j;
    int count = resource->fld_num;
    register SPLField *field;
    if (count == 0) {
        return NULL;
    }
    j = 0;
    if (count > 0) {
        field = resource->fld_ary;
        do {
            if (field == NULL) {
                goto next;
            }
            switch (type) {
            case 0:
                if (field->p_exec == spl_calc_gravity) {
                    return (void *)field->p_obj;
                }
                break;
            case 1:
                if (field->p_exec == spl_calc_random) {
                    return (void *)field->p_obj;
                }
                break;
            case 2:
                if (field->p_exec == spl_calc_magnet) {
                    return (void *)field->p_obj;
                }
                break;
            case 3:
                if (field->p_exec == spl_calc_spin) {
                    return (void *)field->p_obj;
                }
                break;
            case 4:
                if (field->p_exec == spl_calc_scfield) {
                    return (void *)field->p_obj;
                }
                break;
            case 5:
                if (field->p_exec == spl_calc_convergence) {
                    return (void *)field->p_obj;
                }
                break;
            default:
                return NULL;
            }
next:
            j++;
            field++;
        } while (j < count);
    }
    return NULL;
}

void sub_0201560C(SPLEmitter *emitter, VecFx16 *value) {
    VecFx16 *field = sub_02015550(emitter, 0);
    if (field != NULL) {
        *field = *value;
    }
}

void sub_02015628(SPLEmitter *emitter, VecFx32 *value) {
    VecFx32 *field = sub_02015550(emitter, 2);
    if (field != NULL) {
        *field = *value;
    }
}
