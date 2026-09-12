#include "overlay92_battle_sequence_r18_private.h"

void ov92_02261118(Ov92AnimState *work) {
    ManagedSprite *unused = work->sprites[0];
    s32 *level = (s32 *)work->sprites[1];
    s32 *base = (s32 *)work->sprites[3];
    PaletteData *pltt = (PaletteData *)work->sprites[2];
    (void)unused;

    if (work->active != 0) {
        switch (work->state) {
        case 0:
            if (*level < 4) {
                (*level)++;
            } else {
                *level = 4;
                work->state++;
            }
            PaletteData_BlendPalettes(pltt, 0, 1, (u8)(*level + *base), 0);
            PaletteData_BlendPalettes(pltt, 1, 1, (u8)(*level + *base), 0);
            break;
        case 1:
            sub_020182A0(unused, 1);
            work->unk28 = 0;
            work->state++;
            break;
        case 2:
            if (work->unk50 == 1 && ++work->unk28 >= 15) {
                work->state++;
            }
            break;
        case 3:
            if (*level > 0) {
                (*level)--;
            } else {
                *level = 0;
                work->state++;
            }
            PaletteData_BlendPalettes(pltt, 0, 1, (u8)(*level + *base), 0);
            PaletteData_BlendPalettes(pltt, 1, 1, (u8)(*level + *base), 0);
            break;
        default:
            work->unk50 = 0;
            work->active = 0;
            work->state = 0;
            sub_020182A0(unused, 0);
            break;
        }
    }
}
