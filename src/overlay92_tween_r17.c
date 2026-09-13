#include "global.h"

typedef struct Ov92Tween {
    s32 value;
    s32 start;
    s32 unk08;
    s32 delta;
    s32 frame;
    s32 duration;
} Ov92Tween;

BOOL ov92_02260870(Ov92Tween *tween);

BOOL ov92_02260870(Ov92Tween *tween) {
    BOOL finished;
    s32 frame;
    s32 value;

    if (tween->frame >= tween->duration) {
        frame = tween->duration;
        finished = TRUE;
    } else {
        frame = tween->frame;
        tween->frame++;
        finished = FALSE;
    }
    value = FX_Div((s32)(((s64)tween->delta * (frame << FX32_SHIFT) + 0x800) >> FX32_SHIFT), tween->duration << FX32_SHIFT);
    value += tween->start;
    tween->value = value;
    return finished;
}
