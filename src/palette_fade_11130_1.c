#include "global.h"

typedef struct EffectContext {
    s32 f[9];
} EffectContext;
typedef struct EffectWork {
    s32 f[38];
} EffectWork;

extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void GF_AssertFail(void);
extern void sub_02010EC8(void *);
extern void sub_02010F34(u32, u32, u32);
extern void sub_02011068(u32, u32, u32, u32);
extern void sub_020121F4(void *);
extern void sub_02011AD8(EffectWork *);
extern void sub_02011D08(EffectWork *);
extern void sub_02011F10(void *);
extern void sub_02012204(void *);
extern void sub_02012290(void *);
extern void sub_02010F00(void);
extern void SysTask_CreateOnVWaitQueue(void (*)(void), void *, u32);
extern void sub_0200FFB4(u32, u32, u32);
extern void sub_02010AB0(void *, void *, void *, const void *, const void *, u32);
extern void sub_02010F84(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern s16 *sub_02010EE0(void *, int);
extern void sub_02010A00(int, s32 *, int, int);
extern int sub_02010A7C(int, int);
extern void sub_02010A8C(void *, void *);
extern void sub_02013488(u32, int, int, int, int, u32, u32);
extern void sub_02011A44(int, int, int, int, int *, int *);
extern u32 FX_Sqrt(u32);
extern BOOL sub_020117FC(EffectWork *);
extern BOOL sub_020119F4(EffectWork *);
extern BOOL sub_02011CB8(EffectWork *);
extern BOOL sub_02011EC0(EffectWork *);
extern BOOL sub_020121A4(EffectWork *);
extern void sub_020117A0(void *, const void *, u32, u32, u32, u32);
extern void sub_02011918(void *, const void *, u32, u32, u32, u32, u32, u32);
extern void sub_02011BF0(void *, const void *, u32, u32, u32, u32, u32, u32);
extern void sub_02011DEC(void *, const void *, u32, u32, u32, u32, u32, u32);
extern void sub_02012090(void *, const void *, u32, u32, u32, u32, u32, u32);

void sub_0201164C(EffectContext *, const void *);
BOOL sub_0201169C(EffectContext *);
void sub_020116EC(EffectContext *, const void *, const void *);
BOOL sub_02011744(EffectContext *);
void sub_020117A0(void *, const void *, u32, u32, u32, u32);
BOOL sub_020117FC(EffectWork *);
void sub_02011884(EffectContext *, const void *);
BOOL sub_020118BC(EffectContext *);
BOOL sub_020119F4(EffectWork *);
void sub_02011AD8(EffectWork *);
void sub_02011A44(int, int, int, int, int *, int *);
void sub_02011B5C(EffectContext *, const void *);
BOOL sub_02011B94(EffectContext *);
BOOL sub_02011CB8(EffectWork *);
void sub_02011D08(EffectWork *);
void sub_02011D60(EffectContext *, const void *);
BOOL sub_02011D98(EffectContext *);
BOOL sub_02011EC0(EffectWork *);
void sub_02011FF8(EffectContext *, const void *);
BOOL sub_02012030(EffectContext *);
BOOL sub_020121A4(EffectWork *);

void sub_0201164C(EffectContext *ctx, const void *config_) {
    const u8 *config = config_;
    EffectWork *work;
    ctx->f[5] = (u32)Heap_Alloc(ctx->f[8], 0x4C);
    work = (EffectWork *)ctx->f[5];
    sub_020117A0(work, config, ctx->f[1], ctx->f[2], ctx->f[4], ctx->f[6]);
    if (config[8] == 0) {
        sub_02011068(ctx->f[6], 1, work->f[12], work->f[17]);
    } else {
        sub_02011068(ctx->f[6], 2, work->f[12], work->f[17]);
    }
    ctx->f[3]++;
}

BOOL sub_0201169C(EffectContext *ctx) {
    int result = FALSE;
    EffectWork *work = (EffectWork *)ctx->f[5];
    switch (ctx->f[3]) {
    case 1:
        if (sub_020117FC(work) == 1) {
            sub_02010F34(work->f[17], ctx->f[6], ctx->f[4]);
            ctx->f[3]++;
        }
        break;
    case 2:
        Heap_Free(work);
        ctx->f[5] = result;
        ctx->f[3]++;
        result = TRUE;
        break;
    case 3:
        result = TRUE;
        break;
    }
    return result;
}

void sub_020116EC(EffectContext *ctx, const void *a, const void *b) {
    EffectWork *work;
    ctx->f[5] = (u32)Heap_Alloc(ctx->f[8], 0x98);
    work = (EffectWork *)ctx->f[5];
    sub_020117A0(work, a, ctx->f[1], ctx->f[2], ctx->f[4], ctx->f[6]);
    sub_020117A0((u8 *)work + 0x4C, b, ctx->f[1], ctx->f[2], ctx->f[4], ctx->f[6]);
    sub_02011068(ctx->f[6], 3, ctx->f[4], work->f[17]);
    ctx->f[3]++;
}

BOOL sub_02011744(EffectContext *ctx) {
    int result = FALSE;
    EffectWork *work = (EffectWork *)ctx->f[5];
    switch (ctx->f[3]) {
    case 1: {
        int done = sub_020117FC(work);
        done += sub_020117FC((EffectWork *)((u8 *)work + 0x4C));
        if (done == 2) {
            sub_02010F34(work->f[17], ctx->f[6], ctx->f[4]);
            ctx->f[3]++;
        }
        break;
    }
    case 2:
        Heap_Free(work);
        ctx->f[5] = result;
        ctx->f[3]++;
        result = TRUE;
        break;
    case 3:
        result = TRUE;
        break;
    }
    return result;
}
