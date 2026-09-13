#include "to41_overlay_96_residual_98_private.h"

typedef struct Ov96TaskA {
    void *unk0;
    void *unk4;
    void *task;
    u8 valueC;
    u8 valueD;
    u8 padE[2];
    u32 unk10;
} Ov96TaskA;

typedef struct Ov96TaskB {
    void *sprite;
    void *task;
    f32 scale;
    u16 counter;
    u16 state;
} Ov96TaskB;

extern void *SysTask_CreateOnMainQueue(void (*callback)(void *, void *), void *data, u32 priority);
extern void SysTask_Destroy(void *task);
extern void ov96_0220D360(void *task, void *data);
extern void ov96_0220D468(void *task, void *data);
extern void ManagedSprite_SetAffineScale(void *sprite, f32 x, f32 y);
extern void ManagedSprite_SetAnim(void *sprite, int animation);
extern void PlaySE_SetPitch(u32 se, s16 pitch);
void ov96_0220D428(Ov96TaskA *data, u8 valueC, u8 valueD);
BOOL ov96_0220D694(void *data);
void ov96_0220DBCC(void *data, f32 scale);
void ov96_0220DBE8(void *data, int animation, s16 x, s16 y);
BOOL ov96_0220D8C4(void *data, fx32 x, fx32 y);
void ov96_0220DC38(u32 value);
void ov96_0220DB3C(void *data, u32 mode, BOOL draw);

void ov96_0220DB3C(void *data, u32 mode, BOOL draw) {
    BOOL inverse;
    switch (mode) {
    case 0:
        ManagedSprite_SetDrawFlag(PTR(data, 0), draw);
        inverse = draw == FALSE;
        ManagedSprite_SetDrawFlag(PTR(data, 4), inverse);
        ManagedSprite_SetDrawFlag(PTR(data, 8), draw);
        ManagedSprite_SetDrawFlag(PTR(data, 0xC), inverse);
        break;
    case 1:
        inverse = draw == FALSE;
        ManagedSprite_SetDrawFlag(PTR(data, 0), inverse);
        ManagedSprite_SetDrawFlag(PTR(data, 4), draw);
        ManagedSprite_SetDrawFlag(PTR(data, 8), inverse);
        ManagedSprite_SetDrawFlag(PTR(data, 0xC), draw);
        break;
    case 2:
        ManagedSprite_SetDrawFlag(PTR(data, 0), draw);
        ManagedSprite_SetDrawFlag(PTR(data, 4), draw);
        ManagedSprite_SetDrawFlag(PTR(data, 8), draw);
        ManagedSprite_SetDrawFlag(PTR(data, 0xC), draw);
        break;
    }
}

void ov96_0220DBCC(void *data, f32 scale) {
    ManagedSprite_SetAffineScale(PTR(data, 0), scale, scale);
    ManagedSprite_SetAffineScale(PTR(data, 4), scale, scale);
}

void ov96_0220DBE8(void *data, int animation, s16 x, s16 y) {
    int seq = animation - 3;
    if (seq >= 4) {
        GF_AssertFail();
    }
    ManagedSprite_SetPositionXYWithSubscreenOffset(PTR(data, 0x10), x, y, 0x1E0000);
    ManagedSprite_SetPositionXYWithSubscreenOffset(PTR(data, 0x14), x, y, 0x1E0000);
    ManagedSprite_SetAnim(PTR(data, 0x10), seq);
    ManagedSprite_ResetSpriteAnimCtrlState(PTR(data, 0x14));
    ManagedSprite_SetDrawFlag(PTR(data, 0x10), TRUE);
    ManagedSprite_SetDrawFlag(PTR(data, 0x14), TRUE);
}

void ov96_0220DC38(u32 value) {
    s16 pitch;
    switch (value) {
    case 3:
        pitch = 0;
        break;
    case 4:
        pitch = 0x80;
        break;
    case 5:
        pitch = 0;
        break;
    case 6:
        pitch = 0xC0;
        break;
    default:
        GF_AssertFail();
        break;
    }
    PlaySE_SetPitch(0x88D, pitch);
}
