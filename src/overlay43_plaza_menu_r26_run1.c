#include "overlay43_plaza_menu_r26_private.h"

int ov43_0222D47C(void *p, void *state, void *work) {
    int handled = 0;
    int result;

    if ((WORD(gSystem, 0x44) & 0xC0) == 0) {
        HALF(p, 0xE) = 0;
    }
    result = ov43_0222D3B8(p, state, work, &handled);
    if (handled != 0) {
        WORD(state, 0) = 1;
        return result;
    }
    return ov43_0222D2FC(p, state, work);
}

void ov43_0222D4C4(void *p, void *state, void *work, int arg) {
    int mode;

    WORD(p, 4) = 0;
    ov43_0222AD20(work, 0);
    if (WORD(p, 8) == 2) {
        mode = 2;
    } else {
        mode = 1;
    }
    ov43_0222DAE8(p, state, work, mode, *(s16 *)p, (void *)arg);
    PlaySE(0x5E1);
}
