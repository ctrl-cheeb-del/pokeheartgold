#include "r40_unk_0208B1AC_residual_9_candidate_private.h"

void sub_0208BECC(u8 *work) {
    void *mon = sub_0208A520(work);
    int count;
    int i;
    u8 *spriteWork;

    switch ((*(u8 **)(work + 0x22C))[0x11]) {
    case 0:
        count = 1;
        break;
    case 2:
        count = 0;
        break;
    case 1:
        count = (*(u8 **)(work + 0x22C))[0x13];
        break;
    }
    i = 0;
    if (count > 0) {
        spriteWork = work;
        do {
            switch ((*(u8 **)(work + 0x22C))[0x11]) {
            case 0:
                mon = sub_0208A520(work);
                thunk_Sprite_SetPaletteOverride(*(void **)(spriteWork + 0x528), Pokemon_GetIconPalette(mon) + 12);
                break;
            case 2:
                thunk_Sprite_SetPaletteOverride(*(void **)(spriteWork + 0x528), Boxmon_GetIconPalette(mon) + 12);
                break;
            case 1:
                mon = Party_GetMonByIndex(**(void ***)(work + 0x22C), i);
                thunk_Sprite_SetPaletteOverride(*(void **)(spriteWork + 0x528), Pokemon_GetIconPalette(mon) + 12);
                break;
            }
            sub_0208BE00(work, mon, i + 0x49);
            i++;
            spriteWork += 4;
        } while (i < count);
    }
    if (i < 6) {
        spriteWork = work + i * 4;
        do {
            thunk_Sprite_SetDrawFlag(*(void **)(spriteWork + 0x528), 0);
            i++;
            spriteWork += 4;
        } while (i < 6);
    }
}
