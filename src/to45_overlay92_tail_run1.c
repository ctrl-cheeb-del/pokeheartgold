#include "screen_fade.h"
#include "to45_overlay92_tail_private.h"

void ov92_02260860(Ov92Tween *tween, s32 start, s32 end, s32 duration);
BOOL ov92_02260870(Ov92Tween *tween);
void ManagedSprite_SetAnim(void *sprite, int anim);
void ManagedSprite_SetDrawPriority(void *sprite, int priority);
void ManagedSprite_SetAffineOverwriteMode(void *sprite, int mode);
void ManagedSprite_GetAffineScale(void *sprite, f32 *x, f32 *y);
void ManagedSprite_SetPaletteOverrideOffset(void *sprite, int offset);
void ManagedSprite_SetAffineScale(void *sprite, f32 x, f32 y);

void ov92_0225F338(SysTask *task, Ov92SpriteTask *work) {
    BOOL done;
    f32 x;
    f32 y;
    f32 scale;
    f32 roundedFloat;
    s32 rounded;

    if (!IsPaletteFadeFinished() || *((u8 *)work->parent + 0x34) == 1) {
        work->active = 0;
        SysTask_Destroy(task);
        return;
    }

    switch (work->state) {
    case 0:
        ManagedSprite_SetAnim(work->sprite, 7);
        ManagedSprite_SetDrawPriority(work->sprite, 0);
        ManagedSprite_SetAffineOverwriteMode(work->sprite, 2);
        ManagedSprite_GetAffineScale(work->sprite, &x, &y);
        if (y > 0.0f) {
            roundedFloat = y * 4096.0f + 0.5f;
        } else {
            roundedFloat = y * 4096.0f - 0.5f;
        }
        rounded = (s32)roundedFloat;
        ov92_02260860(&work->tween, rounded, 0x2000, 2);
        ManagedSprite_SetPaletteOverrideOffset(work->sprite, *work->current - 1);
        work->state++;
    case 1:
        done = ov92_02260870(&work->tween);
        scale = (f32)work->tween.value / 4096.0f;
        ManagedSprite_SetAffineScale(work->sprite, 1.0f, scale);
        if (done) {
            work->state++;
        }
        return;
    case 2:
        ov92_02260860(&work->tween, 0x2000, 0x666, 4);
        work->state++;
    case 3:
        done = ov92_02260870(&work->tween);
        scale = (f32)work->tween.value / 4096.0f;
        ManagedSprite_SetAffineScale(work->sprite, 1.0f, scale);
        if (done) {
            work->state++;
        }
        return;
    case 4:
        if (work->previous != *work->current) {
            work->state = 0;
        } else {
            if (work->mode == 0) {
                ov92_02260860(&work->tween, 0x666, 0xCCD, 2);
            } else {
                ov92_02260860(&work->tween, 0xCCD, 0x666, 4);
            }
            work->state++;
        }
        work->previous = *work->current;
        if (*work->current == 0) {
            work->state = 0xFF;
        }
        return;
    case 5:
        done = ov92_02260870(&work->tween);
        scale = (f32)work->tween.value / 4096.0f;
        ManagedSprite_SetAffineScale(work->sprite, 1.0f, scale);
        if (done) {
            work->state = 4;
            work->mode ^= 1;
        }
        return;
    default:
        ManagedSprite_SetAffineScale(work->sprite, 1.0f, 1.0f);
        ManagedSprite_SetAnim(work->sprite, 5);
        ManagedSprite_SetDrawPriority(work->sprite, 2);
        ManagedSprite_SetAffineOverwriteMode(work->sprite, 0);
        work->active = 0;
        SysTask_Destroy(task);
        return;
    }
}
