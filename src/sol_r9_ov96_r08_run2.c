#include "sol_r9_ov96_r08_private.h"

void ov96_02216A54(SolR9Ov96R08Animation *work, const s16 *position, u32 *flags, BOOL clear, void *course) {
    ov96_021EAB38(work->owner, 1);
    ManagedSprite_SetPositionXYWithSubscreenOffset(work->sprite10, position[0], position[1], 0x1E0000);
    ManagedSprite_ResetSpriteAnimCtrlState(work->sprite10);
    ManagedSprite_SetDrawFlag(work->spriteC, FALSE);
    ov96_022193CC(0x8B6, course);
    if (clear) {
        *flags &= 0xFFF9FFFF;
    }
}
