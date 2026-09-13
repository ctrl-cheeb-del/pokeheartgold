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

BOOL ov96_0220D694(void *data) {
    u32 state;
    BOOL result;

    if (data == NULL) {
        GF_AssertFail();
    }
    state = U32(data, 0xC);
    result = TRUE;
    if (state != 2 && state != 1) {
        result = FALSE;
    }
    return result;
}

void ov96_0220D6B0(void *data, u32 rawPosition) {
    const s16 *position = (const s16 *)rawPosition;
    S32(data, 0x10) = position[0] << FX32_SHIFT;
    S32(data, 0x14) = position[1] << FX32_SHIFT;
    U32(data, 0x40) |= 0x08000000;
}
