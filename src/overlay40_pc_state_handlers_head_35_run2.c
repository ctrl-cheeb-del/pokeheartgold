#include "overlay40_pc_state_handlers_tail_35_private.h"

void ov40_0223D830(void *p, BOOL draw) {
    int i, j;
    u8 *base;
    u8 *row;
    for (j = 0, base = PTR(p, 0x860); j < 5; base += 0x30, j++) {
        for (i = 0, row = base; i < 6; i++, row += 8) {
            void *sprite = PTR(row, 0x51C);
            if (sprite != NULL) {
                ManagedSprite_SetDrawFlag(sprite, draw);
            }
        }
    }
}

void ov40_0223D874(void *p) {
    int i, j;
    u8 *base;
    u8 *row;
    base = PTR(p, 0x860);
    ov40_02230964(p, (void *)1);
    for (j = 0; j < 5; base += 0x30, j++) {
        for (i = 0, row = base; i < 6; i++, row += 8) {
            void *sprite = PTR(row, 0x51C);
            if (sprite != NULL) {
                ov40_0222FF48(p, PTR(row, 0x518), sprite);
                PTR(row, 0x51C) = NULL;
            }
        }
    }
    ov40_02230964(p, NULL);
}
