#include "to45_overlay89_r11_private.h"

BOOL ov89_0225BDA8(void *unused, u8 *work, u8 *arg) {
    int i;
    u8 *p;
    u8 *argp;

    argp = arg + 0x94;
    i = 0;
    p = work + 0x18C;
    do {
        if (ov89_0225AEA8(p, argp + 4) == TRUE) {
            return TRUE;
        }
        i++;
        p += 0x10;
    } while (i < 3);
    return FALSE;
}
