#include "r40_overlay_72_residual_24_private.h"

int ov72_0223A588(void *work) {
    if (ov72_0223B744[U8_AT(work, 0x1312)](work) == 1) {
        return S8_AT(work, 0x130e);
    }
    return 0;
}

int ov72_0223A5B4(void *work) {
    BeginNormalPaletteFade(4, 0, 0, 0, 4, 1, 0x43);
    U8_AT(work, 0x1312) = 1;
    return 0;
}

int ov72_0223A5E0(void *work) {
    if (IsPaletteFadeFinished() == 1) {
        ov72_0223A680(work);
        ov72_02238730(PTR_AT(work, 0xe04), *(s16 *)((u8 *)work + 0x1310), U32_AT(work, 0x1368));
        ov72_02238B18(work, 1);
        ov72_0223ACA8(work);
        ov72_0223AD20((u8 *)work + 0x1328, PTR_AT(work, 0xbd4), 0x14);
        ov72_0223AD20((u8 *)work + 0x1338, PTR_AT(work, 0xbd4), 0x15);
        ov72_0223AD20((u8 *)work + 0x1348, PTR_AT(work, 0xbd4), 0x16);
        ToggleBgLayer(4, 1);
        BeginNormalPaletteFade(4, 1, 1, 0, 4, 1, 0x43);
        U8_AT(work, 0x1312) = 2;
    }
    return 0;
}

void ov72_0223A680(void *work) {
    int i;
    u8 *cur;

    if (U8_AT(work, 0x130d) == 100) {
        Sprite_SetDrawFlag(PTR_AT(work, 0xdf4), TRUE);
    }
    Sprite_SetDrawFlag(PTR_AT(work, 0xdf8), TRUE);
    Sprite_SetDrawFlag(PTR_AT(work, 0xdfc), TRUE);
    for (i = 0, cur = work; i < 3; i++, cur += 4) {
        ov72_02238750(PTR_AT(cur, 0xdf4), i, U32_AT(work, 0x1368));
    }
    Sprite_SetDrawFlag(PTR_AT(work, 0xe00), TRUE);
    Sprite_SetDrawFlag(PTR_AT(work, 0xe04), TRUE);
    Sprite_SetDrawFlag(PTR_AT(work, 0xe08), TRUE);
    Sprite_SetDrawFlag(PTR_AT(work, 0xe0c), TRUE);
    Sprite_SetDrawFlag(PTR_AT(work, 0xe10), TRUE);
}
