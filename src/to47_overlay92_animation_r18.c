#include "global.h"

#include "to47_overlay92_animation_r18_private.h"

void ov92_02261208(Ov92AnimState *work) {
    s16 limit[4] = { ov92_02263E04[0], ov92_02263E04[1], ov92_02263E04[2], ov92_02263E04[3] };
    Ov92DoneFlags done;
    s16 x, y;
    s16 *limitp = limit;
    int i;
    ManagedSprite *sprite;

    done = ov92_02263E3C;

    if (work->active != 0) {
        switch (work->state) {
        case 0:
            for (i = 0; i < 4; i++) {
                sprite = work->sprites[i];
                if (sprite != NULL) {
                    ManagedSprite_GetPositionXY(sprite, &x, &y);
                    if (y > *limitp) {
                        y -= 6;
                        ManagedSprite_SetPositionXY(sprite, x, y);
                        done.v[i] = 0;
                    }
                }
                limitp++;
            }
            if (done.v[0] != 0 && done.v[1] != 0 && done.v[2] != 0 && done.v[2] != 0) {
                work->unk28 = 0;
                work->unk50 = 0;
                work->state++;
            }
            break;
        case 1:
            if (work->unk50 == 1 && ++work->unk28 >= 15) {
                work->state++;
            }
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                sprite = work->sprites[i];
                if (sprite != NULL) {
                    ManagedSprite_GetPositionXY(sprite, &x, &y);
                    if (y < 0xE0) {
                        y += 6;
                        ManagedSprite_SetPositionXY(sprite, x, y);
                        done.v[i] = 0;
                    }
                }
            }
            if (done.v[0] != 0 && done.v[1] != 0 && done.v[2] != 0 && done.v[2] != 0) {
                work->state++;
            }
            break;
        default:
            work->unk50 = 0;
            work->active = 0;
            work->state = 0;
            break;
        }
        for (i = 0; i < 4; i++) {
            if (work->sprites[i] != NULL) {
                ManagedSprite_TickTwoFrames(work->sprites[i]);
            }
        }
    }
}

void ov92_0226135C(Ov92AnimState *work) {
    int i;
    int angle;
    ManagedSprite *sprite;

    if (work->active != 0) {
        switch (work->state) {
        case 0:
            for (i = 0; i < 8; i++) {
                sprite = work->sprites[i];
                angle = i * 20;
                sub_02018198((u8 *)sprite + 0x88, angle % 40);
                sub_020182A0(sprite, 1);
            }
            work->unk4C = 0;
            work->state++;
            break;
        case 1:
            if (work->unk50 == 1 && ++work->unk4C >= 15) {
                work->state++;
            }
            break;
        default:
            for (i = 0; i < 8; i++) {
                sub_020182A0(work->sprites[i], 0);
            }
            work->unk50 = 0;
            work->active = 0;
            work->state = 0;
            break;
        }
    }
}
