#include "overlay95_sprite_resources_r5_private.h"

BOOL ov95_021E60A4(Ov95R5Work *work, int index) {
    int *state = (int *)&work->state80;
    int finished;
    s16 x;
    s16 y;
    f32 sx;
    f32 sy;

    if (state[0] == 0) {
        if (state[1] >= 10) {
            state[0]++;
            state[1] = 0;
        } else {
            finished = 0;
            x = ov95_021E75DC[index][state[1]];
            y = ov95_021E762C[index][state[1]];
            sx = ov95_021E76D0[index][state[1]];
            sy = ov95_021E7770[index][state[1]];
            if (x == 0xFF) {
                x = 0;
                finished++;
            }
            if (y == 0xFF) {
                y = 0;
                finished++;
            }
            ManagedSprite_OffsetPositionXY(work->sprite74, x, y);
            if (sx != 0.0f) {
                ManagedSprite_SetAffineScale(work->sprite74, sx, sy);
            } else {
                finished++;
            }
            if (finished != 3) {
                state[1]++;
                goto running;
            }
            state[0]++;
        }
    }
    state[0] = 0;
    state[1] = 0;
    return FALSE;

running:
    return TRUE;
}
