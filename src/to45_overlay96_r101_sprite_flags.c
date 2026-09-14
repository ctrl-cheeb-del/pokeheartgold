#include "to45_overlay96_r101_sprite_flags_private.h"

void ov96_0220EAC4(void *arg) {
    int i;
    int j;
    Overlay96R101Work *work = arg;
    Overlay96R101Row *row;
    BOOL animate0;
    BOOL animate1;

    ov96_021EB144(work->unk20, 1);
    ov96_0221031C(work->unkC4);

    for (i = 0; i < 12; i++) {
        ManagedSprite_SetAnimateFlag(work->sprites[i].sprite, 0);
    }

    i = 0;
    animate0 = FALSE;
    animate1 = FALSE;
    row = work->rows;
    for (; i < 2; row++, i++) {
        void **sprites0 = row->sprites0;

        for (j = 0; j < 2; j++) {
            ManagedSprite_SetAnimateFlag(sprites0[j], animate0);
            ManagedSprite_SetAnimateFlag(sprites0[j + 2], animate1);
        }
    }
}
