#include "overlay89_r11_private.h"

BOOL ov89_0225B900(void *unused, u8 *work, u8 *arg) {
    return ov89_0225AEA8(work + 0xA0, arg + 0x98) == TRUE;
}
