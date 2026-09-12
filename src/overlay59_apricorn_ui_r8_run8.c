#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

BOOL ov59_0223AABC(Ov59R8Work *work) {
    switch (U16(work, 0x40)) {
    case 0:
        ov59_0223AD20(work);
        U16(work, 0x40)
        ++;
        break;
    case 1:
        ov59_0223AD84(work);
        sub_020210BC();
        sub_02021148(1);
        U16(work, 0x40) = 0;
        return TRUE;
    }
    return FALSE;
}

BOOL ov59_0223AB00(Ov59R8Work *work) {
    switch (U16(work, 0x40)) {
    case 0:
        sub_02021238();
        ov59_0223AD58(work);
        U16(work, 0x40)
        ++;
        break;
    case 1:
    default:
        ov59_0223ACD0();
        U16(work, 0x40) = 0;
        return TRUE;
    }
    return FALSE;
}

int ov59_0223AB3C(Ov59R8Work *work) {
    switch (U16(work, 0x40)) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, U32(work, 0));
        U16(work, 0x40)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            U16(work, 0x40) = 0;
            return 2;
        }
        break;
    }
    return 0;
}

int ov59_0223AB90(Ov59R8Work *work) {
    switch (U16(work, 0x40)) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, U32(work, 0));
        U16(work, 0x40)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            U16(work, 0x40) = 0;
            return 8;
        }
        break;
    }
    return 1;
}
