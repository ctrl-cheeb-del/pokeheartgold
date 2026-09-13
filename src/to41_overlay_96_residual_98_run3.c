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

BOOL ov96_0220D8C4(void *data, fx32 x, fx32 y) {
    s32 outY;
    s32 outX;

    ov96_021EB06C(PTR(data, 4), x >> FX32_SHIFT, y >> FX32_SHIFT, &outY, &outX);
    if (outY <= 0 || outX <= 0 || outY >= 0xFF || outX >= 0xFF) {
        return TRUE;
    }
    if (outY < 8 || outY >= 0xF8 || outX < 8 || outX >= 0xB4) {
        return TRUE;
    }
    return FALSE;
}
