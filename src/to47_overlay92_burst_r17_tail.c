#include "global.h"

typedef struct ManagedSprite ManagedSprite;
typedef struct SysTask SysTask;

typedef struct Ov92Tween {
    s32 value;
    s32 start;
    s32 unk08;
    s32 delta;
    s32 frame;
    s32 duration;
} Ov92Tween;

typedef struct Ov92OffsetTable {
    s32 v[6];
} Ov92OffsetTable;

typedef struct Ov92BurstTask {
    s32 active;
    s32 state;
    ManagedSprite *sprites[3];
    u8 motion[0x90];
    void *context;
} Ov92BurstTask;

typedef struct Ov92Work {
    u8 unk00[0x14];
    void *unk14;
    u8 unk18[0x2490 - 0x18];
    Ov92BurstTask tasks[8];
} Ov92Work;

extern const Ov92OffsetTable ov92_02263E70;
extern const Ov92OffsetTable ov92_02263E88;

BOOL IsPaletteFadeFinished(void);
void Sprite_DeleteAndFreeResources(ManagedSprite *sprite);
void SysTask_Destroy(SysTask *task);
void ManagedSprite_GetSpritePositionFxXY(ManagedSprite *sprite, fx32 *x, fx32 *y);
void ManagedSprite_SetPositonFxXY(ManagedSprite *sprite, fx32 x, fx32 y);
void ManagedSprite_SetAnim(ManagedSprite *sprite, int anim);
void ManagedSprite_TickFrame(ManagedSprite *sprite);
void ov92_02260798(Ov92Tween *tween, fx32 start, fx32 end, s32 delta, s32 duration);
BOOL ov92_022607F8(Ov92Tween *tween);
ManagedSprite *ov92_0225E7E4(void *work, u16 x, u16 y);
SysTask *SysTask_CreateOnMainQueue(void (*func)(SysTask *, void *), void *arg, u32 priority);

void ov92_022608B8(SysTask *task, Ov92BurstTask *work);
void ov92_02260A38(Ov92Work *work, u16 x, u16 y);

void ov92_022608B8(SysTask *task, Ov92BurstTask *work) {
    BOOL done[4][2];
    Ov92OffsetTable xOffsets;
    Ov92OffsetTable yOffsets;
    fx32 x;
    fx32 y;
    BOOL allDone;
    int i;
    Ov92Tween *case1XTween;

    allDone = TRUE;
    xOffsets = ov92_02263E70;
    yOffsets = ov92_02263E88;

    if (!IsPaletteFadeFinished() || *((u8 *)work->context + 0x34) == 1) {
        for (i = 0; i < 3; i++) {
            Sprite_DeleteAndFreeResources(work->sprites[i]);
        }
        work->active = FALSE;
        SysTask_Destroy(task);
        return;
    }

    switch (work->state) {
    case 0: {
        Ov92BurstTask *cur;
        const s32 *xOffset;
        Ov92Tween *xTween;
        const s32 *yOffset;
        Ov92Tween *yTween;
        i = 0;
        cur = work;
        xOffset = xOffsets.v;
        xTween = (Ov92Tween *)((u8 *)work + 0x14);
        yOffset = yOffsets.v;
        yTween = (Ov92Tween *)((u8 *)work + 0x2C);
        for (; i < 3; i++) {
            ManagedSprite_GetSpritePositionFxXY(cur->sprites[0], &x, &y);
            ov92_02260798(xTween, x, x + *xOffset, 0x4CD, 8);
            ov92_02260798(yTween, y, y + *yOffset, 0x333, 8);
            cur = (Ov92BurstTask *)((u8 *)cur + 4);
            xOffset++;
            xTween += 2;
            yOffset++;
            yTween += 2;
        }
        work->state++;
        return;
    }
    case 1: {
        Ov92Tween *yTween;
        BOOL *donep;
        Ov92BurstTask *cur;
        Ov92BurstTask *values;
        i = 0;
        case1XTween = (Ov92Tween *)((u8 *)work + 0x14);
        donep = &done[0][0];
        yTween = (Ov92Tween *)((u8 *)work + 0x2C);
        values = work;
        cur = values;
        for (; i < 3; i++) {
            donep[0] = ov92_022607F8(case1XTween);
            donep[1] = ov92_022607F8(yTween);
            ManagedSprite_SetPositonFxXY(cur->sprites[0],
                                         *(fx32 *)((u8 *)values + 0x14),
                                         *(fx32 *)((u8 *)values + 0x2C));
            if (!donep[0] || !donep[1]) {
                allDone = FALSE;
            }
            ManagedSprite_TickFrame(cur->sprites[0]);
            case1XTween += 2;
            donep += 2;
            yTween += 2;
            values = (Ov92BurstTask *)((u8 *)values + 0x30);
            cur = (Ov92BurstTask *)((u8 *)cur + 4);
        }
        if (allDone) {
            work->state++;
        }
        break;
    }
    default:
        for (i = 0; i < 3; i++) {
            Sprite_DeleteAndFreeResources(work->sprites[i]);
        }
        work->active = FALSE;
        SysTask_Destroy(task);
        break;
    }
}

void ov92_02260A38(Ov92Work *work, u16 x, u16 y) {
    int slot;
    for (slot = 0; slot < 8; slot++) {
        if (work->tasks[slot].active != 1) {
            int i;
            work->tasks[slot].context = work->unk14;
            work->tasks[slot].state = 0;
            work->tasks[slot].active = 1;
            for (i = 0; i < 3; i++) {
                work->tasks[slot].sprites[i] = ov92_0225E7E4(work, x, y);
                ManagedSprite_SetAnim(work->tasks[slot].sprites[i], (x * (slot + 1) + (i + 1) * y) % 3);
            }
            SysTask_CreateOnMainQueue((void (*)(SysTask *, void *))ov92_022608B8, &work->tasks[slot], 1 << 12);
            return;
        }
    }
}
