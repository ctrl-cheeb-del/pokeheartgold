#include "global.h"

typedef struct Ov71Work18 {
    void *ctx;
    u32 unk_04;
    s32 timer;
    u8 pad_0C[0xC0 - 0x0C];
    void *bgConfig;
    void *unk_C4;
    void *unk_C8;
    void *unk_CC;
    void *unk_D0;
    void *unk_D4;
    void *unk_D8;
    u8 pad_DC[0x160 - 0xDC];
    void *unk_160;
    void *unk_164;
} Ov71Work18;

extern s32 ov71_0224C0C4;
extern BOOL IsPaletteFadeFinished(void);
extern void BeginNormalPaletteFade(u32, u32, u32, u16, u32, u32, u32);
extern void FreeBgTilemapBuffer(void *, u32);
extern void PlaySE(u16);
extern void ov71_02246D40(void *);
extern void ov71_02246D54(void *);
extern void ov71_02247704(void *, u32);
extern void ov71_02247708(void *, u32);
extern void ov71_02248604(Ov71Work18 *);
extern void ov71_022488E4(Ov71Work18 *);
extern void ov71_02248A08(Ov71Work18 *);
extern void ov71_02248B54(Ov71Work18 *);
extern void *ov71_02248D0C(Ov71Work18 *, void *);
extern void ov71_02248E30(void *, u32, u32, u32);
extern void *ov71_02248EB4(Ov71Work18 *);
extern BOOL ov71_02249254(void *);
extern BOOL ov71_02249260(void *);
extern void ov71_0224926C(void *);

BOOL ov71_02248408(Ov71Work18 *work);
BOOL ov71_0224843C(Ov71Work18 *work, u32 *state);
BOOL ov71_02248484(Ov71Work18 *work, u32 *state);
BOOL ov71_02248530(Ov71Work18 *work, u32 *state);
void ov71_0224889C(Ov71Work18 *work);

void ov71_0224889C(Ov71Work18 *work) {
    if (work->unk_C8 != NULL) {
        ov71_02246D54(work->unk_C4);
    }
    FreeBgTilemapBuffer(work->bgConfig, 2);
    FreeBgTilemapBuffer(work->bgConfig, 6);
    FreeBgTilemapBuffer(work->bgConfig, 3);
    FreeBgTilemapBuffer(work->bgConfig, 7);
}
