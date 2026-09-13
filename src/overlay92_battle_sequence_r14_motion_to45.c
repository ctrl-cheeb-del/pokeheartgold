#include "overlay92_battle_sequence_r14_task_setup_to42_private.h"
#include "screen_fade.h"
#include "sprite_system.h"

#define U8_AT_LOCAL(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S32_AT_LOCAL(p, o) (*(s32 *)((u8 *)(p) + (o)))

void ov92_02260860(void *, s32, s32, s32);
BOOL ov92_02260870(void *);

void ov92_0225F254(SysTask *sysTask, void *data) {
    u8 *work = data;
    ManagedSprite_GetAnimationFrame(PTR_AT(work, 0xc));
    if (!IsPaletteFadeFinished() || U8_AT_LOCAL(PTR_AT(work, 0x2c), 0x34) == 1) {
        SysTask_Destroy(sysTask);
        Heap_Free(work);
        return;
    }
    switch (S32_AT_LOCAL(work, 0)) {
    case 0: {
        fx32 x;
        fx32 y;
        S32_AT_LOCAL(work, 8) = 0;
        ManagedSprite_GetSpritePositionFxXY(PTR_AT(work, 0xc), &x, &y);
        if (S32_AT_LOCAL(work, 4) == 0) {
            ov92_02260860(work + 0x14, y, y + 0x20000, 0x10);
        } else {
            ov92_02260860(work + 0x14, y, y - 0x20000, 4);
        }
        S32_AT_LOCAL(work, 0)
        ++;
        return;
    }
    case 1: {
        fx32 x;
        fx32 y;
        BOOL done = ov92_02260870(work + 0x14);
        ManagedSprite_GetSpritePositionFxXY(PTR_AT(work, 0xc), &x, &y);
        ManagedSprite_SetPositonFxXY(PTR_AT(work, 0xc), x, S32_AT_LOCAL(work, 0x14));
        if (done) {
            S32_AT_LOCAL(work, 0)
            ++;
        }
        return;
    }
    default:
        if (S32_AT_LOCAL(work, 4) == 0) {
            if (++S32_AT_LOCAL(work, 8) >= 0x23) {
                S32_AT_LOCAL(work, 4)
                ++;
                S32_AT_LOCAL(work, 0) = 0;
            }
        } else if (++S32_AT_LOCAL(work, 8) >= 10) {
            SysTask_Destroy(sysTask);
            Heap_Free(work);
        }
        return;
    }
}
