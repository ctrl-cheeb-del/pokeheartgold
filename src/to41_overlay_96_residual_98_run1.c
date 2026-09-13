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

void ov96_0220D428(Ov96TaskA *data, u8 valueC, u8 valueD) {
    if (data->unk4 == NULL) {
        GF_AssertFail();
    }
    if (data->unk0 == NULL) {
        GF_AssertFail();
    }
    if (data->task != NULL) {
        SysTask_Destroy(data->task);
    }
    data->unk10 = 0;
    data->valueC = valueC;
    data->valueD = valueD;
    data->task = SysTask_CreateOnMainQueue(ov96_0220D360, data, 2);
}

void ov96_0220D468(void *task, void *raw) {
    Ov96TaskB *data = raw;
    switch (data->state) {
    case 0:
        data->scale = 1.0 - (double)data->counter * 0.3;
        if (data->counter > 1) {
            data->counter = 0;
            data->state++;
            return;
        }
        ov96_021EB10C(data->sprite, 1.0f, data->scale);
        data->counter++;
        return;
    case 1:
        data->scale = 1.0 + (double)data->counter * 0.3;
        if (data->counter > 1) {
            data->task = NULL;
            ov96_021EB10C(data->sprite, 1.0f, 1.0f);
            SysTask_Destroy(task);
            return;
        }
        ov96_021EB10C(data->sprite, 1.0f, data->scale);
        data->counter++;
        return;
    default:
        GF_AssertFail();
        return;
    }
}

void ov96_0220D52C(void *raw, void *sprite) {
    Ov96TaskB *data = raw;
    if (data->task != NULL) {
        SysTask_Destroy(data->task);
    }
    data->sprite = sprite;
    data->counter = 0;
    data->state = 0;
    data->task = SysTask_CreateOnMainQueue(ov96_0220D468, data, 0);
}
