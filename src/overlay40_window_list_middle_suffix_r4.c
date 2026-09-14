#include "overlay40_window_list_middle_r4_private.h"

void ov40_0222F5EC(void *p, s16 value)
{
    s16 selected = 0;
    int direction = 0xFF;

    if (value < 0) {
        if (SWORD(p, 0x38) > 0) {
            SWORD(p, 0x38)--;
            direction = 0;
            PlaySE(0x572);
        }
    } else if (value > 0) {
        if (SWORD(p, 0x38) < SWORD(p, 4) - 1) {
            SWORD(p, 0x38)++;
            direction = 1;
            PlaySE(0x572);
        }
    }

    switch (direction) {
    case 0:
    {
        int start;
        if (SWORD(p, 0x38) < SWORD(p, 0x44)) {
            selected = SWORD(p, 0x38);
        } else {
            start = SWORD(p, 4) - SWORD(p, 0x44);
            if (SWORD(p, 0x38) >= start) {
                selected = SWORD(p, 0x44) + 1;
                if (SWORD(p, 0x38) >= start) {
                    selected += SWORD(p, 0x38) - start;
                }
            } else {
                selected = SWORD(p, 0x44);
                if (SWORD(p, 0x38) <= SWORD(p, 0x44)) {
                    selected += SWORD(p, 0x38) - SWORD(p, 0x44);
                }
            }
        }
        break;
    }
    case 1:
        if (SWORD(p, 0x38) <= SWORD(p, 0x40)) {
            selected = SWORD(p, 0x38);
        } else {
            selected = SWORD(p, 0x40);
            if (SWORD(p, 0x38) >= SWORD(p, 4) - SWORD(p, 0x40)) {
                selected += SWORD(p, 0x38) - (SWORD(p, 4) - SWORD(p, 0x40) - 1);
            }
        }
        break;
    }

    if (selected < 0) {
        GF_AssertFail();
    }
    if (direction != 0xFF) {
        SWORD(p, 0x3C) = selected;
    }

    {
        s16 scroll = 0;
        if (SWORD(p, 0x3C) >= SWORD(p, 0x40)) {
            scroll = SWORD(p, 0x38) - SWORD(p, 0x40);
            if (SWORD(p, 0x38) >= SWORD(p, 4) - (SWORD(p, 0x40) + 1)) {
                scroll = SWORD(p, 4) - SWORD(p, 0x10);
            }
        }
        SHALF(p, 8) = scroll;
    }
    ov40_0222F8C0(p);
}
